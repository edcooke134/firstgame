 # Make an automatic library - will be static or dynamic based on user setting
 set(HEADER_LIST_AppLibrary
         "${CMAKE_SOURCE_DIR}/include/App/App.h"
         )

 # creates a library called AppLibrary
 add_library(AppLibrary
         App.cpp
         ${HEADER_LIST_AppLibrary}
         )

 # directory dependencies
 target_include_directories(AppLibrary PUBLIC
         ${CMAKE_SOURCE_DIR}/include
         )

 # library dependencies
 target_link_libraries(AppLibrary PUBLIC
         GladLibrary
         ${SDL2_LIBRARIES}
         ${SDL2IMAGE_LIBRARIES}
         )