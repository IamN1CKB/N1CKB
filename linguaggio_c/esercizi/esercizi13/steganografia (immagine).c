#include <stdio.h>
#include <math.h>
#define FREQ 32
/*
I file immagine2.bmp contiene dei caratteri nascosti nei pixel dell'immagine.
In particolare  dopo il 54-esimo byte è stato cambiato un bit ogni 32.
Per recuperare il testo occorre leggere 32 byte alla volta e prelevare solo l'ultimo bit.
Ogni 8 bit (dal meno significativo al più significativo) si recupera un carattere.
Il carattere corrispondente a tutti 0 indica il termine della stringa
*/

int main(){
 	FILE * fp;
 	char buf[64];
 	int i = 0;
 	unsigned char c = 0;
 	int endString = 0;
 	fp = fopen("immagine2.bmp","r");
 	if(fp!=NULL) {
		fseek(fp,54,0);
		while( (!feof(fp)) && !endString) {
			fread(buf,1,FREQ,fp);
			//printf("before:%x\n",(unsigned char)buf[63]%2);
			c += ((unsigned char)buf[FREQ-1])%2*128;
			i=(i+1)%8;
			//printf("after:%x\n",c);
			if(i==0) {
			    if (c==0) endString = 1;
				else {
					printf("%c",c);
					c=0;
				}
			}
			else c=c/2;
		}
 	    fclose(fp);
 	}
}