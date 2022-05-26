#include <bits/stdc++.h>

class Array{
	private:
		int size;
		int* tab;
	public:
		int& operator [] (int i){
			return tab[i];
		}
		
		int get_size(){
			return size;
		}
		
		Array(int n = 0) : size(n), tab(size > 0 ? new int[size] : nullptr){
			std::cout << "Default constructor\n";
		}
		
		Array(const Array& other) : size(other.size), tab(size > 0 ? new int[size] : nullptr){
			std::cout << "Copy constuctor\n";
			for(int i = 0; i < size; i++)
				tab[i] = other.tab[i];
		}
		
		Array(Array&& other) : Array() {
			std::cout << "Move constructor\n";
			swap(*this, other);
		}
		
		Array& operator = (Array other){
			std::cout << "Copy assignment\n";
			swap(*this, other);
			return *this;
		}
		
		friend void swap(Array& first, Array& second){
			std::cout << "Swap\n";
			std::swap(first.size, second.size);
			std::swap(first.tab, second.tab);
		}
		
		virtual ~Array(){
			std::cout << "Destructor " << (tab == nullptr ? "NULL" : std::to_string(size)) << "\n";
			delete tab;
		}
};

Array range(int a, int b){
	Array out(b - a + 1);
	for(int i = 0; i < b - a + 1; i++)
		out[i] = a + i;
	return out;
}

class Foo{
	private:
		int a;
		int b;
	public:
		Foo(int a, int b) : a(a), b(b){}
};

int main(){
	Array a2(std::move(range(3, 7)));
	
	std::cout << a2.get_size() << "\n";
	for(int i = 0; i < 5; i++)
		std::cout << a2[i] << "\n";
	
	std::vector<Foo> v;
	v.emplace_back(5, 2);
}