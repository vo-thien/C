#include <stdio.h>
#include <stdlib.h>

void nhapmang(int a[], int &n){
	do{
		printf("Nhap vao n: ");
		scanf("%d", &n);
	}while(n <= 0);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("\nMang da nhap la: \n");
	for(int i = 0; i < n; i++){
		
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void xuatfile(int a[], int n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("Loi mo, tao file");
		return;
	}
	
	for(int i = 0; i < n; i++){
		fprintf(f, "a[%d] = %d\n", i, a[i]);
	}
	
	fclose(f);
}

int main(){
	int a[100];
	int n;
	nhapmang(a, n);
	xuatmang(a, n);
	xuatfile(a, n, "Bai_5.out");
}
