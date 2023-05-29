#include"GameObjectManager.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngineRenderer.h>
#include "Player.h"
GameObjectManager* GameObjectManager::GameObjectManager_ = nullptr;

GameObjectManager::GameObjectManager()
	:RLState_(false)//false 가 오른쪽
	, MakeCheak_(false)
	, ChapterLevel_(0)
	, ShiftCheak_(false)
	, ShiftX_(0)
	, ShiftY_(0)
	, ChapterClear_(false)
	, GameObjectTileMap_()
{

}
GameObjectManager::~GameObjectManager()
{

}

void GameObjectManager::Start()
{

}
void GameObjectManager::Update()
{
	if (MakeCheak_ == false)
	{
		switch (ChapterLevel_)
		{
		case 1:
			CreateMonster(10, 5, 0);
			CreateMonster(8, 5, 0);
			CreateMonster(9, 4, 0);
			CreateSton(9, 8, 0);
			CreateSton(10, 7, 0);
			CreateSton(7, 8, 0);
			CreateSton(7, 7, 0);
			CreateHelper(12, 8, 0);

			CreateWall(7, 3, 0);
			CreateWall(8, 3, 0);
			CreateWall(9, 3, 0);
			CreateWall(10, 2, 0);
			CreateWall(11, 2, 0);
			CreateWall(12, 3, 0);
			CreateWall(12, 4, 0);
			CreateWall(11, 5, 0);
			CreateWall(6, 4, 0);
			CreateWall(6, 5, 0);
			CreateWall(5, 6, 0);
			CreateWall(5, 7, 0);
			CreateWall(5, 8, 0);
			CreateWall(8, 6, 0);
			CreateWall(9, 6, 0);
			CreateWall(10, 6, 0);
			CreateWall(11, 6, 0);
			CreateWall(12, 7, 0);
			CreateWall(13, 8, 0);
			CreateWall(6, 9, 0);
			CreateWall(7, 9, 0);
			CreateWall(8, 9, 0);
			CreateWall(9, 9, 0);
			CreateWall(10, 9, 0);
			CreateWall(11, 9, 0);
			CreateWall(12, 9, 0);
			break;
		case 2:
			break;
		}

		MakeCheak_ = true;
	}

	CheakMonsterAni();
	CheakStonAni();
	CheakHelper();
}
void GameObjectManager::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameObjectManager_ = this;
}
void GameObjectManager::CreateMonster(int _x, int _y, int _index)
{
	GameObjectTile* MonsterTileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	MonsterTileBase->TileObjectX_ = static_cast<float>(_x);
	MonsterTileBase->TileObjectY_ = static_cast<float>(_y);
	MonsterTileBase->Monster_ = CreateRenderer("MonsterL.bmp");
	MonsterTileBase->Monster_->SetPivot({ MonsterTileBase->TileObjectX_ * 100+50, MonsterTileBase->TileObjectY_ * 90 +50 });// 몬스터 이미지 여백 때문에 오차 있음 x50, y50
	MonsterTileBase->Monster_->CreateAnimation("MonsterR.bmp", "MonsterR", 0, 11, 0.065f, true);
	MonsterTileBase->Monster_->CreateAnimation("MonsterL.bmp", "MonsterL", 0, 11, 0.065f, true);
	MonsterTileBase->Monster_->CreateAnimation("MonsterHitL.bmp", "MonsterHitL", 0, 5, 0.05f, true);
	MonsterTileBase->Monster_->CreateAnimation("MonsterHitR.bmp", "MonsterHitR", 0, 5, 0.05f, true);
	MonsterTileBase->Monster_->ChangeAnimation("MonsterR");
	MonsterTileBase->Monster_->SetOrder(static_cast<int>(ORDER::MONSTER));
	MonsterTileBase->TileState_ = MapObject::Monster;

	Mon.push_back(MonsterTileBase);
}
void GameObjectManager::CreateHelper(int _x, int _y, int _index)
{
	GameObjectTile* HelperTileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	HelperTileBase->TileObjectX_ = static_cast<float>(_x);
	HelperTileBase->TileObjectY_ = static_cast<float>(_y);
	HelperTileBase->Helper_ = CreateRenderer("Pandemonica.bmp");
	HelperTileBase->Helper_->SetPivot({ HelperTileBase->TileObjectX_ * 100 + 50, HelperTileBase->TileObjectY_ * 90 + 50 });// 몬스터 이미지 여백 때문에 오차 있음 x50, y50
	HelperTileBase->Helper_->CreateAnimation("Pandemonica.bmp", "Pandemonica", 0, 11, 0.065f, true);
	HelperTileBase->Helper_->ChangeAnimation("Pandemonica");
	HelperTileBase->Helper_->SetOrder(static_cast<int>(ORDER::HELPER));
	HelperTileBase->TileState_ = MapObject::Helper;

	Helper.push_back(HelperTileBase);
}
void GameObjectManager::CreateSton(int _x, int _y, int _index)
{
	GameObjectTile* StonTileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	StonTileBase->TileObjectX_ = _x;
	StonTileBase->TileObjectY_ = _y;
	StonTileBase->Ston_ = CreateRenderer("Ston.bmp");
	StonTileBase->Ston_->SetPivot({ (float)_x * 100 + 50, (float)_y * 90 + 50 });
	StonTileBase->Ston_->CreateAnimation("Ston.bmp", "Ston", 0, 10, 0.065f, true);
	StonTileBase->Ston_->ChangeAnimation("Ston");
	StonTileBase->Ston_->PauseOn();
	StonTileBase->Ston_->SetOrder(static_cast<int>(ORDER::STON));
	StonTileBase->TileState_ = MapObject::Ston;
	Ston.push_back(StonTileBase);
}
void GameObjectManager::CreateWall(int _x, int _y, int _index)
{
	GameObjectTile* WallTileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
}
void GameObjectManager::CreateTrap(int _x, int _y, int _index)
{

}
void GameObjectManager::CreateKey(int _x, int _y, int _index)
{

}
void GameObjectManager::CreateLock(int _x, int _y, int _index)
{

}

