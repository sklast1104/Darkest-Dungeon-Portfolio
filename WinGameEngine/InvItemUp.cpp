#include "stdafx.h"
#include "InvItemUp.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "Scene_Shop.h"
#include "GameMgr.h"
#include "CItem.h"

InvItemUp::InvItemUp(DivUI* _myItem, int _index)
	: scene{ (Scene_Shop*)SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemUp::Execute()
{
	// Ŭ���̶� ���϶� �Ѵ� �̺�Ʈ ����

	if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_Shop") {

		DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");
		DivUI* shopInvPanel = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"shopInvPanel");

		array<CItem*, 16>& inventory = mgr->GetInventory();

		CItem* curUp = inventory[index];

		int prevIndex = itemDragger->GetId();

		// Ŭ���̶� ���������̸� �� �̺�Ʈ�� �Ұ� ����
		if (prevIndex == index) return;

		if (nullptr == curUp) {

			// �� �����̸� �������� �Ű��ָ��

			// ���� ���� �Ŵ��� ������� �Ű��ְ� 
			mgr->MoveInventory(prevIndex, index);

			// �κ��丮 �г� �����ͼ� ������Ʈ ���ش�
			shopInvPanel->updateValue();
		}
		else {

			// �׷��� �ʴٸ� ���� �������̶�� maxCount ��
			CItem* prevItem = inventory[prevIndex];
			
			// ���� �������̶��
			if (prevItem->GetName() == curUp->GetName()) {

				int prevCount = prevItem->GetCurCount();
				int curCount = curUp->GetCurCount();

				// ���� �������� ������ �ƽ�ī���ͺ��� ���� ���¶��
				if (curCount < curUp->GetMaxCount()) {

					int reserve = curUp->GetMaxCount() - curUp->GetCurCount();
					if (reserve > prevItem->GetCurCount()) reserve = prevItem->GetCurCount();
					// �ƽ�ī��Ʈ ���и�ŭ �����ְ�
					curUp->SetCurCount(curUp->GetCurCount() + reserve);
					// ���� �������� ���и�ŭ ���ָ� �ڸ��� �ű��� �ʴ´�
					prevItem->SetCurCount(prevItem->GetCurCount() - reserve);
					// �ٵ� ���࿡ prevItemCount�� 0�̶�� nullptr�� �ٲ������
					if (prevItem->GetCurCount() == 0) {
						mgr->RemoveItem(prevIndex);
					}
				}
				// �ƽ�ī��Ʈ��� �׳� �ϰ͵� ����
				else {
					return;
				}

			}
			// �ٸ� �������̶�� ��ġ �ٲٱ�
			else {

				mgr->SwapInventory(prevIndex, index);

			}

			
			
			// �ƴ϶�� ����

		}

		// �κ��丮 �г� �����ͼ� ������Ʈ ���ش�
		shopInvPanel->updateValue();
	}

	int test = 3;
}
