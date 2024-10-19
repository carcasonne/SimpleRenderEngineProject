file(GLOB GuiSrc
        "*.hpp"
        "*.h"
        "*.cpp"
        )

# Compile cpp files
add_executable(SRE-Gui ${GuiSrc})
target_link_libraries(SRE-Gui ${SGE_LIBRARIES})

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

IF (WIN32)
    file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION .)

    # Set working directory to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    set_target_properties(SRE-Gui PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    set_target_properties(SRE-Gui PROPERTIES FOLDER "SimpleRenderEngine")
ENDIF(WIN32)
