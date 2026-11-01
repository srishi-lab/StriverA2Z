#include <iostream>
#include <map>
#include<string>
using namespace std;

// // count number iteration in an array
// // for one 
// int count(int arr[],int number,int n){
//     int count=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==number){
//             count++;
//         }
//     }
//     return count;
// }
// void countarr(int arr[],int n){
//     int array[n];
//     for(int i=0;i<n;i++)
//     {
//         array[i]=count(arr,arr[i],n);
//     }

//     for(int i=0;i<n;i++){
//         cout<<array[i]<<" ";
//     }

// }

// hashing method


// int main(){
//     int hash[100000] ={0};
//     // max size of hash array can initialise under main fun if of 1e6 but it is 1e7 for outside globallu

//      int arr[5] ={1,2,3,1,2};

//      for(int i=0;i<5;i++){
//         hash[arr[i]] +=1;
//      }
 
//      // taking input num for checking
//      int q;
//      cin>>q;
//      while(q--){
//         int num;
//         cin>>num;
//         cout<<hash[num]<<endl;
//      }
// }
// character hashing
// int main(){
//     // int hash[26]={0}; // only for lowercase string
//     int hash[256] ={0}; // for all character lower or upper
//     string s;
//     cin>>s;

//     for(int i=0;i<s.length();i++){
//         // hash[s[i]-'a']+=1; // for lowercase 
//         hash[s[i]]+=1; // for all character
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         char c;
//         cin>>c;

//         // cout<<hash[c-'a']<<endl; // for lower case
//         cout<<hash[c]<<endl; // for both
//     }
// }

// USING MAP 
void counting(int arr[],int n){
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        // it will check if key arr[i] exist then simple increse vlaue by +1 otherwise create a key arr[i] and initiliase value to 1 coz of ++
    }
    int n1;
    cin>> n1;
    while(n1--){
        int num;
        cin>>num;
        cout<<m[num]<<endl;
    }

}

// MAP FOR CHARACTER HASHING
void characterhash(string s){
    unordered_map<char,int> m;

    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }

    // iteration inside map
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
        // a 1
        // g 1
        // h 2
        // i 3
        // j 1
        // n 1
        // r 2
        // s 2
        // everything in sorted order in map
    // but in unordered_map 
        // //n 1
        // j 1
        // a 1
        // h 2
        // s 2
        // i 3
        // g 1
        // r 2


    }

    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        cout<<m[c]<<endl;
    }
}


int main(){
    int arr[6] ={1,2,4,3,2,1};
    // counting(arr,6);
    string s= "rishirajsingh";
    characterhash(s);
}