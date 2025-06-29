#include <vector>
#include <string>

using namespace std;

// Definition for a Pair
class Pair {
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};

class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ret;
        for(int i = 0; i < pairs.size(); i++) {
            int j = i - 1;
            while(pairs[j].key > pairs[j+1].key and j >= 0) {
                swap(pairs[j], pairs[j+1]);
                j--;
            }
            ret.push_back(pairs);
        }
        return ret;
    }
};
