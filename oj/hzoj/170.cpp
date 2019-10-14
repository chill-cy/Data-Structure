    y(Ben, "Ban_smoking");
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
        //char *p = s[i];
            if (s[i][j] == temp[j]) {
                ans ++;
            } 
            if (ans == strlen(temp)) {
                s[i] = s[i].insert(j, Ben);
                cout << s[i] << endl;
                ans = 0;
            }
        }
    }

    return 0;
}
