#ifndef HASH_TABLE
#define HASH_TABLE

class HashTable {
private:
    int capacity;

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