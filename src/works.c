#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];

int abs(int x){
    if(x < 0) return (-x);
    else return (x);
}

int canCut(int x, int A[]){
    int l, i, s;
    l = 0;
    s = 0;
    for(i=0; i < x; i++){
        l = A[i] + l;
    }
    for(i=0; i < n; i++){
        s = A[i] + s;
    }
    if(l * k > s) return (1);
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
        if(abs(sum(B,lb+1) - B[lb] * k) > abs(sum(B,lb) - B[lb-1] * k))) lb = lb - 1;
        else lb = lb;
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
