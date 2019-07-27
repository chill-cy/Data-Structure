/*************************************************************************
	> File Name: 122.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月06日 星期四 18时51分56秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main() {
    int a;
    scanf ("%d", &a);
    int hour, minute, second;
    hour = a / 3600;
    a = a - hour * 3600;
    minute = a / 60;
    a = a - minute * 60;
    second = a;
    char time[10];
    if (hour < 12) {
        strcpy(time, "am");
        //time[10] = "am";
    }
    if (hour == 12) {
        strcpy(time, "midnoon");
    }
    if (hour > 12) {
        hour = hour - 12;
        //if (hour == 0 ) {
          //  strcpy(time, "midnoon");
            //time[10] = "midnoon";
        //}
        if (hour >= 1) {
            strcpy(time, "pm");
            //time[10] = "pm";
        }
    }

    printf ("%02d:%02d:%02d %s\n",hour, minute, second, time); 
    return 0;
}
