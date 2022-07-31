// Question - implement circular queue using vector

#include <bits/stdc++.h>
#define INIT_SIZE 5
using namespace std;

template <typename T>
class CircularQueue {
    vector<T> q;
    int head;
    int rear;
    int cs;
    int ms;

    public:
    CircularQueue(int maxSize = INIT_SIZE){
        q = vector<int>(maxSize,0);
        cs = 0;
        ms = maxSize;
        head = 0;
        rear = maxSize-1;
    }

    bool push(T data){
        if (cs == ms){
            cout<<"Can't insert element, queue full!"<<endl;
            return false;
        }
        
        cs++;
        rear = (rear+1)%ms;
        q[rear] = data;
        cout<<"Element "<<data<<" inserted into queue"<<endl;
        return true;
    }

    bool pop(){
        if (cs == 0){
            cout<<"Can't pop element, queue empty!"<<endl;
            return false;
        }

        cs--;
        int data = q[head];
        q[head] = 0;
        head = (head+1)%ms;
        cout<<"Element "<<data<<" popped from queue"<<endl;
        return true;
    }

    T front(){
        if (cs == 0){
            T garbageVal;
            cout<<"Can't show element at front, queue empty!"<<endl;
            return garbageVal;
        }
        
        return q[head];
    }

    int size(){
        return cs;
    }

    bool empty(){
        return (cs == 0);
    }
};

// driver code
int main() {
    CircularQueue<int> cq;
    for (int i=0; i<10; i++){
        cq.push(i);
        cout<<cq.front()<<endl;
    }
    cout<<endl;
    for (int i=0; i<10; i++){
        cq.pop();
        cout<<cq.front()<<endl;
    }
    cout<<endl;
    for (int i=0; i<5; i++){
        cq.push(i);
        cout<<cq.front()<<endl;
    }
    cout<<endl;
    cq.pop();
    cout<<cq.front()<<endl;
    cq.pop();
    cout<<cq.front()<<endl;
    cq.push(100);
    cout<<cq.front()<<endl;
    cq.push(101);
    cout<<cq.front()<<endl;
    cq.push(102);
    cout<<cq.front()<<endl;
    return 0;
}

