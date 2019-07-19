/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 19时02分11秒
 ************************************************************************/

#include <iostream>
#include "common_n.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#define MAX_N 200
#define PORT 8888

int main() {
    int listen_socket = socket_create(PORT);
    int ep_fd = epoll_create(MAX_N);
    if (ep_fd < 0) {
        perror("epoll_create");
        exit(1);
    }
    struct epoll_event ev, events[MAX_N];
    ev.data.fd = listen_socket;
    ev.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, listen_socket, &ev) < 0) {
        perror("epoll_ctl");
        exit(0);
    }
    unsigned long ul = 1;
    ioctl(listen_socket, FIONBIO, &ul);
    int nfds;
    while (1) {
        nfds = epoll_wait(ep_fd, events, MAX_N, 10*1000);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        if (nfds == 0) {
            cout << "time out" << endl;
        }
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == listen_socket && events[i].events == EPOLLIN)
        }
    }
}
