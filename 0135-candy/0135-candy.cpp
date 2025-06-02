class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        vector<int>candies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] ){
                candies[i] = candies[i-1]+1;
            }
        }
        for(int i:candies){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] and candies[i] <= candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
        }
        for(int i:candies){
            cout<<i<<" ";
        }
        cout<<endl;
        return accumulate(candies.begin(),candies.end(),0);



    }
};