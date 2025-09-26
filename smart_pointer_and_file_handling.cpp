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
            cout<<"satrted\n";
            ptr=p;
        }
        ~sp(){
            cout<<"\ndeleted\n";
            delete ptr;}
        int &operator *(){return *ptr;}
};

// calling a pointer in the main
class smart{
    int x,y;
    public:
    smart(int a=0,int b=0):x(a),y(b){
        cout<<"started here\n";
    }
    ~smart(){cout<<"destroyed";}
};

void fun(){
    cout<<"SAIKUMAR";
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
    // cout<<*p;
    // cout << "\n";
    // cout<<m;
    // delete p;        deleteing the pointer only when the pointer is dynamically pointing(heap) aka. new or new[] only



    // int s=50;
    // f(s);
    // cout<<s<<endl;


    // sp sp(new int());
    // *sp=10;
    // cout<<*sp;

    // {
    //     smart *p=new smart(10,20);                          //main is called using dynamic memory allocation
    // }

    // There are several types of smart pointers in C++:
    // 1) unique_ptr: Owns the object exclusively. Cannot be copied, only moved.
    // 2) shared_ptr: Multiple pointers can share ownership of the same object. Reference counted.
    // 3) weak_ptr: Non-owning pointer used with shared_ptr to avoid cyclic references. Use lock() to get shared_ptr.
    // 4) Custom smart pointers: Like the 'sp' class above, can be implemented for specific needs.




    // --------------------------------------------------
    // file reading
    // char ch;
    // ifstream fin;
    // fin.open("text.txt");
    // ch=fin.get();
    // while(!fin.eof()){
    //     cout<<ch;
    //     ch=fin.get();
    // }
    // fin.close();


    //file writing
    
    // ofstream sai;
    // sai.open("saikumar.txt");
    // sai<<"hey man its the file which is going to be here for a while ok!!";
    // sai.close();


    // In C++, memory is divided into several sections:
    // 1. Stack: Stores function calls and local variables.
    // 2. Heap: Stores dynamically allocated memory (using new/delete).
    // 3. Data segment: Stores static and global variables.
    // 4. Text segment: Stores executable code (instructions) also function pointers.
    // Example: Using unique_ptr and shared_ptr

    // unique_ptr<int> uptr(new int(100));
    // cout << "unique_ptr value: " << *uptr << endl;

    // shared_ptr<int> sptr1 = make_shared<int>(200);
    // shared_ptr<int> sptr2 = sptr1; // shared ownership
    // cout << "shared_ptr value: " << *sptr1 << ", count: " << sptr1.use_count() << endl;

    // weak_ptr<int> wptr = sptr1; // does not increase reference count
    // if (auto locked = wptr.lock()) {
    //     cout << "weak_ptr locked value: " << *locked << endl;
    // } else {
    //     cout << "weak_ptr expired" << endl;
    // }


    // function pointer
    // auto fun_ptr=fun;
    // (*fun_ptr)(); //also fun_ptr();

    // auto fun_ptr=sum;
    // cout<<fun_ptr(10,20);

// in function pointer we can assign a pointer to multipe function in one call
    // auto fun=add;
    // cout<<fun(10,20);
    //  fun=sub;     
    // cout<<fun(10,20);

    // cout<<compute(10,20,add)<<endl;


    // int arr[5]={2,4,-1,8,-9};
    // int n=5;
    // sort(arr,arr+n,compare);
    // for(int unm:arr){
    //     cout<<unm<<" ";
    // }

    // we can also use the lambda function in place of function pointers
    // auto lambda_add = [](int a, int b) { return a + b; };
    // cout << "Lambda add: " << lambda_add(5, 7) << endl;

    // // Using lambda with sort
    // int arr2[5] = {3, -2, 5, 1, -4};
    // sort(arr2, arr2 + 5, [](int a, int b) { return abs(a) < abs(b); });
    // cout << "Sorted by abs using lambda: ";
    // for (int x : arr2) cout << x << " ";
    // cout << endl;
    

    // vector<int>v={2,4,-1,8,-9};
    // for_each(v.begin(),v.end(),[](int &x){return x=x*2;});
    // for_each(v.begin(),v.end(),[](int x){cout<<x<<" ";});

    // simlilary we also have find_if and count_if and accumulate
    return 0;
}