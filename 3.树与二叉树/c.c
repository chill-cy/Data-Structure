/*************************************************************************
	> File Name: c.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 15时07分02秒
 ************************************************************************/
 #include <stdio.h>
int max(int x, int y) {
return x > y ? x : y;
}
int main() {
int max(int x, int y);
int (*p)(int, int) = &max;
int a, b, c, d;
printf("Please input three integer \n");
scanf("%d%d%d", &a, &b, &c);
d = (*p) ((*p) (a, b), c);
printf("Among %d, %d and %d, the maxmal integer is %d\n", a, b, c, d);
return 0;
}
