class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        bool a = false;
        for(int i = 0;i < s.length();i++){
            char d = s[i];
            int idx = 0;
            cout << d<<endl; 
            for(int j = i+1;j < s.length();j++){
                if(d<=s[j]){
                    d = s[j];
                    idx = j;
                }
            }
            cout << d;
            if(d > s[i]){
                swap(s[idx],s[i]);
                break;
            }
        }
        int x = stoi(s);
        return x;
    }
};