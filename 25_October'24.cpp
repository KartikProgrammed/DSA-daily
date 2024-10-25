#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

// //Daily Problem -1233:  remove sub folders from the filesystem
// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 
//APPROACH 1:- using sets(not intruisive but nice solution)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st(begin(folder),end(folder));
        vector<string> result;
        for(auto currfolder:folder){
            bool found=false;
            string temp=currfolder;
            while(!currfolder.empty()){
                size_t position=currfolder.find_last_of('/');
                currfolder=currfolder.substr(0,position);
                if(st.find(currfolder)!=st.end()){
                    found=true;
                    break;
                }
            }
            if(!found){
                result.push_back(temp);
            }
        }
        return result;
    }
}; 

//APPROACH 2:- Sorting the folders (very intruisive and beats 93%+)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        sort(folder.begin(),folder.end());
        result.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string currfolder=folder[i];
            string prev=result.back();
            prev+="/";
            if(currfolder.find(prev)!=0){
                result.push_back(currfolder);
            }
        }
        return result;
    }
};