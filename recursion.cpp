#include <iostream> 
using namespace std;

// PRINT NAME N TIMES
void printname(string name,int n){
    // base case
    if(n<=0){
        cout<<endl;
        return;
    }
    cout<<name<<endl;
    n--;
    printname(name,n);

}

// PRINT LINEARLLY UPTO N
void printlinear(int i,int n){
    // base case
    if(i>n){
        cout<<endl;
        return ;
    }
    cout<<i<<" ";
    // printlinear(i++,n); // can't use i++ post increment coz i never increment and never reach base case so stack overflow
    printlinear(++i,n);
}

void linearprint(int n){
    // base case
    if(n<=0){
        cout<<endl;
        return;
    }
    // linearprint(--n);// always print upto n-1 
    linearprint(n-1);
    cout<<n<<" ";

}


// PRINT REVERSE FROM N
void reverseprint(int n){
    // base case
    if(n<=0){
        cout<<endl;
        return;
    }
    cout<<n<<" ";
    reverseprint(--n);

}

// SUM OF FIRST N NUMBER

// parameteric way
void nsum(int sum,int n){
    // base case
    if(n==0){
        cout<<sum;
        return ;
    }
    sum+=n;
    nsum(sum,--n);   
}

// functional way
int nsum(int n){
    // base case
    if(n==0){
        return 0;
    }

    return n + nsum(n-1);
}

// FACTORIAL OF N
int factorial(int n){
    // base case
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

// REVERSE AN ARRAY 

// two pointer reversal
void reversearr(int arr[],int low,int high){
    // base case
    if(low>=high){
        return;
    }
    swap(arr[low],arr[high]);
   reversearr(arr,low+1,high-1);
}

// single pointer reversal
void reversearr1(int arr[],int i,int n){
    // base case
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reversearr1(arr,i+1,n);
}

// CHECK GIVEN STRING IS PALLINDORM OR NOT
bool ispallindrom (string name,int start){
    // base case
    if(start>=name.length()/2){
        return true;
    }
    if(name[start]!= name[name.length()-start-1]){
        return false;
    }
    return ispallindrom(name,start+1);
    
}

// MULTIPLE RECURSIVE CALLS

// fibonacci number tc = 2^n
int nthfibo(int n){
    // base case
    // if(n==1){
    //     return 1;
    // }
    // if(n==0){
    //     return 0;
    // }

    if(n<=1){
        return n;
    }
    return nthfibo(n-1) + nthfibo(n-2);
}

int main(){
    // string name ="Jai shree Ram";
    // printname(name,5);

    printname("Jai shree Ram",5);
    

    // int i=1, n=10;
    // print(i,n);

    printlinear(1,10);

    reverseprint(10);
    linearprint(10);

    nsum(0,3);
    cout<<nsum(3);
    cout<<factorial(5);
    cout<<endl;

    int arr[5]={1,2,3,4,5};
    // reversearr(arr,0,4);
    reversearr1(arr,0,5);
    for( int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<ispallindrom("nayana",0);

    cout<<nthfibo(5)<<endl;
}