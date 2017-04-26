#include <iostream>
using namespace std;
class Base{
protected:
	Base(){cout<<'A';}
	Base(char c){cout<<c;}
};
class Derived:public Base{
public:
	Derived(char c){cout<<c;}
};
int main(){
	Derived d1('B');
	return 0;
}