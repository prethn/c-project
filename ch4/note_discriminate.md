# 函数指针和指针函数
> 偏正短语
## 函数指针
>> 本质上是函数的地址，有指向性。
>> 使用：先把要实现的函数写好，然后定义一个函数指针，通过指向不同的函数（赋值）即可通过函数指针实现整串功能。比如屏幕切换、函数表、回调函数等
```c++
// 屏幕切换
void mainScreen() {
    printf("This is the main screen.\n");
    // 这里可以添加更多逻辑
}

void settingsScreen() {
    printf("This is the settings screen.\n");
    // 这里可以添加更多逻辑
}
int main() {
    int input;
    // 声明一个函数指针，并默认指向主屏幕
    void (*screen)() = mainScreen;
    while (1) {
        // 调用当前指向的屏幕函数
        screen();
        printf("Enter 1 for Main Screen, 2 for Settings, 0 to exit: ");
        scanf("%d", &input);
        // 根据输入切换屏幕
        switch (input) {
            case 1:
                screen = mainScreen;
                break;
            case 2:
                screen = settingsScreen;
                break;
            case 0:
                return 0; // 退出程序
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
```
----
```c++
// 函数表
// 定义命令处理函数
void command1() ；
void command2() ；
void command3() ；
// 函数指针数组定义
void (*functionTable[])(void) = {command1, command2, command3};

int main() {
    int command = 0;
    int numCommands = sizeof(functionTable) / sizeof(functionTable[0]);

    while (1) {
        scanf("%d", &command);
        if (command == -1) {
            break; 
        } else if (command > 0 && command <= numCommands) {
            // 调用对应的命令处理函数
            (*functionTable[command - 1])();
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}
```
-----
```c++
// 回调函数
// 定义回调函数类型
typedef void (*Callback)(int);//定义接口类型（无返回值，参数类型为 int）,用户根据这个类型创建相关函数。
// Callback callbackFunction 函数类型（接口） 函数名
// 实现一个调用回调函数的函数
void registerCallback(Callback callbackFunction) {
    printf("Registering callback...\n");
    // 在合适的时刻调用回调函数
    callbackFunction(42); // 假设传递的参数
}

// 用户定义的回调函数
void myCallbackFunction(int num) {
    printf("Callback called with %d\n", num);
}

int main() {
    // 将用户定义的回调函数传递给另一个函数
    registerCallback(myCallbackFunction);
    return 0;
}
// 
```
## 指针函数
>> 使用：1、避免全局变量的使用（配合局部静态变量）  
        2、函数返回多变量
```c++
// 定义一个返回int类型指针的函数
int* allocateArray(int size) {
    // 动态分配内存
    int* arr = (int*)malloc(size * sizeof(int));
    return arr; // 返回指向分配的内存的指针
}

int main() {
    int* myArray = allocateArray(5); // 调用指针函数 //返回地址
    // 使用myArray...
    free(myArray); // 释放内存 //传递地址
    return 0;
}
```
-----
```c++
// 返回多变量
typedef struct {
    int a;
    int b;
} Values;

Values* updateValues() {
    static Values val;
    val.a = 1; // 假设的某种计算结果
    val.b = 2; // 假设的另一种计算结果
    return &val;
}
```