#pragma once
#include "SceneBase.h"
class ResultScene :
    public SceneBase
{
public:
    ResultScene(void);
    ~ResultScene(void);

    void SubLoad(void)override;
    void SubInit(void)override;
    void SubUpdate(void)override;
    void SubDraw(void)override;
    void SubRelease(void)override;
    SCENE_ID GetSceneID(void)const override { return SCENE_ID::RESULT; }
private:
};