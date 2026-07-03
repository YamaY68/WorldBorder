#include "SwordsMan_FinishAttack.h"
#include"../../State/CommonStates.h"
#include"../../../../../../Manager/Generic/KeyManager.h"
#include"../../PlayerBase.h"
void SwordsMan_FinishAttack::Enter(CharactorBase* owner)
{
	idleTime_ = 120;
	stateFrame_ = 0;
	canChange_ = false;
	nextInputStartTime_ = 60;
}

void SwordsMan_FinishAttack::HandleInput(PlayerBase* owner)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::EVADE).down)
	{
		owner->ChangeState<EvadeState>();
	}
}

void SwordsMan_FinishAttack::Update(CharactorBase* owner)
{
}

void SwordsMan_FinishAttack::Exit(CharactorBase* owner)
{
}
