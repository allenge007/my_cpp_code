cout << i << ": ";
        for(int j = 1; j <= 100000; j ++) {
            int res = i ^ j;
            if(res % i != 0 && res % j != 0) {
                cout << j << " ";
            }
        }
        cout << endl;