#pragma once

class Collider;
class Animator;

class Object
{
private:
	wstring m_strName;

	Vec2 m_vPos;
	Vec2 m_vScale;

	// Componenet
	Collider* m_pCollider;
	Animator* m_pAnimator;

	bool m_bAlive;

	void SetDead() { m_bAlive = false; }

public :
	Object();
	Object(const Object& _origin);
	virtual ~Object();

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	Collider* GetCollider() { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }

	bool isDead() { return !m_bAlive; }

	void CreateCollider();
	void CreateAnimator();
	void CreateAnimator(Animator* _animator);
	void CreateRigidBody();

	virtual void OnCollision(Collider* _pOther) {}
	virtual void OnCollisionEnter(Collider* _pOther) {}
	virtual void OnCollisionExit(Collider* _pOther) {}

	virtual void update() = 0;
	virtual void finalupdate();
	virtual void render(HDC _dc);

	void ComponentRender(HDC _dc);

	virtual Object* Clone() = 0;

	friend class EventMgr;
};

