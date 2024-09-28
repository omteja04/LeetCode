class MyCircularDeque {
public:
    int front;
    int rear;
    int k ;
    int length;
    int arr[1000];

    MyCircularDeque(int k) {
        this->k = k;
        front = 0;
        length = 0;
        rear = k - 1;

    }
    
    bool insertFront(int value) {
        if(length == k) return 0;
        front = (front - 1 + k) % k;
        arr[front] = value;
        length++;
        return 1;

    }
    
    bool insertLast(int value) {
        if(length == k) return 0;
        rear = (rear + 1) % k;
        arr[rear] = value;
        length++;
        return 1;

    }
    
    bool deleteFront() {
        if(length == 0) return 0;
        front = (front  + 1) % k;
        length--;
        return 1;
    }
    
    bool deleteLast() {
        if(length == 0) return 0;
        rear = (rear - 1 + k) % k;
        length--;
        return 1;
    }
    
    int getFront() {
        return (length == 0) ? -1 : arr[front];
    }
    
    int getRear() {
        return (length == 0) ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */