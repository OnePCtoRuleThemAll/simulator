#pragma once

#include "Geometry2D/Geometry2D.h"

/// <summary> Abstract parent class of all agents. </summary>
template<typename T>
class Agent
{
public:
	/// <summary> Destruktor. </summary>
	virtual ~Agent();

	/// <summary> Assign operator. </summary>
	/// <param name = "other"> Source objcet of taken properties.</param>
	/// <returns> Adress of the object. </returns>
	Agent& operator=(const Agent& other);

	/// <summary>  Assigning object. </summary>
	/// <param name = "other"> Source objcet of taken properties. </param>
	/// <returns> Adress of the object. </returns>
	virtual Agent& assign(const Agent& other) = 0;

	/// <summary> Equals operator. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	bool operator==(const Agent& other);

	/// <summary> Objcet equality. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	virtual bool equals(const Agent& other) = 0;

	virtual void execute() = 0;

	void act();

	void moveTo(Geometry2D::Point<T>& newPosition);

private:
	Geometry2D::Point<T>* mPosition;

	Geometry2D::Vector<T>* mDirection;
};