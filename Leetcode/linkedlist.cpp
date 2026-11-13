#include <iostream>
#include<map>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// revrse a single linked list 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // using stack 
        stack<int> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp->val);
            temp= temp->next;
        }

        temp = head;
        while(temp)
        {
            temp->val= st.top();
            st.pop();
            temp= temp->next;
        }
        return head;
    }
};

// using swaping pointer in single linked list
ListNode* reverseList(ListNode* head) {
        
        // if list is null or single node 
    if(head==nullptr || head->next== nullptr) return head;
    ListNode* curr= head;
    ListNode* prev= nullptr;
   

    while(curr){
        ListNode* forward = curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward; 
    }
    return prev;

    }

// REVERSE LINKED LIST IN GIVEN RANGE LEFT , RIGHT

// brute force method 

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // for null list or single node list 
        if(head== nullptr || head->next== nullptr) return head;
        // using stack for this
        stack<int> st;
        ListNode* temp = head;
       int cnt=0;
       while(temp){
        cnt++;
        if(cnt>= left && cnt<= right){
            st.push(temp->val);
        }
            temp = temp->next;
       }
    
        temp= head;
        cnt=0;
        while(temp){
            cnt++;
            if(cnt>=left && cnt<= right){
                temp->val= st.top();
                st.pop();
            }
            temp= temp->next;
        }
        return head;
    }
};

// using swapping of pointers
ListNode * reversell(ListNode* head,int left,int right){
    // findout b4left node afterrightnode and reverse from left to right then pointer reversed list to leftside and rightside
    int cnt=1;
    // for b4left node 
    ListNode* b4left = head;
    while(b4left){
        cnt++;
        if(cnt == left) break;
        b4left= b4left->next;
    }
    ListNode* afterright= head ;
    cnt=0;
    while(afterright){
        cnt++;
        if(cnt == right) break;
        afterright= afterright->next;
    }


}

// add two ll and print their output sum in reverse order
ListNode* listsum(ListNode* head1, ListNode* head2){
    // if list is empty
    if(head1 == nullptr) return head2;
    if(head2== nullptr) return head1;
    if(head1 == nullptr && head2== nullptr) return nullptr;
    // we don't know which is smaller and larger 
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    int value =0;
    int carry=0;
    ListNode* newhead = new ListNode(1);
    ListNode* tempnode = newhead;
 int currsum = 0;
    while(temp1 !=nullptr && temp2 != nullptr){
       
        currsum = (temp1->val +temp2->val );
        
        value= currsum+carry;
        currsum =value%10;
        carry = value/10;
        ListNode * newnode = new ListNode(currsum,nullptr);
        tempnode->next = newnode;
        tempnode= newnode;

        temp1= temp1->next;
        temp2= temp2->next;

    }
    while(temp1 != nullptr){
        currsum = (temp1->val);
         value= currsum+carry;
        currsum =value%10;
        carry = value/10;

        ListNode * newnode = new ListNode(currsum,nullptr);
        tempnode->next = newnode;
        tempnode= newnode;


        temp1= temp1->next;
    }

    while(temp2 != nullptr){
         currsum = (temp2->val);
         value= currsum+carry;
        currsum =value%10;
        carry = value/10;

        ListNode * newnode = new ListNode(currsum,nullptr);
        tempnode->next = newnode;
        tempnode= newnode;

         temp2= temp2->next;

    }
    if(carry !=0){
            ListNode * newnode = new ListNode(carry,nullptr);
        tempnode->next = newnode;
        tempnode= newnode;
    }
    return newhead->next;

}

