#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#define int long long
#define mod 10007
using namespace std;
long long num_prefix_sum_precalculation[100005][2], index_prefix_sum_precalculation[100005][2], total_prefix_sum_precalculation[100005][2], nums[100005], colour[100005], num_count[100005][2];
signed main(){
    int n, m, i, j, k, total = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++){
        cin >> nums[i];
    }
    for (i = 1; i <= n; i++){
        cin >> colour[i];
    }
    for (i = 1; i <= n; i++){
        // cerr << ((total_prefix_sum_precalculation[colour[i]][i % 2] % mod) + (index_prefix_sum_precalculation[colour[i]][i % 2] * nums[i] % mod) + (i * num_prefix_sum_precalculation[colour[i]][i % 2] % mod) + (num_count[colour[i]][i % 2] * nums[i] * i % mod)) % mod << "\n";
        total += ((total_prefix_sum_precalculation[colour[i]][i % 2] % mod) + (index_prefix_sum_precalculation[colour[i]][i % 2] * (nums[i] % mod) % mod) + ((i % mod) * num_prefix_sum_precalculation[colour[i]][i % 2] % mod) + (num_count[colour[i]][i % 2] * (nums[i] % mod) * (i % mod) % mod)) % mod;
        num_prefix_sum_precalculation[colour[i]][i % 2] += (nums[i] % mod);
        num_prefix_sum_precalculation[colour[i]][i % 2] %= mod;
        index_prefix_sum_precalculation[colour[i]][i % 2] += (i % mod);
        index_prefix_sum_precalculation[colour[i]][i % 2] %= mod;
        total_prefix_sum_precalculation[colour[i]][i % 2] += (nums[i] % mod) * (i % mod);
        total_prefix_sum_precalculation[colour[i]][i % 2] %= mod;
        num_count[colour[i]][i % 2]++;
        num_count[colour[i]][i % 2] %= mod;
    }
    cout << total << "\n";
    return 0;
}