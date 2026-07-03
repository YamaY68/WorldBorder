#include "SwordsMan_LightAttack2.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
#include"../../../State/CommonStates.h"

void SwordsMan_LightAttack2::Enter(CharactorBase* owner)
{
	idleTime_ = 120;
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void SwordsMan_LightAttack2::HandleInput(PlayerBase* owner)
{
	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
		{
			owner->ChangeState<SwordsMan_LightAttack3>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::HEAVYATTACK).down)
		{
			owner->ChangeState<SwordsMan_HeavyAttack2>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
	}
}

void SwordsMan_LightAttack2::Update(CharactorBase* owner)
{
}

void SwordsMan_LightAttack2::Exit(CharactorBase* owner)
{
}
