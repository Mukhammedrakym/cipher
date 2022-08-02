#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
   int i, k, n;
   cout << "size of array: ";
   cin >> n;
   int a[n];
   for(i = 0; i < n; i++) {
       a[i] = i + 1;
       cout << a[i] << " ";
      }
       cout << "\nPosition: ";
       cin >> k;
       while (k > n) {
              k = k % n;
       }
       int temp[n];
       for (i = 0; i < n; i++) {
            temp[i] = a[(i + (n - k)) % n];
       }
       for (i = 0; i < n; i++) {
            cout << temp[i] << " ";
       }
       cout << endl;
   return 0;
}
