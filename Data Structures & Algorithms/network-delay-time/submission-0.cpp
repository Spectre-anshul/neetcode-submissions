class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto time: times){
            int source = time[0];
            int target = time[1];
            int weight = time[2];
            adj[source].push_back({weight, target}); 
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto[weight, node] = pq.top();
            pq.pop();
            if(weight > dist[node]) continue;
            for(auto op: adj[node]){
                int wei = op.first;
                int neig = op.second;
                if(wei + weight < dist[neig]){
                    dist[neig] = weight + wei;
                    pq.push({dist[neig], neig});
                }
            }
        }
        int ans = 0;
        for(int i=1;  i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
