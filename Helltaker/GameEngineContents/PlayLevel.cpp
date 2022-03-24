#include "PlayLevel.h"
#include "Player.h"
#include "BotUI.h"
#include "ChapterBackGound.h"

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
	CreateActor<ChapterBackGound>("BackGround", (int)ORDER::BACKGROUND);
	CreateActor<Player>("Plyer", (int)ORDER::PLAYER);
}