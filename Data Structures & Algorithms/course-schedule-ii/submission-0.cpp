class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>final;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for(auto node: prerequisites){
            int course = node[0];
            int prereq = node[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        int finish = 0;
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            finish++;
            final.push_back(curr);
            for(auto op: adj[curr]){
                indegree[op]--;
                if(indegree[op] == 0){
                    q.push(op);
                }
            }
        }
        if(finish == numCourses) return final;
        else{
            final.clear();
            return final;
        }
    }
};
