#pragma once
class Mathf
{
public :

	static float Clamp01(float value) {
		if (value < 0.0f) return 0.0f;
		if (value > 1.f) return 1.f;
	}

	static float Lerp(float a, float b, float t) {
		return a + (b - a) * Clamp01(t);
	}
};

