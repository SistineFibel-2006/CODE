// easy version

struct SegmentTree {
   ll size = 1;
   vector<ll> data;
   SegmentTree(ll n) {
      while(size < n) size *= 2;
      data.assign(size * 2, -LINF);
   }
   void update(ll at) {
      while(at /= 2) data[at] = max(data[at * 2], data[at * 2 + 1]);
   }
   void set(ll at, ll val) {
      at += size;
      data[at] = val;
      update(at);
   }
   ll get(ll l, ll r) {
      ll ans = -LINF;
      l += size;
      r += size;
      for(; l < r; l /= 2, r /= 2) {
         if(l & 1) chmax(ans, data[l++]);
         if(r & 1) chmax(ans, data[--r]);
      }
      return ans;
   }
};
