#include "CameraUpdate.h"
#include "PlayerUpdate.h"

FloatRect* CameraUpdate::getPositionPointer()
{
    return &m_Position;
}
void CameraUpdate::assemble(
    shared_ptr<LevelUpdate> levelUpdate,
    shared_ptr<PlayerUpdate> playerUpdate)

{
    m_PlayerPosition = playerUpdate->getPositionPointer();
}
InputReceiver* CameraUpdate::getInputReceiver()
{
    m_InputReceiver = new InputReceiver;
    m_ReceivesInput = true;
    return m_InputReceiver;
}
void CameraUpdate::handleInput()
{
    m_Position.width = 1.0f;
    for (const Event& event : m_InputReceiver->getEvents())
    {
        // Обработка событий прокрутки колеса мыши для масштабирования
        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
            {
                // Изменение коэффициента масштабирования на основе дельты
                m_Position.width *= (event.mouseWheelScroll.delta > 0) ? 0.95f : 1.05f;
            }
        }
        m_InputReceiver->clearEvents();
    }
}
void CameraUpdate::update(float fps)
{
    if (m_ReceivesInput)
    {
        handleInput();
        m_Position.left = m_PlayerPosition->left;
        m_Position.top = m_PlayerPosition->top;
    }
    else
    {
        m_Position.left = m_PlayerPosition->left;
        m_Position.top = m_PlayerPosition->top;
        m_Position.width = 1;
    }
}