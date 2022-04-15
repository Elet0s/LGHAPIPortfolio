#include "Chapter01.h"
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

Chapter01::Chapter01()
{
}

Chapter01::~Chapter01()
{
}

void Chapter01::Loading()
{
	CreateActor<Player>((int)ORDER::PLAYER);
	CreateActor<ChapterBackGound>((int)ORDER::BACKGROUND);
}

void Chapter01::Update()
{

}
void Chapter01::LevelChangeStart()
{

}