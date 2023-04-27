#include "World.h"
#include "Agent.h"
#include "Rendering/Window.h"

World::World(const Geometry2D::MyPoint& point1, const Geometry2D::MyPoint& point2, float granulate) :
	mPointTop(new Geometry2D::MyPoint(point1)),
	mPointBottom(new Geometry2D::MyPoint(point2))
{
	mMatrixBlockSize = granulate;
	mMatrixColumns = ceil((mPointBottom->mPositionX - mPointTop->mPositionX) / granulate);
	mMatrixRows = ceil((mPointBottom->mPositionY - mPointTop->mPositionY) / granulate);

	matrix = new std::vector<std::list<Agent*>*>();

	for (int i = 0; i < mMatrixColumns * mMatrixRows; i++) {
		std::list<Agent*>* list = new std::list<Agent*>();
		matrix->push_back(list);
	}

	obstacles = new std::vector<Obstacle*>();

	toUpdate = new std::vector<Agent*>();

	mAgentDrawer = new DrawTriangles();
}

World::~World()
{
	for (int i = 0; i < matrix->size(); i++) {
		for (Agent* agent : *(matrix->at(i))) {
			delete agent;
		}
	}

	matrix->clear();

	delete matrix;

	matrix = nullptr;
}

void World::insert(Agent* pAgent)
{
	int spotVector = mapping(pAgent->getPosition()->mPositionX, pAgent->getPosition()->mPositionY);
	matrix->at(spotVector)->push_back(pAgent);
}

bool World::remove(Agent* pAgent)
{
	int spotVector = mapping(pAgent->getPosition()->mPositionX, pAgent->getPosition()->mPositionY);
	auto itr = matrix->at(spotVector)->begin();
	for (Agent* agent : *(matrix->at(spotVector))) {
		if (agent->equals(*pAgent)) {
			matrix->at(spotVector)->erase(itr);
			return true;
		}
		itr++;
	}
	return false;
}

std::list<Agent*>* World::searchAgents(Agent* pAgent, Geometry2D::GeomteryBase* form)
{
	Geometry2D::GeomteryBase::MyFloat topX = (mPointTop->mPositionX < form->boundingRec->mTopPoint->mPositionX) ? form->boundingRec->mTopPoint->mPositionX : mPointTop->mPositionX;
	Geometry2D::GeomteryBase::MyFloat topY = (mPointTop->mPositionY < form->boundingRec->mTopPoint->mPositionY) ? form->boundingRec->mTopPoint->mPositionY : mPointTop->mPositionY;
	Geometry2D::GeomteryBase::MyFloat bottomX = (mPointBottom->mPositionX > form->boundingRec->mBottomPoint->mPositionX) ? form->boundingRec->mBottomPoint->mPositionX : mPointBottom->mPositionX;
	Geometry2D::GeomteryBase::MyFloat bottomY = (mPointBottom->mPositionY > form->boundingRec->mBottomPoint->mPositionY) ? form->boundingRec->mBottomPoint->mPositionY : mPointBottom->mPositionY;
	std::list<Agent*>* list = new std::list<Agent*>();

	int point1Order = mapping(topX, topY);
	int point2Order = mapping(bottomX, topY);
	int blocksBetween = point2Order - point1Order;
	int point3Order = mapping(topX, bottomY);

	for (int i = point1Order; i <= point3Order; i += mMatrixColumns) {
		for (int j = i; j <= i + blocksBetween; j++) {
			for (Agent* agent : *(matrix->at(j))) {
				if (form->isPointIn(*agent->getPosition())) {
					if (agent != pAgent) {
						list->push_back(agent);
					}
				}
			}
		}
		point2Order += mMatrixColumns;
	}
	return list;
}

std::list<Obstacle*>* World::searchObstacles(Geometry2D::GeomteryBase* form)
{
	std::list<Obstacle*>* list = new std::list<Obstacle*>();

	for (int i = 0; i < obstacles->size(); i++) {
		if (obstacles->at(i)->mForm->boundingRec->intersectionRectangle(*form->boundingRec)) {
			list->push_back(obstacles->at(i));
		}
	}
	
	return list;
}

void World::shouldAgentUpdate(Agent* pAgent)
{
	int spotVector = mapping(pAgent->getPosition()->mPositionX, pAgent->getPosition()->mPositionY);
	int spotVectorOld = mapping(pAgent->getOldPosition()->mPositionX, pAgent->getOldPosition()->mPositionY);

	if (spotVector != spotVectorOld) {
		this->toUpdate->push_back(pAgent);
	}
}

void World::update(Agent* pAgent)
{
	int spotVectorOld = mapping(pAgent->getOldPosition()->mPositionX, pAgent->getOldPosition()->mPositionY);
	
	auto itr = matrix->at(spotVectorOld)->begin();
	bool erased = false;
	for (Agent* agent : *(matrix->at(spotVectorOld))) {
		if (agent->equals(*pAgent)) {
			matrix->at(spotVectorOld)->erase(itr);
			erased = true;
			break;
		}
		++itr;
	}
	if (erased) {
		insert(pAgent);
	}
}

void World::runWorld()
{
	glClear(GL_COLOR_BUFFER_BIT);

	toUpdate->clear();
	for (int i = 0; i < matrix->size(); i++) {
		for (Agent* agent : *(matrix->at(i))) {
			agent->act();
			shouldAgentUpdate(agent);
		}
	}
	for (int i = 0; i < toUpdate->size(); i++) {
		this->update(toUpdate->at(i));
	}

	for (int i = 0; i < obstacles->size(); i++) {
		obstacles->at(i)->mShape->draw();
	}

	this->mAgentDrawer->drawElements();
	/* Swap front and back buffers */
	glfwSwapBuffers(Window::getInstance().getWindow());

	/* Poll for and process events */
	glfwPollEvents();
}

Geometry2D::MyPoint* World::getTopPoint()
{
	return mPointTop;
}

Geometry2D::MyPoint* World::getBottomPoint()
{
	return mPointBottom;
}

unsigned int World::mapping(Geometry2D::GeomteryBase::MyFloat posX, Geometry2D::GeomteryBase::MyFloat posY)
{
	unsigned int columns = 0;
	unsigned int rows = 0;
	if (posX == mPointBottom->mPositionX ) {
		posX--;
	}
	if (posY == mPointBottom->mPositionY) {
		posY--;
	}
	if (mPointTop->mPositionX < 0) {
		columns = floor((posX - mPointTop->mPositionX) / mMatrixBlockSize);
	}
	else {
		columns = floor((posX) / mMatrixBlockSize);
	}

	if (mPointBottom->mPositionY < 0) {
		rows = floor((posY - mPointBottom->mPositionY) / mMatrixBlockSize);
	}
	else {
		rows = floor((posY) / mMatrixBlockSize);
	}

	return rows * mMatrixColumns + columns;
}

void World::insertObstacle(Obstacle* obstacle)
{
	obstacles->push_back(obstacle);
}
