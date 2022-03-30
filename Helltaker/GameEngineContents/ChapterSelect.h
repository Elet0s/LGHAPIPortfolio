#pragma once
class ChapterSelect
{
private:
	// constrcuter destructer
	ChapterSelect();
	~ChapterSelect();

	// delete Function
	ChapterSelect(const ChapterSelect& _Other) = delete;
	ChapterSelect(ChapterSelect&& _Other) noexcept = delete;
	ChapterSelect& operator=(const ChapterSelect& _Other) = delete;
	ChapterSelect& operator=(ChapterSelect&& _Other) noexcept = delete;
};