#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int mem, i, sum;
    mem = 1;    //一人の仕事量をx以下としたときの必要な人数をカウント
    sum = 0;
    for(i=0; i < n; i++){
        if(A[i] > x) return 0;
        if(sum + A[i] <= x) sum += A[i];
        else {
            mem++;
            sum = A[i];
        }
    }
    return mem <= k;    //必要な人数が与えられたkより小さいか否か
}

int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    lb = 0;
    ub = 1000000000;
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    while(ub - lb > 1){
        int m = (ub + lb) / 2;
        if(p(m)) ub = m;
        else lb = m;
    }
    printf("%d\n",ub);
    return 0;
}
