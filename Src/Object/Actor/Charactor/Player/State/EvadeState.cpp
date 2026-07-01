#include "EvadeState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"

EvadeState::~EvadeState(void)
{
}

void EvadeState::Enter(CharactorBase* owner)
{
}

void EvadeState::HandleInput(PlayerBase* owner)
{
	if (canChange_)
	{
		if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_FRONT).down ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_LEFT).down ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_BACK).down ||
			KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_RIGHT).down)
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

void EvadeState::Update(CharactorBase* owner)
{
}

void EvadeState::Exit(CharactorBase* owner)
{

}
