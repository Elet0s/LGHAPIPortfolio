#include "PlayLevel.h"
#include "Player.h"
#include "GameUi.h"

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
	CreateActor<Player>("Player", (int)ORDER::PLAYER);
	CreateActor<GameUi>("GameUi", (int)ORDER::UI);
}