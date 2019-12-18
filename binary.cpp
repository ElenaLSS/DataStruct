/*
统计某个数字二进制下，数字1的个数
n & (n-1) 每次操作会去掉最右边的数字1，那么上面的while循环执行的次数就是n中数字1的个数
如： n = 1001100 时   n-1=1001011，  那么n&(n-1)为1001000，去掉了最右边的1
*/
while(n){
    cnt++;
    n = n & (n-1);
}

/*
对于十进制整数 x，我们可以用 x & 1 得到 x 的二进制表示的最低位，它等价于 x % 2：
例如当 x = 3 时，x 的二进制表示为 11，x & 1 的值为 1；
例如当 x = 6 时，x 的二进制表示为 110，x & 1 的值为 0。

对于十进制整数 x，我们可以用 x & (1 << k) 来判断 x 二进制表示的第 k 位（最低位为第 0 位）是否为 1。如果该表达式的值大于零，那么第 k 位为 1：
例如当 x = 3 时，x 的二进制表示为 11，x & (1 << 1) = 11 & 10 = 10 > 0，说明第 1 位为 1；
例如当 x = 5 时，x 的二进制表示为 101，x & (1 << 1) = 101 & 10 = 0，说明第 1 位不为 1。
*/
