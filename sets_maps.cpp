#include <bits/stdc++.h>
using namespace std;
# define ABC 1      //just used as define
int main(){
    //sets are use to store sorted data and it works on red black tree internally
    //uniqe data
    cout<<ABC<<"--its just about define"<<endl;
    set<int>s;
    s.insert(30);
    s.insert(20);
    s.insert(10);
    s.insert(50);
    s.insert(50);       //ignore the duplicate value
    for(int num:s)cout<<num<<" ";       //10 20 30 50
    cout<<endl;
    auto it=s.find(10);
    if(it==s.end()){
        cout<<"not foound\n";   
    }else{
        cout<<*it<<endl;        //10
    }
    // s.erase(50);// can also use iterator to find it and then erase it auto it=s.find(50) s.erase(it)
    // auto it1=s.find(20);    
    s.erase(s.find(20),s.end());           // points to 20 and delete everything after it!
    for(int num:s)cout<<num<<" ";             //10
    cout<<endl;
    s.clear();                  //removes everything
    cout<<s.size()<<endl;       //0
    s.insert(20);
    s.insert(10);
    for(int num:s)cout<<num<<" "; // 10 20 20
    cout<<endl;
    s.emplace_hint(s.begin(),5);
    for(int num:s)cout<<num<<" "; // 5 10  20 20
    auto it2=s.lower_bound(15);     //lowerbound only works correclty in asc only 
    cout<<*it2<<endl;
    auto it3=s.upper_bound(20);     //index 2 (points to end).
    cout<<*it3<<endl;

    //floor --> largest value, smaller than or equal than x
    //celing -->smallest value, larger than or equal than x
     multiset<int>ms;
     ms.insert(1);
     ms.insert(1);
     ms.insert(2);
     ms.insert(2);
     for(int num:ms)cout<<num<<" ";         //1 1 2 2
     cout<<endl;
     ms.erase(1);
     for(int num:ms)cout<<num<<" ";         //2 2
     ms.insert(1);
     ms.insert(1);
     cout<<endl;
     cout<<ms.count(2);         //2
     cout<<endl;
    auto it4=ms.equal_range(2);
    cout<<(*it4.first)<<" "<<(*it4.second)<<endl;       //1 2

    //-----------------------------unordered_set---------------------------------
    //it uses hashing internally man!  so all function takes the time of O(1)
    cout<<"-----------------unordered-set-----------------------"<<endl;
    unordered_set<int>uset;
    uset.insert(10);
    uset.insert(20);
    uset.insert(40);
    for(int num:uset)cout<<num<<" ";
    cout << "\n";
    cout<<*(uset.find(10))<<endl;  //10     //resutlt like 1(true) or 0(false)
    cout<<uset.count(0)<<endl;     //0         //resutlt like 1(true) or 0(false)
    uset.erase(10);                 //another way is by iterator man
    // uset.erase(uset.begin(),uset.end());        //to remove all
    for(int num:uset)cout<<num<<" ";

    //see bro i have a short trick to check if the element is present and if not present then if(s.find(num)==s.end()) and to check the element should be present in the set    if(s.find(num)!=s.end())

    //to print the duplicates values just do this
    // for(int num:arr){
    //     if(s.find(num)==s.end()){            //no !s.find() but !s.count() for not found 
    //         s.insert(num);
    //     }else{
    //         cout<<num<<' ';
    //     }
    // }
    //maximum types of elements in a list can be done by d>=n/k return n/k else d

    //longest sequence
    //  unordered_set<int> s(nums.begin(), nums.end()); 
    // int res = 0;
    // for (int num : nums) {
    //     if (!s.count(num - 1)) {
    //         int curr = 1;
    //         int next = num + 1;
    //         while (s.count(next)) {
    //             curr++;
    //             next++;
    //         }
    //         res = max(res, curr);
    //     }
    // }
    // return res;




    //----------------------------------------maps--------------------------------------
    // both use red black tree 
    //both use to store value but maps use key-value pairs
    cout<<endl;
    cout<<"-------------maps-----------"<<endl;
    map<int,int>map;
    map.insert({100,100});
    map[5]=100;
    map.insert(make_pair(10,10));
    map.insert(make_pair(10,80));       //if the key already exist then it will get ignore and the before value will be executed!
    map[60];            //if we dont provide the value but provide the key then the default value is 0 and key is stored
    map[20]=10000;          //can update the value
    map.at(20)=2099;        //can also this can be used man best for the insert case man!!
    for(auto &num:map){
        cout<<num.first<<' '<<num.second<<endl;     //5 100     10 10   20 2099      60 0    100 100    
    }
    cout<<map.size()<<"-size"; //map size       
    cout << "\n";

    if(map.find(10)!=map.end()){        //map only searches for the key not the value
        cout<<"ya found man in find"<<endl;     //output
    }else{
        cout<<"ya not found!"<<endl;
    }
    //map and set doesnot allow duplicates so count only returns 1(present) or 0(false)
    if(map.count(10)==0){
        cout<<"not found\n";
    }else{
        cout<<"found yeah in count\n";      //output
    }

    auto it_map=map.lower_bound(30);
    if(it_map!=map.end()){
        cout<<(*it_map).first<<" "<<it_map->second<<endl;           //60 0
    }else{
        cout<<"not found\n";
    }
    auto it_map1=map.upper_bound(60);       
    cout<<it_map1->first<<" "<<it_map1->second<<endl;           //100   100

    // auto it_map3=map.find(10);
    // map.erase(it_map3);
    map.erase(map.find(10));
    for(auto &num:map){
        cout<<num.first<<' '<<num.second<<endl;     //5 100     20 2099      60 0    100 100    
    }

    //practial usage of maps in day to day life can be seen in grocier or shopping apps where filter can be sorted in high->low or low->high  or hih->low(with prrice range) vise-versa
    multimap<int,int>mps;
    cout<<"----multimaps--------------\n";
    mps.insert({10,20});
    mps.insert({5,20});
    mps.insert({10,30});
    for(auto &num:mps){
        cout<<num.first<<' '<<num.second<<endl;    //5 20       10 20       10 30
    }
    cout<<mps.count(10)<<endl;      //2
    cout<<mps.erase(10)<<endl;      //deletes every key value of this pair
    for(auto &num:mps){
        cout<<num.first<<' '<<num.second<<endl;    //5 20       
    }
    cout<<mps.count(10)<<endl;      //0
    //to get all the dupplicate key value pair just use the equal_range as lowerbound__upperboound

    cout<<"-----unordered_maps--------"<<endl;
    //based on hashing not on red black tree man!!
    //similar to unordered_set its time is almost equal O(1)
    //it has everything same as the map but in random values excuattion
    //application-balance like app for wallet apps(balance,userid)
    
    
    return 0;

}