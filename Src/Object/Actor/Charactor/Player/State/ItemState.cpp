#include "ItemState.h"
#include<DxLib.h>
#include"../../../../../Manager/Generic/KeyManager.h"
#include"../../../../../Manager/Game/SceneManager.h"
#include"../../../Camera/Camera.h"
#include"../../CharactorBase.h"
#include"../PlayerBase.h"
#include"CommonStates.h"

void ItemState::Enter(CharactorBase* owner)
{
}

void ItemState::HandleInput(PlayerBase* owner)
{
}

void ItemState::Update(CharactorBase* owner)
{
	owner->ChangeState<IdleState>();
}

void ItemState::Exit(CharactorBase* owner)
{
}
