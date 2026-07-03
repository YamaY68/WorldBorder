#pragma once
#include "../../IState.h"
#include<DxLib.h>
class MoveState :
    public IState
{
public:
    void Enter(CharactorBase* owner) override;
    void HandleInput(PlayerBase* owner) override;
    void Update(CharactorBase* owner) override;
    void Exit(CharactorBase* owner) override;
private:
	VECTOR moveVec_ = { 0.0f,0.0f,0.0f };
};

