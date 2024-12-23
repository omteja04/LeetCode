/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int indexOf(int [] arr, int num) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == num) {
                return i;
            }
        }
        return -1;
    }
    private void swap(int[] arr, int i, int idx) {
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    private int minSwaps(int[] arr, int k) {
        int ans = 0;
        int temp[] = Arrays.copyOfRange(arr, 0, k);
        Arrays.sort(temp);
        for(int i = 0;i < k; i++) {
            if(arr[i] != temp[i]) {
                ans++;
                swap(arr, i, indexOf(arr, temp[i]));
            }
        }
        return ans;
    }
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int cnt = 0;
        while(!queue.isEmpty()) {
            TreeNode curr = queue.peek();
            int size = queue.size();
            for(int i = 0 ; i  < size; i++) {
                curr = queue.remove();
                if(curr.left != null) {
                    queue.add(curr.left);
                }
                if(curr.right != null) {
                    queue.add(curr.right);
                }
            }
            int arr[] = new int[queue.size()];
            int k = 0;
            for(TreeNode node: queue) {
                arr[k++] = node.val;
            }
            cnt += minSwaps(arr, k);

        }
        return cnt;
    }
}