class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0;
        int n=s.size();
        int i=0,j=n-1;

        while(i<j){

            if(s[i]=='1'){
                if(s[j]=='0'){
                    res+=j-i;
                    i++;
                }
                j--;
            }
            else{
                if(s[j]=='1'){
                    j--;
                }
                i++;
            }

        }
        return res;
    }
};