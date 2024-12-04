# Game Only

file(GLOB_RECURSE Exercise4.Game-src "*.h" "*.cpp")

add_executable(Exercise4.Game ${Exercise4.Game-src} "Game/PlayerController.h" "Game/PlayerController.cpp" "Game/AsteroidController.h" "Game/AsteroidController.cpp")

target_include_directories(Exercise4.Game PUBLIC ${MYENGINE_INCLUDE_DIR})

target_link_libraries(Exercise4.Game Exercise4.Engine ${SGE_LIBRARIES})

# Copy project data to output path
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


IF (WIN32)
	## Copy dll's to output path
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
ENDIF(WIN32)

IF (WIN32)
	set_target_properties(Exercise4.Game PROPERTIES FOLDER "GameProgramming24/Exercise4")
ENDIF(WIN32)