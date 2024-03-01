class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string ch="";
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        if(count==1){
            for(int i=0;i<s.size()-1;i++){
                ch=ch+'0';
            }
            ch=ch+'1';
        }
        else{
            int i=0;
            while(count!=1){
                ch=ch+'1';
                i++;
                count--;
            }
            for(;i<s.size()-1;i++){
                ch=ch+'0';
            }
            ch=ch+'1';
        }
        return ch;
    }
};