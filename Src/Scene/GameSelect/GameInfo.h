#pragma once

enum class STAGE_NUM
{
	TEST,

	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,

	MAX
};

struct GameInfo
{
	STAGE_NUM stage_;
};