#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int work(vector<int>& nums) {
    int n = nums.size();
    // int minVal = *min_element(nums.begin(), nums.end());
    // int maxVal = *max_element(nums.begin(), nums.end());
    int ans = INT_MAX; 
    for (int i = 0; i < n; ++i) {
        vector<int> temp = nums; 
        temp[i] *= 2; 
        int newMinVal = *min_element(temp.begin(), temp.end()); 
        int newMaxVal = *max_element(temp.begin(), temp.end()); 
        int newDiff = newMaxVal - newMinVal; 
        ans = min(ans, newDiff); 
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    cout << work(nums) << endl;
    return 0;
}