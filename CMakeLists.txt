cmake_minimum_required(VERSION 3.20)
project(regain_c C)

set(CMAKE_C_STANDARD 11)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/**/*.c")
foreach(file ${files})
    # 拿到去掉路径和后缀名的纯文件名
    get_filename_component(name ${file} NAME_WE)
    # 下面两步是为了拿到文件路径的最后一个目录部分
    get_filename_component(path ${file} PATH)
    get_filename_component(last_dir ${path} NAME)
    # 为每个单独的 c 文件加入可执行的编译配置
    add_executable(${last_dir}____${name} ${file})
endforeach()
