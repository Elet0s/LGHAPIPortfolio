#pragma once
class Trap
{
private:
	// constrcuter destructer
	Trap();
	~Trap();

	// delete Function
	Trap(const Trap& _Other) = delete;
	Trap(Trap&& _Other) noexcept = delete;
	Trap& operator=(const Trap& _Other) = delete;
	Trap& operator=(Trap&& _Other) noexcept = delete;
};