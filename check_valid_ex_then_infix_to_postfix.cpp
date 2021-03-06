/**
Input a expression like A+B-C then check the expression is valid or invalid? If it is valid then showing the expression infix to postfix otherwise invalid then the program will be closed.

Input:A+B-C
Output:This is valid Expression!
Infix to postfix is:AB+C-

Input:A+-B
Output:Invalid Expression!
**/
#include <bits/stdc++.h>
using namespace std;

int braketCheck(char ch) {

    if( ch == '(' || ch == ')' ) return 1;
    else  return 0;
}

int OperatorCheck(char ch) {

    if( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ) return 1;
    else  return 0;
}

int BCheck(string str)
{
    vector<char>v1; int f = 1;//ei storage e data gulo rakhbo;

    for(int i=0; i<str.size(); i++) {

        if( str[i] == '(' ) v1.push_back(str[i]);
        if( str[i] == ')' ) v1.pop_back();

        if( str[i] == '(' && str[i] == ')' ) { f=0; break; }
    }

    if( v1.size() || f==0 ) return 0;
    else return 1;
}
int prec(char c)  //infix to postfix er function ;
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        ns+=s[i];
        else if(s[i] == '(')
        st.push('(');
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    printf("This is valid Expression!\n");
    printf("Infix to postfix is:\n");
    cout << ns << endl;
}

int main()
{
    printf("Write Your Expression!:\n");
    string str; cin >> str;

    int x = BCheck(str); // bracket check

    if( x == 0 )  { printf("Invalid Expression!\n"); return 0; }

    for(int i=0; i<str.size(); i++) {

        if( !isdigit(str[i]) && !isalpha(str[i]) && !braketCheck(str[i]) && !OperatorCheck(str[i]) ) {
            printf("Invalid Expression!!\n"); return 0;
        }
        else if( OperatorCheck(str[0]) || ( OperatorCheck(str[i]) && OperatorCheck(str[i+1]) )) {
             printf("Invalid Expression!!!\n"); return 0;
        }
        else if( isalpha(str[i]) && isalpha(str[i+1])  ) {
             printf("Invalid Expression!!!!\n"); return 0;
        }
        else if( OperatorCheck(str[str.size()-1] )) {
              printf("Invalid Expression!!!!\n"); return 0;
        }
    }
    infixToPostfix(str);
    main();
    return 0;
}
