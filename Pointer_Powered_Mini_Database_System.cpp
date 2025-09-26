#include <bits/stdc++.h>
using namespace std;

struct record{
    int id;
    int marks;
    string name;
};

class Database{
    record* data;
    int size;
    int capacity;
    public:
        Database(int initialcapacity=(size_t)2);
        ~Database();

        void insert(const record &r);
        bool removed(int id);
        record* findat(int id);
        void display() const;
};

Database::Database(int initialcapacity)
    : data(new record[initialcapacity]), size(0), capacity(initialcapacity) {}

Database::~Database(){
    delete[] data;
    data=nullptr;
}

void Database::insert(const record &r)
{
    if(size==capacity){
        int newcap=capacity*2;
        record* newdata=new record[newcap];
    
    for(int i=0;i<size;i++){
        *(newdata+i)=*(data+i); //newdata[i]=data[i];
    }
    delete[] data;
    data=newdata;
    capacity=newcap;
    }
    data[size]=r;     //data[size]=r;
    size++;
}

bool Database::removed(int id){
    int idx=-1;
    for(int i=0;i<size;i++){
        if(data[i].id==id){
            idx=i;
            cout<<"deleted:"<<idx<<endl;
            break;
        }
    }

    if(idx==-1)return false;

    for(int i=idx;i<size;i++){        //if data is found delete it and shift other data to left
        data[i]=data[i+1];
    }
    size--;
    return true;
}

record* Database::findat(int id){
    for(record *p=data;p<data+size;p++){
        if(p->id==id)return p;
    }
    return nullptr;
}

void Database::display() const{
    cout<<"DB size="<<size<<",capacity="<<capacity<<endl;
    for(const record* p=data;p<size+data;p++){
        cout<<"Id: "<<p->id<<"| Marks:"<<p->marks<<"| Name:"<<p->name<<endl;
    }
    // for(int i=0;i<size;i++){
    // cout << "id: " << data[i].id << " | name: " << data[i].name << " | marks: " << data[i].marks << endl;
// }W
}

int main(){
    int capaacity;
    cout<<"enter the capacity you want: ";cin>>capaacity;
    Database db(capaacity);
    while(true){
        cout<<"\n1) Insert  2) Delete by id  3) Find by id  4) Display  5) Exit\nChoose: ";
        int op;
        if(!(cin>>op))break;
        if(op==1){
            record r;
            cout<<"id:";cin>>r.id;
            cin.ignore();
            cout<<"name:";getline(cin,r.name);
            cout<<"marks:";cin>>r.marks;
            db.insert(r);
            cout<<"inserted succesfully\n";
        }else if(op==2){
            int id;cout<<"id to delete:";cin>>id;
            if(db.removed(id))cout<<"deleted succesfully\n";
            else cout<<"not foound\n";
        }else if(op==3){
            int id;cout<<"id to find:";cin>>id;
            record *p=db.findat(id);
            if(p){
                cout<<"Found--id:"<<p->id<<"| name:"<<p->name<<"| marks:"<<p->marks<<endl;
            }else cout<<"Not found\n";
        }else if(op==4){
            db.display();
        }else break;
    }
    cout<<"BYE"<<endl;
    return 0;
}