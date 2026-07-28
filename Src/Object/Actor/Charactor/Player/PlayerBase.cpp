#include "PlayerBase.h"
#include"../IState.h"

#include"State/EvadeState.h"
#include"State/GuardState.h"
#include"State/MoveState.h"
#include"State/ParryState.h"
#include"State/IdleState.h"
#include"State/ItemState.h"
PlayerBase::PlayerBase(void)
{
}

PlayerBase::~PlayerBase(void)
{
}

void PlayerBase::SubLoad(void)
{
	CharactorBase::SubLoad();
}

void PlayerBase::SubInit(void)
{
	CharactorBase::SubInit();
}

void PlayerBase::SubUpdate(void)
{
	currentState_->HandleInput(this);
	currentState_->DecreaseIdleTime();
	if (currentState_->GetIdleTime() <= 0 &&!currentState_->GetIsLoop())
	{
		ReturnToIdle();
	}
	if (currentState_->GetStateFrame() >= currentState_->GetNextInputStartTime())
	{
		currentState_->OnCanChange();
	}
	CharactorBase::SubUpdate();
	currentState_->InCreaseStateFrame();

}

void PlayerBase::SubDraw(void)
{
}

void PlayerBase::SubRelease(void)
{
}

void PlayerBase::InitCollider(void)
{
}
