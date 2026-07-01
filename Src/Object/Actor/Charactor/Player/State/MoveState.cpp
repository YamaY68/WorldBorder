#include "MoveState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"

void MoveState::Enter(CharactorBase* owner)
{
}

void MoveState::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
	{
		owner->ChangeState<EvadeState>();
	}else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::GUARD).down)
	{
		owner->ChangeState<GuardState>();
	}else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::ITEM).down)
	{
		owner->ChangeState<ItemState>();
	}else	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::LIGHTATTACK).down)
	{
		owner->RequestLightAttack();
	}
	else
	{
		owner->ChangeState<IdleState>();
	}
}

void MoveState::Update(CharactorBase* owner)
{
	VECTOR moveVec = { 0.0f,0.0f,0.0f };

	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_FRONT).now) moveVec.z += 1.0f;
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_BACK).now) moveVec.z -= 1.0f;
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_RIGHT).now) moveVec.x += 1.0f;
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_LEFT).now) moveVec.x -= 1.0f;

	const VECTOR cameraAngle = SceneManager::GetInstance().GetCamera().GetAngles();
	MATRIX camYaw = MGetRotY(cameraAngle.y);
	moveVec = VTransform(moveVec, camYaw);

	if (VSize(moveVec) > 0.0f)
	{
		moveVec = VNorm(moveVec);
	}
	owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(moveVec, owner->GetRigidBody().GetMoveSpeed()));
}

void MoveState::Exit(CharactorBase* owner)
{
}
