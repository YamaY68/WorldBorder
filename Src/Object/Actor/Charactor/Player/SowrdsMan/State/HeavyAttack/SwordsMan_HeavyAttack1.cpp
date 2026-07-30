#include "SwordsMan_HeavyAttack1.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"

void SwordsMan_HeavyAttack1::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1,false);
	owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1, 0.8f);
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void SwordsMan_HeavyAttack1::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
	{
		owner->ChangeState<EvadeState>();
	}
}

void SwordsMan_HeavyAttack1::Update(CharactorBase* owner)
{
	if (stateFrame_ == 30)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1, 1.5f);
	}

	if (stateFrame_ == 90)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1, 0.5f);
	}
	if (stateFrame_ == 120)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1, 1.2f);
	}
	if (stateFrame_ >= 80 && stateFrame_ <= 100)
	{
		auto f = owner->GetTransform().GetForward();
		owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(f, 3));
	}

	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_HeavyAttack1::Exit(CharactorBase* owner)
{
}
