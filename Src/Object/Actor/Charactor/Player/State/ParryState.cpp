#include "ParryState.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"../../../../Common/AnimationController.h"
#include"../SowrdsMan/SwordsMan.h"
void ParryState::Enter(CharactorBase* owner)
{
	idleTime_ = 20;
	stateFrame_ = 0;
	canChange_ = false;
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::PARRY);
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
