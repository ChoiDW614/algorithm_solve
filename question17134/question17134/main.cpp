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

vector<C> cal_FFT(vector<C>& a, vector<C>& b, string str) {
    int N = 1;
    while (N < a.size() + b.size()) N *= 2;

    a.resize(N); FFT(a, false);
    b.resize(N); FFT(b, false);

    vector<C> c(N);
    if (str == "add")
        for (int i = 0; i < N; i++) c[i] = a[i] + b[i];
    else if (str == "sub")
        for (int i = 0; i < N; i++) c[i] = a[i] - b[i];
    else if (str == "mul")
        for (int i = 0; i < N; i++) c[i] = a[i] * b[i];
    else if (str == "div")
        for (int i = 0; i < N; i++) c[i] = a[i] / b[i];

    FFT(c, true);

    return c;
}

int main() {
    FAST_IO;

    /*vector<C> a = { C(1, 0), C(2, 0) };
    vector<C> b = { C(1, 0), C(3, 0) };*/

    int Size = a.size() + b.size() - 1;

    vector<C> c = cal_FFT(a, b, "sub");
    for (int i = 0; i < Size; i++) cout << round(c[i].real()) << " ";
    return 0;
}