// cleaner version
 ListNode * twosum(ListNode * head1,ListNode* head2){
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    // whenever these types of ques come in which we have to store reuslt in new list always use dummy node 
    ListNode* dummynode = new ListNode (-1);
    ListNode* curr = dummynode;
    int carry=0;

    while(temp1 != nullptr || temp2 != nullptr){
        int sum= carry;
        if(temp1) sum+=temp1->val;
        if(temp2) sum+=temp2->val;
        ListNode* newnode = new ListNode(sum%10);
        carry= sum/10;

        curr->next= newnode;
        curr= curr->next;

        if(temp1) temp1= temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if (carry){
        ListNode* newnode = new ListNode(carry);
        curr->next= newnode;
    }

    return dummynode->next;


 }
 // add two numbers #445
 ListNode* addtwonum(ListNode* head1, ListNode* head2){
    // brute force
    // we can reverse the both ll and add them and return reversed ll
    ListNode* new1= reverse(head1);
    ListNode* new2 = reverse(head2);

    ListNode* ans= new ListNode(-1);

    int carry=0;
    ListNode* temp1= new1;
    ListNode* temp2= new2;
    ListNode* temp3= ans; // must otherwise not connection to realnode
    
    while(temp1 != nullptr && temp2 != nullptr){

        int sum = temp1->val + temp2->val + carry;
        ListNode* newnode = new ListNode(sum%10);
        temp3->next= newnode;
        carry= sum/10;

        temp1= temp1->next;
        temp2= temp2->next;
        temp3= temp3->next;
    }
    while(temp1){
        int sum = temp1->val + carry;
        ListNode* newnode = new ListNode(sum%10);
        temp3->next= newnode;
        carry= sum/10;

        temp1= temp1->next;
        temp3= temp3->next;
        
    }

    while(temp2){
        int sum = temp2->val + carry;
        ListNode* newnode = new ListNode(sum%10);
        temp3->next= newnode;
        carry= sum/10;

        temp1= temp2->next;
         temp3= temp3->next;
        

    }
    if(carry != 0){
        ListNode* newnode= new ListNode(carry);
        temp3->next= newnode;
    }
    // now reverse the ans ll
    ListNode* newhead = reverse(ans->next);
    return newhead;


 }

 // reverse linked list in given range left->right
 ListNode * reversell(ListNode* head,int left,int right){
    // we have to use dummynode for this prblm coz if left = 1 then it can run smoothly
    ListNode* dummynode = new ListNode();
    dummynode->next= head;

    // findout just before left node that help in connecting reversed node
    int cnt=1;
    ListNode* b4left = head;
    while(cnt!= left-1){
        cnt++;
        b4left= b4left->next;
    }
    // now reverse the ll given range
    ListNode* prev= nullptr;
    ListNode* curr = b4left->next;

    while(cnt<= right){
        cnt++;
        ListNode* forward= curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward;
    }
    // at last curr will be in after right wala node 
    // prev will be rightend node
    b4left->next->next= curr;
    b4left->next= prev;

    return dummynode->next;


 }

 // corrected code 
 class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* dummynode= new ListNode();
        dummynode->next= head;

        int cnt=0;
        ListNode* b4left= dummynode;
        while(b4left){
            cnt++;
            if(cnt == left ) break;
            b4left= b4left->next;
        }
        // reverse the ll 
        ListNode* curr= b4left->next;
        ListNode* prev= nullptr;

        while(cnt<=right){
            cnt++;
            ListNode* forward = curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
        }
        // connect ListNode
        b4left->next->next = curr;
        b4left->next= prev;

        return dummynode->next;

        
    }
};

// odd even linked list 
// brute force
ListNode* oddeven(ListNode* head){
    // if null list or single node list
    if(head== nullptr || head->next== nullptr) return head;

    vector<int> node;
    // takr a vector and push first odd elements and then after even elements
    ListNode* temp= head;
    // for odd nodes
    while(temp != nullptr && temp->next !=nullptr){
        node.push_back(temp->val);
        temp= temp->next->next;
    }
    // edge case if temp is last node 
    if(temp) node.push_back(temp->val);

    // same for even nodes
    temp= head->next;
    while(temp != nullptr && temp->next != nullptr){
        node.push_back(temp->val);
        temp= temp->next->next;
    }
    // same edge issue
    if(temp) node.push_back(temp->val);

    // change temp nodes accordingly
    temp= head;
    int i=0;
    while(temp){
        temp->val= node[i++];
        temp= temp->next;
    }
    return head;

}

// optimal approach using two pointer in same list
ListNode* oddeven(ListNode* head){
    if(head== nullptr || head->next == nullptr) return head;

    ListNode* oddnode= head;
    ListNode* evenode= head->next;
    ListNode*even = head->next;

    // move odd and even nodes
    while(evenode!= nullptr && evenode->next != nullptr){
        // connect odd node to next odd node
        oddnode->next = oddnode->next->next;
        evenode->next = evenode->next->next;

        // shift oddnode and evenode position
        oddnode = oddnode->next;
        // oddnode= oddnode->next->next; // wrong coz we already shift our oddnode odd->nxt is equal to odd->next->nxt 
        evenode= evenode->next;
    }

    // connect odd node to even node
    oddnode->next = even;
    return head;

}

// sort 0 ,1 and 2 in ll
// brute force method

