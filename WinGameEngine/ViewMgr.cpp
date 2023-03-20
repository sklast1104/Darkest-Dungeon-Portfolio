#include "stdafx.h"
#include "ViewMgr.h"

#include "Camera.h"
#include "TimeMgr.h"

ViewMgr::ViewMgr()
	: zoomRatio{1.f}
	, currentTime{0.f}
	, lerpTime{0.000001f}
	, startZoomRatio{0.f}
	, endZoomRatio{0.f}
{

}

ViewMgr::~ViewMgr() {

}

void ViewMgr::init()
{
	startZoomRatio = zoomRatio;
	endZoomRatio = zoomRatio;
}

void ViewMgr::update()
{
	currentTime += fDT;

	if (currentTime >= lerpTime) {
		currentTime = lerpTime;
	}

	float t = currentTime / lerpTime;

	zoomRatio = Mathf::Lerp(startZoomRatio, endZoomRatio, t);
}

void ViewMgr::SetZoomRatio(float _zoomRatio)
{
	zoomRatio = _zoomRatio;
}

void ViewMgr::animateZoom(float _endzoomRatio, float _lerpTime)
{
	currentTime = 0.f;
	lerpTime = _lerpTime;
	startZoomRatio = zoomRatio;
	endZoomRatio = _endzoomRatio;
}
