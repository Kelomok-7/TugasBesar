#include <stdio.h>

int cek_vokal(char kalimat[]);
int cek_konsonan(char kalimat[]);

int main(){
    char kalimat[50];
    int vokal, konsonan;

    scanf("%[^\n]", kalimat);
    vokal=cek_vokal(kalimat);
    
}