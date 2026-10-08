#include "PlayerUpdate.h"
#include "SoundEngine.h"
#include "InputReceiver.h" 
#include "LevelUpdate.h"
#include <memory>

PlayerUpdate::PlayerUpdate()
    : m_InputReceiver(new InputReceiver())
{
}
PlayerUpdate::~PlayerUpdate()
{
    delete m_InputReceiver;
    m_InputReceiver = nullptr;
}
FloatRect* PlayerUpdate:: getPositionPointer()
{
    return &m_Position;
}
bool* PlayerUpdate::getGroundedPointer()
{
    return &m_IsGrounded;
}
InputReceiver* PlayerUpdate::getInputReceiver()
{
    return m_InputReceiver; 
}
void PlayerUpdate::assemble(
    shared_ptr<LevelUpdate> levelUpdate,
    shared_ptr<PlayerUpdate> playerUpdate)
    {
        SoundEngine::startMusic();
        m_Position.width = PLAYER_WIDTH;
        m_Position.height = PLAYER_HEIGHT;
        m_IsPaused = levelUpdate->getIsPausedPointer();
    }
void PlayerUpdate::handleInput()
{
    m_InputReceiver->clearEvents();
}
void PlayerUpdate::update(float timeTakenThisFrame)
{
    handleInput();
}