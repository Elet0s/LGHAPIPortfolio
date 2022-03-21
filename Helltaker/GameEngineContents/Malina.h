#pragma once
class Malina
{
private:
	// constrcuter destructer
	Malina();
	~Malina();

	// delete Function
	Malina(const Malina& _Other) = delete;
	Malina(Malina&& _Other) noexcept = delete;
	Malina& operator=(const Malina& _Other) = delete;
	Malina& operator=(Malina&& _Other) noexcept = delete;
};