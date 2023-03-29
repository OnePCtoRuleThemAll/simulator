#pragma once
#include "../Geometry2D/Geometry2D.h"
#include "../Rendering/Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <math.h>

namespace Shapes
{
	template<typename T>
	class Shape
	{
	public:
		Shape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);

	protected:
		Geometry2D::Point<T>* mWorldStart;
		Geometry2D::Point<T>* mWorldEnd;

	private:
		float mapBetweenSystems(T value, bool vertical);
	};

	template<typename T>
	inline Shape<T>::Shape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd) :
		mWorldStart(&worldStart),
		mWorldEnd(&worldEnd)
	{
	}

	template<typename T>
	inline float Shape<T>::mapBetweenSystems(T value, bool vertical)
	{
		if (vertical) {
			return (1.0f + ((-1.0f - 1.0f) / (this->mWorldEnd->mPositionY - this->mWorldStart->mPositionY)) * ((float)value - this->mWorldStart->mPositionY));
		}
		else {
			return (-1.0f + ((1.0f + 1.0f) / (this->mWorldEnd->mPositionX - this->mWorldStart->mPositionX)) * ((float)value - this->mWorldStart->mPositionX));
		}
		return 0.0f;
	}
}
