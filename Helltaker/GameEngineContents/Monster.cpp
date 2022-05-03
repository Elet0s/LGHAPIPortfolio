#include"Monster.h"

Monster::Monster()
	:MonsterRender_(nullptr)
	, RState_(true)
{

}
Monster::~Monster()
{

}


	//MonsterRender_ = CreateRenderer();
	//MonsterRender_->CreateAnimation("MonsterL.bmp", "MonsterL", 0, 11, 0.069f, true);
	//MonsterRender_->CreateAnimation("MonsterR.bmp", "MonsterR", 0, 11, 0.069f, true);
	//if (RState_ == true)
	//{
	//	MonsterRender_->ChangeAnimation("MonsterR");
	//}
	//else
	//{
	//	MonsterRender_->ChangeAnimation("MonsterL");
	//}
