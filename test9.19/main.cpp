
//拷贝构造函数调用时机
//1.使用一个已经创建完毕的对象来初始化一个新对象
//2.值传递的方式给函数参数传值
//9.20
#if 0
//1
#include <iostream>
using namespace std;
class Person{
public:
    Person(){
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height){
        m_Age = age;
        m_Height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }
    //自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p){
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        //m_Height = p.m_Height; //编译器默认实现的代码
        //深拷贝操作
        m_Height = new int(*p.m_Height);
    }
    ~Person(){
        //析构代码，将堆区开辟数据做释放操作
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;   //防止野指针出现
        }
        cout << "Person的析构函数调用" << endl;
    }
    int m_Age;
    int *m_Height;
};
void test01(){
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
class Phone{
public:
    Phone(string pName){
        m_PName = pName;
    }
    string m_PName;
};
class Person{
public:
    //m_Phone(pName)相当于 Phone m_Phone = pName 隐式转换法
    Person(string name,string pName):m_Name(name), m_Phone(pName){
        cout << "Person的构造函数调用" << endl;
    }
    string m_Name;
    Phone m_Phone;
};
void test01(){
    Person p("张三", "张三的MAX")
}
int main(){

}
#endif
#if 0
#include <iostream>
using namespace std;
class Person{
public:
    //1.所有对象共享同一份数据
    //2.在编译阶段分配内存
    //3.类内声明，类外初始化操作
    static int m_A;
private:
    static int m_B; //类外访问不到
};
int Person::m_A =100;//类外初始化

void test01(){
    Person p;
    cout << p.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}
int main(){
    test01();
    Person p;
    cout << p.m_A << endl;
    cout << Person::m_A << endl;
    system("pause");
    return 0;
}
#endif
#if 0
//9.24
#include<iostream>
using namespace std;
//静态成员函数
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量
class Person{
public:
    static void func(){
        m_A = 100; //静态成员函数可以访问静态成员变量
        //但是不能访问非静态成员变量
        cout << "static void func调用" << endl;
    }
    static int m_A;
    int m_B;   //非静态成员变量
};
int Person::m_A = 0;
//有两种访问方式
void test01(){
    //1.通过对象访问
    Person p;
    p.func();
    //2.通过类名访问
    Person::func();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
//在c++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上
#include <iostream>
using namespace std;
class Person{
    int m_A; // 非静态成员变量 属于类的对象上
    static int m_B; //静态成员变量 不属于类对象上
    void func() {} //非静态成员函数 不属于类的对象上
    static void func2(){} //静态成员函数 不属于类的对象上
};
void test01(){
    Person p; //看这个对象占多少内存
    cout << "size of p = " << sizeof(p) << endl; //若为空对象则占用一个字节
};
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class Person{
public:
    Person(int age){
        //this指针指向被调用的成员函数所属的对象。
        this->age = age;
    }
    //引用方式(Person&)返回，一直返回p2，若以值方式(Person)返回，会创建拷贝一个新对象进行返回
    Person& PersonAaaAge(Person &p1){
        this->age += p1.age;
        //this指向p2的指针，而*this指向p2这个对象的本体
        return this*;
    }
    int age;
};
//1.解决名称冲突
void test01(){
    Person p1(18);
    cout << p1.age << endl;
}
//2.返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想 cout也是这种思想
    p2.PersonAaaAge(p1).PersonAaaAge(p1).PersonAaaAge(p1).PersonAaaAge(p1);
    cout << p2.age << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//空指针调用成员函数
class Person{
public:
    void showClassName(){
        cout << "this is Person class" << endl;
    }
    void showPersonAge(){
        if(this == NULL){
            return;
        }
        cout << "age = " << m_Age << endl;
    }
    int m_Age;
};
void test01(){
    Person * p = NULL;
    p->showClassName();
    p->showPersonAge();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//常函数
class Person{
public:
    //this指针的本质 是指针常量 指针的指向是不可以修改的
    //const Person * const this
    //在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
    void showPerson() const{
        //this->m_A = 100;  //加const后则不可修改成员属性
        this->m_B = 100;
    }
    void func(){

    }
    int m_A;
    mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
};
void test01(){
    Person p;
    p.showPerson();
}
//常对象
void test02(){
    const Person p; //对象前加const
    //p.m_A = 100; //在常对象中不可修改
    p.m_B = 100;    //m_B是特殊值，在常对象下也可以修改
    p.showPerson(); //可以调用常函数
    //p.func();   //不可调用普通函数 因为普通函数可以修改属性
}
int main(){
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
class Building{
    //goodGay全局函数是Building好朋友，可以访问building中私有成员
    friend void goodGay(Building *building);
public:
    Building(){
        m_BedRoom = "卧室";
        m_SittingRoom = "客厅";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//全局函数
void goodGay(Building *building){
    cout << "好基友全局函数 正在访问 ：" << building->m_SittingRoom << endl;
    cout << "好基友全局函数 正在访问 ：" << building->m_BedRoom << endl;

}
void test01(){
    Building building;
    goodGay(&building);
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
class Building;
class GoodFriend{
public:
    GoodFriend();
    void visit(); //参观函数 访问Building中的属性
    Building * building;
};
class Building{
    //Goodfriend是本类好朋友，可以访问本类私有成员
    friend class GoodFriend;
public:
    Building();
public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;  //卧室
};
//类外写成员函数
Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodFriend::GoodFriend(){
    //创建建筑物对象
    building = new Building;
}
void GoodFriend::visit() {
    cout << "好朋友类正在访问： " << building->m_SittingRoom << endl;
    cout << "好朋友类正在访问： " << building->m_BedRoom << endl;
}
void test01(){
    GoodFriend ff;
    ff.visit();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//成员函数做友元
#if 0
#include <iostream>
#include <string>
using namespace std;
class Building;
class Goodfriend{
public:
    Goodfriend();
    void visit();   //让visit函数可以访问Building中私有成员
    void visit2();   //让visit2函数不可以访问Building中私有成员
    Building * building;
};
class Building{
    //告诉编译器，Goodfriend中的成员函数visit作为friend可以访问Building中的私有成员
    friend void Goodfriend::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//类外实现成员函数
Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
Goodfriend::Goodfriend() {
    building = new Building;
}
void Goodfriend::visit() {
    cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
}
void Goodfriend::visit2() {
    cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
}
void test01(){
    Goodfriend ff;
    ff.visit();
    ff.visit2();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//重载+号
#if 0
#include <iostream>
using namespace std;
class Person{
public:
    Person operator+ (Person &p){
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    int m_A;
    int m_B;
};
Person operator+ (Person &p1, Person &p2){
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
int main(){
    system("pause");
    return 0;
}
#endif
//重载左运算符
#if 0
#include<iostream>
using namespace std;
class Person{
    friend ostream & operator<<(ostream &cout,Person &p);
public:
    Person(int a, int b){
        m_A = a;
        m_B = b;
    }
private:
    int m_A;
    int m_B;
};

//本质  operator<<(cout, p)  简化 cout << p
ostream & operator<<(ostream &cout,Person &p){
    cout << "m_A " << p.m_A << "   m_B" << p.m_B;
    return cout;
}
void test01(){
    Person p(10, 10);
    cout << p << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//重载递增运算符
#if 0
#include <iostream>
using namespace std;
class MyInteger{
    friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符
    MyInteger& operator++(){
        m_Num++;
        return *this;
    }
    //重载后置++运算符  int 代表占位参数，可以用于区分前置和后置递增
    void operator++(int){
        //先 记录当时结果
        MyInteger temp = *this;
        //后 递增
        m_Num++;
        //最后将记录结果做返回
        return temp;
    }
private:
    int m_Num;
};
ostream& operator<<(ostream& cout, MyInteger myint){
    cout << myint.m_Num;
    return cout;
}
void test01(){
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}
void test02(){
    MyInteger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}
int main(){
//    test01();
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//赋值运算符重载
class Person{
public:
    Person(int age){
        m_Age = new int(age); //new 一个int 返回int* 给m_Age
    }
    ~Person(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
    //重载 赋值运算符
    Person& operator=(Person &p){
        //编译器是提供浅拷贝
        //m_Age = p.m_Age;
        //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age); //深拷贝
        return *this;
    }
    int *m_Age;
};
void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;
    cout << "p1的年龄为： "<< *p1.m_Age << endl;
    cout << "p2的年龄为： "<< *p2.m_Age << endl;
    cout << "p3的年龄为： "<< *p2.m_Age << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    }
    //重载 == 号
    bool operator == (Person &p){  //或者!=
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;         //retuen false;
        }
        return false;            //return true;
    }
    string m_Name;
    int m_Age;
};
void test01(){
    Person p1("Tom", 18);
    Person p2("Jerry", 18);
    if(p1 == p2){
        cout << "p1和p2是相等的！" << endl;
    } else{
        cout << "p1和p2是不相等的！" << endl;
    }

}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//函数调用运算符重载
#if 0
#include <iostream>
using namespace std;
#include <string>
//函数调用运算符重载
//打印输出类
class MyPrint{
public:
    //重载函数调用运算符
    void operator()(string test){
        cout << test << endl;
    }
};
void MyPrint02(string test){
    cout << test << endl;
}
void test01(){
    MyPrint myPrint;
    myPrint("hello world"); //由于使用起来非常类似于函数调用，因此称为仿函数
    MyPrint02("hello world");
}
//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};
void test02(){
    MyAdd myAdd;
    int ret = myAdd(100, 100);
    cout << "ret = " << ret << endl;
    //匿名函数对象  当前行执行完立即被释放
    cout << MyAdd()(100, 100) << endl;  //MyAdd()为匿名函数对象
}
int main(){
//    test01();
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//普通实现页面
//Java页面
class Java{
public:
    void header(){
        cout << "首页、公开课、登录、注册……（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图……（公共底部）" << endl;
    }
    void left(){
        cout << "Java、Python、C++、……（公共分类列表）" << endl;
    }
    void content(){
        cout << "Java学科视频" << endl;
    }
};
class Python{
public:
    void header(){
        cout << "首页、公开课、登录、注册……（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图……（公共底部）" << endl;
    }
    void left(){
        cout << "Java、Python、C++、……（公共分类列表）" << endl;
    }
    void content(){
        cout << "Python学科视频" << endl;
    }
};
class CPP{
public:
    void header(){
        cout << "首页、公开课、登录、注册……（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图……（公共底部）" << endl;
    }
    void left(){
        cout << "Java、Python、C++、……（公共分类列表）" << endl;
    }
    void content(){
        cout << "c++学科视频" << endl;
    }
};
void test01(){
    cout << "Java下载视频页面如下：" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-----------------------"<< endl;
    cout << "Python下载视频页面如下：" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-----------------------"<< endl;
    cout << "c++下载视频页面如下：" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
    cout << "-----------------------"<< endl;

}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//继承实现页面
class BasePage{
public:
    void header(){
        cout << "首页、公开课、登录、注册……（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图……（公共底部）" << endl;
    }
    void left(){
        cout << "Java、Python、C++、……（公共分类列表）" << endl;
    }
};
//继承的好处：减少重复代码
//语法： class 子类： 继承方式 父类
//子类（也称为派生类） 父类（也称为基类）
class Java: public BasePage{
public:
    void content(){
        cout << "Java学科视频" << endl;
    }
};
class CPP: public BasePage{
public:
    void content(){
        cout << "cpp学科视频" << endl;
    }
};
class Python: public BasePage{
public:
    void content(){
        cout << "python学科视频" << endl;
    }
};
void test01(){
    cout << "Java下载视频页面如下：" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-----------------------"<< endl;
    cout << "Python下载视频页面如下：" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-----------------------"<< endl;
    cout << "c++下载视频页面如下：" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
    cout << "-----------------------"<< endl;

}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//继承中的对象模型
class  Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_c;
};
class Son:public Base{
public:
    int m_D;
};
void test01(){
    cout << "size of Son = " << sizeof (Son) << endl;
}
int main(){
    test01(); //sizeof = 16
    system("pause");
    return 0;
}
#endif
//继承构造析构顺序
#if 0
#include <iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base的构造函数！" << endl;
    }
    ~Base(){
        cout << "Base的析构函数！" << endl;
    }
};
class Son : public Base{
public:
    Son(){
        cout << "Son构造函数！" << endl;
    }
    ~Son(){
        cout << "Son析构函数！" << endl;
    }
};
void test01(){
    //Base b;
    Son s;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
//继承中同名成员处理方式
class Base{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout << "Base 下 func() 调用" << endl;
    }
    void func(int a){
        cout << "Base 下 func(int) 调用" << endl;
    }
    int m_A;
};
class Son: public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout << "Son 下 func() 调用" << endl;
    }
    int m_A;
};
//同名成员属性处理
void test01(){
    Son s;
    cout << "Son  下 m_A = " << s.m_A << endl;
    //如果通过子类对象 访问到父类中同名成员，需要加作用域
    cout << "Base 下 m_A = " << s.Base::m_A << endl;
}
//同名成员函数处理
void test02(){
    Son s;
    s.func();
    s.Base::func();
    s.Base::func(10);
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class A{
    int a;
public:
    A(int i = 0):a(i){cout << a;}
};
void f2(){
    A c;
    throw -1;
}
void f1(){
    try{
        f2();
    }
    catch (int){
        cout << "#" << endl;
    }
}
int main(){
    f1();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class T{
    int t;
public:
    T(int x = 0):t(x){cout << "#";}
    ~T(){cout<<"*";}
};
class D:public T{
    int d;
public:
    D(int x = 0,int y = 0):T(x),d(y){cout << "@";}
    ~D(){cout<<"%";}
};
int main(){
    D *p = new D;
    delete p;
    p = new D(1,2);
    delete p;
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class A{
public:
    void f(){cout<<"A::f()"<<endl;}
    virtual void g(){cout << "A::g()" << endl;}
};
class B:public  A{
public:
    void f(){cout<<"B::f()"<<endl;}
    void g(){cout<<"B::g()"<<endl;}
};
int main(){
    B b;
    A *pa = &b;
    if(dynamic_cast<B*>(pa)==NULL){
        cout<<"NULL"<<endl;
    } else{
        dynamic_cast<B*>(pa)->f();
        dynamic_cast<B*>(pa)->g();
    }
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class Animal{
public:
    int m_Age;
};
class Sheep :virtual public Animal {

};
class Tuo :virtual public Animal{

};
class SheepTuo :public Sheep, public Tuo{

};
void test01(){
    SheepTuo st;
    //当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    st.m_Age = 38;
    cout << "st.m_Age = " << st.m_Age << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
//关于const的题，单独出一个博客
#include<iostream>
using namespace std;
int main()
{
    int i = 10;
    int &p1 = i;
    const int &p2 = i;
    p1= 5;
    cout <<p2 <<""<<p1 <<endl;
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char c[200000];
    long long str;
    cin >> c;
    str = strlen(c);
    for(int i = 0; i < str; i++){
        if(c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U'){
            c[i] += 32;
        }
        else if(c[i] != 'a' && c[i] != 'e' && c[i] != 'i' && c[i] != 'o' && c[i] != 'u'){
            if(c[i] > 'Z'){
                c[i] -= 32;
            }
        }
    }
    cout << c;
    system("pause");
    return 0;
}
#endif
//多态
#if 0
#include <iostream>
using namespace std;
//多态
class Animal{
public:
    //虚函数
    void virtual speak(){
        cout << "动物在说话" << endl;
    }
};
class Cat :public Animal{
public:
    void speak(){
        cout << "小猫在说话" << endl;
    }
};
class Dog :public Animal{
public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
};
//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定
void doSpeak(Animal &animal){ //Animal & animal = cat;
    animal.speak();
}
void test01(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}
void test02(){
    cout << "sizeof Animal  = " << sizeof(Animal) << endl;
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//分别利用普通写法和多态技术实现计算器
class Calculator{
public:
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1 + m_Num2;
        }
        else if(oper == "-"){
            return m_Num1 - m_Num2;
        }
        else if(oper == "*"){
            return m_Num1 * m_Num2;
        }
        else if(oper == "/"){
            return m_Num1 / m_Num2;
        }
        //如果想扩展新的功能，需修改源码
        //在真实开发中 提倡 开闭原则
        //开闭原则：对扩展进行开发，对修改进行关闭
    }
    int m_Num1;//操作数1
    int m_Num2;//操作数2
};
void test01(){
     Calculator c;
     c.m_Num1 = 10;
     c.m_Num2 = 10;
     cout << c.m_Num1 << "+" << c.m_Num2 << "= " << c.getResult("+") << endl;
     cout << c.m_Num1 << "-" << c.m_Num2 << "= " << c.getResult("-") << endl;
     cout << c.m_Num1 << "*" << c.m_Num2 << "= " << c.getResult("*") << endl;
     cout << c.m_Num1 << "/" << c.m_Num2 << "= " << c.getResult("/") << endl;
}
//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
//+
class AddCalculator :public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 + m_Num2;
    }
};//-
class SubCalculator :public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};
//*
class MulCalculator :public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 * m_Num2;
    }
};
void test02(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
    delete abc;
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
    delete abc;
}
//普通写法
int main(){
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;

//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator {
public:
    virtual int getResult() = 0;

    int m_Num1;
    int m_Num2;

};
//+
//class AddCalculator :public AbstractCalculator{
//public:
//    int getResult(){
//        return m_Num1 + m_Num2;
//    }
//};

//void test02(){
    //多态使用条件
    //父类指针或者引用指向子类对象
//    AbstractCalculator * abc = new AddCalculator;
//    abc->m_Num1 = 10;
//    abc->m_Num2 = 10;
//    cout << abc->getResult() << endl;
//    delete abc;
//    abc = new SubCalculator;
//    abc->m_Num1 = 10;
//    abc->m_Num2 = 10;
//    cout << abc->getResult() << endl;
//    delete abc;
//}
//普通写法
int main(){
    AbstractCalculator * abc = new AddCalculator;
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class AbstractDrinking{
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //制作饮品
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};
//制作咖啡
class Coffee :public AbstractDrinking{
public:
    //煮水
    virtual void Boil() {
        cout << "煮农夫山泉" << endl;
    }
    //冲泡
    virtual void Brew() {
        cout << "冲泡咖啡" << endl;
    }
    //倒入杯中
    virtual void PourInCup() {
        cout << "倒入杯中" << endl;
    }
    //加入辅料
    virtual void PutSomething() {
        cout << "加入糖和牛奶" << endl;
    }
};
//制作咖啡
class Tea :public AbstractDrinking{
public:
    //煮水
    virtual void Boil() {
        cout << "煮矿泉水" << endl;
    }
    //冲泡
    virtual void Brew() {
        cout << "冲泡茶叶" << endl;
    }
    //倒入杯中
    virtual void PourInCup() {
        cout << "倒入杯中" << endl;
    }
    //加入辅料
    virtual void PutSomething() {
        cout << "加入枸杞" << endl;
    }
};
void dowork(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs;
}
void test01(){
    //制作咖啡
    dowork(new Coffee);
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
class Animal{
public:
    Animal(){
        cout << "Animal构造函数调用" << endl;
    }
    //利用虚析构可以解决父类指针释放子类对象时不干净的问题
//    virtual ~Animal(){
//        cout << "Animal析构函数调用" << endl;
//    }
    //纯虚析构
    virtual ~Animal() = 0;
    virtual void speak() = 0;
};
Animal :: ~Animal() {
    cout << "Animal的纯虚析构函数" << endl;
}
class Cat:public Animal{
public:
    Cat(string name){
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){
        cout << *m_Name << "小猫在说话" << endl;
    }
    ~Cat(){
        if(m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};
void test01(){
    Animal * animal  = new Cat("Tom");
    animal->speak();
    delete animal;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//多态案例三思路
#if 0
#include <iostream>
using namespace std;
//抽象出每个零件的类
//class CPU{
//    virtual void calculate() = 0;
//};
//class VideoCard{
//    virtual void display() = 0;
//};
//class Memory{
//    virtual void storage() = 0;
//};
//class Computer{
//    构造函数中传入三个零件指针
//    提供工作的函数{
//        调用每个零件工作的接口
//    }
//};
//
//具体零件厂商
//Inter 厂商
//class IntelCpu :public CPU{
//    void calculate(){
//        cout << "Intel的CPU开始计算了！" << endl;
//    }
//};
//
//Lenovo厂商
//也需要提供三个零件
//
//测试阶段 组装三台不同的电脑

int main(){
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//抽象的CPU
class CPU{
public:
    //抽象的计算函数
    virtual void calculate() = 0;
};
//抽象的显卡类
class VideoCard{
public:
    //抽象的显示函数
    virtual void display() = 0;
};
//抽象的内存条
class Memory{
public:
    //抽象的计算函数
    virtual void storage() = 0;
};
//电脑类
class Computer{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_Cpu = cpu;
        m_VC = vc;
        m_Mem = mem;
    }
    //提供工作的函数
    void work(){
        //让零件工作起来，调用接口
        m_Cpu->calculate();
        m_VC->display();
        m_Mem->storage();
    }
    //提供析构函数 释放3个电脑零件
    ~Computer(){
        //释放cpu零件
        if(m_Cpu != NULL){
            delete m_Cpu;
            m_Cpu = NULL;
        }
        //释放显卡零件
        if(m_VC != NULL){
            delete m_VC;
            m_VC = NULL;
        }
        //释放内存条零件
        if(m_Mem != NULL){
            delete m_Mem;
            m_Mem = NULL;
        }
    }
private:
    CPU* m_Cpu;  //CPU零件指针
    VideoCard* m_VC;  //显卡零件指针
    Memory* m_Mem;   //内存条零件指针
};
//具体厂商
//Intel厂商
class IntelCpu :public CPU{
public:
    virtual void calculate(){
        cout << "Intel的CPU开始计算了" << endl;
    }
};
class IntelVCard :public VideoCard{
public:
    void display(){
        cout << "Intel的显卡开始显示了" << endl;
    }
};
class IntelMemory :public Memory{
public:
    void storage(){
        cout << "Intel的内存条开始存储了！" << endl;
    }
};
class LenovoCpu :public CPU{
public:
    void calculate(){
        cout << "Lenovo的CPU开始计算了" << endl;
    }
};
class LenovoCard :public VideoCard{
public:
    void display(){
        cout << "Lenovo的显卡开始显示了" << endl;
    }
};
class LenovoMemory :public Memory{
public:
    void storage(){
        cout << "Lenovo的内存条开始存储了！" << endl;
    }
};
void test01(){
    //第一台零件
    CPU * intelCpu = new IntelCpu;
    VideoCard * intelCard = new IntelVCard;
    Memory * intelMem = new IntelMemory;
    //创建第一台电脑
    cout << "---------------第一台电脑开始工作--------------" << endl;
    Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    //第二台电脑组装
    cout << "---------------第二台电脑开始工作--------------" << endl;
    Computer * computer2 = new Computer(new LenovoCpu, new LenovoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    //第三台电脑组装
    cout << "----------------第三台电脑开始工作--------------" << endl;
    Computer * computer3 = new Computer(new IntelCpu, new LenovoCard, new IntelMemory);
    computer3->work();
    delete computer3;
}

int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//文本文件 写文件
void test01(){
    //1. 包含头文件
    //2. 创建流对象
    ofstream ofs;
    //3. 指定打开方式
    ofs.open("test.txt", ios::out);
    //4. 写内容
    ofs << "姓名：张三" << endl;
    ofs << "姓别：男" << endl;
    ofs << "年龄：18" << endl;
    //5.关闭文件
    ofs.close();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void test01(){
    //1.包含文件
    //2.创建流对象
    ifstream ifs;
    //3.打开文件，并且判断是否打开成功
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    //第一种
//    char buf[1024] = {0};
//    while (ifs >> buf)
//    {
//        cout << buf << endl;
//    }
    //第二种
//    char buf[1024] = {0};
//    while (ifs.getline(buf, sizeof(buf))){
//        cout << buf << endl;
//    }
    //第三种
//    string buf;
//    while(getline(ifs,buf)){
//        cout << buf << endl;
//    }
    //第四种:不建议 速度慢
    char c;
    while ((c = ifs.get())!= EOF) { // EOF end of file
        cout << c;
    }
    //5.关闭文件
    ifs.close();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
#include <fstream>
//二进制文件 写文件
class Person{
public:
    char m_Name[64];
    int m_Age;
};
void test01(){
    //1.包含头文件
    //2.创建流对象
    ofstream ofs("person.txt", ios::out | ios::binary);
    //3.打开文件
    //可以在创建对象时就说明打开方式，如上
    //ofs.open("person.txt", ios::out | ios::binary);
    //4.写文件
    Person p = {"张三", 18};
    ofs.write((const char*)&p, sizeof (Person));
    //5.关闭文件
    ofs.close();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <fstream>
using namespace std;
class Person{
public:
    char m_Name[64];
    int m_Age;
};
//二进制文件 读文件
void test01(){
    //1.包含头文件
    //2.创建流对象
    ifstream ifs;
    //3.打开文件 判断文件是否打开成功
    ifs.open("person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读文件
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
    //5.关闭文件
    ifs.close();
}

int main(){
    test01();
    system("pause");
    return 0;
}
#endif
# if 0
#include <iostream>
using namespace std;
//函数模板
//两个整形交换函数
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//交互两个浮点型整数
void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}
//函数模板
template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test01(){
    int a = 10;
    int b = 20;
    //swapInt(a, b);
    //利用函数模板交换
    //两种方式
    //1.自动类型推导
    mySwap(a, b);
    //2.显示指定类型
    mySwap<int>(a, b);
    cout << "a: " << a << "  b: " << b << endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble(c, d);
    cout << "c = " << c << "  d = " << d  << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif