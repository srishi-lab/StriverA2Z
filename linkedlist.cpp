#include <iostream>
using namespace std;
/*
// SINGLE LINKED LIST 
// list nodes are not in contegenous location like element used to in array
// used in stack queue 

class node {
    public:
    int data;
    node * next;
public:
node (int data1,node * nextptr){
    data=data1;
    next= nextptr; 
}
public:
node(int data2){
    data = data2;
    next = nullptr;
}


};
// arr to list converter 
node* convertArrtoLL(vector<int> arr){
    // first create first element as head
    node* head = new node(arr[0]);
    // assign a moving node that will help in further node creation
    node * mover = head;

    for(int i=0;i<arr.size();i++){
        // take a element make it node and assign somewhere in heap
        node * temp = new node (arr[i]);
        mover->next = temp;
        mover = temp; // not need to make mover->next = null coz already assign mover to temp and temp->ext = null since from temp node creation

    }
    return head;

}

// length of ll 
int lengthpfll(node * head){
    int count=0;
    node * temp = head;
    while(temp){
        count++;
        temp= temp->next;
    }
    return count;
}

// search or check if present
bool ispresent (node * head, node * given){
    // bool ispresent (node * head, int val){

    node * temp= head;
    while(temp){
        if(temp->data == given->data){
            // if(temp->data == val){
            return true;
        }
        temp= temp->next;
    }
    return false;
}

// deletion of head in ll
node * deletionofhead(node * head){
    // if list is null 
    if(head == nullptr) return nullptr;

    // if single node is present 
    if(head->next == nullptr) return head;

    node * temp = head;
    head= head->next;
    free(temp); 
    delete(temp); // use one of them
    return head;   
}

// deletion of tale
node * taledeletion(node * head){
    // if single node list ; same node will be tale and head and after deletion nothing will remain
    // if list is null 
    if(head->next== nullptr || head== nullptr) {
        free(head);
        return nullptr;
    }
    // we have to find node before tale 
     node * temp = head;
    while(temp->next->next != nullptr){
        temp= temp->next;
    }
    free(temp->next);
    temp->next= nullptr;
    return head;
}

// delete any kth node 
 node * deletekthnode(node * head,int k){
    // if k==1 then deletion of head
    if(k==1){
        node * temp = head;
        head = head->next;
        return head;
        free(temp);
    }
    // findout that node
    int count=0;
    node * temp = head;
    node * prev= nullptr;
    while(temp != nullptr){ // it means we are inside the list 
        count++;
        if(count==k){
            //we have find that node
            prev= prev->next->next;
            free(temp);
            break;
        }
        // not find yet keep searching
        prev= temp;
        temp= temp->next;
    }
    return head;
 }

 // insertion in head
 node * insertinhead(node*head,int val){
    node *temp= new node(val,head);
    return temp;
 }
 
 // insertion in tale
 node * taleinsert(node* head,int val){
    node * temp = head;
    while(temp->next != nullptr){
        temp= temp->next;
    }
    node * nodetoinsert = new node(val);
    temp->next= nodetoinsert;
    return head;
 }

 // insert at kth position
 node * insertatkth(node * head, int val,int k){
    // if ll is nulll
    if(head== nullptr){
        return new node(val);
    }
    // find just before k-1 th node 
    int cnt=0;
    node * temp = head;
    while( temp != nullptr){
        cnt++;
        // check if found
        if(cnt== k-1){
            node *nodetoinsert = new node(val);
            nodetoinsert->next= temp->next; // first connect 
            temp->next= nodetoinsert;
            return head;
        }
        // keep moving
         temp= temp->next;
    }
    return head;
 }


int main(){
    vector<int> arr={2,4,3,5};
    node * head= convertArrtoLL(arr);
    cout<<head->data;
    
    // traversal 
    node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }


}
*/


// DOUBLY LINKED LIST
class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node (int data1,node * next1, node * prev1){
        data= data1;
        next= next1;
        prev= prev1;
    }
    
    public:
    node(int data2)
    {
        data= data2;
        next= nullptr;
        prev= nullptr;
    }
};

