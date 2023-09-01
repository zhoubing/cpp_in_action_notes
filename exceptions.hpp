#include <stdexcept>
#include <iostream>

/*
4个应当使用异常的判断准则：
1.不允许被忽略的错误
2.极少情况下才会发生的错误
3.严重影响正常流程，很难恢复到正常状态的错误
4.本地无法处理，必须穿透调用栈传递到上层才能被处理的错误。
*/

class my_exception : public std::runtime_error
{
public:
    my_exception(const char *msg) : std::runtime_error(msg)
    {
    }
};

[[noreturn]] void raise(const char *msg) // 通过定义方法来引发异常
{
    throw my_exception(msg);
}

void func_with_try_catch()
{
    try
    {
        raise("exception raised!");
    }
    catch (const std::exception &e)
    {
        std::cerr << "catch " << e.what() << '\n';
    }
}


//function try
void function_try()
try
{
    raise("exception raised!");
}
catch (const std::exception &e)
{
    std::cerr << "catch " << e.what() << '\n';
}

//noexcept的意思是 我保证不抛出异常，如果真发生异常 就让我死的快点儿
void func_with_no_except() noexcept
{

}