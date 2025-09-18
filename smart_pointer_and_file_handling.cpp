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
int main(){
    // int x=10;
    // int *p=&x;
    // int &m=*p;
    // cout<<*p;
    // cout << "\n";
    // cout<<m;
    // delete p;



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
    // char ch;
    // ifstream fin;
    // fin.open("text.txt");
    // ch=fin.get();
    // while(!fin.eof()){
    //     cout<<ch;
    //     ch=fin.get();
    // }
    // fin.close();

    ofstream sai;
    sai.open("saikumar.txt");
    sai<<"hey man its the file which is going to be here for a while ok!!";
    sai.close();
    return 0;
}