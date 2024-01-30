#include <bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& t ) {
        stack<int> n;
        for(const string& i:t){
            if( i.size() >1 || isdigit(i[0])){
                n.push(stoi(i));
            }
            else{
                int op2=n.top();
                n.pop();
                int op1=n.top();
                n.pop();
                switch(i[0]){
                    case '+':
                        n.push(op1+op2);
                        break;
                    case '-':
                        n.push(op1-op2);
                        break;
                    case '*':
                        n.push(op1*op2);
                        break;
                    case '/':
                        n.push(op1/op2);
                        break;
                }
            }
        }
        return n.top();
    }
};