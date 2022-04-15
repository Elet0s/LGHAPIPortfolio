#pragma once
class Skel
{
private:
	// constrcuter destructer
	Skel();
	~Skel();

	// delete Function
	Skel(const Skel& _Other) = delete;
	Skel(Skel&& _Other) noexcept = delete;
	Skel& operator=(const Skel& _Other) = delete;
	Skel& operator=(Skel&& _Other) noexcept = delete;
};