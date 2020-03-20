#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct node {
	char kode_kontainer[30];
	char nama_pengirim[30];
	char jenis_barang[30];
	int berat_barang;
	int total_berat;
    struct node *next;
};

typedef struct node node;

void tambahAwal(node **head);
void insertnode(node **head, node *pPre, node *pNew);
void informasi_data(node *head);
void tranverse(node *head);
void Descending(node *head);
void exitList(node *head);

int main() {
	node *head = NULL;
	char pilih;
	do{
	  	system("cls");
    	system("color f0");
		printf("=================================\n");
		printf("|         Program Train         |\n");
		printf("=================================\n\n");
    	printf("  pilihan Menu :\n");
    	printf("  1. Tambah Data Kontainer\n");
		printf("  2. Tampilkan Train\n");
		printf("  3. Tampilkan Train(Descending)\n");
		printf("  4. Informasi Train\n");
    	printf("  q. Keluar\n");
    	printf("\n  Masukkan pilihan = ");
	    fflush(stdin);
	    scanf("%c", &pilih);
		system("cls");
		switch(pilih){
			case '1' :
				tambahAwal(&head);
				break;
			case '2' :
				tranverse(head);
				break;	
			case '3' :
				Descending(head);
				break;
			case '4' :
				informasi_data(head);
				break;
		}
	} while (pilih != 'q');
  	exitList(head);
  	return 0;
}

//========================================================

void tambahAwal(node **head){
	int i, j, berat, jumlah_pengirim, total=0;
	char nama[30], kode[30], jenis[30];
  	node *pTemp;
  	
  	fflush(stdin);
  	printf("Masukkan kode kontainer		 : ");
  	scanf("%[^\n]", &kode);
  	printf("Masukkan jumlah pengirim (max 10): ");
  	scanf("%d", &jumlah_pengirim);
  	fflush(stdin);
	if(jumlah_pengirim >= 1 && jumlah_pengirim <= 10){
		goto input;
	}
	else{
		main();
	}
	input:
		printf("\n\n"); 
		for(i=0;i<jumlah_pengirim;i++){
			fflush(stdin);
			printf("Data Pengirim Ke %d\n", i+1);
			fflush(stdin);
			printf("Masukkan nama pengirim			: ");
  			scanf("%[^\n]", &nama);	  		
			printf("Masukkan jenis barang			: ");
			fflush(stdin);
	  		scanf("%[^\n]", &jenis);
	 		printf("Masukkan berat barang (TON)		: ");
	 		fflush(stdin);
	  		scanf("%d", &berat);
	  		printf("\n");
			
			total=total+berat;
			
 			pTemp = (node *)malloc(sizeof(node));
  			if (pTemp != NULL){
  				strcpy(pTemp->kode_kontainer,kode);
  				pTemp->next = NULL;
      			strcpy(pTemp->nama_pengirim,nama);
      			pTemp->next = NULL;
      			strcpy(pTemp->jenis_barang,jenis);
      			pTemp->next = NULL;
      			pTemp-> berat_barang = berat;
      			pTemp->next = NULL;
      			pTemp->total_berat = total;
      			insertnode(head, NULL, pTemp);
    			printf("\nData Berhasil Ditambahkan\n\n");
    			getch();
  			}	
  			else{
    			printf("\nAlokasi memori gagal!");
    			getch();
		}
	}
}

//========================================================

void Descending(node *head){
	node *pWalker, *pWalker2, *pWalker3;
	int i, jumlah_pengirim;
	
	pWalker = head;
	pWalker2 = NULL;
	pWalker3 = NULL;
	
	printf("KODE	NAMA PENGIRIM	JENIS BARANG	 BERAT BARANG	   	TOTAL BERAT\n");
		while(pWalker!=NULL && pWalker -> total_berat > pWalker -> total_berat){
			printf("%s	  %s		 %s		  %d TON			  %d TON", pWalker->kode_kontainer, pWalker->nama_pengirim, pWalker->jenis_barang, pWalker->berat_barang, pWalker->total_berat );
			pWalker2 = pWalker;
	   		pWalker = pWalker -> next;
			printf("\n");
			}
			pWalker3 = pWalker2;
			pWalker = head;
		printf("NULL");
		getch();
	}
//========================================================

void informasi_data(node *head){
	int i;
	node *pWalker;
	node *next;
	int total = 0, totalberat=0;

	pWalker=head;

   	if(head == NULL){
   		printf("Data kosong!");
		getch();
	}	
	else{
	while (pWalker != NULL){
	   	total++;
	   	pWalker = pWalker -> next;
	}
   	printf("Total barang	      = %d barang", total);
   	
   	pWalker=head;
	while(pWalker != NULL){
   		totalberat = totalberat + pWalker -> berat_barang;
   		pWalker = pWalker -> next;
	   	}
	   	printf("\nTotal berat kontainer = %d TON", totalberat);
		getch();
	}
}

//========================================================

void tranverse(node *head){
	node *pWalker = head;
	int total_berat=0;
	
	if(head == NULL){
   		printf("Data kosong!");
		getch();
	}	
	else{
		printf("KODE	NAMA PENGIRIM	JENIS BARANG	 BERAT BARANG\n");
		while (pWalker != NULL){	
			printf("%s	  %s		 %s		  %d TON", pWalker->kode_kontainer, pWalker->nama_pengirim, pWalker->jenis_barang, pWalker->berat_barang);
			pWalker = pWalker -> next;
    		printf("\n");
		}
		printf("NULL");
		getch();
		}
}

//========================================================

void insertnode(node **head, node *pPre, node *pNew){
	if (pPre == NULL){
	    pNew -> next = *head;
    	*head = pNew;
    }
    else {
   		pNew -> next = pPre -> next;
		pPre -> next = pNew;
   }
}

//========================================================

void exitList(node *head){
	node *pTemp;
	
	while(head != NULL){
		pTemp = head;
		head = head->next;
		free(pTemp);
  	}
}

//========================================================
