#pragma once
#include "../CharactorBase.h"
class EnemyBase :
    public CharactorBase
{
public:
	EnemyBase(void);
	~EnemyBase(void);

	virtual void SubLoad(void) override;
	virtual void SubInit(void) override;
	virtual void SubUpdate(void) override;
	virtual void SubDraw(void) override;
	virtual void SubRelease(void) override;

	virtual void InitCollider(void) override;
protected:
	virtual void ReturnToIdle(void) {};
};

