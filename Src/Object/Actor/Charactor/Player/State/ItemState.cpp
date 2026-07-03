#include "ItemState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"

void ItemState::Enter(CharactorBase* owner)
{
	isLoop_ = true;

}

void ItemState::HandleInput(PlayerBase* owner)
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
void ItemState::Update(CharactorBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::ITEM).now)
	{
		canChange_ = false;
	}
	else
	{
		canChange_ = true;
	}
}

void ItemState::Exit(CharactorBase* owner)
{
}
