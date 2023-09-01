#include <map>
#include <string>
#include <vector>

auto helloworld = "hello world"s;
std::map<int, std::string> m = {{1, "a"}, {2, "b"}}; //不能用auto推断出来

auto && num = 5;

int d_x = 0;

decltype(d_x) d_y; //declare type


using dd_x = decltype(d_x);

decltype(auto) d_z = 12;

auto auto_func()
{
    vector<int> vv = {1,2,3,4,5};
    for(const auto& i : vv)
    {
        cout << i << endl;
    }

    tuple a {"1", 2, 3.0f}; //C++17 模板参数推导特性
    auto [x,y,z] = a;
    cout << x << y << z << endl;

    map<string, string> map = {{"1","z"}, {"2", "a"}};
    for (auto& [k,v] : map)
    {
        cout << "key=" << k << " value=" << v << endl;
    }

    return 0;
}

void call_back(const string &str)
{
    cout << "callback " << str << endl;
}

void handle(decltype(&call_back) func) //decltype能够轻松获取到函数指针
{
    func("!!!");
}