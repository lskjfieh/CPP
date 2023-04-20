#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector容器存放内置数据类型
void myPrint(int val){
    cout << val << endl;
}
void test01(){
    //创建了一个vector容器，数组
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器访问容器中的数据
    //vector<int>类型作用域下的一个迭代器名称iterator
    vector<int>::iterator itBegin = v.begin();  //起始迭代器 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end(); //结束迭代器 指向容器中最后一个元素的下一个位置
    //第一种遍历方式
//    while (itBegin != itEnd){
//        cout << *itBegin << endl;
//        itBegin++;
//    }
    //第二种遍历方式
//    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
//        cout << *it << endl;
//    }
    //第三种遍历方式 利用STL提供遍历算法
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
//vector容器存放自定义数据类型
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
//存放自定义数据类型
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
    //遍历
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name: " << (*it).m_Name << "   age:" << (*it).m_Age << endl;
    }
}
void test02(){
//存放自定义数据类型  指针
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
    //遍历
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
//容器嵌套容器
void test01(){
    vector<vector<int>>v;

    //创建小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    //向小容器中添加数据
    for(int i = 0; i < 4; i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //通过大容器，遍历所有数据
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        //(*it) ---- 容器vector<int>
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
//string 的构造函数
/*
string();                  //创建一个空的字符串 例如：string str;
string(const char* s);     //使用字符串s初始化
string(const string& str); //使用一个string对象初始化另一个string对象
string(int n; char c);     //使用n个字符c初始化
*/
void test01(){
    string s1; //默认构造
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
//string赋值操作

void test01(){
    //string& operator=(const char* s);   //char*类型字符串 赋值给当前的字符串
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;
    //string& operator=(const string &s);  //把字符串s赋给当前字符串
    string str2;
    str2 = str1;
    //string& operator=(char c);       //把字符c赋值给当前的字符串
    string str3;
    str3 = 'a';
    //string& assign=(const char* s);  //把字符串s赋给当前字符串
    string str4;
    str4.assign("hello C++");
    //string& assign=(const char* s, int n);  //把字符串s的前n个字符赋给当前字符串
    string str5;
    str5.assign("hello C++", 5);
    //string& assign=(const string &s);  //把字符串s赋给当前字符串
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
//string 字符存取
void test01(){
    string str = "hello";
    //1. 通过[]访问单个字符
    for(int i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    }
    cout << endl;
    //2. 通过at方式访问单个字符
    for(int i = 0; i < str.size(); i++){
        cout << str.at(i) << " ";
    }
    cout << endl;

    //修改
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
    //从邮箱中获取用户信息
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
//1. vector<T> v;     //采用模板实现类实现，默认构造函数
void test01(){
    vector<int>v1; //默认构造，无参构造
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
//2. vector(v.begin(), v.end());     //将v[begin(), end()]区间中的元素拷贝给本身
    vector<int>v2(v1.begin(), v1.end());
    printVector(v2);
//3. vector(n, elem);           //构造函数将n个elem拷贝给本身。
    vector<int>v3(4, 100);
    printVector(v3);
//4. vector(const vector &vec);     //拷贝构造函数
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
//vector赋值
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
    //赋值 operator=
    vector<int>v2;
    v2 = v1;
    // assign
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);
    //n个elem 方式赋值
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
//vector容器的容量和大小操作
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);
    //为真 代表容器为空
    if(v1.empty())
        cout << "v1为空" << endl;
    else{
        cout << "v1不为空" << endl;
        cout << "capacity: " << v1.capacity() << endl;
        cout << "size: " << v1.size() << endl;
    }
    //重新指定大小
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
    cout << "swap 前：" << endl;
    printVector(v1);
    vector<int>v2;
    for(int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);
    cout << "swap 后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//实际用途
//巧用swap可以收缩内存空间
void test03(){
    vector<int>v;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为" << v.size() << endl;

    cout << " 重新指定后" << endl;
    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为" << v.size() << endl;

    //巧用swap收缩内存
    cout << "用swap收缩内存后：" << endl;
    vector<int>(v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为" << v.size() << endl;
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
//vector容器 预留空间
void test01(){
    vector<int>v;
    int num = 0; //统计开辟次数
    int *p = NULL;
    //利用reserve预留空间
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
    //只读
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
//大小写互换
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
//2.小游戏
#if 0
#include <iostream>
#include <deque>
using namespace std;

int main(){

    return 0;
}
#endif
//F. 反转数字
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
    //只读
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
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序。
    sort(d.begin(), d.end());
    cout << "sort默认从小到大: " << endl;
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
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        //将创建的Person对象 放入到容器中
        v.push_back(p);
    }
}
void setScore(vector<Person>&v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        //将评委的分数 放入到deque容器中
        deque<int>d;
        for(int i = 0; i < 10; i++){
            int score = rand()%41 + 60;   //60 ~ 100随机数
            d.push_back(score);
        }
        //测试代码，查看每个评委所给评分
//        cout << it->m_Name << "的打分： " << endl;
//        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
//            cout << *dit << " ";
//        }
//        cout << endl;
        //排序
        sort(d.begin(), d.end());
        //去除最高分和最低分
        d.pop_back();
        d.pop_front();
        //取平均分
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit;  //累加每个评委的分数
        }
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}
void showScore(vector<Person>&v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
        cout << "姓名：" << it->m_Name << " 平均分：" << it->m_Score << endl;
}
int main(){
    //随机数种子  一定要加在main里
    srand((unsigned int)time(NULL));
    //1.创建5名选手
    vector<Person>v;  //存放选手容器
    creatPerson(v);
    //2.给5名选手打分
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

    //创建list容器
    list<int>L1;   //默认构造
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //遍历
    printList(L1);
    //区间方式构造
    list<int>L2(L1.begin(), L1.end());
    printList(L2);
    //拷贝构造
    list<int>L3(L2);
    printList(L3);
    //n个elem
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




