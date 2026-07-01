#include "PlayerBase.h"
#include"../IState.h"

#include"State/EvadeState.h"
#include"State/GuardState.h"
#include"State/MoveState.h"
#include"State/ParryState.h"
#include"State/IdleState.h"

PlayerBase::PlayerBase(void)
{
}

PlayerBase::~PlayerBase(void)
{
}

void PlayerBase::SubLoad(void)
{
	AddState(std::make_unique<MoveState>());
	AddState(std::make_unique<GuardState>());
	AddState(std::make_unique<EvadeState>());
	AddState(std::make_unique<ParryState>());
	AddState(std::make_unique<IdleState>());
}

void PlayerBase::SubInit(void)
{
}

void PlayerBase::SubUpdate(void)
{
	currentState_->HandleInput(this);
	CharactorBase::Update();
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
