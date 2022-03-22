#pragma once
#include <GameEngine/GameEngineActor.h>

class Map: public GameEngineActor
{
public:
	Map();
	~Map();


	Map(const Map& _Other) = delete;
	Map(Map&& _Other) noexcept = delete;
	Map& operator=(const Map& _Other) = delete;
	Map& operator=(Map&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Render() override;
};