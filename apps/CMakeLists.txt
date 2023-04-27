set(APP_NAME "TheGame")
add_executable(${APP_NAME} main.cpp)
target_compile_features(${APP_NAME} PRIVATE cxx_std_17)

# library dependencies
target_link_libraries(${APP_NAME} PRIVATE
        AppLibrary
)
