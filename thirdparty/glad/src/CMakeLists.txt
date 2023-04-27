 add_library(GladLibrary
         glad.c
         ${CMAKE_SOURCE_DIR}/thirdparty/glad/include/glad/glad.h
         ${CMAKE_SOURCE_DIR}/thirdparty/glad/include/KHR/khrplatform.h
         )

 # directory dependencies
 target_include_directories(GladLibrary PUBLIC
         ${CMAKE_SOURCE_DIR}/thirdparty/glad/include
         )
