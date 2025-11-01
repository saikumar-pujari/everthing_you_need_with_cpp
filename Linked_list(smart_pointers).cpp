#include <iostream>
#include <memory>
using namespace std;

class Node {
public:
    int data;
    Node(int val) : data(val) { cout << "Node " << data << " created\n"; }
    ~Node() { cout << "Node " << data << " deleted\n"; }
};

int main() {
    //in linked list we use .get() to get raw pointer in smart pointer
    //also same as .get() we sue .reset() to remove all elements from the linked list
    
    {
        unique_ptr<Node> ptr1 = make_unique<Node>(10);
        cout << "ptr1 owns " << ptr1->data << endl;

        // transfer ownership
        unique_ptr<Node> ptr2 = move(ptr1);
        if (!ptr1) cout << "ptr1 no longer owns anything\n";
        cout << "ptr2 owns " << ptr2->data << endl;
    } // <-- ptr2 goes out of scope here, deletes Node 10 automatically

    cout << "End of scope reached\n";
    cout<<"---------------------------------------shared-pointer\n";
    shared_ptr<Node> p1;
    {
        shared_ptr<Node> p2 = make_shared<Node>(20);
        cout << "use_count = " << p2.use_count() << endl;

        p1 = p2;  // both share ownership now
        cout << "use_count = " << p2.use_count() << endl;
    } // p2 goes out of scope, but p1 still exists

    cout << "use_count = " << p1.use_count() << endl;

    p1.reset(); // last owner releases ->
    cout<<"--------------------------weak pointer this side\n";
      weak_ptr<Node> weak;
    {
        shared_ptr<Node> shared = make_shared<Node>(30);
        weak = shared; // weak_ptr observes shared_ptr

        cout << "use_count = " << shared.use_count() << endl;

        if (auto temp = weak.lock()) {
            cout << "weak_ptr can access data = " << temp->data << endl;
        }
    } // shared_ptr destroyed here

    if (weak.expired()) {
        cout << "weak_ptr expired (object deleted)\n";
    }

    cout << "End of scope\n";
}
