#include <stdio.h>

void nhap(int a[100], int n){
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

float tbc(int a[100], int n){
	float tb;
	float count = 0;
	float sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0 && a[i] > 5){
			sum += a[i];
			++count;
		}
	}
	if(count == 0){
		return 0;
	}
	else{
		tb = sum/count;
		return tb;
	}
}

int main(){
	int a[100];
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	nhap(a, n);
	if(tbc(a, n) == 0){
		printf("Khong co so hop le");
	}
	else{
		printf("Trung binh cac so chan lon hon 5: %.2f", tbc(a, n));
	}
}
