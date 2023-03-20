#pragma once

#include "Object.h"

class CRectangle :
	public Object
{

private :

public :

	CRectangle();
	~CRectangle();

	virtual void update() override;

	CLONE(CRectangle);
};

