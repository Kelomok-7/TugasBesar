#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tictactoe.h"


int main()
{
    int sisakotak;
    int  counter, Giliran, Win, AfterGame;
    
    int AwalGame=00;

    while(AwalGame==00){
    system("color A");

    DrawJudul();
    scanf("%d",&AwalGame);
    system("cls");

    switch (AwalGame)
    {

    case 1: 
        printf("\n \t\t\tMasukkan Nama Pemain: \n");
        printf("\t\t\t--------------------\n");
        printf(" Player 1 (X): "); 
        gets(Player1.Nama); //Memakai Gets supaya input nama dengan spasi terbaca
        gets(Player1.Nama);
        printf(" Player 2 (O): "); 
        gets(Player2.Nama);

        printf("\nPilih Dimensi Board Yang Akan Anda Mainkan: \n");
        while(AwalGame==1){
        CetakDimensi();
        printf("\t\t\t-----------------\n");
        scanf("%d",&Board.Dimensi);
        system("cls");
        switch(Board.Dimensi){
            case 1 : HapusKotak(Board.AngkaAwal);
                    CetakPapan(Board.AngkaAwal,Board.Dimensi);
                    sisakotak=9;
                    CetakSisa(&sisakotak);
                    for(Giliran=1; Giliran<10; Giliran++){
                    Win=0;                                      //Win=0, untuk kondisi awal, jika tidak berubah maka draw
                    if(Giliran%2==1){
                        sisakotak--;
                        printf(" %s Turn",Player1.Nama);
                        counter=0;                              //Counter untuk menghentikan while
                        while(counter==0){
                            printf("\n Input Kotak [Baris],[Kolom]: ");
                            InputKotak(&Input);
                            system("cls");
                            CekValid(&Input,sisakotak,counter);
                        }
                        Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                        if(Win==1){
                            CetakMenang(&Player1.Nama);
                        }
                    }
                    else{   
                            printf(" %s Turn",Player2.Nama);
                            sisakotak--;
                            counter=0;
                            while(counter==0){
                            printf("\n Input Kotak [Baris],[Kolom]: ");
                            InputKotak(&Input);
                            system("cls");
                            CekValid(&Input,sisakotak,counter);
                        }
                        Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                        if(Win==2){
                            CetakMenang(&Player2.Nama);
                            system("cls");
                        }
                        }
                        if(Win != 0){               //Jika variabel win berubah, maka loop akan lgsg berhenti, break
                        break;
                        }
                        } 
                        if(Win==0){
                        printf("\n Draw.");      //Jika variabel win tetap 0 seperti diawal, maka akan terjadi draw
                        }
                        HapusKotak(Board.AngkaAwal);
                        break;

            case 2:  HapusKotak(Board.AngkaAwal);
                    CetakPapan(Board.AngkaAwal,Board.Dimensi);
                    sisakotak=25;
                    for(Giliran=1; Giliran<26; Giliran++){
                    Win=0;                                      //Win=0, untuk kondisi awal, jika tidak berubah maka draw
                    if(Giliran%2==1){
                        printf(" %s Turn\n",Player1.Nama);
                        sisakotak--;
                        counter=0;                              //Counter untuk menghentikan while
                        while(counter==0){
                            printf("\n Input Kotak [Baris],[Kolom]: ");
                            InputKotak(&Input);
                            system("cls");
                            CekValid(&Input,sisakotak,counter);
                        }
                        Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                        if(Win==1){
                            CetakMenang(&Player1.Nama);
                        }
                    }
                    else{
                            printf(" %s Turn",Player2.Nama);
                            sisakotak--;
                            counter=0;
                            while(counter==0){
                            printf("\n Input Kotak [Baris],[Kolom]: ");
                            InputKotak(&Input);
                            system("cls");
                            CekValid(&Input,sisakotak,counter);
                        }
                        Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                        if(Win==2){
                            CetakMenang(&Player2.Nama);
                            
                        }
                        }
                        if(Win != 0){               //Jika variabel win berubah, maka loop akan lgsg berhenti, break
                        break;
                        }
                        } 
                        if(Win==0){
                        printf("\n Draw.");      //Jika variabel win tetap 0 seperti diawal, maka akan terjadi draw
                        }
                        HapusKotak(Board.AngkaAwal);
                        break;
                
                case 3: HapusKotak(Board.AngkaAwal);
                        CetakPapan(Board.AngkaAwal,Board.Dimensi);
                        sisakotak=49;  
                        for(Giliran=1; Giliran<50; Giliran++){
                        Win=0;                                      //Win=0, untuk kondisi awal, jika tidak berubah maka draw
                        if(Giliran%2==1){
                            printf(" %s Turn\n",Player1.Nama);
                            sisakotak--;
                            counter=0;                              //Counter untuk menghentikan while
                            while(counter==0){
                                printf("\n Input Kotak [Baris],[Kolom]: ");
                                InputKotak(&Input);
                                system("cls");
                                CekValid(&Input,sisakotak,counter);
                            }
                            Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                            if(Win==1){
                                CetakMenang(&Player1.Nama);
                            }
                        }
                        else{
                            printf(" %s Turn",Player2.Nama);
                            sisakotak--;
                            counter=0;
                            while(counter==0){
                                printf("\n Input Kotak [Baris],[Kolom]: ");
                                InputKotak(&Input);
                                system("cls");
                                CekValid(&Input,sisakotak,counter);
                            }
                                Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                                if(Win==2){
                                    CetakMenang(&Player2.Nama);
                                }
                            }
                            if(Win != 0){               //Jika variabel win berubah, maka loop akan lgsg berhenti, break
                            break;
                            }
                            } 
                            if(Win==0){
                                printf("\n Draw.");      //Jika variabel win tetap 0 seperti diawal, maka akan terjadi draw
                            }
                            HapusKotak(Board.AngkaAwal);
                            break;
							}
							printf("\n\nMain Lagi yes(1)/no(2)?\n Masukkan Angka : ");
							scanf("%d", &AfterGame);
							system("cls");
							if(AfterGame==1){
                                AwalGame=1;
                            }
							else if(AfterGame==2){
								AwalGame=00;
							}
                            
						}break;
							

    case 2: 

        CetakIntruksi();
        scanf("%d", &AwalGame);
        system("cls");
        break;
        

    case 3: 
        
        CetakQuit();
        return 0;
        break;

    default: 
        AwalGame=00;
        break;
    }

    }
   

return 0;
}

