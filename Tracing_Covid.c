#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct Covid19 {
    char diadiem[40];
    int gio, phut;
    struct Covid19 *Next;
}CV;

CV *BN;

CV *CreateNewNode(char diadiem[], int gio, int phut){
    CV *newnode=(CV*)malloc(sizeof(CV));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    newnode -> gio = gio;
    newnode -> phut = phut;
    strcpy(newnode -> diadiem, diadiem);
    newnode->Next=NULL;
    return newnode;
}

CV* Insert(CV* A, char diadiem[], int gio, int phut) {
    CV *node = CreateNewNode(diadiem, gio, phut);
    if (A == NULL) {
        A = node;
    }
    else {
        CV *tg = A;
        while ( tg -> Next != NULL) {
            tg = tg -> Next;
        }
        tg -> Next = node;
    }
    return A;
}

void DocFile( ) {
    FILE* fptr;
    int gio, phut;
    char diadiem[40];
    if ((fptr = fopen("log.txt", "r")) == NULL) {
        printf("Cannot open A.txt\n");
        return;
    }
    while (!feof(fptr)) {
        fscanf(fptr, "%s", &diadiem);
        fscanf(fptr, "%d", &gio);
        fscanf(fptr, "%d", &phut);
        BN = Insert(BN, diadiem, gio, phut);
        fflush(stdin);
    }
    fclose(fptr);
    return;
}

void Print() {
    CV *tg = BN;
    printf("------------Lich su  di chuyen:\n");
    while (tg != NULL) {
        printf("%-50s%-10d%-10d\n", tg -> diadiem, tg -> gio, tg -> phut);
        tg = tg -> Next;
    }
}

void Find1() {
    fflush(stdin);
    char a[40];
    printf("\nHay nhap vao dia diem can tim: "); gets(a); 
    CV *tg = BN; 
    int k = 0;
    printf("Nhap vao   Ket qua in ra\n");
    printf("%-10s",a);
    while (tg != NULL) {
        if (strcmp(tg ->diadiem,a) == 0) {
            printf(" %d:%d,", tg -> gio, tg -> phut);
            k = 1;
        }
        tg = tg -> Next;
    }  
    if (k == 0) {
        printf("Ban chua toi dia diem do");
    }
}

void Find2() {
    fflush(stdin);
    int gio, phut, k = 0;
    CV *tg = BN;
    printf("Nhap vao gio : "); scanf("%d", &gio);
    while ( gio < 0 || gio >= 24) {
        printf("Nhap sai gio! Hay Nhap lai gio : "); scanf("%d", &gio);
    }
    printf("Nhap vao phut : "); scanf("%d", &phut);
    while ( phut < 0 || phut >= 60) {
        printf("Nhap sai phut! Hay Nhap lai phut : "); scanf("%d", &phut);
    }
    printf("Nhap vao    Ket qua in ra\n");
    printf("%d:%-10d", gio, phut);
    while (tg != NULL) {
        if (tg -> gio == gio && tg -> phut == phut) {
            printf("%s", tg -> diadiem);
            k = 1;
        }
        tg = tg -> Next;
    }  
    if (k == 0) {
        printf("Khong xac dinh");
    }
}

void TruyVet() {
    fflush(stdin);
    char a[40];
    int gio, phut, k = 0;
    CV *tg = BN;
    printf("\nHay nhap vao dia diem can tim: "); gets(a);
    printf("Nhap vao gio : "); scanf("%d", &gio);
    printf("Nhap vao phut : "); scanf("%d", &phut);
    printf("Nhap vao             Ket qua in ra\n");
    printf("%s %d:%-10d", a, gio, phut);
    while (tg != NULL) {
        if (BN -> gio > gio && strcmp(BN -> diadiem, a) == 0) {
            printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
            k = 1;
        }
        if (BN -> gio == gio && BN -> phut > phut && strcmp(BN -> diadiem, a) == 0) {
            printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
            k = 1;
        }
        if (tg -> gio == gio && tg -> phut <= phut) {
            if (tg -> Next == NULL) {
                if (strcmp(tg -> diadiem,a) == 0) {
                    printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
                    k = 1;
                }
            }
            else {
                if (tg -> Next -> gio > gio) {
                    if (strcmp(tg -> diadiem,a) == 0) {
                        printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
                        k = 1;
                    }
                }
                if (tg -> Next -> gio == gio && tg -> Next -> phut > phut) {
                    if (strcmp(tg -> diadiem,a) == 0) {
                        printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
                        k = 1;
                    }
                }
            }
        }
        if (tg -> gio < gio && tg -> Next -> gio > gio && tg -> Next != NULL) {
            if (strcmp(tg -> diadiem,a) == 0) {
                printf("Ban co kha nang bi lay nhiem Covid, can phai khai bao y te ngay lap tuc!");
                k = 1;
            }
        }
        tg = tg -> Next;
    }  
    if (k == 0) {
        printf("Lich su di chuyen cua ban OK");
    }
}

int main ( ) {
    int s;
    char a;
    do {
        printf("\n");
        printf("  ======Nhap vao so bat ky de thuc hien chuc nang======\n");
        printf("  [ 1 ] Nap du lieu lich su di chuyen                  \n");
        printf("  [ 2 ] In ra lich su di chuyen                        \n");
        printf("  [ 3 ] Tim kiem lich su di chuyen theo dia diem       \n");
        printf("  [ 4 ] Tim kiem thong tin di chuyen theo thoi gian    \n");
        printf("  [ 5 ] Kiem tra truy vet moi nhat                     \n");
        printf("  [ 6 ] Thoat                                          \n");
        printf("  -----------------------------------------------------\n");
        fflush(stdin);
        printf("\n\n Nhap lua chon cua ban:   ");
        scanf("%d", &s);
        while (s < 1 || s > 6) {
            printf("\nLua chon khong hop le, nhap lai: ");
            fflush(stdin);
            scanf("%d", &s);
        }
        switch (s) {
            case 1:
                printf("Thuc hien chuc nang 1:\n");
                DocFile();
                printf("Doc thanh cong du lieu");
                break;
            case 2:
                printf("Thuc hien chuc nang 2:\n");
                Print();
                break;
            case 3:
                printf("Thuc hien chuc nang 3:\n");
                Find1();
                break;
            case 4:
                printf("Thuc hien chuc nang 4:\n");
                Find2();
                break;
            case 5:
                printf("Thuc hien chuc nang 5:\n");
                TruyVet();
                break;
            case 6:
                printf(" Goodbye");
                return 0;
        }
    } while (s <= 6);
}