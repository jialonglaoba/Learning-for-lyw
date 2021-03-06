/*************************************************************************
	> File Name: HZOJ44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 16时33分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 500000

int len[MAX_N + 5], ans = 0;
int dp[MAX_N + 5];
int a[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = n + 1;
    }
    len[++ans] = a[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];
        ans = max(dp[i], ans);
    }
    
    cout << ans << endl;

    return 0;
}

