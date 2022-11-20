#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>
#include <cstring>
#include <ctype.h>
#include <string.h>

using namespace std;

HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
CONSOLE_SCREEN_BUFFER_INFO csbi;

const WORD cores[] = { 0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		               0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6 };

char CampoSN(char val, int lin, int col);

void PosicaoXY(int linha, int coluna) {
	COORD posicao;
	posicao.X = coluna;
	posicao.Y = linha;
	SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		posicao
	);
}

void DrawLine(int ilin, int icol, int flin, int fcol) {
	int plin = 0;
	int pcol = 0;

	for(plin = ilin; plin <= flin; plin++) {		
		for(pcol = icol; pcol <= fcol; pcol++) {			
			if(pcol == icol || pcol == fcol) {	
				PosicaoXY(plin, pcol);
				cout << char(179);
			}			
			if(plin == ilin || plin == flin) {
				PosicaoXY(plin, pcol);
				cout << char(196);
			}			
			if(plin == ilin && pcol == icol) {
				PosicaoXY(plin, pcol);
				cout << char(218); 
			}
			if(plin == ilin && pcol == fcol) {
				PosicaoXY(plin, pcol);
				cout << char(191); 
			}
			if(plin == flin && pcol == fcol) {
				PosicaoXY(plin, pcol);
				cout << char(217); 
			} 			
			if(plin == flin && pcol == icol) {
				PosicaoXY(plin, pcol);
				cout << char(192); 
			}
		}
	}
}

void DrawDoubleLine(int ilin, int icol, int flin, int fcol) {
	int plin = 0;
	int pcol = 0;

	for(plin = ilin; plin <= flin; plin++) {		
		for(pcol = icol; pcol <= fcol; pcol++) {			
			if(pcol == icol || pcol == fcol) {	
				PosicaoXY(plin, pcol);
				cout << char(186); 
			}
			if(plin == ilin || plin == flin) {
				PosicaoXY(plin, pcol);
				cout << char(205); 
			}
			if(plin == ilin && pcol == icol) {
				PosicaoXY(plin, pcol);
				cout << char(201); 
			}
			if(plin == ilin && pcol == fcol) {
				PosicaoXY(plin, pcol);
				cout << char(187); 
			}
			if(plin == flin && pcol == fcol) {
				PosicaoXY(plin, pcol);
				cout << char(188); 
			}
			if(plin == flin && pcol == icol) {
				PosicaoXY(plin, pcol);
				cout << char(200); 
			}
		}
	}
}

void Texto(char texto[], int lin, int col) {
	PosicaoXY(lin, col);
	cout << texto;
}


void TextoI(int val, int lin, int col) {
	PosicaoXY(lin, col);
	cout << val;
}


void LimparTela() {
	int plin = 0;
	int pcol = 0;
	
	int ilin = 4;
	int icol = 1;
	int flin = 21;
	int fcol = 78;
	
	for(plin = ilin; plin <= flin; plin++) {		
		for(pcol = icol; pcol <= fcol; pcol++) {
			PosicaoXY(plin, pcol);
			cout << " "; 
		}
	}
}

