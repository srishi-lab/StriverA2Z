#include <iostream>
using namespace std;

// SELECTION SORT
        // find minimal -> swap it from first -> minimize the arr size
void selectionsort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){ // last itself sorted 
        // find minimum in given arr
        int min= INT_MAX;
        int index=0;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min= arr[j];
                index=j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

// BUBBLE SPRT
void bubblesort(int arr[],int n){
    // for whole arr
    for(int i=0;i<n-1;i++){
        // find max by adjacent swapping
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//INSERTION SORT
void insertionsort(int arr[],int n){
    // transverse whole array
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }

}

// MERGE SORT

void merge(int arr[],int low,int mid,int high){
    // take a big array 
   vector<int> temp;
    int left=low;
    int right= mid+1;
    int index=0;

    while(left<=mid && right <=high){
        if(arr[left]<=arr[right]){
            // temp[index++]= arr[left++];
            temp.push_back(arr[left++]);
        }
        else{
            // temp[index++]=arr[right++];
            temp.push_back(arr[right++]);
        }
    }

        while(left<=mid)
        {
            // temp[index++]=arr[left++];
            temp.push_back(arr[left++]);
        }
    
        while(right<=high){
            // temp[index++]=arr[right++];
            temp.push_back(arr[right++]);
        }

        for(int i=low;i<=high;i++){
            arr[i]= temp[i-low];
        }

}
void mergesort(int arr[],int low ,int high){
    // base case
    if(low>=high){
        return;
    }
    int mid = low + (high-low)/2;

    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

// QUICK SORT
// for asceding order

int findindex(int arr[],int low,int high){
    int pivot =arr[low];
    int i=low;
    int j= high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]); // we know that this time j will at that position which is smaller but crosses i<j condition 
    return j;
    
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pivotindex = findindex(arr,low,high);
        quicksort(arr,low,pivotindex-1);
        quicksort(arr,pivotindex+1,high);
    }
}

// for descending order
int findind(int arr[],int low,int high ){
    int pivot= arr[low];
    int i= low;
    int j=high;

    while(i<j){
        while(arr[i]>pivot && i<high){
            i++;
        }
        while(arr[j]<pivot && j>low){
            j--;
        }
        if(i<j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quick(int arr[],int low,int high){
    if(low<high){
        int pivotind = findind(arr,low,high);
        quick(arr,low,pivotind-1);
        quick(arr,pivotind+1,high);
    }
}

// common 
void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[5] ={11,5,4,6,2};
    // selectionsort(arr,5);
    // print(arr,5);
    // bubblesort(arr,5);
    // print(arr,5);
    // insertionsort(arr,5);
    // print(arr,5);
    // mergesort(arr,0,4);
    // print(arr,5);
    // quicksort(arr,0,4);
    // print(arr,5);
    quick(arr,0,4);
    print(arr,5);
}