#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
# define MAX 99
struct date{
	int ngay;
	int thang;
	int nam;
};

struct SinhVien{
	char ho[10];
	char ten[30];
	date ngaysinh;
	char gioitinh[5];
	char diachi[50];
	char mssv[10];
	char email[30];
};

typedef SinhVien SV;

void printLine(int n){
	printf("\n");
	for (int i = 0; i < n; i++) {
	    printf("_");
    }
    printf("\n");
}
void taoFile(char fileName[], char lop[]){
	strcpy(fileName,lop);
	strcat(fileName,".txt");
	FILE * fp;
	fp = fopen (fileName, "w");
	int fclose(FILE * fp);
	printf("Da tao file ");
	puts(fileName);
}

int docFile(SV a[], char fileName[]) {
	int i = 0;
	FILE * fp;
	while(1){
		printf("Nhap ten file: ");
		fflush(stdin);
		gets(fileName);
		fp = fopen (fileName, "r");
		if(fp==NULL) printf("Loi file!");
		else break;
	}
    printf("Dang doc file:  ");
	puts(fileName);
	while (fscanf(fp, "%10s%30s%d/%d/%4d%5s%50s\n", &a[i].ho, &a[i].ten, &a[i].ngaysinh.ngay, &a[i].ngaysinh.thang, &a[i].ngaysinh.nam, &a[i].gioitinh, &a[i].diachi) != EOF){
	    i++;
	}
    printf("So luong sinh vien co san trong file la: %d\n", i);
	fclose (fp);
	return i;
}

void ghiFile(SV a[], int n, char fileName[]){
	FILE * fp;
	fp = fopen (fileName,"w");
	for(int i = 0;i < n;i++){
	    fprintf(fp, "%10s%30s%d/%d/%4d%5s%50s\n", a[i].ho, a[i].ten, a[i].ngaysinh.ngay, a[i].ngaysinh.thang, a[i].ngaysinh.nam, a[i].gioitinh, a[i].diachi);
    	}
	fclose (fp);
}
void pressAnyKey(){
	printf("\nBam phim bat ky de tiep tuc...");
	getch();
	system("cls");
}

void nhapThongTinSV(SV &sv) {
	printf(" Nhap ho: ");
	fflush(stdin);
	gets(sv.ho);
	printf(" Nhap ten: ");
	fflush(stdin);
	gets(sv.ten);
	printf(" Nhap ngay/thang/nam sinh: ");
	scanf("%d/%d/%d", &sv.ngaysinh.ngay, &sv.ngaysinh.thang, &sv.ngaysinh.nam);
	printf(" Nhap gioi tinh: ");
	fflush(stdin);
	gets(sv.gioitinh);
	printf(" Nhap dia chi: ");
	fflush(stdin);
	gets(sv.diachi);
	strcpy(sv.email,"chua cap");
	strcpy(sv.mssv,"chua cap");
	printLine(40);
}

void nhapSV(SV a[], int i) {
	printLine(40);
	printf("\n Nhap sinh vien thu %d:\n", i + 1);
	nhapThongTinSV(a[i]);
	printLine(40);
}

void sapXepTheoTen(SV a[], int n) {
	SV tmp;
	char tenSV1[30];
	char tenSV2[30];
	for(int i = 0;i < n; i++) {
	    strcpy(tenSV1, a[i].ten);
	    for(int j = i+1; j < n; j++) {
	    	strcpy(tenSV2, a[j].ten);
	       	if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
	       		tmp = a[i];
	       		a[i] = a[j];
	       		a[j] = tmp;
       		}
       	}
    }
}

