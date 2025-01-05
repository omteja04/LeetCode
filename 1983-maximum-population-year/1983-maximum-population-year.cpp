class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> people(101, 0);

        for(auto &it : logs) {
            int birth = it[0];
            int death = it[1];
            people[birth - 1950]++;
            people[death - 1950]--;
        }
        for(int i = 1; i <= 100; i++) {
            people[i] += people[i - 1];
        }
        return max_element(people.begin(), people.end()) - people.begin() + 1950;
    }
};