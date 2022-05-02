#include"Monster.h"

Monster::Monster()
	:MonsterRender_(nullptr)
{

}
Monster::~Monster()
{

}
void Monster::Start()
{
	SetPosition({ 960,490 });
	MonsterRender_ = CreateRendererToScale("MonsterR.bmp", { 256 ,256 });
	MonsterRender_->CreateAnimation("MonsterL.bmp", "MonsterL", 0, 11, 0.069f, true);
	MonsterRender_->CreateAnimation("MonsterR.bmp", "MonsterR", 0, 11, 0.069f, true);
	MonsterRender_->ChangeAnimation("MonsterR");
}
void Monster::Update()
{

}