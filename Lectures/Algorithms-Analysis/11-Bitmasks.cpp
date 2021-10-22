#include <bits/stdc++.h>
using namespace std;

void bitmasks(int arr[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
			    cout << arr[j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    int n = 3;
	int arr[3] = {5, 8, 9};
	bitmasks(arr, n);
}

/*
i=5
1 0 1
        &
0 0 1     5 & pow(2,0)    1
0 1 0     5 & pow(2,1)    0
1 0 0     5 & pow(2,2)    4


5 8 9

{}
{5}
{8}
{9}
{5 8}
{5 9}
{8 9}
{5 8 9}
*/