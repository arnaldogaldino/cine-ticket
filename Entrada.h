#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

Usuario TelaEntrada()
{
	LimparTela();
	Usuario usuario;

	Texto("* * LOGIN * *", 5, 28);
	
	Texto("USUARIO:", 10, 20);
	Texto("SENHA:", 11, 20);
	
	strcpy(usuario.login , Campo(usuario.login, 10, 29, 10)); 		
	strcpy(usuario.senha, CampoSenha(usuario.senha, 11, 27, 10));
	usuario.tipo = 0;

	if(strcmp(usuario.login, "A") == 0 && strcmp(usuario.senha, "A") == 0)
		usuario.tipo = 1;
	else 
	{
		usuario = GetUsuario(&usuario);
	
		if(usuario.tipo == 0)
		{
			Texto("ERRO: USUARIO OU SENHA INVALIDA", 23, 2);	
			getch();
			Texto("                               ", 23, 2);
			return TelaEntrada();	
		}
	}
	return usuario;
}
