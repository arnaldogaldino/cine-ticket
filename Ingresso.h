#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

void LimparPsq()
{
	int i = 0;
	for(i = 0; i < 10; i++)
		Texto("                                                                             ", 12+i, 2);
}

int BuscaSessao(char* titulo, int qtd)
{
	LimparPsq();
	int encontrados = 0;
	
	int i = 0;
	for(i = 0; i < maxReg; i++)
	{
		if(strcmp(Sessoes[i].titulo, titulo) == 0)
		{
			fflush(stdin);
			char* num;
			num = GetNum(i+1);
			
			Texto(num, 12+encontrados, 2);
			//Texto(Sessoes[i].titulo, 12+encontrados, 5);
			//Texto(GetHora(Sessoes[i].horario), 12+encontrados, 36);	
			//Texto(GetDia(Sessoes[i].dia), 12+encontrados, 42);
			//Texto(GetTema(Sessoes[i].tema), 12+encontrados, 47);

			encontrados++;
			if(encontrados > qtd)
				break;
		}
		
		if(strcmp(Sessoes[i].titulo, "") == 0)
			break;
	}
	
	return encontrados;
}

void VendaIngresso()
{
	LimparTela();
	Texto("* * VENDA DE INGRESSO * *", 5, 26);
	int sessao = 0;
	
	int valor = 0;
	int pago = 0;
	int troco = 0;
	
	Ingresso novo;
	
	Texto("FILME:", 7, 10);
	Texto("SESSAO:", 8, 10);
	Texto("POLTRONA:", 9, 10);	
	Texto("TIPO:", 10, 10);
	Texto("VALOR R$:", 11, 10);
	Texto("PAGO R$:", 11, 32); 
	Texto("TROCO R$:", 11, 52);
	int encontrados = 0;
	
	do
	{
		strcpy(novo.filme, Campo(novo.filme, 7, 17, 40));
		encontrados = BuscaSessao(novo.filme, 10);		
	} while ((strcmp(novo.filme, "") == 0) && encontrados > 0);
	
	do
	{
		sessao = CampoNum(sessao, 8, 18, 2);	
	} while(strcmp(Sessoes[sessao-1].titulo, "") == 0);
	
	LimparPsq();
	ShowPoltronas(Sessoes[sessao-1]);
	
	novo.poltrona = CampoNum(novo.poltrona, 9, 20, 2);
	novo.tipo = CampoNum(novo.tipo, 10, 16, 1);
	
	valor = CampoNum(valor, 11, 20, 10);
	pago = CampoNum(pago, 11, 41, 10);
	
	troco = pago - valor;	
	troco = CampoNum(troco, 11, 62, 10);
	
	novo.valor = novo.valor/100;
	novo.pago = novo.pago/100;
	novo.troco = novo.troco/100;
}
