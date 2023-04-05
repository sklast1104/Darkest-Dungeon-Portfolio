#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CDarkMonster :
	public CTurnPlayer
{

protected:

	// 이름
	wstring name;
	// 리소스 경로
	wstring resPath;
	// 몬스터 타입 (인 게임에서는 2~3개 가지룻도 있는거같은데 일단 하나만 잇다고 가정
	wstring monsterType;

	// 현재 체력
	size_t curHp;
	// 총 체력
	size_t maxHp;

	// 방어율
	size_t shieldRate;
	// 회피율
	size_t avoidRate;
	// 속도
	size_t speed;
	// 데미지 하한
	UINT damageLower;
	//데미지 상한
	UINT damageUpper;

	// 저항력
	// 기절 저항력
	size_t faintResist;
	// 중독 저항력
	size_t toxinResist;
	// 출혈 저항력
	size_t bleedResist;
	// 약화 저항력
	size_t weakResist;
	// 이동 저항력
	size_t moveResist;

	// 스킬 이름은 최대 4개까지, 1~3개일수도 있음
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

