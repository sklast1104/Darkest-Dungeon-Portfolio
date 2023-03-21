#include "stdafx.h"
#include "BtnMOver.h"

BtnMOver::BtnMOver()
{
}

BtnMOver::~BtnMOver()
{
}

void BtnMOver::update()
{
	UI::update();
}

void BtnMOver::MouseOn()
{
	SetSrcAlpha(100);
}
