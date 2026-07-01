#include "SwordsMan_LightAttack4.h"
#include<DxLib.h>
#include"../../../../../../../Manager/Generic/KeyManager.h"
#include"../../../PlayerBase.h"
#include"../../../../CharactorBase.h"
#include"../SwordsMan_AttackHeaders.h"

void SwordsMan_LightAttack4::Enter(CharactorBase* owner)
{
}

void SwordsMan_LightAttack4::HandleInput(PlayerBase* owner)
{
	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::FINISH).down)
		{
			owner->ChangeState<SwordsMan_FinishAttack>();
		}
	}
}

void SwordsMan_LightAttack4::Update(CharactorBase* owner)
{
}

void SwordsMan_LightAttack4::Exit(CharactorBase* owner)
{
}
