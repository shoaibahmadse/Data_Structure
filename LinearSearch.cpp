#include<iostream>
using namespace std ;

int LinearSearch(int a[],int n,int s){
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if(s == a[i]){
            j = i;
            return i;
        }
    }
    return j;
}

int main(){
    
    int arr[]{5,2,5,2,5,2,4,7,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = LinearSearch(arr,n,4);

    if (index == -1)
    {
        cout << "Value not found";
    }else{
        cout << "Value Found at index: " << index << endl;
    }

    return 0 ;
}