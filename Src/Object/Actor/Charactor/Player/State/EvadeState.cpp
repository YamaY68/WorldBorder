#include "EvadeState.h"
#include<DxLib.h>
#include"../../../../../Utility/AsoUtility.h"
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
	idleTime_ = 40;
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void EvadeState::HandleInput(PlayerBase* owner)
{

}

void EvadeState::Update(CharactorBase* owner)
{
	auto& pos = owner->GetTransform().pos;
	if (AsoUtility::Equals(evadeDirection_, owner->GetTransform().GetForward()))
	{
		pos = VAdd(pos, VScale(VScale(evadeDirection_,-1), 1.2));
		if (stateFrame_ < 20)
		{
		owner->GetRigidBody().AddForce({ 0.0f,2.0f,0.0f });
		}
		else
		{
			owner->GetRigidBody().AddForce({ 0.0f,-1.0f,0.0f });
		}

	}
	else
	{
		if (stateFrame_ < 20)
		{
		owner->GetRigidBody().AddForce({ 0.0f,1.5f,0.0f });
		}
		else
		{
			owner->GetRigidBody().AddForce({ 0.0f,-1.0f,0.0f });
		}
		pos = VAdd(pos, VScale(evadeDirection_, 1.2));
	}
}

void EvadeState::Exit(CharactorBase* owner)
{
	evadeDirection_ = { 0.0f,0.0f,0.0f };

}
