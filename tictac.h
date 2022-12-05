#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct{
    char *Nama[100]; // *Nama2[100];
}Nama;

Nama Player1, Player2;

typedef struct{
    char AngkaAwal[8][8];
    int Dimensi;
}papan;

typedef struct{
    int Baris, Kolom;
}Kotak;

papan Board;
Kotak Input;

int i,j;

char simbol[4]={6,6,3,3}; //variabel untuk mencetak simbol

// Header Modul

void DrawJudul();
/*Prosedur untuk menampilkan menu awal. Berisi opsi :
1. mulai game
2. intruksi
3. highscore
4. quit
I.S: Judul program belum tampil di layar
F.S: Judul program tampil di layar
*/

void CetakIntruksi();
/*Prosedur berisi intruksi permainan tic tac toe
I.S: Instruksi belum muncul dilayar
F.S: Instruksi muncul di layar
*/

void CetakQuit();
/*Prosedur berisi kata-kata untuk bermain kembali kepada player
*/

void CetakDimensi(); 
/*Prosedur untuk menampilkan opsi dimensi yang akan dipilih
1. dimensi 3x3
2. dimensi 5x5
3. dimensi 7x7 
I.S: Menu dimensi papan belum muncul di layar
F.S: Menu dimensi papan muncul di layar
*/

void Inputkotak();
/*Prosedur untuk menerima nilai baris dan kolom yang diinput oleh user yang 
akan masuk ke dalam variabel baris dan kolom
*/       

void Cetakmenang();
/*Prosedur untuk menampilkan kondisi menang untuk player yang mengacu pada nilai variabel kode yang dimasukkan ke parameter
jika 1 : menampilkan kondisi menang untuk player 1
jika 2 : menampilkan kondisi menang untuk player 2
*/

void CetakPapan(char AngkaAwal[8][8], int Dimensi);
/*Prosedur untuk menampilkan papan tic tac toe dimensi 3x3,5x5, dan 7x7 dengan memasukkan 
sebuah angka ke dalam variabel dimensi. 
jika 1 : menampilkan papan 3x3
jika 2 : menampilkan papan 5x5
jika 3 : menampilkan papan 7x7
*/

int KondisiWin(char AngkaAwal[8][8], int Dimensi);
/*Fungsi untuk mengembalikan nilai 1 atau 2 berdasarkan kondisi yang sudah ditentukan berdasarkan dimensinya masing-masing */

void gotoxy(int x, int y);

void CetakLoading();

void CetakAbout();

//BodyModul

void DrawJudul(){
    printf("\n\t\t   _______________________________________\t\t\t\t\t\t #BSC-Synergy\n");
    printf("\t\t   |                                     |\n");
    printf("\t\t   |    ########   ######   ######## \t |\n");
    printf("\t\t   |       ##        ##     ##       \t |\n");
    printf("\t\t   |       ##        ##     ##       \t |\n");
    printf("\t\t   |       ##        ##     ##       \t |\n");
    printf("\t\t   |       ##      ######   ######## \t |\n");
    printf("\t\t   |________________                     |___________________\n");
    printf("\t\t                   |                                        |\n");
    printf("\t\t\t\t   |\t########      ###       ########    |\n");
    printf("\t\t\t\t   |\t   ##       ##   ##     ##          |\n");
    printf("\t\t\t\t   |\t   ##      #########    ##          |\n");
    printf("\t\t\t\t   |\t   ##     ##       ##   ##          |\n");
    printf("\t\t\t\t   |\t   ##    ##         ##  ########    |\n");
    printf("\t\t\t\t   |________________                        |______________\n");
    printf("\t\t\t\t                   |                                      |\n");  
    printf("\t\t\t\t\t\t   |     ########   ########   ########   |\n");
    printf("\t\t\t\t\t\t   |        ##      ##    ##   ##         | \n");
    printf("\t\t\t\t\t\t   |        ##      ##    ##   ########   |\n");
    printf("\t\t\t\t\t\t   |        ##      ##    ##   ##         |\n");
    printf("\t\t\t\t\t\t   |        ##      ########   ########   |\n"); 
    printf("\t\t\t\t                   |______________________________________|\n\n"); 
    printf("\t\t\t\t\t\t   1. Mulai \n");
    printf("\t\t\t\t\t\t   2. Instruksi\n");
    printf("\t\t\t\t\t\t   3. Selesai\n");
    printf("\t\t\t\t\t\t   3. About\n\n");
    printf("  Apa yang pengen kamu lakuin? (masukan nomor) : ");
}

