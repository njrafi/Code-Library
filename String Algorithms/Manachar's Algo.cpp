/// used for finding Longest Palindromic Sub-string in any string
/// Can also be done with hash


#define mxn 100005

int p[mxn * 2 +10];

// Transform S into new string with special characters inserted.

string convert(string s) {
        string tem = "@";

        For(i,s.sz)
        {
                tem += "#" ;
                tem += s[i];
        }

        tem += "#$";
        return tem;
}



string longestPalindromeSubstring(string s)
{
        string q = convert(s);
        int c = 0, r = 0;                
        // current center, right limit
        // find the corresponding letter in the palidrome subString

        Fre(i,1,(int)q.sz-1)            
        {

                int iMirror = c - (i - c);

                if(r > i)
                    p[i] = min(r - i, p[iMirror]);


                // expanding around center i
                while(q[i + 1 + p[i]] == q[i - 1 - p[i]])
                        p[i]++;


        // Update c,r in case if the palindrome centered at i expands past r,
                if (i + p[i] > r)
                {
                        c = i;              // next center = i
                        r = i + p[i];
                }
        }

        // Find the longest palindrome length in p.

        int maxPalindrome = 0;
        int centerIndex = 0;
        int totpalin = 0;
        Fre(i,1,(int)q.sz-1)
        {

                totpalin += (p[i]+1)/2;
                if (p[i] > maxPalindrome)
                {
                        maxPalindrome = p[i];
                        centerIndex = i;

                }
        }
        /// p[i] = max palindrome sequence centred at i
        cout << maxPalindrome << endl;
        cout << totpalin << endl;
        return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main()
{
//        string s = "kiomaramol\n";
        string s;
        cin >> s;
        cout << longestPalindromeSubstring(s);
        return 0;
}
