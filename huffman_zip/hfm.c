/*************************************************************************
	> File Name: hfm.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月13日 星期日 14时09分09秒
 ************************************************************************/


#include "hfm.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Error parameter\n");
        exit(1);
    }
    char *op = argv[1];
    char *filename = argv[2];
    char *destname = argv[3];
    if (!strcmp(op, "-c")) {
        prepare(filename);
        HuffmanTree *tree = build(cnt);
        compress(tree, filename, destname);
    } else if (!strcmp(op, "-d")) {
        uncompress(filename, destname);
    } else {
        printf("Error option\n");
    }
    return 0;
}

