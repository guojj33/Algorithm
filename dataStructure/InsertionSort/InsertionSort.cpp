#include <iostream>
using namespace std;

void printA(int *a, int count) {
  for (int i = 0; i < count; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

// 插入排序 对每个元素，从后往前去比较已有序的子序列
// 画一个 5 4 3 2 1 的数组，考虑指针 i 和 j 的含义以及范围
// i 指向有序子序列的最后一个元素
//    j 初始时 = i+1 指向下一个要插入有序子序列的元素
//    从后往前比较时，用 j 和 j-1 的元素来比较，则 j-1 最小为 0，j-1 >= 0，j >= 1
void InsertionSort(int *a, int count) {
  for (int i = 0; i <= count-2; ++i) {
    for (int j = i+1; j >= 1; --j) {
      if (a[j] < a[j-1]) {
        int t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
      else continue;
    }
  }
}

int main(){
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  InsertionSort(a, count);
  printA(a, count);
}
