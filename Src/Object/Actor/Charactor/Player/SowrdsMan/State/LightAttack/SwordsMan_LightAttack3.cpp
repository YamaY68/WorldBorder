#include "SwordsMan_LightAttack3.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"
void SwordsMan_LightAttack3::Enter(CharactorBase* owner)
{
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
	}
}
void SwordsMan_LightAttack3::Update(CharactorBase* owner)
{
}

void SwordsMan_LightAttack3::Exit(CharactorBase* owner)
{
}
