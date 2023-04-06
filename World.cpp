#include "World.h"
#include "Agent.h"

World::World(const Geometry2D::MyPoint& point1, const Geometry2D::MyPoint& point2, float granulate) :
	mPointTop(new Geometry2D::MyPoint(point1)),
	mPointBottom(new Geometry2D::MyPoint(point2))
{
	mMatrixColumns = ceil((mPointBottom->mPositionX - mPointTop->mPositionX) / granulate);
	mMatrixRows = ceil((mPointBottom->mPositionY - mPointTop->mPositionY) / granulate);

	matrix = new std::vector<std::list<Agent*>*>();

	for (int i = 0; i < mMatrixColumns * mMatrixRows; i++) {
		std::list<Agent*>* list = new std::list<Agent*>();
		matrix->push_back(list);
	}
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
	Geometry2D::GeomteryBase::MyFloat topY = (mPointTop->mPositionY < form->boundingRec->mTopPoint->mPositionX) ? form->boundingRec->mTopPoint->mPositionY : mPointTop->mPositionY;
	Geometry2D::GeomteryBase::MyFloat bottomX = (mPointTop->mPositionX > form->boundingRec->mBottomPoint->mPositionX) ? form->boundingRec->mBottomPoint->mPositionX : mPointTop->mPositionX;
	Geometry2D::GeomteryBase::MyFloat bottomY = (mPointTop->mPositionY > form->boundingRec->mBottomPoint->mPositionY) ? form->boundingRec->mBottomPoint->mPositionY : mPointTop->mPositionY;
	std::list<Agent*>* list = new std::list<Agent*>();

	int point1Order = mapping(topX, topY);
	int point2Order = mapping(bottomX, topY);
	int point3Order = mapping(topX, bottomY);

	for (int i = point1Order; i <= point3Order; i += mMatrixColumns) {
		for (int j = i; j <= point2Order; j++) {
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

void World::update(Agent* pAgent)
{
	int spotVector = mapping(pAgent->getPosition()->mPositionX, pAgent->getPosition()->mPositionY);
	int spotVectorOld = -1;
	if (pAgent->getOldPosition() != nullptr) {
		spotVectorOld = mapping(pAgent->getOldPosition()->mPositionX, pAgent->getOldPosition()->mPositionY);
	}
	if (spotVectorOld != -1 && spotVector != spotVectorOld) {
		auto itr = matrix->at(spotVectorOld)->begin();
		bool erased = false;
		for (Agent* agent : *(matrix->at(spotVectorOld))) {
			if (agent->equals(*pAgent)) {
				matrix->at(spotVectorOld)->erase(itr);
				erased = true;
				break;
			}
			itr++;
		}
		if (erased) {
			insert(pAgent);
		}
	}


}

void World::runWorld()
{
	for (int i = 0; i < matrix->size(); i++) {
		for (Agent* agent : *(matrix->at(i))) {
			agent->act();
		}
	}
	this->mAgentDrawer->drawElements();
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
	if (mPointTop->mPositionX < 0) {
		columns = ceil((posX - mPointTop->mPositionX) / mMatrixColumns);
	}
	else {
		columns = ceil((posX) / mMatrixColumns);
	}

	if (mPointBottom->mPositionY < 0) {
		rows = ceil((posY - mPointBottom->mPositionY) / mMatrixRows);
	}
	else {
		rows = ceil((posY) / mMatrixRows);
	}

	return rows * mMatrixColumns + columns;
}