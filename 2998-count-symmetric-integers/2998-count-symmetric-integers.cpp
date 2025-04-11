class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.length()%2==0 and accumulate(s.begin(),s.begin()+s.length()/2,0)==accumulate(s.begin()+s.length()/2,s.end(),0))
            cnt++;
        }
        return cnt;
    }
};