#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct solieubanhang{
	int stt;
	char tenhang[20];
	int dongia;
	int soluong;
	int thanhtien;
};

typedef struct solieubanhang sl;

struct node{
	sl data;
	struct node* pnext;
};

struct list{
	struct node* phead;
	struct node* ptail;
};

void khoitao(struct list *l){
	l->phead = NULL;
	l->ptail = NULL;
}

struct node *khoitaonode(sl x){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if(p == NULL){
		printf("Loi cap phat");
	}
	else{
		p->data = x;
		p->pnext = NULL;
	}
	return p;
}

void them(struct list *l, struct node* p){
	if(l->ptail == NULL){
		l->ptail = l->phead = p;
	}
	else{
		p->pnext = l->ptail;
		l->ptail = p;
	}
}

void xuat(struct list l){
	for(struct node* k = l.ptail; k != NULL; k = k->pnext){
		printf("%-15d %-15s %-15d %-15d %-15d", k->data.stt, k->data.tenhang, k->data.dongia, k->data.soluong, k->data.thanhtien);
		printf("\n");
	}
}

void menu(struct list l){
	int chon;
	do{
		printf("\n\t====== MENU ======");
		printf("\n1. Them");
		printf("\n2. Xuat");
		printf("\n0. Thoat");
		
		printf("\n\nNhap lua chon cua ban: ");
		scanf("%d", &chon);
		
		switch(chon){
			case 1:{
				sl x;
				printf("Nhap stt: ");
				scanf("%d", &x.stt);
				printf("Nhap ten hang: ");
				fflush(stdin);
				gets(x.tenhang);
				printf("Don gia: ");
				scanf("%d", &x.dongia);
				printf("Nhap so luong: ");
				scanf("%d", &x.soluong);
				x.thanhtien = x.dongia * x.soluong;
				
				struct node* p = khoitaonode(x);
				them(&l, p);
				break;
			}
			case 2:{
				printf("%-15s %-15s %-15s %-15s %-15s", "Stt", "Ten hang", "Don gia", "So luong", "Thanh tien");
				printf("\n");
				xuat(l);
				break;
			}
		}
	}while(chon != 0);
}

int main(){
	struct list l;
	khoitao(&l);
	menu(l);
}
