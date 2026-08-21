class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto op: strs){
            string pp = op;
            sort(pp.begin(), pp.end());
            mp[pp].push_back(op);
        }
        vector<vector<string>>final;
        for(auto &pair : mp){
            final.push_back(pair.second);
        }
        return final;

    }
};
