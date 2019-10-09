/*************************************************************************
	> File Name: 1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月09日 星期三 20时55分21秒
 ************************************************************************/

#include<iostream>
using namespace std;
int func(int n)  
{  
    int count = 0;  
    while(n > 1)  
    {  
        if(n % 2 == 0)  
            n >>= 1;  
        else if(n == 3)  
            n--;  
        else  
        {  
            if(n&2)      // 二进制是******11时  
                n++;  
            else         // 二进制是******01时  
                n--;  
        }  
        count++;  
    }  
    return count;  
}
