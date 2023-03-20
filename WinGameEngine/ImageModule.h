#pragma once

class Texture;

// UI������ ����ϴ� �̹��� �ε��� ����̶�� ����
class ImageModule
{

private :

	Texture* m_pTex;
	wstring resourceKey;
	wstring relativePath;

	// vLT, �̹� �θ�κ��� ����� GetFinalPos�� ���´ٰ� ����
	// ���� ������, ����Ʈ ������ ���� �̹� �����ִٰ� �����Ѵ�
	Vec2 vPos;

	// ũ��
	Vec2 vScale;

public :

	ImageModule(const wstring& _resourceKey, const wstring& _relativePath);
	~ImageModule();

	// Local, World, Camera, Viewport ���� ���� Pos������
	void SetPos(Vec2 _vPos) { vPos = _vPos; }
	// Local, World, Camera, Viewport ���� ���� Scale������
	void SetScale(Vec2 _vScale) { vScale = _vScale; }

	const wstring& GetResourceKey() const { return resourceKey; }
	const wstring& GetRelativePath() const { return relativePath; }

	void render(HDC _dc);
};

