cmake_minimum_required(VERSION 3.28)
project(MDTranslator)

set(CMAKE_CXX_STANDARD 20)

# 若不使用 vcpkg，下面一行可注释
set(CMAKE_TOOLCHAIN_FILE "vcpkg_path/scripts/buildsystems/vcpkg.cmake:893 ")

# 若手动安装 curl，可设置以下变量
# set(CURL_INCLUDE_DIR "C:/curl/include")
# set(CURL_LIBRARY     "C:/curl/lib/libcurl.lib")

find_package(CURL REQUIRED)

# 把所有 .h 文件收集到 INCLUDES
file(GLOB INCLUDES
        "${CMAKE_SOURCE_DIR}/include/*.h"
        "${CMAKE_SOURCE_DIR}/include/translator/*.h"
)

# 把所有 .cpp 文件收集到 SOURCES
file(GLOB SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/translator/*.cpp"
)

# 添加所有编译的可执行文件
add_executable(MDTranslator  ${INCLUDES} ${SOURCES})

# 链接外部头文件
target_link_libraries(${PROJECT_NAME}
        PRIVATE CURL::libcurl
)