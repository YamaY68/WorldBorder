#include "PlayerSelect.h"
#include <DxLib.h>
#include <string>
#include<memory>
#include "../../Manager/Generic/KeyManager.h"
#include"../../Manager/Game/SceneManager.h"
#include"../GameScene/GameScene.h"


PlayerSelect::PlayerSelect(void)
{
}

PlayerSelect::PlayerSelect(GameInfo info)
{
	gameInfo_ = info;
}

PlayerSelect::~PlayerSelect(void)
{
}

void PlayerSelect::SubLoad(void)
{
}

void PlayerSelect::SubInit(void)
{
}

void PlayerSelect::SubUpdate(void)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::SPACE).down)
	{
		SceneManager::GetInstance().ChangeScene<GameScene>(gameInfo_,CHARACTORKIND::SWORDSMAN);
	}
}

void PlayerSelect::SubDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "PlayerSelect");
}

void PlayerSelect::SubRelease(void)
{
}
