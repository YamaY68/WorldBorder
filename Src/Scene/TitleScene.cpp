#include "TitleScene.h"
#include"../Manager/Game/SceneManager.h"
#include"../Manager/Generic/KeyManager.h"
#include"../Manager/Resource/ResourceManager.h"


TitleScene::TitleScene(void)
{
}

TitleScene::~TitleScene(void)
{
}

void TitleScene::SubLoad(void)
{
	
}

void TitleScene::SubInit(void)
{
	
}

void TitleScene::SubUpdate(void)
{
	//スペース押したらゲームシーンへ
	if (KeyManager::GetIns().GetInfo(KEY_TYPE::SPACE).down)
	{
		SceneManager::GetInstance().ChangeScene(SCENE_ID::GAME_SELECT);
		return;
	}
}

void TitleScene::SubDraw(void)
{
	DrawString(0, 0, "title", 0xffffff);	
}

void TitleScene::SubRelease(void)
{
}
