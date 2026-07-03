#pragma once
#include "../../IState.h"
class GuardState :
    public IState
{
public:
    void Enter(CharactorBase* owner) override;
    void HandleInput(PlayerBase* owner) override;
    void Update(CharactorBase* owner) override;
    void Exit(CharactorBase* owner) override;
private:
    bool isGuard_ = false;
};

