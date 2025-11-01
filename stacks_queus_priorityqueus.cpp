#include <bits/stdc++.h>
using namespace std;

bool matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool balanced(string &name){
    stack<char>s;
    for(int i=0;i<name.length();i++){
        if(name[i]=='('||name[i]=='['||name[i]=='{'){
            s.push(name[i]);
        }else if(name[i]==')'||name[i]==']'||name[i]=='}'){
            if(s.empty()) return false;
            else if(!matching(s.top(),name[i])) return false;
            else s.pop();
        }
    }
    return s.empty();
}
 void previousgreaetereleemtn(int arr[], int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        int pg = s.empty() ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}
void nextgreaetereleemtn(int arr[], int n) {
    stack<int> s;
    vector<int> res(n);
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}

void genrate(int n){
    queue<string>q;
    q.push("5");
    q.push("6");
    for(int i=0;i<n;i++){
        string curr=q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr+"5");
        q.push(curr+"6");
    }
}
void reversekelements(queue<int>&q,int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size();i++){
        q.push(q.front());
        q.pop();
    }
}
void printKLargestElements(priority_queue<int> pq, int k) {
    for (int i = 0; i < k && !pq.empty(); ++i) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int genrtesum(int arr[],int n,int sum){
    priority_queue<int, vector<int>, greater<int>> q(arr, arr + n);
    int quantity=0;
    while(sum>=0 && !q.empty() && sum>=q.top()){
        sum-=q.top();
        q.pop();
        quantity++;
    }
    return quantity;
}

int main(){
    // stacks is a lifo(last in first out)
    // we can only insert at top and remove from the top
    // stack<int>s;
    // // it has fun like push,pop,top,size,empty
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // cout<<s.top();cout << "\n";
    // s.pop();
    // cout<<s.top();cout << "\n";
    // cout<<s.size();

///reverse a string using stack instead of reverse()
    // string name="saikumar";
    // stack<char>s;
    // for(int i=0;i<name.size();i++){
    //     s.push(name[i]);
    // }
    // for(int i=0;i<name.length();i++){
    //     name[i]=s.top();
    //     s.pop();
    // }
    // cout<<name;

    // stacks are usefull to forward_list where the travsering is only possible for 1 direvtion you can travser backwards using stack
////balanced string
    // string test = "{[()]}";
    // cout << (balanced(test) ? "Balanced" : "Not Balanced") << endl;


    ///stock span problem and its vartition
    //previousgreterelement
    // int arr1[]={20,30,10,5,15};
    // int arr[]={10,15,20,25};
    // int n=5;
    // previousgreaetereleemtn(arr1,n);
    // nextgreaetereleemtn(arr,n);



/////////////////////////////////////QUEUES
    // its a first in first out
    // similar to stack but oppsoit to it
    // first come,first server
    // queue<int>q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // cout<<q.top();  //wont work
    // cout<<q.front();cout << "\n";
    // cout<<q.back();

    //genrate 10 number using the elements 5 & 6
    // genrate(10);cout << "\n";
    // genrate(14);cout << "\n";

    //revere first k elemet using stack and queue
    // queue<int>q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // reversekelements(q,3);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }



//////////priority__queues
    // always implemeneted using heap structure           
    // default is always a max-heap
    // in max-heap the maximum max_element( will be at top
    // mostly used in dijisktra,prim,huffman,heap sort
    priority_queue<int>p;
    // p.push(10);
    // p.push(20);
    // p.push(30);
    // p.push(40);
    // cout<<p.top();
    // for minheap (greater<int>)

    // print k largest element using priority queue
    // int k = 3;
    // cout << "\nK largest elements: ";
    // printKLargestElements(p, k);
    
    int arr[]={1,12,5,111,200};
    int n=5;
    int sum=10;
    cout<<genrtesum(arr,n,sum);
    
    return 0;
}