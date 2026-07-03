#include "ParryState.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
void ParryState::Enter(CharactorBase* owner)
{
	idleTime_ = 20;
	stateFrame_ = 0;
	canChange_ = false;
}

void ParryState::HandleInput(PlayerBase* owner)
{
}

void ParryState::Update(CharactorBase* owner)
{
	auto f=owner->GetTransform().GetForward();
	auto& pos = owner->GetTransform().pos;
	pos = VAdd(pos, f);
}

void ParryState::Exit(CharactorBase* owner)
{
}
