#include "stdafx.h"
#include "CRectangle.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::update()
{
	Vec2 mPos = GetPos();

	float speed = 300.f;

	if (KEY_HOLD(KEY::W)) {
		
		SetPos(Vec2(mPos.x, mPos.y + -speed * fDT));
	}

	if (KEY_HOLD(KEY::S)) {
		SetPos(Vec2(mPos.x, mPos.y + speed * fDT));
	}

	if (KEY_HOLD(KEY::A)) {
		SetPos(Vec2(mPos.x - speed * fDT, mPos.y));
	}

	if (KEY_HOLD(KEY::D)) {
		SetPos(Vec2(mPos.x + speed * fDT, mPos.y));
	}
}