class Solution {
public:
    vector<int>parent;
    int find(int u){

    if(parent[u]!=u)
        parent[u]=find(parent[u]);

    return parent[u];
}
    void unions(int u,int v){

    int pu=find(u);
    int pv=find(v);

    if(pu!=pv)
        parent[pv]=pu;
}
    int countComponents(int n, vector<vector<int>>& edges) {
    parent.resize(n);
    for(int i=0;i<n;i++)
        parent[i]=i;
    for(auto &edge:edges){
        unions(edge[0],edge[1]);
    }
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(find(i));
    }
    return st.size();
}
};
