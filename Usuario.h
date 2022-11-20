#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

void TelaCadUsuario()
{
	Usuario novo;

	LimparTela();		
	Texto(" * * CADASTRO DE USUARIO * * ", 5, 24);

	Texto("USUARIO:", 7, 10);
	Texto("SENHA:", 8, 10);
	Texto("TIPO DE USUARIO:", 9, 10);
			
	do{
		strcpy(novo.login, Campo(novo.login, 7, 19, 10));
				
		if(strcmp(novo.login, "") == 0)
			Texto("CAMPO OBRIGATORIO", 7, 30);	
		else
			Texto("                  ", 7, 30);			
	} while (strcmp(novo.login, "") == 0);

	do{
		strcpy(novo.senha, CampoSenha(novo.senha, 8, 17, 10));
				
		if(strcmp(novo.senha, "") == 0)
			Texto("CAMPO OBRIGATORIO", 8, 28);	
		else 	
			Texto("                  ", 8, 28);	
	} while (strcmp(novo.senha, "") == 0);
	
	do
	{
		Texto("ALERTA: 1=ADMINISTRADOR 2=VENDEDOR", 23, 2);
		novo.tipo = CampoNum(novo.tipo, 9, 27, 1);	
		Texto("                                   ", 23, 2);	
	} while (novo.tipo <= 0 || novo.tipo > 2);
			
	switch(novo.tipo) // 1=ADMINISTRADOR 2=VENDEDOR
	{
	    case 1:
	    	Texto("ADMINISTRADOR", 9, 29);
	    	break;
	    case 2:
	    	Texto("VENDEDOR", 9, 29);
	    	break;	
    }
	
	if(ExistsUsuario(novo.login) == 1) {
		Texto("ALERTA: USUARIO JA CADASTRADO", 23, 2);	
		getch();
		Texto("                             ", 23, 2);	
	} 
	else 
	{
		Texto("ALERTA: CONFIRMA O CADASTRO DESTE USUARIO (S=SIM / N=NAO):", 23, 2);	
		char sn = 'N';
		sn = CampoSN(sn, 23, 60);
		Texto("                                                           ", 23, 2);	
		
		if(sn == 'S')
		{
			AddUsuario(novo);
		}
	}
}
