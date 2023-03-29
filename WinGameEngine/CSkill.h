#pragma once
class CSkill
{

private :

	// ��ų �̸� �� ���ҽ� Ű
	wstring skillName;
	// ��ų ���
	wstring skillPath;

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

public :

	CSkill();
	~CSkill();

	const wstring& GetSkillName() { return skillName; }
	void SetSkillName(const wstring& _skillName) { skillName = _skillName; }

	const wstring& GetSkillPath() { return skillPath; }
	void SetSkillPath(const wstring& _skillPath) { skillPath = _skillPath; }

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

};

