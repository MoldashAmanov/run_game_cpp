#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <memory>

class LevelUpdate;
class PlayerUpdate;
class Update : public Component
{
    private:
    public:
        Update();
        virtual void assemble(
            shared_ptr<LevelUpdate> levelUpdate,
            shared_ptr<PlayerUpdate> playerUpdate) = 0;
        virtual void update(float timeSinceLastUpdate) = 0;
};