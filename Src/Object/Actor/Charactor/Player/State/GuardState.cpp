#include "GuardState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"
#include"../../../../Common/AnimationController.h"
#include"../SowrdsMan/SwordsMan.h"

void GuardState::Enter(CharactorBase* owner)
{
	isLoop_ = true;
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::GUARD);
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
			owner->RequestAttack();
		}
		else
		{
			owner->ChangeState<IdleState>();
		}
	}
}

void GuardState::Update(CharactorBase* owner)
{
	if(KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_FRONT).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_LEFT).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_BACK).now ||
		KEY::GetIns().GetInfo(KEY::KEY_TYPE::MOVE_RIGHT).now)
	{
		owner->GetAnimationController()->SetBlendAnim((int)SwordsMan::ANIM_TYPE::WALK, 0.3f, true);
	}
	else
	{
		owner->GetAnimationController()->RemoveBlendAnim((int)SwordsMan::ANIM_TYPE::WALK);
	}

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
	//owner->GetTransform().quaRot = Quaternion::Euler(VGet(0, atan2f(moveVec.x, moveVec.z), 0.0f));
	owner->GetTransform().pos = VAdd(owner->GetTransform().pos, VScale(moveVec, owner->GetRigidBody().GetMoveSpeed()*0.5f));

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
