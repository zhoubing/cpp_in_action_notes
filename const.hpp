#include <iostream>
#include <assert.h>
#include <bitset>

class Const final
{
private:
    int num = 0;
    mutable int counter = 0;

public:
    void func() const // 不可变函数 不会修改对象的状态（成员变量），函数执行的只读操作
    {
        // num++;
    }

    void func2()
    {
        num++;
    }

    void func1(int num)
    {
        num++;
    }

    void func3() const
    {
        counter++; // 即使是const函数也可以修改mutable修饰的变量，相当于在const对象上打了一个补丁，让某些特殊的变量允许修改。因为即使是一个const的对象也有可能有一些成员变量是需要能够被修改的。它只能修饰类里面的成员变量
    }
};

// 编译期常量 只能修饰基本类型和字符串字面量 不能修饰map string等需要动态变化的容器类型
constexpr int MAX = 100;
constexpr auto ss = "ss";
// constexpr string sss = "sss";

//修饰函数的时候要求不能有运行期的特性 比如trycatch 不能有动态分配内存等。。。
constexpr long mega_bits()
{
    return 1024 * 1024;
}



void const_func()
{
    // 如果是const的话就不允许改了 这里多了个volatile,如果只是const的话 那么一切对于const变量的修改都会被编译器优化掉 编译器会把所有const变量替换成常量造成所有对这个变量的更改都无用了
    // 如果加上volatile，就会告诉编译器这个变量有可能不稳定会变化，所以编译器就不会自作主张的去优化了。在读取这个变量的代码处会生成去内存取值的CPU指令，而不是自作主张的直接替换成常量值了。
    const volatile int MAX_LEN = 1024;
    auto ptr = const_cast<int *>(&MAX_LEN);
    *ptr = 2048;
    std::cout << MAX_LEN << std::endl;

    // const指针
    string name = "zhoubing";
    const string *p_name = &name;           // name是常量
    string *const k_p_name = &name;         // 指针是常量
    const string *const k_p_k_name = &name; // name和指针都是常量

    decltype(auto) n = as_const(name);
    assert(is_reference_v<decltype(n)>);
    assert(is_const_v<remove_reference_t<decltype(n)>>);

    // Const cst;
    // auto& a = as_const(cst); //const只能调用const函数
    // a.func();

    Const cst;
    auto &a1 = as_const(cst);
    a1.func3();

    
}