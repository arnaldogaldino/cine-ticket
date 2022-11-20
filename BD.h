#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

#define maxReg 1000

struct Usuario
{
    char login[10] = "";
    char senha[10] = "";
    int tipo = 0;
} typedef Usuario;

struct Sessao
{
	char titulo[30] = "";
	int tema = 0;
	int qtdPoltronas = 0;
	int PontronasOcupadas[99];
	Hora horario;
	int dia = 0;
} typedef Sessao;

struct Ingresso
{
	char filme[40] = "";
    Sessao sessao;
    int poltrona = 0;
    int tipo = 0;
    float valor = 0;
    float pago = 0;
    float troco = 0;
} typedef Ingresso;

struct Usuario Usuarios[maxReg];
struct Sessao Sessoes[maxReg];
struct Ingresso Ingressos[maxReg];

void LerArquivo() {
	int i = 0;
	FILE *arquivoUsuario = fopen("usuario.dat", "rb");
	if(arquivoUsuario == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO USUARIO.DAT", 23, 2);	
		getch();
		Texto("                                                  ", 23, 2);	
    } else {
    	Usuario u;
		while(fread(&u, sizeof(Usuario), 1, arquivoUsuario)) {
			Usuarios[i] = u;
			i++;
		}
	}
	fclose(arquivoUsuario);

	i = 0;
	FILE *arquivoSessao = fopen("sessao.dat", "rb");
	if(arquivoSessao == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO SESSAO.DAT", 23, 2);	
		getch();
		Texto("                                                  ", 23, 2);	
    } else {
    	Sessao sessao;
		while(fread(&sessao, sizeof(Sessao), 1, arquivoSessao)) {
			Sessoes[i] = sessao;
			i++;
		}
	}
	fclose(arquivoSessao);
		
	i = 0;
	FILE *arquivoIngresso = fopen("ingresso.dat", "rb");
	if(arquivoSessao == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO INGRESSO.DAT", 23, 2);	
		getch();
		Texto("                                                   ", 23, 2);	
    } else {
    	Ingresso ingresso;
		while(fread(&ingresso, sizeof(Ingresso), 1, arquivoIngresso)) {
			Ingressos[i] = ingresso;
			i++;
		}
	}
	fclose(arquivoIngresso);
}

void GravarArquivo()
{
	int i = 0;
	FILE *arquivoUsuario = fopen("usuario.dat", "wb");
	if(arquivoUsuario == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO USUARIO.DAT", 23, 2);	
		getch();
		Texto("                                                  ", 23, 2);	
    } else {
    	for(i = 0; i <= maxReg; i++) {
    		 fwrite(&Usuarios[i], sizeof(Usuario), 1, arquivoUsuario);
		}
	}
	fclose(arquivoUsuario);
	
	i = 0;
	FILE *arquivoSessao = fopen("sessao.dat", "wb");
	if(arquivoSessao == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO SESSAO.DAT", 23, 2);	
		getch();
		Texto("                                                  ", 23, 2);	
    } else {
    	for(i = 0; i <= maxReg; i++) {
    		 fwrite(&Sessoes[i], sizeof(Sessao), 1, arquivoSessao);
		}
	}
	fclose(arquivoSessao);
	
	i = 0;
	FILE *arquivoIngresso = fopen("ingresso.dat", "wb");
	if(arquivoIngresso == NULL) {
		Texto("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO INGRESSO.DAT", 23, 2);	
		getch();
		Texto("                                                   ", 23, 2);	
    } else {
    	for(i = 0; i <= maxReg; i++) {
    		 fwrite(&Ingressos[i], sizeof(Ingresso), 1, arquivoIngresso);
		}
	}
	fclose(arquivoIngresso);
}

int ExistsUsuario(char login[10]) {
	int i = 0;

	for(i = 0; i < maxReg; i++) {
		if(strcmp(login, Usuarios[i].login) == 0)
			return 1;
	}
	
	return 0;
}

Usuario GetUsuario(Usuario* usuario) {
	Usuario result;
	
	int i = 0;
	for(i = 0; i < maxReg; i++) {
		if(strcmp(usuario->login, Usuarios[i].login) == 0 && strcmp(usuario->senha, Usuarios[i].senha) == 0)
		{
			result = Usuarios[i];
			break;
		}
	}
	
	return result;
}

void AddUsuario(Usuario usuario) {
	int i = 0;

	for(i = 0; i <= maxReg; i++) {
		if(strcmp(Usuarios[i].login, "") == 0) {
			if(ExistsUsuario(usuario.login) == 0) {
				Usuarios[i] = usuario;
				break;
			} else {
				Texto("ALERTA: USUARIO JA CADASTRADO", 23, 2);	
				getch();
				Texto("                             ", 23, 2);	
				break;
			}
		}
	}
	GravarArquivo();
}

Sessao GetSessao(int codSessao) {
	Sessao result;

	if(strcmp(Sessoes[codSessao].titulo, "") != 0)
		result = Sessoes[codSessao];
	
	return result;
}

void AddSessao(Sessao sessao) {
	int i = 0;

	for(i = 0; i <= maxReg; i++) {
		if(strcmp(Sessoes[i].titulo, "") == 0) {
			Sessoes[i] = sessao;
			break;
		}
	}
	GravarArquivo();
}

Ingresso GetIngresso(int codIngresso) {
	Ingresso result;

	if(strcmp(Ingressos[codIngresso].filme, "") != 0)
		result = Ingressos[codIngresso];
	
	return result;
}

void AddIngresso(Ingresso ingresso) {
	int i = 0;

	for(i = 0; i <= maxReg; i++) {
		if(strcmp(Ingressos[i].filme, "") == 0) {
			Ingressos[i] = ingresso;
			break;
		}
	}
	GravarArquivo();
}



