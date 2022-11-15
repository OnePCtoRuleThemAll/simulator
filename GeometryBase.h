#pragma once

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
		GeomteryBase& operator=(GeomteryBase& other);

		/// <summary>  Assigning object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		virtual GeomteryBase& assign(GeomteryBase& other) = 0;

		/// <summary> Equals operator. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal. </returns>
		bool operator==(GeomteryBase& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal. </returns>
		virtual bool equals(GeomteryBase& other) = 0;


	};
}