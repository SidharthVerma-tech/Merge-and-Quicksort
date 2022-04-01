#include <iostream>
using namespace std;
int partition(int *arr,int start,int end){
    int pivot = arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<pivot) count++;
    }
    int position = start+count;
    swap(arr[position],arr[start]);
    int i=start;
    int j=end;
    while(i<position && j>position){
        while(arr[i]<=arr[position]) i++;
        while(arr[j]>arr[position]) j--;
        if(i<position && j>position){
            swap(arr[i++],arr[j--]);
        }
    }
    return position;
    
}
void quickSort(int *arr,int start,int end){
    while(start>=end) return;
    int p=partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);

}
int main(){
    int arr[10]={1,3,5,2,8,4,7,9,10,6};
    quickSort(arr,0,9);
    for(int i=0;i<10;i++) cout<<arr[i]<<" ";
}