#include <bits/stdc++.h>
using namespace std;

int main(){
    // STL stands for Standard Template Library in C++
    // It provides commonly used data structures and algorithms.
    // Examples: vector, list, map, set, stack, queue, etc.

    //stl is mainly divided into 4 pillars
    //containers, algorithms,iterators,functors



    //iterators are used to point towards the memory location of containers like vector,set,map etc.,eg: begin(),end(),next(),prev() or dereference operator(*it)

    //functors are objects that can be treated as functions or function pointers.eg: greater<int>(priority_min),less<int>(priority_max) etc.,

    //algorithms are used to perform operations on data structures like sorting, searching, etc.,eg: sort(),binary_search(),reverse(),max_element(),min_element() etc.,

    //containers are used to store data.eg: vector,list,set,map,stack,queue etc.,
    //|____there are 4 types of containers: sequence containers(vector,deque,list,forward_list,array), associative containers(set,map), unordered associative containers(unordered_set,unordered_map), and container adapters(stack,queue,priority_queue).

    // Container vs Adaptor Comparison:----->container not equal to adaptor
    // ┌─────────────┬────────────────────────────┬──────────────────┬──────────────────────────────┐
    // │ Type        │ Access                     │ Can Iterate?     │ Example Functions            │
    // ├─────────────┼────────────────────────────┼──────────────────┼──────────────────────────────┤
    // │ Container   │ Full (direct & elements)   │ ✅ Yes           │ begin(), end(), find(),      │
    // │             │                            │                  │ erase(), insert()            │
    // ├─────────────┼────────────────────────────┼──────────────────┼──────────────────────────────┤
    // │ Adaptor     │ Restricted (top/front/back)│ ❌ No            │ push(), pop(), top(),        │
    // │             │                            │                  │ front(), back()              │
    // └─────────────┴────────────────────────────┴──────────────────┴──────────────────────────────┘

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