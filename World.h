#pragma once
#include <list>
#include <vector>
#include "Obstacle.h"
#include "Geometry2D/GeometryBase.h"
#include "Rendering/DrawTriangles.h"

class Agent;
class World
{
public:
	/// <summary>Parameterized constructor. </summary>
	/// <param name = "point1"> Top left corner of the world. </param>
	/// <param name = "point1"> Bottom right corner of the world. </param>
	/// <param name = "granulate"> Number used to determin to how many blocks we want devide world. </param>
	World(const Geometry2D::MyPoint& point1, const Geometry2D::MyPoint& point2, float granulate);

	/// <summary>Destructor. </summary>
	~World();

	void insert(Agent* pAgent);

	bool remove(Agent* pAgent);

	std::list<Agent*>* searchAgents(Agent* pAgent, Geometry2D::GeomteryBase* form);

	std::list<Obstacle*>* searchObstacles(Geometry2D::GeomteryBase* form);

	void update(Agent* pAgent);

	void runWorld();

	Geometry2D::MyPoint* getTopPoint();

	Geometry2D::MyPoint* getBottomPoint();

	std::vector<std::list<Agent*>*>* matrix;

	std::vector<Obstacle*>* obstacles;

	Geometry2D::MyPoint* mPointTop;

	Geometry2D::MyPoint* mPointBottom;

	DrawTriangles* mAgentDrawer;

	unsigned int mMatrixColumns;
	
	unsigned int mMatrixRows;

	unsigned int mapping(Geometry2D::GeomteryBase::MyFloat posX, Geometry2D::GeomteryBase::MyFloat posY);
};