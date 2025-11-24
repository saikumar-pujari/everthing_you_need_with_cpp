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
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    for(auto& num:v){
        cout<<num<<" "; // Expected output: 10 30 20 
    }
// // v.at(i)   checks the array index check

// 1. pop_back: removes last element
v.pop_back();
cout << "\nAfter pop_back: "; // Expected output: After pop_back: 10 30 
for(auto& num : v) cout << num << " "; // Expected output: 10 30 

// 2. front: access first element
cout << "\nFront element: " << v.front(); // Expected output: Front element: 10

// 3. back: access last element
cout << "\nBack element: " << v.back(); // Expected output: Back element: 30

// 4. insert: insert element at position 1
v.insert(v.begin() + 1, 25);
cout << "\nAfter insert at position 1: "; // Expected output: After insert at position 1: 10 25 30 
for(auto& num : v) cout << num << " "; // Expected output: 10 25 30 

// 5. erase: erase element at position 0
v.erase(v.begin());
cout << "\nAfter erase at position 0: "; // Expected output: After erase at position 0: 25 30 
for(auto& num : v) cout << num << " "; // Expected output: 25 30 

// 6. clear: remove all elements
v.clear();
cout << "\nAfter clear, size: " << v.size(); // Expected output: After clear, size: 0

// 7. resize: change vector size to 5, fill with 0
v.resize(5, 0);
cout << "\nAfter resize to 5: "; // Expected output: After resize to 5: 0 0 0 0 0 
for(auto& num : v) cout << num << " "; // Expected output: 0 0 0 0 0 

vector<student> students;
student s1, s2;
s1.fname = "John";
s1.lname = "Doe";
s2.fname = "Jane";
s2.lname = "Smith";
students.push_back(s1);
students.push_back(s2);
for (const student &s : students) {
    cout << "First Name: " << s.fname << ", Last Name: " << s.lname << endl; 
    // Expected output:
    // First Name: John, Last Name: Doe
    // First Name: Jane, Last Name: Smith
}

// capacity vs size
    vector<int> v;
    cout << "\nInitially: size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // Expected output: Initially: size = 0, capacity = 0
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "After adding 3 elements: size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // Expected output: After adding 3 elements: size = 3, capacity = 3 (capacity may vary by implementation)
    v.reserve(10);
    cout << "After reserve(10): size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // Expected output: After reserve(10): size = 3, capacity = 10
    v.resize(8);
    cout << "After resize(8): size = " << v.size() << ", capacity = " << v.capacity() << endl;
    // Expected output: After resize(8): size = 8, capacity = 10




// list is a doubely linked list and forward list is singly linked list
// we will be doing the forwatd linked list
// we can add or reove from front only


forward_list<int>list={10,20,30};
list.push_front(40);
list.push_front(50);
// list.push_back(70);      //wont work as its a forward_list
for(int n:list)cout<<n<<" "; // Expected output: 50 40 10 20 30 
cout<<endl; // Expected output: (newline)
list.pop_front();
// list.pop_back();             //only front is allowed as its a singled list
for(int n:list)cout<<n<<" "; // Expected output: 40 10 20 30 

forward_list<int>l;
l.assign({10, 20, 30, 10}); // Correct usage with initializer_list
cout<<endl; // Expected output: (newline)
for(int n:l)cout<<n<<" "; // Expected output: 10 20 30 10 
cout<<endl; // Expected output: (newline)
l.remove(10);  //removes every element with the value
for(int n:l)cout<<n<<" "; // Expected output: 20 30 

// insert_after: insert 99 after first element
auto it = l.begin();
l.insert_after(it, 99);
cout << "\nAfter insert_after: "; // Expected output: After insert_after: 20 99 30 
for(int n:l)cout<<n<<" "; // Expected output: 20 99 30 

// emplace_after: emplace 77 after first element
l.emplace_after(l.begin(), 77);
cout << "\nAfter emplace_after: "; // Expected output: After emplace_after: 20 77 99 30 
for(int n:l)cout<<n<<" "; // Expected output: 20 77 99 30 

// erase_after: erase element after first
l.erase_after(l.begin());
cout << "\nAfter erase_after: "; // Expected output: After erase_after: 20 99 30 
for(int n:l)cout<<n<<" "; // Expected output: 20 99 30 

// clear: remove all elements
l.clear();
cout << "\nAfter clear, empty: " << l.empty(); // Expected output: After clear, empty: 1