ListNode* sortll(ListNode* head){
    // first count 0 ,1 and 2 then make node val respectively according to their count
    int cnt0= 0,cnt1=0,cnt2=0;
    ListNode*temp = head;
    while(temp){
        if(temp->val ==0)  cnt0++;
        else if(temp->val==1) cnt1++;
        else if(temp->val==2) cnt2++;

        temp= temp->next;
            
        }
    
    temp= head;
    while(temp){
        if(cnt0--) temp->val=0;
        else if(cnt1--) temp->val=1;
        else if(cnt2--) temp->val=2;

        temp= temp->next;

        }
        return head;
} // this works in two traversal that is not optimal 

// optimised code taking dummy nodes
ListNode * sortll(ListNode* head){
    // edge case
    if(head== nullptr || head->next== nullptr) return head;
    // create all three dummy nodes
    ListNode* zero = new ListNode(-1);
    ListNode* one = new ListNode(-1);
    ListNode* two = new ListNode(-1);

    // dummy for traversal 
    ListNode* move0 = zero;
    ListNode* move1 = one;
    ListNode* move2 = two;

    ListNode* temp= head;

    while(temp){
        // save temp->next for upcoming node
        ListNode*nextnode = temp->next;
        // make temp node single coz we have to add temp node to dummynodes
        temp->next= nullptr;

        if(temp->val==0) {
            move0->next= temp;
            move0= temp;
        }
        else if(temp->val==1){
            move1->next= temp;
            move1= temp;
        }
        else if(temp->val==2){
            move2->next= temp;
            move2= temp;
        }

        temp= nextnode;

    }
 // now connect nodes

    
    move0->next = (one->next) ? one->next : two->next;
     move1->next= two->next;
    

    ListNode* newhead = (zero->next)? zero->next: (one->next)? one->next:two->next;
    move2->next= nullptr;
    
// delete dummy nodes
delete zero;
delete one; 
delete two;

return newhead;

}

// sort list 

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // for edge cases
        if(head== nullptr || head->next == nullptr) return head;
        // brute force method
        vector<int> nodes;
        ListNode* temp= head;
        while(temp){
            nodes.push_back(temp->val);
            temp= temp->next;
        }
        sort(nodes.begin(),nodes.end());

        temp= head;
        int i=0;
        while(temp){
            temp->val= nodes[i++];
            temp= temp->next;
        }
        return head;
        
    }
};

// dlt the nth node from the last
ListNode* dltnth(ListNode* head,int n){
    // nth from last is equal to size-n+1 from the head
    // find out size
    int size=0;
    ListNode* temp= head;
    while(temp){
        size++;
        temp= temp->next;
    }
    // so the size will be size
    // we have to dlt size-n+1 node so wwe have to store prev and nodetodlt node
    temp= head;
       // for invalid position
    if(n>size || n<=0) return head;
    // ListNode* prev= nullptr; // this will create error when we have to dlt head that time prev will be null so prev->nxt is inaccesible
    ListNode* dummynode = new ListNode(-1);
    ListNode* prev= dummynode;
    int cnt=0;
    while(temp)
    {
        // store next node
        ListNode* nextnode = temp->next;
        // temp->next= nullptr; // no need to detach coz there are next nodes are too
         cnt++;
         if(cnt== size-n+1) break;
         prev= temp;
         temp= nextnode;
    }
    // point to prv->next to nodetodlt->next
    prev->next = temp->next;
    delete(temp);
    ListNode* ans= dummynode->next;
    delete dummynode;
    return ans;

}

// brute force method
ListNode * dltnth(ListNode* head,int n)
{
    // find size then point to prev to nodetodlt and then dlt 
    int size=0;
    ListNode*temp = head;
    while(temp){
        size++;
        temp= temp->next;
    }
    int cnt=0;
    temp=head;

    // for invalid nodes 
    if(n>size || n<=0) return head;
    // if head deletion
    if(n==size) {
        ListNode* newhead= head->next;
        delete head;
        return newhead;
    }
    while(temp){
        cnt++;
        if(cnt== size-n) break;
        temp= temp->next;
    }
    ListNode* nodetodlt = temp->next;
    temp->next= temp->next->next;
    delete nodetodlt;
    return head;
} // tc= 2n two traversal 

// optimal approach 
ListNode* dltnth(ListNode* head,int n){

    int size=0;
    ListNode*temp1 = head;
    while(temp1){
        size++;
        temp1= temp1->next;
    }
    int cnt=0;
    temp1=head;

    // for invalid nodes 
    if(n>size || n<=0) return head;
    // using fast and slow pointer
    ListNode* slow= head;
    ListNode* fast= head;
    //point fst to n node further to slow
    for(int i=0;i<n;i++){
        fast= fast->next;
    }
    // edge case 
           if(fast==nullptr) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
           }

    // move fast and slow and when the fast reach null slow will be the b4 the nodetodlt
    while(fast->next){
        slow= slow->next;
        fast= fast->next;
    }
    ListNode* dltnode = slow->next;
    slow->next= slow->next->next;
    delete dltnode;

    return head;
}

