#include "IdleState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"
#include"../../../../Common/AnimationController.h"
#include"../SowrdsMan/SwordsMan.h"
void IdleState::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::IDLE);
}

void IdleState::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_FRONT).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_LEFT).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_BACK).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_RIGHT).now)
	{
		owner->ChangeState<MoveState>();
	}
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::GUARD).now)
	{
		owner->ChangeState<GuardState>();
	}else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::ITEM).down)
	{
		owner->ChangeState<ItemState>();
	}else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
	{
		owner->RequestLightAttack();
	}
}

void IdleState::Update(CharactorBase* owner)
{
}

void IdleState::Exit(CharactorBase* owner)
{
}
