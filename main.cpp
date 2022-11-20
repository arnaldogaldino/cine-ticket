#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

#include "ScreenFuncs.h"
#include "BD.h"
#include "Cliente.h"
#include "Entrada.h"
#include "Menu.h"
#include "Sessao.h"
#include "Ingresso.h"
#include "Usuario.h"

void TelaPrincipal();

using namespace std;
	
Usuario usuarioLogin;

int main()
{
	// Cores da Tela
	system("color 71");
	system("cls");

	usuarioLogin.tipo = 0;
	
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	
	DrawDoubleLine(0, 0, 24, 79);
	DrawLine(1, 6, 3, 72);
	DrawDoubleLine(22, 0, 22, 79);
	PosicaoXY(22, 0);
	cout << char(204); 
	PosicaoXY(22, 79);
	cout << char(185); 
	
	Texto("* * SVECP - SISTEMA PARA VENDA DE INGRESSO DE CINEMA DO PIM * *", 2, 8);
	
	LerArquivo();	
	
	usuarioLogin = TelaEntrada();
	TelaPrincipal();
	return 0;
}

void TelaPrincipal() {
	int opcaoMenu = -1;
	char* menu[6] = { " 0 - VENDA DE INGRESSOS   ",
		              " 1 - CADASTRO DE SESSOES  ",
		              " 2 - CADASTRO DE USUARIOS ",
		              " 3 - RELATORIO FECHAMENTO ",
		              " 4 - LOGOUT               ",
					  " 5 - SAIR                 " };
					  
char* menuUser[3] = { " 0 - VENDA DE INGRESSOS   ",
		              " 1 - LOGOUT               ",
					  " 2 - SAIR                 " };
					  					  
	if(usuarioLogin.tipo == 1 || usuarioLogin.tipo == 2)
	{
		while(opcaoMenu >= -1 && opcaoMenu < 999) {
			LimparTela();
			Texto("* * MENU PRINCIPAL * *", 5, 28);
			
			if(usuarioLogin.tipo == 1)
			{
				opcaoMenu = Menu(menu, 6, 7, 26);
				
				switch(opcaoMenu)
				{
			         case 0:
			            opcaoMenu = -1;
			            VendaIngresso();
			            break;
			         case 1:
			            opcaoMenu = -1;
			            MenuSessao();
			            break;
			         case 2:
			            opcaoMenu = -1;
			            TelaCadUsuario();
			            break;	
			         case 4:
       					opcaoMenu = main();
       					opcaoMenu = -1;
			            break;	
			         case 5:
			         	GravarArquivo();
			            opcaoMenu = 999;
			            break;										            
			         default:
			         	exit(0);
			            break;
				}
			}
			else if(usuarioLogin.tipo == 2)
			{
				opcaoMenu = Menu(menuUser, 3, 7, 26);

				switch(opcaoMenu)
				{
			        case 0:
			        	opcaoMenu = -1;
			        	VendaIngresso();
			        	break;
			        case 1:
			        	opcaoMenu = main();	
			            opcaoMenu = -1;
			            break;	
			        case 2:
			        	GravarArquivo();
			            opcaoMenu = 999;
			            break;
			        default:
			        	exit(0);
			            break;
				}								
			}				
		}
	}
	
	PosicaoXY(0, 0);
}
