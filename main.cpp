#include "fwd.hpp"
#include <assert.h>

int raw_data[] = {
    #include "data.inc" //可以通过include引入进来
};


[[noreturn]]
[[deprected("2023-08-01")]]
int func()
{
    throw runtime_error("no return error");
}

// [[gnu::constructor]]
// void before_main()
// {
//     cout << "before main!!!" << endl;
// }

// [[gnu::destructor]]
// void after_main()
// {
//     cout << "before main!!!" << endl;
// }

template <typename T> void foo1(T t)
{
    //C++17新增的断言模板参数的模板元函数
    static_assert(is_integral_v<T>);
    static_assert(is_pointer_v<T>);
    static_assert(is_constructible_v<T>);
}

void my_cb(const string &str)
{
    cout << "my callback " << str << endl;
}


int main()
{
    Utils().func1();

    cout << ADD(1, 2) << endl;
 
    cout << raw_data[0] << endl;

    // assert(false); 运行时断言

    // static_assert(false, "static assert failed"); 静态断言

    // foo1("1");

    // Impl a;
    // Impl b = a;


    StrClass s = static_cast<StrClass>("123");
    s.func();

    cout << helloworld << endl;

    auto_func();

    handle(my_cb);

    const_func();

    func_with_try_catch();
    
    funcs(2);

    return 0;
}