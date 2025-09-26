#include <bits/stdc++.h>
using namespace std;

int main(){
    // pairs are use to store two or more items of same or fiifernet types
    pair<int,int>p1={10,20};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,string>p2;
    p2=make_pair(10,"saikumar");
    cout<<p2.first<<" "<<p2.second;
    cout<<endl;

    //by jusing pointer we need to use this pointer method as dot not works in pointers!!
    pair<int, string> *pr= new pair<int, string>(10, "geeks");
    cout << pr->first << ": " << pr->second;

    pair<int, int> ps = make_pair(10, 'A');
    cout << ps.first << endl << ps.second;
    return 0;
}