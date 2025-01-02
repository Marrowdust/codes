#include <iostream>
#include <cmath>
using namespace std;
int step=0;
int iteration=0;
int * QUICKSORT(int arr[], int size){
    if(size==0 or size ==1){
        step++;
        return arr;
    }
    srand(time(0));
    int n =rand()%(size);
    //n=0; //uncomment this line if you want it take a random pivot
    int pivot = arr[n];
     int * rightarray;
     int * leftarray;
     int * mergedarray;
     int size1,size2=0;
     step+=7;

swap(arr[0],arr[n]);
step+=3;
rightarray=new int [size];
leftarray=new int [size];
step+=2;
    
    int r=0;
    int l =0;
    step+=2;
    for(int i=0;i<size;i++){
        if(arr[i]==pivot){step++;continue;}
       if(arr[i]<=pivot){
     rightarray[r]=arr[i];
     r++;
     step++;
       }else{
        leftarray[l]=arr[i];
        l++;
        step++;
       }
    }
    rightarray=QUICKSORT(rightarray,r);
    leftarray=QUICKSORT(leftarray,l);
    step+=2;
    mergedarray=new int [size];
    step++;
for(int i = 0; i < r; i++){
    mergedarray[i] = rightarray[i];  
    step++;
    step+=3;// Copy smaller elements first
}
step++;
mergedarray[r] = pivot;          // Put pivot in the middle
for(int i = 0; i < l; i++){
    mergedarray[r+1+i] = leftarray[i];  
    step+=2;// Copy larger elements
    
}step++;
    return mergedarray;
}
int main(){
int array[100]={136, 75, 38, 175, 152, 111, 102, 146, 194, 129, 115, 160, 50, 74, 196, 143, 7, 135, 92, 149, 40, 15, 132, 76, 18, 32, 4, 84, 60, 124, 26, 2, 41, 39, 172, 10, 17, 158, 63, 144, 142, 36, 68, 20, 127, 104, 62, 150, 27, 163, 29, 185, 171, 177, 82, 181, 13, 100, 54, 77, 113, 31, 187, 189, 87, 67, 167, 157, 85, 69, 80, 122, 121, 90, 1, 24, 61, 107, 155, 159, 134, 37, 42, 140, 147, 199, 170, 198, 161, 114, 180, 120, 88, 66, 96, 22, 70, 48, 110, 105};

int size =100;
int* sorted=new int [size];
for(int i=0;i<size;i++){
    sorted[i]=array[i];
}
sorted=QUICKSORT(sorted,size);
cout<<"{";
for(int i=0; i<100; i++){
    if(i!=99){
    cout<<sorted[i] << ",";}
    else
    cout<<sorted[i]<<"}";
}


}
