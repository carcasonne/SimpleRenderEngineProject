# author: Chris (original from mortennobel)
# NEEDED:
# -include mixer
# - include bullet
# TODO:
# - incude assimp
# - make cross-platform
# - make more robust
# - refactor lib/include variables to make them more friendly towards target_include_directories and target_link_libraries

cmake_minimum_required(VERSION 3.8)
project(SimpleGameEngine CXX)

set( CMAKE_VERBOSE_MAKEFILE on )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# where to look for cmake "find" modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# custom, centralized path to dependencies
set(SGE_LIBS_PATH "" CACHE PATH "Path to the SimpleGameEngine libraries")

############################################################################
# Collect SGE libraries
############################################################################

# mixer
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2MIXER_INCLUDE_DIR})

# box2d
find_package(Box2D)
include_directories(${BOX_2D_INCLUDE_DIR})

# build sre library
add_subdirectory(submodules/SimpleRenderEngine)
get_directory_property(SRE_INCLUDE DIRECTORY submodules/SimpleRenderEngine DEFINITION SRE_INCLUDE)
get_directory_property(SRE_LIBRARIES DIRECTORY submodules/SimpleRenderEngine DEFINITION SRE_LIBRARIES)
get_directory_property(SRE_LIBRARIES_SHARED DIRECTORY submodules/SimpleRenderEngine DEFINITION SRE_LIBRARIES_SHARED)


include_directories(${SRE_INCLUDE})

# prepare static library list
set(SGE_LIBRARIES SRE ${SRE_LIBRARIES} ${SDL2MIXER_LIBRARY})

# prepare dynamic library list
set(SGE_LIBRARIES_SHARED ${SRE_LIBRARIES_SHARED} ${SDL2_MIXER_SHARED_LIBS})


message("424242: ${SGE_LIBRARIES}")
message("424243: ${SGE_LIBRARIES_SHARED}")

# build targets using sre
SET(USE_SGE_PROJECT_EXAMPLES ON CACHE BOOL "Enable project examples for SGE")
if (USE_SGE_PROJECT_EXAMPLES)
add_subdirectory(project)
endif(USE_SGE_PROJECT_EXAMPLES)
