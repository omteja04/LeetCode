class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string n1,n2,n3;
        n1 = to_string(num1);
        n2 = to_string(num2);
        n3 = to_string(num3);
        if(n1.length() < 4) {
            n1 =  string(4 - n1.length(), '0')  + n1;
        }
        if(n2.length() < 4) {
            n2 =  string(4 - n2.length(), '0') + n2;
        }
        if(n3.length() < 4) {
            n3 = string(4 - n3.length(), '0') + n3;
        }
        cout<<n1<<endl;
        cout<<n2<<endl;
        cout<<n3<<endl;
        string r = "";
        for(int i = 0 ; i <4; i++) {
            int a,b,c;
            a = n1[i] - '0';
            b = n2[i] - '0';
            c = n3[i] - '0';
            r += to_string(min({a,b,c}));
        }
        return stoi(r);
    }
};