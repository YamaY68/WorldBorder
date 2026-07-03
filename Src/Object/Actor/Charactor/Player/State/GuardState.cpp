#include "GuardState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"

void GuardState::Enter(CharactorBase* owner)
{
	isLoop_ = true;
}

void GuardState::HandleInput(PlayerBase* owner)
{
 if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_FRONT).now ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_LEFT).now ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_BACK).now ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_RIGHT).now)
		{
			owner->ChangeState<MoveState>();
		}
		else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
		else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::GUARD).down)
		{
			owner->ChangeState<GuardState>();
		}
		else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::ITEM).down)
		{
			owner->ChangeState<ItemState>();
		}
		else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
		{
			owner->RequestLightAttack();
		}
		else
		{
			owner->ChangeState<IdleState>();
		}
	}
}

void GuardState::Update(CharactorBase* owner)
{
	if(KEY::GetIns().GetInfo(KEY::KEY_TYPE::GUARD).now)
	{
		canChange_ = false;
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::PARRY).down)
		{
			owner->ChangeState<ParryState>();
		}
		else if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
		{
			owner->ChangeState<EvadeState>();
		}
		else if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::ITEM).down)
		{
			owner->ChangeState<ItemState>();
		}
	}
	else
	{
		canChange_ = true;
	}
}

void GuardState::Exit(CharactorBase* owner)
{
}
