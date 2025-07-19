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

//1233. Remove Sub-Folders from the Filesystem
// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

// Approach:
// 1. Sort the folders lexicographically.
// 2. Use a vector to store the result.
// 3. Iterate through the sorted folders and check if the current folder is a sub-folder of the last added folder.
// 4. If it is not a sub-folder, add it to the result.
// 5. Return the result vector.

// CODE:
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(),folder.end());
        res.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string curr=folder[i];
            string prev=res.back();
            prev+='/';
            if(curr.find(prev)!=0){
                res.push_back(curr);
            }
        }
        return res;
    }
};