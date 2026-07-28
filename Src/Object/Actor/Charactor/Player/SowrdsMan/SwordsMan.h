#pragma once
#include "../PlayerBase.h"
class SwordsMan :
    public PlayerBase
{
public:
	enum class ANIM_TYPE
	{
		NONE = -1,
		IDLE,
		WALK,
		RUN,
		GUARD,
		EVADE,
		PARRY,

		BACK_EVADE,
		LEFT_STRAFE_WALK,
		LEFT_STRAFE_RUN,
		RIGHT_STRAFE_WALK,
		RIGHT_STRAFE_RUN,

		LIGHT_ATTACK_1,
		LIGHT_ATTACK_2,
		LIGHT_ATTACK_3,
		LIGHT_ATTACK_4,

		HEAVY_ATTACK_1,
		HEAVY_ATTACK_2,
		HEAVY_ATTACK_3,

	};

	SwordsMan(void);
	~SwordsMan(void);

	void SubLoad(void) override;
	void SubInit(void) override;
	void SubUpdate(void) override;
	void SubDraw(void) override;
	void SubRelease(void) override;


	void RequestLightAttack(void)override;
private:
	void LoadAnimation(void)override;
	void InitCollider(void) override;
	void InitRigidBody(void) override;

	void CreateAttack(void)override;
	void ReturnToIdle(void)override;
};

