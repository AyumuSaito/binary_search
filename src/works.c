#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];

int between(int x, int y, int A[]){
    int i, l;
    for(i=x; i < y; i++){
        l = A[i] + l;
    }
    return l;
}

int canCut(int x, int A[]){
    int l, i, r;
    l = 0;
    r = 0;
    for(i=0; i < x; i++){
        l = A[i] + l;
    }
    for(i=x; i < n; i++){
        r = A[i] + r;
    }
    if(l > (r / (k-1))) return (1);
    else return (0);
}


int main(){
    int i, lb, ub, a, b;
    scanf("%d%d", &n, &k);
    lb = 0;
    ub = n;
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    while(k >= 2){
        b = 0;
        for(i=lb; i < n; i++){
            B[i-lb] = A[i];
        }
        while(ub - lb > 1){
            int m = (ub + lb) / 2;
            if(canCut(m,B)) ub = m;
            else lb = m;
        }
        for(i=0; i < lb; i++){
            b = B[i] + b;
        }
        if(a > b) a = a;
        else a = b;
        k = k - 1;
    }
    b = 0;
    for(i=lb; i < n; i++){
        b = B[i] + b;
    }
    if(a > b) a = a;
    else a = b;
    printf("%d\n",a);
    return 0;
}
