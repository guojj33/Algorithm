#include <iostream>
using namespace std;

void printA(int *a, int count) {
  for (int i = 0; i < count; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

// 选择排序 每次选择最小元素插到有序子序列的后面
void SelectionSort(int *a, int count) {
  for (int i = 0; i <= count-2; ++i) { // i 指向有序子序列的最后一个元素的下一个位置
    int minPos = i; // minPos 指向向后查找过程中发现的最小元素
    for (int j = i+1; j <= count-1; ++j) {
      if (a[j] < a[minPos]) 
        minPos = j;
    }
    int tmp = a[i];
    a[i] = a[minPos];
    a[minPos] = tmp;
  }
}

int main() {
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  SelectionSort(a, count);
  printA(a, count);
}