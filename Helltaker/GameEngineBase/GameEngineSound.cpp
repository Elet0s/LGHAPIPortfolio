#include "GameEngineSound.h"
#include "GameEnginePath.h"
#include "GameEngineDebug.h"
#include "GameEngineString.h"

#pragma comment(lib, "fmod_vc.lib")

FMOD::System* SoundSystem_ = nullptr;

class SoundSystemCreater 
{
public:
	SoundSystemCreater() 
	{
		FMOD::System_Create(&SoundSystem_);

		if (nullptr == SoundSystem_)
		{
			MsgBoxAssert("»ç¿îµå ½Ã½ºÅÛ »ý¼º¿¡ ½ÇÆÐÇß½À´Ï´Ù.");
			return;
		}

		// ¿ì¸® ÄÄÇ»ÅÍ »ç¿îµå Ä«µå¿¡ ´ëÇÑ Á¤º¸¸¦ ¾ò¾î¿À°í
		if (FMOD_OK != SoundSystem_->init(32, FMOD_DEFAULT, nullptr))
		{
			MsgBoxAssert("»ç¿îµå ½Ã½ºÅÛ ¼³Á¤ÀÌ ½ÇÆÐÇß½À´Ï´Ù.");
			return;
		}

	}
};

SoundSystemCreater CreateInst = SoundSystemCreater();

GameEngineSound::GameEngineSound() 
{
<<<<<<< HEAD
	//FMOD::System_Create();
=======
	// FMOD::System_Create();
>>>>>>> ì´ê´€í˜• : ì§„ë„ ì—…ë°ì´íŠ¸
}

GameEngineSound::~GameEngineSound() 
{
}

bool GameEngineSound::Load(const std::string& _Path) 
{
	if (FMOD_OK != SoundSystem_->createSound(_Path.c_str(), FMOD_LOOP_NORMAL, nullptr, &Sound))
	{
		MsgBoxAssertString("»ç¿îµå ·Îµå¿¡ ½ÇÆÐÇß½À´Ï´Ù.\n °æ·Î : " + _Path);
		return false;
	}

	return true;
}

/// /////////////////////////////////////////////////////////////// ±â´É ¸Å´ÏÁö¸ÕÆ®

GameEngineSoundPlayer GameEngineSound::SoundPlayControl(const std::string& _Name)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	GameEngineSound* FindSound = FindRes(UpperName);

	if (nullptr == FindSound)
	{
		MsgBoxAssertString("Á¸ÀçÇÏÁö ¾Ê´Â »ç¿îµå¸¦ Àç»ýÇÏ·Á°í Çß½À´Ï´Ù.\n ÀÌ¸§ : " + UpperName);
		return GameEngineSoundPlayer();
	}

	FMOD::Channel* PlayControl = nullptr;

	SoundSystem_->playSound(FindSound->Sound, nullptr, false, &PlayControl);

	return GameEngineSoundPlayer(FindSound, PlayControl);
}

void GameEngineSound::SoundPlayOneShot(const std::string& _Name, int LoopCount /*= 1*/)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	GameEngineSound* FindSound = FindRes(UpperName);

	if (nullptr == FindSound)
	{
		MsgBoxAssertString("Á¸ÀçÇÏÁö ¾Ê´Â »ç¿îµå¸¦ Àç»ýÇÏ·Á°í Çß½À´Ï´Ù.\n ÀÌ¸§ : " + UpperName);
		return;
	}

	FMOD::Channel* PlayControl = nullptr;

	SoundSystem_->playSound(FindSound->Sound, nullptr, false, &PlayControl);

	PlayControl->setLoopCount(LoopCount);

	

}

void GameEngineSound::Update()
{
	if (nullptr == SoundSystem_)
	{
		return;
	}
	SoundSystem_->update();
}

/// /////////////////////////////////////////////////////////////// ¸Å´ÏÁö¸ÕÆ®

std::map<std::string, GameEngineSound*> GameEngineSound::AllRes;


GameEngineSound* GameEngineSound::FindRes(const std::string& _Name) 
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	std::map<std::string, GameEngineSound*>::iterator FindIter = AllRes.find(UpperName);

	if (FindIter == AllRes.end())
	{
		return nullptr;
	}

	return FindIter->second;
}
GameEngineSound* GameEngineSound::LoadRes(const std::string& _Path)
{
	GameEnginePath NewPath = GameEnginePath(_Path);
	return LoadRes(_Path, NewPath.GetFileName());	//°æ·Î¿Í ÆÄÀÏÀÌ¸§(ex.idle.bmp)À» MapÀÇ key,value·Î ³Ö±âÀ§ÇØ °¢°¢ ³Ñ°ÜÁØ´Ù.
}
GameEngineSound* GameEngineSound::LoadRes(const std::string& _Path, const std::string& _Name)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_Name);

	GameEngineSound* NewRes = new GameEngineSound();

	if (false == NewRes->Load(_Path))
	{
		delete NewRes;
		NewRes = nullptr;
		return nullptr;
	}

	AllRes.insert(std::make_pair(UpperName, NewRes));
	return nullptr;
}

void GameEngineSound::AllResourcesDestroy()
{
	for (std::pair<std::string, GameEngineSound*> Res : AllRes)
	{
		delete Res.second;
		Res.second = nullptr;
	}

	AllRes.clear();

	if (nullptr != SoundSystem_)
	{
		SoundSystem_->release();
		SoundSystem_ = nullptr;
	}
}

////////////////////////////////////////////////////////// »ç¿îµå ÇÃ·¹ÀÌ¾î

void GameEngineSoundPlayer::Stop() 
{
	if (nullptr == ControlHandle_)
	{
		MsgBoxAssert("»ç¿îµå ÄÁÆ®·Ñ Ã¤³Î¿¡ Ä¡¸íÀûÀÎ ¹®Á¦°¡ ÀÖ½À´Ï´Ù.\n");
		return;
	}

	ControlHandle_->stop();
}


GameEngineSoundPlayer::GameEngineSoundPlayer() 
	: Sound_(nullptr)
	, ControlHandle_(nullptr)
{

}

GameEngineSoundPlayer::GameEngineSoundPlayer(const GameEngineSoundPlayer& _Other) 
	: Sound_(_Other.Sound_)
	, ControlHandle_(_Other.ControlHandle_)
{

}

GameEngineSoundPlayer::GameEngineSoundPlayer(GameEngineSound* _Sound, FMOD::Channel* _ControlHandle)
	: Sound_(_Sound)
	, ControlHandle_(_ControlHandle)
{
	
}

GameEngineSoundPlayer::~GameEngineSoundPlayer() 
{

}