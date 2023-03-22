#pragma once
#include "../Point.h"
#include "../Rectangle.h"

namespace Geometry2D
{
	/// <summary> Abstract parent class of all geometrical objects. </summary>
	class GeomteryBase 
	{
	public:
		/// <summary> Destruktor. </summary>
		virtual ~GeomteryBase();

		/// <summary> Assign operator. </summary>
		/// <param name = "other"> Source objcet of taken properties.</param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& operator=(const GeomteryBase& other);

		/// <summary>  Assigning object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		virtual GeomteryBase& assign(const GeomteryBase& other) = 0;

		/// <summary> Equals operator. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal. </returns>
		bool operator==(const GeomteryBase& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal. </returns>
		virtual bool equals(const GeomteryBase& other) = 0;

		template<typename T>
		bool isPointIn(const Point<T>& point);

		Rectangle<float>* boundingRec;
	};

	template<typename T>
	inline bool GeomteryBase::isPointIn(const Point<T>& point)
	{
		return false;
	}

	using MyRectangle = Rectangle<MyFloat>;
}