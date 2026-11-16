#include <iostream>
using namespace std;

// //stack using array 
// class stimp{
//     public:
//     int st[10]; // size have to allot during class time because arr has no property of increasing size automatically
//     int start=-1;

//     public:
//     void push(int x){
//         if(start>=9) { cout<<"stack overflowed"<<endl; return;} // must break also 
//         st[++start]=x;
//     }
//     public:
//     void pop(){
//         if(start==-1) { cout<<"stack underflowed"<<endl; return;}
//         start-=1;
//     }
//     public:
//     int top(){
//          if(start==-1) {cout<<"stack is empty"<<endl; return -1;}
//          return st[start];
//     }
//     public:
//     int size(){
//         if(start==-1) return 0;
//         return start+1;
//     }

//     public:
//     bool empty(){
//         if(start==-1) return true;
//         return false;
//     }
//     public:
//     bool isfull(){
//         if(start==9) return true;
//         return false;
//     }
//     public:
//     void display(){
//         if(!empty()){
//             for(int i=0;i<=start;i++){
//                 cout<<st[i]<<" ";
//             }
//             cout<<endl;
//         }
//         else{
//             cout<<"stack is empty"<<endl;
//         }
//     }
// };

// // queue using array
// class quimp{
//     public:
//     int qu[10];
//     int start=-1,end=-1,currsize=0;
    

//     public:
//     void push(int x){
//         if(currsize==10) {cout<<"queue is overflowed"<<endl; return; }
//         end= (end+1)%10;
//         qu[end]=x;
//         currsize++;
//     }
//     public:
//     void pop(){
//         if(currsize==0) { cout<<"queue is empty"<<endl; return; }
//         start= (start+1)%10;
//         currsize--;
//     }
//     public:
//     int top(){
//         if(currsize==0) return -1;
//         return qu[start];
//     }
//     public:
//     int size(){
//         return currsize;
//     }

// };

// // stack using linked list 
// class stlist{
//     public:
//     ListNode* temp= nullptr;
//     int currsize=0;

//     public:
//     void push(int x){
//         // no overflowed condition
//         ListNode* nodetopush= new ListNode(x);
//          nodetopush->next = temp;
//         temp= nodetopush;
//         currsize++;
//     }
//     public:
//     void pop(){
//         if(currsize==0) {cout<<"underflowed"; return ;}
//         else{
//         ListNode* newtemp= temp->next;
//         delete temp;
//         temp= newtemp;
//         currsize--;
//         }
//     }
//     public:
//     int top(){
//         if(currsize==0) return -1;
//         return temp->val;
//     }
//     public:
//     int size(){
//         return currsize;
//     }

// };

// // queue using ll
// class qulist
// {
//     public:
//     node* start= nullptr;
//     node* end= nullptr;
//     int size=0;

//     public:
//     void push(int x){
//         node* nodetopush = new node(x);
//         if(size==0) {start= nodetopush;end= nodetopush;size++; return;}
//         end->next = nodetopush;
//         end= nodetopush;
//         size++;
//     }
//     public:
//     void pop(){
//         if(start==nullptr && end== nullptr) {cout<<"queue is empty"<<endl; return;}
//         if(size==1) {delete start; start= nullptr; end= nullptr; size=0; return ;}
//         node* newstart= start->next;
//         delete start;
//         start= newstart;
//         size--;
//     }
//     public:
//     int top(){
//         if(start==nullptr && end== nullptr) return -1;
//         return start->val;
//     }
// };

// // implement stack using queue
// class stque{
//         public:
//         queue<int> stack;

//         public:
//         void push(int x){
//             stack.push(x);
//             for(int i=0;i<stack.size();i++){
//                 stack.push(stack.top());
//                 stack.pop();
//             }
//         }
//         public:
//         void pop(){
//             stack.pop();
//         }
//         public:
//         int top(){
//             if(stack.size()) return stack.top();
//             return -1;
//         }

// };

// // implementation queue using stack
// // for it we have to use two stacks
// class queuest{
//     public:
//     stack<int> s1,s2;

//     public:
//     void push(int x){
//         while(s1.size()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(s2.size()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
//     public:
//     void pop(){
//         s1.pop();
//     }
//     public:
//     int top(){
//         if(s1.size()) return s1.top();
//         return -1;
//     }

// }; // will take time too much for push operations two traversal

// // much optimal approach but useful when more push operations but not optimal for pop and top operations as well 
// class queuest{
//     public:
//     stack<int> s1,s2;

//     public:
//     void push(int x){
//         s1.push(x);
//     }