// reversal of ll using recursion
// we know that without recursion
 ListNode* reversal(ListNode* head){
    ListNode* prev= nullptr;
    ListNode* curr= head;

    while(curr){
        ListNode* forward= curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward;
    }
    return prev;
    
 }
 // using recursion in it
 ListNode* reverse(ListNode* head){
    // base case
    if(head== nullptr || head->next==nullptr ) return head;

    ListNode* newhead= reverse(head->next);
    ListNode* front= head->next;
    front->next= head;
    head->next= nullptr;

    return newhead;
 }

bool ispallindrom(ListNode*head){
    // using brute force method 
    stack<int>st;
    // restore first all element and then compare next time
    ListNode* temp= head;
    while(temp){
        st.push(temp->val);
        temp= temp->next;
    }
    // check this time
    temp= head;
    while(temp){
        if(temp->val != st.top()){
            return false;
        }
        temp= temp->next;
        st.pop();
    }
    return true;
}

// optimal approach
bool ispallindrom(ListNode* head){
    if(head== nullptr || head->next== nullptr) return true;
    // find out middle part
    ListNode* slow= head;
    ListNode* fast= head;

    while(fast->next != nullptr || fast->next->next!= nullptr){
        // first condition is for odd size ll and 2nd for even length of ll
        fast= fast->next->next;
        slow= slow->next;
    }
    ListNode* newhead= reverse(slow->next);
    ListNode* second = newhead;
    ListNode* first = head;

    while(second!= nullptr){
        if(first->val != second->val){
            reverse(newhead);
            return false;
        }
        first= first->next;
        second=second->next;

    }
    // slow->next= newhead; // no need coz already pointed
    reverse(newhead);
    return true;
}
 
class Solution {
    private: 
     ListNode* reverse(ListNode* head){
        // base case for single node
        if(head== nullptr || head->next == nullptr) return head;

        ListNode* newhead= reverse(head->next);
        ListNode* front= head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;
     }
public:
    bool isPalindrome(ListNode* head) {

        if(head== nullptr || head->next == nullptr) return true;

        // optimal approach
        // find out size
        ListNode* fast= head;
        ListNode* slow= head;

        while(fast->next != nullptr && fast->next->next !=nullptr){
            fast= fast->next->next;
            slow= slow->next;
        }
        ListNode* newhead= reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;

        while(second){
            if(first->val != second->val){
                reverse(newhead);
                return false;
            }
            first = first->next;
            second= second->next;
        }
        reverse(newhead);
        return true;
    }
};

// add 1 to the ll 
// brute force
ListNode* add1(ListNode* head){
    // first we reverse the ll and then add one using carry and then reverse and return head
    ListNode* newhead= reverse(head);
    int carry= 1; // initially we have to add 1
    ListNode* temp= newhead;
    while(temp){
        int value= temp->val + carry;
        if(value<10){
            temp->val = value;
            reverse(newhead);
            return head; 
        }
        temp->val= 0;
        carry= 1;
        temp = temp->next;
    }
    if(carry==1){
        reverse(newhead);
        ListNode*dummy = new ListNode(1);
        dummy->next = head;
        return dummy;
    }
    return head;

 // tc= 3N  not optimal
}

// optimal approach using recursion
 int helper (ListNode* head){
    // base case
    if(head->next== nullptr) return 1; // as a carry

    int carry= helper(head->next);
  
        head->val= head->val +carry;
        if(head->val <10) return 0;
        head->val= 0;
        return 1;

    
 }
ListNode* add1(ListNode* head){
    int carry = helper(head);
    if(carry==1){
        ListNode* temp = new ListNode(1);
        temp->next= head;
        return temp;
    }
    return head;
    
}

// find the intersection of y ll 
// brute force using hash map
ListNode* intersect(ListNode* head1, ListNode* head2){
    map<ListNode*, int> mp;
    ListNode* temp1= head1; // any of them 
    while(temp1){
        mp[temp1]++;
        temp1= temp1->next;
    } // all node stored
    temp1= head2;
    // for(auto i:mp){ // we have to traverse in second ll not in map
    while(temp1){
        if(mp.find(temp1)!= mp.end()){
            return temp1;
        }
        temp1= temp1->next;
    }
    return nullptr;
} // tc= n1+n2  ; sc = n1 or n2

