#include <bits/stdc++.h>
using namespace std;


class page{
    public:
    string url;
    page* next;
    // page* prev;
    page(string url){
        this->url=url;
        next=nullptr;
    }
};
class BrowserHistory {
public:
    page* head;

    BrowserHistory() {
        head = nullptr;
    }
    void visitpage(string url){
        page* newpage=new page(url);
        if(head==NULL||head->next==nullptr){
            head=newpage;
            return;
        }
        page* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newpage;
    }
    void showhistory(){
        page* temp=head;
        if(head==nullptr){
            cout<<"NO HISTORYY!!\n";
            return;
        }
        cout<<"Browsing History:";
        while(temp!=nullptr){
            cout<<temp->url<<"->";
            temp=temp->next;
        }
    }
    void deletepage(string url){
        if(head==nullptr){
            cout<<"history is empty\n";
            return;
        }
        if(head->url==url){
            page* todelete=head;
            head=head->next;
            delete todelete;
            cout<<"Deleted:"<<url<<endl;
            return;
        }
        
        page* temp=head;
        while(temp->next&&temp->next->url!=url){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            cout<<"Page Not Found";
            return;
        }
        page* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        cout<<"Deleted:"<<url<<endl;
    }
    void clearhistory(){
        page* temp=head;
        while(temp!=nullptr){
            page* nextpage=temp->next;
            delete temp;
            temp=nextpage;
        }
        head=nullptr;
        cout<<"History Cleared :) ";
    }
};


int main(){
      BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "\n--- Browser History ---\n";
        cout << "1. Visit Page\n2. Show History\n3. Delete Page\n4. Clear All History\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.visitpage(url);
            break;

        case 2:
            browser.showhistory();
            break;

        case 3:
            cout << "Enter URL to delete: ";
            cin >> url;
            browser.deletepage(url);
            break;

        case 4:
            browser.clearhistory();
            break;

        case 0:
            cout << "Exiting browser...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);


    return 0;
}