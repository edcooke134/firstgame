 # Make an automatic library - will be static or dynamic based on user setting
 set(HEADER_LIST_RenderingLibrary
         "${firstgame_SOURCE_DIR}/include/Rendering/RenderWindow.h"
 )

 # creates a library called RenderingLibrary
 add_library(RenderingLibrary
         RenderWindow.cpp
         ${HEADER_LIST_RenderingLibrary}
 )

 # directory dependencies
 target_include_directories(RenderingLibrary PUBLIC
         ${firstgame_SOURCE_DIR}/include
  )

 # library dependencies
 target_link_libraries(RenderingLibrary PRIVATE
         ${SDL2_LIBRARIES}
         ${SDL2IMAGE_LIBRARIES}
  )

 set(HEADER_LIST_RenderingLibrary
         "${firstgame_SOURCE_DIR}/include/Entity/Entity.h"
  )

 add_library(EntityLibrary
         Entity.cpp
         ${HEADER_LIST_RenderingLibrary}
 )

 target_include_directories(EntityLibrary PUBLIC
         ${firstgame_SOURCE_DIR}/include
  )

 target_link_libraries(EntityLibrary PRIVATE
         ${SDL2_LIBRARIES}
         ${SDL2IMAGE_LIBRARIES}
 )