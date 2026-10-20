#pragma once
#include "Graphics.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

class PlatformGraphics : public Graphics
{
    private:
        FloatRect* m_Position = nullptr;
        int m_VertexStartIndex = -1;
    public:
        // Из Graphics : Component
        void draw(VertexArray& canvas) override;
        void assemble(VertexArray& canvas,
            shared_ptr<Update> genericUpdate,
            IntRect texCoords) override;
};