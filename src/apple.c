#include <stdio.h>

int n;
int k;
int A[100000];

int canBeIn(int x){
    int l, i, y;
    l = 0;
    for(i=0; i < n; i++){
        l = ((A[i] + x - 1) / x) + l;
    }
    if(l <= k) return (1);
    else return (0);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
    lb = 0;
    ub = 10000;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    while(ub - lb > 1){
        int m = (ub + lb) / 2;
        if(canBeIn(m)) ub = m;
        else lb = m;
    }
  printf("%d\n",ub);
  return 0;
}
