#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//3403. Find the Lexicographically Largest String From the Box I
// You are given a string word, and an integer numFriends.
// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

//Approach:
//start from the end of the string and compare lexicographically with the current largest string.
//return the largest string found.

// CODE:
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int n=word.size();
        int reqLen=n-numFriends+1;
        string res="";
        for(int i=0;i<n;i++){
            res=max(res,word.substr(i,reqLen));
        }
        return res;
    }
};

