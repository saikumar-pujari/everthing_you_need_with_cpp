#include <bits/stdc++.h>
using namespace std;


// struct node{
//     int data;
//     node* next;
//     node(int data,node* next){
//         this->data=data;
//         this->next=next;
//     }
//     node(int data){
//         this->data=data;
//         this->next=nullptr;
//     }
// };


// Singly Linked List Topics
// Introduction / Basics
// node structure & memory allocation
// Traversal
// Counting nodes
// Insertion
//     At beginning
//     At end
//     At specific position
//     In sorted list
// Deletion
//     From beginning
//     From end
//     Specific position
//     By value
//     Delete entire list
// Searching
//     Linear search
//     All occurrences
// Reversal
//     Iterative
//     Recursive
//     In groups of k nodes
// Advanced operations
//     Find middle node
//     Detect loop/cycle (Floyd’s cycle detection)
//     Remove loop
//     Find length of loop
//     Merge two sorted lists
//     Remove duplicates (sorted & unsorted)
//     Intersection of two lists
//     Union of two lists
//     Check palindrome
//     Pairwise swap of nodes
//     Rotate list
//     Delete alternate nodes
// Sorting
//     Bubble sort
//     Insertion sort
//     Merge sort
//     Copy / Clone list
// Skip and delete nodes (like LeetCode pattern)
// Miscellaneous
//     Nth node from end
//     Nth node from start
//     Sum of two linked lists (digit by digit)
//     Flatten a linked list (if list has child pointers)
class node{
    public:
    int data;
    node* next;
    public:
    node(int data,node* next){
        this->data=data;
        this->next=next;
    }
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class List{
    node* head,*tail;
    public:
    List(){
        head=tail=NULL;
    }
    void push_front(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    void print(){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    node* getHead() {
        return head;
    }
    void push_back(int val){
        node* newnode=new node(val);
        node* temp=head;
        if(head->next==nullptr) {
            head->next=newnode;
            tail=newnode;
        }else{
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
            tail=newnode;
        }
    }
    void push_at(int val,int position){
        node* newnode=new node(val);
        node* temp=head;
        if(position==1){
            newnode->next=head;
        }else{
            int count=0;
            while(temp!=nullptr&&count<position-2){
                temp=temp->next;count++;
            }
            if(temp==nullptr){
                cout<<"fucker keep a eye on the len!!"<<endl;
                delete newnode;
                // return temp;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    void pop_front(){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    void pop_back(){
        if (head == nullptr) return; // empty list
        if (head->next == nullptr) { // only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        tail = temp;
    }
    void pop_at(int position){
        if (head == nullptr) return; // empty list
        if (head->next == nullptr) { // only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        node* temp = head;
        int count=0;
        while(temp!=nullptr&&count<position-2){
            temp=temp->next;count++;
        }
        if(temp==nullptr){
            cout<<"Fucker keep a eye on the len!!"<<endl;
            return; }
        node* curr=temp->next;
        temp->next=curr->next;
        delete curr;
    }
    
};

node* convertarr2ll(vector<int>&arr){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        // mover->next=temp;
        mover=mover->next;
        mover=temp;
    }
    return head;
}
int lengthofll(node* head){
    int count=0;
    node* temp=head;
    cout<<"the head node containd the data: "<<temp->data<<endl;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}
int searchnll(node* head,int value){
    node* temp=head;
    while(temp){
        if(temp->data==value)return 1;
        temp=temp->next;
    }
    return 0;
}
node* removethehead(node* head){
    node* temp=head;
    head=head->next;
    // cout<<"the head node after removing a node: "<<head->data<<endl;
    delete temp;
    return head;
}
node* deleteatlast(node* head){
    if(head==NULL||head->next==nullptr)return nullptr;
    node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;

}
void print(node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
} 
node* removeat(node* head,int position){
    if (head == nullptr) return nullptr; // empty list
    int count=0;
    node* temp=head;
    node* prev=nullptr;
    while(temp!=nullptr){
        if(count==position){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;count++;
    }return head;
}
node* removeCHAT(node* head,int position){
    if(head==NULL)return NULL;
    node* temp=head;
    if(position==1){
        head=head->next;
        delete temp;
        return head;
    }
    int idx=1; 
    while(temp!=NULL&&idx<position-1){
        temp=temp->next;
        idx++;
    }
    if(temp==NULL||temp->next==nullptr){
        return head;
    }
    node* curr=temp->next;
    temp->next=curr->next;
    // node* curr=temp->next;
    delete curr;
    // temp=temp->next;
    return head;
}
node* removeval(node* head,int element){
    if(head==NULL)return NULL;
    node* temp=head;
    if(temp->data==element){
        head=head->next;
        delete temp;
        return head;
    }
    node* prev=head;
    node* curr=head->next;
    while(curr!=nullptr){
        if(curr->data==element){
            prev->next=curr->next;
            // prev->next=prev->next->next;  //ya same man!!
            delete curr;
            return head;
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}
node* insertfront(node* head,int value){
    node* temp=new node(value,head);
    return temp;
}
node* insertback(node* head,int element){
   node* lastnode=new node(element);
    if(head==nullptr)return NULL;
    node* temp=head;
    while(temp->next!=nullptr){temp=temp->next;}
    temp->next=lastnode;
    return head;
} 
node* insertatpost(node* head,int value,int position){
    node* newnode=new node(value);
    if(position==1){
        newnode->next=head;
        return newnode;
    }
    int count=0;
    node* temp=head;
    while(temp!=nullptr&&count<position-2){
        temp=temp->next;
        count++;
    }
    if(temp==nullptr){
        cout<<"invalid position\n";
        delete newnode;
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
node* insertbeforeval(int val,int element,node* head){
    if(head==NULL)return NULL;
    if(head->data==val){
        return new node(val);
    }
    node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==element){
            node* newnode=new node(val,temp->next);
            temp->next=newnode;
            return head;
        }
        temp=temp->next;
    }return head;
}
node* insertafterval(int val,int element,node* head){
    if(head==NULL)return NULL;
    if(head->data==val){
        return new node(val);
    }
    node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==element){
            temp=temp->next;
            node* newnode=new node(val,temp->next);
            temp->next=newnode;
            return head;
        }
        temp=temp->next;
    }return head;
}
 void removesLoop(node* head) {
        if (!head) return;

        node* slow = head;
        node* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return; // No loop

        // Step 2: Find start of loop
        slow = head;
        if (slow == fast) {
            // Special case: loop starts at head
            while (fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the loop
        fast->next = nullptr;
    }
node* remverse(node* head,int k){
    node* temp=head;
    node* prev=nullptr;
    int count=0;
    while(temp!=nullptr&&count<k){
        node* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        count++;
    }
    if(temp!=nullptr)
        temp->next=remverse(temp,k);
    return prev;
}
node* insertbysort(node* &head,int val){
    node* newnode = new node(val);
    // Empty list: new node becomes head
    if (!head) {
        head = newnode;
        return head;
    }
    // Insert at beginning if value is <= current head
    if (val <= head->data) {
        newnode->next = head;
        head = newnode;
        return head;
    }
    // Find insertion point
    node* temp = head;
    while (temp->next && temp->next->data < val) {
        temp = temp->next;
    }
    // Insert after temp
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
void deleteList(node* &head) {
    node* curr = head;
    while (curr) {
        node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}
vector<int> searchall(node* head,int key){
    int pos=0;
    vector<int>ans;
    node* temp=head;
    while(temp){
        if(temp->data==key){
            ans.push_back(pos);
        }
        temp=temp->next;
        pos++;
    }return ans;
}
int lengthofloop(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int len=0;
            slow=slow->next;
            while(slow!=fast){
                len++;
                slow=slow->next;
            }return len;
        }
    }return 0;
}
node* removeduplicatesortedklinkedlist(node* head){
    node* temp=head;
    while(temp&&temp->next){
        if(temp->data==temp->next->data){
            node* curr=temp->next;
            temp->next=temp->next->next;
            delete curr;
        }else{
            temp=temp->next;
        }
    }
    return head;
}
node* removeDuplicatesRebuild(node* head) {
    if (!head) return nullptr;
    unordered_set<int> seen;
    vector<int> order;  // maintain insertion order
    node* temp = head;
    while (temp) {
        if (seen.find(temp->data) == seen.end()) {
            seen.insert(temp->data);
            order.push_back(temp->data);
        }
        temp = temp->next;
    }
    node* newHead = new node(order[0]);
    node* curr = newHead;
    for (int i = 1; i < order.size(); i++) {
        curr->next = new node(order[i]);
        curr = curr->next;
    }
    curr->next = nullptr;
    return newHead;
}
node *getIntersectionnode(node *headA, node *headB) {
        unordered_set<node*>map;
        while(headA){
            map.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(map.count(headB))return headB;
            headB=headB->next;
        }return nullptr;
    }

node* getUnion(node* head1, node* head2) {
    set<int> seen;
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1){
        seen.insert(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2){
        seen.insert(temp2->data);
        temp2 = temp2->next;
    }
        node* head = nullptr;
        node* tail= nullptr;
    for (auto x : seen) {
        node* newnode = new node(x);
        if (!head) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}
bool isPalindrome(node* head) {
    vector<int> vals;
    node* curr = head;
    while (curr) {
        vals.push_back(curr->data);
        curr = curr->next;
    }
    int i = 0, j = vals.size()-1;
    while (i < j) {
        if (vals[i++] != vals[j--]) return false;
    }
    return true;
}
node* pairwiseSwap(node* head) {
    node* curr = head;
    while (curr && curr->next) {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
}
node* deleteAlternate(node* head) {
    node* curr = head;
    while (curr && curr->next) {
        node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        curr = curr->next;
    }
    return head;
}
node* skipAndDelete(node* head, int M, int N) {
    node* curr = head;
    while (curr) {
        for (int i=1; i<M && curr; i++) curr = curr->next;
        if (!curr) break;
        node* temp = curr->next;
        for (int i=0; i<N && temp; i++) {
            node* del = temp;
            temp = temp->next;
            delete del;
        }
        curr->next = temp;          //connect the LL
        curr = temp;                //move forward
    }
    return head;
}

node* addTwoLists(node* l1, node* l2) {
    node dummy(0);
    node* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        int digit = sum % 10;
        tail->next = new node(digit);
        tail = tail->next;
    }
    return dummy.next;
}
node* oddEvenList(node* head) {
        if(head==NULL||head->next==nullptr||head->next->next==nullptr)return head;
        node* odd=head,*even=head->next,*evennode=head->next;
        while(even!=NULL&&even->next!=nullptr){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evennode;
        return head;
    }
node* sortLL(node* head){
    if(!head||!head->next)return head;;
    node* oned=new node(0);
    node* twod=new node(0);
    node* zerod=new node(0);
    node* one=oned;
    node* two=oned;
    node* zero=oned;
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else if(temp->data==2){
            two->next=temp;
            two=two->next;
        }else{
            zero->next=temp;
            zero=zero->next;
        }
        temp=temp->next;
    }
    zero->next=(one->next)?(one->next):(two->next);
    one->next=two->next;
    two->next=nullptr;
    node* newnodes=zerod->next;
    delete oned;
    delete twod;
    delete zerod;
    delete newnodes;
    return head;
}
node* reverseLLwithrecursive(node* head){
    if(head==NULL||head->next==nullptr)return head;
    node* newhead=reverseLLwithrecursive(head->next);
    node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}
node* reverse1(node* head){
    node* curr=head;
    node* prev=nullptr;
    while(curr->next!=nullptr){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }return prev;
}
node* add1toLL(node* head){
    head=reverse1(head);
    int carry=1;
    node dummy(0);
    node* tail=&dummy;
    node* temp=head;
    while(temp||carry){
        int sum=carry;
        if(temp){
            sum+=temp->data;
            temp=temp->next;
        }
        carry=sum/10;
        int digit=sum%10;
        tail->next=new node(digit);
        tail=tail->next;
    }
    // temp=tail->next;
    // delete tail;
    return (reverse1(dummy.next));
}
node* merge(node*head1,node*head2){
    if(head1==NULL||head2==NULL)return (head1==NULL)?head2:head1;
    if(head1->data<head2->data){
        head1->next=merge(head1->next,head2);
        return head1;
    }else{
        head2->next=merge(head1,head2->next);
        return head2;
    }
}
node* flateenLLbysorthing(node* head){
        if(head==NULL||head->next==nullptr)return head;
        node* mergehead=flateenLLbysorthing(head->next);
        return merge(head,mergehead);    
}

/// doubely linked list
class dnode{
public: // <-- add this line
    int data;
    dnode* next;
    dnode* prev;
    dnode(int data){
        this->data=data;
        next=prev=nullptr;
    }
};
class doublylist{
    dnode* head;
    dnode* tail;
    public:
    doublylist(){
        head=tail=nullptr;
    }
    void push_front(int val){
        dnode* newnode=new dnode(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    void printfro(){
        dnode* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"<->";
            temp=temp->next;
        }cout<<"NULL";cout << "\n";
    }
    void printback(){
        dnode* temp=tail;
        while(temp!=nullptr){
            cout<<temp->data<<"<->";
            temp=temp->prev;
        }cout<<"NULL\n";
    }
    void push_back(int val){
        dnode* newnode=new dnode(val);
        if(head==nullptr){
            head=tail=newnode;
        }else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop_front(){
        dnode* temp=head;
        if(head==NULL)return ;
        else{
            head=head->next;
            // head->prev=nullptr;
            if(head!=NULL){
                head->prev=nullptr;
            }
            temp->next=nullptr;
            delete temp;
        }
    }
    void pop_back(){
        dnode* temp=tail;
        if(head==NULL)return ;
        else{
            tail=tail->prev;
            if(tail!=NULL){
                tail->next=nullptr;
            }
            temp->prev=nullptr;
            delete temp;
        }
    }
    void push_at(int val,int pos){
        dnode* newnode=new dnode(val);
        if(pos==1){
            newnode->next=head;
            if(head!=NULL){
                head->prev=newnode;
            }
            head=newnode;return;
        }
        dnode* temp=head;
        int count=1;
        while(temp!=NULL&&count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            cout << "Position out of range!" << endl;
        return;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newnode;
        }
        temp->next=newnode;
    }
    void deleteAtPosition(dnode*& head, int pos) {
    if (!head || pos <= 0) return;
    dnode* curr = head;
    // Move to the given position
    for (int i = 1; curr && i < pos; i++)
        curr = curr->next;
    if (!curr) return; // Position > length
    // If deleting the head
    if (curr == head)
        head = curr->next;
    // Relink neighbors
    if (curr->prev)
        curr->prev->next = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;
    delete curr;
}
};
dnode* convertarr2dll(vector<int>&arr){
    dnode* head=new dnode(arr[0]);
    dnode* mover=head;
    for(int i=1;i<arr.size();i++){
        dnode* temp=new dnode(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}

class cnode{
    public:
    int data;
    cnode* next;
    cnode(int data){
        this->data=data;
        next=nullptr;
    }
};
class circularlist{
    cnode* head;
    cnode* tail;
    public:
    circularlist(){
        head=tail=nullptr;
    }
    void push_front(int val){
        cnode* newnode= new cnode(val);
        if(!head){
            head=tail=newnode;
            tail->next=head;
        }else{
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }
    void print(){
        if(head==NULL)return;
        cout<<head->data<<"->";
        cnode* temp=head->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<temp->data<<"(head)";cout << "\n";
    }
    void push_back(int val){
        cnode* newnode=new cnode(val);
        if(!head){
            head=tail=newnode;
            tail->next=head;
        }else{
            newnode->next=head;
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop_front(){
        if(!head)return;
        else if(head==tail){
            delete head;
            head=tail=nullptr;
        }
        else{
            cnode* temp=head;
            head=head->next;
            tail->next=head;
            delete temp;
        }
    }
    void pop_back(){
        if(!head)return;
        else if(head==tail){
            delete head;
            head=tail=nullptr;
        }
        else{
            cnode* temp=tail;
            cnode* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=nullptr;
            delete temp;
        }
    }
};


//  node* flatten(node* head) {
//         if(head==NULL)return head;
//         node* curr=head;
//         while(curr!=NULL){
//             if(curr->child!=nullptr){
//                 //flatten child node
//                 node* next=curr->next;
//                 curr->next=flatten(curr->child);
//                 curr->next->prev=curr;
//                 curr->child=NULL;

//                 //find tail
//                 while(curr->next!=nullptr){
//                     curr=curr->next;
//                 }

//                 //attach the tail to next
//                 if(next!=NULL){
//                     curr->next=next;
//                     next->prev=curr;
//                 }
//             }
//             curr=curr->next;
//         }return head;
//     }
    
    int main(){
    // int tc=0;
    // int* y=&tc;
    // cout<<y<<endl;
    // cout<<*y;cout << "\n";
    // cout<<&tc;cout << "\n";
    // cout<<tc;



    // node* y=new node(2,nullptr);
    // cout<<y;cout << "\n";       //address
    // cout<<y->data;cout << "\n";   //value ->2
    // cout<<y->next;cout << "\n";     //adress -> 0
    // if(nullptr==0){
    //     cout<<"its zero man";
    // }
    //node* z=new node(3);
    // cout<<z->data<<" "<<z->next;cout << "\n";            // 3  0
    // cout<<sizeof(z->data)<<" "<<sizeof(z->next);  

    // vector<int>arr={10,20,30};
    // node* head=convertarr2ll(arr);
    // cout<<head->data<<" "<<head->next;c

    // node* temp=head;        //assign the head value to know the staring value
    // while(temp){
    //     cout<<temp->data<<" ";          //get the value from the head
    //     temp=temp->next;        //next address
    // }
    //cout<< "\n";
    // cout<<lengthofll(head);         //also will get to know the starting node also
    // cout << "\n";
    // cout<<searchnll(head,30);cout << "\n";          //1
    // cout<<removethehead(head);      //updated node
    // head=removethehead(head);
    // cout << "\n";
    // cout<<lengthofll(head);  
    // print(head);
    // head=deleteatlast(head);
    // head=removeat(head,2);
    // head=removeCHAT(head,1);
    // head=removeval(head,20);
    // head=insertfront(head,100);
    // head=insertafterval(200,20,head);
    // print(head);
    
    // List ll;
    // ll.push_front(10);
    // ll.push_front(20);
    // ll.push_front(30);
    // ll.push_front(40);
    // ll.push_back(60);
    // ll.push_at(50,5);
    // ll.print();
    // cout << endl;
    // ll.pop_front();
    //    ll.print();
    // cout << endl;
    // ll.pop_back();
    // ll.print();
    // cout << endl;
    // ll.pop_at(3);
    // ll.pop_at(9);
    // // Print all values in the List object
    // // ll.print(ll.getHead());
    // ll.print();
    // cout << endl;



    // types of LL;
    // singly LL
    //     struct node{
    //         int data;
    //         node* next;
    //     };

    // doubely LL    
    //     struct node{
    //         int data;
    //         node* next;
    //         node* prev;
    //     };

    // circular LL
    //similar to the doubely LL but in last emement we will store the value address of 1st element which makes it a circular shape


////////////////////////-----------------doubely linked list
         doublylist dll;
         dll.push_front(20);
         dll.push_front(10);
         dll.push_front(30);
         dll.printfro();
         dll.push_back(50);
         dll.printfro();
         dll.pop_front();
         dll.printfro();
         dll.pop_back();
         dll.printfro();
         dll.printback();
         dll.push_at(30,3);
         dll.printfro();


//--------------circular list--------------
        // circularlist cl;
        // cl.push_front(4);
        // cl.push_front(3);
        // cl.push_front(2);
        // cl.push_front(1);
        // cl.print();
        // cl.push_back(5);
        // cl.print();
        // cl.pop_front();
        // cl.print();
        // cl.pop_back();
        // cl.print();

        
    return 0;

}