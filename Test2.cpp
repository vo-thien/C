#include <stdio.h>
#include <stdlib.h>

struct solieubanhang{
	int stt;
	char tenhang[15];
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

void khoitao(struct list &l){
	l.phead = NULL;
	l.ptail = NULL;
}

struct node* khoitaonode(sl x){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if(p == NULL){
		printf("Loi cap phat");
		return NULL;
	}
	else{
		p->data = x;
		p->pnext = NULL;
	}
}

void themvaocuoi(struct list &l, struct node* p){
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
		printf("%-15d %-15s %-15d %-15d %-15d", k->data.stt, k->data.tenhang, k->data.dongia, k->data.soluong, k->data.thanhtien);
		printf("\n");
	}
}

void menu(struct list &l){
	int chon;
	do{
		printf("\n\t====== MENU ======");
		printf("\n1.Them vao cuoi");
		printf("\n2.Xuat");
		printf("\n0.Thoat");
		
		printf("\n\nNhap lua chon cua ban: ");
		scanf("%d", &chon);
		
		switch(chon){
			case 1:{
				sl x;
				printf("Nhap stt: ");
				scanf("%d", &x.stt);
				printf("Nhap Ten hang: ");
				fflush(stdin);
				gets(x.tenhang);
				printf("Nhap Don gia: ");
				scanf("%d", &x.dongia);
				printf("Nhap so luong: ");
				scanf("%d", &x.soluong);
				x.thanhtien = x.dongia * x.soluong;
				
				struct node* p = khoitaonode(x);
				themvaocuoi(l, p);
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
	khoitao(l);
	menu(l);
}
