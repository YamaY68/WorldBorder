#pragma once
#include "../../IState.h"
class ParryState :
    public IState
{
public:
    void Enter(CharactorBase* owner) override;
    void HandleInput(PlayerBase* owner) override;
    void Update(CharactorBase* owner) override;
    void Exit(CharactorBase* owner) override;

private:
};

