#include "ParryState.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"../../../../Common/AnimationController.h"
#include"../SowrdsMan/SwordsMan.h"
#include"../State/IdleState.h"
void ParryState::Enter(CharactorBase* owner)
{
	owner->GetAnimationController()->Play((int)SwordsMan::ANIM_TYPE::PARRY,false);

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
	f=VScale(f, 0.2);
	pos = VAdd(pos, f);

	if (stateFrame_ == 30)
	{
	}
	if (owner->GetAnimationController()->IsEnd())
	{
		owner->ChangeState<IdleState>();
	}
}

void ParryState::Exit(CharactorBase* owner)
{
}
