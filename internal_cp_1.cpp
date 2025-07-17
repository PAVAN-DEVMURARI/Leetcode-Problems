#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int rotated(vector<int> &nums , int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] &&
                 target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
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
    int n, target;
    cin >> n >>  target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << rotated(nums, target) << endl;
    return 0;
}
