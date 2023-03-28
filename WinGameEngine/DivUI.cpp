#include "stdafx.h"
#include "DivUI.h"
#include "Camera.h"
#include "Animator.h"
#include "ImageModule.h"
#include "TextModule.h"

#include "ViewMgr.h"

DivUI::DivUI()
	: UI(false)
	, iModule{ nullptr }
	, canRendImg{false}
	, canRendTxt{false}
	, canRend{true}
{
}

DivUI::~DivUI()
{
	Safe_Delete<ImageModule*>(iModule);
	Safe_Delete<TextModule*>(tModule);

	Safe_Delete<CCommand*>(onMouseOver);
	Safe_Delete<CCommand*>(onMouseClick);
}

void DivUI::SetSrcAlpha(int _alpha)
{
	if (nullptr != iModule) {
		iModule->SetAlpha(_alpha);
	}
}

void DivUI::SetTextColor(UINT r, UINT g, UINT b)
{
	if (nullptr != tModule) {
		tModule->SetColor(r, g, b);
	}
}

void DivUI::SetSecondFont()
{
	if (nullptr != tModule) {
		tModule->SetSecondFont();
	}
}

void DivUI::SetFormat(UINT _format)
{
	if (nullptr != tModule) {
		tModule->SetFormat(_format);
	}
}

void DivUI::InitImageModule(const wstring& _resourceKey, const wstring& _relativePath)
{
	if (nullptr == iModule) {
		iModule = new ImageModule(_resourceKey, _relativePath);
		canRendImg = true;
	}	
}

void DivUI::InitTextModule(const wstring& _text, const UINT _textSize)
{
	if (nullptr == tModule) {
		tModule = new TextModule;
		tModule->SetText(_text);
		tModule->SetTextSize(_textSize);
		canRendTxt = true;
	}
}

void DivUI::render(HDC _dc)
{
	if (!canRend) return;


	if (canRendImg) {

		Vec2 vPos = GetFinalPos();
		Vec2 vScale = GetScale();

		if (IsCamEffected()) {
			// View 변환 실행
			// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		if (isViewEffected()) {
			vPos = ViewMgr::GetInst()->GetViewPortPos(vPos);
			vScale = ViewMgr::GetInst()->GetViewPortScale(vScale);
		}

		iModule->SetPos(vPos);
		iModule->SetScale(vScale);
		iModule->render(_dc);
	}

	if (canRendTxt) {

		Vec2 vPos = GetFinalPos();
		Vec2 vScale = GetScale();

		if (IsCamEffected()) {
			// View 변환 실행
			// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		if (isViewEffected()) {
			vPos = ViewMgr::GetInst()->GetViewPortPos(vPos);
			vScale = ViewMgr::GetInst()->GetViewPortScale(vScale);
		}

		tModule->SetLt(vPos);
		tModule->SetScale(vScale);
		tModule->render(_dc);
	}

	UI::render(_dc);

	ComponentRender(_dc);
}

void DivUI::LoadAnimation(const wstring& _animName, const wstring& _atlasPath)
{
	if (nullptr != GetAnimator()) {
		GetAnimator()->LoadAnimation(_atlasPath, _animName);
		GetAnimator()->Play(_animName, true);
	}	
}
