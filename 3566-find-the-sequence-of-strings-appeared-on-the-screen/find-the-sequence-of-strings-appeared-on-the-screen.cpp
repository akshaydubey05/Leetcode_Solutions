class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> s;
        int i = 0;
        string a = "";
        while(i < target.length()){
            char ch = target[i];
            for(char c = 'a';c <= 'z';c++){
                string b = a;
                if(c == ch){
                    i++;
                    a+=ch;
                    s.push_back(a);
                    break;
                    
                }
                else{
                    b+=c;
                    s.push_back(b);
                }
            }
        }
        return s;
    }
};