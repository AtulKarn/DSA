#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<char, int> p1, p2, p4;
    p1.first = 'a';
    p1.second = 65;
    cout<<p1.first<<endl;
    cout<<p1.second<<endl;
    p2 = make_pair('b', 66);
    cout<<p2.first<<" "<<p2.second<<endl;

    pair<int, string> p3;
    p3=make_pair(33, "hello");
    cout<<p3.first<<" "<<p3.second<<endl;
    cout<< ((p1==p2)?1:0) << endl;


    cout<<"p1: "<<p1.first<<" "<<p1.second<<endl;
    cout<<"p2: "<<p2.first<<" "<<p2.second<<endl;
    p1.swap(p2);
    cout<<"p1: "<<p1.first<<" "<<p1.second<<endl;
    cout<<"p2: "<<p2.first<<" "<<p2.second<<endl;

    int a;
    char b;
    p4 = make_pair('l', 12);
    tie(b,a)=p4;   //it is like unpacking
    cout<<"p4: "<<p4.first<<" "<<p4.second<<endl;

    cout<<"a: "<<a<<" "<<"b: "<<b<<endl;

    

    



}
