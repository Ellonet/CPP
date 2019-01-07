#include <iostream>
#include <string>

using namespace std;

//template<class T>
//
//void swappppp(T& a, T& b) {
//    T temp = b;
//    b = a;
//    a = temp;
//}
//int main() {
//    int a = 3, b=4;
//    cout << a << ", " << b << endl;
//    swappppp(a,b);
//    cout << a << ", " << b << endl;
//    swap(a,b);
//    cout << a << ", " << b << endl;
//}
////////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>
template<class T> void foo(T x) {
    cout << "in tamplate:" << endl;
    std::cout << "foo<" << typeid(T).name() << ">(T)\n";
}
void foo(int x) {
    cout << "in int:" << endl;
    std::cout << "foo<" << typeid(x).name() << ">(T)\n";
}
//void foo(double x) {
//    cout << "in double:" << endl;
//    std::cout << "foo<" << typeid(x).name() << ">(T)\n";
//}
int main() {
    foo(42);
    foo(42.0);
    foo("abcdef");
    return 0;
}

