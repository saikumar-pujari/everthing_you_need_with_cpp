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
    // func(x);
    // funcd(&y);
    // cout<<x<<endl; // 20
    // cout<<y; // 30
    // cout<<endl;

    // string s="saikumar";
    // asd(s); // saikumar

    //in fun called by a array always asign the size with the array so that in fun it should not be treated as a pointer
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
    // int *p1=arr;
    // int (*p2)[4]=&arr;  //here the 4 represent the size of block if i do a p2++ then i t will increment in a way that increase it's value by 4
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

    // funcx(NULL); // ambisoius call in the funcx

    // int arr[]={10,20,30,40};
    // int *ptr=arr;
    // cout<<*ptr<<" "<<ptr; // 10 (address of arr)
    // cout<<endl;
    // ptr++;
    // cout<<*ptr<<" "<<ptr; // 20 (address of arr[1])

    // int *ptr=nullptr; //nulllptr is equal to 0 which is false
    // if(!ptr){
    //     cout<<"its a null pointer"; // its a null pointer
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
    // int* p = (arr + 1);
    // cout << *arr + 10;  // 14
    // cout<<endl;
    // cout<<*p; // 5

    return 0;
}