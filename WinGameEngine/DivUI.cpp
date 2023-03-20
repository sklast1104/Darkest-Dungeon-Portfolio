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
	// �ִϸ��̼ǰ� �ؽ��ĸ� ���ÿ� �ε��ϴ� ��Ȳ�� �������̶� ����
	if (nullptr != GetAnimator()) {

		UI::render(_dc);

		ComponentRender(_dc);

	}
	else if (nullptr != iModule) {

		Vec2 vPos = GetFinalPos();
		Vec2 vScale = GetScale();

		if (IsCamEffected()) {
			// View ��ȯ ����
			// ī�޶� ������ ���� �ʴ´ٸ� �׻� ������ġ�� �������ȴ�(�Ϲ������� �����ϴ� UI�̴�)
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
