#include <iostream>
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

// using hash map
vector<int> twosum(vector<int> nums,int target){
    unordered_map<int, int> map;
    int n= nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i])
    }
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


int main(){
    int arr[4] ={2,7,11,15};
    vector<int> ans = twosum(arr,4,9);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    vector<int> nums ={}
}