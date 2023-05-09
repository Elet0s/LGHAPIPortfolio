#pragma once
class Helper
{
public:
	Helper();
	~Helper();


	Helper(const Helper& _Other) = delete;
	Helper(Helper&& _Other) noexcept = delete;
	Helper& operator=(const Helper& _Other) = delete;
	Helper& operator=(Helper&& _Other) noexcept = delete;
protected:

private:

};