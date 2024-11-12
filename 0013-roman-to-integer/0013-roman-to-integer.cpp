class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char,int>m;
        int ans=0;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        for(int i=0;i<str.size();i++){
            if(m[str[i]]<m[str[i+1]]){
                ans-=m[str[i]];
            }
            else ans+=m[str[i]];
        }
        return ans;
    }
};