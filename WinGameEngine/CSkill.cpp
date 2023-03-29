#include "stdafx.h"
#include "CSkill.h"

CSkill::CSkill()
	: skillName{ L"" }
	, skillPath{ L"" }
	, skillRange{}
	, skillPos{}
	, hitRate{ 0 }
	, multiAttack{false}
{
}

CSkill::~CSkill()
{
}
