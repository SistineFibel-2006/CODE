#include <stdio.h>

signed main () {
    int num[30];    
    int score[30][3];  
    int sum[30] = {0};    
    float aver[30] = {0};    
    int n, i, j, search_num, found = 0;
    printf("������ѧ������(������30��): ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("�������%d��ѧ����ѧ��: ", i+1);
        scanf("%d", &num[i]);
        
        printf("��������ѧ��Ӣ�������ɼ�(�ÿո�ָ�): ");
        for (j = 0; j < 3; j++) {
            scanf("%d", &score[i][j]);
            sum[i] += score[i][j];
        }
        aver[i] = (float)sum[i] / 3;
    }

    printf("\nѧ��\t��ѧ\tӢ��\t�����\t�ܷ�\tƽ����\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", num[i]);
        for (j = 0; j < 3; j++) {
            printf("%d\t", score[i][j]);
        }
        printf("%d\t%.2f\n", sum[i], aver[i]);
    }

    printf("\n������Ҫ��ѯ��ѧ��: ");
    scanf("%d", &search_num);
    found = 0;
    for (i = 0; i < n; i++) {
        if (num[i] == search_num) {
            found = 1;
            printf("ѧ��\t��ѧ\tӢ��\t�����\t�ܷ�\tƽ����\n");
            printf("%d\t", num[i]);
            for (j = 0; j < 3; j++) {
                printf("%d\t", score[i][j]);
            }
            printf("%d\t%.2f\n", sum[i], aver[i]);
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ�ѧ��Ϊ%d��ѧ��\n", search_num);
    }

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (sum[j] < sum[j+1]) {

                int temp_sum = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = temp_sum;

                float temp_aver = aver[j];
                aver[j] = aver[j+1];
                aver[j+1] = temp_aver;

                int temp_num = num[j];
                num[j] = num[j+1];
                num[j+1] = temp_num;
            
                for (int k = 0; k < 3; k++) {
                    int temp_score = score[j][k];
                    score[j][k] = score[j+1][k];
                    score[j+1][k] = temp_score;
                }
            }
        }
    }
    printf("\n�ɼ�����:\n");
    printf("����\tѧ��\t�ܷ�\tƽ����\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i+1, num[i], sum[i], aver[i]);
    }
    return 0;
}