#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

// #pragma comment(lib, "msimg32.lib")

GameEngineImage::GameEngineImage()
	: ImageDC_(nullptr)
{
}

GameEngineImage::~GameEngineImage()
{
	// window에서 할당해온녀석들은 릭으로 체크가 안되지만
	// 지워주는게 깔끔하다.
	// 당연히 윈도우에게 할당해왔으므로 윈도우의 함수를 이용해서 지워야한다.

	if (nullptr != BitMap_)
	{
		DeleteObject(BitMap_);
		BitMap_ = nullptr;
	}

	if (nullptr != OldBitMap_)
	{
		DeleteObject(OldBitMap_);
		OldBitMap_ = nullptr;
	}

	if (nullptr != ImageDC_)
	{
		DeleteDC(ImageDC_);
		ImageDC_ = nullptr;
	}
}

bool GameEngineImage::Create(HDC _DC)
{
	ImageDC_ = _DC;
	ImageScaleCheck();
	return true;
}

bool GameEngineImage::Create(float4 _Scale)
{
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.");
		return false;
	}

	// 먼저 비트맵을 만들어
	// 이미지 크기만한
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// 비어있지가 않아요
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc 생성에 실패했습니다.");
	}

	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	ImageScaleCheck();

	return true;
}

void GameEngineImage::ImageScaleCheck()
{
	// DC 내부에 박혀있는 BITMAP을 꺼내오는 함수
	HBITMAP CurrentBitMap = (HBITMAP)GetCurrentObject(ImageDC_, OBJ_BITMAP);
	GetObject(CurrentBitMap, sizeof(BITMAP), &Info_);
}

void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0, 0 }, { 0, 0 }, _Other->GetScale());
}

// 다른 이미지가 들어와서
void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale)
{
	// 윈도우에서 지원해주는 일반적인 dc vs dc의 복사함수입니다.
	BitBlt(
		ImageDC_, // 여기에 복사해라.
		_CopyPos.ix(), // 내 이미지의 이 부분 x
		_CopyPos.iy(), // 내 이미지의 이 부분 y 에 복사해라
		_OtherPivotScale.ix(), // 내 이미지의 이 크기만큼 x
		_OtherPivotScale.iy(), // 내 이미지의 이 크기만큼 y
		_Other->ImageDC_, // 복사하려는 대상은
		_OtherPivot.ix(), // 복사하려는 대상의 시작점X
		_OtherPivot.iy(),// 복사하려는 대상의 시작점Y
		SRCCOPY // 복사하라는 명령
	);
}