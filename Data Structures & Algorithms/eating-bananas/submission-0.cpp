class Solution {
public:
    long long hours(vector<int>&piles, int speed){
        long long totalspent = 0;
        for(auto op: piles){
            totalspent += ceil((double)op/speed);
        }
        return totalspent;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi = *max_element(piles.begin(), piles.end());
        long long low = 1, ans = maxi, high = maxi;
        while(low<=high){
            long long  mid = low + (high - low)/2;
            long long  timespent = hours(piles, mid);
            if(timespent <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
