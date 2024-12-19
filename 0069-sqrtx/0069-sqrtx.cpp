
class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        long long int mid,ans=-1;;
        while(low<=high){
            mid=low+(high-low)/2;
            long long int sq=mid*mid;
            if(sq==x){
                return mid;
            }
            else if(sq>x){
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};