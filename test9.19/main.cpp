
//�������캯������ʱ��
//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//2.ֵ���ݵķ�ʽ������������ֵ
//9.20
#if 0
//1
#include <iostream>
using namespace std;
class Person{
public:
    Person(){
        cout << "Person��Ĭ�Ϲ��캯������" << endl;
    }
    Person(int age, int height){
        m_Age = age;
        m_Height = new int(height);
        cout << "Person���вι��캯������" << endl;
    }
    //�Լ�ʵ�ֿ������캯�� ���ǳ��������������
    Person(const Person &p){
        cout << "Person�������캯������" << endl;
        m_Age = p.m_Age;
        //m_Height = p.m_Height; //������Ĭ��ʵ�ֵĴ���
        //�������
        m_Height = new int(*p.m_Height);
    }
    ~Person(){
        //�������룬�����������������ͷŲ���
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;   //��ֹҰָ�����
        }
        cout << "Person��������������" << endl;
    }
    int m_Age;
    int *m_Height;
};
void test01(){
    Person p1(18, 160);
    cout << "p1������Ϊ��" << p1.m_Age << "���Ϊ��" << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2������Ϊ��" << p2.m_Age << "���Ϊ��" << *p2.m_Height << endl;
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
    //m_Phone(pName)�൱�� Phone m_Phone = pName ��ʽת����
    Person(string name,string pName):m_Name(name), m_Phone(pName){
        cout << "Person�Ĺ��캯������" << endl;
    }
    string m_Name;
    Phone m_Phone;
};
void test01(){
    Person p("����", "������MAX")
}
int main(){

}
#endif
#if 0
#include <iostream>
using namespace std;
class Person{
public:
    //1.���ж�����ͬһ������
    //2.�ڱ���׶η����ڴ�
    //3.���������������ʼ������
    static int m_A;
private:
    static int m_B; //������ʲ���
};
int Person::m_A =100;//�����ʼ��

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
//��̬��Ա����
//���ж�����һ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person{
public:
    static void func(){
        m_A = 100; //��̬��Ա�������Է��ʾ�̬��Ա����
        //���ǲ��ܷ��ʷǾ�̬��Ա����
        cout << "static void func����" << endl;
    }
    static int m_A;
    int m_B;   //�Ǿ�̬��Ա����
};
int Person::m_A = 0;
//�����ַ��ʷ�ʽ
void test01(){
    //1.ͨ���������
    Person p;
    p.func();
    //2.ͨ����������
    Person::func();
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
//��c++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ�����
#include <iostream>
using namespace std;
class Person{
    int m_A; // �Ǿ�̬��Ա���� ������Ķ�����
    static int m_B; //��̬��Ա���� �������������
    void func() {} //�Ǿ�̬��Ա���� ��������Ķ�����
    static void func2(){} //��̬��Ա���� ��������Ķ�����
};
void test01(){
    Person p; //���������ռ�����ڴ�
    cout << "size of p = " << sizeof(p) << endl; //��Ϊ�ն�����ռ��һ���ֽ�
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
        //thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
        this->age = age;
    }
    //���÷�ʽ(Person&)���أ�һֱ����p2������ֵ��ʽ(Person)���أ��ᴴ������һ���¶�����з���
    Person& PersonAaaAge(Person &p1){
        this->age += p1.age;
        //thisָ��p2��ָ�룬��*thisָ��p2�������ı���
        return this*;
    }
    int age;
};
//1.������Ƴ�ͻ
void test01(){
    Person p1(18);
    cout << p1.age << endl;
}
//2.���ض�������*this
void test02(){
    Person p1(10);
    Person p2(10);
    //��ʽ���˼�� coutҲ������˼��
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
//��ָ����ó�Ա����
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
//������
class Person{
public:
    //thisָ��ı��� ��ָ�볣�� ָ���ָ���ǲ������޸ĵ�
    //const Person * const this
    //�ڳ�Ա���������const�����ε���thisָ�룬��ָ��ָ���ֵҲ�������޸�
    void showPerson() const{
        //this->m_A = 100;  //��const���򲻿��޸ĳ�Ա����
        this->m_B = 100;
    }
    void func(){

    }
    int m_A;
    mutable int m_B; //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable
};
void test01(){
    Person p;
    p.showPerson();
}
//������
void test02(){
    const Person p; //����ǰ��const
    //p.m_A = 100; //�ڳ������в����޸�
    p.m_B = 100;    //m_B������ֵ���ڳ�������Ҳ�����޸�
    p.showPerson(); //���Ե��ó�����
    //p.func();   //���ɵ�����ͨ���� ��Ϊ��ͨ���������޸�����
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
    //goodGayȫ�ֺ�����Building�����ѣ����Է���building��˽�г�Ա
    friend void goodGay(Building *building);
public:
    Building(){
        m_BedRoom = "����";
        m_SittingRoom = "����";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//ȫ�ֺ���
void goodGay(Building *building){
    cout << "�û���ȫ�ֺ��� ���ڷ��� ��" << building->m_SittingRoom << endl;
    cout << "�û���ȫ�ֺ��� ���ڷ��� ��" << building->m_BedRoom << endl;

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
    void visit(); //�ιۺ��� ����Building�е�����
    Building * building;
};
class Building{
    //Goodfriend�Ǳ�������ѣ����Է��ʱ���˽�г�Ա
    friend class GoodFriend;
public:
    Building();
public:
    string m_SittingRoom; //����
private:
    string m_BedRoom;  //����
};
//����д��Ա����
Building::Building() {
    m_SittingRoom = "����";
    m_BedRoom = "����";
}
GoodFriend::GoodFriend(){
    //�������������
    building = new Building;
}
void GoodFriend::visit() {
    cout << "�����������ڷ��ʣ� " << building->m_SittingRoom << endl;
    cout << "�����������ڷ��ʣ� " << building->m_BedRoom << endl;
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
//��Ա��������Ԫ
#if 0
#include <iostream>
#include <string>
using namespace std;
class Building;
class Goodfriend{
public:
    Goodfriend();
    void visit();   //��visit�������Է���Building��˽�г�Ա
    void visit2();   //��visit2���������Է���Building��˽�г�Ա
    Building * building;
};
class Building{
    //���߱�������Goodfriend�еĳ�Ա����visit��Ϊfriend���Է���Building�е�˽�г�Ա
    friend void Goodfriend::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//����ʵ�ֳ�Ա����
Building::Building() {
    m_SittingRoom = "����";
    m_BedRoom = "����";
}
Goodfriend::Goodfriend() {
    building = new Building;
}
void Goodfriend::visit() {
    cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
}
void Goodfriend::visit2() {
    cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
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
//����+��
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
//�����������
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

//����  operator<<(cout, p)  �� cout << p
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
//���ص��������
#if 0
#include <iostream>
using namespace std;
class MyInteger{
    friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //����ǰ��++�����
    MyInteger& operator++(){
        m_Num++;
        return *this;
    }
    //���غ���++�����  int ����ռλ������������������ǰ�úͺ��õ���
    void operator++(int){
        //�� ��¼��ʱ���
        MyInteger temp = *this;
        //�� ����
        m_Num++;
        //��󽫼�¼���������
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
//��ֵ���������
class Person{
public:
    Person(int age){
        m_Age = new int(age); //new һ��int ����int* ��m_Age
    }
    ~Person(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
    //���� ��ֵ�����
    Person& operator=(Person &p){
        //���������ṩǳ����
        //m_Age = p.m_Age;
        //Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age); //���
        return *this;
    }
    int *m_Age;
};
void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;
    cout << "p1������Ϊ�� "<< *p1.m_Age << endl;
    cout << "p2������Ϊ�� "<< *p2.m_Age << endl;
    cout << "p3������Ϊ�� "<< *p2.m_Age << endl;
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
    //���� == ��
    bool operator == (Person &p){  //����!=
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
        cout << "p1��p2����ȵģ�" << endl;
    } else{
        cout << "p1��p2�ǲ���ȵģ�" << endl;
    }

}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
//�����������������
#if 0
#include <iostream>
using namespace std;
#include <string>
//�����������������
//��ӡ�����
class MyPrint{
public:
    //���غ������������
    void operator()(string test){
        cout << test << endl;
    }
};
void MyPrint02(string test){
    cout << test << endl;
}
void test01(){
    MyPrint myPrint;
    myPrint("hello world"); //����ʹ�������ǳ������ں������ã���˳�Ϊ�º���
    MyPrint02("hello world");
}
//�º����ǳ���û�й̶���д��
//�ӷ���
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
    //������������  ��ǰ��ִ�����������ͷ�
    cout << MyAdd()(100, 100) << endl;  //MyAdd()Ϊ������������
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
//��ͨʵ��ҳ��
//Javaҳ��
class Java{
public:
    void header(){
        cout << "��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����" << endl;
    }
    void footer(){
        cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
    }
    void left(){
        cout << "Java��Python��C++�����������������б�" << endl;
    }
    void content(){
        cout << "Javaѧ����Ƶ" << endl;
    }
};
class Python{
public:
    void header(){
        cout << "��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����" << endl;
    }
    void footer(){
        cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
    }
    void left(){
        cout << "Java��Python��C++�����������������б�" << endl;
    }
    void content(){
        cout << "Pythonѧ����Ƶ" << endl;
    }
};
class CPP{
public:
    void header(){
        cout << "��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����" << endl;
    }
    void footer(){
        cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
    }
    void left(){
        cout << "Java��Python��C++�����������������б�" << endl;
    }
    void content(){
        cout << "c++ѧ����Ƶ" << endl;
    }
};
void test01(){
    cout << "Java������Ƶҳ�����£�" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-----------------------"<< endl;
    cout << "Python������Ƶҳ�����£�" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-----------------------"<< endl;
    cout << "c++������Ƶҳ�����£�" << endl;
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
//�̳�ʵ��ҳ��
class BasePage{
public:
    void header(){
        cout << "��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����" << endl;
    }
    void footer(){
        cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
    }
    void left(){
        cout << "Java��Python��C++�����������������б�" << endl;
    }
};
//�̳еĺô��������ظ�����
//�﷨�� class ���ࣺ �̳з�ʽ ����
//���ࣨҲ��Ϊ�����ࣩ ���ࣨҲ��Ϊ���ࣩ
class Java: public BasePage{
public:
    void content(){
        cout << "Javaѧ����Ƶ" << endl;
    }
};
class CPP: public BasePage{
public:
    void content(){
        cout << "cppѧ����Ƶ" << endl;
    }
};
class Python: public BasePage{
public:
    void content(){
        cout << "pythonѧ����Ƶ" << endl;
    }
};
void test01(){
    cout << "Java������Ƶҳ�����£�" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-----------------------"<< endl;
    cout << "Python������Ƶҳ�����£�" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-----------------------"<< endl;
    cout << "c++������Ƶҳ�����£�" << endl;
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
//�̳��еĶ���ģ��
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
//�̳й�������˳��
#if 0
#include <iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base�Ĺ��캯����" << endl;
    }
    ~Base(){
        cout << "Base������������" << endl;
    }
};
class Son : public Base{
public:
    Son(){
        cout << "Son���캯����" << endl;
    }
    ~Son(){
        cout << "Son����������" << endl;
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
//�̳���ͬ����Ա����ʽ
class Base{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout << "Base �� func() ����" << endl;
    }
    void func(int a){
        cout << "Base �� func(int) ����" << endl;
    }
    int m_A;
};
class Son: public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout << "Son �� func() ����" << endl;
    }
    int m_A;
};
//ͬ����Ա���Դ���
void test01(){
    Son s;
    cout << "Son  �� m_A = " << s.m_A << endl;
    //���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
    cout << "Base �� m_A = " << s.Base::m_A << endl;
}
//ͬ����Ա��������
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
    //�����μ̳У���������ӵ����ͬ���ݣ���Ҫ��������������
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
//����const���⣬������һ������
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
//��̬
#if 0
#include <iostream>
using namespace std;
//��̬
class Animal{
public:
    //�麯��
    void virtual speak(){
        cout << "������˵��" << endl;
    }
};
class Cat :public Animal{
public:
    void speak(){
        cout << "Сè��˵��" << endl;
    }
};
class Dog :public Animal{
public:
    void speak(){
        cout << "С����˵��" << endl;
    }
};
//ִ��˵���ĺ���
//��ַ��� �ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а�
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
//�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
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
        //�������չ�µĹ��ܣ����޸�Դ��
        //����ʵ������ �ᳫ ����ԭ��
        //����ԭ�򣺶���չ���п��������޸Ľ��йر�
    }
    int m_Num1;//������1
    int m_Num2;//������2
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
//���ö�̬ʵ�ּ�����
//ʵ�ּ�����������
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
    //��̬ʹ������
    //����ָ���������ָ���������
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
//��ͨд��
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

//���ö�̬ʵ�ּ�����
//ʵ�ּ�����������
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
    //��̬ʹ������
    //����ָ���������ָ���������
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
//��ͨд��
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
    //��ˮ
    virtual void Boil() = 0;
    //����
    virtual void Brew() = 0;
    //���뱭��
    virtual void PourInCup() = 0;
    //���븨��
    virtual void PutSomething() = 0;
    //������Ʒ
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};
//��������
class Coffee :public AbstractDrinking{
public:
    //��ˮ
    virtual void Boil() {
        cout << "��ũ��ɽȪ" << endl;
    }
    //����
    virtual void Brew() {
        cout << "���ݿ���" << endl;
    }
    //���뱭��
    virtual void PourInCup() {
        cout << "���뱭��" << endl;
    }
    //���븨��
    virtual void PutSomething() {
        cout << "�����Ǻ�ţ��" << endl;
    }
};
//��������
class Tea :public AbstractDrinking{
public:
    //��ˮ
    virtual void Boil() {
        cout << "���Ȫˮ" << endl;
    }
    //����
    virtual void Brew() {
        cout << "���ݲ�Ҷ" << endl;
    }
    //���뱭��
    virtual void PourInCup() {
        cout << "���뱭��" << endl;
    }
    //���븨��
    virtual void PutSomething() {
        cout << "�������" << endl;
    }
};
void dowork(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs;
}
void test01(){
    //��������
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
        cout << "Animal���캯������" << endl;
    }
    //�������������Խ������ָ���ͷ��������ʱ���ɾ�������
//    virtual ~Animal(){
//        cout << "Animal������������" << endl;
//    }
    //��������
    virtual ~Animal() = 0;
    virtual void speak() = 0;
};
Animal :: ~Animal() {
    cout << "Animal�Ĵ�����������" << endl;
}
class Cat:public Animal{
public:
    Cat(string name){
        cout << "Cat���캯������" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){
        cout << *m_Name << "Сè��˵��" << endl;
    }
    ~Cat(){
        if(m_Name != NULL)
        {
            cout << "Cat������������" << endl;
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
//��̬������˼·
#if 0
#include <iostream>
using namespace std;
//�����ÿ���������
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
//    ���캯���д����������ָ��
//    �ṩ�����ĺ���{
//        ����ÿ����������Ľӿ�
//    }
//};
//
//�����������
//Inter ����
//class IntelCpu :public CPU{
//    void calculate(){
//        cout << "Intel��CPU��ʼ�����ˣ�" << endl;
//    }
//};
//
//Lenovo����
//Ҳ��Ҫ�ṩ�������
//
//���Խ׶� ��װ��̨��ͬ�ĵ���

int main(){
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//�����CPU
class CPU{
public:
    //����ļ��㺯��
    virtual void calculate() = 0;
};
//������Կ���
class VideoCard{
public:
    //�������ʾ����
    virtual void display() = 0;
};
//������ڴ���
class Memory{
public:
    //����ļ��㺯��
    virtual void storage() = 0;
};
//������
class Computer{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_Cpu = cpu;
        m_VC = vc;
        m_Mem = mem;
    }
    //�ṩ�����ĺ���
    void work(){
        //������������������ýӿ�
        m_Cpu->calculate();
        m_VC->display();
        m_Mem->storage();
    }
    //�ṩ�������� �ͷ�3���������
    ~Computer(){
        //�ͷ�cpu���
        if(m_Cpu != NULL){
            delete m_Cpu;
            m_Cpu = NULL;
        }
        //�ͷ��Կ����
        if(m_VC != NULL){
            delete m_VC;
            m_VC = NULL;
        }
        //�ͷ��ڴ������
        if(m_Mem != NULL){
            delete m_Mem;
            m_Mem = NULL;
        }
    }
private:
    CPU* m_Cpu;  //CPU���ָ��
    VideoCard* m_VC;  //�Կ����ָ��
    Memory* m_Mem;   //�ڴ������ָ��
};
//���峧��
//Intel����
class IntelCpu :public CPU{
public:
    virtual void calculate(){
        cout << "Intel��CPU��ʼ������" << endl;
    }
};
class IntelVCard :public VideoCard{
public:
    void display(){
        cout << "Intel���Կ���ʼ��ʾ��" << endl;
    }
};
class IntelMemory :public Memory{
public:
    void storage(){
        cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
    }
};
class LenovoCpu :public CPU{
public:
    void calculate(){
        cout << "Lenovo��CPU��ʼ������" << endl;
    }
};
class LenovoCard :public VideoCard{
public:
    void display(){
        cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
    }
};
class LenovoMemory :public Memory{
public:
    void storage(){
        cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
    }
};
void test01(){
    //��һ̨���
    CPU * intelCpu = new IntelCpu;
    VideoCard * intelCard = new IntelVCard;
    Memory * intelMem = new IntelMemory;
    //������һ̨����
    cout << "---------------��һ̨���Կ�ʼ����--------------" << endl;
    Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    //�ڶ�̨������װ
    cout << "---------------�ڶ�̨���Կ�ʼ����--------------" << endl;
    Computer * computer2 = new Computer(new LenovoCpu, new LenovoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    //����̨������װ
    cout << "----------------����̨���Կ�ʼ����--------------" << endl;
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
//�ı��ļ� д�ļ�
void test01(){
    //1. ����ͷ�ļ�
    //2. ����������
    ofstream ofs;
    //3. ָ���򿪷�ʽ
    ofs.open("test.txt", ios::out);
    //4. д����
    ofs << "����������" << endl;
    ofs << "�ձ���" << endl;
    ofs << "���䣺18" << endl;
    //5.�ر��ļ�
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
    //1.�����ļ�
    //2.����������
    ifstream ifs;
    //3.���ļ��������ж��Ƿ�򿪳ɹ�
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    //��һ��
//    char buf[1024] = {0};
//    while (ifs >> buf)
//    {
//        cout << buf << endl;
//    }
    //�ڶ���
//    char buf[1024] = {0};
//    while (ifs.getline(buf, sizeof(buf))){
//        cout << buf << endl;
//    }
    //������
//    string buf;
//    while(getline(ifs,buf)){
//        cout << buf << endl;
//    }
    //������:������ �ٶ���
    char c;
    while ((c = ifs.get())!= EOF) { // EOF end of file
        cout << c;
    }
    //5.�ر��ļ�
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
//�������ļ� д�ļ�
class Person{
public:
    char m_Name[64];
    int m_Age;
};
void test01(){
    //1.����ͷ�ļ�
    //2.����������
    ofstream ofs("person.txt", ios::out | ios::binary);
    //3.���ļ�
    //�����ڴ�������ʱ��˵���򿪷�ʽ������
    //ofs.open("person.txt", ios::out | ios::binary);
    //4.д�ļ�
    Person p = {"����", 18};
    ofs.write((const char*)&p, sizeof (Person));
    //5.�ر��ļ�
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
//�������ļ� ���ļ�
void test01(){
    //1.����ͷ�ļ�
    //2.����������
    ifstream ifs;
    //3.���ļ� �ж��ļ��Ƿ�򿪳ɹ�
    ifs.open("person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.���ļ�
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "����: " << p.m_Name << " ����: " << p.m_Age << endl;
    //5.�ر��ļ�
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
//����ģ��
//�������ν�������
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//������������������
void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}
//����ģ��
template<typename T>//����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test01(){
    int a = 10;
    int b = 20;
    //swapInt(a, b);
    //���ú���ģ�彻��
    //���ַ�ʽ
    //1.�Զ������Ƶ�
    mySwap(a, b);
    //2.��ʾָ������
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