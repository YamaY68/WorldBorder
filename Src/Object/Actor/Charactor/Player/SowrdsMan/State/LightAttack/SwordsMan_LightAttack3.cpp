#include "SwordsMan_LightAttack3.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"
void SwordsMan_LightAttack3::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_3,false);
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 30;
}

void SwordsMan_LightAttack3::HandleInput(PlayerBase* owner)
{

	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
		{
			owner->ChangeState<SwordsMan_LightAttack4>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::HEAVYATTACK).down)
		{
			owner->ChangeState<SwordsMan_HeavyAttack3>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
	}
}
void SwordsMan_LightAttack3::Update(CharactorBase* owner)
{
	if (stateFrame_ == 20)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_3, 0.7f);
	}
	if (stateFrame_ == 40)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_3, 1.4f);

	}
	if (stateFrame_ == 115)
	{
		owner->GetAnimationController()->SetAnimSpeedRate((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_3, 0.05f);

	}

	if (stateFrame_ >= 40 && stateFrame_ <= 60)
	{
		auto f = owner->GetTransform().GetForward();
		owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(f, 2));
	}

	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_LightAttack3::Exit(CharactorBase* owner)
{
}
