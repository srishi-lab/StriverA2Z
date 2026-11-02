#include <iostream>
#include<map>
using namespace std;

// // COUNT ELEMENTS WITH MAXIMUM FREQUENCY (3005)
//  int maxFrequencyElements(vector<int>& nums) {
//     unordered_map<int,int> mp;
//     int n= nums.size();
//     for(int i=0;i<n;i++){
//         mp[nums[i]]++;

//     }
//     int max=INT_MIN;
//     int ans=0;
//     for(auto i:mp){
       
//         if(i.second>max){
//             max= i.second;
//             ans =max;
//         }
//         else if(i.second==max){
//             ans+=max;
//         }
       
//     }
//     return ans;
//  }

// // TOP K FREQUENT ELEMENTS (347)
//  vector<int> topKFrequent(vector<int>& nums, int k){
//     vector<int> ans;
//     unordered_map<int,int> mp;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         mp[nums[i]]++;
//     }
//     int max =INT_MIN;
//     while(k--){
       
//         for(auto i:mp){
//             if(i.second>max){
//                 max= i.first;
//             }
//         }
//         ans.push_back(max);
//         mp.erase(max);

//     }
//  }

//  // using priority queue for this operation
//  vector<int> topKFrequent(vector<int>& nums, int k){
//     vector<int> ans;
//     unordered_map<int,int> mp;
//     int n= nums.size();
//     for(int i=0;i<n;i++){
//         mp[nums[i]]++;
//     }
//     // insert it on priority queue
//     priority_queue<pair<int,int>> pq;
//     for(auto i: mp){
//         pq.push({i.second,i.first});
//     }
//     while(k){
//         ans.push_back(pq.top().first);
//         pq.pop();
//         k--;       
//     }
//     return ans;
//  }

//  LONGEST SUBSTRING WITHOUT REPEATING CHARACTER
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
       int count=0;
        int i=0;
            while(mp[s[i]]==0 && i<s.length()){
                count++;
                i++;
            }
            return count;
        }
        
// TWO SUM USING HASH (1)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    // create a map having index and value
    unordered_map<int,int> mp;
    // first is index and second is value
    for(int i=0;i<nums.size();i++){
        int required = target- nums[i];
        for(auto it:mp){
            if(it.second==required){
                ans.push_back(it.first);
                ans.push_back(i);
                return ans;
            }  
        }
         mp[i]= nums[i];
         // if we are doing here key = index and value = indexvalue then we have to use for loop for finding iterator in map
         // but if we change key value then we can optimise it in n from n^2

        
    }
    return ans;
}
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> mp;
    vector<int>ans;

    for(int i=0;i<nums.size();i++){
        int required = target-nums[i];
        // if(mp[required]){ 
            // can't use because value can be 0 :: mp[required]= 0 
            if(mp.find(required)!= mp.end()){ 
            ans.push_back(mp[required]);
            ans.push_back(i);
            return ans;
        }
        else{
            mp[nums[i]]= i;
        }
    }
    return ans;
}
            

  
int main(){
    // int arr[5]={1,2,2,2,3};
    // map<int,int> mp;
    // for(int i=0;i<5;i++){
    //     mp[arr[i]]++;
    // }

    // for(int i=0;i<mp.size();i++){
    //     cout<<mp[i]<<" ";
    // }
    string s="abcabcbb";
    int ans= lengthOfLongestSubstring(s);
    cout<<ans;
}