// optimal approach 
ListNode* intersect (ListNode* head1,ListNode* head2){
    // findout how much other node is greater and move smaller node with diff after then when both starting point will same the move one by one and first common node will be the answer
    // findout sizes
    int size1=0,size2=0;
    ListNode* temp = head1;
    
    while(temp){
        size1++;
        temp= temp->next;
    }
    temp= head2;
    while(temp){
        size2++;
        temp= temp->next;
    }
     ListNode* move1 = head1;
     ListNode*move2 = head2;

    if(size1>size2){
        // move head1 node with size1- size2 steps
        int diff = size1- size2;
        while(diff--){
            move1= move1->next;
        }
    }
    else{
        int diff= size2-size1;
        while(diff--){
            move2= move2->next;
        }
        
    }
     // now move 1 and move2 both are same so move both by one step untill the same node found
// now move 2 nd 1 are same move gradually 
        while(move1 != move2){
            move1= move1->next;
            move2= move2->next;

        }
             return move1;
} // tc= n+m sc=1

//more optimal approach
ListNode* intersect(ListNode* head1,ListNode* head2){
    // point pointers at heads move whenever any reach null point to opposite head again move then if find equal node that be ans otherwise null will be answer
    ListNode* temp1= head1;
    ListNode* temp2= head2;

    while(temp1 != temp2){
        (temp1) ? temp1= temp1->next:temp1= head2;
        (temp2)? temp2= temp2->next: temp2= head1;
    }
    return temp1;
}

// find the middle of ll 
// brute force
ListNode* middlenode(ListNode* head){
    if(head== nullptr || head->next== nullptr) return head;
    // using mid = n/2 +1 method
    // find size then use mid method 
    int size= 0;
    ListNode* temp= head;
    while(temp){
        size++;
        temp= temp->next;
    }
    int mid= size/2 +1;
    temp= head;
    while(--mid){
        temp= temp->next;
    }
    return temp;
}

// using slow and fast pointer
ListNode* middlenode(ListNode* head){
    ListNode* slow= head;
    ListNode* fast= head;
    // when fast will reach at last slow will be at mid for odd size and for even size ll fast willl be at null when slow had reached mid
    while(fast != nullptr && fast->next!= nullptr){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}

// detect a loop in ll
// brute force usinf hashing map
bool haveloop(ListNode* head){
    map<ListNode*,int> mp;
    ListNode* temp= head;
    while(temp){
        if(mp.find(temp)!= mp.end()){
            return true;
        }
        mp[temp]++;
        temp= temp->next;
    }
    return false;
}

// using slow fast pointer approach
bool haveloop(ListNode* head){
    if(head== nullptr) return false;
    ListNode* slow= head;
    ListNode* fast= head;
    while(fast != nullptr && fast->next!= nullptr){
        fast=fast->next->next;
        slow= slow->next;
        if(slow== fast) return true;
    }
    return false;
}

// node from where loop starts
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // brute force by using map
        map<ListNode*,int> mp;
        ListNode* temp= head;
        while(temp){
            if(mp.find(temp)!= mp.end()){
                return temp;
            }
            mp[temp]++;
            temp= temp->next;
        }
        return nullptr;

        
    }
};
// optimal approach using fast and slow pointers 
ListNode *detectCycle(ListNode *head) {
        if(head== nullptr || head->next==nullptr) return nullptr;
        // usign slow fast
        ListNode* slow= head;
        ListNode* fast= head;
         // note down when they meet first time then point fast to head and move single step next time meetup node will be the answer
        while(fast!= nullptr && fast->next!= nullptr){
            fast= fast->next->next;
            slow= slow->next;
            if(slow== fast) break;
        }
        if(slow==fast){
            fast= head;
            while(fast != slow){
            fast= fast->next;
            slow= slow->next;
        }
        return slow;
        }
        return nullptr;
        
        
    }
};

// length of the loop
int looplength(ListNode* head){
    // brute force using map
    map<ListNode*,int> mp;
    ListNode*temp= head;
    int count=0;
    while(temp){
        if(mp.find(temp)!= mp.end()){
            // means it has visited them takeit count and findout lenght
            int value= mp[temp];
            return value- count;
        }
        mp[temp] = count++;
        temp= temp->next;

    }
    return 0;
} // tc = n+ nlogn ; sc= n

//optimal approach using slow and fast pointer
int findlength(ListNode* slow, ListNode* fast){
    int count =1;
    fast= fast->next;
    while(slow!= fast){
        fast=fast->next;
        count++;
    }
    return count;
}
int looplength(ListNode* head){
    ListNode* slow= head;
    ListNode* fast= head;
    
    while(fast!= nullptr && fast->next!= nullptr){
        fast= fast->next->next;
        slow= slow->next;
        if(slow== fast) return findlength(slow,fast);
    }
    return 0;
} // tc= n ; sc= 1;