void CetakIntruksi(){
    printf("\n\t\t\t\t\t\t%c\tIntruksi\t%c\n", simbol[0], simbol[1]);
	printf("\t\t\t\t\t=========================================\n\n");
	printf("\t_________________________________________________________________________________________________________\n");
	printf("\t|                                                                                                       |\n");
    printf("\t| 1. Player memilih opsi 1 untuk memulai permainan.\t\t\t\t\t\t\t|\n");
	printf("\t| 2. Player akan diminta mengisi nama.\t\t\t\t\t\t\t\t\t|\n");
    printf("\t| 3. Player akan diminta memilih dimensi board yang akan dimainkan.\t\t\t\t\t|\n");
	printf("\t| 4. Player akan diminta menginput baris dan kolom, sesuai dengan kotak yang ingin di isi \t\t|\n");
	printf("\t| 5. Player akan diberi waktu selama 10 detik untuk mengisi kotak.\t\t\t\t\t|\n");
	printf("\t| 6. Player tidak bisa mengisi kotak yang sudah terisi sebelumnya, jika terisi maka akan invalid.   \t|\n");
    printf("\t| 7. Player tidak bisa menginput baris/kolom diluar jangkauan board yang dipilih,    \t\t\t|\n");
    printf("\t|     jika dipilih maka akan invalid.    \t\t\t\t\t\t\t\t|\n");
	printf("\t| 8. Player dinyatakan menang jika bisa membuat garis pertama secara horizontal,vertikal, \t\t|\n");
    printf("\t|     ataupun diagonal dari 3 bidaknya.   \t\t\t\t\t\t\t\t|\n");
	printf("\t| 9. Permainan dinyatakan draw jika board sudah terisi penuh dan keduanya tidak membuat \t\t|\n");
    printf("\t|     3 bidak yang membentuk garis.   \t\t\t\t\t\t\t\t\t|\n");
	printf("\t| 10. Player dinyatakan kalah jika lawan yang pertama membuat garis dari ketiga bidaknya.         \t|\n");
    printf("\t| 11. Jika game sudah selesai, player akan diberikan pilihan untuk kembali main atau tidak.    \t\t|\n");
	printf("\t|                                                                                                       |\n");
	printf("\t|_______________________________________________________________________________________________________|\n\n");
	printf("\n\n\t Kembali(00) : ");
}

void CetakDimensi(){
    printf("\nPilih Dimensi Board Yang Akan Anda Mainkan: \n");
    printf("\n\t\t=======================");
    printf("\n\t\t||\t       \t     ||");
    printf("\n\t\t||\t1. 3x3 \t     ||");
    printf("\n\t\t||\t2. 5x5 \t     ||");
    printf("\n\t\t||\t3. 7x7 \t     ||\n");
    printf("\t\t||\t             ||\n");
    printf("\t\t=======================\n");
    printf("\nMasukkan Angka (1/2/3): ");
}

void InputKotak(Kotak *Put){
    scanf("%d,%d",&Put->Baris,&Put->Kolom);
}

void CetakMenang(Nama *Player){
    printf("\t\t\t\t>> %s Win <<",*Player);
}


void Countdown(int *detik)
{
    while(*detik>=0){
        printf("      \r%d",*detik);
        Sleep(1000);
        if(*detik!=0){
            *detik--;
        }
    }
}
 

void CetakQuit(){
    printf("\n\n\t\t\t\t\t____________________________________\n");
	printf("\t\t\t\t\t|                                  |\n");
    printf("\t\t\t\t\t|  %c\t Nanti Main lagi Yak\t%c  |\n", simbol[2],simbol[3]);
    printf("\t\t\t\t\t|                                  |\n");
    printf("\t\t\t\t\t|__________________________________|\n");
}

void CetakSisa(int *sisakotak){
	printf(" Sisa Kotak : %d\n\n", *sisakotak);
}

