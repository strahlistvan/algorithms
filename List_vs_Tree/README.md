# Linked list or Binary tree

## Comparsion of the Simple linked list and the Binary search tree insert efficiency

I used the same random data (C++ `srand(0);` seed) in the linked list and binary search tree (100 000 random data)
Then make the same searchings in the list and the tree. I used random sequence of numbers to search (C++ `srand(42);` seed in every searching)

Count of searching | List time [s] | Tree time [s] | Founded Elements
-------------------|---------------|---------------|-----------------
1000               |          0.53 |             0 |             0
10000              |          5.19 |          0.00 |             0
100000             |          54.3 |          0.04 |             3
200000             |        105.23 |          0.09 |             9
500000             |        264.33 |          0.22 |            25
1000000            |        542.79 |          0.41 |            47
10M                |       -       |          3.78 |           410
20M                |       -       |          7.53 |           852
40M                |       -       |         14.96 |          1735
80M                |       -       |         30.31 |          3586
160M               |       -       |         63.33 |          7389
