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
	CreateActor<Player>((int)ORDER::PLAYER);
	CreateActor<ChapterBackGound>((int)ORDER::BACKGROUND);
}

void PlayLevel::Update()
{

}
void PlayLevel::LevelChangeStart()
{

}