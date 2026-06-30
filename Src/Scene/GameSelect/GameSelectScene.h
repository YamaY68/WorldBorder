#pragma once
#include"../SceneBase.h"


class GameSelectScene :
    public SceneBase
{
public:
    GameSelectScene(void);
    ~GameSelectScene(void);
    void SubLoad(void) override;
    void SubInit(void) override;
    void SubUpdate(void) override;
    void SubDraw(void) override;
    void SubRelease(void) override;
    SCENE_ID GetSceneID(void)const override { return SCENE_ID::GAME_SELECT; }

private:
    int cursorIndex_ = 0;

};
