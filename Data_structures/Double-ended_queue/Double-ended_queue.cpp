class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};
    
    
class Deque {
private:
    Node* dummyHead;
    Node* dummyTail;

public:
    Deque() {
        dummyHead = new Node(-1);
        dummyTail = new Node(-1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {
        return dummyHead->next == dummyTail;
    }

    void append(int value) {
        Node* insertNode = new Node(value);
        insertNode->prev = dummyTail->prev;
        insertNode->next = dummyTail;
        dummyTail->prev->next = insertNode;
        dummyTail->prev = insertNode;
    }

    void appendleft(int value) {
        Node* insertNode = new Node(value);
        insertNode->next = dummyHead->next;
        insertNode->prev = dummyHead;
        dummyHead->next->prev = insertNode;
        dummyHead->next = insertNode;
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int ret = dummyTail->prev->value;
        Node* toDelete = dummyTail->prev;
        dummyTail->prev = dummyTail->prev->prev;
        dummyTail->prev->next = dummyTail;
        delete[] toDelete;
        return ret;
    }

    int popleft() {
        if(dummyHead->next == dummyTail) {
            return -1;
        }
        int ret = dummyHead->next->value;
        Node* toDelete = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        dummyHead->next->prev = dummyHead;
        delete[] toDelete;
        return ret;
    }
};
