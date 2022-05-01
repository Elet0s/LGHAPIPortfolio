#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
#include <GameEngineBase/GameEngineSound.h>

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
	float Speed_;

	void Start() override;
	void Update() override;
	void Render() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel)override;

	std::string NextLevel_;
	std::string PreLevel_;
	std::string EntryLevel_;

private:
	void IdleUpdate();
	void MoveUpdate();
	void AttackUpdate();
	void HitUpdate();
	void DieUpdate();
	void WinUpdate();
	void IdleStart();
	void MoveStart();


};


