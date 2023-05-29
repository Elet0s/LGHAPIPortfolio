#include"ChapterCounter.h"

ChapterCounter::ChapterCounter()
	:ChapterFont_()
	, ChapterPoint_(0)
	, ChapterPointStr_()
	, SetEnter_(false)
{

}
ChapterCounter::~ChapterCounter()
{

}

void ChapterCounter::Start()
{
}
void ChapterCounter::Render()
{
	if (SetEnter_ == true)
	{
		ChapterPointStr_ = std::to_string(ChapterPoint_);
		if (ChapterPointStr_.size() == 1)
		{
			ChapterFont_.Draw(ChapterPointStr_, { 1670.0f, 730.0f }, RGB(255, 255, 255), 200, 50);
		}
		else if (ChapterPointStr_.size() == 2)
		{
			ChapterFont_.Draw(ChapterPointStr_, { 1640.0f, 730.0f }, RGB(255, 255, 255), 200, 50);
		}
	}

}

void ChapterCounter::SetChapterPoint(int _ChapterPoint)
{
	ChapterPoint_ = _ChapterPoint;
	SetEnter_ = true;
}