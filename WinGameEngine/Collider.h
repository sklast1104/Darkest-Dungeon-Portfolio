#pragma once

class Object;

class Collider
{
private :

	static UINT g_iNextID;

	Object* m_pOwner; // collider�� �����ϰ� �ִ� ������Ʈ
	Vec2 m_vOffsetPos; // ������Ʈ�κ��� ������� ��ġ
	Vec2  m_vFinalPos; // final update���� �� �����Ӹ��� ���
	Vec2 m_vScale;     // �浹ü�� ũ��

	UINT m_iID;       // �浹ü ������ ID ��
	UINT m_iCol;

public :

	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	Object* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

	Collider();
	Collider(const Collider& _origin);
	~Collider();

	void finalUpdate();
	void render(HDC _dc);

	void OnCollision(Collider* _pOther);
	void OnCollisionEnter(Collider* _pOther);
	void OnCollisionExit(Collider* _pOther);

	Collider& operator = (Collider& _origin) = delete;

	friend class Object;
};

