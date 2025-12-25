#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
     
    node(int data){
        this->data=data;
        left=right=nullptr;
    }
};
int idx=-1;
node* buildtree(vector<int>&preoreder){
    idx++;
    if(preoreder[idx]==-1)return nullptr;
    node* root=new node(preoreder[idx]);
    root->left=buildtree(preoreder);    //left child
    root->right=buildtree(preoreder);   //right child
    return root;
}

//--------------------------------------------------------------------------------------------------------------
//travsersal order->preorder,inorder,postorder

//preorder traversal
void preordertravsersal(node* root){
    if(root==nullptr)return;
    cout<<root->data<<"->";
    preordertravsersal(root->left);
    preordertravsersal(root->right);
}

//inorder travsersal
void inordertravsersal(node* root){
    if(root==nullptr)return;
    inordertravsersal(root->left);
    cout<<root->data<<"->";
    inordertravsersal(root->right);
}

//postorder travsersal
void postordertraversal(node* root){
    if(root==nullptr)return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<"->";
}

//level order travsersal(iteravtive)--print the values level wise it has 2 way -BFS and -DFS
//dfs are like preorder,inorder and postorder approch manner
//bfs are like level order approch

//level-order
void levelordertravsersal(node* root){
    queue<node*>q;
    q.push(root);
    while(q.size()>0){
        node* curr=q.front();
        cout<<curr->data<<"->";
        q.pop();
        if(curr->left!=nullptr)q.push(curr->left);
        if(curr->right!=nullptr)q.push(curr->right);
    }
}
//=======================================================================================================================
//utility func
int ans=0;
//height of a tree
int height(node* root){
    if(root==nullptr)return 0;
    ans=max(ans,height(root->left)+height(root->right));
    return max(height(root->left),height(root->right))+1;
}
//see bro i will basically tell you how it works ok see if we take the root as 1 and 2 as left-node for root then the 2 will act as root now and check for its left if nullptr check right if its nnullptr return max(left,right) in this case is 0 and add 1 to it so 1 is the height for 2 and same do for the root-right side 3 and check its left and right side if exist check them to!
 
//count the no of nodes
int count(node* root){
    if(root==nullptr)return 0;
    return count(root->left)+count(root->right)+1;
}

//search for a value
int search(node* root,int key){
    if(root==nullptr)return 0;      //see man onces we travser this any side and not found make it false
    if(root->data==key)return 1;
    return search(root->left,key)||search(root->right,key);
}

//sum of all nodes
int sum(node* root){
    if(root==nullptr)return 0;
    return sum(root->left)+sum(root->right)+root->data;
}

//identical binary tree(leetcode 100)
bool isidentical(node* root,node* root1){
    if(root==nullptr||root1==nullptr)return root==root1;
    return isidentical(root->left,root1->left)&&isidentical(root->right,root1->right)&&root->data==root1->data;
}

//sub-tree(leetcode 572)
bool subtree(node* root,node* root1){
    if(root==nullptr||root1==nullptr)return root==root1;
    if(root->data==root1->data&&isidentical(root,root1))return true;
    return subtree(root->left,root1)|subtree(root->right,root1);
}

//diameter(leetcode 543)
// int diameter(node* root){    //O(n*n-for height)
//     if(root==nullptr)return 0;
//     int left=diameter(root->left);
//     int right=diameter(root->right);
//     int currDiameter=height(root->left)+height(root->right);
//     return max({left,right,currDiameter});
// }
// int ans=0; //sorry man its should be assigned above the height func!
int diameter(node* root){   //O(n)
    return ans;         //idoit go and check the height code
}

