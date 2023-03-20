#pragma once

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::weak_ptr;

#include <windows.h>
#include <Objbase.h>
#include <gdiplus.h>
#include <wincodec.h>
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <list>
using std::list;

#include <map>
using std::map;
using std::make_pair;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;
using std::wstring;

#include <math.h>
#include <assert.h>

#include "struct.h"
#include "define.h"
#include "func.h"