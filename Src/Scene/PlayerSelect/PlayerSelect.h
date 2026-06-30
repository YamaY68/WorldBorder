#pragma once
#include "../SceneBase.h"
#include"../GameSelect/GameInfo.h"
#include"../../Object/Actor/Charactor/Player/PlayerInfo.h"

class PlayerSelect :
    public SceneBase
{
public:
    PlayerSelect(void);
    PlayerSelect(GameInfo info);
    ~PlayerSelect(void);

    void SubLoad(void) override;
    void SubInit(void) override;
    void SubUpdate(void) override;
    void SubDraw(void) override;
    void SubRelease(void) override;
    SCENE_ID GetSceneID(void)const override { return SCENE_ID::PLAER_SELECT; }

private:
    int cursorIndex_ = 0;
    GameInfo gameInfo_;
    CHARACTORKIND charaKind_;
};