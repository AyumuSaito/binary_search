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
    int i, lb, ub, a, b, sum, u;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = 0;
    u = n;
    while(k >= 2){
        for(i=0; i < n; i++){
            B[i] = 0;
        }
        sum = 0;
        b = 0;
        u = u - lb;
        for(i=n-u; i < n; i++){
            B[i-n+u] = A[i];
        }
        for(i=0; i < n-lb; i++){
            sum = B[i] + sum;
        }
        lb = 0;
        ub = u - k + 1;
        while(ub - lb > 1){
            int m = (ub + lb) / 2;
            if(canCut(m,B)) ub = m;
            else lb = m;
        }
        for(i=0; i < lb; i++){
            b = B[i] + b;
        }
        if(lb == 0){
            b = B[0];
            lb = lb + 1;
        }
        else{
            if(abs(sum - b * k) > abs(sum - (b + B[lb]) * k)){
            b = b + B[lb];
            lb = lb + 1;
        }
        }
        if(a < b) a = b;
        k = k - 1;
        for(i=0; i<n; i++){
        }
    }
    b = 0;
    for(i=lb; i < n; i++){
        b = B[i] + b;
    }
    if(a < b) a = b;
    printf("%d\n",a);
    return 0;
}
