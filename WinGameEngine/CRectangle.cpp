#include "stdafx.h"
#include "CRectangle.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

#include "Camera.h"
#include "ViewMgr.h"

CRectangle::CRectangle()
	: isPlayer{true}
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::update()
{
	Vec2 mPos = GetPos();

	float speed = 300.f;

	if (isPlayer) {
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

}

void CRectangle::render(HDC _dc)
{
	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(GetPos());

	Vec2 vViewPos = ViewMgr::GetInst()->GetViewPortPos(vRenderPos);
	Vec2 vViewScale = ViewMgr::GetInst()->GetViewPortScale(GetScale());

	Rectangle(_dc, (int)(vRenderPos.x - vViewScale.x / 2.f), (int)(vRenderPos.y - vViewScale.y / 2.f),
		(int)(vRenderPos.x + vViewScale.x / 2.f), (int)(vRenderPos.y + vViewScale.y / 2.f));

	ComponentRender(_dc);

}
