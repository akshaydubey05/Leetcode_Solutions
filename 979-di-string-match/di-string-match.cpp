class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> a;
        int x,j;
        if(s[0]=='I'){
            a.push_back(0);
            x=1;
            j=s.length();
        }
        else{
            a.push_back(s.length());
            x=0;
            j=s.length()-1;
        }
        
        for(int i=0;i<s.length();i++){
          if(s[i]=='D' && s[i+1]=='I'){
              a.push_back(x);
              x++;
          }
          else if(s[i]=='D' && s[i+1]=='D'){
              a.push_back(j);
              j--;
          }
          else if(s[i]=='I' && s[i+1]=='D'){
              a.push_back(j);
              j--;
          }
          else{
              a.push_back(x);
              x++;
          }
        }
        return a;
    }
};