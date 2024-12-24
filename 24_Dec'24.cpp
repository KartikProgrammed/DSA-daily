#include <bits/stdc++.h>
using namespace std;

//this problem is premium enabled on LC so i had to generate test cases by myself :( lmk if theres any other tc which might be problematic 
//Finding Diameter of a undirected graph

//APPROACH:-
//find the farthest distance from any node (i took 0 since it is always available) the farthest node would be always 1 end of the Diameter
//then find the farthest distance from the previously calculated node this would be the other node of the Diameter


//CODE:-
int maxDiameter(vector<vector<int>> edges){
    int numNodes=edges.size()+1;
    unordered_map<int,vector<int>> adj;
    for(auto &iter:edges){
        int u=iter[0];
        int v=iter[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //find distances all from 0
    vector<int> distfromZero(numNodes,0);
    queue<int> q;
    q.push(0);
    vector<bool> visited(numNodes, false);
    visited[0]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int neighbour:adj[curr]){
            if(!visited[neighbour]){
                q.push(neighbour);
                distfromZero[neighbour]=distfromZero[curr]+1;
                visited[neighbour]=true;
            }            
        }
    }
    auto maxElementIt = max_element(distfromZero.begin(), distfromZero.end());
    int maxIndex1 = distance(distfromZero.begin(), maxElementIt);
    
    //max dist from 1 end node to the second end node
    vector<int> distfromMax(numNodes,0);
    queue<int> q2;
    q2.push(maxIndex1);
    vector<bool> visited2(numNodes, false);
    visited2[maxIndex1]=true;
    while(!q2.empty()){
        int curr=q2.front();
        q2.pop();
        for(int neighbour:adj[curr]){
            if(!visited2[neighbour]){
                q2.push(neighbour);
                distfromMax[neighbour]=distfromMax[curr]+1;
                visited2[neighbour]=true;
            }            
        }
    }
    int diameter=*max_element(distfromMax.begin(),distfromMax.end());
    return diameter;
}

int main() {
    // Test case 1: Simple tree with diameter 3
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    cout << "Diameter of Tree 1: " << maxDiameter(edges1) << endl; // Expected: 3

    // Test case 2: A tree with a single node (diameter 0)
    vector<vector<int>> edges2 = {};
    cout << "Diameter of Tree 2: " << maxDiameter(edges2) << endl; // Expected: 0

    // Test case 3: A chain tree (diameter 5)
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Diameter of Tree 3: " << maxDiameter(edges3) << endl; // Expected: 5

    // Test case 4: A more complex tree with multiple branches
    vector<vector<int>> edges4 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    cout << "Diameter of Tree 4: " << maxDiameter(edges4) << endl; // Expected: 4

    // Test case 5: Another tree with a different structure
    vector<vector<int>> edges5 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    cout << "Diameter of Tree 5: " << maxDiameter(edges5) << endl; // Expected: 6

    return 0;
}
