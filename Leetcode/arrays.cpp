#include <iostream>
#include<set>
using namespace std;

// two sum
// brute method
vector<int> twosum(int arr[], int n,int target){
    int i=0;
    vector<int> ans;
    while(i<n-1){
   for(int j=i+1;j<n;j++){
        if(arr[i] +arr[j]== target){
            ans.push_back(i);
            ans.push_back(j);
        }   
    }
         i++;
    }
    return ans;
 
}



// max operation on array
int maxoperations(vector<int> nums, int target)
{

}

// rotate non negative elements
// brute force
void rotate(vector<int> nums,int k){
    vector<int> temp;
    int n= nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]>=0){
            temp.push_back(nums[i]);
        }
    }
    // apply left rotation here
    reverse(temp.begin(), temp.end());
    reverse(temp.begin(),temp.end()-k);
    reverse(temp.end()-k, temp.end());

    // replace the order of non negative elements
    int j=0;
    for(int i=0;i<n;i++){
        if(nums[i]>=0){
            nums[i]=temp[j++];
        }
    }
   for(int i=0;i<n;i++){
    cout<<nums[i]<<" ";
   }
   cout<<endl;
}


//  kth largest element in array in sorted order (215)
// bhut hi gnda process ghatiya 
int kthlargest(vector<int> nums,int k){
    int n= nums.size();
    int index=0;
    int largest= INT_MIN;
    while(k>0){
        largest = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>=largest){
                largest= nums[i];
                index =i;
            }
        }
        swap(nums[index],nums[n-1]);
        n--;
        k--;
    }
    return largest;
    
}

// UNION OF TWO SORTED ARRAY 
// brute method

vector<int> unionofarr (vector<int> a, vector<int> b){
    int m= a.size(), n= b.size();
    set<int> s;
    vector<int> temp;

    for(int i =0;i<m;i++){
        s.insert(a[i]);
    }

    for(int i=0;i<n;i++){
        s.insert(b[i]);
    }
    for(auto i:s){
        temp.push_back(i);
    }
    return temp;

}

// optimal approach

vector<int> unionarr(vector<int> a, vector<int> b){
    int n= a.size();
    int m= b.size();
    vector<int> unionarr;

    int x=0;
    int y=0;

    while(x<n && y<m){
        if(a[x]<= b[y]){
            if(unionarr.size() ==0 || unionarr.back() != a[x]){
                unionarr.push_back(a[x]);
            }
             x++;
        }
        else{
            if(unionarr.size() ==0 || unionarr.back() != b[y]){
                unionarr.push_back(b[y]);
            }
            y++;
        }

    }

    while(x<n){
        if(a[x]<= b[y]){
            if(unionarr.size() ==0 || unionarr.back() != a[x]){
                unionarr.push_back(a[x]);
            }
             x++;
    }
}

while( y<m){
    if(unionarr.size() ==0 || unionarr.back() != b[y]){
                unionarr.push_back(b[y]);
            }
            y++;

}
return unionarr;


}
// int main(){
//     int arr[4] ={2,7,11,15};
//     vector<int> ans = twosum(arr,4,9);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }

//     vector<int> nums ={}
// }


// find missing number 
int missingNumber(vector<int>& nums) {
        // using map
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<=nums.size();i++){
            mp[i]++;
        }
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]--;
        }
        for(auto i:mp){
            if(i.second == 1){
               ans=i.first;
            }
        }
        return ans;
    } // tc = n ; sc= n;

    // more optimal 
int missingNumber(vector<int>& nums){
    // use sum of number method
    int sum=0;
    for(int i=0;i<=nums.size();i++){
        sum+=i;
    }
    
    for(int i=0;i<nums.size();i++){
        sum-=nums[i];
    }
    return sum;
}

//max consecutive ones 
 int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==1){
                int count=0;
                int j=i;
                while(j<nums.size() && nums[j]!=0){
                    count++;
                    j++;
                }
                ans= max(ans,count);
                i=j;
            }
            else{
     i++;
            }
       
            
        }
        return ans;
    }


// optimised approach
int findMaxConsecutiveOnes(vector<int>& nums){
    
    int ans=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            count=0;
        }
        else{
            count++;
            ans= max(count,ans);
        }
    }
    return ans;
}

// find single occured num rest are twice 
int singleNumber(vector<int>& nums) {
        int xorr =0;
        for(int i=0;i<nums.size();i++){
            xorr =xorr^nums[i];
        }
        return xorr;
    }

// LONGEST SUBARRAY WITH SUM K 
// two pointer approach
int longestsubarr(vector<int> arr,int k){
   
    int left=0,right=0;
    int n= arr.size();
    int sum= arr[0];
    int maxi=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }

        if(sum==k)
        {
            maxi= max(right-left+1,maxi);
        }
        right++;
        if(right<n) sum+=arr[right];

    }
    return maxi;
}

// subarray sum equal k (#560)
// this is valid for only positive numbers

int subarraySum(vector<int>& nums, int k) {
        int count=0;
    int left=0,right=0;
    int n= nums.size();
    int sum= nums[0];
    
    while(right<n){
        while(left<=right && sum>k){
            sum-=nums[left];
            left++;
        }
        if(sum==k){
            count++;
        }
        right++;
        if(right<n) sum+=nums[right];

    }
    return count;
    }

    // DUTCH NATIONAL FLAG ALGORITHM

    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int mid=0;

        while(mid>=low && mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high--]);
                // not mid++ here part after mid is not sorted yet 
            }
            else if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
                // mid++ can coz left is sorted
            }
            else{
                mid++;
            }
        }
    }


    class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     int n= nums.size();
    //     // using map
    //     unordered_map<int,int> mp;
    //     for(int i:nums){
    //         mp[i]++;
    //     }
    //     for(auto i:mp){
    //         if(i.second >n/2){
    //             return i.first;
    //         }
    //     }
    //     return -1;
    // }

// moore theoram'

int count=0;
int element=0;
for(int i=0;i<nums.size();i++){

    if(count==0){
        element= nums[i];
    }

    if(nums[i]==element){
        count++;
    }
    else{
        count--;
    }
}
    return element;
    }

};

class Solution {
public:
        // kadane algorithm
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           maxi= max(maxi,sum);
           if(sum<0){
            sum=0;
           }

        }
        return maxi;
        
    }
};

int main(){

}