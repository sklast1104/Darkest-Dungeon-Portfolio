#include "stdafx.h"
#include "UIFactory.h"
#include "DivUI.h"

DivUI* UIFactory::CreateTownDiscUI(Vec2 _vPos, const wstring& _titleName, const wstring& _disc)
{
	DivUI* panel = new DivUI;
	panel->SetScale(Vec2(208.f, 224.f));
	panel->SetScale(panel->GetScale() * 1.f);
	panel->SetPos(_vPos);
	panel->CanTarget(false);
	panel->InitImageModule(L"Darkest_Estate_namebg", L"resource\\Background\\name_bg.png");
	panel->SetSrcAlpha(255);

	// 텍스트 패널
	DivUI* title_txt = new DivUI;
	title_txt->SetScale(Vec2(100.f, 100.f));
	title_txt->SetScale(title_txt->GetScale() * 1.f);
	title_txt->SetPos(Vec2(70.f, 45.f));
	title_txt->CanTarget(false);
	title_txt->SetSrcAlpha(255);
	title_txt->InitTextModule(_titleName, 40);
	title_txt->SetTextColor(201, 185, 129);
	title_txt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	panel->AddChild(title_txt);

	// 설명 패널
	DivUI* disc_txt = new DivUI;
	disc_txt->SetScale(Vec2(200.f, 100.f));
	disc_txt->SetScale(disc_txt->GetScale() * 1.f);
	disc_txt->SetPos(Vec2(70.f, 85.f));
	disc_txt->CanTarget(false);
	disc_txt->SetSrcAlpha(255);
	disc_txt->InitTextModule(_disc, 27);
	disc_txt->SetTextColor(201, 201, 201);
	disc_txt->SetSecondFont();
	disc_txt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	panel->AddChild(disc_txt);

	return panel;
}
