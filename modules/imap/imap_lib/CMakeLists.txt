project(imap_lib)

set(HEADER_FILES
        IMLayer.h
        IMLayerAdd.h
        IMLayerConvolve.h
        IMLayerDraw.h
        IMLayerPoint.h
        )

set(SOURCE_FILES
        IMLayer.cpp
        IMLayerAdd.cpp
        IMLayerConvolve.cpp
        IMLayerDraw.cpp
        IMLayerPoint.cpp
        )

add_library(imap_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})