cmake_minimum_required(VERSION 3.28)
project(MDTranslator)

set(CMAKE_CXX_STANDARD 20)

# —— 若不使用 vcpkg，下面一行可注释 ——
#set(CMAKE_TOOLCHAIN_FILE "vcpkg_path/scripts/buildsystems/vcpkg.cmake:893 ")

# —— 若手动安装 curl，可设置以下变量 ——
# set(CURL_INCLUDE_DIR "C:/curl/include")
# set(CURL_LIBRARY     "C:/curl/lib/libcurl.lib")

find_package(CURL REQUIRED)

add_executable(MDTranslator  src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE CURL::libcurl
)