// delete the middle node of ll
// using brute method
ListNode* dltmiddle(ListNode* head){
    if(head== nullptr) return nullptr;
    if(head->next== nullptr) {delete head; return nullptr;}
    // findout n/2th node and dlt node->next and point it to node->next->next
    int size=0;
    ListNode*temp = head;
    while(temp){
        size++;
        temp = temp->next;
    }
    int b4mid = size/2;
    // find that node and do operation
    temp= head;
    while(--b4mid){
        temp= temp->next;
    }
    ListNode* nodetodlt= temp->next;
    temp->next= temp->next->next;
    delete nodetodlt;
    return head;
} // tc= n+ n/2 two traversal ; sc= 1

// optimal approach using slow nd fast pointers
ListNode* dltmiddle(ListNode* head){
    if(head== nullptr) return nullptr;
    if(head->next== nullptr) {delete head; return nullptr;}
    
     ListNode* slow= head;
     ListNode* fast= head;

     // we have to don't let move to slow one time then it will automatically be before middle when fast had reched null for even length and at last for odd lenght
     fast= fast->next->next;
     while(fast != nullptr && fast->next!= nullptr){
        fast= fast->next->next;
        slow= slow->next;
     }
     ListNode* nodetodlt= slow->next;
     slow->next= slow->next->next;
     delete nodetodlt;
     return head;
} // tc= n one traversal ; sc= 1;

// dlt all occurance of given ket in dll 
ListNode* dltkey(ListNode* head,int key){
    // take node curr, prev and next and do operations
    ListNode* curr= head;
    
    while(curr){
        
        if(curr->val==key){
            if(curr==head){
                head= curr->next;
            }
            ListNode* forward= curr->next;
            ListNode* prevnode= curr->prev;
           
            if(forward) forward->prev= prevnode;
            if(prevnode) prevnode->next= forward;

            delete curr;
            curr= forward;
        }
        else{
             curr= curr->next;
        }
    }
    return head;
}
// 
// deleting all key value occurance in single ll 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;

        ListNode* curr= head;
        ListNode* prev= nullptr;

        while(curr){
            
            if(curr->val==val){
                ListNode* forward = curr->next;
                // if dlt to head position
                if(curr==head){
                    head= curr->next;
                }
                // other than head node
                delete curr;
                curr= forward;
                  if(prev) prev->next= curr;
                // if(forward) forward->next; // no need of doing this twice
                
            }
            else{
                prev= curr;
                curr= curr->next;;
                
            }
        }
        return head;
        
    }
};

// find two sum pairs in  sorted dll
vector<vector<int>> twosumpair(ListNode* head,int sum){
      vector<vector<int>> ans;
    if(head== nullptr) return ans;
    // using brute force 
  
    ListNode* temp1= head;
    while(temp1){
        ListNode* temp2= temp1->next;
        while(temp2!= nullptr && (temp1-> val+ temp2->val) <=sum){
            if(temp1->val+ temp2->val == sum){
                ans.push_back({temp1->val,temp2->val});
            }
            temp2= temp2->next;
        }
        temp1= temp1->next;
    }
    return ans;
}

// using optimal approach using two pointers

// finatale functino 
ListNode* findtale(ListNode* head){
    ListNode* temp= head;
    while(temp->next){
        temp= temp->next;
    }
    return temp;
}
vector<vector<int>> twosumpair(ListNode* head,int sum){
    vector<vector<int>> ans;
    if(head== nullptr || head->next== nullptr) return ans;
    ListNode* left= head;
    ListNode* right= findtale(head);

    // while(left->val <right->val){ 
    while(left!= right && left->prev != right){
        if(left->val+ right->val == sum){
            ans.push_back({left->val, right->val});
            left= left->next;
            right= right->prev;
        }
        else if(left->val+ right->val <sum){
            left= left->next;
        }
        else{
            right= right->prev;
        }
    }
    
    return ans;
}

// remove duplicated in sorted dll
ListNode* removedupli(ListNode* head){
    ListNode* curr= head;
    while(curr!= nullptr && curr->next != nullptr ){
        ListNode* nextnode= curr->next;
        while(nextnode!= nullptr && nextnode->val== curr->val){
            ListNode* duplicate= nextnode;
            nextnode= nextnode->next;
            delete duplicate;
        }
        curr->next==nextnode;
        if(nextnode) nextnode->prev= curr;

        curr= curr->next;   

    }
    return head;
}

