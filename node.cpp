struct node{
    int val , idx;
    node(int v = 0 , int i = 0){
        val = v;
        idx = i;
    }
    bool operator < (const node & other) const{
        return val < other.val or (val == other.val and idx > other.idx);
    }
};