char* Campo(char val[], int lin, int col, int tam) {
	char result[tam] = "";
	int count = 0;
	PosicaoXY(lin, col);	
    
	SetConsoleTextAttribute(hstdout, cores[4]);	
	
	do {
		PosicaoXY(lin, col+count);
		cout << " ";
		count++;
	} while(count < tam);
    
	int tecla = 0;
	count = 0;	
	Texto(val, lin, col);
	PosicaoXY(lin, col);
	
 	do {
 		PosicaoXY(lin, col+count);
        tecla = getch();
        fflush(stdin);
        
       if(count <= (tam-1))
       {
	       	if(tecla!=13 && tecla!=8 && ((tecla >=65 && tecla <=90) || (tecla>=97 && tecla<=122) || (tecla >= 48 && tecla <= 57) || (tecla==32))) {
				result[count] = toupper(char(tecla));
				cout << result[count];
				count++;
	       	} else if(tecla==8) {
		      	if(count > 0)
	            	count--;               
		        PosicaoXY(lin, col+count);          
		        cout << " ";         
	       	}
		   	/*else if(tecla==27)
			{
				Texto("ALERTA: VOLTAR PARA O MENU (S=SIM / N=NAO):", 23, 2);	
				char sn = 'N';
				sn = CampoSN(sn, 23, 46);
				Texto("                                                           ", 23, 2);	
				
				if(sn == 'S') {
				 	TelaPrincipal();
					return result;
				}
			}*/
		} else if(tecla!=13 && tecla==8) {
				if(count > 0)
					count--;

				PosicaoXY(lin, col+count);
				cout << " ";
		}
	} while(tecla!=13);
	
	if(count < tam)
    	result[count] = '\0';
    
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	FlushConsoleInputBuffer(hstdin);

	return result;
}

int CampoNum(int val, int lin, int col, int tam) {
	char result[tam];
	itoa(val, result, 10);
		
	int count = 0;
	PosicaoXY(lin, col);
    
	SetConsoleTextAttribute(hstdout, cores[4]);	
	
	do {
		PosicaoXY(lin, col+count);
		cout << " ";
		count++;
	} while(count < tam);
	
	char tecla;
	count = 0;
	Texto(result, lin, col);
	PosicaoXY(lin, col);
	
 	do {
 	   PosicaoXY(lin, col+count);
       tecla = getch();
       fflush(stdin);
       if(count < tam) {
	       	if(tecla!=13 && tecla!=8 && (tecla >= 48 && tecla <= 57)) {
				result[count] = tecla;
				cout << result[count];
				count++;
	       	} else if(tecla==8) {
		      	if(count > 0)
	            	count--;               
		        PosicaoXY(lin, col+count);          
		        cout << " ";         
	       }
		} else if(tecla!=13 && tecla==8) {
				if(count > 0)
					count--;

				PosicaoXY(lin, col+count);
				cout << " ";
		}	   
	} while(tecla!=13);

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	FlushConsoleInputBuffer(hstdin);

	return atoi(result);
}

char CampoSN(char val, int lin, int col) {
	int tam = 1;
	char result = val;
	int count = 0;
	PosicaoXY(lin, col);	
    
	SetConsoleTextAttribute(hstdout, cores[4]);	
	
	do {
		PosicaoXY(lin, col+count);
		cout << " ";
		count++;
	} while(count < tam);
	
	char tecla;
	count = 0;

	PosicaoXY(lin, col);
	
 	do {
 		PosicaoXY(lin, col);
        tecla = getch();
       	fflush(stdin);
       	if(count <= (tam-1)) {
	       	if(tecla!=13 && tecla!=8) {
	       		if(tecla == 115 || tecla == 83)
					result = 'S';
				if(tecla == 110 || tecla == 78) 
					result = 'N';	

				cout << result;
	       	} else if(tecla==8) {
		      	if(count > 0)
	            	count--;               
		        PosicaoXY(lin, col+count);          
		        cout << " ";         
	       }  
		} else if(tecla!=13 && tecla==8) {
				if(count > 0)
					count--;

				PosicaoXY(lin, col+count);
				cout << " ";
		}	   
	} while(tecla!=13);

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	FlushConsoleInputBuffer(hstdin);

	return result;
}

typedef struct
{
	int dia, mes, ano;
} Data;

typedef struct
{
	int hora = 0, min = 0;
} Hora;

