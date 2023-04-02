#pragma once

class CSkill;

class CHero
{
protected :

	// �̸�
	wstring name;
	// ����
	wstring job_name;
	// �ʻ�ȭ Ű
	wstring key;
	// �ʻ�ȭ ���
	wstring path;

	// ���� ü��
	UINT curHp;
	// �� ü��
	UINT hp;

	// ���� ��Ʈ����
	UINT curStress;
	// �� ��Ʈ����
	UINT stress;

	// ���߷�
	int hitRate;
	// ȸ����
	UINT avoidanceRate;
	// ġ����
	UINT criticalHitRate;
	// �����
	UINT defenseRate;
	// ������ ����
	UINT damageLower;
	//������ ����
	UINT damageUpper;
	// �ӵ�
	UINT speed;

	// ����
	UINT level;

	// ����ġ ������ �ִ� ����ġ 8�̶�� ����
	int curExp;

	// ���� ��ų ����Ʈ
	array<CSkill*, 4> curSkillArray;

	// ������ �ִ� ��ų ����Ʈ
	array<CSkill*, 7> skillArray;

	// ���尣 ��� �̸� �� ��� (Enum���� �ϴ°� �������� ����)
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

