# 说明

This is a demo for dynamic library and static library. 这是一个使用CMake构建动态库和静态库的测试，也演示了pkgconfig文件的配置。

# 使用方式

先将func-utils-lib打成deb包安装后，再将func-utils-lib-test.pc（也可以将此文件放到func-utils-lib包中）拷贝到/usr/share/pkgconfig/目录后执行

```
gcc main.c -fpie -pie -o main $(pkg-config --cflags --libs func-utils-lib-test)
```

![](./pkg_content.png)

# 运行

![](./result.png)

#### 注意事项：

1. 可以将静态库libtest.a链接到动态库.so中（target_link_libraries(my_dynamic_lib /home/staticlib/libtest.a)），但静态库编译时必须加-fPIC编译参数。

2. python中的ctypes不支持加载静态库。
   
3. python中的ctypes加载动态库liba.so,liba.so依赖于libc.a,在程序运行时不会自动链接libc.a,此时可以将静态库链接到so库中后，python可以正常调用so库中的api。
   
# 参考文档

* [pkg-config的简单用法](https://blog.csdn.net/feng__shuai/article/details/126916291)

* https://github.com/Liuyvjin/notebook/tree/master/Cmake
