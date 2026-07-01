#include "SwordsMan_LightAttack2.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
void SwordsMan_LightAttack2::Enter(CharactorBase* owner)
{
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
	}
}

void SwordsMan_LightAttack2::Update(CharactorBase* owner)
{
}

void SwordsMan_LightAttack2::Exit(CharactorBase* owner)
{
}