// maximum twin sum of ll #2130
class Solution {
    private: 
    ListNode* reverse(ListNode* head){
        // base case
        if(head==nullptr || head->next == nullptr) return head;

        ListNode* newnode= reverse(head->next);
        ListNode* front = head->next;
        front->next= head;
        head->next= nullptr;
        return newnode;
    }
public:
    int pairSum(ListNode* head) {
        // findout b4middle node then reverse 2nd part and initialise two pointer move further and store sum
        int size=0;
        ListNode* temp= head;
        while(temp){
            size++;
            temp= temp->next;
        }
        //now find b4middle node
        int mid= size/2;
        temp=head;
        while(--mid){
            temp= temp->next;
        }
        ListNode* newhead = reverse(temp->next);
        ListNode* temp1= head;
        ListNode* temp2= newhead;

        int maxi= INT_MIN;
        while(temp2){
            maxi =max(maxi,temp1->val + temp2->val);
            temp1= temp1->next;
            temp2= temp2->next;
        }
        reverse(newhead);
        return maxi;
        
    }
};

// remove duplicated from sorted ll #82
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         if(head==nullptr) return nullptr;
         if(head->next == nullptr){
            return head;
         }
        ListNode* curr= head;
        ListNode* prev= nullptr;
       

        while(curr != nullptr && curr->next != nullptr ){
            ListNode* nextnode= curr->next;
            if(curr->val == nextnode->val){
                while(nextnode!= nullptr && nextnode->val==curr->val){
                    ListNode* nodetodlt = nextnode;
                    nextnode= nextnode->next;
                    delete nodetodlt;

                }
                if(curr==head){
                    ListNode* nodetodlt= head;
                    head= nextnode;
                    curr= head;
                    delete nodetodlt;
                }
                else{
                    ListNode* nodetodlt =curr;
                    prev->next=nextnode;
                    curr= nextnode;
                    delete nodetodlt;
                }
            }
            else{
                prev=curr;
                curr= curr->next;
            }
        }
        return head;
        
    }
};

// SWAP NODES IN PAIR #24
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        // take two pointers and swap them continue this process untill find null one of them
        ListNode* curr=head;
        ListNode* prev= nullptr;

        while(curr!=nullptr && curr->next!= nullptr){
            ListNode* forward = curr->next;
            // we have to reverse curr and forward 
            // head edge case
            if(curr==head){
                curr->next= forward->next;
                forward->next= curr;
                head= forward;
            }
            else{
                prev->next= forward;
                curr->next= forward->next;
                forward->next= curr;  
            }
            prev= curr;
            curr=curr->next;
        }
        return head;
    }
};

// optimal approach 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head== nullptr || head->next== nullptr) return head;
        // taking a dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* prev= dummy;
        ListNode* curr= head;

        while(curr!= nullptr && curr->next != nullptr){
            ListNode* forward = curr->next;

            prev->next= forward;
            curr->next= forward->next;
            forward->next= curr;

            prev= curr;
            curr= curr->next;
        }
        return dummy->next;
    }
};

// merge two sorted ll
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //edge case
        if(list1== nullptr) return list2;
        if(list2==nullptr) return list1;
        if(list1==nullptr && list2== nullptr) return nullptr;

        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;

        ListNode* temp1= list1;
        ListNode* temp2= list2;

        while(temp1 != nullptr && temp2!= nullptr){
            if(temp1->val > temp2->val){
                ListNode* forward2= temp2->next;
                temp2->next= nullptr;
                temp->next= temp2;
                temp2= forward2;
                 temp= temp->next;
                
            }
            else{
                ListNode* forward1= temp1->next;
                temp1->next= nullptr;
                temp->next= temp1;
                temp1= forward1;
                 temp= temp->next;
              

            }
        }
        if(temp1!= nullptr){
                temp->next= temp1;
        }
        if(temp2!= nullptr){
            temp->next= temp2;
        }
        return dummy->next;
        
    }
};

