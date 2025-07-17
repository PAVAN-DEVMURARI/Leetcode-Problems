#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ll test=1;
//cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> temp;
    int sum = 0;
    map <vector<int>, int> mp;
    for (int i = 0;i<n;i++)
    {
        if (nums[i] < 0)
        {
            if (!temp.empty()) {
                mp[temp] = sum;
            }
            sum = 0;
            temp.clear();
        }
        else
        {
            temp.push_back(nums[i]);
            sum += nums[i];
        }
    }
    if (!temp.empty()) {
        mp[temp] = sum;
    }

    int maxi = 0;
    int idx = 0;
    for (auto it:mp)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
            if (idx<it.first.size())
            {
                idx = it.first.size();
            }
        }
    }

    for (auto it:mp)
    {
        if (it.second == maxi && it.first.size() == idx)
        {
            for (auto t:it.first)
            {
                cout << t << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
