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



int main(){
    int arr[4] ={2,7,11,15};
    vector<int> ans = twosum(arr,4,9);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    vector<int> nums ={}
}