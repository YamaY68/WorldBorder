#include "SwordsMan_HeavyAttack2.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"
void SwordsMan_HeavyAttack2::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_2,false);
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void SwordsMan_HeavyAttack2::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
	{
		owner->ChangeState<EvadeState>();
	}
}

void SwordsMan_HeavyAttack2::Update(CharactorBase* owner)
{
	if (stateFrame_ >= 100 && stateFrame_ <= 120)
	{
		auto f = owner->GetTransform().GetForward();
		owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(f, 2));
	}
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_HeavyAttack2::Exit(CharactorBase* owner)
{
}
