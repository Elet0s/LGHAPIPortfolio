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
	//////////////////////�̹��� �ε��ϴ� �κ�

	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1920, 1080 });
	{
		//���� ���� ���丮
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("AudioClip");

		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile();

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}

	}

	{
		//Ÿ��Ʋ �̹���
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
		//���θ޴� ��׶��� �̹���
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
		//���θ޴� �ؽ�Ʈ �޼���
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
		//���� Booper
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
		//é�� ��׶���
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
		//é�� �۷ι� �÷��̾�
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

	//////////////////////�̹��� �ڸ��� �κ�

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