#include "SwordsMan_LightAttack1.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"

void SwordsMan_LightAttack1::Enter(CharactorBase* owner)
{
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
	}
}

void SwordsMan_LightAttack1::Update(CharactorBase* owner)
{
}

void SwordsMan_LightAttack1::Exit(CharactorBase* owner)
{
}