// reverse: reverse the list
l.assign({1, 2, 3, 4});
l.reverse();
cout << "\nAfter reverse: "; // Expected output: After reverse: 1 2 3 4 
for(int n:l)cout<<n<<" "; // Expected output: 1 2 3 4 

// sort: sort the list
l.assign({4, 2, 3, 1});
l.sort();
cout << "\nAfter sort: "; // Expected output: After sort: 1 2 3 4 
for(int n:l)cout<<n<<" "; // Expected output: 1 2 3 4 

// merge: merge two sorted lists
forward_list<int> l1 = {1, 3, 5};
forward_list<int> l2 = {2, 4, 6};
l1.merge(l2); // l2 becomes empty
cout << "\nAfter merge: "; // Expected output: After merge: 1 2 3 4 5 6 
for(int n:l1)cout<<n<<" "; // Expected output: 1 2 3 4 5 6 


// Example: To remove elements after a specific position in forward_list, use erase_after.
forward_list<int> fl = {1, 2, 3, 4, 5};
auto it = fl.begin(); // points to 1
advance(it, 2); // move iterator to 3
fl.erase_after(it); // removes 4 (element after 3)
for(int n : fl) cout << n << " "; // Output: 1 2 3 5 

 forward_list<A> fl = {{1, 2}};
    fl.insert_after(fl.begin(), {3, 4});
    auto it = fl.begin();
    ++it;
    // cout <<it->x << " " <<it->y; // Expected output: 3 4(No Idea but its givning an error try to fix it man!)

////////////////////////////////list--------------------------------------------

// list is for both double linked list that means we can even add or remove from front or back

std::list<int> l12;     //list is a keyword giving by std,so the compiler interupt as a template so add a scope to fix it
l12.push_front(10);
l12.push_back(20);
for(int n:l12)cout<<n<<" "; // Expected output: 10 20 
l12.pop_front();
l12.pop_back(); 
for(int n:l12)cout<<n<<" "; // Expected output: (no output, list is empty)

// rename this std::list<int> l1 -> lst1 to avoid collision with forward_list fl1
std::list<int> lst1={10,20,30,40,20,40};
// auto it=l1.begin();
// it=l1.erase(it);
lst1.remove(40);
for(int n:lst1)cout<<n<<" "; // Expected output: 20 30 20 

// // unique function: removes consecutive duplicates
lst1.push_back(20);
lst1.push_back(20);
lst1.push_back(30);
for(int n:lst1)cout<<n<<" "; // Expected output: 20 30 20 20 20 30 
lst1.unique();
cout << "\nAfter unique: "; // Expected output: After unique: 20 30 20 30 
for(int n:lst1)cout<<n<<" "; // Expected output: 20 30 20 30 

// // reverse function: reverses the list
lst1.reverse();
cout << "\nAfter reverse: "; // Expected output: After reverse: 30 20 30 20 
for(int n:lst1)cout<<n<<" "; // Expected output: 30 20 30 20 

// // sort function: sorts the list
lst1.sort();
cout << "\nAfter sort: "; // Expected output: After sort: 20 20 30 30 
for(int n:lst1)cout<<n<<" "; // Expected output: 20 20 30 30 


// // Example usage of Josephus problem------------------------------------------------


//     int n = 7, k = 2;
//     cout << "\nJosephus survivor: " << josephus(n, k) << endl;
//     // Expected output: (prints eliminated order, then survivor)
//     // 1
//     // 3
//     // 5
//     // 0
//     // 4
//     // 2
//     // Josephus survivor: 6

// in the func called insert above
    // insert(1);
    // insert(2);
    // insert(3);
    // insert(4);
    // insert(5);
    // display(); // Expected output: 1 2 3 4 5 
    // cout << "\n"; // Expected output: (newline)
    // vector<int>ls={6,7,8,9,10};
    // replace(5,ls);       //another func
    // display(); // Expected output: 1 2 3 4 6 7 8 9 10 




// -------------------------------------------------------------------------deque
// it provides the functioality of both stack and queue
// in deque you can delete from any side
// deque is doubely linked list
deque<int>dq={10,20,30};
dq.push_front(1);
dq.push_back(255);
for(int num:dq){
    cout<<num<<" ";   //output:- 1 10 20 30 255
}cout << "\n";
cout<<dq.front()<<" "<<dq.back()<<endl;  //output:- 1  255
// The internal implementation of a deque is more complex than that of a vector,
// and for this reason, a deque is slower than a vector. Still, both adding and
// removing elements take O(1) time on average at both ends.


return 0;
}