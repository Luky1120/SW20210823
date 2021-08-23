#include<stdio.h>

int min(i,j) {

}
void ex1() {
    int a[10];
    int sum = 0;
    double avg;
    int result;
    int max, min;
    printf("10개의 정수를 입력하시오 : ");
    
    for (int i = 0; i < 10; i++) {
        
        printf("%d.", i + 1);
        scanf("%d", &a[i]);
        if (a[i] >= 0 && a[i] <= 10000) {
            sum += a[i];
        }
        else {
            printf("범위 초과\n");
            return 0;
        }
    }
    max = a[0];
    min = a[0];
    for (int i = 1; i <= 9; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if (min > a[i]) {
            min = a[i];
        }
    }
    sum = sum - min - max;
    avg = sum / (double)8;
    int b = ((int)(avg * 10)) % 10;

    if (b > 4) {
        result = (int)avg + 1;
    }
    else {
        result = (int)avg;
    }
    printf("%d\n", result);
}
void ex2() {
    int n,m;
    
    printf("범위 설정 : ");
    scanf("%d", &n);
    int** arr1;
    arr1 = (int**)malloc(sizeof(int*) * n);
    arr1[0] = (int*)malloc(sizeof(int) * n * n);
    for (int i = 1; i <n; i++) {
        arr1[i] = arr1[i - 1] + n;
    }


    printf("파리채 크기 설정 : ");
    scanf("%d", &m);
   

   

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d %d = ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    int a = 0, a1 = m;
    int b = 0, b1 = m;
    int sum = 0;
    int max = 0;
    while (1) {
        
            for (int i = a; i < a1; i++) {
                for (int j = b; j < b1; j++) {
                    sum += arr1[i][j];
                    if (max < sum) {
                        max = sum;
                        sum = 0;
                    }
                    else {
                        sum = 0;
                    }

                }
            }
            a++;
            a1++;
            if (a1 < n-1) {
                a = 0;
                a1 = m;
                b++;
                b1++;
            }
            if (b1 < n-1) {
                break;
            }

    }
    printf("%d", max);
    free(arr1);
   

}

int main(void) {
    int exnum;
    printf("예제 번호 입력 : ");
    scanf("%d", &exnum);

    switch (exnum)
    {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    }
}