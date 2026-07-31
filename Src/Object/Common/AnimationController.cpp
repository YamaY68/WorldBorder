#include <DxLib.h>
#include<algorithm>
#include "AnimationController.h"
#include "../../Manager/Game/SceneManager.h"
AnimationController::AnimationController(int modelId)
{
	modelId_ = modelId;
	playType_ = -1;
	loopFlg_ = false;
}
AnimationController::~AnimationController(void)
{
}
void AnimationController::Add(int type, float speed, const std::string path)
{
	Animation animation;
	animation.model = MV1LoadModel(path.c_str());
	animation.animIndex = -1;
	Add(type, speed, animation);

}
void AnimationController::AddInFbx(int type, float speed, int animIndex)
{
	Animation animation;
	animation.model = -1;
	animation.animIndex = animIndex;
	Add(type, speed, animation);
}
void AnimationController::AddSpeedRange(int type, float startRate, float endRate, float rate)
{
	if (animations_.count(type) > 0) {
		SpeedRange range;
		range.startRate = startRate;
		range.endRate = endRate;
		range.rate = rate;
		animations_[type].speedRanges.push_back(range);
	}
}
void AnimationController::Play(int type, bool isloop)
{
	if (playType_ == type) return;

	if (playType_ != -1)
	{
		playAnim_.speedRate = 1.0f;
		playAnim_.speed = playAnim_.baseSpeed;


		// モデルからアニメーションを外す
		MV1DetachAnim(modelId_, playAnim_.attachNo);
	}

	// アニメーション種別を変更
	playType_ = type;
	playAnim_ = animations_[type];
	playAnim_.speedRate = 1.0f;
	// 初期化
	playAnim_.step = 0.0f;
	loopFlg_ = isloop;

	// 再生速度を初期速度×倍率で確定（切り替わり先がもしリセットされていれば初期速度になる）
	playAnim_.speed = playAnim_.baseSpeed * playAnim_.speedRate;

	if (playAnim_.model == -1) {
		// モデルと同じファイルからアニメーションをアタッチする
		playAnim_.attachNo = MV1AttachAnim(modelId_, playAnim_.animIndex);
	}
	else {
		//別のモデルファイルからアニメーションをアタッチする
		int animIdx = 0;
		playAnim_.attachNo = MV1AttachAnim(modelId_, animIdx, playAnim_.model);
	}

	// アニメーション総時間の取得
	playAnim_.totalTime = MV1GetAttachAnimTotalTime(modelId_, playAnim_.attachNo);
}
void AnimationController::Update(void)
{
	float deltaTime = SceneManager::GetInstance().GetDeltaTime();

	// 1. 現在の進捗割合（0.0 ? 1.0）を計算する
	float currentProgress = 0.0f;
	if (playAnim_.totalTime > 0.0f) {
		currentProgress = playAnim_.step / playAnim_.totalTime;
		// 1.0を超える場合に備えてクランプ
		if (currentProgress > 1.0f) currentProgress = 1.0f;
	}

	// 2. 登録された割合の区間に合致するかチェックして速度レートを決定する
	float currentRate = 1.0f; // デフォルトは等倍

	for (const auto& range : playAnim_.speedRanges)
	{
		if (currentProgress >= range.startRate && currentProgress < range.endRate)
		{
			currentRate = range.rate;
			break;
		}
	}

	// レートを反映
	playAnim_.speedRate = currentRate;
	playAnim_.speed = playAnim_.baseSpeed * playAnim_.speedRate;

	// 3. 決定した速度でステップを進める
	playAnim_.step += (deltaTime * playAnim_.speed);

	if (loopFlg_) {
		if (playAnim_.step > playAnim_.totalTime) {
			playAnim_.step = 0.0f;
		}
	}
	else {
		if (playAnim_.step > playAnim_.totalTime) {
			playAnim_.step = playAnim_.totalTime;
			playAnim_.speedRate = 1.0f;
		}
	}

	// アニメーション設定
	MV1SetAttachAnimTime(modelId_, playAnim_.attachNo, playAnim_.step);
}
void AnimationController::Release(void)
{
	if (playType_ != -1) {
		MV1DetachAnim(modelId_, playAnim_.attachNo);
	}

	//外部ロードしたFBXのアニメーションモデルのメモリ解放
	for (auto& pair : animations_) {
		if (pair.second.model != -1) {
			MV1DeleteModel(pair.second.model);
		}
	}

	//可変長配列をクリアする
	animations_.clear();
}

