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

//1408. String Matching in an Array
//Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

//APPROACH:-
//brute force

//CODE:-
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; 
                }
            }
        }
        return result;
    }
};
