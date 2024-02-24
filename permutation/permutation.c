#include <stdio.h>
#define N 10

int numperms(int perm[], int used[], int k, int jumps[], int len);

int main(){
    int nums[N] = {0};
    int used[N] = {0};
    int jumps[] = {-3,-2,2,3};

    printf("%d\n", numperms(nums, used, 0, jumps, sizeof(jumps)/sizeof(jumps[0])));

    return 0;
}

int numperms(int perm[], int used[], int k, int jumps[], int len){
    int res = 0;

    if (k == N){
        return 1;
    }

    for (int i = 0; i < N; i++){
        if (!used[i]){
            int flag = 0;
            if (k == 0){
                flag = 1;
            }
            else{
                for (int j = 0; j < len; j++){
                    if (i-perm[k-1] == jumps[j]){
                        flag = 1;
                    }
                }
            }
            if (flag){
                used[i] = 1;
                perm[k] = i;
                res += numperms(perm, used, k+1, jumps, len);
                used[i] = 0;
            }
        }
    }

    return res;
}