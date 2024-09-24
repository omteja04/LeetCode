class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<String> mySet = new HashSet<>();
        for(int num : arr1) {
            String str = Integer.toString(num);
            for(int i = 1; i <= str.length(); i++) {
                mySet.add(str.substring(0, i));
            }
        }
        int cnt = 0;
        for(int num : arr2) {
            String str = Integer.toString(num);
            for(int i = 1; i <= str.length(); i++) {
                String myString = str.substring(0, i);
                if(mySet.contains(myString)) {
                    cnt = Integer.max(cnt, myString.length());
                }
            }
        }
        return cnt;

    }
}