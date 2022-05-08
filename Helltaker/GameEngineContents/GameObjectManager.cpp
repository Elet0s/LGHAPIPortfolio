#include"GameObjectManager.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngineRenderer.h>
GameObjectManager* GameObjectManager::GameObjectManager_ = nullptr;

GameObjectManager::GameObjectManager()
	:RLState_(false)//false 가 오른쪽
	, MakeCheak_(false)
	, ChapterLevel_(0)
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
		CreateMonster(7, 7, 0);
		CreateMonster(8, 7, 0);
		CreateMonster(6, 3, 0);
		CreateMonster(11, 4, 0);
		CreateMonster(11, 5, 0);
		MakeCheak_ = true;
	}

	CheakAni();
}
void GameObjectManager::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameObjectManager_ = this;
}
void GameObjectManager::CreateMonster(int _x, int _y, int _index)
{
	GameObjectTile* MonsterTileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	MonsterTileBase->TileObjectX_ = _x;
	MonsterTileBase->TileObjectY_ = _y;
	MonsterTileBase->Monster_ = CreateRenderer("MonsterL.bmp");
	MonsterTileBase->Monster_->SetPivot({ (float)_x * 100+50, (float)_y* 90 +50 });// 몬스터 이미지 여백 때문에 오차 있음 x50, y50
	MonsterTileBase->Monster_->CreateAnimation("MonsterR.bmp", "MonsterR", 0, 11, 0.065f, true);
	MonsterTileBase->Monster_->CreateAnimation("MonsterL.bmp", "MonsterL", 0, 11, 0.065f, true);
	MonsterTileBase->Monster_->ChangeAnimation("MonsterL");
	MonsterTileBase->Monster_->SetOrder(static_cast<int>(ORDER::MONSTER));
	MonsterTileBase->TileState_ = MapObject::Monster;

	Mon.push_back(MonsterTileBase);
}
void GameObjectManager::CreateHellper(int _Posx, int _Posy, int _index)
{

}
void GameObjectManager::CreateSton(int _Posx, int _Posy, int _index)
{

}
void GameObjectManager::CreateWall(int _Posx, int _Posy, int _index)
{

}
void GameObjectManager::CreateTrap(int _Posx, int _Posy, int _index)
{

}
void GameObjectManager::CreateKey(int _Posx, int _Posy, int _index)
{

}
void GameObjectManager::CreateLock(int _Posx, int _Posy, int _index)
{

}

void GameObjectManager::CheakAni()
{
	for (int i = 0; i < Mon.size(); i++)
	{
		if (nullptr == Mon[i])
		{
			continue;
		}

		if (true == Mon[i]->IsLKick_)
		{	
			if (true == Mon[i]->Monster_->IsEndAnimation())
			Mon[i]->Monster_->Off();
		}
	}
}