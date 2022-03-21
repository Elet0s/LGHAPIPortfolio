#pragma once
class Skell
{
private:
	// constrcuter destructer
	Skell();
	~Skell();

	// delete Function
	Skell(const Skell& _Other) = delete;
	Skell(Skell&& _Other) noexcept = delete;
	Skell& operator=(const Skell& _Other) = delete;
	Skell& operator=(Skell&& _Other) noexcept = delete;
};