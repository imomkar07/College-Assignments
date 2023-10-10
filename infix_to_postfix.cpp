#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else{
        return-1;
    }
}

string infix_to_postfix(string s)
{
   stack <int>st;
   string answer;

   for(int i=0; i< s.length() ; i++)
   {
         
        if (s[i] >='a'&& s[i]<='z' || s[i] >='A'&& s[i]<='Z')
        {
            answer +=s[i];
        }
        else if (s[i] =='(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while(!st.empty() && st.top()!='(')
            {
                answer += st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else 
        {
             while(!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                answer +=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main()
{
    string infix;
    cout<<"Enter the Infix string = ";
    cin>>infix;
    string postfix;
    postfix = infix_to_postfix(infix);
    cout<<endl<<"Postfix = "<<postfix;
}