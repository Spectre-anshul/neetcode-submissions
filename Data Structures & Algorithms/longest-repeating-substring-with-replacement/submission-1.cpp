class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, maxf = 0, res = 0;
        unordered_map<char, int>op;
        for(int r=0; r<s.size(); r++){
            op[s[r]]++;
            maxf = max(maxf, op[s[r]]);
            if((r-l+1) -maxf > k){
                op[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
