class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // initially North
        char directions[] = {'N', 'E', 'S', 'W'};
        int dir = 0;
        int x = 0;
        int y = 0;
        int res = 0;
        std::set<std::vector<int>> mySet(obstacles.begin(), obstacles.end());
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -1) {
                dir = (dir + 1) % 4;
            } else if(commands[i] == -2) {
                dir = (dir + 3) % 4;
            } else {
                if(directions[dir] == 'N') {
                    for(int j = 0; j < commands[i]; j++) {
                        if(mySet.contains({x, y + 1})) {
                            break;
                        }
                        y++;
                    }
                } else if(directions[dir] == 'E') {
                    for(int j = 0; j < commands[i]; j++) {
                        if(mySet.contains({x + 1, y})) {
                            break;
                        }
                        x++;
                    }
                } else if(directions[dir] == 'S') {
                    for(int j = 0; j < commands[i]; j++) {
                        if(mySet.contains({x, y - 1})) {
                            break;
                        }
                        y--;
                    }
                } else{
                    for(int j = 0; j < commands[i]; j++) {
                        if(mySet.contains({x - 1, y})) {
                            break;
                        }
                        x--;
                    }
                }
            }
            res = max(res, x * x + y * y);
        }
        return res;

    }
};