void CetakPapan(char AngkaAwal[8][8], int Dimensi){

    if(Dimensi==1){
        printf("\n\t\t1\t\t2\t\t3\n");
	printf("\t-------------------------------------------------\n");
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf(" 1\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3]);
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf(" 2\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3]);
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf(" 3\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3]); 
	printf("\t|\t\t|\t\t|\t\t|\n");
	printf("\t-------------------------------------------------\n\n");
    }
    else if(Dimensi==2){
        printf("\n\t\t1\t\t2\t\t3\t\t4\t\t5\n\n");
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 1\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3],AngkaAwal[1][4],AngkaAwal[1][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 2\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3],AngkaAwal[2][4],AngkaAwal[2][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 3\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3],AngkaAwal[3][4],AngkaAwal[3][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 4\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[4][1],AngkaAwal[4][2],AngkaAwal[4][3],AngkaAwal[4][4],AngkaAwal[4][5]);
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 5\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[5][1],AngkaAwal[5][2],AngkaAwal[5][3],AngkaAwal[5][4],AngkaAwal[5][5]);
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("\t---------------------------------------------------------------------------------\n\n");
    }
    else if(Dimensi==3){
    printf("\n   \t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t7\n\n");
    printf("   --------------------------------------------------------------------------------------------------------------\n");
    printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 1 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3],AngkaAwal[1][4], AngkaAwal[1][5],AngkaAwal[1][6], AngkaAwal[1][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 2 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3],AngkaAwal[2][4], AngkaAwal[2][5], AngkaAwal[2][6], AngkaAwal[2][7]);
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
    printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 3 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3],AngkaAwal[3][4], AngkaAwal[3][5],AngkaAwal[3][6], AngkaAwal[3][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 4 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[4][1],AngkaAwal[4][2],AngkaAwal[4][3],AngkaAwal[4][4], AngkaAwal[4][5], AngkaAwal[4][6], AngkaAwal[4][7]);
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
 	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 5 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[5][1],AngkaAwal[5][2],AngkaAwal[5][3],AngkaAwal[5][4], AngkaAwal[5][5],AngkaAwal[5][6], AngkaAwal[5][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");	
    printf(" 6 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[6][1],AngkaAwal[6][2],AngkaAwal[6][3],AngkaAwal[6][4], AngkaAwal[6][5]), AngkaAwal[6][6], AngkaAwal[6][7];
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 7 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[7][1],AngkaAwal[7][2],AngkaAwal[7][3],AngkaAwal[7][4], AngkaAwal[7][5]), AngkaAwal[7][6], AngkaAwal[7][7];
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("   --------------------------------------------------------------------------------------------------------------\n\n");
    }
}

void HapusKotak(char AngkaAwal[8][8]){
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			AngkaAwal[i][j]=' ';
			}
		}
}

