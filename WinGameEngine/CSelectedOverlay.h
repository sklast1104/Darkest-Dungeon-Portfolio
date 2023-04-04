#pragma once
#include "UI.h"
class Texture;

class CSelectedOverlay : 
	public UI
{
private :

	Texture* overlayTex;
	bool isGrowing;

public :

	CSelectedOverlay();
	~CSelectedOverlay() {}

	virtual void update() override;
	virtual void render(HDC _dc) override;

	CLONE(CSelectedOverlay);

};

