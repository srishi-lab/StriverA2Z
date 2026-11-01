#include <iostream>
using namespace std;

// // kth largest interger in nums 
// // string kthlargest(vector<string> nums, int k){
// //     int largest = INT_MIN;
// //     int n= nums.size();
// //     int curr=0;
// //     int index=0;
// //     while(k>0){
// //         largest = INT_MIN;
// //         for(int i=0;i<n;i++){
// //             curr= stoi(nums[i]); // will fail due to int size
// //             if(curr>=largest){
// //                 largest= curr;
// //                 index= i;
// //             }
// //         }
// //         swap(nums[index],nums[n-1]);
// //             n--; k--;

// //     }
// //     string ans = to_string(largest);
// //     return ans;

// // }

// string kthlargest(vector<string> nums,int k){
//     int index =0;
//     int n= nums.size();
//     string largest="";
//     while(k>0){
//         for(int i=0;i<n;i++){
//             // if(nums[i].size()> largest.size()){ // this will not work for same no of digits
//             if(nums[i].size()> largest.size() || (nums[i].size()== largest.size() && nums[i]> largest)){
//                 largest= nums[i];
//                 index =i;
//             }
//         }
//         swap(nums[index],nums[n-1]);
//         n--;k--;
        
//     }
//     return largest;

// }

// //  COUNTING WORDS WITH A GIVEN PREFIX (2185)
// bool ispref (string s, string pref){
//     //remind a case when strinf itself is smaller than pref
//     if(s.size()<pref.size()){
//         return false;
//     }
//     for(int i=0;i<pref.size();i++){
//         if (pref[i] != s[i]){
//             return false;
//         }
//     }
//     return true;

// }
//  int prefixCount(vector<string>& words, string pref) 
//  {
//     // brute force
//     int n= words.size();
//     int count=0;
//     for(int i=0;i<n;i++){
//         if(ispref(words[i],pref)){
//             count++;
//         }
        
//     }
//     return count;
//  }

//  // using string compare method
//  int prefixCount(vector<string>& words, string pref) {
//     int n= words.size();
//     int count=0;
//     for( int i =0;i<n;i++){
//         if(words[i].compare(0,pref.size(),pref)){
//             count++;
//         }
//     }
//     return count;

//  } 

// //  count prefixes of a given string (2255)

// bool isprefix(string s, string pref)
// {
//     if(s.size()<=pref.size()){
//         for(int i=0;i<s.size();i++){
//             if(s[i]!=pref[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     else{
//         for(int i=0;i<pref.size();i++){
//             if(s[i]!= pref[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// }

// int countPrefixes(vector<string>& words, string s) {
//     int n= words.size();
//     int count=0;
//     for(int i=0;i<n;i++){
//         if(isprefix(words[i],s)){
//             count++;
//         }
//     }
//     return count;
// }

// // CHECK IF WORD OCCURS AS A PREFIX OF ANY WORD IN SENTENCE (1455)
// int isPrefixOfWord(string sentence, string searchWord) {
//     //brute force
//     int i=0;
//    int wordno=0;
//     while(i<sentence.length()){
//         int j=i;
//         while(j<sentence.length() && sentence[j]!= ' '){
//             j++;
//         }
//         wordno++;
//         int sizeofthisword= j-i;
//         if(sizeofthisword<searchWord.length()){
//             i=sizeofthisword+1+i;

//         }
//         else{
//             int index=i;
//             bool hint = false;
//             for(int a=0;a<searchWord.length();a++){
//                 if(searchWord[a]!=sentence[index++]){
//                     i=sizeofthisword+1+i;
//                     hint= true;
//                     break;
//                 }
//             }
//             if(hint){
//                 break;
//             }
//             else{
//                 return wordno;
//             }
//         }

//     }
//     return -1;
// }

// COUNTING BITS
    int oneinbit(int n){
        int count=0;
        while(n !=0){
            if(n%2==1){
                count++;
            }
            n=n/2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        // basically we have to create an array from zero upto n and arr[i] will be no of 1's in i 
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(oneinbit(i));   
        }
        return ans;

    }

int main(){
//    vector<string> nums ={"3","6","7","10"};
//    string ans =kthlargest(nums,4);
//    cout<<ans;

int ans1= oneinbit(10);
int ans2= oneinbit(9);
int ans3= oneinbit(6);
int ans4= oneinbit(5);
int ans5= oneinbit(7);
cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<endl;


}