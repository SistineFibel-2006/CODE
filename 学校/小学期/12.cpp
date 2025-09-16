#include <stdio.h>
#include <string.h>

#define MAX_STUFF 10

struct Stuff {
    char name[20];
    int num;
    float bonus;
};

void print(struct Stuff staff[], int count) {
    printf("����Ա����Ϣ��\n");
    printf("Ա����\t����\tн��\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", staff[i].num, staff[i].name, staff[i].bonus);
    }
    printf("\n");
}

void search(struct Stuff staff[], int count) {
    printf("н�ʴ���5000��Ա����\n");
    printf("Ա����\t����\tн��\n");
    for (int i = 0; i < count; i++) {
        if (staff[i].bonus > 5000) {
            printf("%d\t%s\t%.2f\n", staff[i].num, staff[i].name, staff[i].bonus);
        }
    }
    printf("\n");
}

void update(struct Stuff staff[], int count, int num, float amount) {
    for (int i = 0; i < count; i++) {
        if (staff[i].num == num) {
            staff[i].bonus += amount;
            printf("Ա��%d��н���Ѹ���Ϊ%.2f\n\n", num, staff[i].bonus);
            return;
        }
    }
    printf("δ�ҵ�Ա��%d\n\n", num);
}

int remove_staff(struct Stuff staff[], int count, int num) {
    for (int i = 0; i < count; i++) {
        if (staff[i].num == num) {
            for (int j = i; j < count - 1; j++) {
                staff[j] = staff[j + 1];
            }
            printf("Ա��%d��ɾ��\n\n", num);
            return count - 1;
        }
    }
    printf("δ�ҵ�Ա��%d\n\n", num);
    return count;
}

int insert(struct Stuff staff[], int count, int pos, struct Stuff new_staff) {
    if (pos < 0 || pos > count) {
        printf("��Ч��λ��\n\n");
        return count;
    }
    
    if (count >= MAX_STUFF) {
        printf("Ա�������Ѵ����ޣ��޷�����\n\n");
        return count;
    }
    
    for (int i = count; i > pos; i--) {
        staff[i] = staff[i - 1];
    }
    
    staff[pos] = new_staff;
    printf("��Ա���Ѳ��뵽λ��%d\n\n", pos);
    return count + 1;
}

int main() {
    struct Stuff staff[MAX_STUFF] = {
        {"zhang", 1001, 5000.00},
        {"wang", 1002, 5200.00},
        {"xu", 1003, 4700.00},
        {"zhao", 1004, 4200.00},
        {"sun", 1005, 6100.00}
    };
    int count = 5;
    
    print(staff, count);
    
    search(staff, count);
    
    update(staff, count, 1003, 1000.00);
    print(staff, count); 
    
    count = remove_staff(staff, count, 1004);
    print(staff, count); 
    
    struct Stuff new_staff = {"li", 1006, 5500.00};
    int pos = 2; 
    count = insert(staff, count, pos, new_staff);
    print(staff, count); 
    
    return 0;
}