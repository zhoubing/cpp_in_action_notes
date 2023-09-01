#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include <iostream>
#include <vector>

using namespace std;


//using在c++17的扩展用法 类似于typedef
using mystr = string; // typedef mystr string;

class Utils final 
{
public:
    void func1()
    {
        cout << "func1 exec" << endl;
    }
};

class Interface
{
    virtual void func1() = 0;
};

class Abstract : Interface
{
    void func1() final  //禁止重载
    {

    }
};

class Impl final : Abstract //禁止继承
{
public:
    Impl() = default;
    ~Impl() = default; //虽然编译器会自动生成，但是还是建议明确用default写出来 使用默认实现比较好

    Impl(const Impl&) = delete; //禁止使用拷贝构造函数
    Impl & operator=(const Impl&); //禁止使用赋值赋值函数
};

class StrClass final
{
public:
    explicit StrClass(const char* str) {//禁止隐式转换StrClass s = "123" 只能StrClass s = static_cast<StrClass>("123");或者StrClass a = (StrClass) "123"
        this->str = str;
    } 

    void func() {
        cout << this->str << endl;
    }
private:
    const char *str;
};

//委托构造
class Delegate final 
{
public:
    Delegate(int a) : a(a) {}

    Delegate() : Delegate(0) {}
private:
    int a;
};

//成员变量初始化
class Init final
{
private:
    int a = 0;
    const string &str = "123";
    vector<int> v {1,2,3};

    inline static mystr name = "how"; //内联变量初始化静态变量
    static const int x = 0; //如果是静态常量就无所谓了，直接初始化即可
};

#endif