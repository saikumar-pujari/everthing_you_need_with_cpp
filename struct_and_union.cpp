#include <bits/stdc++.h>
using namespace std;

struct points{
    int x;
    string y;
};
typedef struct {                    //typedef is used in old c++ compilers now the compiler are more mordern and if we need then use the keyword "using" inplace of 'typedef'
        int x;
        int y;
    }pd;

struct sai{
        int x;
    };
struct derived:sai{};


class point{
    // public:
    int x;
};

class kumar{
    public:
    int x;
};
class derviedd:public kumar{};  //untill the class derived is  public the value will not compile
struct saikumar
{
    /* data */
    int x,y;
};
struct nikhil{
    int x,y;

};
void print(nikhil p){
    cout<<p.x<<" "<<p.y;
}
struct s2 {
    double d1; //8
    double d2; //8
    char c1; //2
    char c2; //2
} __attribute__((packed));
struct s1 {
    double d1;  //8 ()
    double d2; //8 ()
    char c1; //8 ()
    char c2; //8 ()
};


// union is similar to struct but it assign its largest value to all of elements (mostly used in compiler in my project of compilers)
    union saiku{
        public:
        int x;
        private:
        string y;
        protected:
        float z;
    };

int main(){
    // struct is user defined and public 
    // points p;
    // p.x=10;
    // p.y="khgbk";
    // cout<<p.x<<" "<<p.y; // Expected output: 10 khgbk
    
    // we often use typedef while using the struct in cpp so that we can assign the value after we define them
    // pd p;
    // p.x=0;
    // p.y=44;
    // cout<<p.x<<" "<<p.y; // Expected output: 0 44

    // class is similar to struct but these have private members in them so if we call them we will get a compiler error
    // point p;
    // p.x=0;       //now its commented as its also used for other example plz uncomment it on line 20 i guess ;)
    // cout<<p.x; //it will give a error as private here

    //  point p;
    // p.x=0;
    // cout<<p.x;       //but we can run this programm if we metion the class as public and vice-versa in struct

    // now inhertence in the struct and clas
    // derived s;
    // s.x=72;
    // cout<<s.x;   //it compiles as the struct and the inhertance 
    // Expected output: 72

    // derviedd sai;
    // sai.x=3;
    // cout<<sai.x;   //in class the inhertance will give compiler error until the class called is made public 

    // saikumar p={10,20};
    // saikumar *ptr=&p;
    // cout<<ptr->x<<endl;          //its struct as a pointer__Expected output: 10
    
    // ptr->x=100;
    // cout<<ptr->x<<endl;  //in pointer the dot is not used when comparing it uses the -> method!!
    // Expected output: 100

    // nikhil p={10,20};
    // print(p);                //struct as a argument
    // Expected output: 10 20

    // nikhil n[2];
    // for(int i=1;i<=2;i++){
    //     n[i].x=i;
    //     n[i].y=i*10;
    // }
    // for(int i=1;i<=2;i++){                   //struct as a array
    //     cout<<n[i].x<<" "<<n[i].y<<endl;
    // Expected output:
    // 1 10
    // 2 20
    // }

    // cout<<sizeof(s2)<<endl; // Expected output: 20
    // cout<<sizeof(s1);       // Expected output: 24
    
    return 0;
}