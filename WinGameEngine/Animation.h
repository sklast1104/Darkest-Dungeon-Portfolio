#pragma once

class Animator;
class Texture;
class Object;

struct tAnimFrm
{
	Vec2 vLT;
	Vec2 vSlice;
	Vec2 vOffset;
	float fDuration;
};

class Animation
{
private:
	wstring m_strName;
	Animator* m_pAnimator;
	Texture* m_pTex;
	vector<tAnimFrm> m_vecFrm; // 모든 프레임 정보
	int m_iCurFrm;
	float m_fAccTime; // 시간 누적

	bool m_bFinish;

	
public:
	Animation();
	~Animation();

	void update();
	void render(HDC _dc);
	void Create(Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);

	void Save(const wstring& _strRelativePath);
	void Load(const wstring& _strRelativePath);

	const wstring& GetName() { return m_strName; }
	bool IsFinish() { return m_bFinish; }
	void SetFrame(int _iFrameIdx) {
		m_bFinish = false;
		m_iCurFrm = _iFrameIdx;
		m_fAccTime = 0.f;
	}

	tAnimFrm& GetFrame(int _iIdx) {
		return m_vecFrm[_iIdx];
	}
	UINT GetMaxFrame() { return (UINT)m_vecFrm.size(); }

	void SetName(const wstring& _strName) {
		m_strName = _strName;
	}

	void SetAnimator(Animator* _animator) { m_pAnimator = _animator; }

	friend class CAnimator;
};

