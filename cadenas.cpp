#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    string str1 = "Hello world!";
    string str2(str1);
    string str3(7, 'A');
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str2.at(0) << endl;
    cout << str2.substr(0,3) << endl;
    cout << str3 << endl;
    cout << str3.push_back('B') << endl;
    return 0;
}