void GameObjectManager::CheakMonsterAni()
{
	for (int i = 0; i < Mon.size(); i++)
	{
		if (nullptr == Mon[i])
		{
			continue;
		}

		if (true == Mon[i]->IsLKick_)///왼쪽
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ - 1, Mon[i]->TileObjectY_) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
					ShiftX_ = Mon[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Mon[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftX_ > (Mon[i]->TileObjectX_ - 1) * 100 + 50)
				{
					ShiftX_ -= 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Mon[i]->Monster_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftX_ <= (Mon[i]->TileObjectX_ - 1) * 100 + 50)
				{

					ShiftX_ = Mon[i]->TileObjectX_;
					ShiftY_ = Mon[i]->TileObjectY_;
					Mon[i]->Monster_->Off();
				
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
					CreateMonster(ShiftX_ - 1, ShiftY_, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ - 1, Mon[i]->TileObjectY_) != nullptr)// 뒤에 무엇이 있으면
			{
				Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
			
				if (true == Mon[i]->Monster_->IsEndAnimation())
				{
					GameEngineSound::SoundPlayOneShot("MonsterDie.wav", 0);
					Mon[i]->Monster_->Off();
					
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
				}
			}
		}


		else if (true == Mon[i]->IsRKick_)///오른쪽
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ + 1, Mon[i]->TileObjectY_) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
					ShiftX_ = Mon[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Mon[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftX_ < (Mon[i]->TileObjectX_ + 1) * 100 + 50)
				{
					ShiftX_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Mon[i]->Monster_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftX_ >= (Mon[i]->TileObjectX_ + 1) * 100 + 50)
				{

					ShiftX_ = Mon[i]->TileObjectX_;
					ShiftY_ = Mon[i]->TileObjectY_;
					Mon[i]->Monster_->Off();
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
					CreateMonster(ShiftX_ + 1, ShiftY_, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ + 1, Mon[i]->TileObjectY_) != nullptr)// 뒤에 무엇이 있으면
			{
				Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
				
				if (true == Mon[i]->Monster_->IsEndAnimation())
				{
					GameEngineSound::SoundPlayOneShot("MonsterDie.wav", 0);
					Mon[i]->Monster_->Off();
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
				}
			}
		}


		else if (true == Mon[i]->IsUKick_)///위
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ , Mon[i]->TileObjectY_ - 1) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
					ShiftX_ = Mon[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Mon[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftY_ > (Mon[i]->TileObjectY_ - 1) * 100 + 50)
				{
					ShiftY_ -= 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Mon[i]->Monster_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftY_ <= (Mon[i]->TileObjectY_ - 1) * 100 + 50)
				{

					ShiftX_ = Mon[i]->TileObjectX_;
					ShiftY_ = Mon[i]->TileObjectY_;
					Mon[i]->Monster_->Off();
		
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
					CreateMonster(ShiftX_ , ShiftY_ - 1, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_ , Mon[i]->TileObjectY_ - 1) != nullptr)// 뒤에 무엇이 있으면
			{
				Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
				
				if (true == Mon[i]->Monster_->IsEndAnimation())
				{
					GameEngineSound::SoundPlayOneShot("MonsterDie.wav", 0);
					Mon[i]->Monster_->Off();
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
				}
			}
		}


		else if (true == Mon[i]->IsDKick_)///아래
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_ + 1) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					Mon[i]->Monster_->ChangeAnimation("MonsterHitL");
					ShiftX_ = Mon[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Mon[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftY_ < (Mon[i]->TileObjectY_ + 1) * 100 + 50)
				{
					ShiftX_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Mon[i]->Monster_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftY_ >= (Mon[i]->TileObjectY_ + 1) * 100 + 50)
				{

					ShiftX_ = Mon[i]->TileObjectX_;
					ShiftY_ = Mon[i]->TileObjectY_;
					Mon[i]->Monster_->Off();
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
					CreateMonster(ShiftX_, ShiftY_ + 1, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_ + 1) != nullptr)// 뒤에 무엇이 있으면
			{
				Mon[i]->Monster_->ChangeAnimation("MonsterHitL");

				if (true == Mon[i]->Monster_->IsEndAnimation())
				{
					GameEngineSound::SoundPlayOneShot("MonsterDie.wav", 0);
					Mon[i]->Monster_->Off();
					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Mon[i]->TileObjectX_, Mon[i]->TileObjectY_);
					Mon.erase(Mon.begin() + i);
				}
			}
		}
	}
}


