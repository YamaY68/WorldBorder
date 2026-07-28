#include "SwordsMan_HeavyAttack1.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"

void SwordsMan_HeavyAttack1::Enter(CharactorBase* owner)
{
	idleTime_ = 120;
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::HEAVY_ATTACK_1);
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
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_HeavyAttack1::Exit(CharactorBase* owner)
{
}
