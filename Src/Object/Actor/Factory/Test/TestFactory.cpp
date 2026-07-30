#include "TestFactory.h"
#include"../../Charactor/Player/SowrdsMan/SwordsMan.h"
#include"../../Stage/Floor/Floor.h"
#include"../../Stage/SkyDome/SkyDome.h"
std::vector<std::unique_ptr<ActorBase>> TestFactory::CreateActors(void)
{
    std::vector<std::unique_ptr<ActorBase>> actors;
	actors.push_back(std::make_unique<SwordsMan>());
	actors.push_back(std::make_unique<Floor>());
	actors.push_back(std::make_unique<SkyDome>());
    return actors;
}
