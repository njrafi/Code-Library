
int main()
{

        /// 2 file name
        ifstream lib("lib.txt");
        ifstream yo("yo.txt");
        string s1,s2;
        while(getline(lib,s1))
        {
                getline(yo,s2);
                if(s1!=s2)
                        cout << s1 << endl << s2 << endl;
        }

        return 0;
}

