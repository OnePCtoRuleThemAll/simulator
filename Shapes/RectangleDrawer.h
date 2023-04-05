#pragma once
#include "StaticShape.h"

namespace Shapes {
    template <typename T>
    class RectangleDrawer :
        public StaticShape<T>
    {
    public:
        RectangleDrawer(Geometry2D::Point<T> point1, Geometry2D::Point<T> point2,
            Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
        ~RectangleDrawer();
        void drawRectangle();

    private:
        float positions[8];
        Shader shaderObject;
    };
    template<typename T>
    inline RectangleDrawer<T>::RectangleDrawer(Geometry2D::Point<T> point1, Geometry2D::Point<T> point2,
        Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd) :
        StaticShape<T>::StaticShape(worldStart, worldEnd)
    {
        this->positions[0] = Shape<T>::mapBetweenSystems(point1.mPositionX, false);
        this->positions[1] = Shape<T>::mapBetweenSystems(point1.mPositionY, true);
        this->positions[2] = Shape<T>::mapBetweenSystems(point2.mPositionX, false);
        this->positions[3] = Shape<T>::mapBetweenSystems(point1.mPositionY, true);
        this->positions[4] = Shape<T>::mapBetweenSystems(point2.mPositionX, false);
        this->positions[5] = Shape<T>::mapBetweenSystems(point2.mPositionY, true);
        this->positions[6] = Shape<T>::mapBetweenSystems(point1.mPositionX, false);
        this->positions[7] = Shape<T>::mapBetweenSystems(point2.mPositionY, true);
    }

    template<typename T>
    inline RectangleDrawer<T>::~RectangleDrawer()
    {
        delete this->shaderObject;
        delete[] this->positions;
    }

    template<typename T>
    inline void RectangleDrawer<T>::drawRectangle()
    {
        ShaderProgramSource source = this->shaderObject.ParseShader("Resources/Shaders/Circle.shader");
        unsigned int shader = this->shaderObject.CreateShader(source.VertexSource, source.FragmentSource);

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        unsigned int vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->positions), this->positions, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        int indicies[] = { 0, 1, 2, 0, 2, 3};

        unsigned int ebo;
        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

        glUseProgram(shader);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glUseProgram(0);
        glDeleteProgram(shader);
    }
}


