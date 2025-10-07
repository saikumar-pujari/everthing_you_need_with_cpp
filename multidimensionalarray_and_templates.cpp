#include <bits/stdc++.h>
using namespace std;

template <typename t>
t saikumar(t x,t y){
    return (x>y)?x:y;
}
template <typename t, size_t N>
void nikhil(const t (&arr)[N]){
    for(size_t i=0; i<N; i++) cout << arr[i] << " "; // Expected output: 10 20 30 40 50 60 
}


class intarray{
    public:
    int array[10];
    void fill(int value){
        for(int i=0;i<10;i++){
            array[i]=value;
        }
    }
    int& at(int index){
        return array[index];
    }
    void print();       //need to initalsize first inside the class then call them
};

void intarray::print(){     //calliing a func outside the class
    for(int i=0;i<10;i++){
        cout<<array[i]<<" "; // Expected output: 10 10 10 10 10 50 10 10 10 10 
    }
}

int main(){
    // template is used for write ones and use it again and again 
    // cout<<saikumar(8,9)<<endl; // Expected output: 9
    // cout<<saikumar(8.5,8.1)<<endl; // Expected output: 8.5
    // cout<<saikumar('g','f')<<endl; // Expected output: g
    // ...existing code...

    //  int nuums[]={10,20,30,40,50,60};
    // nikhil(nuums); // Expected output: 10 20 30 40 50 60 

    // ...existing code...
    intarray arr;
    arr.fill(10);
    arr.at(5)=50;
    // for(int i=0;i<10;i++){
    //     cout<<arr.at(i)<<" "; // Expected output: 10 10 10 10 10 50 10 10 10 10 
    // }
    arr.print(); // Expected output: 10 10 10 10 10 50 10 10 10 10 
    return 0;
}