#pragma once
#include "../../ActorBase.h"
class Floor :
    public ActorBase
{
public:
    Floor(void);
    ~Floor(void);

    void SubLoad(void)override;
    void SubInit(void)override;
    void SubUpdate(void)override;
    void SubDraw(void)override;
    void SubRelease(void)override;

    void InitCollider(void)override;

private:
    VECTOR halfSize_ = { 1000.0f,10.0f,1000.0f };
};


