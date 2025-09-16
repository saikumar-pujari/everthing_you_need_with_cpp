#include <bits/stdc++.h>
using namespace std;
void f(int &s){
    s+=10;
}
int main(){
    int x=10;
    int *p=&x;
    int &m=*p;
    cout<<*p;
    cout << "\n";
    cout<<m;
    int s=50;
    f(s);
    cout<<s<<endl;
    return 0;
}