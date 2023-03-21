#include "GeometryBase.h"

namespace  Geometry2D {
	GeomteryBase::~GeomteryBase()
	{
	}

	GeomteryBase& GeomteryBase::operator=(const GeomteryBase& other)
	{
		return this->assign(other);
	}

	bool GeomteryBase::operator==(const GeomteryBase& other)
	{
		return this->equals(other);
	}

}
