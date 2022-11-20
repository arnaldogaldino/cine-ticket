#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

using namespace std;

void TelaCadCliente()
{
	LimparTela();		
	Texto(" * * CADASTRO DE CLIENTES * * ", 5, 24);
	char* nome = "";
	char* senha = "";
	Data dataNasc; // = Data() { dia = 0, mes = 0, ano = 0};
	
	dataNasc.dia = 0;
	dataNasc.mes = 0;
	dataNasc.ano = 0;
	
	int idade = 0;
	char testeSN = 'N';
		
	//while(result==0) {		
		Texto("NOME:", 7, 10);
		Texto("ESTUDANTES:", 8, 10);
		Texto("APOSTENTADO:", 9, 10);
		Texto("GRAVAR:", 15, 10);
		Texto("SENHA:", 16, 10);
		
		nome = Campo(nome, 7, 16, 50);
		dataNasc = CampoData(dataNasc, 8, 25);
		
		idade = 
		
		idade = CampoNum(idade, 9, 17, 3);
		
		testeSN = CampoSN(testeSN, 15, 18);
		
		senha = CampoSenha(senha, 16, 17, 10);
		_getch();
	//}
}