// 現在再生中のアニメーションの総時間を取得する
// 速度変化を考慮した、実際のトータルタイム（実時間）を取得する
float AnimationController::GetTotalTime(void) const
{
	if (playType_ == -1) return 0.0f;

	// 元のベースとなる総時間
	float baseTotalTime = playAnim_.totalTime;
	if (baseTotalTime <= 0.0f) return 0.0f;

	// もし速度変更区間がなければ、そのままの総時間を返す
	if (playAnim_.speedRanges.empty()) {
		return baseTotalTime;
	}

	// 速度変化を考慮した実際の総時間を計算する
	// ※ 割合（0.0?1.0）を基準に区間が設定されているため、
	//   各区間の「時間の長さ（幅）」に「速度の逆数（1.0 / rate）」を掛けて足し合わせます。
	float actualTotalTime = 0.0f;
	float lastProcessedRate = 1.0f; // どの区間にも属さない部分のデフォルト速度（通常は1.0）

	// 区間をスタート位置が早い順に並べ替えておくと安全（念のため）
	// ※もし登録時にソートしていない場合は注意が必要ですが、ここでは計算ロジックを記述します。

	// わかりやすくするために、0.0から1.0までの区間を隙間なく走査して積算する方法をとります。
	// 細かく0.0?1.0を区切るか、あるいは「各区間の長さ × (1.0 / 速度)」で計算します。

	float currentNormalizedPos = 0.0f; // 0.0 ? 1.0 の追跡用

	// 簡易的かつ確実な計算方法：
	// 全体を細かく見るか、あるいは登録された SpeedRange ごとに計算する
	// ここでは、各 SpeedRange の区間ごとの実時間を積み上げるロジックにします。

	// ※正確に計算するため、コピーを作成してソートするか、あらかじめ登録順が綺麗であることを前提とします
	std::vector<SpeedRange> sortedRanges = playAnim_.speedRanges;

	// ラムダ式で startRate の昇順にソート
	std::sort(sortedRanges.begin(), sortedRanges.end(), [](const SpeedRange& a, const SpeedRange& b) {
		return a.startRate < b.startRate;
		});

	float lastEndRate = 0.0f;

	for (const auto& range : sortedRanges)
	{
		// 1. 前回の終わりから今回の区間の始まりまでの「隙間（速度1.0の区間）」があれば足す
		if (range.startRate > lastEndRate) {
			float gapLength = (range.startRate - lastEndRate) * baseTotalTime;
			actualTotalTime += gapLength; // 速度1.0なのでそのまま足す
		}

		// 2. 今回の区間の長さ（ベース時間換算）
		float rangeBaseLength = (range.endRate - range.startRate) * baseTotalTime;

		// 速度が0以下の場合はゼロ除算を防ぐため安全策を入れる
		float safeRate = (range.rate > 0.0001f) ? range.rate : 0.0001f;

		// 速度が速いと時間は短くなり、遅い（スロー）と時間は長くなる（時間 = 距離 / 速度）
		actualTotalTime += rangeBaseLength / safeRate;
		lastEndRate = (lastEndRate > range.endRate) ? lastEndRate: range.endRate;
	}

	// 3. 最後の区間から 1.0（100%）までの「残り（速度1.0の区間）」があれば足す
	if (lastEndRate < 1.0f) {
		float remainingLength = (1.0f - lastEndRate) * baseTotalTime;
		actualTotalTime += remainingLength;
	}

	return actualTotalTime;
} 

// 現在の再生時間（step）を取得する
float AnimationController::GetCurrentStep(void) const
{
	if (playType_ == -1) return 0.0f;
	return playAnim_.step; // ← 0.0f固定ではなく現在のステップを返す
}

// 現在の進捗割合（0.0 ? 1.0）を取得する
float AnimationController::GetProgressRate(void) const
{
	if (playType_ == -1) return 0.0f;
	if (playAnim_.totalTime <= 0.0f) return 0.0f;

	float rate = playAnim_.step / playAnim_.totalTime;

	// 1.0を超える場合に備えてクランプ
	if (rate > 1.0f) rate = 1.0f;

	return rate;
}

bool AnimationController::IsEnd(void) const
{
	bool ret = false;

	if (loopFlg_) {
		return ret;
	}

	if (playAnim_.step >= playAnim_.totalTime) {
		return true;
	}

	return ret;
}

void AnimationController::Add(int type, float speed, Animation& animation)
{
	if (animations_.count(type) == 0) {
		// 初期速度を保持し、スピード倍率は1.0fで初期化する
		animation.baseSpeed = speed;
		animation.speedRate = 1.0f;
		animation.speed = speed;

		animations_.emplace(type, animation);
	}
}

int AnimationController::GetPlayType(void) const
{
	return playType_;
}