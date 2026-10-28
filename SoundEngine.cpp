#include "SoundEngine.h"
#include <assert.h>

SoundEngine* SoundEngine::m_s_Instance = nullptr;
bool SoundEngine::mMusicIsPlaying = false;
Music SoundEngine::music;
SoundBuffer SoundEngine::m_ClickBuffer;
Sound SoundEngine::m_ClickSound;
SoundBuffer SoundEngine::m_JumpBuffer;
Sound SoundEngine::m_JumpSound;
SoundBuffer SoundEngine::m_FireballLaunchBuffer;
Sound SoundEngine::m_FireballLaunchSound;
SoundEngine::SoundEngine()
{
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
    m_ClickBuffer.loadFromFile("sounds/click.wav");
    m_ClickSound.setBuffer(m_ClickBuffer);
    m_JumpBuffer.loadFromFile("sounds/jump.wav");
    m_JumpSound.setBuffer(m_JumpBuffer);

    Listener::setDirection(1.f, 0.f, 0.f);
    Listener::setUpVector(1.f, 1.f, 0.f);
    Listener::setGlobalVolume(100.f);

    m_FireballLaunchBuffer.loadFromFile("sounds/fireballLaunch.wav");
    m_FireballLaunchSound.setBuffer(m_FireballLaunchBuffer);
}
void SoundEngine::playClick()
{
    m_ClickSound.play();
}
void SoundEngine::playJump()
{
    m_JumpSound.play();
}
void SoundEngine::startMusic()
{
    music.openFromFile("music/music.wav");
    m_s_Instance->music.play();
    m_s_Instance->music.setLoop(true);
    mMusicIsPlaying = true;
}
void SoundEngine::pauseMusic()
{
    m_s_Instance->music.pause();
    mMusicIsPlaying = false;
}
void SoundEngine::resumeMusic()
{
    m_s_Instance->music.play();
    mMusicIsPlaying = true;
}
void SoundEngine::stopMusic()
{
    m_s_Instance->music.stop();
    mMusicIsPlaying = false;
}
void SoundEngine::playFireballLaunch(
    Vector2f playerPosition,
    Vector2f soundLocation)
{
    m_FireballLaunchSound.setRelativeToListener(true);

    if (playerPosition.x > soundLocation.x)
    // Звук слева
    {
        Listener::setPosition(0, 0, 0.f);
        m_FireballLaunchSound.setPosition(-100, 0, 0.f);
        m_FireballLaunchSound.setMinDistance(100);
        m_FireballLaunchSound.setAttenuation(0);
    }
    else // Звук справа
    {
        Listener::setPosition(0, 0, 0.f);
        m_FireballLaunchSound.setPosition(100, 0, 0.f);
        m_FireballLaunchSound.setMinDistance(100);
        m_FireballLaunchSound.setAttenuation(0);
    }
    m_FireballLaunchSound.play();
}