// x's inverse mod k
// if k is prime
long long GetInv(long long x, long long k){
	return qPow(x, k-2);
}
// if you need [1, x] (most use: [1, k-1]
void solve(int x, long long k){
	inv[1] = 1;
	for(int i=2;i<x;i++)
		inv[i] = ((long long)(k - k/i) * inv[k % i]) % k;
}