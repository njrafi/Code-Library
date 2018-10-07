#include <ext/rope> //header with rope
using namespace __gnu_cxx; //namespace with rope and some additional stuff

// declaration
rope<int> rp, gg;

// some functions
gg = rp.substr(l, r - l + 1);
rp.erase(l, r - l + 1);
rp.insert(rp.mutable_begin(), gg);

// iterator
for(rope <int>::iterator it = rp.mutable_begin(); it != rp.mutable_end(); ++it)
        cout << *it << endl;

