#include "SwordsMan_FinishAttack.h"
#include"../../State/CommonStates.h"
#include"../../../../../../Manager/Generic/KeyManager.h"
#include"../../PlayerBase.h"
#include"../../../../../Common/AnimationController.h"
#include"../../SowrdsMan/SwordsMan.h"
void SwordsMan_FinishAttack::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::FINISH, false);
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void SwordsMan_FinishAttack::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
	{
		owner->ChangeState<EvadeState>();
	}
}

void SwordsMan_FinishAttack::Update(CharactorBase* owner)
{
	if (stateFrame_ == 1)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::FINISH, 1.5);
	}
	if (stateFrame_ == 40)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::FINISH, 0.15f);
	}
	if (stateFrame_ == 80)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::FINISH, 1.4f);
	}

	if (stateFrame_ >= 110&&stateFrame_<=130)
	{
		auto f=owner->GetTransform().GetForward();
		owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(f, 2));
	}
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_FinishAttack::Exit(CharactorBase* owner)
{
}
