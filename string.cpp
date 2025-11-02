#include <bits/stdc++.h>
using namespace std;

int main(){
    // string starts drom 65-90 and small from 97-122
    // char s[]="gfg",s2[]={'g','g','g'};
    // cout<<strlen(s)<<endl; // Example: 3.
    // cout<<strcmp(s,s2)<<endl;  //only give s 0,1,-1 // Example: -1
    // int res=strcmp(s,s2);
    // if(res>0){
    //     cout<<"s is greater"; // Example: s is greater
    // }else if(res==0){
    //     cout<<"equal"; // Example: equal
    // }else{
    //     cout<<"s2 is bigger"; // Example: s2 is bigger(actual output)
    // }

    // char str[3];
    // // str="gfg";   //not allowed
    // strcpy(str,"hfh");
    // cout<<str; // Example: hfh

    //.find in string (if not prsent then ::npos)

    //getline is used untill the user enter the enter  button
    // string name;
    // cin>>name;
    // cout<<"your name is "<<name;  //after the space its not gonna print // Example: your name is saikumar
    
    // string name;
    // getline(cin,name);   //will print the value after the space
    // cout<<"your name is "<<name; // Example: your name is saikumar pujari

    // string name="saikumar";
    // for(char x:name){
    //     cout<<x<<" "; // Example: s a i k u m a r 
    // }

    // string name="saikumar";
    // int last=name.size()-1;
    // string rev="";
    // while( last>=0){
    //     rev+=name[last--];
    // }
    // cout<<rev; // Example: ramukias

    // string name="1001";
    // int base=1;
    // int ans=0;
    // int size=name.size();
    // for(int i=size-1;i>=0;i--){
    //     ans=ans+((int)name[i]-'0')*base;
    //     base*=2;
    // }
    // cout<<ans; // Example: 9

    // Expected Output:
    // strlen(s) -> 3
    // strcmp(s, s2) -> 0
    // s is greater / equal / s2 is bigger (based on strcmp result)
    // strcpy(str, "hfh") -> hfh
    // cin>>name; cout<<"your name is "<<name; -> prints name until first space
    // getline(cin, name); cout<<"your name is "<<name; -> prints full line including spaces
    // for(char x:name) -> prints each character separated by space: s a i k u m a r 
    // reverse string -> ramukias
    // binary string "1001" to int -> 9

    return 0;
}