#include <string>

using namespace std;

class LinkedListNode
{
public:
    LinkedListNode* previous;
    LinkedListNode* next;
    string value;

    LinkedListNode(LinkedListNode* previous, string value);
};

class BrowserHistory 
{
private:
    LinkedListNode* head;

public:
    BrowserHistory(string homepage);
    
    void visit(string url);
    
    string back(int steps);
    
    string forward(int steps);
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */