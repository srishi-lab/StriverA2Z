#include <iostream>
using namespace std;

// // creation of tree
// struct treenode{
//     int data;
//     struct treenode* left;
//     struct treenode* right;

//     // constructor
//     treenode(int val){
//         data= val; 
//         left = right = NULL;
//     }
//     treenode(int val, struct treenode*leftside , struct treenode* rightside){
//         data = val;
//         left = leftside;
//         right = rightside;
//     }
//     // void print(){
//     //       cout<<data<<" "<<left->data<<" "<<right->data<<endl;
//     // }

//     void print(){
//         cout<<data<<" ";
//         if(left != nullptr){
//             cout<<left->data<<" ";
//         }
//         else{
//             cout<<NULL<<" ";
//         }
//         if(right != nullptr){
//             cout<<right->data<<" ";
//         }
//         else{
//             cout<<NULL<<" ";
//         }
//         cout<<endl;
//     }

// };
// //   void print(struct treenode*root){
// //           cout<<root->data<<" "<<root->left<<" "<<root->right<<endl;
// //     }
// int main(){
//     // treenode *root = new treenode(1);
//     // root->print();
//     // // print(root);
//     // cout<<root->data<<" "<<root->left<<" "<<root->right;

//     treenode *root = new treenode(1);
//     // root->left = new treenode(2);
//     // root->right= new treenode(3);

//     treenode *l1= new treenode(2);
//     treenode *l2 = new treenode(3);
//     root->left = l1;
//     root->right = l2;

//     treenode *l3 = new treenode(4);
//     treenode *l4 = new treenode(5);
//     l1->left = l3;
//     l1->right = l4;

//     treenode* l5 = new treenode(6);
//     l2->left = l5;
//     treenode *l6 = new treenode(7);
//     l2->right = l6;

//     // root->left->left = new treenode(4);
//     // root->left->right = new treenode(5);

//     // root->right->left= new treenode(6);
//     // root->right->right= new treenode(7);

//     // root->print();
//     // root->left->print();
//     // root->right->print();
//     root->print();
//     l1->print();
//     l2->print();
//     l3->print();
//     l4->print();
//     l5->print();
//     l6->print();

// }

struct treenode{
    int data;
    struct treenode*left ,*right= nullptr;

    // constructor
    // treenode(int val){
    //     data=val;
    //     left= right= nullptr;
    // }
    treenode(int val, treenode *leftside = nullptr, treenode *rightside =nullptr){
        data= val;
        left = leftside;
        right = rightside;
    }


    void print(){
        cout<<data<<" ";
        (left != nullptr) ? cout<<left->data<<" " : cout<<NULL<<" ";
        (right != nullptr) ? cout<<right->data<<" " : cout<<NULL<<" ";
        cout<<endl;
    }

};
//  // level order tree creation through array

//     treenode* levelorder(vector<int> &a, int i){
//         if( i>= a.size() || a[i]== -1){
//             return nullptr;
//         }
//         treenode *node = new treenode(a[i]);
//         node->left =levelorder(a,2*i +1);
//         node->right= levelorder(a,2*i +2);
//         return node;
//     }

//     //level order input using queue
//     treenode* levelOrder(vector<int> &a){
//         if( a.empty() || a[0] == -1) return nullptr;
//         treenode *root = new treenode(a[0]);
//         queue<treenode*> q;
//         q.push(root);
//         int i=1;

//         while( !q.empty() && i< a.size()){
//             treenode *curr = q.front(); q.pop();
//             if(i< a.size() && a[i] != -1){
//                 curr->left = new treenode(a[i]);
//                 q.push(curr->left);
//             }
//             i++;
//             if( i< a.size() && a[i] != -1){
//                 curr->right= new treenode(a[i]);
//                 q.push(curr->right);
//             }
//             i++;
//         }
//         return root;

