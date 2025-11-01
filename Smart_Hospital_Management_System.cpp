#include <bits/stdc++.h>
using namespace std;

class person{
    protected:
        string name;
        int age;
    public:
        person():name(""),age(){};
        person(const string& name,int age):name(name),age(age){};
        virtual void display() const{ 
            cout<<"Name: "<<name<<"| Age:"<<age<<endl;
        }
};

class patient:public person{
    int patientid;
    public:
        patient():person(),patientid(0){}
        patient(const string& name,int age,int patientid):person(name,age),patientid(patientid){}
        void display() const override{
            cout<<"patientid:"<<patientid<<endl;
        }
        int getid()const {return patientid;}

};

class doctor:public person{
    int doctorid;
    public:
        doctor():person(),doctorid(0){}
        doctor(const string& name,int age,int doctorid):person(name,age),doctorid(doctorid){}
        void display() const override{
            cout<<"doctorID:"<<doctorid<<endl;
        }
        int getid()const {return doctorid;}
};




struct patinetnode{
    patient data;
    patinetnode* next;
    patinetnode(const patient& p):data(p),next(nullptr){}
};

void insertpatientsnode(patinetnode*& head,const patient& p){
    patinetnode* newnode=new patinetnode(p);
    if(head==nullptr){
        head=newnode;
        return;
    }
    patinetnode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}

void displaypatients(patinetnode* head){
    patinetnode* temp=head;
    while(temp!=nullptr){
        temp->data.display();
        temp=temp->next;
    }
}

bool deletenode(patinetnode* head,int id){
    patinetnode*temp=head;
    patinetnode*prev=nullptr;
    while(temp!=nullptr){
        if(temp->data.getid()==id){
            if(prev==nullptr){
                head=head->next;
            }else{
                prev->next=temp->next;
            }
            delete temp;
            cout<<"deleted the patient:"<<temp->data.getid()<<endl;
            return true;
        }
        prev=temp;
        temp=temp->next;
    }
    return false;
}






struct patientnodesp{
    patient data;
    shared_ptr<patientnodesp>next;
    patientnodesp(const patient& p):data(p),next(nullptr){}
};

void insertpatientsp(shared_ptr<patientnodesp>& head,const patient& p){
    shared_ptr<patientnodesp>newnode=make_shared<patientnodesp>(p);
    if(!head){
        head=newnode;
        return;
    }
    shared_ptr<patientnodesp>temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
}
void display(shared_ptr<patientnodesp>& head){
       shared_ptr<patientnodesp>temp=head;
    while(temp){
        temp->data.display();
        temp=temp->next;
    }
}

bool deletePatientNodeSP(std::shared_ptr<patientnodesp>& head, int id) {
    if (!head) return false;
    if (head->data.getid() == id) {
        head = head->next;  
        cout<<"deleted succesfully\n";
        return true;
    }

    std::shared_ptr<patientnodesp> prev = head;
    std::shared_ptr<patientnodesp> curr = head->next;

    while (curr) {
        if (curr->data.getid() == id) {
            prev->next = curr->next; 
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}



template <typename T>
class RecordManager {
    struct Node {
        T data;
        shared_ptr<Node> next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    shared_ptr<Node> head;  // head of linked list

public:
    RecordManager() : head(nullptr) {}

    void insert(const T& record) {
        auto newNode = make_shared<Node>(record);
        if (!head) {
            head = newNode;
            return;
        }
        auto temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    bool remove(int id) {
        if (!head) return false;
        if (head->data.getid() == id) {
            head = head->next;  // old head auto-deleted
            return true;
        }
        auto prev = head;
        auto curr = head->next;
        while (curr) {
            if (curr->data.getId() == id) {
                prev->next = curr->next; // memory auto-freed
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    shared_ptr<T> find(int id) {
        auto temp = head;
        while (temp) {
            if (temp->data.getId() == id) return make_shared<T>(temp->data);
            temp = temp->next;
        }
        return nullptr;
    }

    void display() {
        auto temp = head;
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
    }
};






class Appointment {
protected:
    shared_ptr<patient> patientq;
    shared_ptr<doctor> doctorq;
    string date;
public:
    Appointment(shared_ptr<patient> p_, shared_ptr<doctor> d_, string dt_)
        : patientq(p_), doctorq(d_), date(dt_) {}

    virtual ~Appointment() {}  // virtual destructor (important for polymorphism)

    virtual void display() const {
        cout << "Appointment on " << date << ":\n";
        cout << "  Patient -> ";
        patientq->display();
        cout << "  Doctor -> ";
        doctorq->display();
    }
};
//if we want to accese it then we need by vector<shared_ptr<Appointment>>appointments;
class OnlineAppointment : public Appointment {
    string videoLink;
public:
    OnlineAppointment(shared_ptr<patient> p, shared_ptr<doctor> d, string dt, string link)
        : Appointment(p, d, dt), videoLink(link) {}

    void display() const override {
        Appointment::display();
        cout << "  [Online] Video Link: " << videoLink << "\n";
    }
};
class InPersonAppointment : public Appointment {
    string room;
public:
    InPersonAppointment(shared_ptr<patient> p, shared_ptr<doctor> d, string dt, string rm)
        : Appointment(p, d, dt), room(rm) {}

    void display() const override {
        Appointment::display();
        cout << "  [InPerson] Room: " << room << "\n";
    }
};


int main(){
    int patientcapacity=2;
    int patientcount=0;
    patient* patients=new patient[patientcapacity];

    int doctorcapacity=2;
    int doctorcount=0;
    doctor* doctors=new doctor[doctorcapacity];

    patients[patientcount++]=patient("saikumar",20,154);
    patients[patientcount++]=patient("sony",25,485);


    for(int i=0;i<patientcount;i++){
        patients[i].display();
    }

    doctors[doctorcount++]=doctor("satish",45,145);
    doctors[doctorcount++]=doctor("vignesh",63,456);

    for(int i=0;i<doctorcount;i++){
        doctors[i].display();
    }

    cout<<"\nthis is linkedList\n";

    patinetnode* patienthead=nullptr;
    for(int i=0; i<patientcount; i++) {
        insertpatientsnode(patienthead, patients[i]);
    }

    displaypatients(patienthead);

    deletenode(patienthead,485);

    displaypatients(patienthead);

    while(patienthead!=nullptr){
        patinetnode* temp=patienthead;
        patienthead=patienthead->next;
        delete temp;
    }
    cout<<"\nthis is smart pointers\n";
    
    shared_ptr<patientnodesp> patientheadsp = nullptr;
    for(int i=0;i<patientcount;i++){
        insertpatientsp(patientheadsp,patients[i]);
    }
    display(patientheadsp);
    deletePatientNodeSP(patientheadsp,154);
    display(patientheadsp);


    cout<<"\nthis is from Templates\n";
    RecordManager<patient>patientss;
    RecordManager<doctor>doctorss;
    for(int i=0;i<patientcount;i++){
        patientss.insert(patients[i]);
    }
    for(int i=0;i<doctorcount;i++){
        doctorss.insert(doctors[i]);
    }
    patientss.display();
    doctorss.display();
    patientss.remove(145);
    patientss.display();
    auto doc=doctorss.find(456);
    if(doc){
        cout<<"found";
    }else{
        cout<<"not found";
    }

    delete[] patients;
    delete[] doctors;
    return 0;
}