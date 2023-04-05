#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CDarkMonster :
	public CTurnPlayer
{

protected:

	// �̸�
	wstring name;
	// ���ҽ� ���
	wstring resPath;
	// ���� Ÿ�� (�� ���ӿ����� 2~3�� ������ �ִ°Ű����� �ϴ� �ϳ��� �մٰ� ����
	wstring monsterType;

	// ���� ü��
	size_t curHp;
	// �� ü��
	size_t maxHp;

	// �����
	size_t shieldRate;
	// ȸ����
	size_t avoidRate;
	// �ӵ�
	size_t speed;
	// ������ ����
	UINT damageLower;
	//������ ����
	UINT damageUpper;

	// ���׷�
	// ���� ���׷�
	size_t faintResist;
	// �ߵ� ���׷�
	size_t toxinResist;
	// ���� ���׷�
	size_t bleedResist;
	// ��ȭ ���׷�
	size_t weakResist;
	// �̵� ���׷�
	size_t moveResist;

	// ��ų �̸��� �ִ� 4������, 1~3���ϼ��� ����
	array<CSkill*, 4> curSkillArray;

public :

	CDarkMonster();
	virtual ~CDarkMonster();

	const array<CSkill*, 4> GetCurSkills() { return curSkillArray; }

	const wstring& GetName() { return name; }
	void SetName(const wstring& _name) { name = _name; }

	const wstring& GetPath() { return resPath; }
	void SetPath(const wstring& _path) { resPath = _path; }

	const wstring& GetMonType() { return monsterType; }
	void SetMonType(const wstring& _monType) { monsterType = _monType; }

	size_t GetCurHp() { return curHp; }
	void SetCurHp(size_t _hp) { curHp = _hp; }
	size_t GetMaxHp() { return maxHp; }
	void SetMaxHp(size_t _maxHp) { maxHp = _maxHp; }

	size_t GetShieldRate() { return shieldRate; }
	void SetShieldRate(size_t _shieldRate) { shieldRate = _shieldRate; }
	size_t GetAvoidRate() { return avoidRate; }
	void SetAvoidRate(size_t _avoidRate) { avoidRate = _avoidRate; }
	size_t GetSpeed() { return speed; }
	void SetSpeed(size_t _speed) { speed = _speed; }

	size_t GetFaintResist() { return faintResist; }
	void SetFaintResist(size_t _faintResist) { faintResist = _faintResist; }
	size_t GetToxinResist() { return toxinResist; }
	void SetToxinResist(size_t _toxinResist) { toxinResist = _toxinResist; }
	size_t GetBleedResist() { return bleedResist; }
	void SetBleedResist(size_t _bleedResist) { bleedResist = _bleedResist; }
	size_t GetWeakResist() { return weakResist; }
	void SetWeakResist(size_t _weakResist) { weakResist = _weakResist; }
	size_t GetMoveResist() { return moveResist; }
	void SetMoveResist(size_t _moveResist) { moveResist = _moveResist; }

	void SetDamageLower(UINT lowerDamage) {
		this->damageLower = lowerDamage;
	}

	UINT GetDamageLower() {
		return damageLower;
	}

	void SetDamageUppder(UINT upperDamage) {
		this->damageUpper = upperDamage;
	}

	UINT GetDamageUppder() {
		return damageUpper;
	}
};

