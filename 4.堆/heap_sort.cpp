/*************************************************************************
	> File Name: heap_sort.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月29日 星期一 13时07分34秒
 ************************************************************************/
//在改变这个结构的过程中是如何维护这种结构的性质的

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

int num[MAX_N + 5], n;

void heap_sort(int *num, int n) {
    //原num数组num[0]存储数组第一个元素，num -= 1, num指针向前移动一位，访问num[１]就相当于访问第一个元素
    num -= 1;
    //建大顶堆
    /*for (int i = 2; i <= n; i++) {
        int ind = i; 
        while (ind != 1 && num[ind] > num[ind >> 1]) {
            swap(num[ind], num[ind >> 1]);
            ind >>= 1;
        }
    }*/
    //出n-1次堆，交换第n位和第１位元素交换
    for (int i = n; i >= 2; i--) {
        swap(num[i], num[1]);
        int ind = 1;
        //当ind位置有子节点，且当前结点小于孩子结点中的任意一个的时候，进行堆的调整
        while ((ind << 1) < i) {
            int temp = ind, lchild = ind << 1, rchild = ind << 1 | 1;
            if (num[temp] < num[lchild]) temp = lchild;
            if (rchild < i && num[temp] < num[rchild]) temp = rchild;
            if (temp == ind) break;
            //当前位置不违反堆的性质
            swap(num[temp], num[ind]);
            //交换完ind指向temp
            ind = temp;
        }
    }
    return ;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", num + i);
    heap_sort(num, n);
    for (int i = 0; i < n; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}
