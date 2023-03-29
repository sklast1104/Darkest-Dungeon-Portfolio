#pragma once

// DrawText ��� �Լ�
class TextModule
{
private :

	LOGFONT lf;
	UINT fontSize;
	UINT format;
	wstring text;

	int r, g, b;

	// DrawRect�� ����ϰԵ� ��ǥ
	// ���� ���������� ��� ��ȯ�� �Ϸ�� ��ǥ�����Ѵ�
	Vec2 vLt;
	Vec2 vScale;

public :

	TextModule();
	~TextModule();

	void render(HDC _dc);

	void SetLt(Vec2 _vLt) { vLt = _vLt; }
	void SetScale(Vec2 _vScale) { vScale = _vScale; }

	void SetTextSize(UINT _fontSize) { lf.lfHeight = _fontSize; }
	void SetText(const wstring& _text) { text = _text; }
	void SetColor(int _r, int _g, int _b) { 
		r = _r; 
		g = _g;
		b = _b;
	}
	void SetFormat(UINT _format) { format = _format; }

	void SetFont(const wstring& _fontName);
	void SetSecondFont();
};

