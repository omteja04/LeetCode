import java.util.*;
class Pair{
    public final int freq;
    public final char ch;
    Pair(int freq, char ch) {
        this.freq = freq;
        this.ch = ch;
    }
}
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> p2.freq - p1.freq);
        if (a > 0) pq.offer(new Pair(a, 'a'));
        if (b > 0) pq.offer(new Pair(b, 'b'));
        if (c > 0) pq.offer(new Pair(c, 'c'));

        StringBuilder res = new StringBuilder();
        while(pq.size() > 1) {
            Pair p1 = pq.poll();
            int f1 = p1.freq;
            char c1 = p1.ch;

            if(res.length() <= 1) {
                res.append(c1);
                f1--;
            } else {
                if(res.charAt(res.length() - 1) == c1 && res.charAt(res.length() - 2) == c1) {
                    Pair p2 = pq.poll();
                    int f2  = p2.freq;
                    char c2  =p2.ch;
                    res.append(c2);
                    f2--;
                    if(f2 > 0) pq.offer(new Pair(f2, c2));
                } else {
                    res.append(c1);
                    f1--;
                }
            }
            if(f1 > 0) pq.offer(new Pair(f1, c1));
        }
        if(!pq.isEmpty()) {
            Pair p1 = pq.poll();
            int f1 = p1.freq;
            char c1 = p1.ch;
            if(f1 <= 1) res.append(c1);
            else {
                res.append(c1);
                res.append(c1);
            }
        }
        return res.toString();
    }
}