#pragma once
#include "../../../../IState.h"

class SwordsMan_LightAttack3 :
    public IState
{
    public:
        void Enter(CharactorBase* owner) override;
        void HandleInput(PlayerBase* owner) override;
        void Update(CharactorBase* owner) override;
        void Exit(CharactorBase* owner) override;
};

