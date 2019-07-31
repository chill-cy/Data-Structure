/*************************************************************************
	> File Name: newton.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月01日 星期四 00时05分27秒
 ************************************************************************/


const double EPSINON = 0.0000000001;

double sqrt2() {
    double low = 1.4, high = 1.5;
    double mid = (low + high) / 2;

    while (high - low > EPSINON) {
        if (mid * mid > 2) {
            high = mid;
        }
        else {
            low = mid;
        }
        mid = (high + low) / 2;
    }
    return mid;
} 
