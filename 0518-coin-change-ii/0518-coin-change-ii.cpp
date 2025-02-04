class Solution {
public:
    int dp[301][5001];
    int Find(int idx, int amount, vector<int>&coins, int n){
        if(idx >= n ){
            return (amount == 0) ? 1 : 0;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        int left = 0 , right = 0;
        if(amount >= coins[idx]){
            left = Find(idx,amount-coins[idx],coins,n);
        }
        right = Find(idx+1,amount,coins,n);
        return dp[idx][amount] = left + right;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = Find(0,amount,coins,n);

        return ans;
    }
};