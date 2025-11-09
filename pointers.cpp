#include <bits/stdc++.h>
using namespace std;


void func(int &x){
    x+=10;
}

void funcd(int *p){
    *p+=20;
}
void asd(string &s){
    cout<<s;
}
void funcx(int x){

}
void funcx(int *ptr){

}
class Animal {
public:
    void eat()  { cout << "Animal eating\n"; }
    virtual void speak() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks\n"; }
    void bark() { cout << "Bark! Bark!\n"; }
};

int main(){
    // int x=0;
    // cout<<&x<<endl; // (address of x, e.g. 0x7ffee4b8c8ac)
    // cout<<**x<<endl; // error: invalid type argument
    // cout<<*(&x)<<endl; // 0
    // cout<<x<<endl; // 0
    // cout<<"pointer"<<endl; // pointer
    // int &y=x;
    // cout<<*(&y); // 0

    // int x=10;
    // int *p;
    // p=&x;
    // cout<<x<<endl; // 10
    // cout<<&x<<endl; // (address of x, e.g. 0x7ffee4b8c8ac)
    // cout<<*p<<endl; // 10
    // cout<<p; // (address of x, e.g. 0x7ffee4b8c8ac)

    // int *x;
    // // int *w;
    // float *r;
    // double *f;
    // cout<<sizeof(x)<<endl; // 8 (on 64-bit), 4 (on 32-bit)
    // cout<<sizeof(r)<<endl; // 8 (on 64-bit), 4 (on 32-bit)
    // cout<<sizeof(f)<<endl; // 8 (on 64-bit), 4 (on 32-bit)
    // cout<<endl; 

    // int x=10;
    // int y=10;
    // func(x);     //uses the reference method
    // funcd(&y);       //uses the pointer method
    // cout<<x<<endl; // 20
    // cout<<y; // 30
    // cout<<endl;

    // string s="saikumar";
    // asd(s); // saikumar

    //reference
    // int a=10;
    // int& g=a;
    // g++;
    // cout<<a<<" "<<g<<endl;    //both are refering to same address so increment of the g will effect the a also!

    // int* p=nullptr;
    // cout<<*p;

    //SWAP USING THE POINTERS
    // void swap(int* a, int* b) {
    // int temp = *a;
    // *a = *b;
    // *b = temp;
    // }

    //SWAP USING REFERENCE
    // void swap(int& a, int& b) {
    // int temp = a;
    // a = b;
    // b = temp;
    // }

    //in fun called by a array always asign the size with the array so that in fun it should not be treated as a pointer
    // When you pass an array to a function, it automatically decays into a pointer to its first element.
    // int arr[]={10,20,30,40,50};
    // cout<<(arr)<<endl; // (address of arr, e.g. 0x7ffee4b8c880)
    // cout<<(arr+1)<<endl; // (address of arr[1], e.g. 0x7ffee4b8c884)
    // cout<<*(arr)<<endl; // 10
    // cout<<*(arr+2)<<endl; // 30
    // int *ptr=arr;
    // cout<<*ptr<<endl; // 10
    // ptr++;
    // cout<<*ptr<<endl; // 20
    // cout<<ptr<<endl; // (address of arr[1], e.g. 0x7ffee4b8c884)
    // cout<<ptr[2]; // 40 cuz the pointer points at 20 now

    // int arr[]={10,20,30,40};
    // int *p1=arr; //10
    //arr is a reference to an array of N integers(int(&arr)[N])
    // int (*p2)[4]=&arr;
    // cout<<*p1<<endl; // 10
    // cout<<**p2<<endl; // 10
    // p2++;
    // cout<<**p2<<endl; // garbage value or error

    // int *ptr;
    // cout<<*ptr;  // garbage value

    // int *ptr=NULL;
    // if(ptr!=NULL)
    //     cout<<*ptr; // (no output)

    // ITS ALWAYS RECOMMENED TO USE NULLPTR IN PLACE OF NULL AS NULL I SCONSIDERED AS 0 IN CPP

    // funcx(NULL); // ambisoius call in the funcx,can be fixed by using nullptr instead of NULL or #define NULL 0
                    //in this error the func gets confused to call which func man cuz all have same name and parameter!

    // int arr[]={10,20,30,40};
    // int *ptr=arr;
    // cout<<*ptr<<" "<<ptr; // 10 (address of arr)
    // cout<<endl;
    // ptr++;
    // cout<<*ptr<<" "<<ptr; // 20 (address of arr[1])

    // int *ptr=nullptr; //nulllptr is equal to 0 which is false
    // if(!ptr){
    //     cout<<"its a null pointer"; // its a null pointer(it prints a output)
    // }

    // Dynamic memory allocator
    // int *ptr= new int[5];           //these all the values aare stored in heap 
    // *(ptr+3)=10;
    // cout<<*(ptr+3); // 10
    // cout<<endl;
    // cout<<*(ptr+2); // garbage value  
    // delete ptr;
    // ptr=nullptr;
    // cout<<endl;
    // cout<<*(ptr+3)<<"ya it wont workk"; // undefined behavior
    // cout<<endl;
    
    // int arr[] = { 4, 5, 6, 7 };
    // int* p = (arr + 1);      //5
    // cout << *arr + 10;  // 14
    // cout<<endl;
    // cout<<*p; // 5

    //DYNAMIC ARRAYS USING POINTER TO RESIZE
    // int* newArr = new int[newSize];
    // for (int i = 0; i < size; ++i)
    //     newArr[i] = arr[i];
    // for (int i = size; i < newSize; ++i)
    //     newArr[i] = 0; // fill default
    // delete[] arr;
    // arr = newArr;
    // size = newSize;


    //----------base-class calling a derived class----------
    //when you have a base class(interface)  you can call your derived method through the base class but the method--
    //--should be present in both the class or else we need to implicity show the compiler there exists a method in--
    //--dervied class and base class is using it

    //IMPORTANT--> a clinet only interacts with with interfeace(base_class) so calling wiith derived from base_class is important

    // normak_calling_of_pointer
    Dog d;
    d.bark();
    d.speak();

    Animal a;
    a.speak();
    a.eat();
    //calling a derived class using base_class
    Animal* a1=new Dog();       //Animal view → parent method
    a1->speak();

    Animal* a2=new Dog();
    // a2->bark();     //error cause there is no method bark in the base-class
    ((Dog*)a2)->bark(); //we can use its alternative here by using cast(static_casting)(static_down)
    delete a1;
    delete a2;
    // +-----------------------+
    // |       Animal* a1      | ----> [ Dog object in heap ]
    // |                       |        ├── Animal::eat()
    // |                       |        ├── Dog::speak()   (virtual)
    // |                       |        └── Dog::bark()
    // +-----------------------+

    return 0;
}