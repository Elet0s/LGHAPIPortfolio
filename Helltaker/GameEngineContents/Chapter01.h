#pragma once
#include <GameEngine/GameEngineLevel.h>

// Ό³Έν :
class Chapter01 : public GameEngineLevel
{
public:
	// constrcuter destructer
	Chapter01();
	~Chapter01();

	// delete Function
	Chapter01(const Chapter01& _Other) = delete;
	Chapter01(Chapter01&& _Other) noexcept = delete;
	Chapter01& operator=(const Chapter01& _Other) = delete;
	Chapter01& operator=(Chapter01&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
private:

};