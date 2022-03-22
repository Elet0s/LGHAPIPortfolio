#include "PlayLevel.h"
#include "Player.h"
#include "BotUI.h"
#include "Map.h"

enum class ORDER
{
	BACKGROUND,
	PLAYER,
	MONSTER,
	UI
};

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{

}
void PlayLevel::LevelChangeStart()
{
	CreateActor<Map>("Map", (int)ORDER::BACKGROUND);
	CreateActor<Player>("Player", (int)ORDER::PLAYER);
}