#pragma once

class Object;
class AI;

void CreateObject(Object* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(Object* _pObj);
void ChangeScene(SCENE_TYPE _eNext);
void ChangeState(AI* _ai, wstring _stateKey);

template<typename T>
void	Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

template<typename T>
void Safe_Delete_Vec(vector<T>& _vec) {

	for (size_t i = 0; i < _vec.size(); ++i) {
		if (nullptr != _vec[i])
			delete _vec[i];
	}
	_vec.clear();
}

template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2>& _map) {

	typename map<T1, T2>::iterator iter = _map.begin();

	for (; iter != _map.end(); ++iter) {

		if (nullptr != iter->second)
			delete iter->second;
	}

	_map.clear();
};

void FScanf(char* _pOutBuff, FILE* _pFile);