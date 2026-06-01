//brute force if no repitition were allowed ------
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         string op;
//         for(int i=0; i<wordDict.size(); i++){
//             op+= wordDict[i];
//         }
//         return s==op;
//     }
// };

//recurssion 
// class Solution{
//     public:
//     bool word(int i, string s, vector<string>&wordDict){
//         if(i == s.size()) return true;

//         for(auto &op: wordDict){
//             if(i+ op.size() <= s.size() && s.substr(i, op.size()) == op){
//                 if(word(i+op.size(), s, wordDict)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>&wordDict){
//         return word(0,s,wordDict);
//     }
// };


//dp
class Solution {
public:

    bool word(int i,
              string &s,
              vector<int>& dp,
              vector<string>& wordDict){

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(auto &op : wordDict){

            if(i + op.size() <= s.size() &&
               s.substr(i, op.size()) == op){

                if(word(i + op.size(), s, dp, wordDict))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict){

        vector<int> dp(s.size(), -1);

        return word(0, s, dp, wordDict);
    }
};