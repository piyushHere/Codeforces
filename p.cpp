int main() {
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n, a = INT_MAX, b = INT_MAX, c = INT_MAX, l, r, m;
        cin >> l >> r >> m;
        ll low = l - r, high = r - l;
        for (int i = l; i <= r; i++) {
            a = i;
            n = m / a;
            if (n == 0) n = 1;
            n++;
            int k = 2;
            while (k > 0) {
                ll rem = m - (n * a);
                if (rem >= low && rem <= high) {
                    if (rem >= 0) {
                        c = l;
                        b = rem + c;
                    }
                    else {
                        b = l;
                        c = b - rem;
                    }
                    goto print;
                }
                n--;
                k--;
            }
        }
print:
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}