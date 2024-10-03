class Solution {
public:
    

    int tab(vector<int>& arr) {
        int n = arr.size();
        int past = 0;
        int just = arr[0];
        for(int i = 1 ; i < n; i++) {
            int take = arr[i];
            if(i > 1) take += past;
            int notTake = just;
            int curr = max(take, notTake);
            past = just;
            just = curr;
        }
        return just;
    }
    int rob(vector<int>& arr) {
    // Write your code here.
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);

        vector<int> temp1(arr.begin() + 1, arr.end());  
        vector<int> temp2(arr.begin(), arr.end() - 1);

        return max(tab(temp1), tab(temp2));


    }

};