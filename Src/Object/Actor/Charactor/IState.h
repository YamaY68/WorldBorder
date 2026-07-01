#pragma once

class CharactorBase;
class PlayerBase;

class IState
{
public:
	virtual ~IState(void) {};

	virtual void Enter(CharactorBase* owner) = 0;

	virtual void HandleInput(PlayerBase* owner) {};

	virtual void Update(CharactorBase* owner) = 0;

	virtual void Exit(CharactorBase* owner) = 0;

protected:
	bool canChange_ = false;
};