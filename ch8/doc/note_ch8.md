# 函数重载
>- 返回值类型可以不同，但是特征标（参数列表）必须不同

# 模版
>>- 常见情形是，将模版放在头文件中，并在需要使用模版的文件中包含头文件。
>>- 优先级： 非模版 > 具体化(模板特化) > 常规模版  
>>- 模板特化    

|全特化 |偏特化|  
|:----:|:----:|  
|为模板提供了一个具体类型的完整定义|为一类类型提供特定的实现|  
```c++
// 全特化
template <>
class MyTemplate<int> { // 全特化MyTemplate模板类为int类型
    // 特化的实现
};
```
```c++
// 偏特化
template <typename T>
class MyTemplate<T*> { // 偏特化MyTemplate模板类为指针类型
    // 特化的实现
};
```

## 引用和指针常量  
>> 两者要在定义的时候初始化  
>> ```c++
>> int i = 1;
>> int& apple = i;  
>> int* const p = &i;
>> ```

>>>- 组名 arr 在上下文中会隐式转换为指向数组的指针
>>>- 参数传递 将非const值赋给const变量是合法的，反之不行。（范围可以缩小，但一定不可以扩大） 

>> precision
>>- precision() 返回当前的浮点数的精度值;  
>>- cout.precision(val) 在输出的时候设定输出值以新的浮点数精度值显示，就是设置输出值的有效位数

>> C++为标准输入和输出定义了一些格式标志, 它可以通过flags(), setf(), 和 unsetf() 三个函数来控制。  
>> cout.setf()的作用是通过设置格式标志来控制输出形式。(具体参见下面连接) 
>> https://blog.csdn.net/baishuiniyaonulia/article/details/79144033  
>> 第一原型 用来设置输出格式   
>> cout.setf(ios_base::left); //对所有cout的输出进行左对齐调整.  
>> 第二原型  
>> cout.setf(ios_base::fixed, ios_base::floatfield)