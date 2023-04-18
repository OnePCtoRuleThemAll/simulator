#include "TestAgent.h"

TestAgent::TestAgent(World* world, int ver, int hor):
	mVerticalOffset(ver),
	mHorizontalOffset(hor)
{
	this->mWorld = world;
	this->mPosition = new Geometry2D::MyPoint(50, 50);
	this->mOldPosition = new Geometry2D::MyPoint(*this->mPosition);
	this->mDirection = new Geometry2D::MyVector(1, 0);
	this->mOldDirection = new Geometry2D::MyVector(1, 0);
	this->mShape = new Shapes::TriangleDrawerDynamic<Geometry2D::GeomteryBase::MyFloat>(*this->mOldPosition, *this->mOldDirection,
		*this->mWorld->mPointTop, *this->mWorld->mPointBottom, this->mWorld->mAgentDrawer);
	this->mBehavoir = new std::vector<Behavior*>();
	this->mBehavoir->push_back(new TestBehaviour());
}

TestAgent::~TestAgent()
{
	delete this->mDirection;
	delete this->mPosition;
	delete this->mOldPosition;
	delete this->mShape;
	delete this->mBehavoir;

	this->mDirection = nullptr;
	this->mPosition = nullptr;
	this->mOldPosition = nullptr;
	this->mShape = nullptr;
	this->mBehavoir = nullptr;
}

Agent& TestAgent::assign(const Agent& other)
{
	return *this;
}

bool TestAgent::equals(const Agent& other)
{
	if (this == &other) {
		return true;
	}
	else {
		const TestAgent* otherAgent = dynamic_cast<const TestAgent*>(&other);
		if (otherAgent->mDirection->equals(*this->mDirection) && otherAgent->mPosition->equals(*this->mPosition) && 
			otherAgent->mOldPosition->equals(*this->mOldPosition) && otherAgent->mWorld == this->mWorld) {
			return true;
		}
	}
	return false;
}

Geometry2D::MyVector* TestBehaviour::behave(Agent* pAgent)
{
	TestAgent* newAgent = dynamic_cast<TestAgent*>(pAgent);
	Geometry2D::MyVector* result = new Geometry2D::MyVector(1, 0);
	// Move down until reaching (70,70)
	if (pAgent->mPosition->mPositionX == 70.0 + newAgent->mHorizontalOffset && pAgent->mPosition->mPositionY < 70.0 + newAgent->mVerticalOffset) {
		result->mDeltaX = 0;
		result->mDeltaY = 0.25;
	}
	// Move left until reaching (50,70)
	else if (pAgent->mPosition->mPositionX > 50.0 - newAgent->mHorizontalOffset && pAgent->mPosition->mPositionY == 70.0 + newAgent->mVerticalOffset) {
		result->mDeltaX = -0.25;
		result->mDeltaY = 0;
	}
	// Move up until reaching (50,50)
	else if (pAgent->mPosition->mPositionX == 50.0 - newAgent->mHorizontalOffset && pAgent->mPosition->mPositionY > 50.0 - newAgent->mVerticalOffset) {
		result->mDeltaX = 0;
		result->mDeltaY = -0.25;
	}
	// Move right until reaching (70,50)
	else if (pAgent->mPosition->mPositionX < 70.0 + newAgent->mHorizontalOffset && pAgent->mPosition->mPositionY == 50.0 - newAgent->mVerticalOffset) {
		result->mDeltaX = 0.25;
		result->mDeltaY = 0;
	}

	return result;

}
