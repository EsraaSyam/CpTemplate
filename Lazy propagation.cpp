struct node {
    ll val;

    node() {
        val = -1;
    }

    node(int v) {
        val = v;
    }

    node(node &a, node &b) {
        val =  max(a.val, b.val);
    }

    node(ll a , ll b){
        val = max(a, b);
    }
};

struct segtree{
    vector < node > tree, lazy;
    ll size = 1;

    segtree(ll n){
        while(size < n) size *= 2;
        tree.assign(size * 2, 0);
        lazy.assign(size * 2, 0);
    }

    ll query(ll l, ll r, ll idx, ll tl, ll tr){
        push(idx, tl, tr);
        if(tl > r or tr < l) return -1;
        if(l <= tl and tr <= r) return tree[idx].val;
        ll mid = tl + (tr - tl) / 2;
        ll left = query(l, r, idx * 2 + 1, tl, mid);
        ll right = query(l, r, idx * 2 + 2, mid + 1, tr);
        return node(left, right).val;
    }

    ll query(ll l, ll r){
        return query(l, r, 0, 0, size - 1);
    }

    void push(ll idx, ll tl, ll tr){
        if(lazy[idx].val == -1) return;
        tree[idx] = node(lazy[idx].val , tree[idx].val);
        if(tl != tr){
            lazy[idx * 2 + 1] = node(lazy[idx].val, lazy[idx * 2 + 1].val);
            lazy[idx * 2 + 2] = node(lazy[idx].val, lazy[idx * 2 + 2].val);
        }
        lazy[idx] = -1;
    }

    void update(ll l, ll r, ll v, ll idx, ll tl, ll tr){
        push(idx, tl, tr);
        if(tl > r or tr < l) return;
        if(l <= tl and tr <= r){
            lazy[idx].val = v;
            push(idx, tl, tr);
            return;
        }
        ll mid = tl + (tr - tl) / 2;
        update(l, r, v, idx * 2 + 1, tl, mid);
        update(l, r, v, idx * 2 + 2, mid + 1, tr);
        tree[idx] = node(tree[idx * 2 + 1], tree[idx * 2 + 2]);
    }

    void update(ll l, ll r, ll val){
        update(l, r, val, 0, 0, size - 1);
    }
};
