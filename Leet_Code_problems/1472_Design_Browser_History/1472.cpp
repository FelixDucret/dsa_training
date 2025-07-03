#include "1472.hpp"


LinkedListNode::LinkedListNode(LinkedListNode* previous, string value) : previous(previous), value(value), next(nullptr)
{}


BrowserHistory::BrowserHistory(string homepage)
{
    head = new LinkedListNode(nullptr, homepage);
}

void BrowserHistory::visit(string url)
{
    int forwardHistoryCounter = 0;
    while(head->next != nullptr)
    {
        head = head->next;
        forwardHistoryCounter++;
    }
    while(forwardHistoryCounter > 0)
    {
        head = head->previous;
        delete head->next;
        forwardHistoryCounter--;
    }
    
    LinkedListNode* newEntry = new LinkedListNode(head, url);
    head->next = newEntry;
    head = head->next;
}

string BrowserHistory::back(int steps)
{
    int i = 0;
    while(i < steps && head->previous != nullptr)
    {
        head = head->previous;
        i++;
    }
    return head->value;
}

string BrowserHistory::forward(int steps)
{
    int i = 0;
    while(i < steps && head->next != nullptr)
    {
        head = head->next;
        i++;
    }
    return head->value;
}

