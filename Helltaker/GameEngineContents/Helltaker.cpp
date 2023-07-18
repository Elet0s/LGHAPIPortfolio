#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineFont.h>

#include "Helltaker.h"
#include "TitleLevel.h"
#include "MenuLevel.h"
#include "Chapter01.h"
#include "Chapter02.h"
#include "Chapter03.h"

Helltaker::Helltaker()
	:Chapter_(0),
	Value_({ 1920, 1080 })
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	//////////////////////�̹��� �ε��ϴ� �κ�

	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, Value_);
	{
		
		//���� ���� ���丮
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("AudioClip");

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
	{
		//é�� ������Ʈ
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Chapter");
		ResourcesDir.Move("Object");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//é�� Helper
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Chapter");
		ResourcesDir.Move("Global");
		ResourcesDir.Move("Helper");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
		{
		//é�� ������Ʈ
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Chapter");
		ResourcesDir.Move("Global");
		ResourcesDir.Move("Ui");

		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

		//////////////////////����ä�� �ҷ��� �̹���
		{
			//���� Loding
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Helltaker");
			ResourcesDir.Move("Resource");
			ResourcesDir.Move("Global");
			ResourcesDir.Move("Loding");
			GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
		}
		{
			//é�� ���� DieEfect
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Helltaker");
			ResourcesDir.Move("Resource");
			ResourcesDir.Move("Chapter");
			ResourcesDir.Move("Global");
			ResourcesDir.Move("Ui");
			ResourcesDir.Move("DieEfect");
			GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
		}
		{
			//é�� ���� DieEvent
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Helltaker");
			ResourcesDir.Move("Resource");
			ResourcesDir.Move("Chapter");
			ResourcesDir.Move("Global");
			ResourcesDir.Move("Ui");
			ResourcesDir.Move("DieEvent");
			GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
		}
		{
			// Player�����̹���
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Helltaker");
			ResourcesDir.Move("Resource");
			ResourcesDir.Move("Chapter");
			ResourcesDir.Move("Global");
			ResourcesDir.Move("Player");
			ResourcesDir.Move("PlayerWin");
			GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
		}
		{
			// Player�����̹���
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Helltaker");
			ResourcesDir.Move("Resource");
			ResourcesDir.Move("Chapter");
			ResourcesDir.Move("Global");
			ResourcesDir.Move("Player");
			ResourcesDir.Move("PlayerDie");
			GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
		}
	//////////////////////�̹��� �ڸ��� �κ�

	{
		GameEngineImage* Booper = GameEngineImageManager::GetInst()->Find("Booper.bmp");
		Booper->CutCount(17,1);
		GameEngineImage* PlayerRight = GameEngineImageManager::GetInst()->Find("PlayerRight.bmp");
		PlayerRight->CutCount(12,1);
		GameEngineImage* PlayerLeft = GameEngineImageManager::GetInst()->Find("PlayerLeft.bmp");
		PlayerLeft->CutCount(12, 1);
		GameEngineImage* PlayerMoveR = GameEngineImageManager::GetInst()->Find("PlayerMoveR.bmp");
		PlayerMoveR->CutCount(6, 1);
		GameEngineImage* PlayerMoveL = GameEngineImageManager::GetInst()->Find("PlayerMoveL.bmp");
		PlayerMoveL->CutCount(6, 1);
		GameEngineImage* PlayerKickR = GameEngineImageManager::GetInst()->Find("PlayerKickR.bmp");
		PlayerKickR->CutCount(13, 1);
		GameEngineImage* PlayerKickL = GameEngineImageManager::GetInst()->Find("PlayerKickL.bmp");
		PlayerKickL->CutCount(13, 1);
		GameEngineImage* Ston = GameEngineImageManager::GetInst()->Find("Ston.bmp");
		Ston->CutCount(11, 1);
		GameEngineImage* MonsterR = GameEngineImageManager::GetInst()->Find("MonsterR.bmp");
		MonsterR->CutCount(12, 1);
		GameEngineImage* MonsterL = GameEngineImageManager::GetInst()->Find("MonsterL.bmp");
		MonsterL->CutCount(12, 1);
		GameEngineImage* Pandemonica = GameEngineImageManager::GetInst()->Find("Pandemonica.bmp");
		Pandemonica->CutCount(12, 1);
		GameEngineImage* MonsterHitL = GameEngineImageManager::GetInst()->Find("MonsterHitL.bmp");
		MonsterHitL->CutCount(6, 1);
		GameEngineImage* MonsterHitR = GameEngineImageManager::GetInst()->Find("MonsterHitR.bmp");
		MonsterHitR->CutCount(6, 1);

	}

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<MenuLevel>("MenuLevel");
	CreateLevel<Chapter01>("Chapter01");
	CreateLevel<Chapter02>("Chapter02");
	CreateLevel<Chapter03>("Chapter03");
	ChangeLevel("Chapter01");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}