int KondisiWin(char AngkaAwal[8][8], int Dimensi)
{
    if(Dimensi == 1)        //kondisi win 3x3
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X'){                  //Kondisi Menang untuk Player 1
            return 1;
        } 
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][1]== 'X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
         }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O'){                  //Kondisi Menang untuk Player 2
             return 2;
        } 
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][1]== 'O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
         }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][1] == 'O'){
            return 2;
        }
        else{
            return 0;
        }
    }
    else if(Dimensi == 2)   //kondisi win 5x5
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4] == 'X'){                  //Kondisi Menang untuk Player 1
            return 1;
        } 
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4] == 'X'){                  
            return 1;
        } 
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4] == 'X' ){
             return 1;
        }
        else if(AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4] && AngkaAwal[2][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][1]== 'X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4] == 'X' && AngkaAwal[3][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[4][1]== 'X' && AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
         else if(AngkaAwal[5][1]== 'X' && AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4] == 'X' ){
             return 1;
        }
        else if(AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1] == 'X'){	//6
             return 1;
        }
        else if(AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1] == 'X' && AngkaAwal[5][1] == 'X'){	//6
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][2] == 'X'){
             return 1;
        }   
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4] == 'O'){      //kondisi menang player2            
            return 2;
        } 
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4] == 'O'){                  
            return 2;
        } 
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4] == 'O' ){
             return 2;
        }
        else if(AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4] && AngkaAwal[2][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][1]== 'O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4] == 'O' && AngkaAwal[3][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[4][1]== 'O' && AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
         else if(AngkaAwal[5][1]== 'O' && AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4] == 'O' ){
             return 2;
        }
        else if(AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1] == 'O'){	
             return 2;
        }
        else if(AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1] == 'O' && AngkaAwal[5][1] == 'O'){	
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][2] == 'O'){
             return 2;
        }
        else {
            return 0;
        }
    }
    else if(Dimensi == 3)   //kondisi win 7x7
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4]== 'X' && AngkaAwal[1][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        } 
	
	else if(AngkaAwal[1][2]=='X' && AngkaAwal[1][3]=='X' && AngkaAwal[1][4] == 'X' && AngkaAwal[1][5]== 'X' && AngkaAwal[1][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        } 
        
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[1][4]=='X' && AngkaAwal[1][5] == 'X' && AngkaAwal[1][6]== 'X' && AngkaAwal[1][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4]== 'X' && AngkaAwal[2][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[2][2]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[2][4] == 'X' && AngkaAwal[2][5]== 'X' && AngkaAwal[2][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[2][3]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[2][5] == 'X' && AngkaAwal[2][6]== 'X' && AngkaAwal[2][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4]== 'X' && AngkaAwal[3][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[3][2]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[3][5]== 'X' && AngkaAwal[3][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][3]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[3][6]== 'X' && AngkaAwal[3][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[4][1]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[4][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[4][2]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[4][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[4][3]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[4][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[5][1]=='X' && AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[5][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[5][2]=='X' && AngkaAwal[5][3]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[5][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[5][3]=='X' && AngkaAwal[5][4]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[5][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[6][1]=='X' && AngkaAwal[6][2]=='X' && AngkaAwal[6][3] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[6][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[6][2]=='X' && AngkaAwal[6][3]=='X' && AngkaAwal[6][4] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[6][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[6][3]=='X' && AngkaAwal[6][4]=='X' && AngkaAwal[6][5] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[6][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[7][1]=='X' && AngkaAwal[7][2]=='X' && AngkaAwal[7][3] == 'X' && AngkaAwal[7][4]== 'X' && AngkaAwal[7][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[7][2]=='X' && AngkaAwal[7][3]=='X' && AngkaAwal[7][4] == 'X' && AngkaAwal[7][5]== 'X' && AngkaAwal[7][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[7][3]=='X' && AngkaAwal[7][4]=='X' && AngkaAwal[7][5] == 'X' && AngkaAwal[7][6]== 'X' && AngkaAwal[7][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]=='X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1]== 'X' && AngkaAwal[5][1]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }

    else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][1]=='X' && AngkaAwal[4][1] == 'X' && AngkaAwal[5][1]== 'X' && AngkaAwal[6][1]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[4][1]=='X' && AngkaAwal[5][1] == 'X' && AngkaAwal[6][1]== 'X' && AngkaAwal[7][1]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2]== 'X' && AngkaAwal[5][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][2]== 'X' && AngkaAwal[6][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][2]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[5][2] == 'X' && AngkaAwal[6][2]== 'X' && AngkaAwal[7][2]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3]== 'X' && AngkaAwal[5][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][3]== 'X' && AngkaAwal[6][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][3]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][3]== 'X' && AngkaAwal[7][3]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][4]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][4]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][4]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][4]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[5][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][5]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[6][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][5]=='X' && AngkaAwal[4][5]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[7][5]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][6]=='X' && AngkaAwal[2][6]=='X' && AngkaAwal[3][6] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[5][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][6]=='X' && AngkaAwal[3][6]=='X' && AngkaAwal[4][6] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[6][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][6]=='X' && AngkaAwal[4][6]=='X' && AngkaAwal[5][6] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[7][6]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][7]=='X' && AngkaAwal[2][7]=='X' && AngkaAwal[3][7] == 'X' && AngkaAwal[4][7]== 'X' && AngkaAwal[5][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][7]=='X' && AngkaAwal[3][7]=='X' && AngkaAwal[4][7] == 'X' && AngkaAwal[5][7]== 'X' && AngkaAwal[6][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][7]=='X' && AngkaAwal[4][7]=='X' && AngkaAwal[5][7] == 'X' && AngkaAwal[6][7]== 'X' && AngkaAwal[7][7]== 'X'){                  
    	return 1;
        }
    
    else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2]== 'X' && AngkaAwal[5][1]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[1][6]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][3]== 'X' && AngkaAwal[5][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][2]== 'X' && AngkaAwal[6][1]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][7]=='X' && AngkaAwal[2][6]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][6]=='X' && AngkaAwal[3][5]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][3]== 'X' && AngkaAwal[6][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][5]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][2]== 'X' && AngkaAwal[7][1]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[2][7]=='X' && AngkaAwal[3][6]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][6]=='X' && AngkaAwal[4][5]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][3]== 'X' && AngkaAwal[7][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][7]=='X' && AngkaAwal[4][6]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][3]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[5][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[5][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[6][7]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[6][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][3]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[7][7]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][2]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[7][6]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][5]== 'X'){                  
    	return 1;
    	}
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4]== 'O' && AngkaAwal[1][5]== 'O'){    //Menang O              //Kondisi Menang untuk Player 1
    	return 2;
        } 
	
	else if(AngkaAwal[1][2]=='O' && AngkaAwal[1][3]=='O' && AngkaAwal[1][4] == 'O' && AngkaAwal[1][5]== 'O' && AngkaAwal[1][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        } 
        
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[1][4]=='O' && AngkaAwal[1][5] == 'O' && AngkaAwal[1][6]== 'O' && AngkaAwal[1][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4]== 'O' && AngkaAwal[2][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[2][2]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[2][4] == 'O' && AngkaAwal[2][5]== 'O' && AngkaAwal[2][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[2][3]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[2][5] == 'O' && AngkaAwal[2][6]== 'O' && AngkaAwal[2][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4]== 'O' && AngkaAwal[3][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[3][2]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[3][5]== 'O' && AngkaAwal[3][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][3]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[3][6]== 'O' && AngkaAwal[3][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[4][1]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[4][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[4][2]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[4][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[4][3]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[4][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[5][1]=='O' && AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[5][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[5][2]=='O' && AngkaAwal[5][3]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[5][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[5][3]=='O' && AngkaAwal[5][4]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[5][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[6][1]=='O' && AngkaAwal[6][2]=='O' && AngkaAwal[6][3] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[6][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[6][2]=='O' && AngkaAwal[6][3]=='O' && AngkaAwal[6][4] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[6][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[6][3]=='O' && AngkaAwal[6][4]=='O' && AngkaAwal[6][5] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[6][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[7][1]=='O' && AngkaAwal[7][2]=='O' && AngkaAwal[7][3] == 'O' && AngkaAwal[7][4]== 'O' && AngkaAwal[7][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[7][2]=='O' && AngkaAwal[7][3]=='O' && AngkaAwal[7][4] == 'O' && AngkaAwal[7][5]== 'O' && AngkaAwal[7][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[7][3]=='O' && AngkaAwal[7][4]=='O' && AngkaAwal[7][5] == 'O' && AngkaAwal[7][6]== 'O' && AngkaAwal[7][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]=='O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1]== 'O' && AngkaAwal[5][1]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }

    else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][1]=='O' && AngkaAwal[4][1] == 'O' && AngkaAwal[5][1]== 'O' && AngkaAwal[6][1]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[4][1]=='O' && AngkaAwal[5][1] == 'O' && AngkaAwal[6][1]== 'O' && AngkaAwal[7][1]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2]== 'O' && AngkaAwal[5][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][2]== 'O' && AngkaAwal[6][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][2]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[5][2] == 'O' && AngkaAwal[6][2]== 'O' && AngkaAwal[7][2]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3]== 'O' && AngkaAwal[5][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][3]== 'O' && AngkaAwal[6][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][3]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][3]== 'O' && AngkaAwal[7][3]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][4]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][4]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][4]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][4]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[5][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][5]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[6][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][5]=='O' && AngkaAwal[4][5]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[7][5]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][6]=='O' && AngkaAwal[2][6]=='O' && AngkaAwal[3][6] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[5][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][6]=='O' && AngkaAwal[3][6]=='O' && AngkaAwal[4][6] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[6][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][6]=='O' && AngkaAwal[4][6]=='O' && AngkaAwal[5][6] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[7][6]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][7]=='O' && AngkaAwal[2][7]=='O' && AngkaAwal[3][7] == 'O' && AngkaAwal[4][7]== 'O' && AngkaAwal[5][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][7]=='O' && AngkaAwal[3][7]=='O' && AngkaAwal[4][7] == 'O' && AngkaAwal[5][7]== 'O' && AngkaAwal[6][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][7]=='O' && AngkaAwal[4][7]=='O' && AngkaAwal[5][7] == 'O' && AngkaAwal[6][7]== 'O' && AngkaAwal[7][7]== 'O'){                  
    	return 2;
        }
    
    else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2]== 'O' && AngkaAwal[5][1]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[1][6]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][3]== 'O' && AngkaAwal[5][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][2]== 'O' && AngkaAwal[6][1]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][7]=='O' && AngkaAwal[2][6]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][6]=='O' && AngkaAwal[3][5]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][3]== 'O' && AngkaAwal[6][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][5]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][2]== 'O' && AngkaAwal[7][1]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[2][7]=='O' && AngkaAwal[3][6]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][6]=='O' && AngkaAwal[4][5]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][3]== 'O' && AngkaAwal[7][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][7]=='O' && AngkaAwal[4][6]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][3]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[5][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[5][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[6][7]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[6][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][3]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[7][7]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][2]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[7][6]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][5]== 'O'){                  
    	return 2;
    	}
    else {
        return 0;
        }
    }
}

