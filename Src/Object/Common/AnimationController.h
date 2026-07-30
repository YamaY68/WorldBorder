#pragma once
#include <string>
#include <map>

class AnimationController
{
public:

	// アニメーションデータ
	struct Animation
	{
		int model = -1;
		int attachNo = -1;
		int animIndex = 0;
		float speed = 0.0f;          // 最終的な再生速度（初期速度 × 外部倍率）[cite: 2]
		float baseSpeed = 0.0f;      // 登録時の初期速度を保持
		float speedRate = 1.0f;      // 外から掛ける速度の倍率
		float totalTime = 0.0f;
		float step = 0.0f;
	};
	// コンストラクタ
	AnimationController(int modelId);
	// デストラクタ
	~AnimationController(void);

	//外部FBXからアニメーションを追加
	void Add(int type, float speed, const std::string path);

	// 同じFBX内のアニメーションを準備
	void AddInFbx(int type, float speed, int animIndex);

	// アニメーション再生
	void Play(int type, bool isloop = true);
	void Update(void);
	void Release(void);

	// 外からアニメーションの速度倍率を変更する関数
	void SetAnimSpeedRate(int type, float rate);
	void SetCurrentAnimSpeedRate(float rate); // 再生中のものだけ変更する場合

	int GetPlayType(void) const;			//再生中のアニメーション
	bool IsEnd(void) const;		//再生終了

	float GetTotalTime(void) const;       // 現在再生中のアニメーションの総時間を取得
	float GetCurrentStep(void) const;     // 現在の再生時間（step）を取得
private:
	// アニメーションするモデルのハンドルID
	int modelId_;
	// 種類別のアニメーションデータ
	std::map<int, Animation> animations_;
	// 再生中のアニメーション
	int playType_;
	Animation playAnim_;

	bool loopFlg_;

	// アニメーション追加の共通処理
	void Add(int type, float speed, Animation& animation);
};