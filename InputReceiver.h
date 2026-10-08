#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class InputReceiver
{
    private:
        vector<Event> mEvents;
    public:
        void addEvent(Event event);
        vector<Event>& getEvents();
        void clearEvents();
};