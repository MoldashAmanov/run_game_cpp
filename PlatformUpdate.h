#pragma once
#include "Update.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

class PlatformUpdate : public Update
{
    private:
        FloatRect m_Position;
        FloatRect* m_PlayerPosition = nullptr;
        bool* m_PlayerIsGrounded = nullptr;
    public:
        FloatRect* getPositionPointer();

        // Из Update : Component
        void update(float fps) override;
        void assemble(shared_ptr<LevelUpdate> levelUpdate,
            shared_ptr<PlayerUpdate> playerUpdate) override;
};
