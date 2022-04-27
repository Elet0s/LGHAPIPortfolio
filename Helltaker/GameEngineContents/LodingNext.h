#pragma once
class LodingNext
{
private:
	// constrcuter destructer
	LodingNext();
	~LodingNext();

	// delete Function
	LodingNext(const LodingNext& _Other) = delete;
	LodingNext(LodingNext&& _Other) noexcept = delete;
	LodingNext& operator=(const LodingNext& _Other) = delete;
	LodingNext& operator=(LodingNext&& _Other) noexcept = delete;
};