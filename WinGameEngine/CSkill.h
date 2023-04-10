#pragma once
class CSkill
{

private :

	// ��ų �̸� �� ���ҽ� Ű
	wstring skillName;
	// ��ų ���
	wstring skillPath;
	// �׷��̽����� ��ų ���
	wstring graySkillPath;

	// ���� ��� �迭 4���� true, false�� ������
	array<bool, 4> skillRange;
	// ���� ������ ������
	array<bool, 4> skillPos;

	// ������ �����ϴ� ������ ��ų����
	bool multiAttack;

	// ���߷�
	size_t hitRate;

	// ���� ����
	int attackRate;

	// ġ��Ÿ ����
	float criticalRate;

	// Ȱ��ȭ ��������
	bool isAlive;

	// ��ų �ִϸ��̼� �̸�
	wstring skillAnimName;
	// ��ų �ִϸ��̼� ���
	wstring skillAnimPath;

public :

	CSkill();
	~CSkill();

	const wstring& GetSkilAnimName() { return skillAnimName; }
	void SetSkillAnimName(const wstring& _skilName) { skillAnimName = _skilName; }

	const wstring& GetAnimPath() { return skillAnimPath; }
	void SetAnimPath(const wstring& _animPath) { skillAnimPath = _animPath; }

	const wstring& GetSkillName() { return skillName; }
	void SetSkillName(const wstring& _skillName) { skillName = _skillName; }

	const wstring& GetSkillPath() { return skillPath; }
	void SetSkillPath(const wstring& _skillPath) { skillPath = _skillPath; }

	const wstring& GetGraySkillPath() { return graySkillPath; }
	void SetGraySkillPath(const wstring& _graySkillPath) { graySkillPath = _graySkillPath; }

	array<bool, 4>& GetSkillRange() { return skillRange; }
	array<bool, 4>& GetSkillPos() { return skillPos; }

	void SetMultiAttack(bool _isMulti) { multiAttack = _isMulti; }
	bool GetMulti() { return multiAttack; }

	size_t GetHitRate() { return hitRate; }
	void SetHitRate(size_t _hitRate) { hitRate = _hitRate; }

	int GetAttackRate() { return attackRate; }
	void SetAttackRate(int _attackRate) { attackRate = _attackRate; }

	float GetCritRate() { return criticalRate; }
	void SetCritRate(float _criticalRate) { criticalRate = _criticalRate; }

	void SetSkillAlive(bool _isAlive) { isAlive = _isAlive; }
	bool IsAlive() { return isAlive; }
};

