#include <iostream> 
using namespace std;

// // second largest element in array
// void secondlargest(int arr[],int n){
//     int largest =INT_MIN; // assum all element are +ve
//     int secondlargest = INT_MIN;
//     // for(int i=0;i<n;i++){
//     //     if(arr[i]> largest){
//     //         largest = arr[i];
//     //     }
//     //      if(arr[i]> secondlargest && arr[i] != largest){
//     //         secondlargest= arr[i];
//     //     }
//     // }
//     // cout<<"largest is : "<< largest<<endl;

//     for(int i=0;i<n;i++){
//         if(arr[i]> largest){
//             secondlargest= largest;
//             largest= arr[i];
//         }
//         else if( secondlargest < arr[i] && arr[i]< largest){
//                 secondlargest= arr[i];
//             }
//     }

//       cout<<"largest: "<< largest<<endl;
//     if(secondlargest == INT_MIN){
//         cout<<"second largest doesn't exist"<<endl;
//     }
//     else{
// cout<<"second largest: "<< secondlargest<<endl;
//     }
  
    


// } 

// //  second smallest 
// void secondsmallest (int arr[],int n){
//     int smallest =INT_MAX;
//     int secondsmallest =INT_MAX;

//     for(int i=0; i<n;i++){
//         if(arr[i]< smallest){
//             secondsmallest= smallest;
//             smallest=arr[i];
//         }
//         else if( arr[i] >smallest && arr[i] <secondsmallest){
//             secondsmallest = arr[i];
//         }
//     }
//     cout<<"smallest: "<<smallest<<endl;
//     if( secondsmallest == INT_MAX){
//         cout<<"second smallest doesn't exist"<<endl;
//     }
//     else{
//  cout<<"secondsmallest: "<<secondsmallest<<endl;
//     }
   
// }


// //  CHECK IF ARRAY IS SORTED 
// bool issorted (int arr[], int n){
//     for(int i=0;i<n;i++){
//         if(arr[i]>arr[i+1]){
//             return false;
//         }
//     }
//     return true;
// }

// // remove duplicates in place from sorted array
// void removedupli (int arr[], int n){
//     int i=0;
//     for(int j=1;j<n;j++){
//         if(arr[j] != arr[i]){
//             arr[i+1]= arr[j];
//             i++;
//         }
//     }
//     for( int k=0;k<i+1 ;k++){
//         cout<<arr[k]<<" ";
//     }
// }

// int main(){
//  int arr[6] ={1,1,2,2,3,3};
// //  secondlargest(arr,6);
// //  secondsmallest(arr,6);
// //  bool ans =issorted(arr,6);
// //  cout<<ans;
// removedupli(arr,6);


// }


// <!------------------------------Lecture 2 --------------------------------------!>

// ROTATE ARRAY TO LEFT SIDE K TIME

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftrotate (int arr[], int n,int k){
    k= k%n;
    int j=0;
   while( j<k){

for(int i=1;i<n;i++){
        swap(arr[i],arr[i-1]);}
                j++;
    }  print(arr,n);
}

// OPTIMISED WAY 
void reverse(int arr[],int s, int e){
    while(s<e){
        swap(arr[s++],arr[e--]); 
    }
}
void leftrotate1(int arr[],int n, int k){
     reverse(arr,0,n-1);
    
     reverse(arr,0,n-1-k);
     reverse(arr,n-k,n-1);

     print(arr,n);
}

//  RIGHT ROTATION OF ARRAY 
 void rightrotate(int arr[], int n, int k){
        k = k%n;
    //  brute method
    int j=0;
    while( j<k){
        for(int i=n-1;i>0;i--){
        swap(arr[i-1], arr[i]); }
                j++;
    }
    print(arr,n);
   
 }

//  OPTIMISED WAY 
void rightrotate1(int arr[], int n, int k){
    k = k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);

    print(arr,5);
}

//  MOVE ALL ZERO AT THE END SIDE OF ARRAY KEEPING THE ELEMENTS ORDER SAME

// using two pointer 
void movezero(int arr[],int n){
    int i=0;
    for(int j=0; j<n;j++){
        if(arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    print(arr,n);
    
}

// UNION OF TWO SORTED ARRAYS

// plus one to any array
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // first reverse then add then reverse
        reverse(digits.begin(),digits.end());
        int i=0;
        int carry=1;
        while(i<digits.size())
        {
            digits[i]+=carry;
            if(digits[i]<10){
                reverse(digits.begin(),digits.end());
                return digits;
            }
            digits[i++]=0;
            carry=1;
        }
        if(carry==1){
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
            return digits;
        }
        return digits;
        
    }
};

int main(){
    int arr[10] ={5,0,0,1,2,0,3,4,0,5};
    // leftrotate(arr,5,3);
    // leftrotate1(arr,5,3);
    // rightrotate1(arr,5,2);
    movezero(arr,10);

}
