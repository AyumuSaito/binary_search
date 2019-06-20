#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];

int between(int x, int y, int A[]){
    int i, l;
    for(i=x-1; i < y; i++){
        l = A[i] + l;
    }
    return l;
}

int canBeIn(int x){
    int l, i, s;
    l = between(1,x,A);
    s = between(1,n,A);
    if(s / k <= l) return (1);
    else return (0);
}


int main(){
    int i, lb, ub, a;
    scanf("%d%d", &n, &k);
    lb = 1;
    ub = n;
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    B[0] = A[0];
    for(i=0; i < n; i++){
        B[i+1] = B[i] + A[i+1];
    }
    while(ub - lb > 1){
        int m = (ub + lb) / 2;
        if(canBeIn(m)) ub = m;
        else lb = m;
    }
    printf("%d\n",B[4]);
    return 0;
}