//     public:
//     void pop(){
//         if(s1.empty() && s2.empty()) return;
//         if(!s2.empty()) {s2.pop(); return ;}
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.pop();
//     }
//     public:
//     int top(){
//         if(s1.empty() && s2.empty()) return -1;
//         if(!s2.empty()) return s2.top();
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         return s2.top();
//     }
// }


/* STACK BASED QUESTIONS  */

// INFIX TO POST FIX
string infixtopostfix(string s){
    int i=0;
    string ans="";
    stack<char> st;
    while(i<s.size()){
        char ch= s[i];
        if(ch>='A' && ch<='Z' ||ch>='a' && ch<='z' || ch>='0' && ch<='9' ){
            ans+=ch;
        }
        else if (ch==')'){
            while(!s.empty() && st.top()=='('){
                ans+=st.top();
                st.pop();
            }
        }
        else if(ch=='('){
            st.push(ch);   
        }
        else{
            while(st.empty() && priority(ch) <= priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
};

// infix to prefix
string infixtoprefix(string s){
    /* 1. reverse the string
     2. convert into postfix
     3. reverse the postfix 
     4. getting string will be prefix
    */
   string revs="";
   for(int i=s.size()-1;i>=0;i--){
    char ch= s[i];
    revs+=ch;
   }

   int i=0;
   stack<char> st;
   string ans="";
   while(i<revs.size()){
    char ch= revs[i];
    if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' || ch>='0' && ch<='9'){
        ans+=ch;
    }
    else if(ch=='('){
        st.push(ch);
    }
    else if(ch==')'){
        while(!st.empty() && st.top()!= '('){
            ans+=st.top();
            st.pop();
        }
        st.pop();

    }
    else if( st.empty() && priority(s[i])<=priority(st.top())){
        ans+=st.top();
        st.pop();
    }
    else{
        st.push(ch);
    }
    i++;
   }
   while (!st.empty()){
    ans+=st.top();
    st.pop();
   }
   
   string answer="";
   for(int i=ans.size()-1;i>=0;i--){
    answer+=s[i];
   }
   return answer;
};

// POSTFIX TO INFIX
string postfixtoinfix(string s){
    /* 1. What happens actually in infix that we have to push operand and if any operation comes 
    last two operand get popped and first operation second 
    result will single string 
    */
   int i=0;
   stack<string> st;
   
   while(i<s.size()){
    string ch= "s[i]";
    if(ch>="A" && ch<="Z" || ch>="a"&& ch<="z" || ch>="0" && ch<="9"){
        st.push(ch);
    }
    else{
        string t1= st.top(); st.pop();
        string t2= st.top(); st.pop();
        string t= '('+t1+ch+t2+')';
        st.push(t);
    }
    i++;
   }
   return st.top();
}

// prefix to infix
string prefixtoinfix(string s)
{
    // same as postfixtoinfix but the diff is we have to start from reverse
    int i= s.size()-1;
    stack<string> st;
    while(i>=0){
        string ch="s[i]";
        if(ch>="A" && ch<="Z" || ch>="a"&& ch<="z" || ch>="0" && ch<="9"){
        st.push(ch);
    }
    else{
        string t1= st.top(); st.pop();
        string t2= st.top(); st.pop();
        string t= '('+t1+ch+t2+')';
        st.push(t);
    }
    i++;
   }
   return st.top();
}

/// post fix to prefix
string postfixtoprefix(string s){
    /* push whenever gets operand but in operation popped top two and 
    operation t2 t1 and push back
    return top in answer
    */
   int i=0;
   stack<string> st;
   while(i<s.size()){
    string ch= "s[i]";
    if(ch>="A" && ch<="Z" || ch>="a"&& ch<="z" || ch>="0" && ch<="9"){
        st.push(ch);
    }
    else{
        string t1= st.top(); st.pop();
        string t2= st.top(); st.pop();
        string t= "("+ ch+ t2+t1 +")";
        st.push(t);
    }
    i++;
   }
   return st.top();
   }

   // prefix to postfix
   string prefix2postfix(string s){
    /* same as postfix 2 prefix the only diff is to start from reverse
    */
   int i= s.size()-1;
   stack<string> st;
   while(i>=0){
    string ch= "s[i]";
    if(ch>="A" && ch<="Z" || ch>="a"&& ch<="z" || ch>="0" && ch<="9"){
        st.push(ch);
    }
    else{
        string t1= st.top(); st.pop();
        string t2= st.top(); st.pop();
        string t= "(" + t1 +t2+ ch+ ")";
        st.push(t);
    }
    i--;
   }
   return st.top();
   }

   

int main(){

}