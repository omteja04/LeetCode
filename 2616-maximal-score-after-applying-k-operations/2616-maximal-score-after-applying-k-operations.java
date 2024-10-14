import java.util.*;
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for(int i = 0; i  <nums.length; i++) {
            pq.add((long)nums[i]);
        }
        Long score = 0l;
        for(int i = 0 ; i < k; i++) {
            long top = pq.poll();
            score += top;
            top = (int) Math.ceil(top / 3.0);
            pq.add(top);
        }
        return score;
    }
}