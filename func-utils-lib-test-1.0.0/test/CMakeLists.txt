INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

ADD_EXECUTABLE(main main.c)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/test/bin)
# LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/src/lib)
# 链接动态库
TARGET_LINK_LIBRARIES(main func_utils)

# func_utils为需要查找的库文件的名称，通常不需要加后缀
FIND_LIBRARY(STATIC_LINK_LIB func_utils PATHS ${PROJECT_SOURCE_DIR}/staticlib)
IF (STATIC_LINK_LIB)
    MESSAGE(STATUS "Found STATIC_LINK_LIB: ${STATIC_LINK_LIB}")
ELSE()
    MESSAGE(STATUS "STATIC_LINK_LIB not found")
ENDIF()

# 链接静态库 静态库是在编译的时候生成的，所以不能使用 ${PROJECT_BINARY_DIR}/src/lib里面的库文件
# TARGET_LINK_LIBRARIES(main ${STATIC_LINK_LIB})
# 也可以直接写静态库的路径
# TARGET_LINK_LIBRARIES(main ${PROJECT_SOURCE_DIR}/staticlib/libfunc_utils.a)
# 引入静态库和动态库的区别
# 1、引入静态库时，静态库在连接阶段会被连接到最终目标中(比如可执行执行程序中)，缺点就是同一份静态库如果被不同的程序引用，那么内存中会存在这个静态库函数的多份拷贝
# 2、引入动态库时，连接阶段不会被拷贝最终目标中，程序运行时将按照指定的规则(上一步提到的规则，并非编译时的动态库路径)去搜索这个动态库，搜索到了之后才加载到内存中。所以多个程序就算引用了同一个动态库，内存中也只是存在一份动态库函数的拷贝