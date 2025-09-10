class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size();
        unordered_set<int> usersToTeach;
        for(auto &friendship : friendships) {
            int user1 = friendship[0] - 1;
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;
            for(auto &lang1 : languages[user1]) {
                for(auto &lang2 : languages[user2]) {
                    if(lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate) {
                    break;
                }
            }
            if(!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }
        int minUsersToTeach = languages.size() + 1;
        for(int l = 1; l <= n; l++) {
            int cnt = 0;
            for(auto &user : usersToTeach) {
                bool knowsLanguage = false;
                for (int lang : languages[user]) {
                    if (lang == l) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if (!knowsLanguage) cnt++;
            }
            minUsersToTeach = min(cnt, minUsersToTeach);
        }
        return minUsersToTeach;
    }
};