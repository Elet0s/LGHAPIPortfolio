#pragma once
class Zdrada
{
private:
	// constrcuter destructer
	Zdrada();
	~Zdrada();

	// delete Function
	Zdrada(const Zdrada& _Other) = delete;
	Zdrada(Zdrada&& _Other) noexcept = delete;
	Zdrada& operator=(const Zdrada& _Other) = delete;
	Zdrada& operator=(Zdrada&& _Other) noexcept = delete;
};