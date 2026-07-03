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
#include"Game/TestGame/TestGame.h"

#include"../../Object/Actor/Manager/ActorManager.h"
#include"../../Object/Actor/Camera/Camera.h"



GameScene::GameScene(void)
{

}

GameScene::GameScene(GameInfo info, CHARACTORKIND cKind)
{
	gameInfo_ = info;
	charaKind_ = cKind;
}

GameScene::~GameScene(void)
{
}

void GameScene::SubLoad(void)
{
	actorMng_ = std::make_unique<ActorManager>();
	colMng_ = std::make_unique<CollisionManager>();
	actorMng_->Load(gameInfo_,charaKind_);
	CreateGame(gameInfo_);
	game_->Load(gameInfo_);
}

void GameScene::SubInit(void)
{
	game_->Init();

}

void GameScene::SubUpdate(void)
{
	game_->Update();
	if (KEY::GetIns().GetInfo(KEY::KEY_TYPE::DEBUG_KEY_0).down)
	{
		SceneManager::GetInstance().ChangeScene(SCENE_ID::RESULT);
	}
	if(KEY::GetIns().GetInfo(KEY::KEY_TYPE::TAB).down)
	{
		SceneManager::GetInstance().GetCamera().CameraMoveStop();
	}
}

void GameScene::SubDraw(void)
{
	game_->Draw();
	DrawFormatString(0, 0, 0xffffff, "Game");
}

void GameScene::SubRelease(void)
{
	SE::GetInstance().Stop(SOUND_TYPE::BGM);
	SE::GetInstance().Release();
	game_->Release();
}

void GameScene::CreateGame(GameInfo info)
{
	game_ = std::make_unique<TestGame>(actorMng_.get(), colMng_.get());
	switch (info.stage_)
	{
	case STAGE_NUM::STAGE1:
		break;
	case STAGE_NUM::STAGE2:
		break;
	case STAGE_NUM::STAGE3:
		break;
	case STAGE_NUM::STAGE4:
		break;
	default:
		break;
	}
}


