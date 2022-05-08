#pragma once
#include"PlayerEnums.h"
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
#include <GameEngineBase/GameEngineSound.h>



class PlayerTile: public Tile
{
	
};


class Player : public GameEngineActor
{
public:
	Player();
	~Player();
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	inline void SetChapter01TileMap(GameEngineRendererTileMap* _TileMap)
	{
		TileMap_ = _TileMap;
	}
	inline void SetChapter02TileMap(GameEngineRendererTileMap* _TileMap)
	{
		TileMap_ = _TileMap;
	}
	inline void SetChapter03TileMap(GameEngineRendererTileMap* _TileMap)
	{
		TileMap_ = _TileMap;
	}
protected:
	GameEngineSoundPlayer BgmPlayer_;
private:
	GameEngineRendererTileMap* TileMap_;
	GameEngineRenderer* PlayerRender_;
	GameEngineImage* ChapterCol_;
	float Speed_;
	int LifePoint_;
	PlayerState CurState_;
	PlayerState PreState_;

	void Start() override;
	void Update() override;
	void Render() override;
	void KeySet();

public:	

	void ColSet(int _ChapterCount);
	void ChangeState(PlayerState _State);
	 void StateUpdate();


private: //State
	void IdleStart();
	void IdleUpdate();
	void MoveStart();
	void MoveUpdate();
	void KickStart();
	void KickUpdate();
	void DieStart();
	void DieUpdate();
	void WinStart();
	void WinUpdate();



};


