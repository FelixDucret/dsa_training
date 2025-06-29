#include "Hash_table.hpp"

HashTable::HashTable(int capacity) : capacity(capacity), size(0)
{
    table.resize(capacity, nullptr);
}

int HashTable::hash(int key)
{
    return key % capacity;
}

void HashTable::insert(int key, int value)
{
    int index = hash(key);
    while(table[index] != nullptr && table[index]->key != key)
    {
        index++;
        index = index % capacity;
    }

    if(table[index] != nullptr && table[index]->key == key)
    {
        table[index]->value = value;
    }
    else
    {
        table[index] = new Node(key, value);
        size++;

        if(capacity <= size * 2)
        {
            resize();
        }
    }
}

int HashTable::get(int key)
{
    int index = hash(key);
    while(table[index] != nullptr)
    {
        if(table[index]->key == key)
        {
            return table[index]->value;
        }
        index++;
        index = index % capacity;
    }
    return -1;
}

bool HashTable::remove(int key)
{
    int index = hash(key);
    while(table[index] != nullptr)
    {
        if(table[index]->key == key)
        {
            delete table[index];
            table[index] = nullptr;
            size--;
            return true;
        }
        index++;
        index = index % capacity;
    }
    return false;
}

int HashTable::getSize() const
{
    return size;
}

int HashTable::getCapacity() const
{
    return capacity;
}

void HashTable::resize()
{
    capacity *= 2;
    vector<Node*> newTable(capacity, nullptr);
    int counter = 0;
    int index = 0;
    while(counter != size)
    {
        if(table[index] != nullptr)
        {
            counter++;
            int newIndex = hash(table[index]->key);
            newTable[newIndex] = new Node(table[index]->key, table[index]->value);
            delete table[index];
            table[index] = nullptr;
        }
        index++;
    }
    table = newTable;
}