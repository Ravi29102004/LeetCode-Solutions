// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int n=prerequisites.size();
//         vector<vector<int>> adj(numCourses);  // Correct
//         for(auto & pre:prerequisites)
//         {
//             int u=pre[0];
//             int v=pre[1];
//             adj[u].push_back(v);

//         }

//         vector<int>InDeg(numCourses,0);
//         for(int i=0;i<n;i++)
//         {
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             InDeg[prerequisites[i][0]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(!InDeg[i])
//             q.push(i);
//             //int count=0;
//             vector<int>ans;

//             while(!q.empty())
//             {
//                 int node=q.front();
//                 q.pop();
//                 //count++;
//                 ans.push_back(node);

//                 //look at theneighbour
//                 for(int j=0;j<adj[node].size();j++)
//                 {
//                     InDeg[adj[node][j]]--;
//                     if(!InDeg[adj[node][j]])
//                     q.push(adj[node][j]);
//                 }

//             //        for (int neighbour : adj[node]) {
//             //     InDeg[neighbour]--;

//             //     if (InDeg[neighbour] == 0) {
//             //         q.push(neighbour);
//             //     }
//             // }
//             }
            
//         }
//         vector<int>temp;
//            // Step 5: Check for cycle
//         return ans.size()==numCourses ? ans : temp;
//     }

// };






class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);

        // Build graph: prerequisite -> course
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];

            adj[prerequisite].push_back(course);
            inDeg[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbour : adj[node]) {
                inDeg[neighbour]--;

                if (inDeg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans.size() == numCourses;
    }
};







