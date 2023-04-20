#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector�������������������
void myPrint(int val){
    cout << val << endl;
}
void test01(){
    //������һ��vector����������
    vector<int> v;
    //�������в�������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //ͨ�����������������е�����
    //vector<int>�����������µ�һ������������iterator
    vector<int>::iterator itBegin = v.begin();  //��ʼ������ ָ�������е�һ��Ԫ��
    vector<int>::iterator itEnd = v.end(); //���������� ָ�����������һ��Ԫ�ص���һ��λ��
    //��һ�ֱ�����ʽ
//    while (itBegin != itEnd){
//        cout << *itBegin << endl;
//        itBegin++;
//    }
    //�ڶ��ֱ�����ʽ
//    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
//        cout << *it << endl;
//    }
    //�����ֱ�����ʽ ����STL�ṩ�����㷨
    for_each(v.begin(), v.end(), myPrint);
}
int main(){
    test01();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//vector��������Զ�����������
class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
void test01(){
//����Զ�����������
    vector<Person>v;
    Person p1("cnda", 10);
    Person p2("sfre", 20);
    Person p3("kcei", 30);
    Person p4("afev", 40);
    Person p5("rfwr", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //����
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name: " << (*it).m_Name << "   age:" << (*it).m_Age << endl;
    }
}
void test02(){
//����Զ�����������  ָ��
    vector<Person*>v;
    Person p1("cnda", 10);
    Person p2("sfre", 20);
    Person p3("kcei", 30);
    Person p4("afev", 40);
    Person p5("rfwr", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //����
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name: " << (*it)->m_Name << "   age:" << (*it)->m_Age << endl;
    }
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
//����Ƕ������
void test01(){
    vector<vector<int>>v;

    //����С����
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    //��С�������������
    for(int i = 0; i < 4; i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //��С�������뵽��������
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //ͨ����������������������
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        //(*it) ---- ����vector<int>
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
    }
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//string �Ĺ��캯��
/*
string();                  //����һ���յ��ַ��� ���磺string str;
string(const char* s);     //ʹ���ַ���s��ʼ��
string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
string(int n; char c);     //ʹ��n���ַ�c��ʼ��
*/
void test01(){
    string s1; //Ĭ�Ϲ���
    const char* str = "hello world";
    string s2(str);

    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//string��ֵ����

void test01(){
    //string& operator=(const char* s);   //char*�����ַ��� ��ֵ����ǰ���ַ���
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;
    //string& operator=(const string &s);  //���ַ���s������ǰ�ַ���
    string str2;
    str2 = str1;
    //string& operator=(char c);       //���ַ�c��ֵ����ǰ���ַ���
    string str3;
    str3 = 'a';
    //string& assign=(const char* s);  //���ַ���s������ǰ�ַ���
    string str4;
    str4.assign("hello C++");
    //string& assign=(const char* s, int n);  //���ַ���s��ǰn���ַ�������ǰ�ַ���
    string str5;
    str5.assign("hello C++", 5);
    //string& assign=(const string &s);  //���ַ���s������ǰ�ַ���
    string str6;
    str6.assign(str5);
    //
    string str7;
    str7.assign(10, "r");
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
using namespace std;
//string �ַ���ȡ
void test01(){
    string str = "hello";
    //1. ͨ��[]���ʵ����ַ�
    for(int i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    }
    cout << endl;
    //2. ͨ��at��ʽ���ʵ����ַ�
    for(int i = 0; i < str.size(); i++){
        cout << str.at(i) << " ";
    }
    cout << endl;

    //�޸�
    str[0] = 'v';
    str.at(1) = 'j';

    cout << "str = " << str << endl;
}
void test02(){
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
}
void test03(){
    string email = "lbb@163.com";
    //�������л�ȡ�û���Ϣ
    int pos = email.find("@"); //3
    string userName = email.substr(0, pos);
    cout << "userName: " << userName << endl;
}
int main(){
    test03();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//1. vector<T> v;     //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
void test01(){
    vector<int>v1; //Ĭ�Ϲ��죬�޲ι���
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
//2. vector(v.begin(), v.end());     //��v[begin(), end()]�����е�Ԫ�ؿ���������
    vector<int>v2(v1.begin(), v1.end());
    printVector(v2);
//3. vector(n, elem);           //���캯����n��elem����������
    vector<int>v3(4, 100);
    printVector(v3);
//4. vector(const vector &vec);     //�������캯��
    vector<int>v4(v3);
    printVector(v4);
}

int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//vector��ֵ
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
    //��ֵ operator=
    vector<int>v2;
    v2 = v1;
    // assign
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);
    //n��elem ��ʽ��ֵ
    vector<int>v4;
    v4.assign(4,100);
    printVector(v4);
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//vector�����������ʹ�С����
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
    //Ϊ�� ��������Ϊ��
    if(v1.empty())
        cout << "v1Ϊ��" << endl;
    else{
        cout << "v1��Ϊ��" << endl;
        cout << "capacity: " << v1.capacity() << endl;
        cout << "size: " << v1.size() << endl;
    }
    //����ָ����С
    v1.resize(15);
    printVector(v1);
    v1.resize(14, 6);
    printVector(v1);
}
void test02(){
    vector<int>v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    cout << "swap ǰ��" << endl;
    printVector(v1);
    vector<int>v2;
    for(int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);
    cout << "swap ��" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//ʵ����;
//����swap���������ڴ�ռ�
void test03(){
    vector<int>v;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
    }
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ" << v.size() << endl;

    cout << " ����ָ����" << endl;
    v.resize(3);
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ" << v.size() << endl;

    //����swap�����ڴ�
    cout << "��swap�����ڴ��" << endl;
    vector<int>(v).swap(v);
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ" << v.size() << endl;
}
int main(){
    test03();
    return 0;
}
#endif
# if 0
#include <iostream>
#include <vector>
using namespace std;
//vector���� Ԥ���ռ�
void test01(){
    vector<int>v;
    int num = 0; //ͳ�ƿ��ٴ���
    int *p = NULL;
    //����reserveԤ���ռ�
    //v.reserve(100000);
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
        if(p!=&v[0]){
            p = &v[0];
            num++;
        }
    }
    cout << "num = " << num << endl;

}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int> &d){
    //ֻ��
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
         cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    deque<int>d1;
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(), d1.end());
    printDeque(d2);
    deque<int>d3(4, 100);
    printDeque(d3);
    deque<int>d4(d3);
    printDeque(d4);
}
int main(){
    test01();
    return 0;
}
#endif
//��Сд����
#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char c[101];
    int str;
    cin.get(c, 101);
    str = strlen(c);
    for(int i = 0; i < str; i++){
        if((c[i] >= 65) && (c[i] <= 90))
            c[i] += 32;
        else if((c[i] >= 97) && (c[i] <= 122))
            c[i] -= 32;
    }
    cout << c << endl;
    system("pause");
    return 0;
}
#endif
//2.С��Ϸ
#if 0
#include <iostream>
#include <deque>
using namespace std;