//top-view ising the level order based man!!
void topview(node* root){
    queue<pair<node*,int>>q;
    map<int,int>map;
    q.push({root,0});
    while(q.size()>0){
        node* curr=q.front().first;
        int currvalue=q.front().second;
        if(map.find(currvalue)==map.end())map[currvalue]=curr->data;
        q.pop();
        if(curr->left!=nullptr)q.push({curr->left,currvalue-1});
        if(curr->right!=nullptr)q.push({curr->right,currvalue+1});
    }
    for(auto& it:map)cout<<it.second<<"->";
}
//bootom view
void bootomview(node* root){
    map<int,int>map;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        node* curr=q.front().first;
        int value=q.front().second;
        q.pop();
        map[value]=curr->data;
        if(curr->left!=nullptr)q.push(make_pair(curr->left,value-1));
        if(curr->right!=nullptr)q.push(make_pair(curr->right,value+1));
    }
    for(auto& it:map)cout<<it.second<<"->";
}
//right-side view
void rightsideview(node* root){
    if(root==nullptr)return;
    vector<int>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* curr=q.front();
            q.pop();
            if(i==size-1)ans.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    for(int num:ans)cout<<num<<"->";
}
//left-view
void leftsideview(node* root){
    if(root==nullptr)return;
    vector<int>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* curr=q.front();
            q.pop();
            if(i==0)ans.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    for(int num:ans)cout<<num<<"->";
}
//kth level 
void kthlevel(node* root,int k){
    if(root==nullptr)return ;
    if(k==1){
        cout<<root->data<<"->";
        return;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}

//lowest common ancestors(leetcode 236)
//a node can be ancestor of itself and p!=q
node* LCA(node* root,node* p,node* q){
    if(root==nullptr)return nullptr;
    if(root==p|root==q)return root;
    node* left=LCA(root->left,p,q);
    node* right=LCA(root->right,p,q);
    if(left&&right)return root;
    else if(!left)return left;
    else return right;
}


//symmetric(leetcode 101)
bool ismirror(node* root,node* root1){
    if(!root&&!root1)return true;
    if(!root|!root1)return false;
    return root->data==root1->data&&
    ismirror(root->left,root1->right)&&
    ismirror(root->right,root1->left);
}

bool symmetric(node* root){
    if(root==nullptr)return false;
    return ismirror(root->left,root->right);
}


//======================================================================================================================================
//construct a tree from preorder travsersal (root,left,right) and inorder(left,root,right)
//see bro basically the IMP thing is that from prorder we will know the root value and from the inorder we will know the left-root value so ya then build it recursively accordingly!
// leetcode 105

//transform a normal to sum tree
int sumtree(node* root){
    if(root==nullptr)return 0;
    return root->data+sumtree(root->left)+sumtree(root->right);
}

//binary paths(leetcode 257)
void helperbinary(node* root,string path,vector<string>&ans){
    if(root->left==nullptr&&root->right==nullptr){
        ans.push_back(path+"\n");
        return;
    }
    if(root->left){
        helperbinary(root->left,path+"->"+to_string(root->left->data),ans);
    }
    if(root->right){
        helperbinary(root->right,path+"->"+to_string(root->right->data),ans);
    }
}

void allpath(node* root){
    vector<string>ans;
    string path=to_string(root->data);
    helperbinary(root,path,ans);
    for(string s:ans){
        cout<<s;
    }
}

//maximum width 
int width(node* root){
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int first=q.front().second;
        int last=q.back().second;
        maxi=max(maxi,last-first+1);
        for(int i=0;i<size;i++){
            node* curr=q.front().first;
            int idx=q.front().second;
            q.pop();
            if(curr->left!=nullptr)q.push({curr->left,2*idx+1});
            if(curr->right!=nullptr)q.push({curr->right,2*idx+2});
        }
    }
    return maxi;
}

//morris inorder traversal(ALGORITHM) using iterations
void morrisinorder(node* root){
    vector<int>ans;
    node* curr=root;
    while(curr!=nullptr){
       if(curr->left==nullptr){
         ans.push_back(curr->data);
         curr=curr->right;
       }else{
        node* ip=curr->left;
        while(ip->right!=nullptr&&ip->right!=curr){
            ip=ip->right;
        }
        if(ip->right==nullptr){
            ip->right=curr;
            curr=curr->left;
        }else{
            ip->right=nullptr;
            ans.push_back(curr->data);
            curr=curr->right;
        }
       }
    }
    for(int num:ans)cout<<num<<"->";
}

//flatten tree into linked list
// node* nextright=nullptr;
// void flateen(node* root){
//     if(root==nullptr)return;
//     flateen(root->right);
//     flateen(root->left);
//     root->left=nullptr;
//     root->right=nextright;
//     nextright=root;
// }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);   

    // tree is from where the data are stored in hireercial way other DS are linear
    // user-->guest
    //     |__sai----->local data
    //         |_______>online data
    // in tree we only work for binary tree so recursion and backtracking is mainly used!!

    // binary tree is seen as nodes normally the tree start from parent and goes till the roots
    

    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root=buildtree(preorder);
    cout<<"the root value is "<<root->data<<endl;
    cout<<"the left root value is:"<<root->left->data<<endl;
    cout<<"the right root value is:"<<root->right->data<<endl;
    // cout<<root->left->left->data<<endl;  //see the down comment!
    // cout<<root->left->right->data<<endl; //bro see its a nullptr so it doesnot print anything
    cout<<"the right root left value is:"<<root->right->left->data<<endl;
    cout<<"the right root right value is:"<<root->right->right->data<<endl;
    cout<<"preorder traversal:";
    preordertravsersal(root);
    cout << "\n";
    cout<<"inorder traversal:";
    inordertravsersal(root);
    cout << "\n";
    cout<<"postorder traversal:";
    postordertraversal(root);
    cout << "\n";
    cout<<"level order traversal:";
    levelordertravsersal(root);
    cout << "\n";
    cout<<"the height of the tree "<<height(root)<<endl;
    cout<<"the count of the tree "<<count(root)<<endl;
    cout<<"the serach value here is"<<search(root,9)<<endl;
    cout<<"the sum of the all the nodes in the tree:"<<sum(root)<<endl;
    cout<<"the given tree is identical:"<<isidentical(root,root)<<endl;
    cout<<"is the tree a subtree"<<subtree(root,root)<<endl;
    cout<<"the diameter of a tree is"<<diameter(root)<<endl;
    cout<<"the top view of a tree:";
    topview(root);
    cout << "\n";
    cout<<"the bottom view is:";
    bootomview(root);
    cout << "\n";
    cout<<"the right view is:";
    rightsideview(root);
    cout << "\n";
    cout<<"the left view is:";
    leftsideview(root);
    cout << "\n";
    cout<<"the kth level of elements in the tree:";
    kthlevel(root,2);
    cout << "\n";
    cout<<"is the tree symmetric:"<<symmetric(root)<<endl;
    cout<<"the sumtree value is: "<<sumtree(root)<<endl;
    cout<<"the binary tree path are:-";
    allpath(root);
    cout << "\n";
    cout<<"the width is: "<<width(root)<<endl;
    cout<<"morris inorder:";
    morrisinorder(root);
    cout << "\n";
    // cout<<"flateen the tree: ";
    // flateen(root);
    
    return 0;
}