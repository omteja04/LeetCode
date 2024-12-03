class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int space = 0;
        string str = "";

        for(int i = 0; i  < s.length(); i++) {
            if(space < spaces.size() && i == spaces[space]) {
                str += " ";
                space++;
            }
            str += s[i];
        }
        return str;
        

    }
};