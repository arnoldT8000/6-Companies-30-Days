//https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int func(int a, int b, string y){
        if(y=="+") return b+a;
        if(y=="-") return b-a;
        if(y=="*") return long(a)*b;
        return b/a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string &x :tokens) {
            if(x =="+" || x =="*" || x =="/" || x =="-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(func(a,b,x));
            }

            else{
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};