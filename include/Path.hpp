#ifndef PATH
#define PATH

class Path {
public:
    Path(int src, int dest, float cost)
    : src{src}, dest{dest}, cost{cost}
    {}
    Path()
    : src{-1}, dest{-1}, cost{-1}
    {}
        
    int src;
    int dest;
    float cost;
};

#endif
