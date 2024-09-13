#include <iostream>
#define n 2
using namespace std;

class CQueue{
    int front=-1;
    int rear=-1;
    // int front;
    // int rear;
    int queue[n];
    public:
    // CQueue(){
    //     front=-1;
    //     rear=-1;
    // }
    void enqueue();
    void dequeue();
    void display();
};

void CQueue::enqueue(){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        cout<<"Enter element:\n";
        cin>>queue[rear];
    }
    
    else if(front==(rear+1)%n){
        cout<<"Queue is full\n";
    }
    
    else{
        rear=(rear+1)%n;
        cout<<"Enter element:\n";
        cin>>queue[rear];
    }

}

void CQueue::dequeue(){
    int val;
    if(front==-1 && rear==-1){
        cout<<"Queue is empty\n";
    }
    
    else if(front==rear){
        int val;
        val=queue[front];
        cout<<"Dequeued element is"<<val;
        front=-1;
        rear=-1;
    }
    
    else {
        val=queue[front];
        cout<<"Dequeued element is"<<val;
        front=(front+1)%n;
    }
}

void CQueue::display(){
    int temp;
    if(front==-1 && rear==-1){
        cout<<"Queue is empty\n";
    }
    
    else{
        temp=front;
        while(temp!=rear){
            cout<<queue[temp]<<"\t";
            temp=(temp+1)%n;
        }
        cout<<queue[temp];
    }
    
    
}

int main(){
    int ch,op;
    CQueue obj;
    do{
    cout<<"Enter Choice from below dropdown:";
    cout<<"\n1.Enqueue \n"<<"2.Dequeue\n"<<"3.Display\n";
    cin>>ch;
    switch(ch){
        case 1:
        obj.enqueue();
        break;
        
        case 2:
        obj.dequeue();
        break;

        case 3:
        obj.display();
        break;

    }
    cout<<"Do you want to continue:\n";
    cout<<"1.Yes\n"<<"2.No\n";
    cin>>op;
    }while(op==1);
}