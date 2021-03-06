class Hash{
private:
  static const int N = 1000000;
  const int p = 127, q = 1208220623;
  int sz, prefix[N], power[N];
  inline int add(int x, int y){return x+y>=q?x+y-q:x+y;}
  inline int sub(int x, int y){return x-y<0?x-y+q:x-y;}
  inline int mul(int x, int y){return 1LL*x*y%q;}
public:
  void init(const std::string &x){
    sz = x.size();
    prefix[0]=0;
    for(int i=1;i<=sz;i++) prefix[i]=add(mul(prefix[i-1], p), x[i-1]);
    power[0]=1;
    for(int i=1;i<=sz;i++) power[i]=mul(power[i-1], p);
  }
  int query(int l, int r){
    // 1-base (l, r]
    return sub(prefix[r], mul(prefix[l], power[r-l]));
  }
};
