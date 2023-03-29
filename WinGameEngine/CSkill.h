#pragma once
class CSkill
{

private :

	// 스킬 이름 및 리소스 키
	wstring skillName;
	// 스킬 경로
	wstring skillPath;

	// 공격 대상 배열 4개의 true, false로 정하자
	array<bool, 4> skillRange;
	// 공격 가능한 포지션
	array<bool, 4> skillPos;

	// 여러명 공격하는 종류의 스킬인지
	bool multiAttack;

	// 명중률
	size_t hitRate;

	// 피해 보정
	int attackRate;

	// 치명타 보정
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

