#include "stdafx.h"
#include "DivUI.h"
#include "Camera.h"
#include "Animator.h"
#include "ImageModule.h"

DivUI::DivUI()
	: UI(false)
	, iModule{ nullptr }
{
}

DivUI::~DivUI()
{
	Safe_Delete<ImageModule*>(iModule);
}

void DivUI::InitImageModule(const wstring& _resourceKey, const wstring& _relativePath)
{
	if (nullptr == iModule) {
		iModule = new ImageModule(_resourceKey, _relativePath);
	}	
}

void DivUI::render(HDC _dc)
{
	// 애니메이션과 텍스쳐를 동시에 로딩하는 상황은 없을것이라 가정
	if (nullptr != GetAnimator()) {

		UI::render(_dc);

		ComponentRender(_dc);

	}
	else if (nullptr != iModule) {

		Vec2 vPos = GetFinalPos();
		Vec2 vScale = GetScale();

		if (IsCamEffected()) {
			// View 변환 실행
			// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		iModule->SetPos(vPos);
		iModule->SetScale(vScale);
		iModule->render(_dc);

		UI::render(_dc);

		ComponentRender(_dc);
	}
	else {
		UI::render(_dc);

		ComponentRender(_dc);
	}
}

void DivUI::LoadAnimation(const wstring& _animName, const wstring& _atlasPath)
{
	if (nullptr != GetAnimator()) {
		GetAnimator()->LoadAnimation(_atlasPath, _animName);
		GetAnimator()->Play(_animName, true);
	}	
}
