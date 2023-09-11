#include <iostream>
#include <vector>
#include <list>
using namespace std;

//struct Point
//{
//    int _x;
//    int _y;
//};
//
// class Date
//{
//public:
//    explicit Date(int year, int month, int day): _year(year), _month(month), _day(day) 
//    {
//        cout << "Date(int year, int month, int day)" << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    int x1 = 1;
//    int x2 = { 2 };
//    // 省略赋值符号
//    int x3{ 3 };
//    int array[]{ 1,2,3,4,5 };
//    int array[5]{ 0 };
//    Point p{ 1, 2 };
//
//    // C++11中列表初始化也可以适用于new表达式中
//    int* pa = new int[4] {0};
//    
//    Date d1(2022, 1, 1);
//
//    // C++11支持的列表初始化，调用构造函数初始化
//    Date d2{ 2022, 1, 2 };
//    //Date d3 = { 2022,1,3 };
//
//    return 0;
//}

int main()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 10,20,30 };

	list<int> lt1 = { 1,2,3,4,5 };
	list<int> lt2 = { 10,20,30 };

	auto i1 = { 10,20,30,1,1,1,2 };
	auto i2 = { 10,20,30 };

	cout << typeid(i1).name() << endl;
	cout << typeid(i2).name() << endl;

	initializer_list<int>::iterator it1 = i1.begin();
	initializer_list<int>::iterator it2 = i2.begin();


	return 0;
}