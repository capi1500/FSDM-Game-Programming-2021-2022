#include <iostream>

using namespace std;

int main(){
	int x = 5;
	cout << x << " " << &x << "\n";
	int* ptr_x = &x;
	x = 10;
	cout << *ptr_x << " " << ptr_x << "\n\n";
	
	int* ptr;
	ptr = new int(3);
	cout << *ptr << " " << ptr << "\n";
	(*ptr) = 15;
	
	delete ptr;
}