//     }


    // travelsal on trees
    // inorder using recursion
    void inorder(struct treenode* root){
        // base casee
        if(root== nullptr) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    // pre order 
    void preorder(struct treenode* root){
        // base case 
        if(root ==nullptr) return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(struct treenode* root){
        // base case
        if( root== nullptr) return ;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
// int main(){
//     treenode *root = new treenode(1, new treenode(2, new treenode(4), new treenode (5)), new treenode(3, new treenode(6), new treenode(7)));
//     cout<<" printing using print function"<<endl;
//     root->print();
//     root->left->print();
//     root->right->print();
//     root->left->left->print();
//     root->left->right->print();

// /* taking input from user for level order tree */
// vector<int> a(7);
// for(int i=0;i< a.size();i++){
//     cout<<"enter: ";
//     cin>>a[i];
// }
// treenode* root1 = levelorder(a,0);
// treenode* root2 = levelOrder(a);

// cout<<" in order printing "<<endl;
// inorder(root1);
// cout<<endl;
// inorder(root2);
// cout<<endl;

// cout<<"pre order printing "<<endl;
// preorder(root1);
// cout<<endl;
// preorder(root2);
// cout<<endl;

// cout<<"post order printing "<<endl;
// postorder(root1);
// cout<<endl;
// postorder(root2);
//    cout<<endl;
    

// }


//  ITERATIVE PRE ORDER TRAVERSAL

vector<int> Preorder(struct treenode* root){
    stack<treenode*> st;
    vector<int> preordered;
    st.push(root);
    while( !st.empty()){
        root =st.top(); st.pop();
        preordered.push_back(root->data);

        if(root->right != nullptr) {
            st.push(root->right);
        }
        if(root->left != nullptr){
            st.push(root->left);
        }
    }
    return preordered;
}

// ITERATIVE INORDER TRAVERSAL 

vector<int> Inorder(struct treenode* root){
    stack<treenode*> st;
    vector<int> inorder;
    treenode* node= root;
    while(true){
        if(node != NULL){
            st.push(node);
            node= node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node= node->right;  
        }
    }
    return inorder;

}

// ITERATIVE TRAVERSAL OF POST ORDER TREES
vector<int> Postorder(struct treenode* root){
    vector<int> postorder;
    stack<treenode*> s1,s2;
    s1.push(root);
    while( !s1.empty()){
        root= s1.top();
        s2.push(root);
        s1.pop();
        if(root->left !=nullptr){
            s1.push(root->left);
        }
        if(root->right != nullptr){
            s1.push(root->right);
        }

        while( !s2.empty()){
            postorder.push_back(s2.top()->data);
            s2.pop();
        }
    }
    return postorder;

}

// PRE IN AND POST ALL IN ONE TRAVERSAL
vector<vector<int>> megatraversal(struct treenode* root){
   vector<vector<int>> answer;
    vector<int> inorder,postorder,preorder;
    
    stack<pair<treenode*,int>> st;
    st.push({root,1});
 
    if (root==NULL) return answer;

    while( !st.empty()){
       auto it= st.top();
       st.pop();

    if(it.second == 1){
        preorder.push_back(it.first->data);
        it.second++;
        st.push(it);

        if(it.first->left !=nullptr){
            st.push({it.first->left,1});
        }
    }
    else if(it.second== 2){
        inorder.push_back(it.first->data);
        it.second++;
        st.push(it);

        if(it.first->right !=nullptr){
            st.push({it.first->right,1});
        }
    }
    else{
        postorder.push_back(it.first->data);
    }
    }
     answer.push_back(preorder);
    answer.push_back(inorder);
    answer.push_back(postorder);
   
    return answer;
   
}

// MAXIMUM DEPTH OF TREE
// by using recursion 

int maxdepth(struct treenode*root){
    // base case
    if(root==nullptr){
        return 0;
    }
    int lh= maxdepth(root->left);
    int rh= maxdepth(root->right);
    return 1+ max(lh,rh);
}

// FINDING HEIGHT BY USING ITERATIVE LEVEL ORDER APPROACH
// key = no of levels = no of height
int height(struct treenode* root){
    queue<treenode*> q;
    treenode* node= root;
    q.push(node);
    int height= 0;
  
    while( !q.empty()) { 
        int size= q.size();
        for(int i=0; i<size;i++){
        node =q.front(); q.pop();
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);

    }
        height++;
    }
    return height;
}

//  BALANCE BINARY TREE CHECKING
bool isbalance(struct treenode* root){
    // base case 
    if(root==nullptr) return true;

    int lh= height(root->left);
    int rh= height(root->right);

    if(abs(!(lh-rh)<=1)) return false;

    bool leftside = isbalance(root->left);
    bool rightside = isbalance(root->right);

    if( !leftside || !rightside) return false;

    return true;
}


// DIAMETER OF BINARY TREE (LONGEST PATH BW TWO NODES)
// taking one node and its total height left height + right height will be diameter assuming that node is somewhere on path curve 

int diameter (struct treenode* root, int &maxi){
    // base case 
    if(root == nullptr) return 0;

    int lh= height(root->left);
    int rh= height(root->right);

    maxi = max(maxi,(lh+rh));

    int leftside =diameter(root->left,maxi);
    int rightside =diameter(root->right,maxi);

    return maxi;
}

// BETTER APPROACH 
int diameteroftree(struct treenode*root){
    int diameter =0;
    heightt(root,diameter);
    return diameter;
}
int heightt(struct treenode*root, int& diameter){
    if(root==nullptr) return 0;

    int lh= heightt(root->left,diameter);
    int rh= heightt(root->right,diameter);

    diameter= max(diameter, lh+rh);
    return 1+ max(rh,lh);

}

//  MAXIMUM PATH SUM IN ANY BINARY TREE



int main(){
    treenode *root = new treenode(1, new treenode(2, new treenode(4, new treenode(8)), new treenode(5)), new treenode(3, new treenode(6), new treenode(7,nullptr, new treenode(9))));
//     // Preorder(root);
//     inorder(root);
//     cout<<endl;
//     preorder(root);
//     cout<<endl;
//     vector<int> a =Preorder(root);
//     for(int i= 0;i<a.size();i++){
//         cout<<a[i]<<" ";
//     }

//     vector<int> b= Inorder(root);
//     for(int i=0;i<b.size();i++){
//         cout<<b[i]<<" ";
//     }
 int num = maxdepth(root);
 int num1= height(root);
 cout<<num<<endl;
 cout<<num1;
}

