#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct danhsachthuthu{
	int stt;
	char mathuthu[20];
	char tenthuthu[20];
	int namsinh;
};

typedef struct danhsachthuthu tt;

struct node{
	tt data;
	struct node* pnext;
};

struct list{
	struct node* phead;
	struct node* ptail;
};

void khoitao(struct list &l){
	l.phead = NULL;
	l.ptail = NULL;
}

struct node* khoitaonode(tt x){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if(p == NULL){
		printf("Loi cap phat");
		return NULL;
	}
	else{
		p->data = x;
		p->pnext = NULL;
	}
	return p;
}

void themcuoi(struct list &l, struct node* p){
	if(l.phead == NULL){
		l.phead = l.ptail = p;
	}
	else{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}

void xuat(struct list l){
	for(struct node* k = l.phead; k != NULL; k = k->pnext){
		printf("%-15d %-15s %-15s %-15d", k->data.stt, k->data.mathuthu, k->data.tenthuthu, k->data.namsinh);
		printf("\n");
	}
}

void themvaodau(struct list &l, struct node* p){
	if(l.phead == NULL){
		l.phead = l.ptail = p;
	}
	else{
		p->pnext = l.phead;
		l.phead = p;
	}
}

void themtruocma(struct list &l, struct node* p, char mathuthu[20]){
	struct node* g = (struct node*)malloc(sizeof(struct node));
	for(struct node* k = l.phead; k != NULL; k = k->pnext){
		if(strcmp(l.phead->data.mathuthu, mathuthu) == 0){
			themvaodau(l, p);
			return;
		}
		else{
			p->pnext = k;
			g->pnext = p;
		}
		g = k;
	}
}

void menu(struct list l){
	int chon;
	do{
		printf("\n\t====== MENU ======");
		printf("\n1.Them vao cuoi");
		printf("\n2.Xuat");
		printf("\n3.Them vao truoc node");
		printf("\n0.Thoat");
		
		printf("\n\nNhap lua chon cua ban: ");
		scanf("%d", &chon);
		
		switch(chon){
			case 1:{
				tt x;
				printf("Nhap stt: ");
				scanf("%d", &x.stt);
				printf("Nhap ma thu thu: ");
				fflush(stdin);
				gets(x.mathuthu);
				printf("Nhap ten thu thu: ");
				fflush(stdin);
				gets(x.tenthuthu);
				printf("Nhap nam sinh: ");
				scanf("%d", &x.namsinh);
				
				struct node* p = khoitaonode(x);
				themcuoi(l, p);
				break;
			}
			case 2:{
				printf("%-15s %-15s %-15s %-15s", "STT", "Ma thu thu", "Ten thu thu", "nam sinh");
				printf("\n");
				xuat(l);
				break;
			}
			case 3:{
				char mathuthu[20];
				tt x;
				printf("Nhap ma thu thu muon them vao truoc: ");
				fflush(stdin);
				gets(mathuthu);
				printf("Nhap stt: ");
				scanf("%d", &x.stt);
				printf("Nhap ma thu thu: ");
				fflush(stdin);
				gets(x.mathuthu);
				printf("Nhap ten thu thu: ");
				fflush(stdin);
				gets(x.tenthuthu);
				printf("Nhap nam sinh: ");
				scanf("%d", &x.namsinh);
				
				struct node* p = khoitaonode(x);
				themtruocma(l, p, mathuthu);
				break;
			}
		}
	}while(chon != 0);
}

int main(){
	struct list l;
	khoitao(l);
	
	menu(l);
}
