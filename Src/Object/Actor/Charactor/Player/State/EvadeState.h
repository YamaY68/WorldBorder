#pragma once
#include "../../IState.h"
#include<DxLib.h>
class EvadeState :
    public IState
{
public:
    ~EvadeState(void)override;
    void Enter(CharactorBase* owner) override;
    void HandleInput(PlayerBase* owner) override;
    void Update(CharactorBase* owner) override;
    void Exit(CharactorBase* owner) override;
    void SetEvadeDirection(const VECTOR& direction) { evadeDirection_ = direction; }
private:
    VECTOR evadeDirection_ = { 0.0f,0.0f,0.0f };
};

