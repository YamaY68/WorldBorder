#include "GameSelectScene.h"
#include <DxLib.h>
#include <string>
#include<memory>
#include "../../Manager/Generic/KeyManager.h"
#include"../../Manager/Game/SceneManager.h"
#include"../GameScene/GameScene.h"
#include"../PlayerSelect/PlayerSelect.h"
GameSelectScene::GameSelectScene(void)
{
}

GameSelectScene::~GameSelectScene(void)
{
}

void GameSelectScene::SubLoad(void)
{
}

void GameSelectScene::SubInit(void)
{
}

void GameSelectScene::SubUpdate(void)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::SPACE).down)
	{
		SceneManager::GetInstance().ChangeScene<PlayerSelect>(static_cast<GameInfo>(STAGE_NUM::TEST));
	}
}

void GameSelectScene::SubDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "GameSelect");
}

void GameSelectScene::SubRelease(void)
{
}
