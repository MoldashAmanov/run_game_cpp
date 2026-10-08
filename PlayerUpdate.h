#pragma once
#include "Update.h"
#include "InputReceiver.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

class PlayerUpdate : public Update
{
    private:
        const float PLAYER_WIDTH = 20.f;
        const float PLAYER_HEIGHT = 16.f;
        FloatRect m_Position;

        bool* m_IsPaused = nullptr;
        float m_Gravity = 165;
        float m_RunSpeed = 150;
        float m_BoostSpeed = 250;
        InputReceiver* m_InputReceiver = nullptr;

        Clock m_JumpClock;
        bool m_SpaceHeldDown = false;
        float m_JumpDuration = .50;
        float m_JumpSpeed = 400;
    public:
        PlayerUpdate();
        ~PlayerUpdate();
        bool m_RightIsHeldDown = false;
        bool m_LeftIsHeldDown = false;
        bool m_BoostIsHeldDown = false;
        bool m_IsGrounded;
        bool m_InJump = false;

        FloatRect* getPositionPointer();

        bool* getGroundedPointer();
        void handleInput();
        InputReceiver* getInputReceiver();

        // Из Update : Component
        void assemble(
            shared_ptr<LevelUpdate> levelUpdate,
            shared_ptr<PlayerUpdate> playerUpdate)
            override;

        void update(float fps) override;
};