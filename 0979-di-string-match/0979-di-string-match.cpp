class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int inc = 0,dec = 0;
        for (char i : s){
            if (i == 'I')inc++;
            else dec++;
        }
        int firstVal = dec;
        vector<int> vis(n+1,0);
        vector<int> res(n+1,0);
        res[0] = firstVal;
        vis[firstVal]++;
        for (int i=0; i<n; i++){
            if (s[i]=='I')firstVal++;
            else firstVal--;
            while (vis[firstVal]){
                if (s[i]=='I')firstVal++;
                else firstVal--;
            }
            res[i+1] = firstVal;
            vis[firstVal]++;
        }
        return res;
    }
};