    vector < T > res(n, -1);
    stack < int > st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : abs(st.top() - i));
        st.push(i);
    }
    return res;
}
 
template < typename T = int > vector < T > prevGreaterelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n, -1);
    stack < int > st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : abs(st.top() - i));
        st.push(i);
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector < int > v(n);
    cin >> v;
    vector < int > next = nextGreaterelement(v) , prev = prevGreaterelement(v);
}
