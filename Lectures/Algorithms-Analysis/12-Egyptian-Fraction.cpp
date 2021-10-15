#include <bits/stdc++.h>
using namespace std;

void egyptian_fraction(int nr, int dr) {
    vector<int> ef;
    while (nr != 0) {
        int x = (dr + (nr - 1)) / nr;
        ef.push_back(x);
        nr = x * nr - dr;
        dr = dr * x;
    }
    for (int i = 0; i < ef.size(); i++) {
        printf("1/%d", ef[i]);
        if (i < ef.size() - 1)
            printf(" + ");
    }
}

int main() {
    int nr = 6, dr = 14;
    printf("The Egyptian Fraction Representation of %d/%d is\n", nr, dr);
    egyptian_fraction(nr, dr);
}
