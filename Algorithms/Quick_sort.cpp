#include <vector>
#include <algorithm>


// Definition for a Pair
class Pair {
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};


class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortHelper(vector<Pair>& pairs, int s, int e) {
        if (e - s + 1 <= 1) {
            return;
        }
        Pair pivot = pairs[e];
        int left = s;
        for(int i = s; i < e; i++) {
            if(pairs[i].key < pivot.key) {
                swap(pairs[left], pairs[i]);
                left++;
            }
        }

        pairs[e] = pairs[left];
        pairs[left] = pivot;

        quickSortHelper(pairs, s, left - 1);
        quickSortHelper(pairs, left + 1, e);
    }
};
