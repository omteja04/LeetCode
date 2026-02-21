public class Solution {
    public int CountPrimeSetBits(int left, int right)
    {
        HashSet<int> set = new() {2,3,5,7,11,13,17,19};
        var res = 0;
        for(var i = left; i <= right; i++)
        {
            var temp = i;
            var cnt = 0;
            while(temp != 0)
            {
                if((temp & 1) == 1)
                {
                    cnt++;
                }
                temp >>= 1;
            }
            if(set.Contains(cnt))
            {
                res++;
            }
        }
        return res;
    }
}