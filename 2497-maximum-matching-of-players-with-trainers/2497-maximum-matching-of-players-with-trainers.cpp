class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        int playerInd = players.size() - 1, trainerInd = trainers.size() - 1;
        while(playerInd >= 0 && trainerInd >= 0) {
            if(players[playerInd] <= trainers[trainerInd]) {
                ans++;
                trainerInd--;
            }
            playerInd--;
        }
        return ans;

    }
};