#include "Factory.h"
#include "LevelUpdate.h"
#include "PlayerGraphics.h"
#include "PlayerUpdate.h"
#include "InputDispatcher.h"
#include <iostream>
#include <memory>


Factory::Factory(RenderWindow* window)
{
    m_Window = window;
    m_Texture = new Texture();
    if (!m_Texture->loadFromFile("graphics/texture.png"))
    {
        cout << "Texture isn't loaded";
        return;
    }
}
void Factory::loadLevel(
    vector<GameObject>& gameObjects,
    VertexArray& canvas,
    InputDispatcher& inputDispatcher)
{
    // Создаем игровой объект уровня
    GameObject level;
    shared_ptr<LevelUpdate> levelUpdate = make_shared<LevelUpdate>();
    level.addComponent(levelUpdate);
    gameObjects.push_back(level);

    // Создаем объект игрового персонажа
    GameObject player;
    shared_ptr<PlayerUpdate> playerUpdate = make_shared<PlayerUpdate>();
    playerUpdate->assemble(levelUpdate, nullptr);
    player.addComponent(playerUpdate);

    inputDispatcher.registerNewInputReceiver(playerUpdate->getInputReceiver());

    shared_ptr<PlayerGraphics> playerGraphics = make_shared<PlayerGraphics>();
    playerGraphics->assemble(canvas, playerUpdate, IntRect(PLAYER_TEX_LEFT, PLAYER_TEX_TOP, PLAYER_TEX_WIDTH, PLAYER_TEX_HEIGHT));
    player.addComponent(playerGraphics);

    gameObjects.push_back(player);

    // Передаем LevelUpdate информацию о персонаже
    levelUpdate->assemble(nullptr, playerUpdate);
}