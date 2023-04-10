#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <random>

using std::shared_ptr;
using std::weak_ptr;

#include <fstream>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;

#include <windows.h>
#include <Objbase.h>
#include <gdiplus.h>
#include <wincodec.h>
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "windowscodecs.lib")

#include <functional>
using std::function;

#include <algorithm>

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#include <array>
using std::array;

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

using std::to_wstring;

#include <fstream>
using std::ifstream;
using std::istringstream;

#include <functional>
using std::function;


#include <locale>
#include <codecvt>

#include <math.h>
#include <assert.h>

#include "struct.h"
#include "define.h"
#include "func.h"
#include "Mathf.h"

