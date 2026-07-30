#include <DxLib.h>
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
	// 経過時間の取得
	float deltaTime = SceneManager::GetInstance().GetDeltaTime();

	// 再生（現在の速度を反映）
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
			playAnim_.speed = playAnim_.baseSpeed * playAnim_.speedRate; 
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

float AnimationController::GetTotalTime(void) const
{
	if (playType_ == -1) return 0.0f;
	return playAnim_.totalTime;
}

// 現在の再生時間（step）を取得する
float AnimationController::GetCurrentStep(void) const
{
	if (playType_ == -1) return 0.0f;
	return playAnim_.step;
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

// 指定したアニメーションの速度倍率を変更する
void AnimationController::SetAnimSpeedRate(int type, float rate)
{
	if (playType_ == type) {
		playAnim_.speedRate = rate;
		playAnim_.speed = playAnim_.baseSpeed * rate;
	}
}

// 現在再生中のアニメーション速度倍率を変更する
void AnimationController::SetCurrentAnimSpeedRate(float rate)
{
	if (playType_ != -1) {
		SetAnimSpeedRate(playType_, rate);
	}
}

int AnimationController::GetPlayType(void) const
{
	return playType_;
}