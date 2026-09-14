#pragma once
#include "../CharactorBase.h"
class PlayerBase :
    public CharactorBase
{
public:
	PlayerBase(void);
	~PlayerBase(void);

	virtual void SubLoad(void) override;
	virtual void SubInit(void) override;
	virtual void SubUpdate(void) override;
	virtual void SubDraw(void) override;
	virtual void SubRelease(void) override;

	virtual void InitCollider(void) override;
	virtual void RequestAttack(void) = 0;

	void SetNextComboChoices(int lightType, int heavyType) {
		nextLightAttackType_ = lightType;
		nextHeavyAttackType_ = heavyType;
	}

	void SetComboBuffer(float time) { comboBufferTimer_ = time; }
	void ClearCombo() {
		nextLightAttackType_ = -1;
		nextHeavyAttackType_ = -1;
		comboBufferTimer_ = 0.0f;
	}
protected:
	virtual void ReturnToIdle(void) {};
	virtual void CreateAttack(void)=0;
protected:
	int nextLightAttackType_ = -1; // 選択肢：次に繋がるライト攻撃
	int nextHeavyAttackType_ = -1; // 選択肢：次に繋がるヘヴィ攻撃
	bool isLightAttack_ = true; //true :ライト攻撃、false:ヘヴィ攻撃
	float comboBufferTimer_ = 0.0f; // 受付猶予タイマー	float comboBufferTimer_ = 0.0f; // コンボ受付の残り猶予時間（フレームまたは秒数）
};

