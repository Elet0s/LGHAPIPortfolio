#pragma once
class Lucifer
{
private:
	// constrcuter destructer
	Lucifer();
	~Lucifer();

	// delete Function
	Lucifer(const Lucifer& _Other) = delete;
	Lucifer(Lucifer&& _Other) noexcept = delete;
	Lucifer& operator=(const Lucifer& _Other) = delete;
	Lucifer& operator=(Lucifer&& _Other) noexcept = delete;
};