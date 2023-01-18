#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 10;

class MyGreater
{
public:
    bool operator()(int v1, int v2)const
    {
        return v1 > v2;
    }

};

void printSetInt(set<int, MyGreater>& s)
{
    set<int, MyGreater>::const_iterator it = s.begin();
    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void printSetInt(set<int>& s)
{
    set<int>::const_iterator it = s.begin();
    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void t1()
{
    set<int, MyGreater>s1;
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    printSetInt(s1);

}

class MyGreaterPerson;
class Person
{
    friend class MyGreaterPerson;
    friend void printSetPerson(set<Person, MyGreaterPerson>& s);
public:
    Person(){}
    Person(int num, string name, double score)
    {
        this->num = num;
        this->name = name;
        this->score = score;
    }

private:
    int num;
    string name;
    double score;
};
class MyGreaterPerson
{
public:
    bool operator()(Person ob1, Person ob2)const
    {
        return ob1.num < ob2.num;
    }

};
void printSetPerson(set<Person, MyGreaterPerson>& s)
{
    set<Person, MyGreaterPerson>::const_iterator it = s.begin();
    for (; it != s.end(); it++) {
        cout << (*it).num << " " << (*it).name << " " << (*it).score << endl;
    }
}
void t2()
{
    set<Person,MyGreaterPerson>s;
    s.insert(Person(100, "lucy", 88.8));
    s.insert(Person(103, "tom", 88.8));
    s.insert(Person(105, "bob", 88.8));
    s.insert(Person(104, "dema", 88.8));
    s.insert(Person(102, "xafa", 88.8));

    printSetPerson(s);
}

void t3()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    s1.insert(70);
    s1.insert(90);

    printSetInt(s1);

    set<int>::const_iterator ret;
    ret = s1.find(50);
    if (ret != s1.end()) {
        cout << "找到的结果为：" << *ret << endl;
    }

    cout << s1.count(50) << endl;
}

void t4()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    s1.insert(70);
    s1.insert(90);

    set<int>::const_iterator ret;
    ret = s1.lower_bound(50);
    if (ret != s1.end()) {
        cout << "下限为：" << *ret << endl;
    }
    ret = s1.upper_bound(50);
    if (ret != s1.end()) {
        cout << "上限为：" << *ret << endl;
    }

    //以对组的方式存储上下限 pair
    pair<set<int>::const_iterator, set<int>::const_iterator>pa;
    pa = s1.equal_range(50);
    if (pa.first != s1.end()) {
        cout << "下限为：" << *(pa.first) << endl;
    }
    if (pa.second != s1.end()) {
        cout << "上限为：" << *(pa.second) << endl;
    }
}

void t5()
{
    multiset<int>s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(10);
    s1.insert(70);
    s1.insert(10);

    multiset<int>::const_iterator it = s1.begin();
    for (; it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void t6()
{
    //方式一：
    pair<int, string>p1(10086, "移动");
    pair<int, string>p2(10010, "联通");
    pair<int, string>p3(10000, "典型");

    //方式二：
    pair<int, string>p4 = make_pair(9527, "星爷");
    cout << p4.first << " " << p4.second << endl;
}
int main()
{
    //t1();
    //t2();
    //t3();
    //t4();
    //t5();
    t6();
    return 0;
}