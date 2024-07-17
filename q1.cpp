#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

long long int count(int coins[], int N, int sum) {
    vector<long long int> dp(sum + 1, 0);
    dp[0] = 1;  
    for (int i = 0; i < N; ++i) {
        for (int j = coins[i]; j <= sum; ++j) {
            dp[j] = (dp[j] + dp[j-coins[i]]) % MOD;
        }
    }

    return dp[sum];
}

int main() {
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    long long int ans = count(c, n, x) % MOD;
    cout << ans << endl;
    return 0;
}
