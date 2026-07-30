#include "SkyDome.h"
#include"../../../../Utility/AsoUtility.h"
SkyDome::SkyDome(void)
{
}

void SkyDome::SubLoad(void)
{
	trans_.modelId = MV1LoadModel("Data/Model/SkyDome/sky.mv1");
	trans_.scl = VGet(30, 30, 30);
}

void SkyDome::SubInit(void)
{
}

void SkyDome::SubUpdate(void)
{
	static float rot_=0;
	rot_ += 0.01f;
	trans_.quaRot = Quaternion::Euler(VGet(0.0f, AsoUtility::Deg2RadF(rot_), 0.0f));
	trans_.Update();
}

void SkyDome::SubDraw(void)
{
}

void SkyDome::SubRelease(void)
{
}
