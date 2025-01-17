#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//2683. Neighboring Bitwise XOR
//A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.
// Specifically, for each index i in the range [0, n - 1]:
// If i = n - 1, then derived[i] = original[i] ⊕ original[0].
// Otherwise, derived[i] = original[i] ⊕ original[i + 1].
// Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.
// Return true if such an array exists or false otherwise.
// A binary array is an array containing only 0's and 1's

//APPROACH:-
//the xor sum of the derived array should be 0 if it is possible

//CODE:-
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorsum=0;
        for(int i=0;i<derived.size();i++){
            xorsum^=derived[i];
        }
        return xorsum==0?true:false;
    }
};