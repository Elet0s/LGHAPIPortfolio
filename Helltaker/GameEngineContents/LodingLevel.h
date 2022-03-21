#pragma once
class LodingLevel
{
private:
	// constrcuter destructer
	LodingLevel();
	~LodingLevel();

	// delete Function
	LodingLevel(const LodingLevel& _Other) = delete;
	LodingLevel(LodingLevel&& _Other) noexcept = delete;
	LodingLevel& operator=(const LodingLevel& _Other) = delete;
	LodingLevel& operator=(LodingLevel&& _Other) noexcept = delete;
};