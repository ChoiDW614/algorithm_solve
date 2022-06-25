#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;

const double PI = acos(-1);
typedef complex<double> C;

void FFT(vector<C>& ftn, bool inv) {
    int fSize = ftn.size(), j = 0;

    for (int i = 1; i < fSize; i++) {
        int bit = fSize / 2;

        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;

        if (i < j) swap(ftn[i], ftn[j]);
    }

    for (int k = 1; k < fSize; k *= 2) {
        double angle = (inv ? PI / k : -PI / k);
        C dir(cos(angle), sin(angle));

        for (int i = 0; i < fSize; i += k * 2) {
            C unit(1, 0);

            for (int j = 0; j < k; j++) {
                C u = ftn[i + j];
                C v = ftn[i + j + k] * unit;

                ftn[i + j] = u + v;
                ftn[i + j + k] = u - v;

                unit *= dir;
            }
        }
    }

    if (inv)
        for (int i = 0; i < fSize; i++) ftn[i] /= fSize;
}

vector<C> mul(vector<C>& a, vector<C>& b) {
    int N = 1;
    while (N < a.size() + b.size()) N *= 2;

    a.resize(N); FFT(a, false);
    b.resize(N); FFT(b, false);

    vector<C> c(N);
    for (int i = 0; i < N; i++) c[i] = a[i] * b[i];

    FFT(c, true);

    return c;
}

void Solve()
{
    string A, B;
    cin >> A >> B;
    if (A == "0" || B == "0")
    {
        cout << 0;
        return;
    }
    vector<C> a, b;

    while (!A.empty()) {
        a.push_back((double)A[A.length() - 1] - 48);
        A.pop_back();
    }
    while (!B.empty()) {
        b.push_back((double)B[B.length() - 1] - 48);
        B.pop_back();
    }

    vector<C> c = mul(a, b);
    long long Size = a.size() + b.size() - 1;

    string output;
    int ceil = 0;
    for (long long i = 0; i < c.size() && i < Size; i++) {
        if (ceil) {
            c[i] += ceil;
            ceil = 0;
        }
        if (round(c[i].real()) >= 10) {
            ceil = (int)round(c[i].real()) / 10;
            output += to_string((int)round(c[i].real()) % 10);
            continue;
        }
        output += to_string((int)round(c[i].real()));
    }

    bool frontZero = true;
    for (int i = 1; i <= output.size(); i++) {
        if (output[output.length() - i] != '0') {
            frontZero = false;
        }
        if (output[output.length() - i] && !frontZero) {
            cout << output[output.length() - i];
        }
    }
}

int main() {
    FAST_IO;
    Solve();
    return 0;
}