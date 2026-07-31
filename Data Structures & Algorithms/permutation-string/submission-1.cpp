class Solution{
    public:
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size()) return false;
    
    vector<int>s1c(26,0);
    vector<int>s2c(26,0);
    for(int i=0; i<s1.size(); i++){
        s1c[s1[i] - 'a']++;
        s2c[s2[i] - 'a']++;
    }
    int match = 0;
    for(int i=0; i<26; i++){
        if(s1c[i]==s2c[i])match++;
    }
    int l=0;
    for(int r=s1.size(); r< s2.size(); r++){
        if(match == 26) return true;
        int index= s2[r] - 'a';
        s2c[index]++;
        if(s1c[index] == s2c[index]){
            match ++;
        }
        else if(s1c[index]+1 == s2c[index]){
            match --;
        }
        index = s2[l] - 'a';
        s2c[index]--;
        if(s1c[index] == s2c[index]){
            match++;
        }
        else if(s1c[index]-1 == s2c[index]){
            match--;
        }
        l++;
    }
    return match ==26;
}
};
