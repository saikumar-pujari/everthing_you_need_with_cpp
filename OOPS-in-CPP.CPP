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
        cout<<x;
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
        cout<<x<<" "<<y<<endl;
    }
};

class test{
    
    public:
    int x;
        test(){
            cout<<"default\n";
        }
        test(int x){
            cout<<"parameterizes\n";
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
            cout<<*ptr<<endl;
        }


};

// ------

class dest{
    public:
    dest(){
        cout<<"created it man"<<endl;
    }
    ~dest(){                            //destructor is called if the value is out of scope man 
        cout<<"destory it man";
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
        cout << "Allocated memory for " << n << " subjects" << endl;
    }

    // destructor
    ~Student() {
        delete[] marks;  // free memory when object is destroyed
        cout << "Memory freed" << endl;
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
        cout<<x<<" "<<y<<endl;
       }

};

// ---------------------------------------------------------------------------------------------------
// static members and functions


class player{
    public:
    static int count;
    player(){count++;};
    ~player(){count--;};
    static int getcount(){return count;}
};
int player::count=0;              //import  //static-members should be defined outside the class or compiler will thorw an error man


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
        cout<<name<<" "<<marks<<" "<<id;
    }
};

// ---------------------------------------------------------
// virtual


// without using virtual(multiple-inheritance{diamond problem in the drawing i have explained refer it!!})
class maid{
    public:
    void show(){
        cout<<"base_case";
        cout << "\n";
    }
};
class none:public maid{
    public:
    void show(){
        cout<<"derived_case";           //even though we called the derived class but the base class will be excuted cuz both point at a same direction.
        cout << "\n";
    }
};

// with using virtual
class maid1{
    public:
    virtual void show(){
        cout<<"base_case";
        cout << "\n";
    }
};
class none1:public maid1{
    public:
    void show(){
        cout<<"derived_case";           //by using virtual we can know that they both to a same direction and we need the derived one not the
        cout << "\n";
    }
};



int main(){
    // OOPS is a way to build a software
    // class: is a datatype with function
    // object:varable of a class


    // MyClass p(412545454354);
    // p.print();


    // point p1,p2(10,20);
    // p1.print();
    // p2.print();
    // point *ptr=new point(10,60);
    // ptr->print();
    // delete ptr;

    // MyMain m;

    // login t1(10);
    // login t2(t1);
    // t2.set(20);
    // t1.print();
    // t2.print();

    // dest f;


    //  Student s1(5);
    
    // pointer p(1,2);
    // p.print();
    // cout<<endl;
    // p.setx(10).sety(20).print();            //chaining of functions to be perform in the outgrowth of the func


    // player p1;
    // cout<<p1.count<<endl;
    // {
        //  player p2;          
    // cout<<player::count<<endl;          //the recommened way to access the static value is by assing it from the class
    // }
    // cout<<player::count<<endl;
    // cout<<player::getcount();

// #pragma message("this is a messgae"); IMPORTANT
    

// teachers t1;
// t1.setdata("saikumar","1MV23CS133",45);
// t1.print();

// c d;
// d.setdata("saikumar",48556,100);
// d.print();


// maid *b;
// none d;
// b=&d;
// b->show();

// maid1 *b1;
// none1 d1;
// b1=&d1;
// b1->show();

    return 0;
}