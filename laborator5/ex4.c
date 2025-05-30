/* Scrieți un program care copiază conținutul unui fișier sursă într-un fișier destinație.
Numele fișierelor se citesc din linia de comandă.
Pentru eficiența copierii, programul va citi câte un bloc de maxim 4096 de octeți, pe care îl va scrie în destinație.
Exemplu: ./copiere src.dat dst.dat -> copiază src.dat în dst.dat
*/

#include<stdio.h>
#include<stdlib.h>

#define BUF_SIZE 4096

int main(int argc,char *argv[]){
    if(argc!=3){
        fprintf(stderr,"Utilizare: %s <fisier_sursa> <fisier_destinatie>\n",argv[0]);
        return 1;
    }
    FILE *src=fopen(argv[1],"rb");
    if(!src){
        perror("Eroare la deschiderea fisierului");
        return 1;
    }
    FILE *dst=fopen(argv[2],"wb");
    if(!dst)
    {
        perror("Eroare la deschiderea fisierului destinatie");
        return 1;
    }
    char buffer[BUF_SIZE];
    size_t bytes;

    while((bytes=fread(buffer,1,BUF_SIZE,src))>0){
        fwrite(buffer,1,bytes,dst);
    }
    fclose(src);
    fclose(dst);

    printf("Fisierul a fost copiat cu succes.\n");
    return 0;
}
