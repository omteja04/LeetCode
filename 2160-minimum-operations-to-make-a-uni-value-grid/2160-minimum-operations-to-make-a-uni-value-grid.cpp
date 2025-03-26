class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &nums : grid) {
            for(auto &i : nums) {
                arr.push_back(i);
            }
        }
        sort(arr.begin(), arr.end());
        int reqRem = arr[0] % x;
        for(int i = 1; i< arr.size(); i++) {
            if(arr[i] % x != reqRem) {
                return -1;
            }
        }
        int median = arr[arr.size() / 2];
        cout << median;
        int operations = 0;
        for(int i = 0; i< arr.size(); i++) {
            operations += abs(arr[i] - median) / x;
        }
        return operations;

    }
};