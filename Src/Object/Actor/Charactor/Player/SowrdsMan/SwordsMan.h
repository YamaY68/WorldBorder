#pragma once
#include "../PlayerBase.h"
class SwordsMan :
    public PlayerBase
{
public:
	SwordsMan(void);
	~SwordsMan(void);

	void SubLoad(void) override;
	void SubInit(void) override;
	void SubUpdate(void) override;
	void SubDraw(void) override;
	void SubRelease(void) override;

	void InitCollider(void) override;
	void InitRigidBody(void) override;

	void RequestLightAttack(void)override;
private:
	void CreateAttack(void)override;
};

