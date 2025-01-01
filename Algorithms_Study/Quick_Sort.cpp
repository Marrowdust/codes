#include <iostream>
using namespace std;
int* QUICKSORT(int arr[], int size){
    if(size==0 or size ==1){
        return arr;
    }
    int pivot = arr[0];
     int * rightarray;
     int * leftarray;
     int * mergedarray;
     int size1,size2=0;

    if(size%2==0){
        size1=size/2;
        size2=size/2;
        rightarray = new int [size1];
        leftarray = new int [size2];
    }else{
        size1=size/2;
        size2=size-size1;
        rightarray = new int [size1];
        leftarray = new int [size2];

    }
    int r=0;
    int l =0;
    for(int i=1;i<size;i++){
       if(arr[i]<=pivot){
     rightarray[r]=arr[i];
     r++;
       }else{
        leftarray[l]=arr[i];
        l++;
       }
    }
    rightarray=QUICKSORT(rightarray,r);
    leftarray=QUICKSORT(leftarray,l);
    mergedarray=new int [size];
for(int i = 0; i < r; i++){
    mergedarray[i] = rightarray[i];  // Copy smaller elements first
}
mergedarray[r] = pivot;          // Put pivot in the middle
for(int i = 0; i < l; i++){
    mergedarray[r+1+i] = leftarray[i];  // Copy larger elements
}
    return mergedarray;
}
int main(){
int size=10;
int * arr =new int [size];
   for(int i = 0; i < size; i++) {
        arr[i] = size - i;  // This will fill it with 10,9,8,7,6,5,4,3,2,1
    }
arr=QUICKSORT(arr,size);

for(int i=0;i<size;i++){
    cout<<arr[i]<<"\t";
}

}
