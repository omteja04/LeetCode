class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        int preMul=1;
        int postMul=1;
        int n=nums.size();
        vector<int>res(n,1);
        for(int i=1;i<n;i++){
            preMul*=nums[i-1];
            res[i]=preMul;
        }
        for(int i=n-2;i>=0;i--){
            postMul*=nums[i+1];
            res[i]*=postMul;
        }
        

        return res;
    }
};