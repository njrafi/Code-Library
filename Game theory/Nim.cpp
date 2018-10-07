
/*

Nim game :
There are some piles and there are stones in the piles
2 players can take any number of stone from any pile
Last player who can't move loses
Winner will be 1st player if the xor sum is nonzero


Misere Nim: 
Last person to move loses
If all the piles have 1 stone, Then for odd pile 2nd player wins
otherwise 1st player wins

If any pile have more than 1 stone , Then it will counted as normal nim



*** Which Moves to make ***:

First we have to know x ^ x = 0


lets assume we have 4 piles and they have a1,a2,a3,a4 marbles

Then their nimsum , x = a1 ^ a2 ^ a3 ^ a4

now lets try to reduce number 2 pile to z

we need (remaining pile nim sum(a1 ^ a3 ^ a4) ) ^ z = 0 to have a winning position

1st step:

how to get the remaining pile nim sum. easy

for a2 , x ^ a2 = a1 ^ a2 ^ a3 ^ a4 ^ a2 = a1 ^ (a2 ^ a2) ^ a3 ^ a4 = a1 ^ a3 ^a4 = remaining pile nim sum

now our z should be x^a2

But its only possible if z < a2

if z<a2 we can just pick a2-z marbles from that pile to get to an winning position

*/


int main()
{

        int t,c=1,inp,k,pre;
        cin >> t;
        while(t--)
        {
                cin >> k ;
                int ans = 0;
                For(i,k)
                {
                        cin >> pre >> inp;
                        ans ^= (inp-pre-1);
                }

                CASE(c++);
                if(ans)
                        cout << "Alice";
                else
                        cout << "Bob";
                cout << endl;
        }








        return 0;
}
