#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Factory.h"
#include "InputDispatcher.h"
#include <memory>

using namespace std;
using namespace sf;

int main()
{
    // Создаем полноэкранное окно
    RenderWindow window(VideoMode::getDesktopMode(), "Booster", Style::Fullscreen);
    // VertexArray для хранения всех изображений
    VertexArray canvas(Quads, 0);
    // Этот объект можно отправлять события любому объекту
    InputDispatcher inputDispatcher(&window);
    // Все будет игровым объектом
    // Этот вектор будет содержать их все
    vector <GameObject> gameObjects;
    // Этот класс обладает всем необходимым для создания
    // игровых объектов, которые выполянют множество разных задач
    Factory factory(&window);
    // Этот вызов передаст вектор игровых объектов, холст для отрисовки
    // и диспетчер ввода в фабрику для настройки игры
    factory.loadLevel(gameObjects, canvas, inputDispatcher);
    // Часы для отслеживания времени
    Clock clock;
    // Цвет, который мы используем для фона
    const Color BACKGROUND_COLOR(100, 100, 100, 255);
    // Игровой цикл
    while (window.isOpen())
    {
        // Измеряем время, затраченное на этот кадр
        float timeTakenInSeconds = clock.restart().asSeconds();
        // Обрабатываем ввод игрока
        inputDispatcher.dispatchInputEvents();
        // Очищаем предыдущий кадр
        window.clear(BACKGROUND_COLOR);
        // Обновляем все игровые объекты
        for(auto& gameObject : gameObjects)
        {
            gameObject.update(timeTakenInSeconds);
        }
        // Отрисовываем все игровые объекты на холсте
        for (auto& gameObject : gameObjects)
        {
            gameObject.draw(canvas);
        }

        // Временный код до следующей главы
        window.draw(canvas, factory.m_Texture);
        // Показываем новый кадр
        window.display();
    }
    return 0;
}   