void CekValid(){
    printf(" Invalid Move!!!\n");
}

void gotoxy(int x, int y)   //buat memanipulasi tampilan di layar monitor 
{                           //jdi nnti tulisan bisa di tengah langsung berdasarkan koordinatnya tanpa pke printf banyak
    COORD K;
    K.X = x;
    K.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),K);
}

void CetakLoading()
{
    int i,j;
    char AKI,Ver,BKI,Hor,BKA,AKA;
    // Kode ASCII untuk membentuk kotak loading
    AKI = 201;  //Atas Kiri
    Ver = 186;  //Vertikal
    BKI = 200;   //Bawah Kiri
    Hor = 205;  //Horizontal
    BKA = 188;  //Bawah Kanan
    AKA = 187;  //Atas Kanan
    system("color A");
    for ( i = 1; i < 5; i++)
    {
        for ( j = 1; j < 35; j++)
        {
            if (i == 1 && j == 1)
            {
                gotoxy(38,6);
                printf("%c",AKI);
            }
            if (i == 1 && j == 34)
            {
                gotoxy(71,6);
                printf("%c",AKA);
            }
            if (i == 3 && j == 1)
            {
                gotoxy(38,8);
                printf("%c",BKI);
            }
            if (i == 3 && j == 34)
            {
                gotoxy(71,8);
                printf("%c",BKA);
            }
            if (i == 1 || i == 3)
            {
                if (j > 1 && j < 34)
                {
                    printf("%c",Hor);
                }
            }
            if (j == 1 || j == 34)
            {
                if (i == 2 && j == 34)
                {
                    gotoxy(71,7);
                    printf("%c",Ver);
                }
                if (i == 2 && j == 1)
                {
                    gotoxy(38,7);
                    printf("%c",Ver);
                }
                
            }
            
        }
        
    }
    
    gotoxy(49,5);
    printf("Please Wait....\n");
    gotoxy(40,7);
    for ( i = 0; i < 30; i++)      //30 teh mau ada brp kotaknya
    {
        printf("%c",221);       //176 kode ascii simbol
        Sleep(50);
    }
    gotoxy(49,5);
    printf("KLIK ENTER ");
    getche();       //hrs enter dl biar ke next
}

void CetakAbout()
{
	gotoxy(75,7);
	printf("----------------------------------------------------------------------\n");
		gotoxy(75,7);
	printf("----------------------------------------------------------------------\n");
		gotoxy(75,7);
	printf("||\t\t\t\t\t\tABOUT\t\t\t\t\t||");
}