void GameObjectManager::CheakStonAni()
{
	for (int i = 0; i < Ston.size(); i++)
	{
		if (nullptr == Ston[i])
		{
			continue;
		}

		if (true == Ston[i]->IsLKick_)///왼쪽	
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_ - 1, Ston[i]->TileObjectY_) == nullptr)//뒤에 아무것도 없으면
			{

				if (ShiftCheak_ == false)
				{
					GameEngineSound::SoundPlayOneShot("StoneMove.wav", 0);
					ShiftX_ = Ston[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Ston[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
					
				}
				else if (ShiftX_ > (Ston[i]->TileObjectX_ - 1) * 100 + 50)
				{
					ShiftX_ -= 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Ston[i]->Ston_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftX_ <= (Ston[i]->TileObjectX_ - 1) * 100 + 50)
				{
					
					ShiftX_ = Ston[i]->TileObjectX_;
					ShiftY_ = Ston[i]->TileObjectY_;
					Ston[i]->Ston_->Off();

					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_);
					Ston.erase(Ston.begin() + i);
					CreateSton(ShiftX_ - 1, ShiftY_, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;


				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_ - 1, Ston[i]->TileObjectY_) != nullptr)// 뒤에 무엇이 있으면
			{
				
				Ston[i]->IsDKick_ = false;
				
			}
		}


		else if (true == Ston[i]->IsRKick_)///오른쪽
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_ + 1, Ston[i]->TileObjectY_) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					GameEngineSound::SoundPlayOneShot("StoneMove.wav", 0);
					ShiftX_ = Ston[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Ston[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftX_ < (Ston[i]->TileObjectX_ + 1) * 100 + 50)
				{
					ShiftX_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Ston[i]->Ston_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftX_ >= (Ston[i]->TileObjectX_ + 1) * 100 + 50)
				{

					ShiftX_ = Ston[i]->TileObjectX_;
					ShiftY_ = Ston[i]->TileObjectY_;
					Ston[i]->Ston_->Off();

					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_);
					Ston.erase(Ston.begin() + i);
					CreateSton(ShiftX_ + 1, ShiftY_, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_ +1, Ston[i]->TileObjectY_) != nullptr)// 뒤에 무엇이 있으면
			{
				Ston[i]->IsDKick_ = false;
			}
		}
		else if (true == Ston[i]->IsUKick_)///위
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_ - 1) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					GameEngineSound::SoundPlayOneShot("StoneMove.wav", 0);
					ShiftX_ = Ston[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Ston[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftY_ > (Ston[i]->TileObjectY_ - 1) * 100 + 50)
				{
					ShiftY_ -= 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Ston[i]->Ston_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftY_ <= (Ston[i]->TileObjectY_ - 1) * 100 + 50)
				{

					ShiftX_ = Ston[i]->TileObjectX_;
					ShiftY_ = Ston[i]->TileObjectY_;
					Ston[i]->Ston_->Off();

					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_);
					Ston.erase(Ston.begin() + i);
					CreateSton(ShiftX_, ShiftY_ - 1, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_ , Ston[i]->TileObjectY_ -1) != nullptr)// 뒤에 무엇이 있으면
			{
				Ston[i]->IsDKick_ = false;
			}
		}
		else if (true == Ston[i]->IsDKick_)///아래
		{
			if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_ + 1) == nullptr)//뒤에 아무것도 없으면
			{
				if (ShiftCheak_ == false)
				{
					GameEngineSound::SoundPlayOneShot("StoneMove.wav", 0);
					ShiftX_ = Ston[i]->TileObjectX_ * 100 + 50;
					ShiftY_ = Ston[i]->TileObjectY_ * 90 + 50;
					ShiftCheak_ = true;
				}
				else if (ShiftY_ < (Ston[i]->TileObjectY_ + 1) * 100 + 50)
				{
					ShiftY_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
					Ston[i]->Ston_->SetPivot({ ShiftX_ , ShiftY_ });
				}
				else if (ShiftY_ >= (Ston[i]->TileObjectY_ + 1) * 100 + 50)
				{

					ShiftX_ = Ston[i]->TileObjectX_;
					ShiftY_ = Ston[i]->TileObjectY_;
					Ston[i]->Ston_->Off();

					GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->DeleteTile(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_);
					Ston.erase(Ston.begin() + i);
					CreateSton(ShiftX_, ShiftY_ + 1, 0);
					ShiftCheak_ = false;
					ShiftX_ = 0;
					ShiftY_ = 0;

				}
			}
			else if (GameObjectTileMap_->GetTile<GameObjectTile>(Ston[i]->TileObjectX_, Ston[i]->TileObjectY_ + 1) != nullptr)// 뒤에 무엇이 있으면
			{
				Ston[i]->IsDKick_ = false;
			}

		}
	}
}

void GameObjectManager::CheakHelper()
{
//	if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(Helper[0]->TileObjectX_ -1 , Helper[0]->TileObjectY_)->TileState_ == MapObject::Player)
//	{
//		ChapterClear_ = true;
//	}
}

void GameObjectManager::ObjectCheakChapter(int _ChapterLevel)
{
	ChapterLevel_ = _ChapterLevel;
}

bool GameObjectManager::GetChapterClear()
{
	return ChapterClear_;
}
