#include "GeometryBase.h"

namespace  Geometry2D {
	GeomteryBase::~GeomteryBase()
	{
	}

	GeomteryBase& GeomteryBase::operator=(GeomteryBase& other)
	{
		return this->assign(other);
	}

	bool GeomteryBase::operator==(GeomteryBase& other)
	{
		return this->equals(other);
	}


}
