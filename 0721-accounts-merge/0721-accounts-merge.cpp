class DSU {
private:
public:
    unordered_map<string, string> parent;
    string find(string x) {
        if(x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if(pa != pb) {
            parent[pb] = pa;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> mailToName;
        for(auto &account : accounts) {
            string name = account[0];
            int mails = account.size();
            for(int i = 1; i < mails; i++) {
                string mail = account[i];
                mailToName[mail] = name;
                if(!dsu.parent.count(mail)) {
                    dsu.parent[mail] = mail;
                }
                if(i > 1) {
                    dsu.unite(mail, account[1]);
                }
            }
        }
        unordered_map<string, vector<string>> components;
        for(auto &[email, _] : mailToName) {
            string root = dsu.find(email);
            components[root].push_back(email);
        }
        vector<vector<string>> res;
        for(auto &[root, emails] : components) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(mailToName[root]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }
        return res;
        
    }
};