#include <iostream>
using namespace std;

#define sync() { ios_base::sync_with_stdio(0); cin.tie(0);}
#define endl '\n'

void merge(int *arr, int p, int q, int r) {
    int i, j, t, tmp[r-p];
    i = p, j = q+1, t = 0;

    while (i <= q and j <= r) {
        if(arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }

    while (i <= q)
        tmp[t++] = arr[i++];
    while (j <= r)
        tmp[t++] = arr[j++];

    i = p, t = 0;
    while (i <= r) {
        arr[i++] = tmp[t++];
    }
}

void mergeSort(int *arr, int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    sync();

    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << endl;

    return 0;
}