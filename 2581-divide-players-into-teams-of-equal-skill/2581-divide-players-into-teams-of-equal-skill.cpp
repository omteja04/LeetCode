class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int low = 0;
        int high = n - 1;
        long long ref = skill[low] + skill[high];
        while(low < high) {
            long long curr = skill[low] + skill[high];
            long long chemistry = skill[low]*skill[high];
            if(curr != ref) return -1;
            ans += chemistry;
            low++;
            high--;
        }
        return ans;
    }
};