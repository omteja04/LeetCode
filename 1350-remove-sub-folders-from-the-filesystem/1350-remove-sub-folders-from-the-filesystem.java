class Node {
    Node links[] = new Node[27];
    boolean flag;
    Node() {
        this.flag = false;
        for(int i = 0; i < 27; i++) links[i] = null;
    }
    int toChar(char ch) {
        if(ch == '/') return 26;
        return ch - 'a';
    }
    boolean containsKey(char ch) {
        return links[toChar(ch)] != null;
    }
    void put(char ch, Node node) {
        links[toChar(ch)] = node;
    }
    Node get(char ch) {
        return links[toChar(ch)];
    }
    boolean isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
}
class Trie {
    private Node root;
    public Trie() {
        root = new Node();
    }
    boolean insert(String word) {
        Node node = root;
        for(int i = 0; i < word.length(); i++) {
            int idx = node.toChar(word.charAt(i));
            if(word.charAt(i) == '/' && node.isEnd()) {
                // It is sub-folder
                return false;
            } else if(!node.containsKey(word.charAt(i))) {
                node.put(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
        }
        node.setEnd();
        return true;
    } 
}
class Solution {
    Node root = new Node();
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> list = new ArrayList<>();
        Trie trie = new Trie();
        for(int i = 0; i  < folder.length; i ++) {
            if(trie.insert(folder[i])) list.add(folder[i]);
        }
        return list;
    }
}