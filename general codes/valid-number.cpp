class Solution {
public:
    bool isNumber(string s) {
        s = stringToString(s);
        char first_char = s[0];
        if(first_char != '+' && first_char !='-' && !digit(first_char))//if first char is not sign or digit return false
            return false;
        if(first_char == '+' || first_char =='-') //if first char is sign
        {
            string t(s,1,s.size()-1);
            s = t;
        }
        
        int dot_position = has_dot(s);
        string dec = "";
        if(dot_position!=-1)//if number has dot
        {
            string t (s,0,dot_position);
            dec = t;
            if(!number(dec)) 
                return false;
            string t1 (s,dot_position+1,s.size()-dot_position-1);
            s = t1;
            
            string frac ="";
            int exp_pos = has_exp(s);
            if(exp_pos!=-1)//if has exponent
            {
                string t (s,0,exp_pos);
                frac = t;
                if(!number(frac)) 
                    return false;
                string exp (s,exp_pos+1,s.size()-exp_pos-1);
                if(!number(exp)) 
                    return false;
            }
        }
        else if(has_exp(s)!=-1)//if has exponent
        {
            int exp_pos = has_exp(s);            
            string t (s,0,exp_pos);
            dec = t;
            if(!number(dec)) 
                return false;
            string exp (s,exp_pos+1,s.size()-exp_pos-1);
            if(!number(exp)) 
                return false;
        }
        else
        {
            dec = s;
            if(!number(dec)) 
                return false;
        }
        return true;

    }
    int has_exp(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch =='e')
                return i;
        }
        return -1;
    }
    int has_dot(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch =='.')
                return i;
        }
        return -1;
    }
    bool digit(char ch)
    {
        return (ch>57 || ch < 48)?false:true;
    }
    bool number(string s)
    {
        if(s.size()==0)
            return false;
        for(char ch:s)
            if(!digit(ch)) //if char is not digit return false
                return false;
        return true;
    }
    string stringToString(string s) {
        if(s[0]==' '&& s[s.size()-1]==' ')
        {
            string t (s,1,s.size()-2);
                return t;
        }
        else if(s[0]==' '&& s[s.size()-1]!=' ')
        {
            string t (s,1,s.size()-1);
                return t;
        }
        else if(s[0]!=' '&& s[s.size()-1]==' ')
        {
            string t (s,0,s.size()-1);
                return t;
        }
        else 
            return s;
        
}
};

