#pragma once
#include "../../IState.h"
class IdleState :
    public IState
{
    void Enter(CharactorBase* owner) override;
    void HandleInput(PlayerBase* owner) override;
    void Update(CharactorBase* owner) override;
    void Exit(CharactorBase* owner) override;
};

