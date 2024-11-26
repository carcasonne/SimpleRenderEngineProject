# Engine Only

file(GLOB_RECURSE Exercise4.Engine-src "*.cpp")
file(GLOB_RECURSE Exercise4.Engine-hpp "*.h")

set(MYENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "" FORCE)

add_library(Exercise4.Engine ${Exercise4.Engine-src} ${Exercise4.Engine-hpp})

target_include_directories(Exercise4.Engine PUBLIC "Engine")
target_link_libraries(Exercise4.Engine ${SGE_LIBRARIES})

# group this shit together
IF (WIN32)
    set_target_properties(Exercise4.Engine PROPERTIES FOLDER "GameProgramming24/Exercise4")
ENDIF(WIN32)
