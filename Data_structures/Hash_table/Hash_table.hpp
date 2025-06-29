#ifndef HASH_TABLE
#define HASH_TABLE

#include <vector>

using namespace std;

class Node {
public:
    int key;
    int value;

    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}

};

class HashTable {
private:
    int capacity;
    int size;

    vector<Node*> table;

    int hash(int key);

public:
    HashTable(int capacity);

    void insert(int key, int value);

    int get(int key);

    bool remove(int key);

    int getSize() const;

    int getCapacity() const;

    void resize();
};


#endif