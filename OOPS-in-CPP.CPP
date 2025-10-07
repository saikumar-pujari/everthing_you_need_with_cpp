#include <bits/stdc++.h>
using namespace std;
#define IMPORTANT


class MyClass {
public:
    int x;
    // Constructor
    MyClass(int val) {
        x = val;
    }
    void print(){
        cout<<x; // Expected output: value of x
    }
};

class point{
    private:
    int x=100,y=100;
    public:
    point():x(0),y(0){          //we can even assign the values with the initalizer :x(0),y(0){} which is same as x=0&y=0.
        x=0;                       //if we have to choose ,we have to choose initalizer for performance
        y=0;
    }
    point(int x1,int y1){
        x=x1;
        y=y1;
    }
    void print(){
        cout<<x<<" "<<y<<endl; // Expected output: values of x and y separated by space
    }
};

class test{
    
    public:
    int x;
        test(){
            cout<<"default\n"; // Expected output: default
        }
        test(int x){
            cout<<"parameterizes\n"; // Expected output: parameterizes
        }
};

class MyMain{
    test t;
    public:
        MyMain():t(10){                 //without initalizer the output will be default and paramertised
            t=test(10);
        }               //in initalizer it direclty assignes it but in default it creates first and then assigns
};


//copy constructor

//when ever we use pointer in class remeber we need to use the dynamic memory allocation and destroy afterwards
class login{
    int *ptr;
    public:
        login(int x){
            ptr=new int(x);
        }
        void set(int x){
            *ptr=x;
        }
        void print(){
            cout<<*ptr<<endl; // Expected output: value pointed by ptr
        }


};

// ------

class dest{
    public:
    dest(){
        cout<<"created it man"<<endl; // Expected output: created it man
    }
    ~dest(){                            //destructor is called if the value is out of scope man 
        cout<<"destory it man"; // Expected output: destory it man
    }
};


class Student {
    int *marks;   // pointer (will hold dynamic memory)
    int n;        // number of subjects

public:
    // constructor
    Student(int subjects) {
        n = subjects;
        marks = new int[n];  // dynamic memory allocated here
        cout << "Allocated memory for " << n << " subjects" << endl; // Expected output: Allocated memory for <n> subjects
    }

    // destructor
    ~Student() {
        delete[] marks;  // free memory when object is destroyed
        cout << "Memory freed" << endl; // Expected output: Memory freed
    }
};

// --------------------------------------------------------------------------------------------------------------------
// this pointer
class pointer{
    int x,y;
    public:
        pointer(int x,int y){
            this->x=x;
            this->y=y;
        }
        pointer &setx(int x){
            this->x=x;
            return *this;
        }
        pointer &sety(int y){
            this->y=y;
            return *this;
        }
       void print(){
        cout<<x<<" "<<y<<endl; // Expected output: values of x and y separated by space
       }

};

// ---------------------------------------------------------------------------------------------------
// static members and functions


class player{
    public:
    static int count;
    player(){count++;};
    ~player(){count--;};
    static int getcount(){return count;} // Expected output: current count value
};
int player::count=0;              //important //static-members should be defined outside the class or compiler will thorw an error man


// --------------------------------------------------------------------------------------
// inhertance

// before we inherit a _Construct from the other we need a  base class to be called in derived class also
// #pragma-message here


// protected: its mix of private and public like it can be only accesed by the members which is getting inherited by it  only


class student{
    protected:
    string name;
    string id;
};
class teachers : public student {
    private:
        int marks; // marks is private now
    public:
        // void setMarks(int m) {
        //     marks = m;
        // }
        // int getMarks() {
        //     return marks;
        // }
        void setdata(string name,string id,int marks){
            this->name=name;
            this->id=id;
            this->marks=marks;
        }
        void print() {
            cout <<"name is: "<< name << " the id is: " << id << "and the marks are: " << marks; 
            // Expected output: name is: <name> the id is: <id>and the marks are: <marks>
        }
};


class a{
    public:
    string name;
};
class b{
    public:
    int id;
};
class c:public a,public b{
    public:
    int marks;
    void setdata(string name,int id,int marks){
        this->name=name;
        this->id=id;
        this->marks=marks;
    }
    void print(){
        cout<<name<<" "<<marks<<" "<<id; // Expected output: <name> <marks> <id>
    }
};

// ---------------------------------------------------------
// virtual


// without using virtual(multiple-inheritance{diamond problem in the drawing i have explained refer it!!})
class maid{
    public:
    void show(){
        cout<<"base_case"; // Expected output: base_case
        cout << "\n";
    }
};
class none:public maid{
    public:
    void show(){
        cout<<"derived_case"; // Expected output: derived_case
        cout << "\n";
    }
};

// with using virtual
class maid1{
    public:
    virtual void show(){
        cout<<"base_case"; // Expected output: base_case
        cout << "\n";
    }
};
class none1:public maid1{
    public:
    void show() override{
        cout<<"derived_case"; // Expected output: derived_case
        cout << "\n";
    }
};



int main(){
    // OOPS is a way to build a software
    // class: is a datatype with function
    // object:varable of a class


    // MyClass p(412545454354);
    // p.print(); // Expected output: 412545454354

    // point p1,p2(10,20);
    // p1.print(); // Expected output: 0 0
    // p2.print(); // Expected output: 10 20
    // point *ptr=new point(10,60);
    // ptr->print(); // Expected output: 10 60
    // delete ptr;

    // MyMain m; // Expected output: parameterizes

    // login t1(10);
    // login t2(t1);
    // t2.set(20);
    // t1.print(); // Expected output: 20
    // t2.print(); // Expected output: 20

    // dest f; // Expected output: created it man (on creation), destory it man (on destruction)

    //  Student s1(5); // Expected output: Allocated memory for 5 subjects
    // (on destruction) Expected output: Memory freed

    // pointer p(1,2);
    // p.print(); // Expected output: 1 2
    // cout<<endl;
    // p.setx(10).sety(20).print(); // Expected output: 10 20

    // player p1;
    // cout<<p1.count<<endl; // Expected output: 1
    // {
    //     player p2;          
    //     cout<<player::count<<endl; // Expected output: 2
    // cout<<player::getcount()<<endl; // Expected output: 2
    // }
    // cout<<player::count<<endl; // Expected output: 1
    // cout<<player::getcount(); // Expected output: 1

// #pragma message("this is a messgae"); IMPORTANT

// teachers t1;
// t1.setdata("saikumar","1MV23CS133",45);
// t1.print(); // Expected output: name is: saikumar the id is: 1MV23CS133and the marks are: 45

// c d;
// d.setdata("saikumar",48556,100);
// d.print(); // Expected output: saikumar 100 48556

maid *b;
none d;
b=&d;
b->show(); // Expected output: Base_case

maid1 *b1;
none1 d1;
b1=&d1;
b1->show(); // Expected output: derived_case

    return 0;
}