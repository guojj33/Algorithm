#include <iostream>
using namespace std;

void printA(int *a, int count) {
  for (int i = 0; i < count; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int Partition(int *a, int low, int high) {
  int pivot = a[low]; // 取子序列的首个元素为枢纽值
  while(low < high) {
    while(low < high && a[high] >= pivot) --high;
    a[low] = a[high];
    while(low < high && a[low] <= pivot) ++low;
    a[high] = a[low];
  }
  a[low] = pivot;
  return low; // 枢纽值在子序列中的最终位置
}

// 快速排序
void QuickSort(int *a, int low, int high) {
  if (low < high) {
    int pivotPos = Partition(a, low, high);
    // cout << a[pivotPos] << " final position " << pivotPos << "\n";
    QuickSort(a, low, pivotPos-1);
    QuickSort(a, pivotPos+1, high);
  }
}

int main() {
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  QuickSort(a, 0, count-1);
  printA(a, count);
}