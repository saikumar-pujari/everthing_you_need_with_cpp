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
    // cout<<&x<<endl;
    // cout<<**x<<endl;
    // cout<<*(&x)<<endl;
    // cout<<x<<endl;
    // cout<<"pointer"<<endl;
    // int &y=x;
    // cout<<*(&y);

    // int x=10;
    // int *p;
    // p=&x;
    // cout<<x<<endl;
    // cout<<&x<<endl;
    // cout<<*p<<endl;
    // cout<<p;


    // int *x;
    // // int *w;
    // float *r;
    // double *f;
    // cout<<sizeof(x)<<endl;
    // cout<<sizeof(r)<<endl;
    // cout<<sizeof(f)<<endl;  //size of a pointer in 32bit is always 4 and 64 bit is 8
    // cout<<endl; 



    // int x=10;
    // int y=10;
    // func(x);
    // funcd(&y);
    // cout<<x<<endl;
    // cout<<y;
    // cout<<endl;

    // string s="saikumar";
    // asd(s);
   

    //in fun called by a array always asign the size with the array so that in fun it should not be treated as a pointer
    // int arr[]={10,20,30,40,50};
    // cout<<(arr)<<endl;
    // cout<<(arr+1)<<endl;
    // cout<<*(arr)<<endl;
    // cout<<*(arr+2)<<endl;
    // int *ptr=arr;
    // cout<<*ptr<<endl;
    // ptr++;
    // cout<<*ptr<<endl;
    // cout<<ptr<<endl;
    // cout<<ptr[2]; //pointer satrts the value from 0(the valeu should be 40 cuz in previous step we made a ptr++ which now indicated to arr[1] so, from there p[2] which means 3rd element which is 40) 

    // int arr[]={10,20,30,40};
    // int *p1=arr;
    // int (*p2)[4]=&arr;  //here the 4 represent the size of block if i do a p2++ then i t will increment in a way that increase it's value by 4
    // cout<<*p1<<endl;
    // cout<<**p2<<endl;
    // p2++;
    // cout<<**p2<<endl;  //garbage value or error(4bits forward man deadend!!)


    // int *ptr;
    // cout<<*ptr;  //gives a garbage value

    // int *ptr=NULL;
    // if(ptr!=NULL)
    //     cout<<*ptr;

        // ITS ALWAYS RECOMMENED TO USE NULLPTR IN PLACE OF NULL AS NULL I SCONSIDERED AS 0 IN CPP

    // funcx(NULL); //ambisoius call in the funcx

    // int arr[]={10,20,30,40};
    // int *ptr=arr;
    // cout<<*ptr<<" "<<ptr;
    // cout<<endl;
    // ptr++;
    // cout<<*ptr<<" "<<ptr;


    // int *ptr=nullptr; //nulllptr is equal to 0 which is false
    // if(!ptr){
    //     cout<<"its a null pointer";
    // }

    // Dynamic memory allocator
    // int *ptr= new int[5];           //these all the values aare stored in heap 
    // *(ptr+3)=10;
    // cout<<*(ptr+3);
    // cout<<endl;
    // cout<<*(ptr+2); //garbage value  
    // delete ptr;
    // ptr=nullptr;
    // cout<<endl;
    // cout<<*(ptr+3)<<"ya it wont workk";
    // cout<<endl;
    
    // int arr[] = { 4, 5, 6, 7 };
    // int* p = (arr + 1);
    // cout << *arr + 10;  //arr is refered to the first element
    // cout<<endl;
    // cout<<*p;


    return 0;
}