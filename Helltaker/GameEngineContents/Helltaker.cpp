#include "Helltaker.h"
#include"TitleLevel.h"
#include"MenuLevel.h"
#include"PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

Helltaker::Helltaker()
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

	// ���ҽ��� �� �ε����� ���ϴ� ��Ȳ�� �ü��� ����.

	GameEngineImageManager::GetInst()->Load("C:\\Users\\lthlo\\Desktop\\Work\\Portfolio\\Helltaker\\Resource\\chapterBG0001.bmp", "chapterBG0001.bmp");
	GameEngineImageManager::GetInst()->Load("C:\\Users\\lthlo\\Desktop\\Work\\AR40\\API\\Resources\\Image\\Idle.bmp", "Idle.bmp");
	GameEngineImageManager::GetInst()->Load("C:\\Users\\lthlo\\Desktop\\Work\\AR40\\API\\Resources\\Image\\HPBAR.bmp", "HPBAR.bmp");


	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}