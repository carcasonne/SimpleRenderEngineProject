# author: Chris
# TODO
# - make cross-platform
# - handle more robust-genmeric paths
# - handle debug/release configurations
# - remove redundant variables
# - mark variables as advanced when possible

message("<FindBox2D.cmake>")

set(BOX2D_PATH "${SGE_LIBS_PATH}/box2d")


find_path(BOX_2D_INCLUDE_DIR
        NAMES box2d/box2d.h
        PATH_SUFFIXES box2d
        # path suffixes to search inside ENV{SDLDIR}
        include/box2d include
        PATHS
            ${BOX2D_PATH}
        )

find_library(BOX2D_LIBRARY
        NAMES box2d
        PATH_SUFFIXES bin/Debug build/bin/Debug # TODO handle debug/release
        PATHS ${BOX2D_PATH}
        )

mark_as_advanced(BOX_2D_INCLUDE_DIR BOX2D_LIBRARY)
message("</FindBox2D.cmake>")