int main(){

    return 0;
}
#endif
//F. ��ת����
#if 0
#include <iostream>
using namespace std;
int main(){
    int n, r;
    cin >> n;
    while(n!=0){
        r = r*10+n%10;
        n/=10;
    }
    cout << r;
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main(){
    int n;
    int num;
    char m[17] = "0123456789ABCDEF";
    char k[101];
    cin >> n;
    if(n == 0)
        cout << 0;
    while (n != 0){
        k[++num] = m[num%16];
        n = n/16;
    }
    for(int i = num; i > 0; i--){
        cout << k[i];
    }
    return 0;
}#include<iostream>
using namespace std;
int main()
{
    int n;
    int num;
    char m[100]="0123456789ABCDEF";
    char k[100];
    cin >> n;
    if(n==0)
        cout << "0" << endl;
    while(n!=0)
    {
        k[++num]=m[n%16];
        n=n/16;
    }
    for(int i=num;i>0;i--)
        cout << k[i];
    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main(){
    int n;
    int a[101];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int min = a[0];
    for(int i = 0; i < 10; i++){
        if(a[i] < min)
            min = a[i];
    }
    int tag = 0;
    while (tag == 0){
        tag=1;
        for(int i = 0; i < n; i++){
            if(a[i]%min){
                tag = 0;
                min = a[i]%min;
            }
        }
    }
    cout << n*min << endl;
    return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
#include <deque>
void printDeque(const deque<int> &d){
    //ֻ��
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);
    //����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
    sort(d.begin(), d.end());
    cout << "sortĬ�ϴ�С����: " << endl;
    printDeque(d);
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;
class Person{
public:
    Person(string name, int score ){
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;
    int m_Score;
};
void creatPerson(vector<Person>&v){
    string nameSeed = "ABCDE";
    for(int i = 0; i < 5; i++){
        string name = "ѡ��";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        //��������Person���� ���뵽������
        v.push_back(p);
    }
}
void setScore(vector<Person>&v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        //����ί�ķ��� ���뵽deque������
        deque<int>d;
        for(int i = 0; i < 10; i++){
            int score = rand()%41 + 60;   //60 ~ 100�����
            d.push_back(score);
        }
        //���Դ��룬�鿴ÿ����ί��������
//        cout << it->m_Name << "�Ĵ�֣� " << endl;
//        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
//            cout << *dit << " ";
//        }
//        cout << endl;
        //����
        sort(d.begin(), d.end());
        //ȥ����߷ֺ���ͷ�
        d.pop_back();
        d.pop_front();
        //ȡƽ����
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit;  //�ۼ�ÿ����ί�ķ���
        }
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}
void showScore(vector<Person>&v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
        cout << "������" << it->m_Name << " ƽ���֣�" << it->m_Score << endl;
}
int main(){
    //���������  һ��Ҫ����main��
    srand((unsigned int)time(NULL));
    //1.����5��ѡ��
    vector<Person>v;  //���ѡ������
    creatPerson(v);
    //2.��5��ѡ�ִ��
    setScore(v);
    showScore(v);
    return 0;
}
#endif
#if 0
#include <iostream>
#include <list>
using namespace std;
void printList(const list<int>&l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){

    //����list����
    list<int>L1;   //Ĭ�Ϲ���
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //����
    printList(L1);
    //���䷽ʽ����
    list<int>L2(L1.begin(), L1.end());
    printList(L2);
    //��������
    list<int>L3(L2);
    printList(L3);
    //n��elem
    list<int>L4(4, 1000);
    printList(L4);
}
int main(){
    test01();
    return 0;
}
#endif
#if 0
#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){

    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);
}
int main(){
    return 0;
}
#endif
//G
#if 0
#include <iostream>
#include <string>
using namespace std;
const int N = 2e5+5;
int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    string s;
    while (m--){
        int op,l, r;
        cin >> op>>l>>r;
        if(op==0) {
            s[s.find('1')] = 0;
            s[s.find('0')] = 1;
        } else{
            for(int i =l;i <= r; i++){
                if(s[i] == '1') ans++;
            }
            cout <<ans << endl;
        }
    }
    return 0;
}
#endif
#if 0
#include <bits/stdc++.h>
#include <vector>
const int N = 1e5+5;
using namespace std;
int main(){
    int n, k, a[N];
    cin >> n >> k;
    int temp = 0, ans =0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int t = 1;
    for(int i = 1; i <= n-k+1; i++){
        temp = 0;
        int b[N] = {0};
        for(int j = 1; j <= k; j++){
            b[a[i+j-1]]++;
            if(b[a[i+j-1]]>1)
                t = 0;
            temp+=a[i+j-1];
        }
        int lengh = b / b[0];
        for(int i = 0; i < lengh; i++){
            cout << b[i] << endl;
        }
        if(t)
            ans = max(ans, temp);
    }
    cout<<ans;
    return 0;
}
#endif
#if 0
#include <iostream>
const int N = 1e5+5;
using namespace std;
int main(){
    int n, k, a[N];
    cin >> n >> k;
    int temp = 0, ans =0;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    int t = 1;
    for(int i = 0; i < n-k+1; i++){
        temp = 0;
        int b[N] = {0};
        for(int j = 0; j < k; j++)
            b[a[i+j]]++;
            if(b[a[i+j]] > 1) t = 0;
            temp += a[i+j];
    }
    memset(b, '\0', sizeof (b));
    if(t==1){
        if(ans < temp)
            ans = temp;
    }
    cout << ans;
}#include <bits/stdc++.h>
#include <vector>
const int N = 1e5+5;
using namespace std;
int main(){
    int n, k, a[N];
    cin >> n >> k;
    int temp = 0, ans =0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int b[N] = {0};
    int t = 1;
    for(int i = 1; i <= n-k+1; i++){
        temp = 0;
        for(int j = i; j <= k+i-1; j++){
            b[a[j]]++;
            if(b[a[j]]>1)
                t = 0;
            temp+=a[j];
        }
        memset(b, '\0', sizeof (b));
        if(t==1){
            if(ans < temp)
                ans = temp;
        }

    }
    cout<<ans;
    return 0;
}

#endif
#if 0
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    int a[1000005]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool mark[1000005]={0};
    int left = 1,right = 1,ans=0,temp=0;
    for(;right<=n;right++){
        if(mark[a[right]]==0&&right-left+1<=k){
            mark[right] = 1;
            temp+=a[right];
            if(right-left+1 == k)ans=max(ans,temp);
        }else{
            while(mark[a[right]]==1||right-left+1>k){
                temp-=a[left++];
            }
            temp+=a[right];
            mark[a[right]]=1;
            if(right-left+1 == k)ans=max(ans,temp);
        }
    }
    cout<<ans;

    return 0;
}
#endif
#if 0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[10000] = {0};
    int m, k, t;
    cin >> m >> k;
    t = 0;
    while(t <= n){
        a[t]++;
        t+=m;
    }
    t = n;
    while(t >= 0){
        a[t]++;
        t-=k;
    }
    int num = 0;
    for(int i = 0; i <= n; i++){
        if(a[i]>0)
            num++;
    }
    cout << num << endl;
    return 0;
}
#endif
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {

    int n;

    cin>>n;
    int arr[50];
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<endl;

    return 0;
}




