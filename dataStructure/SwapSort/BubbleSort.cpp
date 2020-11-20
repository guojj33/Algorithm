#include <iostream>
using namespace std;

void printA(int *a, int count) {
  for (int i = 0; i < count; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

// 冒泡排序
void BubbleSort(int *a, int count) {
  for (int i = 0; i < count - 1; ++i) { // 指针 i 指向已有序的序列的下一个位置
    for (int j = count - 1; j >= i+1; --j) { // 指针 j 从后往前，且 j 最小时 ，j-1 = i，故 j >= i+1
      if (a[j] < a[j-1]) {  // 从后往前比较规定用 j 和 j-1
        int tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
      }
    }
  }
}

int main() {
  int count = 0;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; ++i) {
    cin >> a[i];
  }
  BubbleSort(a, count);
  printA(a, count);
}