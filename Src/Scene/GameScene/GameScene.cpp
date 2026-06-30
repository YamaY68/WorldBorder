#include "GameScene.h"
#include<DxLib.h>
#include <EffekseerForDXLib.h>
#include "../../Application.h"

#include"../../Manager/Game/SceneManager.h"
#include"../../Manager/Game/UIManager.h"
#include"../../Manager/Game/SE.h"
#include"../../Manager/Resource/ResourceManager.h"
#include"../../Manager/Generic/KeyManager.h"

#include"../../Manager/System/Collision/CollisionManager.h"
#include"../../Manager/System/EventSystem/EventManager.h"
#include"../../Manager/System/EventSystem/GameEventType.h"

#include"Game/GameBase.h"

#include"../../Object/Actor/Manager/ActorManager.h"
#include"../../Object/Actor/Camera/Camera.h"



GameScene::GameScene(void)
{

}

GameScene::GameScene(GameInfo info)
{
	gameInfo_ = info;
}

GameScene::~GameScene(void)
{
}

void GameScene::SubLoad(void)
{
	actorMng_ = std::make_unique<ActorManager>();
	colMng_ = std::make_unique<CollisionManager>();
	actorMng_->Load(gameInfo_);
}

void GameScene::SubInit(void)
{


}

void GameScene::SubUpdate(void)
{
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::DEBUG_KEY_0).down)
	{
		SceneManager::GetInstance().ChangeScene(SCENE_ID::RESULT);
	 }
}

void GameScene::SubDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "Game");

}

void GameScene::SubRelease(void)
{
	SE::GetInstance().Stop(SOUND_TYPE::BGM);
	SE::GetInstance().Release();
}


