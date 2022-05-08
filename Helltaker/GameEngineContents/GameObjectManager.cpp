#include"GameObjectManager.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngineRenderer.h>
GameObjectManager* GameObjectManager::GameObjectManager_ = nullptr;

GameObjectManager::GameObjectManager()
	:RLState_(false)
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
		MakeCheak_ = true;
	}
}
void GameObjectManager::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameObjectManager_ = this;
}
void GameObjectManager::CreateMonster(int _x, int _y, int _index)
{
	GameObjectTile* TileBase = GameObjectTileMap_->CreateTile<GameObjectTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	TileBase->Monster_ = CreateRenderer("MonsterR.bmp");
	TileBase->Monster_->SetPivot({ 750, 700 });// 몬스터 이미지 여백 때문에 오차 있음 x50, y20
	TileBase->Monster_->CreateAnimation("MonsterR.bmp", "MonsterR", 0, 11, 0.065f, true);
	TileBase->Monster_->CreateAnimation("MonsterL.bmp", "MonsterL", 0, 11, 0.065f, true);
	TileBase->Monster_->SetOrder(static_cast<int>(ORDER::MONSTER));
	TileBase->Monster_->ChangeAnimation("MonsterR");
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