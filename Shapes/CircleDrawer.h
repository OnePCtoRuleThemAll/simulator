#pragma once
#include "StaticShape.h"

namespace Shapes
{
	template <typename T>
	class CircleDrawer : 
		public StaticShape<T>
	{
	public:
		CircleDrawer(Geometry2D::Circle<T>& circle, Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
		~CircleDrawer();
		void draw() override;

	private:
		float xCoordinate;
		float yCoordinate;
		float radius;
		Shader shader;
	};


	template<typename T>
	inline CircleDrawer<T>::CircleDrawer(Geometry2D::Circle<T>& circle,	Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd):
		StaticShape<T>::StaticShape(worldStart, worldEnd)
	{
		this->xCoordinate = Shape<T>::mapBetweenSystems(circle.mCenter->mPositionX, false);
		this->yCoordinate = Shape<T>::mapBetweenSystems(circle.mCenter->mPositionY, true);
		this->radius = (float)circle.mRadius;
	}

	template<typename T>
	inline CircleDrawer<T>::~CircleDrawer()
	{
		delete this->xCoordinate;
		delete this->yCoordinate;
		delete this->radius;
		delete this->shader;
	}


	template<typename T>
	inline void CircleDrawer<T>::draw()
	{
		ShaderProgramSource source = this->shader.ParseShader("Resources/Shaders/Circle.shader");

		unsigned int shader = this->shader.CreateShader(source.VertexSource, source.FragmentSource);
		glUseProgram(shader);

		int i;
		int triangleAmount = 40; //# of triangles used to draw circle

		//GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * atan(1) * 4;

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(this->xCoordinate, this->yCoordinate); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				this->xCoordinate + (this->radius * cos(i * twicePi / triangleAmount)),
				this->yCoordinate + (this->radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();

		glUseProgram(0);
		glDeleteProgram(shader);
	}

}