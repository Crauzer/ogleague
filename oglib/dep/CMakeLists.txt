add_library(dep STATIC cxxlua51/lapi.cpp
cxxlua51/lauxlib.cpp
cxxlua51/lbaselib.cpp
cxxlua51/lcode.cpp
cxxlua51/ldblib.cpp
cxxlua51/ldebug.cpp
cxxlua51/ldo.cpp
cxxlua51/ldump.cpp
cxxlua51/lfunc.cpp
cxxlua51/lgc.cpp
cxxlua51/linit.cpp
cxxlua51/liolib.cpp
cxxlua51/llex.cpp
cxxlua51/lmathlib.cpp
cxxlua51/lmem.cpp
cxxlua51/loadlib.cpp
cxxlua51/lobject.cpp
cxxlua51/lopcodes.cpp
cxxlua51/loslib.cpp
cxxlua51/lparser.cpp
cxxlua51/lstate.cpp
cxxlua51/lstring.cpp
cxxlua51/lstrlib.cpp
cxxlua51/ltable.cpp
cxxlua51/ltablib.cpp
cxxlua51/ltm.cpp
cxxlua51/lundump.cpp
cxxlua51/lvm.cpp
cxxlua51/lzio.cpp)
target_include_directories(dep PRIVATE "${CMAKE_CURRENT_LIST_DIR}/cxxlua51")
target_include_directories(dep INTERFACE "${CMAKE_CURRENT_LIST_DIR}")