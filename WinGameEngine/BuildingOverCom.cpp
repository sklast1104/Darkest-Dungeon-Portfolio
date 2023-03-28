#include "stdafx.h"
#include "BuildingOverCom.h"
#include "DivUI.h"

BuildingOverCom::BuildingOverCom(DivUI* _overImg, DivUI* _txtPanel)
	: overImg{_overImg}
	, txtPanel{_txtPanel}
{
}

void BuildingOverCom::Execute()
{
	overImg->SetCanRendImg(true);
	txtPanel->SetCanRend(true);
}
