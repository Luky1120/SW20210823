#include<stdio.h>

int min(i,j) {

}
void ex1() {
    int a[10];
    int sum = 0;
    double avg;
    int result;
    int max, min;
    printf("10���� ������ �Է��Ͻÿ� : ");
    
    for (int i = 0; i < 10; i++) {
        
        printf("%d.", i + 1);
        scanf("%d", &a[i]);
        if (a[i] >= 0 && a[i] <= 10000) {
            sum += a[i];
        }
        else {
            printf("���� �ʰ�\n");
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
    
    printf("���� ���� : ");
    scanf("%d", &n);
    int** arr1;
    arr1 = (int**)malloc(sizeof(int*) * n);
    arr1[0] = (int*)malloc(sizeof(int) * n * n);
    for (int i = 1; i <n; i++) {
        arr1[i] = arr1[i - 1] + n;
    }


    printf("�ĸ�ä ũ�� ���� : ");
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
    printf("���� ��ȣ �Է� : ");
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