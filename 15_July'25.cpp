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

//3136. Valid Word
// A word is considered valid if:
// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.
// Return true if word is valid, otherwise, return false.
// Notes:
// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.
 

// Approach:
// 1. Check if the length of the word is at least 3.
// 2. Check if the word contains only valid characters (digits and letters).
// 3. Check if the word contains at least one vowel and one consonant.
// 4. Return true if all conditions are met, otherwise return false.

// CODE:
class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }
        int vow=0;
        int cons=0;
        for(int i=0;i<word.length();i++){
            char curr=tolower(word[i]);
            if(curr=='a'|| curr=='e'|| curr=='i'|| curr=='o'|| curr=='u'){
                vow++;
            }
            if(isalpha(curr)){
                cons++;
            }
            if(!isdigit(curr) && !isalpha(curr)){
                return false;
            }
        }
        if(vow<1 || cons-vow<1){
            return false;
        }
        return true;
    }
};