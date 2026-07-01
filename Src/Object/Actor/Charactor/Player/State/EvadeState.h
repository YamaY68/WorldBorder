#pragma once
#include "../../IState.h"
class EvadeState :
    public IState
{
public:
    ~EvadeState(void)override;
        void Enter(CharactorBase* owner) override;
        void HandleInput(PlayerBase* owner) override;
        void Update(CharactorBase* owner) override;
		void Exit(CharactorBase* owner) override;

private:
};

