# 文件读取
>- 在fstream类中，成员函数open（）实现打开文件的操作，从而将数据流和文件进行关联，通过ofstream,ifstream,fstream对象进行对文件的读写操作
>- 默认情况下 open() 打开文件先截断该文件，即丢弃原文件，然后再将新内容输入进去

> #include <fstream\>  
> ofstream         //文件写操作 内存写入存储设备   
> ifstream         //文件读操作，存储设备读取到内存中  
> fstream          //读写操作，对打开的文件可进行读写操作   