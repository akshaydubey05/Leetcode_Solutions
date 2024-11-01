class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string str="";
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(s[i+1]==ch&&s[i+2]==ch)
            {
                continue;
            }
            else
            {
                str+=s[i];
            }
        }
        return str;

        
    }
};