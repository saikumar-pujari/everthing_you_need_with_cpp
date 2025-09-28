#include <bits/stdc++.h>
using namespace std;
struct student{
    string fname, lname;
};
// Josephus problem implementation
int josephus(int n, int k) {
    list<int> people;
    for(int i = 0; i < n; i++) people.push_back(i);
    auto it = people.begin();
    while(people.size() > 1) {
        for(int step = 0; step < k; step++) {
            it++;
            if(it == people.end()) it = people.begin();
        }
        cout << *it << endl;
        it = people.erase(it);
        if(it == people.end()) it = people.begin();
    }
    return *people.begin();
}


list<int>l;
void insert(int x) { l.push_back(x); }
void display(){
    for(int num:l)cout<<num<<" ";
}
void replace(int x, vector<int>& seq) {
    auto it = find(l.begin(), l.end(), x);
    if (it == l.end()) return;
    it = l.erase(it);
    l.insert(it, seq.begin(), seq.end());
}
class A
{
  public:
    int x, y;
    A(int a, int b) : x(a), y(b)
    {
    }
};
int main(){
    
    // vector is not size oriented(dynamic size)(rich libraray)
    // no need to pass size in a vector unlike array as array is treated as pointer in normal func
//     vector<int>v;
//     v.push_back(10);
//     v.push_back(30);
//     v.push_back(20);
//     for(auto& num:v){
//         cout<<num<<" ";
//     }
// // v.at(i)   checks the array index check

// // 1. pop_back: removes last element
// v.pop_back();
// cout << "\nAfter pop_back: ";
// for(auto& num : v) cout << num << " ";

// // 2. front: access first element
// cout << "\nFront element: " << v.front();

// // 3. back: access last element
// cout << "\nBack element: " << v.back();

// // 4. insert: insert element at position 1
// v.insert(v.begin() + 1, 25);
// cout << "\nAfter insert at position 1: ";
// for(auto& num : v) cout << num << " ";

// // 5. erase: erase element at position 0
// v.erase(v.begin());
// cout << "\nAfter erase at position 0: ";
// for(auto& num : v) cout << num << " ";

// // 6. clear: remove all elements
// v.clear();
// cout << "\nAfter clear, size: " << v.size();

// // 7. resize: change vector size to 5, fill with 0
// v.resize(5, 0);
// cout << "\nAfter resize to 5: ";
// for(auto& num : v) cout << num << " ";

// vector<student> students;
// student s1, s2;
// s1.fname = "John";
// s1.lname = "Doe";
// s2.fname = "Jane";
// s2.lname = "Smith";
// students.push_back(s1);
// students.push_back(s2);
// for (const student &s : students) {
//     cout << "First Name: " << s.fname << ", Last Name: " << s.lname << endl;
// }

// capacity vs size
    // vector<int> v;
    // cout << "\nInitially: size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // cout << "After adding 3 elements: size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // v.reserve(10);
    // cout << "After reserve(10): size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // v.resize(8);
    // cout << "After resize(8): size = " << v.size() << ", capacity = " << v.capacity() << endl;





// list is a doubely linked list and forward list is singly linked list
// we will be doing the forwatd linked list
// we can add or reove from front only


// forward_list<int>list={10,20,30};
// list.push_front(40);
// list.push_front(50);
// // list.push_back(70);
// for(int n:list)cout<<n<<" ";
// cout<<endl;
// list.pop_front();
// // list.pop_back();             //only front is allowed as its a singled list
// for(int n:list)cout<<n<<" ";

// forward_list<int>l;
// l.assign({10, 20, 30, 10}); // Correct usage with initializer_list
// cout<<endl;
// for(int n:l)cout<<n<<" ";
// cout<<endl;
// l.remove(10);
// for(int n:l)cout<<n<<" ";

// // insert_after: insert 99 after first element
// auto it = l.begin();
// l.insert_after(it, 99);
// cout << "\nAfter insert_after: ";
// for(int n:l)cout<<n<<" ";

// // emplace_after: emplace 77 after first element
// l.emplace_after(l.begin(), 77);
// cout << "\nAfter emplace_after: ";
// for(int n:l)cout<<n<<" ";

// // erase_after: erase element after first
// l.erase_after(l.begin());
// cout << "\nAfter erase_after: ";
// for(int n:l)cout<<n<<" ";

// // clear: remove all elements
// l.clear();
// cout << "\nAfter clear, empty: " << l.empty();

// // reverse: reverse the list
// l.assign({1, 2, 3, 4});
// // l.reverse();
// // l.reverse(l.begin(),l.end());
// cout << "\nAfter reverse: ";
// for(int n:l)cout<<n<<" ";

// // sort: sort the list
// l.assign({4, 2, 3, 1});
// l.sort();
// cout << "\nAfter sort: ";
// for(int n:l)cout<<n<<" ";

// // merge: merge two sorted lists
// forward_list<int> l1 = {1, 3, 5};
// forward_list<int> l2 = {2, 4, 6};
// l1.merge(l2); // l2 becomes empty
// cout << "\nAfter merge: ";
// for(int n:l1)cout<<n<<" ";



////////////////////////////////list--------------------------------------------

// list is for both double linked list that means we can even add or remove from front or back

// list<int>l;
// l.push_front(10);
// l.push_back(20);
// for(int n:l)cout<<n<<" ";
// l.pop_front();
// l.pop_back();
// for(int n:l)cout<<n<<" ";

// list<int>l1={10,20,30,40,20,40};
// auto it=l1.begin();
// it=l1.erase(it);
// l1.remove(40);
// for(int n:l1)cout<<n<<" ";

// // unique function: removes consecutive duplicates
// l1.push_back(20);
// l1.push_back(20);
// l1.push_back(30);
// l1.unique();
// cout << "\nAfter unique: ";
// for(int n:l1)cout<<n<<" ";

// // reverse function: reverses the list
// l1.reverse();
// cout << "\nAfter reverse: ";
// for(int n:l1)cout<<n<<" ";

// // sort function: sorts the list
// l1.sort();
// cout << "\nAfter sort: ";
// for(int n:l1)cout<<n<<" ";


// // Example usage of Josephus problem------------------------------------------------


//     int n = 7, k = 2;
//     cout << "\nJosephus survivor: " << josephus(n, k) << endl;



    // insert(1);
    // insert(2);
    // insert(3);
    // insert(4);
    // insert(5);
    // display();
    // cout << "\n";
    // vector<int>ls={6,7,8,9,10};
    // replace(5,ls);
    // display();

// Example: To remove elements after a specific position in forward_list, use erase_after.
// forward_list<int> fl = {1, 2, 3, 4, 5};
// auto it = fl.begin(); // points to 1
// advance(it, 2); // move iterator to 3
// fl.erase_after(it); // removes 4 (element after 3)
// for(int n : fl) cout << n << " "; // Output: 1 2 3 5


// forward_list<int>ls;
// ls.assign({1, 2, 3, 4});
// ls.reverse();
// // l.reverse(l.begin(),l.end());
// cout << "\nAfter reverse: ";
// for(int n:ls)cout<<n<<" ";

//   forward_list<A> fl = {{1, 2}};
//     fl.insert_after(fl.begin(), {3, 4});
//     auto it = ++fl.begin();
//     cout << it->x << " " << it->y;

vector<int>ls;
ls.push_back(10);
cout<<ls[0];

return 0;
}