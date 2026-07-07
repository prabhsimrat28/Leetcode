class Solution {
public:

    vector<int> constraints={-1,-1};
    // digit processing started
    // sign seen

    void fun(string &s,long long &num,int i,int n)
    {
    //return directly if character is seen or .
        if(i==n || isalpha(s[i]) || s[i]=='.')
        return;

        //digit processing started but non digit encountered
        if(!isdigit(s[i]) && (constraints[0]!=-1 || constraints[1]!=-1))
        return;


        //above condition checks non leading spaces also
        //so this condition is for leading spaces only
        if(s[i]==' ' && constraints[0] == -1 && constraints[1] == -1)
        {
            fun(s,num,i+1,n);
            return;
        }

        //mark position of sign
        if(s[i]=='-' || s[i]=='+')
        {
            constraints[1]=i;
            fun(s,num,i+1,n);
            return;
        }

        if(isdigit(s[i]))
        {
            int digit=s[i]-'0';
            if(num>INT_MAX)
            {
                return ;
            }
            num=num*10+digit;
            constraints[0]=1;
            fun(s,num,i+1,n);
            return;
        }
    }


    int myAtoi(string s) {
        long long num=0;
        fun(s,num,0,s.size());
        if(constraints[1]==-1 || s[constraints[1]]=='+')
        {
            if(num>INT_MAX)
            return INT_MAX;

            return num;
        }
        num=-num;
        if(num<INT_MIN)
        return INT_MIN;
        return num;
        
    }
};