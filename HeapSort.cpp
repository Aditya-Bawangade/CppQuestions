#include<stdio.h>
class  PriorityQueue{
    public:
    int arr[];
    int size;
    PriorityQueue(){
        arr[] = {};
        size = 0;
    }
    void Insert(int val);
    int Parent(int i);
    int LeftChild(int i);
    int RightChild(int i);
    int ShiftUp(int i);
    void Heapify(int i);
    int GetMax();
    void ChangePriority(int i, int p);
    void Remove(int i);
};
void PriorityQueue::Parent(int i){
    return (i-1)/2;
}
int PriorityQueue::LeftChild(int i){
    return ((2*i)+1);
}
int PriorityQueue::RightChild(int i){
    return((2*i)+2);
}
void PriorityQueue::ShiftUp(int i){
    while(i>0 && arr[Parent(i)]<arr[i]){
        swap(&arr[Parent(i)],&arr[i]);
        i = parent(i);
    }
}
void PriorityQueue::Heapify(int i){
    int largest = i;
    int left = LeftChild(i);
    int right = RightChild(i);
    if(left<=size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<= size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        Heapify(largest);
    }
}
void PriorityQueue::Insert(int val){
    size+=1;
    arr[size] = val;
    Shiftup(size);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
void Heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<N && arr[left]>arr[largest]){
        largest = left;
    } 
    if(right<N && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        Heapify(arr, N, largest);
    }
}
void HeapSort(int arr[], int N){
    for(int i = (N-2)/2; i>=0; i--){
        Heapify(arr,N,i);
    }
    for(int i= N-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        Heapify(arr,i,0);
    }
}
void printArray(int arra[], int limit){
    for(int i = 0; i < limit;i++){
        printf("%d->",arra[i]);
    }
    printf("Null");
}
int main(){
//     int arr[] = { 12, 11, 13, 5, 6, 7 };
//     int size = sizeof(arr)/sizeof(arr[0]);
//     HeapSort(arr,size);
//     printArray(arr,size);
    PriorityQueue q1;
    q1.Insert(45);
    q1.Insert(20);
    q1.Insert(14);
    q1.Insert(12);
    q1.Insert(31);
    q1.Insert(7);
    q1.Insert(11);
    q1.Insert(13);
    q1.Insert(7);
    
}