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
	virtual void RequestLightAttack(void) = 0;

protected:
	virtual void ReturnToIdle(void) {};
	virtual void CreateAttack(void)=0;
};

