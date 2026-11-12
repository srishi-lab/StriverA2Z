#include <iostream>
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

int main(){

}