#pragma once

class CSkill;

class CHero
{
protected :

	// 이름
	wstring name;
	// 직업
	wstring job_name;
	// 초상화 키
	wstring key;
	// 초상화 경로
	wstring path;

	// 현재 체력
	UINT curHp;
	// 총 체력
	UINT hp;

	// 현재 스트레스
	UINT curStress;
	// 총 스트레스
	UINT stress;

	// 명중률
	int hitRate;
	// 회피율
	UINT avoidanceRate;
	// 치명율
	UINT criticalHitRate;
	// 방어율
	UINT defenseRate;
	// 데미지 하한
	UINT damageLower;
	//데미지 상한
	UINT damageUpper;
	// 속도
	UINT speed;

	// 레벨
	UINT level;

	// 경험치 무조건 최대 경험치 8이라고 가정
	int curExp;

	// 현재 스킬 리스트
	array<CSkill*, 4> curSkillArray;

	// 가지고 있는 스킬 리스트
	array<CSkill*, 7> skillArray;

	// 대장간 장비 이름 및 경로 (Enum으로 하는게 좋을수도 있음)
	wstring equipKey;
	wstring equipPath;
	int equipLevel;

	wstring armourKey;
	wstring armourPath;
	int armorLevel;

	

public :

	CHero();
	virtual ~CHero();

	int GetCurExp() { return curExp; }
	void SetExp(int _exp) { curExp = _exp; }

	void SetEquipLevel(int _equipLevel) { equipLevel = _equipLevel; }
	int GetEquipLevel() { return equipLevel; }

	void SetArmorLevel(int _armorLevel) { armorLevel = _armorLevel; }
	int GetArmorLevel() { return armorLevel; }

	void SetEquipKey(const wstring& _equipKey) { equipKey = _equipKey; }
	const wstring& GetEquipKey() { return equipKey; }

	void SetEquipPath(const wstring& _equipPath) { equipPath = _equipPath; }
	const wstring& GetEquipPath() { return equipPath; }

	void SetArmourKey(const wstring& _armourKey) { armourKey = _armourKey; }
	const wstring& GetArmourKey() { return armourKey; }

	void SetArmourPath(const wstring& _armourPath) { armourPath = _armourPath; }
	const wstring& GetArmourPath() { return armourPath; }

	void SetCurStress(UINT _curStress) { curStress = _curStress; }
	UINT GetCurStress() { return curStress; }

	void SetStress(UINT _stress) { stress = _stress; }
	UINT GetStress() { return stress; }

	void SetCurHp(UINT _curHP) { curHp = _curHP; }
	UINT GetCurHp() { return curHp; }

	void SetName(const wstring& name) {
		this->name = name;
	}

	const wstring& GetName() {
		return name;
	}

	const wstring& GetJobName() { return job_name; }

	void SetKey(const wstring& key) {
		this->key = key;
	}

	const wstring& GetKey() {
		return key;
	}

	void SetPath(const wstring& path) {
		this->path = path;
	}

	const wstring& GetPath() {
		return path;
	}

	void SetHp(UINT hp) {
		this->hp = hp;
	}

	UINT GetHp() {
		return hp;
	}

	void SetHitRate(UINT hitRate) {
		this->hitRate = hitRate;
	}

	int GetHitRate() {
		return hitRate;
	}

	void SetAvoidanceRate(UINT avoidanceRate) {
		this->avoidanceRate = avoidanceRate;
	}

	UINT GetAvoidanceRate() {
		return avoidanceRate;
	}

	void SetCriticalHitRate(UINT criticalHitRate) {
		this->criticalHitRate = criticalHitRate;
	}

	UINT GetCriticalHitRate() {
		return criticalHitRate;
	}

	void SetDefenseRate(UINT defenseRate) {
		this->defenseRate = defenseRate;
	}

	UINT GetDefenseRate() {
		return defenseRate;
	}

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

	void SetSpeed(UINT speed) {
		this->speed = speed;
	}

	UINT GetSpeed() {
		return speed;
	}

	void SetLevel(UINT level) {
		this->level = level;
	}

	UINT GetLevel() {
		return level;
	}



};

