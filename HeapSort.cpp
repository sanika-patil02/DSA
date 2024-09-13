#include<iostream>
using namespace std;

class Heap{
    // int arr[10];
    public:
        void Max_heapsort(int arr[],int );
        void Max_heapify(int arr[],int ,int );
        void Min_heapsort(int arr[],int );
        void Min_heapify(int arr[],int ,int );
        void display(int arr[],int );

};

void Heap:: Max_heapify(int arr[],int i,int n){

    int temp;
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }

    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        
        Max_heapify(arr,largest,n);
    }

    

}

void Heap::Max_heapsort(int arr[],int n){
    int var;
    for(int i=n/2-1;i>=0;i--){           //buiding of max heap
        Max_heapify(arr,i,n);
    }

        for(int i=n-1;i>=0;i--){
            var=arr[0];
            arr[0]=arr[i];
            arr[i]=var;

            Max_heapify(arr,0,i);

        }
}


void Heap:: Min_heapify(int arr[],int i,int n){
    int temp;
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]<arr[largest]){
        largest=left;
    }

    if(right<n && arr[right]<arr[largest]){
        largest=right;
    }

    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        
        Min_heapify(arr,largest,n);
    }

    

}

void Heap::Min_heapsort(int arr[],int n){
    int var;
    for(int i=n/2-1;i>=0;i--){           //buiding of max heap
        Min_heapify(arr,i,n);
    }

        for(int i=n-1;i>=0;i--){
            var=arr[0];
            arr[0]=arr[i];
            arr[i]=var;

            Min_heapify(arr,0,i);

        }
}

void Heap::display(int arr [],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }

};

int main(){
    int size,ch,op;
    Heap h;

    cout<<"Enter how many elements you want to sort:";
    cin>>size;
    int arr[size];

    cout<<"Enter Elements:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Entered Elements:\n";
    h.display(arr,size);

    do{
    cout<<"\nWant to sort elements in which order:\n";
    cout<<"1.Ascending Order\n"<<"2.Decending Order\n";
    cin>>ch;

    switch(ch){
        case 1:
        cout<<"Ascending Order:";
        h.Max_heapsort(arr,size);
        h.display(arr,size);
        break;

        case 2:
        cout<<"decending Order:";
        h.Min_heapsort(arr,size);
        h.display(arr,size);
        break;

    }
    cout<<"\nDo you want to continue\n";
    cout<<"1.Yes\n"<<"2.No\n";
    cin>>op;
    }while(op==1);
return 0;
}