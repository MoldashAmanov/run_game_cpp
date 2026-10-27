#pragma once
#include "Graphics.h"
#include <memory>


class Animator;

class RainGraphics : public Graphics
{
    private:
        FloatRect* m_PlayerPosition;
        int m_VertexStartIndex;
        Vector2f m_Scale;
        float m_HorizontalOffset;
        float m_VerticalOffset;
        Animator* m_Animator;
        IntRect* m_SectionToDraw;
    public:
        RainGraphics(FloatRect* m_PlayerPosition,
            float horizontalOffset,
            float verticalOffset,
            int rainCoveragePerObject);

        // Из Graphics : Component
        void draw(VertexArray& canvas) override;
        void assemble(VertexArray& canvas,
        shared_ptr<Update> genericUpdate,
        IntRect texCoords) override;
};