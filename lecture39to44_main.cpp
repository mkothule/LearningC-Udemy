#include <iostream>
#include <typeinfo> // required for typeid
#include <string>
#include <vector>

using namespace std;

template <class T>  // template function with trailing return type using decltype and auto as return type
// Only auto does not work we need trailing return type
auto test(T value) -> decltype(value){  // trailing return type
	return value;
}
// decltype can also take function as input, also complicated expression as well
int disp() {
	return 999;
}

auto get() -> decltype(disp()) {
	return disp();
}


template <class T>
class ring {
	int size;
	int idx;
	T * ring_vec;
public:
	class iterator;
	ring(int val) : size(val), ring_vec(NULL), idx(0){
		ring_vec = new T[size];
	}
	~ring(){
		delete [] ring_vec;
	}
	void add(T value)
	{
		idx = (idx == size) ? 0 : idx;
		ring_vec[idx++] = value;
	}
	T &get(int i)
	{
		return ring_vec[i];
	}
	int get_size() {
		return size;
	}
	iterator begin() {
		return iterator(0, *this);
	}
	iterator end() {
		return iterator(size, *this);
	}
};

template <class T>
class ring<T>::iterator {
	int m_size;
	int m_pos;
	ring &ring_vec; // No need to copy the array just reference is enough
public:
	void print(){
		cout << "Hello from iterator " << endl;
	}
	iterator(int pos, ring &ar) : m_pos(pos), ring_vec(ar) {
	}

	bool operator!=(const iterator &other) const {
		return m_pos != other.m_pos;
	}

	iterator operator++(int) { // postfix increment operator
		++m_pos;
		return *this;
	}

	T &operator*() {
		return ring_vec.get(m_pos);
	}
};



int main()
{
	//lecture 39 - decltype and typeid
	string val;
	//decltype
	cout << typeid(val).name() << endl;
	// int for int
	// double for double
	// class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > for string
	decltype(val) name = "Learn";
	cout << name << endl;

	// lecture 40 - auto keyword
	auto value = 98.0;
	cout << typeid(value).name() << endl;

	cout << test("Hello") << endl;
	cout << get() << endl;

	//lecture 41 - range based loop
	auto text = {"one", "two", "three"};

	for (auto t : text)
		cout << t << endl;

	vector<int> numbers = { 852, 963, 741};

	//for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	//	cout << *it << endl;

	for (auto n : numbers)  
		cout << n << endl;


	//lecture 42 and 43 - Nested template classes
	//implement a class that support range based loop
	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four");

	cout << "#################################################" << endl; // separator

	for (int i = 0; i < textring.get_size(); i++)
		cout << textring.get(i) << endl;

	//ring<string>::iterator it;
	//it.print();


	//lecture 44 make range based for loop work for user defined classes

	for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
		cout << *it << endl;
	// If above works then bewlo will also work


	//for (auto v : textring)
	//	cout << v << endl;


	while (1);
	return 0;

}