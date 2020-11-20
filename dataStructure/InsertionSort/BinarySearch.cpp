#include <iostream>
using namespace std;

// 折半查找
int BinarySearch(int* a, int count, int toSearch) {
  int low = 0;
  int high = count - 1;
  while(low <= high) {
    int mid = (low+high)/2;
    if (a[mid] == toSearch) {
      return mid; // 查找成功
    }
    if (toSearch < a[mid])
      high = mid - 1;
    else if (a[mid] < toSearch)
      low = mid + 1;
  }
  return -1;  // 查找失败
}

int main() {
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  int toSearch = 0;
  cin >> toSearch;
  int index = BinarySearch(a, count, toSearch);
  cout << index << "\n";
}