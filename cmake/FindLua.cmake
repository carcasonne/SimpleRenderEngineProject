# author: Chris
# TODO
# - make cross-platform
# - handle more robust-genmeric paths
# - handle debug/release configurations
# - remove redundant variables
# - mark variables as advanced when possible

message("<FindLua.cmake>")

set(LUA_PATH "${SGE_LIBS_PATH}/lua")


find_path(LUA_INCLUDE_DIR
        NAMES lua.h
        PATH_SUFFIXES # path suffixes to search inside ENV{SDLDIR}
        src/lua src
        PATHS
            ${LUA_PATH}
        )

find_library(LUA_LIBRARY
        NAMES lua-static.lib
        PATH_SUFFIXES src
        PATHS ${LUA_PATH}
        )

if(WIN32)
     find_file(LUA_LIBRARY_SHARED
        NAMES lua.dll
        PATH_SUFFIXES src
        PATHS ${LUA_PATH}
    )
    set(LUA_SHARED_LIBS "${SDL2_MIXER_LIBRARY_SHARED}")
endif(WIN32)

mark_as_advanced(LUA_INCLUDE_DIR LUA_LIBRARY LUA_SHARED_LIBS)
message("</FindLua.cmake>")
