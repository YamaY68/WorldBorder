#pragma once
#include "../../CharactorBase.h"
class SowdrsMan :
    public CharactorBase
{
public:
	SowdrsMan(void);
	~SowdrsMan(void);

	void SubLoad(void) override;
	void SubInit(void) override;
	void SubUpdate(void) override;
	void SubDraw(void) override;
	void SubRelease(void) override;

	void InitCollider(void) override;
private:

};

