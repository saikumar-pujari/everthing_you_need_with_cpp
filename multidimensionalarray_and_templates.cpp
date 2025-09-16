#include <bits/stdc++.h>
using namespace std;

template <typename t>
t saikumar(t x,t y){
    return (x>y)?x:y;
}
template <typename t, size_t N>
void nikhil(const t (&arr)[N]){
    for(size_t i=0; i<N; i++) cout << arr[i] << " ";
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
};
int main(){
    // template is used for write ones and use it again and again 
    // cout<<saikumar(8,9)<<endl;
    // cout<<saikumar(8.5,8.1)<<endl;
    // cout<<saikumar('g','f')<<endl;          
     //if we use template we dont care about the data type cuz its pre defined in the template as the type


    //  int nuums[]={10,20,30,40,50,60};
    // nikhil(nuums);


    //the main difference between func and class template is in class template we can add any sata struc 
// intarray arr;
// arr.fill(10);
// arr.at(5)=100;
// for(int i=0;i<10;i++){
//     cout<<arr.at(i)<<" ";
// }

    return 0;
}