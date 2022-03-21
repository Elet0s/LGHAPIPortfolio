#pragma once
class Azazel
{
private:
	// constrcuter destructer
	Azazel();
	~Azazel();

	// delete Function
	Azazel(const Azazel& _Other) = delete;
	Azazel(Azazel&& _Other) noexcept = delete;
	Azazel& operator=(const Azazel& _Other) = delete;
	Azazel& operator=(Azazel&& _Other) noexcept = delete;
};