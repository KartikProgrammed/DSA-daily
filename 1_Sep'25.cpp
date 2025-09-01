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


// 1792. Maximum Average Pass Ratio

// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.


//Approach:-
// 1. We can use a max heap to store the classes based on the increase in pass ratio if we add an extra student to that class.
// 2. We can calculate the increase in pass ratio by adding an extra student to a class as follows:
//    increase = (passi + 1) / (totali + 1) - passi / totali
// 3. We can keep adding extra students to the class with the maximum increase in pass ratio until we run out of extra students.
// 4. Finally, we can calculate the average pass ratio of all the classes.


//CODE:-
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> maxHeap;
        for(int i=0;i<classes.size();i++){
            int a=classes[i][0];
            int b=classes[i][1];
            double curr = (double)classes[i][0] / classes[i][1];
            double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            maxHeap.push({newPr-curr,i});
        }

        while(extraStudents>0){
            int it=maxHeap.top().second;
            maxHeap.pop();
            classes[it][0]+=1;
            classes[it][1]+=1;
            double curr = (double)classes[it][0] / classes[it][1];
            double newPr = (double)(classes[it][0] + 1) / (classes[it][1] + 1);
            maxHeap.push({newPr-curr,it});
            extraStudents--;
        }
        
        double ans=0.0;
        for(int i=0;i<classes.size();i++){
            double passed=classes[i][0];
            double totsum=classes[i][1];
            ans+=passed/totsum;
        }
        return ans/classes.size();
    }
};