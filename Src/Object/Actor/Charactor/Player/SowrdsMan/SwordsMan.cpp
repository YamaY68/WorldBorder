#include "SwordsMan.h"
#include"../../../Collider/ColliderBase.h"
#include"../../../Collider/ColliderCapsule.h"
#include"State/SwordsMan_AttackHeaders.h"
#include"../State/CommonStates.h"
#include"../../../../Common/AnimationController.h"
#include"../../../../../Utility/AsoUtility.h"

const std::string ANIM_PATH = "Data/Model/Player/SowrdMan/";

SwordsMan::SwordsMan(void)
{
}

SwordsMan::~SwordsMan(void)
{
}

void SwordsMan::SubLoad(void)
{
	trans_.modelId = MV1LoadModel("Data/Model/Player/SowrdMan/Sowrdman.mv1");
	animationController_ = std::make_unique<AnimationController>(trans_.modelId);
	trans_.quaRotLocal = Quaternion::Euler(VGet(0, AsoUtility::Deg2RadF(180), 0));
	trans_.scl = VGet(0.5f, 0.5f, 0.5f);
	CreateAttack();
	PlayerBase::SubLoad();
	LoadAnimation();
	ChangeState<IdleState>();
}

void SwordsMan::SubInit(void)
{
	PlayerBase::SubInit();
}

void SwordsMan::SubUpdate(void)
{
	PlayerBase::SubUpdate();
}

void SwordsMan::SubDraw(void)
{
	PlayerBase::SubDraw();
	DrawFormatString(0, 10, 0xffffff, "State:%s", currentState_->GetName());
}

void SwordsMan::SubRelease(void)
{
}

void SwordsMan::LoadAnimation(void)
{
	animationController_->Add((int)ANIM_TYPE::IDLE,30,ANIM_PATH+"Idle.mv1");
	animationController_->Add((int)ANIM_TYPE::WALK, 30, ANIM_PATH + "Walk.mv1");
	animationController_->Add((int)ANIM_TYPE::RUN, 30, ANIM_PATH + "Run.mv1");
	animationController_->Add((int)ANIM_TYPE::GUARD, 30, ANIM_PATH + "Guard.mv1");
	animationController_->Add((int)ANIM_TYPE::EVADE, 30, ANIM_PATH + "Evade.mv1");
	animationController_->Add((int)ANIM_TYPE::PARRY, 30, ANIM_PATH + "Parry.mv1");
	animationController_->Add((int)ANIM_TYPE::BACK_EVADE, 30, ANIM_PATH + "BackEvade.mv1");
	animationController_->Add((int)ANIM_TYPE::LEFT_STRAFE_WALK, 30, ANIM_PATH + "LeftStrafeWalk.mv1");
	animationController_->Add((int)ANIM_TYPE::LEFT_STRAFE_RUN, 30, ANIM_PATH + "LeftStrafeRun.mv1");
	animationController_->Add((int)ANIM_TYPE::RIGHT_STRAFE_WALK, 30, ANIM_PATH + "RightStrafeWalk.mv1");
	animationController_->Add((int)ANIM_TYPE::RIGHT_STRAFE_RUN, 30, ANIM_PATH + "RightStrafeRun.mv1");
	animationController_->Add((int)ANIM_TYPE::LIGHT_ATTACK_1, 60, ANIM_PATH + "LightAttack/LightAttack1.mv1");
	animationController_->Add((int)ANIM_TYPE::LIGHT_ATTACK_2, 60, ANIM_PATH + "LightAttack/LightAttack2.mv1");
	animationController_->Add((int)ANIM_TYPE::LIGHT_ATTACK_3, 60, ANIM_PATH + "LightAttack/LightAttack3.mv1");
	animationController_->Add((int)ANIM_TYPE::LIGHT_ATTACK_4, 60, ANIM_PATH + "LightAttack/LightAttack4.mv1");
	animationController_->Add((int)ANIM_TYPE::HEAVY_ATTACK_1, 60, ANIM_PATH + "HeavyAttack/HeavyAttack1.mv1");
	animationController_->Add((int)ANIM_TYPE::HEAVY_ATTACK_2, 60, ANIM_PATH + "HeavyAttack/HeavyAttack2.mv1");
	animationController_->Add((int)ANIM_TYPE::HEAVY_ATTACK_3, 60, ANIM_PATH + "HeavyAttack/HeavyAttack3.mv1");
}


void SwordsMan::InitCollider(void)
{
	ColliderInfo info;
	info.shape_ = ColliderShape::CAPSULE;
	info.layer_ = ColliderLayer::ACTOR;
	info.mask_ = ColliderBase::SetMask({ Layer::ACTOR,Layer::STAGE });
	float radius = 10.0f;
		VECTOR localPosTop = VGet(0.0f, 10.0f, 0.0f);
	VECTOR localPosDown = VGet(0.0f, -10.0f, 0.0f);
	std::unique_ptr<ColliderCapsule>collider =
		std::make_unique<ColliderCapsule>(info, radius, localPosTop, localPosDown, *this);
	ownColliders_.emplace(static_cast<int>(info.shape_), std::move(collider));
}

void SwordsMan::InitRigidBody(void)
{
	rigidBody_.SetUseGravity(true);
}

void SwordsMan::RequestLightAttack(void)
{
	ChangeState<SwordsMan_LightAttack1>();
}

void SwordsMan::CreateAttack(void)
{
	AddState(std::make_unique<IdleState>());
	AddState(std::make_unique<MoveState>());
	AddState(std::make_unique<GuardState>());
	AddState(std::make_unique<EvadeState>());
	AddState(std::make_unique<ParryState>());
	AddState(std::make_unique<IdleState>());
	AddState(std::make_unique<ItemState>());

	AddState(std::make_unique<SwordsMan_LightAttack1>());
	AddState(std::make_unique<SwordsMan_LightAttack2>());
	AddState(std::make_unique<SwordsMan_LightAttack3>());
	AddState(std::make_unique<SwordsMan_LightAttack4>());

	AddState(std::make_unique<SwordsMan_HeavyAttack1>());
	AddState(std::make_unique<SwordsMan_HeavyAttack2>());
	AddState(std::make_unique<SwordsMan_HeavyAttack3>());

	AddState(std::make_unique<SwordsMan_FinishAttack>());
	AddState(std::make_unique<SwordsMan_BreakAttack>());
}

void SwordsMan::ReturnToIdle(void)
{
	ChangeState<IdleState>();
}
