
/// Do the opposite what you would do with array

struct info
{
    /// other things

    bool operator < (const info &b) const {
        return h > b.h;
    }
};

class cmp
{
public:
        bool operator()(pii a,pii b)
        {
                if(a.ff==b.ff)
                        return a.ss>b.ss;
                else
                        return a.ff>b.ff;
        }
};




