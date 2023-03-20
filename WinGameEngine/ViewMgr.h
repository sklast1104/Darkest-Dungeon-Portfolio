#pragma once
class ViewMgr
{
private :

	float zoomRatio;
	float currentTime;
	float lerpTime;
	
	float startZoomRatio;
	float endZoomRatio;

public :

	void init();
	void update();

	void SetZoomRatio(float _zoomRatio);

	void animateZoom(float _zoomRatio, float _timer);

	Vec2 GetViewPortPos(Vec2 _vObjPos) { return _vObjPos * zoomRatio; }
	Vec2 GetViewPortScale(Vec2 _vObjScale) { return _vObjScale * zoomRatio; }

public :
	SINGLE(ViewMgr);

};