void showStudent(SV a[], int n) {
	printLine(100);
	printf("\nSTT\tHo\tTen\t\tNgaySinh\tGioi tinh\tDiaChi\t\tMSSV\t\tEmail");
	for(int i = 0; i < n; i++) {
	    printf("\n%d", i + 1);
	    printf("\t%s", a[i].ho);
	    printf("\t%s", a[i].ten);
	    printf("\t\t%d", a[i].ngaysinh.ngay);
	    printf("/%d", a[i].ngaysinh.thang);
	    printf("/%d", a[i].ngaysinh.nam);
	    printf("\t%s", a[i].gioitinh);
	    printf("\t\t%s", a[i].diachi);
	    printf("\t%s", a[i].mssv);
	    printf("\t%s", a[i].email);
    }
	printLine(100);
}

int xoaTheoTen(SV a[], char tim_ho[], char tim_ten[], int n){
	int found = 0;
	int i;
	for(i = 0; i < n; i++){
        if (strcmp(a[i].ho,tim_ho)==0||strcmp(a[i].ten,tim_ten)==0){
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++){
                a[j] = a[j+1];
            }
            printf("\n Da xoa SV %c %c", tim_ho, tim_ten);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien %c %c khong ton tai.", tim_ho, tim_ten);
        return 0;
    } else {
        return 1;
    }
}
		
