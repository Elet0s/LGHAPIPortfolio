#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"

enum class ORDER
{
	TitleBackGround,
	TitleLogo,
};
TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	// ȸ�縶�� �ٸ����ְ�����
	// Actor�� ��������?

	CreateActor<TitleBackGround>("TitleLogo", (int)ORDER::TitleBackGround);

	CreateActor<TitleLogo>("TitleLogo", (int)ORDER::TitleLogo);

}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}