#include <iostream>
#include<list>
#include <deque>
#include<set>
#include <map> 
using namespace std;

// pairs 
void explainpair(){
    pair <int,int> p ={1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,pair<int,int>> pp= {1,{2,3}};
    cout<<pp.first<<" "<<pp.second.first<<" "<<pp.second.second<<endl;

    pair<int,int> arr[3] ={{1,2},{3,4},{5,6}};
    for(int i=0;i<3;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    cout<<endl;
}

// vectors
void explainvector(){
    vector<int> v; 
    // size of vector is dynamic so no need to worry if we initialised n size of vector sudden want to push back one more element then no need to change the size it automatically increse its size 

    v.emplace_back(1); // faster than push back 
    vector<pair<int,int>> v1;
    v1.push_back({1,2});
    v1.emplace_back(1,2); // automatically treat it as set

    vector<int> v2(5,100); // {100,100,100,100,100} 
    vector<int> v3(5); //{0,0,0,0,0};

    cout<<v[0]<<" "<<v.at(0); 
    cout<<v.back()<<" "; // last element

    // below all three are same 

    for(vector<int> ::iterator it =v.begin() ; it !=v.end();it++){
        cout<<*it<<" ";
    }

    for(auto it=v.begin();it != v.end(); it++){
        cout<<*it<<" ";
    }

    for(auto it:v){
        cout<<it<<" "; // not * here coz it automatically detect it's data type
    }

    // erase elements
    v.erase(v.begin()+1); // 2nd element will erase
    v.erase(v.begin(),v.begin()+2); // 1,2 element will erase not 3 coz it follows [start,end)

    v.clear(); // clear the whole vector 

    //insert
    // {100,100,100,100,100}
    v.insert(v.begin(),120); //{120,100,100,100,100,100}
    v.insert(v.begin()+1,2,200); //{120,200,200,100,100,100,100,100}
}

// list
void explainlist(){
    list<int> ls;

    ls.push_back(1);
    ls.emplace_front(0); // only the extra funx it have than vector 
    // other fuctions are same 
    // begin,end,rbegin,clear,insert,size,swap


}

// dequeue
void explaindeque(){
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(3); // {1,3}
    dq.emplace_front(0); // {0,1,3}
    dq.push_front(-1); // {-1,0,1,3}

    dq.pop_back(); //{-1,0,1}
    dq.pop_front(); //{0,1}

    dq.back(); // 1
    dq.front(); // 0

    // rest functions are same as vector and list
}

// priority queue
void expainPQ(){
    priority_queue <int> pq; // always keep largest element on top
     pq.push(2); // {2}
     pq.push(3); // {3,2}
     pq.push(1); // {3,2,1}
     pq.push(8); // {8,3,2,1}
     pq.emplace(10); // {10,8,3,2,1}

     cout<<pq.top(); // 10
     pq.pop(); // {8,3,2,1} top most element will pop
} 

// set
void explainset(){
    set<int> s;

    s.insert(1); // {1}
    s.insert(2); // {1,2}
    s.insert(1); // {1,2}
    s.insert(11); // {1,2,11}
    s.insert(22); //{1,2,11,22}
    s.insert(11); // {1,2,11,22}


}

//  map 
void explainmap(){
    // map<key,value> mapp;
    // key and value can be any data type in which key will be unique and value can be same 
    map<int,int> m;
    map<pair<int,int>,int> m1;
    map<int,pair<int,int>> m2;
    
    m[1] =2; // {1,2}
    m.insert(3,4); // [{1,2},{3,4}]
    m.emplace(5,6); // [{1,2},{3,4},{5,6}]
    m.insert(2,6); // [{1,2},{2,6},{3,4},{5,6}] 
    // store in unique and sorted order

    m1[{2,3}]=10;

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<m[1]; // 2;
    cout<<m[7]; // 0 or null notexist

    auto j = m.find(5);
    cout<< (*j).second;

    // unordered map same as this only the diff is of sorted element
}

int main(){
    // explainpair();
    int arr[5] = {1,2,3,4,5};
    for(auto i:arr){
        cout<<i<<" ";
    }

}