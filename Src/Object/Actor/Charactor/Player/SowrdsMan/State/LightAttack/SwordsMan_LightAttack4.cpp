#include "SwordsMan_LightAttack4.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"
void SwordsMan_LightAttack4::Enter(CharactorBase* owner)
{
	idleTime_ = 180;
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_4);
}

void SwordsMan_LightAttack4::HandleInput(PlayerBase* owner)
{
	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::FINISH).down)
		{
			owner->ChangeState<SwordsMan_FinishAttack>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
	}
}

void SwordsMan_LightAttack4::Update(CharactorBase* owner)
{
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_LightAttack4::Exit(CharactorBase* owner)
{
}
