#include <bits/stdc++.h>
using namespace std;
void f(int &s){
    s+=10;
}
// calling a pointer without a pointer in the main
class sp{
    int *ptr;
    public:
        sp(int *p=nullptr){
            cout<<"satrted\n"; // Output: satrted
            ptr=p;
        }
        ~sp(){
            cout<<"\ndeleted\n"; // Output: deleted
            delete ptr;}
        int &operator *(){return *ptr;}
};

// calling a pointer in the main
class smart{
    int x,y;
    public:
    smart(int a=0,int b=0):x(a),y(b){
        cout<<"started here\n"; // Output: started here
    }
    ~smart(){cout<<"destroyed";} // Output: destroyed
};

void fun(){
    cout<<"SAIKUMAR"; // Output: SAIKUMAR
}
int sum(int x,int y){
    return (x+y);
}
int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }

int compute(int a,int b,int (*fun_prt)(int,int)){       //in function we cant use the keyword auto it can be only used in lambda or templates or main 
    return fun_prt(a,b);
}

bool compare(int c,int d){return abs(c)<abs(d);}

int main(){
    // int x=10;
    // int *p=&x;
    // int &m=*p;
    // cout<<*p; // Output: 10
    // cout << "\n"; // Output: (newline)
    // cout<<m; // Output: 10
    // delete p;        // deleteing the pointer only when the pointer is dynamically pointing(heap) aka. new or new[] only

    // int s=50;
    // f(s);
    // cout<<s<<endl; // Output: 60

    // sp sp(new int());
    // *sp=10;
    // cout<<*sp; // Output: 10 and also Deleted from the func

    // {
    //     smart *p=new smart(10,20); // Output: started here
    // } // Output: destroyed

    // There are several types of smart pointers in C++:
    // 1) unique_ptr: Owns the object exclusively. Cannot be copied, only moved.
    // 2) shared_ptr: Multiple pointers can share ownership of the same object. Reference counted.
    // 3) weak_ptr: Non-owning pointer used with shared_ptr to avoid cyclic references. Use lock() to get shared_ptr.
    // 4) Custom smart pointers: Like the 'sp' class above, can be implemented for specific needs.


    unique_ptr<int>st=make_unique<int>(10);
    cout<<*st; // Output: 10
    cout<<endl; // Output: (newline)
    // cout<<st.use_count()<<endl;  //error as unique pointer does not have any count()!! we can transfer unique to shared if we want

    shared_ptr<int>sst=make_shared<int>(100);
    cout<<*sst; // Output: 100
    cout<<endl; // Output: (newline)
    auto p=sst;
    cout<<*p; // Output: 100
    cout<<endl; // Output: (newline)
    auto pq=p;
    cout<<pq<<endl; // Output: address of shared_ptr<int> object (e.g., 0x55f... format)
    cout<<p.use_count()<<" "; // Output: 3 
    cout<<sst.use_count()<<" "; // Output: 3
    cout<<endl; // Output: (newline)
    cout<<endl; // Output: (newline)

    unique_ptr<int>sai=make_unique<int>(70504);     //any number staring with 0 will be a octet form!!
    shared_ptr<int>saikumar=move(sai);
    cout<<*saikumar<<endl; // Output: 70504
    cout<<"count is :"<<saikumar.use_count()<<endl; // Output: count is :2
    auto niki=saikumar;
    cout<<*niki<<endl; // Output: 70504
    cout<<"count is :"<<niki.use_count()<<endl; // Output: count is :2
    if(!sai){
        cout<<"unique pointer is empty now man!!\n"; // Output: unique pointer is empty now man!!
    }


    // --------------------------------------------------
    // file reading
    // char ch;
    // ifstream fin;
    // fin.open("text.txt");
    // ch=fin.get();
    // while(!fin.eof()){
    //     cout<<ch; // Output: (contents of text.txt, character by character)
    //     ch=fin.get();
    // }
    // fin.close();

    // file writing
    // ofstream sai;
    // sai.open("saikumar.txt");
    // sai<<"hey man its the file which is going to be here for a while ok!!";
    // sai.close();



    // --------------------------------------------
    // In C++, memory is divided into several sections:
    // 1. Stack: Stores function calls and local variables.
    // 2. Heap: Stores dynamically allocated memory (using new/delete).
    // 3. Data segment: Stores static and global variables.
    // 4. Text segment: Stores executable code (instructions) also function pointers.
    // Example: Using unique_ptr and shared_ptr

    // unique_ptr<int> uptr(new int(100));
    // cout << "unique_ptr value: " << *uptr << endl; // Output: unique_ptr value: 100

    // shared_ptr<int> sptr1 = make_shared<int>(200);
    // shared_ptr<int> sptr2 = sptr1; // shared ownership
    // cout << "shared_ptr value: " << *sptr1 << ", count: " << sptr1.use_count() << endl; // Output: shared_ptr value: 200, count: 2

    // weak_ptr<int> wptr = sptr1; // does not increase reference count
    // if (auto locked = wptr.lock()) {
    //     cout << "weak_ptr locked value: " << *locked << endl; // Output: weak_ptr locked value: 200
    // } else {
    //     cout << "weak_ptr expired" << endl; // Output: weak_ptr expired
    // }

    // function pointer
    // auto fun_ptr=fun;
    // (*fun_ptr)(); //also fun_ptr(); // Output: SAIKUMAR

    // auto fun_ptr=sum;
    // cout<<fun_ptr(10,20); // Output: 30

    // in function pointer we can assign a pointer to multipe function in one call
    // auto fun=add;
    // cout<<fun(10,20); // Output: 30
    // fun=sub;     
    // cout<<fun(10,20); // Output: -10

    // cout<<compute(10,20,add)<<endl; // Output: 30

    // int arr[5]={2,4,-1,8,-9};
    // int n=5;
    // sort(arr,arr+n,compare);
    // for(int unm:arr){
    //     cout<<unm<<" "; // Output: -1 2 4 8 -9 
    // }

    // we can also use the lambda function in place of function pointers
    // auto lambda_add = [](int a, int b) { return a + b; };
    // cout << "Lambda add: " << lambda_add(5, 7) << endl; // Output: Lambda add: 12

    // // Using lambda with sort
    // int arr2[5] = {3, -2, 5, 1, -4};
    // sort(arr2, arr2 + 5, [](int a, int b) { return abs(a) < abs(b); });
    // cout << "Sorted by abs using lambda: "; // Output: Sorted by abs using lambda: 
    // for (int x : arr2) cout << x << " "; // Output: 1 -2 3 -4 5 
    // cout << endl; // Output: (newline)

    // vector<int>v={2,4,-1,8,-9};
    // for_each(v.begin(),v.end(),[](int &x){return x=x*2;});
    // for_each(v.begin(),v.end(),[](int x){cout<<x<<" ";}); // Output: 4 8 -2 16 -18 

    // simlilary we also have find_if and count_if and accumulate
    return 0;
}