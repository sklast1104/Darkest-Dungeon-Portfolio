#pragma once

class Object;
class Texture;

enum class CAM_EFFECT {
	FADE_IN,
	FADE_OUT,
	NONE,
};

struct tCamEffect {
	CAM_EFFECT eEffect;   // ī�޶� ȿ��
	float fDuration;    // ȿ�� �ִ� ���� �ð�
	float fCurTime;     // ī�޶� ȿ�� ���� ����� �ð�
};

class Camera
{
private :
	Vec2 m_vLookAt; // ī�޶� ���� ��ġ
	Vec2 m_vCurLookAt; // ������ġ�� ������ġ ���� ��ġ
	Vec2 m_vPrevLookAt; // ī�޶� ���� ���������� ��ġ
	Object* m_pTargetObj; // ī�޶� Ÿ�� ������Ʈ

	Vec2 m_vDiff; // �ػ� �߽���ġ�� ī�޶� LookAt ���� ���� ��

	float m_fTime; // Ÿ���� ���󰡴µ� �ɸ��� �ð�
	float m_fSpeed; // Ÿ���� ���󰡴� �ӵ�
	float m_fAccTime; // ���� �ð�

	list<tCamEffect> m_listCamEffect;
	Texture* m_pVeilTex; // ī�޶� ������ �ؽ���

	bool isShake;

	void CalDiff();
public :

	void init();
	void update();
	void render(HDC _dc);
	void Shake();

	void EnableShake(bool _isEnable) {
		isShake = _isEnable;
	}

	void SetLookAt(Vec2 _vLook) {
		m_vLookAt = _vLook;
		float fMoveDist = (m_vLookAt - m_vPrevLookAt).Length();
		m_fSpeed = fMoveDist / m_fTime;
		//m_fSpeed /= 4.f;
		m_fAccTime = 0.f;
	}

	void SetCurLookAt(Vec2 _vLook) {
		m_vCurLookAt = _vLook;
		m_vLookAt = _vLook;
	}

	void SetTarget(Object* _pTarget) { m_pTargetObj = _pTarget; }
	Vec2 GetLookAt() { return m_vCurLookAt; }
	Vec2 GetRenderPos(Vec2 _vObjPos) { return _vObjPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _vRenderPos) { return _vRenderPos + m_vDiff; }

	void FadeIn(float _fDuration) {

		tCamEffect ef = {};
		ef.eEffect = CAM_EFFECT::FADE_IN;
		ef.fDuration = _fDuration;
		ef.fCurTime = 0.f;

		m_listCamEffect.push_back(ef);

		if (0.f == _fDuration) {
			assert(nullptr);
		}
	}
	void FadeOut(float _fDuration) {

		tCamEffect ef = {};
		ef.eEffect = CAM_EFFECT::FADE_OUT;
		ef.fDuration = _fDuration;
		ef.fCurTime = 0.f;

		m_listCamEffect.push_back(ef);

		if (0.f == _fDuration) {
			assert(nullptr);
		};
	}

public :
	SINGLE(Camera)
};

