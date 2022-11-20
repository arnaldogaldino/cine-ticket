#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

int Menu(char* items[], int qtd, int lin, int col) {
	int result = -1;
	int posicao = 0;
	int tecla = 0;
	
	while(result == -1) {
		int plin = lin;	
		int qlin = 0;

		do {
			if(posicao == qlin)
				SetConsoleTextAttribute(hstdout, cores[4]);
				
			Texto(items[qlin], plin, col);
			plin++;
			qlin++;
			SetConsoleTextAttribute(hstdout, csbi.wAttributes);
			FlushConsoleInputBuffer(hstdin);
		} while(qlin < qtd);
		
		tecla = _getch();
		fflush(stdin);
		
		if(tecla == 72 && posicao > 0)
			posicao--;
		else if (tecla == 80 && posicao < qlin-1)
			posicao++;	
		else if(tecla == 13) {
			result = posicao;	
		} else if(tecla == 27) {
			result = 999;
		} else if(tecla == 48 && qlin >= 0) {
			posicao = 0;
		} else if(tecla == 49 && qlin >= 1) {
			posicao = 1;
		} else if(tecla == 50 && qlin >= 2) {
			posicao = 2;
		} else if(tecla == 51 && qlin >= 3) {
			posicao = 3;
		} else if(tecla == 52 && qlin >= 4) {
			posicao = 4;
		} else if(tecla == 53 && qlin >= 5) {
			posicao = 5;
		} else if(tecla == 54 && qlin >= 6) {
			posicao = 6;
		} else if(tecla == 55 && qlin >= 7) {
			posicao = 7;
		} else if(tecla == 56 && qlin >= 8) {
			posicao = 8;
		} else if(tecla == 57 && qlin >= 9) {
			posicao = 9;
		}
	}
	
	return result;	
}
