class Solution {
    public String makeFancyString(String s) {
        StringBuilder str = new StringBuilder();
        str.append(s.charAt(0));
        int n = s.length(), cnt = 1;
        for(int i = 1; i < n; i++) {
            int size = str.length();
            if(s.charAt(i) == str.charAt(size - 1)) {
                cnt++;
                if(cnt < 3) str.append(s.charAt(i));
            } else {
                cnt = 1;
                str.append(s.charAt(i));
            }
        }
        return str.toString();
    }
}