// reverse k pair node #25
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private: // reverse in given range 
        ListNode* reverse(ListNode* s,ListNode* e){
            if(s==e) return e;

            ListNode* newhead= reverse(s->next,e);
            ListNode* front= s->next;
            front->next= s;
            s->next= nullptr;
            return newhead;
        }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==nullptr || head->next ==nullptr) return head;
        // using reversing method
        ListNode* dummy = new ListNode(-1);
        ListNode* prev= dummy;
        ListNode* curr= head;
        int count=0;
        while(curr){
            // first reverse in k pair then move curr after k step
            // find node after k step
            ListNode* enode= curr;
            count =k;
            while(--count && enode!=nullptr){
                enode= enode->next;  
            }
            if(count!=0 || enode==nullptr) return dummy->next; // means not reached after k step
            else {
                // reverse the list and point
                ListNode* newend = enode->next; 
                ListNode* newhead=reverse(curr,enode);
                prev->next= newhead;
                curr->next= newend;

                prev= curr;
                curr= newend;

            }
        }
        return dummy->next;
    }
};
// partition list #86
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head== nullptr || head->next== nullptr) return head;
        // we have to create two list one having lesser and other have greater and equal to x 
        ListNode* dummy1= new ListNode(-1);
        ListNode* dummy2= new ListNode(-1);

        ListNode* lesser= dummy1;
        ListNode* greater= dummy2;
        
        ListNode* temp= head;
        while(temp){
            if(temp->val <x){
                ListNode* forward = temp->next;
                temp->next= nullptr;
                lesser->next= temp;
                lesser = lesser->next;
                temp= forward; 
            }
            else{
                ListNode* forward = temp->next;
                temp->next= nullptr;
                greater->next= temp;
                greater = greater->next;
                temp= forward;  
            }
        }
        // connect both lists
        lesser->next= dummy2->next;
        ListNode* newhead = dummy1->next;
        delete dummy1;
        delete dummy2;
        return newhead;
        
    }
};

// reorder list # 143 
// if return type if Listnode* type 
class Solution {
    private: 
    ListNode* reverse(ListNode* head){
        if(head== nullptr || head->next == nullptr) return head;

        ListNode* newhead = reverse(head->next);
        ListNode* front= head->next;
        front->next= head;
        head->next= nullptr;
        return newhead;
    }
public:
    ListNode* reorderList(ListNode* head) {
        if(head== nullptr || head->next==nullptr) return head;
        // findout middle and take two pointers and move them simultationaly 
    ListNode* slow= head;
    ListNode* fast= head;
    while(fast != nullptr && fast->next != nullptr){
        slow= slow->next;
        fast= fast->next->next;
    }
    // slow will be the middle node 
    ListNode* newhead= reverse(slow->next);
    ListNode* temp1= head;
    ListNode* temp2= newhead;

ListNode* dummy = new ListNode(-1);
ListNode* temp= dummy;
    while(temp2){
        // first store temp1 
        ListNode* next1= temp1->next;
        temp1->next= nullptr;
        temp->next= temp1;
        temp= temp->next;
        temp1= next1;

        // now store temp2
        ListNode* next2= temp2->next;
        temp2->next= nullptr;
        temp->next= temp2;
        temp= temp->next;
        temp2= next2;
    }
    // one last node in odd length cases
    if(temp1){
        temp1->next =nullptr;
        temp->next = temp1;
    }
        ListNode* newhead1= dummy->next;
        delete dummy;
        return newhead1;
    }
};

// optimal approach 
class Solution {
    private: 
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next == nullptr) return head;

        ListNode* newhead= reverse(head->next);
        ListNode* front= head->next;
        front->next= head;
        head->next= nullptr;
        return newhead;
    }
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return;
        else{

                // take two pointer first on head and second on reversed part of middle list 
        // connect both first node and so on
        ListNode* fast= head;
        ListNode* slow= head;
    
        while(fast!=nullptr && fast->next != nullptr){
            fast= fast->next->next;
            slow= slow->next;
        }
        ListNode* newhead= reverse(slow->next);
         slow->next= nullptr;
        ListNode* temp1= head;
        ListNode* temp2= newhead;
// we have slow , temp1 , temp2 
       

        while(temp2 != nullptr && temp1 !=nullptr){
            ListNode* nexttemp1= temp1->next;
            ListNode* nexttemp2= temp2->next;

            temp2->next= temp1->next;
            temp1->next= temp2;
            
            temp1= nexttemp1;
            temp2= nexttemp2;
        }
        
        } 
    }
};

// ROTATE A LINKED LIST 
ListNode* rotate(ListNode* head,int k){
    if(head==nullptr || head->next== nullptr) return head;
    // point tale to head and make size-k node to tale and it's next to head and return this head
int size=0;
ListNode* temp= head;
while(temp){
    size++;
    temp=temp->next;
}
if(k%size==0) return head;
k= k%size;
 int n= size-k;
 temp= head;
 while(--n)
 {
    temp= temp->next;
    
 }

 ListNode* newhead= temp->next;
ListNode * tale= head;
while(tale->next){
    tale= tale->next;
}
tale->next= head;
temp->next= nullptr;
return newhead;
}
int main(){

}
