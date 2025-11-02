#include <bits/stdc++.h>
using namespace std;

int main(){
    // STL stands for Standard Template Library in C++
    // It provides commonly used data structures and algorithms.
    // Examples: vector, list, map, set, stack, queue, etc.

    // Example usage of vector (dynamic array)
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl; // Output: Vector elements: 1 2 3 4 5 

    // Example usage of set (unique sorted elements)
    set<int> s = {5, 3, 1, 4, 2};
    cout << "Set elements: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl; // Output: Set elements: 1 2 3 4 5 

    // Example usage of map (key-value pairs)
    map<string, int> m;
    m["apple"] = 2;
    m["banana"] = 5;
    cout << "Map elements:" << endl;
    for (auto p : m) {
        cout << p.first << ": " << p.second << endl;
        // Output: apple: 2
        //         banana: 5
    }
    // begins() and end() are member functions used to get iterators to the start and end of containers.

    // iterator
    vector<int> v2 = {1,2,3,4,5};
    vector<int>::iterator i = v2.begin();
    cout << "First element pointed by iterator: " << *i << endl; // Output: 1
    i++;
    cout << "Second element pointed by iterator: " << *i << endl; // Output: 2
    i = v2.end();          // it points towards the end so if we decrement it then it will point towards the last element
    i--;                   // last element
    cout << "Last element pointed by iterator: " << *i << endl; // Output: 5
    i = prev(i);           // points to previous element
    cout << "Second last element pointed by iterator: " << *i << endl; // Output: 4
    i = next(i);           // points to next element
    cout << "Back to last element pointed by iterator: " << *i << endl; // Output: 5

     // pairs are use to store two or more items of same or fiifernet types
    pair<int,int>p1={10,20};
    cout<<p1.first<<" "<<p1.second<<endl; //10  20
    pair<int,string>p2;
    p2=make_pair(10,"saikumar");
    cout<<p2.first<<" "<<p2.second;  //10 saikumar
    cout<<endl;

    //by using pointer we need to use this pointer method as dot not works in pointers!!
    pair<int, string> *pr= new pair<int, string>(10, "geeks");
    cout << pr->first << ": " << pr->second; //10 geeks

    pair<int, int> ps = make_pair(10, 'A');
    cout << ps.first << endl << ps.second;   // 10 65(asic value)
    return 0;
}