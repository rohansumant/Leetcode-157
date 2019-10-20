typedef long long ll;
const ll MOD = 1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> mp[5];
        mp[0] = {1};
        mp[1] = {0,2};
        mp[2] = {0,1,3,4};
        mp[3] = {2,4};
        mp[4] = {0};
        
        vector<vector<ll>> dp(n+1,vector<ll>(5,0));
        for(int i=0;i<5;i++) {
            dp[1][i] = 1;
        }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<5;j++) {
                for(int next:mp[j]) {
                    dp[i+1][next] = (dp[i+1][next] + dp[i][j]) % MOD;
                }
            }
        }
        ll ans = 0;
        for(int i=0;i<5;i++) {
            ans = (ans + dp[n][i]) % MOD;
        }
        return ans;
    }
};
