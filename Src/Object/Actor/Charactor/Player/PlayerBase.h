#pragma once
#include "../CharactorBase.h"
class PlayerBase :
    public CharactorBase
{
public:
	PlayerBase(void);
	~PlayerBase(void);

	void SubLoad(void) override;
	void SubInit(void) override;
	void SubUpdate(void) override;
	void SubDraw(void) override;
	void SubRelease(void) override;

	void InitCollider(void) override;
	virtual void RequestLightAttack(void) = 0;
	virtual void RequestHeavyAttack(void) = 0;
private:
	virtual void CreateAttack(void)=0;
};

