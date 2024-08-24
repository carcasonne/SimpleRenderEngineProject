# Locate the SDL2_mixer library. This CMake module is a modified version
# of the original FindSDL_mixer.cmake file
# ###########################################################################
# Locate SDL_mixer library
# This module defines
# SDL2MIXER_LIBRARY, the name of the library to link against
# SDLMIXER_FOUND, if false, do not try to link to SDL
# SDL2MIXER_INCLUDE_DIR, where to find SDL/SDL.h
#
# $SDLDIR is an environment variable that would
# correspond to the ./configure --prefix=$SDLDIR
# used in building SDL.
#
# Created by Eric Wing. This was influenced by the FindSDL.cmake
# module, but with modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).

#=============================================================================
# Copyright 2005-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distributed this file outside of CMake, substitute the full
#  License text for the above reference.)

message("<FindSDL2_mixer.cmake>")

set(SDL2_MIXER_PATH "${SGE_LIBS_PATH}/sdl2_mixer")

FIND_PATH(SDL2MIXER_INCLUDE_DIR SDL_mixer.h
        HINTS
        $ENV{SDL2MIXERDIR}
        $ENV{SDL2DIR}
        PATH_SUFFIXES include
        PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local/include/SDL2
        /usr/include/SDL2
        /sw/include/SDL2 # Fink
        /opt/local/include/SDL2 # DarwinPorts
        /opt/csw/include/SDL2 # Blastwave
        /opt/include/SDL2
        ${SDL2_MIXER_PATH}
        )

# TODO find a more robust way to check for x86/x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()

FIND_LIBRARY(SDL2MIXER_LIBRARY
        NAMES SDL2_mixer
        HINTS
        $ENV{SDL2MIXERDIR}
        $ENV{SDL2DIR}
        PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
        PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        /opt
        ${SDL2_MIXER_PATH}
        )

if(WIN32)
     find_file(SDL2_MIXER_LIBRARY_SHARED
        NAMES SDL2_mixer.dll
        PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
        PATHS ${SDL2_MIXER_PATH}
    )
    get_filename_component(SDL2_MIXER_SHARED_PATH ${SDL2_MIXER_LIBRARY_SHARED} DIRECTORY)
    set(SDL2_MIXER_SHARED_LIBS "${SDL2_MIXER_LIBRARY_SHARED}" "${SDL2_MIXER_SHARED_PATH}/optional/libogg-0.dll" "${SDL2_MIXER_SHARED_PATH}/optional/libwavpack-1.dll")
endif(WIN32)

SET(SDL2MIXER_FOUND "NO")
IF(SDL2MIXER_LIBRARY AND SDL2MIXER_INCLUDE_DIR)
    SET(SDL2MIXER_FOUND "YES")
ENDIF(SDL2MIXER_LIBRARY AND SDL2MIXER_INCLUDE_DIR)
message("</FindSDL2_mixer.cmake>")
