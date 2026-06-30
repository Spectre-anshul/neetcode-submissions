// class Solution {
// public:
//     bool dfs(int i, vector<vector<int>>&adj, vector<int>&visited, vector<int>&pathvisited){
//         visited[i] = 1;
//         pathvisited[i] = 1;
//         for(auto neighbour: adj[i]){
//             if(!visited[neighbour]){
//                 if(!dfs(neighbour, adj, visited, pathvisited)) return false;
//             }
//             else if(pathvisited[neighbour]){
//                 return false;
//             }
//         }
//         pathvisited[i] = 0;
//         return true;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>>adj(numCourses);
//         for(int i=0; i<prerequisites.size(); i++){
//             int u = prerequisites[i][0];
//             int v = prerequisites[i][1];
//             adj[u].push_back(v);
//         }
//         vector<int>visited(numCourses, 0);
//         vector<int>pathvisited(numCourses, 0);
//         for(int i=0; i<numCourses; i++){
//             if(!visited[i]){
//                 if(!dfs(i, adj, visited, pathvisited)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &edge : prerequisites) {

            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int finished = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            finished++;

            for (auto neighbour : adj[node]) {

                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return finished == numCourses;
    }
};