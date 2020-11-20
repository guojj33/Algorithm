#include <iostream>
using namespace std;

void printA(int *a, int count) {
  for (int i = 0; i < count; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

// 折半查找要插入的位置
int BinaryInsertionSearch(int* a, int count, int toSearch) {
  int low = 0;
  int high = count - 1;
  while(low <= high) {
    int mid = (low+high)/2;
    if (toSearch < a[mid])
      high = mid - 1;
    else low = mid + 1;
  }
  return low; // 此时 low 大于 high，且 low 即 toSearch 要放置的位置
}

// 折半插入排序
void BinaryInsertionSort(int *a, int count) {
  for (int i = 1; i <= count-1; ++i) {  // i 指向下一个要插入有序子序列的元素
    int insertPos = BinaryInsertionSearch(a, i, a[i]);  // 折半查找插入元素在有序子序列
    int tmp = a[i];
    for (int j = i; j >= insertPos+1; --j) {  // 从 i-1 到 insertPos 位置的元素都要后移
      a[j] = a[j-1];                          // 从后往前时，规定用 j 和 j-1
    }
    a[insertPos] = tmp; // 新元素插入到 insertPos 的位置
    printA(a, count);
  }
}

int main() {
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  BinaryInsertionSort(a, count);
  printA(a, count);
}