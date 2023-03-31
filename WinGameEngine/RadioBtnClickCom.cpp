#include "stdafx.h"
#include "RadioBtnClickCom.h"

#include "Scene_DSelect.h"
#include "DivUI.h"
#include "CQuest.h"

RadioBtnClickCom::RadioBtnClickCom(DivUI* _myBg, CQuest* _quest, Scene_DSelect* _dScene)
	: myBg{_myBg}, quest{_quest}
	, dSelectScene{_dScene}
{
}

void RadioBtnClickCom::Execute()
{
	dSelectScene->turnOffRadioBtn();
	myBg->SetCanRend(true);

	dSelectScene->questTitle->SetText(quest->GetQTypeTitle());
	dSelectScene->questText->SetText(quest->GetQDisc());
	dSelectScene->pathLengText->SetText(quest->GetDPath() + L" | ");
	dSelectScene->pathLevText->SetText(quest->GetQLevel());
	dSelectScene->goalDisc->SetText(quest->GetQGoal());
}
