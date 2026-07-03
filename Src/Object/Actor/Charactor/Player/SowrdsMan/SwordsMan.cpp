#include "SwordsMan.h"
#include"../../../Collider/ColliderBase.h"
#include"../../../Collider/ColliderCapsule.h"
#include"State/SwordsMan_AttackHeaders.h"
#include"../State/CommonStates.h"

SwordsMan::SwordsMan(void)
{
}

SwordsMan::~SwordsMan(void)
{
}

void SwordsMan::SubLoad(void)
{
	CreateAttack();
	ChangeState<IdleState>();
	PlayerBase::SubLoad();
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