Data CampoData(Data val, int lin, int col)
{
	Data result;
	Texto("  /  /    ", lin, col);
	TextoI(val.dia, lin, col);
	TextoI(val.mes, lin, col+3);
	TextoI(val.ano, lin, col+6);

	do {
		result.dia = CampoNum(val.dia, lin, col, 2);
	} while(!(result.dia > 0 && result.dia <= 31));
	
	do {
		result.mes = CampoNum(val.mes, lin, col+3, 2);
	} while(!(result.mes > 0 && result.mes <= 12));
	
	do {
		result.ano = CampoNum(val.ano, lin, col+6, 4);
	} while(!(result.ano >= 1900 && result.ano < 2017));
	
	return result;
}

char* CampoSenha(char val[], int lin, int col, int tam) {
	char result[tam-1];
	int count = 0;
	PosicaoXY(lin, col);	
    
	SetConsoleTextAttribute(hstdout, cores[4]);	
	strcpy(result, val);
	
	do {
		PosicaoXY(lin, col+count);
		cout << " ";
		count++;
	} while(count < tam);
	
	char tecla;
	count = 0;
	
	PosicaoXY(lin, col);
	
 	do {
 		PosicaoXY(lin, col+count);
        tecla = getch();
       	fflush(stdin);
       	if(count <= (tam-1))
       	{
	       	if(tecla!=13 && tecla!=8 && ((tecla >=65 && tecla <=90) || (tecla>=97 && tecla<=122) || (tecla >= 48 && tecla <= 57))) {
				result[count] = toupper(tecla);
				cout << "*";
				count++;
	       	} else if(tecla==8) {
		      	if(count > 0)
	            	count--;               
		        PosicaoXY(lin, col+count);          
		        cout << " ";    
	       }  
		} else if(tecla!=13 && tecla==8) {
				if(count > 0)
					count--;

				PosicaoXY(lin, col+count);
				cout << " ";
		}	   
	} while(tecla!=13);
	
	if(count < tam)
    	result[count] = '\0';
    	
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	FlushConsoleInputBuffer(hstdin);
	
	PosicaoXY(lin, col);
	return result;
}

char* GetTema(int tema) {
	char* result;
	
	switch(tema) // 0=GERAL 1=DIR. HUMANOS 2=SUSTENTABILIDADE 3=REL. ETNICO-RACIAIS
	{
	    case 0:
	    	return "GERAL";
	    	break;
	    case 1:
	    	return "DIR. HUMANOS";
	    	break;	
	    case 2:
	    	return "SUSTENTABILIDADE";
	    	break;	
	    case 3:
	    	return "REL. ETNICO-RACIAIS";
	    	break;					   	
    }
    
    return result;
}

char* GetDia(int dia)
{
	char* result;
	switch(dia) //  1=SEG. 2=TER. 3=QUA. 4=QUI. 5=SEX. 6=SAB. 7=DOM
	{
	    case 1:
	    	return "SEG.";
	    	break;
	    case 2:
	    	return "TER.";
	    	break;
	    case 3:
	    	return "QUA.";
	    	break;
	    case 4:
	    	return "QUI.";
	    	break;
	    case 5:
	    	return "SEX.";
	    	break;
	    case 6:
	    	return "SAB.";
	    	break;
	    case 7:
	    	return "DOM.";
	    	break;							   	
    }
    return result;
}

char* GetNum(int num)
{
	char p[2] = { '0', '0' };
	
	itoa(num, p, 10);	
	if(num <= 9)
	{
		p[1] = p[0];
		p[0] = '0';
	}
	
	return p;		
}

char* GetHora(Hora hotario)
{
	char x[5] = { '0', '0', ':', '0', '0' };
	
	char h[2] = { '0', '0' };
	char m[2] = { '0', '0' };
	
	itoa(hotario.hora, h, 10);
	itoa(hotario.min, m, 10);
	
	if(hotario.hora <= 9)
	{
		h[1] = h[0];
		h[0] = '0';
	}
	
	if(hotario.min <= 9)
	{
		m[1] = m[0];
		m[0] = '0';
	}

	x[0] = h[0];
	x[1] = h[1];
	x[3] = m[0];
	x[4] = m[1];
	
	return x;
}
