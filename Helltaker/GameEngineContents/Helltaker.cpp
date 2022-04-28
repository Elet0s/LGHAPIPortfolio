#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>

#include "Helltaker.h"
#include "TitleLevel.h"
#include "MenuLevel.h"
#include "Chapter01.h"

Helltaker::Helltaker()
	:Chapter_(0)
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	//////////////////////이미지 로드하는 부분

	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1920, 1080 });
	{
		//각종 사운드 디렉토리
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("AudioClip");

		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile();

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}

	}

	{
		//타이틀 이미지
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("TitleLevel");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		//메인메뉴 백그라운드 이미지
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("MenuLevel");
		ResourcesDir.Move("MenuBackGround");
		

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		//메인메뉴 텍스트 메세지
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("MenuLevel");
		ResourcesDir.Move("Text");


		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		//공용 Booper
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Global");
		ResourcesDir.Move("Booper");


		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		//챕터 백그라운드
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Chapter");
		ResourcesDir.Move("ChapterBG");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//챕터 글로벌 플레이어
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Chapter");
		ResourcesDir.Move("Global");
		ResourcesDir.Move("Player");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	//////////////////////이미지 자르는 부분

	{
		GameEngineImage* Booper = GameEngineImageManager::GetInst()->Find("Booper.bmp");
		Booper->CutCount(17,1);
		GameEngineImage* PlayerRight = GameEngineImageManager::GetInst()->Find("PlayerRight.bmp");
		PlayerRight->CutCount(12,1);
		GameEngineImage* PlayerLeft = GameEngineImageManager::GetInst()->Find("PlayerLeft.bmp");
		PlayerLeft->CutCount(12, 1);
	}


	if (false == GameEngineInput::GetInst()->IsKey("Start"))
	{
		GameEngineInput::GetInst()->CreateKey("Start", 'p');
	}

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<MenuLevel>("MenuLevel");
	CreateLevel<Chapter01>("Chapter01");
	ChangeLevel("MenuLevel");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}