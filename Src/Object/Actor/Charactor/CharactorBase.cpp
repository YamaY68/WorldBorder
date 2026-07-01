#include "CharactorBase.h"
#include"IState.h"
CharactorBase::CharactorBase(void)
{
}

CharactorBase::~CharactorBase(void)
{
}

void CharactorBase::SubLoad(void)
{
}

void CharactorBase::SubInit(void)
{
}

void CharactorBase::SubUpdate(void)
{
	currentState_->Update(this);
}

void CharactorBase::SubDraw(void)
{
}

void CharactorBase::SubRelease(void)
{
}

void CharactorBase::InitCollider(void)
{
}

void CharactorBase::ChangeState(IState* newState)
{
	if (currentState_ != nullptr)
	{
		currentState_->Exit(this);
	}

	currentState_ = newState;

	if (currentState_ != nullptr)
	{
		currentState_->Enter(this);
	}
}
