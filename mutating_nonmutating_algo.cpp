#include <bits/stdc++.h>
using namespace std;


// Non-Mutating Algorithms-->Don’t modify the original data (they just read and analyze it).
//Mutating Algorithms-->Modify or rearrange the data (they change the container or its elements).

int main(){
    // cout<<"---------nonmutating---------------\n";
    //find----except the set,map other all the containers use the find(l.begin(),l.end()) even the set can aslo use this but not recommeneded
    // vector<int>v{1,2,3,4,5};
    // auto it=find(v.begin(),v.end(),4);
    // cout<<*it<<" is the position\n";          //2
    // if(it==v.end()){
    //     cout<<"not found!\n";
    // }      
    // list<int>l{1,2,3,4,5};
    // auto it1=find(l.begin(),l.end(),3);
    // cout<<*it1<<endl;
    // set<int>l1{1,2,3,4,5};
    // auto it12=find(l1.begin(),l1.end(),3);
    // cout<<*it12<<endl;
    // cout<<*(l1.find(3))<<endl;

    //lower-bound
    //  vector<int>v1{1,2,3,4,6};
    //  auto it3=lower_bound(v1.begin(),v1.end(),5);
    //  cout<<*it3<<endl;
    //  set<int>l12{1,2,3,4,6};
    // auto it123=lower_bound(l12.begin(),l12.end(),5);
    // cout<<*it123<<endl;
    // cout<<*(l12.lower_bound(5))<<endl;
    // list<int>l2{1,2,3,4,6};
    // auto it15=lower_bound(l2.begin(),l2.end(),5);
    // cout<<*it15<<endl;

    //upper-bound
    //   vector<int>v0{1,2,3,4,6};
    //  auto it31=upper_bound(v0.begin(),v0.end(),4);
    //  cout<<*it31<<endl;
    //  set<int>l121{1,2,3,4,6};
    // auto it1234=upper_bound(l121.begin(),l121.end(),5);
    // cout<<*it1234<<endl;
    // cout<<*(l121.upper_bound(5))<<endl;
    // list<int>l21{1,2,3,4,6};
    // auto it151=upper_bound(l21.begin(),l21.end(),5);
    // cout<<*it151<<endl;
    //lower is helpfull to get the 1st number if duplicate exisits and upperbound the last element of the duplicate elements!

    //is_permutations---checks the elements in both should be same!
    // vector<int>pv{10,20,30,40};
    // vector<int>pv1{20,40,10,30};
    // if(is_permutation(pv.begin(),pv.end(),pv1.begin())){
    //     cout<<"ya\n";
    // }else   cout<<"na\n";

    //max-element&min-element
    // vector<int>v{10,20,30,40,50};
    // auto it=max_element(v.begin(),v.end());
    // auto it2=min_element(v.begin(),v.end());
    // cout<<*it<<" "<<*it2;
    
    //count
    // vector<int>v{10,20,30,40,50,10};
    // cout<<count(v.begin(),v.end(),10)<<endl;
    // string s="saikumar";
    // cout<<count(s.begin(),s.end(),'a');
    
    //binary-search(but the vector/array should be sorted array)
    // vector<int>v{10,20,30,40,50};
    // int x=10;
    // if(binary_search(v.begin(),v.end(),x)==true){
        //     cout<<"ya\n";
        // }
        
    //fill
    // vector<int>v{10,20,30,40,50};
    // fill(v.begin(),v.end(),5);
    // for(int num:v)cout<<num<<" ";
    
    
    //rotate
    // vector<int>v{10,20,30,40,50};
    // rotate(v.begin(),v.begin()+2,v.end());
    // for(int num:v)cout<<num<<" ";
    
    //accumlate
    // --add
    // vector<int>v{10,20,30,40,50};
    // int res=0;
    // cout<<accumulate(v.begin(),v.end(),res);
    // --sub
    // vector<int>v{10,20,30,40,50};
    // int res=100;
    // cout<<accumulate(v.begin(),v.end(),res,minus<int>());

    //rand
    // for(int i=0;i<5;i++)cout<<rand()<<" ";

    //for_each
    //   vector<int> v = {1, 2, 3, 4, 5};
    // cout << "Vector elements: ";
    // for_each(v.begin(), v.end(), [](int x){
    //     cout << x+1 << " ";
    // });

    //count_if
    //  vector<int> v = {1, 2, 3, 4, 5, 6};
    // int evens = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    // cout << "Even numbers in vector: " << evens;

    //all_of,none_of,any_of(boolapha is used to trun 1 to true or 0 to false)
    //  vector<int> v = {2, 4, 6};
    // cout << boolalpha;
    // cout << "All even? " << all_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << endl;
    // cout << "Any even? " << any_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << endl;
    // cout << "None even? " << none_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << endl;
    

    cout<<"--------------Mutating------------\n";
    //sort
    // vector<int> v = {1, 2, 4, 3, 5, 6};
    // sort(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";
    // sort(v.begin(),v.end(),greater<int>());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";
    

    //make_heap         //acces the lef child by 2i+1 and right child by 2i+2 and parents are[i+1/2]
    // vector<int> v = {1, 2, 4, 3, 5, 6};
    // make_heap(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";
    // make_heap(v.begin(),v.end(),greater<int>());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";       
    // pop_heap(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // push_heap(v.begin(),v.end());
    // cout << "\n";
    // for(int num:v)cout<<num<<" ";

    //merge
    // vector<int> v1 = {1, 2, 4, 3, 5, 6};
    // vector<int> v2 = {7,8,9,10,11,12};
    // vector<int>v3(12);
    // merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    // for(int num:v3)cout<<num<<" ";
    
    //next_pemutations
    // vector<int> v = {1, 2, 4, 3, 5, 6};
    // next_permutation(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";

    //reverse
    // vector<int> v = {1, 2, 4, 3, 5, 6};
    // reverse(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";

    //prev_permuataions
    // vector<int> v = {1, 2, 4, 3, 5, 6};
    // prev_permutation(v.begin(),v.end());
    // for(int num:v)cout<<num<<" ";
    // cout << "\n";
    return 0;
}