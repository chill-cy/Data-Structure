/*************************************************************************
	> File Name: big.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月16日 星期三 23时23分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
void BigNumMultiSmall(char a1[],int b1)

{

	int i,j,t;

	int a[2000]={0};

	//将字符串转化为整型数组，并逆置

	t=strlen(a1);

	for(i=0;i<t;i++)

		a[i]=a1[t-1-i]-'0';

	//整型数组的每个元素乘以b1，然后对其进行求余，整除，使其只有一位数

	a[0]=a[0]*b1;

	for(i=1;i<t;i++)

	{

		a[i]*=b1;

		a[i]+=a[i-1]/10;

		a[i-1]=a[i-1]%10;

	}

	while(a[i-1]>9)

	{//若最后一个元素大于9

		a[i]=a[i-1]/10;

		a[i-1]=a[i-1]%10;

		i++;

	}

	//将得到的整型数组逆置赋给字符串

	for(j=0;j<i;j++)

		c[j]=a[i-j-1]+'0';

	if(Judge(c))//若积全为0，则只输出一个0

		strcpy(c,"0");

}
