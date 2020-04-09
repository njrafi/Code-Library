// Code from https://rezwanarefin01.github.io/posts/palindromic-tree-01/

/*
Concept:
aba -> tree[node][c] means -> cabac , adding c in both side
for odd length, define one root and consider the length -1
Suffix Link: biggest proper suffix ( length < string length) which is also a palindrome
if no proper suffix , link to root with length 0
length 0 root links back to length -1 root
length -1 root links to own node

tree[node][character] -> trie info
len[node] -> length of the node
link[node] -> suffix link
last = holds the max palindrome suffix of the processed prefix till now
endsAt[node] -> total palindrome ends at i
dfsLink[node] -> If need to traverse the suffix link tree
Current code only works for lowerCase letter

fact 1: N length string can only have N distinct palindrome
fact 2: Palindrome tree holds all distinct palindrome
fact 3: number of distinct palindrome = freeNode - 2
fact 4: number of total palindrome = sum of( endsAt[i]) 0 to freeNode
fact 5: freq[node] will give us total freq of palindrome at node i
fact 6: total tree node will be <= n + 2 , so for MLE use map or pointer implemention of tree
*/

#define mxn 1000010
int tree[mxn][26];
int freeNode;
int len[mxn], link[mxn], last;
//vi dfsLink[mxn];
char s[mxn];

i64 endsAt[mxn];
i64 freq[mxn];

void extend(int p) {
	while(s[p - len[last] - 1] != s[p])
		last = link[last];
	int x = link[last], c = s[p] - 'a';
	while(s[p - len[x] - 1] != s[p])
		x = link[x];
	if(!tree[last][c]) {
		tree[last][c] = ++freeNode;
		len[freeNode] = len[last] + 2;
		link[freeNode] = len[freeNode] == 1 ? 2 : tree[x][c];
//		dfsLink[link[freeNode]].pb(freeNode);
		endsAt[freeNode] = endsAt[link[freeNode]] + 1;
	}
	last = tree[last][c];
	freq[last]++;
}



bool ache[mxn];

void ini(int n) {
	For(i,n+ 5) {
		mem(tree[i],0);
		len[i] = 0;
		link[i] = 0;
		endsAt[i] = 0;
		freq[i] = 0;
		ache[i] = 0;
//		dfsLink[i].clr;
	}
	len[1] = -1, link[1] = 1;
	len[2] = 0, link[2] = 1;
	freeNode = last = 2;
}

void inputAndBuild() {
	int n;
	sf(n);
	ini(n);
	scanf("%s",s);
	for(int i = n ; i > 0 ; i--)
		s[i] = s[i-1];
	s[0] = '#';
	Fre(i,1,n+1)
	extend(i);
	assert(freeNode <= n + 5);
	for(int i = freeNode ; i > 2 ; i--)
		freq[link[i]] += freq[i];
}