// array to doubly linked list conversion
node * converttodll(vector<int> arr){
    // first create head 
    node * head= new node(arr[0]);
    node* prev= head;
    for(int i=1;i<arr.size();i++){
        node * temp = new node(arr[i],nullptr,prev);
        prev->next = temp; // connect prevnode to current
        prev = prev->next; // or : prev= temp;
    }
    return head;
}


// deletion of head
node * headdeletion(node * head){
    // if dll is empty
    if(head== nullptr || head->next == nullptr) return nullptr;

    node* newhead= head;
    head->prev= nullptr;
    head->next = nullptr;
    delete(head);
    return newhead;
}

// deletion of tale 
node * taledeletion(node * head){
    // null list
    if(head==nullptr || head->next==nullptr) return nullptr;

    // find tale node then delete after removing its all pointers
    node * tale = head;
    while(tale->next != nullptr){
        tale= tale->next;
    }
    node * newtale = tale;
    tale->prev= nullptr;
    newtale->next= nullptr;
    delete(tale);
    return head;
}

// deletion of any kth node
node * deletionkthnode(node * head,int k){
    // if dll is empty
    if(head== nullptr || head->next== nullptr) return nullptr;

    // find that kth node and do operation
    node * temp = head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    node * backnode = temp->prev;
    node * frontnode = temp->next;

    if(backnode == nullptr && frontnode== nullptr) // its a single node
        return nullptr;
    else if(backnode== nullptr) // it's a head 
    {
        return headdeletion(head);
    }
    else if( frontnode== nullptr) // it's a tale 
    {
        return taledeletion(head);
    }
    else{
        backnode->next = frontnode;
        frontnode->prev= backnode;

        temp->next= nullptr;
        temp->prev= nullptr;
        delete(temp);
        return head;
    }
}

// insertion before head
node * insertb4head(node * head,int val){
    node * newhead = new node(val,head,nullptr);
    head->prev= newhead;
    return newhead;
}

// insertion before tale
node * insertb4tale(node* head, int val){
    // find tale first
    node * tale= head;
    while(tale->next != nullptr){
        tale= tale->next;
    }
    // create node and point it's next to tale and it's prev to tale->prev
    node * back = tale->prev;
    node * nodetoinsert = new node(val,tale,back);
    back->next= nodetoinsert;
    tale->prev= nodetoinsert;
    return head;
} 

// insert before kth node
node * insertb4kth(node* head, int k, int val){
    // if dll is empty
    if(head== nullptr) {
        node * head= new node(val);
        return head;
    }
    
    int cnt=0;
    node * temp= head;
    while(temp){
        cnt++;
        if(cnt== k) break;
        temp= temp->next;
    }
    node * backnode = temp->prev;
    node * frontnode= temp->next;
    
    if(backnode== nullptr) // instertion before head
    {
        return insertb4head(head,val);
    }
    else if(frontnode== nullptr) // insertion before tale
    {
        return insertb4tale(head, val);
    }
    else{
        // somewhere inside dll
        node *nodetoinsert = new node(val,temp,backnode);
        backnode->next= nodetoinsert;
        temp->prev= nodetoinsert;
    }
    return head;
}

// REVERSE A DOUBLY LINKED LIST

// brute force method
void reversedll(node* head){
    // using a stack and store first data and then chnage data using stack lifo
    stack <int> st;
    node * temp = head;
    while(temp){                         // tc = n
        st.push(temp->data);
        temp= temp->next;
    }
    temp = head;
    while(temp){                        // tc = n 
        temp->data = st.top();
        st.pop();
        temp= temp->next;
    }
// tc = 2n
// sc = n 
}

// optimal approach
node* revesedll(node * head){
    // approach is to swap the prev and next pointers 
    node* last = nullptr;
    node* curr = head;

    while(curr){                                       // tc==n
        last = curr->prev;
        curr->prev =curr->next;
        curr->next= last;
        curr = curr->prev;
    }
    return last->prev;

    // tc= n 
    // sc= O(1)
}

//add two linked list #445

int main(){

}