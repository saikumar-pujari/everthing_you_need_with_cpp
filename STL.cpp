#include <bits/stdc++.h>
using namespace std;

int main(){
    // STL stands for Standard Template Library in C++
    // It provides commonly used data structures and algorithms.
    // Examples: vector, list, map, set, stack, queue, etc.

    // Example usage of vector (dynamic array)
    // vector<int> v = {1, 2, 3, 4, 5};
    // for (int x : v) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // Example usage of set (unique sorted elements)
    // set<int> s = {5, 3, 1, 4, 2};
    // for (int x : s) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // Example usage of map (key-value pairs)
    // map<string, int> m;
    // m["apple"] = 2;
    // m["banana"] = 5;
    // for (auto p : m) {
    //     cout << p.first << ": " << p.second << endl;
    // }
    // begins() and end() are member functions used to get iterators to the start and end of containers.

    // iterator
    // vector<int>v={1,2,3,4,5};
    // vector<int>::iterator i=v.begin();
    // cout<<*i<<endl;
    // i++;
    // cout<<*i<<endl;
    // i=v.end();          //it points towards the end so if we decrement it then it will point towards the lst element
    // i--;                //last element
    // cout<<*i<<endl;
    // i=prev(i);          //points to prev elemenet and also be use as (next(i,2) moves 2)
    // cout<<*i<<endl;
    // i=next(i);          //points to next element
    // cout<<*i<<endl;

    return 0;
}