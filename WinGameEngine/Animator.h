#pragma once

class Object;
class Animation;
class Texture;

class Animator
{

private:

	map<wstring, Animation*> m_mapAnim; // ��� Animation
	Animation* m_pCurAnim; // ���� Animation
	Object* m_pOwner; // Animation ���� ������Ʈ
	bool m_bRepeat;

public:

	Animator();
	~Animator();

	void CreateAnimation(const wstring& _strName, Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	virtual void LoadAnimation(const wstring& _strRelativePath);
	virtual void LoadAnimation(const wstring& _strRelativePath, const wstring& _animName);
	virtual void LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip);
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration);
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset);
	// �¿� ������ �ؽ��ĸ� ����ϴ���
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset, bool _isHorizontalFlip);
	Animation* FindAnimation(const wstring& _strName);
	void Play(const wstring& _strName, bool _bRepeat);

	void update();
	void finalupdate();
	void render(HDC _dc);

	Object* GetObj() { return m_pOwner; }

	friend class Object;
};

