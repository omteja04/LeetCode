class Solution {
    // public boolean helper(String s, String goal, int n) {
    //     if(s.equals(goal)) return true;
    //     else if(n == s.length()) return false;
    //     return helper(s.substring(1) + s.charAt(0), goal, n + 1);
    // }
    public boolean rotateString(String s, String goal) {
        // return helper(s, goal, 0);
        if(s.length()!=goal.length())
        return false;
        String str=s+s;
        if(str.contains(goal))
        return true;
        return false;
    }
}