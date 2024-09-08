class Solution {
    public String convertDateToBinary(String date) {
        String [] s = new String[3];
        s[0] = date.substring(0, 4);
        s[1] = date.substring(5, 7);
        s[2] = date.substring(8);
        String a = Integer.toBinaryString(Integer.parseInt(s[0]));
        String b = Integer.toBinaryString(Integer.parseInt(s[1]));
        String c = Integer.toBinaryString(Integer.parseInt(s[2]));
        return a + "-" + b + "-" + c;
        
    }
}