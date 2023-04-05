#pragma once

#include "Geometry2D/Geometry2D.h"
#include "World.h"
#include "Shapes/MovableShape.h"
#include "Behavior.h"

class World;
/// <summary> Abstract parent class of all agents. </summary>
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

	virtual void act() = 0;

	void moveTo(Geometry2D::MyVector& velocity);

	Geometry2D::MyPoint* getPosition();

	Geometry2D::MyPoint* getOldPosition();

	Geometry2D::MyVector* getDirection();

	void setDirection(Geometry2D::MyVector& direction);

	World* mWorld;

	World* getWorld();

	Shapes::MovableShape<Geometry2D::GeomteryBase::MyFloat>* mShape;

	Behavior* mBehavoir;

	void setWorld(World* world);

	Geometry2D::MyPoint* mPosition;

	Geometry2D::MyPoint* mOldPosition;

	Geometry2D::MyVector* mDirection;
};