#include <iostream>

using namespace std;

int n = 2;

auto funcs = [](int x) { cout << "hello world " << x * n <<endl;};

auto f3 = [](long x) -> int { return static_cast<int>(x);}; //lambda表达式一般不需要明确声明返回值类型，可以自动推导，但有时候需要明确指定返回类型，需要用类似rust的语法指定