int xoaTheoMSSV(SV a[], char id[], int n) {
    int found = 0;
    int i;
    for(i = 0; i < n; i++){
        if (strcmp(a[i].mssv,id)==0){
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            printf("\n Da xoa SV co MSSV = %c", id);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co MSSV = %c khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void cap_mssv(SV &sv, char fileName[]){
	char tmp[10];
	int len = strlen(fileName);
	strcpy(sv.mssv,"102");
	strncpy(tmp, fileName, 2);
	strcat(sv.mssv, tmp);
	strncpy(tmp, fileName + len - 2, 2);
	strcat(sv.mssv, tmp);
}

void cap_email(SV &sv){
	strcpy(sv.email, sv.mssv);
	strcat(sv.email, "@sv.dut.udn.vn");
}

main(){
	int chon;
	char lop[10], fileName[20];
	SV arraySV[MAX];
	int soluongSV = 0;
	int check = 0, check1 = 0;
	char tim_ho[10], tim_ten[30], id[10];
	int i;
	while(1){
		printf("CHUONG TRINH QUAN LY SINH VIEN\n");
		printf( "=======================================================\n");
		printf( "**  1. Tao lop moi.                                  **\n");
		printf( "**  2. Nhap lop tu file.                             **\n");
		printf( "**  3. Thoat                                         **\n");
		printf( "=======================================================\n");
		printf( "Nhap tuy chon: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("Nhap ten lop: ");
				fflush(stdin);
				gets(lop);
				taoFile(fileName,lop);
				pressAnyKey();
				break;
			case 2:	
				soluongSV = docFile(arraySV, fileName);
				pressAnyKey();
				break;
			case 3:
				printf("\nBan da chon thoat chuong trinh!");
				getch();
				return 0;	
			default:
				printf( "\nKhong co chuc nang nay!");
				printf( "\nHay chon chuc nang trong hop menu.\n");
				pressAnyKey();
				system("cls");
				break;
		}
		if(chon==1||chon==2||chon==3) break;
	}
	while(1){
		printf("CHUONG TRINH QUAN LY SINH VIEN\n");
		printf( "=======================================================\n");
		printf( "**  1. Them sinh vien.                               **\n");
		printf( "**  2. Sap xep danh sach theo ten.                   **\n");
		printf( "**  3. Xoa sinh vien.                                **\n");
		printf( "**  4. Tim kiem sinh vien theo ten.                  **\n");
		printf( "**  5. Cap ma sinh vien.                             **\n");
		printf( "**  6. Cap email.                                    **\n");
		printf( "**  7. Ghi danh sach sinh vien vao file.             **\n");
		printf( "**  8. Thoat                                         **\n");
		printf( "=======================================================\n");
		printf( "Nhap tuy chon: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("\n1. Them sinh vien.");
				nhapSV(arraySV, soluongSV);
				printf("\nThem sinh vien thanh cong!");
				soluongSV++;
				check1 = 0;
				pressAnyKey();
				break;
			case 2:
				if(soluongSV > 0){
					printf("\n2. Sap xep sinh vien theo ten.");
					sapXepTheoTen(arraySV, soluongSV);
					showStudent(arraySV, soluongSV);
				}else printf("\nSanh sach sinh vien trong!");
				pressAnyKey();
				check1 = 1;
				break;
			case 3:
				if(soluongSV > 0){
            	    printf("\n3. Xoa sinh vien.");
             	   printf( "\n\n1. Xoa theo ten.");
                	printf( "\n2. Xoa theo ma so sinh vien");
                	printf( "\nNhap tuy chon: ");
					scanf("%d",&chon);
					switch(chon){
						case 1:
							printf("\nNhap ho ten sinh vien:");
							printf("\nNhap ho: ");
							fflush(stdin);
							gets(tim_ho);
							printf("\nNhap ten:");
							fflush(stdin);
							gets(tim_ten);
							if(xoaTheoTen(arraySV, tim_ho, tim_ten, soluongSV) == 1){
								printf("\nSinh vien %c %c da bi xoa.", tim_ho, tim_ten);
								soluongSV--;
							}
            				pressAnyKey();
            				break;
						case 2:
							if(check==0) printf("Chua cap ma sinh vien!");
							else{
                				printf("\n Nhap MSSV: ");
								fflush(stdin);
								gets(id);
                				if (xoaTheoMSSV(arraySV, id, soluongSV) == 1){
                    			printf("\nSinh vien co ma so sinh vien = %c da bi xoa.", id);
                    			soluongSV--;
                    			}
	               			}
            				pressAnyKey();
            				break;
            		}
            	}else printf("\nSanh sach sinh vien trong!");
            case 4:
            	if(soluongSV > 0){
                	printf("\n4. Tim kiem sinh vien theo ten.");
                	char strTen[30];
                	printf("\nNhap ten de tim kiem: ");
					fflush(stdin);
					gets(strTen);
                	timKiemTheoTen(arraySV, strTen, soluongSV);
            	}else printf("\nSanh sach sinh vien trong!");
            	pressAnyKey();
            	break;
            case 5:
            	if(soluongSV > 0){
                	printf("\n5. Cap ma so sinh vien.");
                	if(check1==0){
                		printf("\nChua sap xep danh sach!");
                		break;
					}
					for(i=0;i<soluongSV;i++){
						cap_mssv(arraySV[i],fileName);
						if(i<10) strcat(arraySV[i].mssv,"0");
						char temp[10];
						itoa(i,temp,10);
						strcat(arraySV[i].mssv, temp);
					}
					printf("\nCap ma so sinh vien thanh cong!");
					check = 1;
            	}else printf("\nSanh sach sinh vien trong!");
            	pressAnyKey();
            	break;
            case 6:
            	if(soluongSV > 0){
                	printf("\n5. Cap email.");
                	if(check1==0){
                		printf("\nChua sap xep danh sach!");
                		break;
					}
					if(check==0){
						printf("Chua cap ma sinh vien!");
						break;
					}
					for(i=0;i<soluongSV;i++) cap_email(arraySV[i]);
					printf("\nCap email thanh cong!");
            	}else printf("\nSanh sach sinh vien trong!");
            	pressAnyKey();
            	break;	
			case 7:
				if(soluongSV > 0) {
					printf("\n7. Ghi danh sach sinh vien vao file.");
					ghiFile(arraySV, soluongSV, fileName);
				}else printf( "\nSanh sach sinh vien trong!");
				printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
				pressAnyKey();
				break;
			case 8:
				printf("\nBan da chon thoat chuong trinh!");
				getch();
				return 0;
			default:
				printf( "\nKhong co chuc nang nay!");
				printf( "\nHay chon chuc nang trong hop menu.");
				pressAnyKey();
				break;
		}
	}
}
