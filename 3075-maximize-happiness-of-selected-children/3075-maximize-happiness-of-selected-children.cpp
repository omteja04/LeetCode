class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

    int n = happiness.size();
    sort(happiness.begin(), happiness.end(), greater<int>());

    long long maxHappinessSum = 0;
    for (int i = 0; i < k; i++) {
         maxHappinessSum += max(happiness[i] - i, 0);
            
    }


    return maxHappinessSum;
        
        
    }
};