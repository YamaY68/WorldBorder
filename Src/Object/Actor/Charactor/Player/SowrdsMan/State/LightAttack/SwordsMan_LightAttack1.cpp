#include "SwordsMan_LightAttack1.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
#include"../../../State/CommonStates.h"
#include"../../../../../../Common/AnimationController.h"
#include"../../../SowrdsMan/SwordsMan.h"
void SwordsMan_LightAttack1::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::LIGHT_ATTACK_1,false);
	totalAnimFrame_ = owner->GetAnimationController()->GetTotalTime();
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 0.6f*totalAnimFrame_;
}

void SwordsMan_LightAttack1::HandleInput(PlayerBase* owner)
{

	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
		{
			owner->ChangeState<SwordsMan_LightAttack2>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::HEAVYATTACK).down)
		{
			owner->ChangeState<SwordsMan_HeavyAttack1>();
		}

		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
	}
}

void SwordsMan_LightAttack1::Update(CharactorBase* owner)
{
	auto anim = owner->GetAnimationController();

	if (anim->GetProgressRate()>=0.2f&&anim->GetProgressRate()<=0.8f)
	{
		auto f = owner->GetTransform().GetForward();
		owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(f, 2));
	}
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void SwordsMan_LightAttack1::Exit(CharactorBase* owner)
{
}
