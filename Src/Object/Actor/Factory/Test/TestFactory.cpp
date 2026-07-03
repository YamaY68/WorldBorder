#include "TestFactory.h"
#include"../../Charactor/Player/SowrdsMan/SwordsMan.h"
#include"../../Stage/Floor/Floor.h"

std::vector<std::unique_ptr<ActorBase>> TestFactory::CreateActors(void)
{
    std::vector<std::unique_ptr<ActorBase>> actors;
	actors.push_back(std::make_unique<SwordsMan>());
	actors.push_back(std::make_unique<Floor>());

    return actors;
}
