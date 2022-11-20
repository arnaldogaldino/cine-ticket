#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

void CadSessao();
void PsqSessao();

void MenuSessao()
{
	int opcaoMenu = -1;
	
	char* menuSessao[3] = { " 0 - CONSULTAR SESSEOS    ",
		                    " 1 - CADASTRAR SESSOES    ",
		                    " 2 - VOLAR PARA O MENU    " };

	while(opcaoMenu >= -1 && opcaoMenu < 999) {
		LimparTela();
		Texto(" * * MENU DE CADASTRO DE SESSAO * * ", 5, 21);
		opcaoMenu = Menu(menuSessao, 3, 7, 26);
			
		switch(opcaoMenu)
		{
         	case 0:
            	opcaoMenu = -1;
            	PsqSessao();
            	break;
         	case 1:
            	opcaoMenu = -1;
            	CadSessao();
            	break;
         	case 2:
            	opcaoMenu = 999;
            	break;					            
         	default:
            	break;
		}
		
	}						  	
}

void CadSessao()
{
	LimparTela();
	Texto(" * * CADASTRO DE SESSAO * * ", 5, 26);

	Texto("TITULO DO FILME:", 7, 10);
	Texto("QTD DE POLTRONAS:", 8, 10);
	Texto("TEMA DO FILME:", 9, 10);
	Texto("HORARIO DA SESSAO:", 10, 10); Texto(":", 10, 31);		
	Texto("DIA DA SEMANA:", 11, 10);
	
	Sessao novo;
	
	do
	{
		strcpy(novo.titulo, Campo(novo.titulo, 7, 27, 20));
		
		if(strcmp(novo.titulo, "") == 0)
			Texto("CAMPO OBRIGATORIO", 7, 48);	
		else
			Texto("                  ", 7, 48);		
	} while (strcmp(novo.titulo, "") == 0);
	
	novo.qtdPoltronas = CampoNum(novo.qtdPoltronas, 8, 28, 2);
	
	do
	{
		Texto("ALERTA: 0=GERAL 1=DIR. HUMANOS 2=SUSTENTABILIDADE 3=REL. ETNICO-RACIAIS", 23, 2);
		novo.tema = CampoNum(novo.tema, 9, 25, 1);
		Texto("                                                                       ", 23, 2);
	} while (novo.tema <= -1 || novo.tema > 3);
		
	Texto(GetTema(novo.tema), 9, 27);
    
    do {
		novo.horario.hora = CampoNum(novo.horario.hora, 10, 29, 2);
	} while (novo.horario.hora <= -1 || novo.horario.hora > 23);
	
	do {
		novo.horario.min = CampoNum(novo.horario.min, 10, 32, 2);
	} while (novo.horario.min <= -1 || novo.horario.min > 59);
	Texto(GetHora(novo.horario), 10, 29);
	
	do {
		Texto("ALERTA: 1=SEG. 2=TER. 3=QUA. 4=QUI. 5=SEX. 6=SAB. 7=DOM", 23, 2);
		novo.dia = CampoNum(novo.dia, 11, 25, 1);
		Texto("                                                                       ", 23, 2);
	} while (novo.dia <= 0 || novo.dia > 7);
	
	Texto(GetDia(novo.dia), 11, 27);
	    
	Texto("ALERTA: CONFIRMA O CADASTRO DESTA SESSAO (S=SIM / N=NAO):", 23, 2);	
	char sn = 'S';
	sn = CampoSN(sn, 23, 59);
	Texto("                                                          ", 23, 2);	
	
	int i = 0;
	for(i == 0; i < 99; i++)
		novo.PontronasOcupadas[i] = 0;
		
	if(sn == 'S')
	{	
		AddSessao(novo);
	}
}

void ShowPoltronas(Sessao psq)
{

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	FlushConsoleInputBuffer(hstdin);

	Texto("POLTRONAS OCUPADAS:", 12, 2);

	int l, c, i = 0;
	for(l = 0; l < 9; l++)
	{
		for(c = 0; c < 10; c++)
		{
			char p[2] = { '0', '0' };
			itoa(i+1, p, 10);
			if(i < 9)
			{
				p[1] = p[0];
				p[0] = '0';
			}

			if(i < psq.qtdPoltronas) {
				Texto(p, 13+l, 19+(c*6));
				Texto("[ ]", 13+l, 19+(c*6)+2);
				
				if(psq.PontronasOcupadas[i] == 1) {
					SetConsoleTextAttribute(hstdout, cores[3]);	
					Texto("X", 13+l, 19+(c*6)+3);
					SetConsoleTextAttribute(hstdout, csbi.wAttributes);
					FlushConsoleInputBuffer(hstdin);
				}
			}
			i++;
		}
	}		
}

void PsqSessao()
{
	int numero = 0;
	Sessao psq;
	
	LimparTela();
	Texto("* * CONSULTAR DE SESSAO * *", 5, 26);
	
	Texto("TITULO DO FILME:", 7, 10);
	Texto("QTD DE POLTRONAS:", 8, 10); Texto("QTD DE POLTRONAS DISPONIVEIS:", 8, 31);
	Texto("TEMA DO FILME:", 9, 10);
	Texto("HORARIO DA SESSAO:", 10, 10); Texto(":", 10, 31);		
	Texto("DIA DA SEMANA:", 11, 10);
	
	Texto("ALERTA: INFORME O NUMERO DA SESSAO: ", 23, 2);
	numero = CampoNum(numero, 23, 38, 2);
	Texto("                                             ", 23, 2);

	psq = GetSessao(numero);
	SetConsoleTextAttribute(hstdout, cores[4]);	

	Texto(psq.titulo, 7, 27);
	TextoI(psq.qtdPoltronas, 8, 28);
	TextoI(psq.qtdPoltronas, 8, 61);
  	Texto(GetTema(psq.tema), 9, 25);
	Texto(GetHora(psq.horario), 10, 29);
	Texto(GetDia(psq.dia), 11, 25);

	ShowPoltronas(psq);
	
	Texto("ALERTA: VOLTAR PARA O MENU (S=SIM / N=NAO):", 23, 2);	
	char sn = 'S';
	sn = CampoSN(sn, 23, 46);
	Texto("                                                           ", 23, 2);	
	
	if(sn != 'S')
		PsqSessao();
}
