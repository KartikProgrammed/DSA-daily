#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Problem 216:-Combination Sum III
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

//APPOACH:- using a set we can sort the numbers and also avoid duplicates
//so i'll be using a set initially and converting it to vector after the computations since thats the return type required


//CODE:-
class Solution {
public:
    void recursion(set<set<int>> &result,int tot,set<int> &db,int k,int n){
        if(db.size()==k && tot==n){
            result.insert(db); //if the size matches k and the sum matches n push it into the set of sets result
            return;
        }
        for(int i=1;i<=9;i++){
            if(db.size()>=k || tot>n){ //break if any of the conditions go wrong
                break;
            }
            if (db.find(i) != db.end()){
                continue; //if an element already in the set, continue(so that it isnt added to the total in the recursion call)
            }
            else{
                db.insert(i); //insert into the db set
                recursion(result,tot+i,db,k,n); //add the total to i as new total and run recursion
                db.erase(i); //backtracking
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<set<int>> result; //easier to satisfy the sorted condition and no duplicate condition
        set<int> db;
        recursion(result,0,db,k,n);
        vector<vector<int>> resultVector;
        for (const auto& innerSet : result) { //conversion of set to vector since vector is the return type
            resultVector.push_back(vector<int>(innerSet.begin(), innerSet.end()));
        }
        return resultVector;
    }
};
