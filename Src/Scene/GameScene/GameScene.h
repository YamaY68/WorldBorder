#pragma once
#include "../SceneBase.h"
#include<vector>
#include<memory>
#include"../GameSelect/GameInfo.h"
#include"../../Object/Actor/Charactor/Player/PlayerInfo.h"

class ActorManager;
class CollisionManager;
class ContactEventManager;
class GameBase;

class GameScene :
	public SceneBase
{
public:
	GameScene(void);
	GameScene(GameInfo info,CHARACTORKIND cKind);
	~GameScene(void);

	void SubLoad(void) override;
	void SubInit(void) override;
	void SubUpdate(void) override;
	void SubDraw(void) override;
	void SubRelease(void) override;
	SCENE_ID GetSceneID(void)const override { return SCENE_ID::GAME; }
private:
#pragma region ä÷êî
	void SetContactEventRule(void);
	void SetContactEventCallback(void);
	void SetCollisionCollback(void);
	void CreateGame(GameInfo info);
#pragma endregion

#pragma region ïœêî
	std::unique_ptr<ActorManager> actorMng_;
	std::unique_ptr<CollisionManager>colMng_;
	std::unique_ptr<GameBase> game_;
	GameInfo gameInfo_;
	CHARACTORKIND charaKind_;
#pragma endregion

};

