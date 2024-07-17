#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix matMul(const Matrix &a, const Matrix &b)
{
    int n = a.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

Matrix matPow(Matrix base, long long exp)
{
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = matMul(result, base);
        }
        base = matMul(base, base);
        exp /= 2;
    }
    return result;
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<vector<int>> vec(n, vector<int>(n));
    Matrix adj(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j])
            {
                adj[i][j] = 1;
            }
        }
    }

    Matrix result = matPow(adj, k);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = (ans + result[i][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
