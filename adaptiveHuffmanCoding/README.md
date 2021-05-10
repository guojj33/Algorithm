# 自适应哈夫曼编码解码程序

## 基本说明

    在linux环境下编写并执行
    这里的测试是在将小说prince.txt放在了adaptiveHuffmanCoding目录的情况下

## 编译指令说明

adaptiveHuffmanCoding目录下的makefile使用

- 编译生成encoder和decoder并查看

  ```
  # make
  # cd bin
  # ls
  ```

- 编译生成encoder并执行

  ```
  # make encoder
  # cd bin
  # ./encoder
  # ../prince.txt
  ```

- 编译生成decoder并执行

  ```
  # make decoder
  # cd bin
  # ./decoder
  # ../prince.ahc
  ```

- 删除编译生成的文件

  ```
  # make clean
  ```