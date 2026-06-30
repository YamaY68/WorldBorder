#include "ResultScene.h"
#include"../Manager/Game/SceneManager.h"
#include"../Manager/Generic/KeyManager.h"
#include"../Manager/Resource/ResourceManager.h"

ResultScene::ResultScene(void)
{
}

ResultScene::~ResultScene(void)
{
}

void ResultScene::SubLoad(void)
{
}

void ResultScene::SubInit(void)
{
}

void ResultScene::SubUpdate(void)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::SPACE).down)
	{
		SceneManager::GetInstance().PushScene(SCENE_ID::PAUSE);
	}
}

void ResultScene::SubDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "Result");
}

void ResultScene::SubRelease(void)
{
}
