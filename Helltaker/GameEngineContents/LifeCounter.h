#pragma once
class LifeCounter
{
private:
	// constrcuter destructer
	LifeCounter();
	~LifeCounter();

	// delete Function
	LifeCounter(const LifeCounter& _Other) = delete;
	LifeCounter(LifeCounter&& _Other) noexcept = delete;
	LifeCounter& operator=(const LifeCounter& _Other) = delete;
	LifeCounter& operator=(LifeCounter&& _Other) noexcept = delete;
};