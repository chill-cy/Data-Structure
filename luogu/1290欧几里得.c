/*************************************************************************
	> File Name: test2.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年04月30日 星期二 16时45分18秒
 ************************************************************************/

#include <stdio.h>
//当前操作者为p,p为0时代表Stan操作,p为1时代表Ollie操作。

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int find(int x,int y,int p)
{
    if(x==y) return p;//返回胜者.
    if(y/x>=2) return p;//返回胜者.
    else return find(y-x,x,p^1);//向下一个状态查找.
}
int main()
{
    int m, n, q;
    char *str[2] = {"Stan wins\n", "Ollie wins\n"};
    scanf("%d", &q);
    for(int i = 1;i <= q; i++)
    {
        scanf("%d%d", &m, &n);
        if(m > n) swap(&m, &n);
        if(find(m, n, 0) == 0) printf("%s", str[0]);//如果返回0,胜者为Stan,反之则为Ollie.
        else printf("%s", str[1]);
    }
    return 0;
}
