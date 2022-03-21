#pragma once
class Modeus
{
private:
	// constrcuter destructer
	Modeus();
	~Modeus();

	// delete Function
	Modeus(const Modeus& _Other) = delete;
	Modeus(Modeus&& _Other) noexcept = delete;
	Modeus& operator=(const Modeus& _Other) = delete;
	Modeus& operator=(Modeus&& _Other) noexcept = delete;
};