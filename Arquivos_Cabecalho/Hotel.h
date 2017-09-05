#ifndef _Hotel_ 
	//Se não estiver definido entra no if
#define _Hotel_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Prototipos.h"
	//Inclui arquivos de cabeçalho
/*
void Ler_Hotel_Txt(char Url[99]);
void Ler_Hotel_Bin();
void Ler_Hotel_Memoria(DADOS_HOTEL Hotel);
void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel);
void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel);
void Criar_Modificar_Hotel(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Hotel(char Url[99], int Codigo);
void Apagar_Modificar_Hotel_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
DADOS_HOTEL Retorna_Struct_Grava_Memoria(DADOS_HOTEL *Hotel);
*/

void Ler_Hotel_Txt(char Url[99]){
	DADOS_HOTEL Hotel;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		printf("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Hotel.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Nome_Fantasia);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Razao_Social);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Inscricao_Estadual);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.CNPJ);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Logradouro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Numero);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Bairro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Cidade);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Telefone);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Email);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Dono_Gerente);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Telefone_Gerente);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Check_in);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Check_out);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Lucro);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o ;)
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)

			printf("Codigo:\t\t\t%d\n",Hotel.Codigo);
			printf("Nome fantasia:\t\t%s\n",Hotel.Nome_Fantasia);
			printf("Razao social:\t\t%s\n",Hotel.Razao_Social);
			printf("Inscricao Estadual\t%s\n",Hotel.Inscricao_Estadual);
			printf("CNPJ:\t\t\t%s\n",Hotel.CNPJ);
			printf("Logradouro:\t\t%s\n",Hotel.Endereco.Logradouro);
			printf("Numero:\t\t\t%s\n",Hotel.Endereco.Numero);
			printf("Bairro:\t\t\t%s\n",Hotel.Endereco.Bairro);
			printf("Cidade:\t\t\t%s\n",Hotel.Endereco.Cidade);
			printf("Telefone:\t\t%s\n",Hotel.Telefone);
			printf("Email:\t\t\t%s\n",Hotel.Email);
			printf("Dono gerente:\t\t%s\n",Hotel.Dono_Gerente);
			printf("Telefone gerente:\t%s\n",Hotel.Telefone_Gerente);
			printf("Check in:\t\t%s\n",Hotel.Check_in);
			printf("Check out:\t\t%s\n",Hotel.Check_out);
			printf("%% de Lucro\t\t%s\n",Hotel.Lucro);
			printf("____________________________________________________\n");
			Arquivo_Vazio++;
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			printf("O Arquivo está vazio\n");
		}
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}
void Ler_Hotel_Memoria(DADOS_HOTEL Hotel){
	//Recebe por parametro Struct de Hotel
	printf("Codigo:\t\t\t%d\n",Hotel.Codigo);
	printf("Nome fantasia:\t\t%s\n",Hotel.Nome_Fantasia);
	printf("Razao social:\t\t%s\n",Hotel.Razao_Social);
	printf("Inscricao Estadual\t%s\n",Hotel.Inscricao_Estadual);
	printf("CNPJ:\t\t\t%s\n",Hotel.CNPJ);
	printf("Logradouro:\t\t%s\n",Hotel.Endereco.Logradouro);
	printf("Numero:\t\t\t%s\n",Hotel.Endereco.Numero);
	printf("Bairro:\t\t\t%s\n",Hotel.Endereco.Bairro);
	printf("Cidade:\t\t\t%s\n",Hotel.Endereco.Cidade);
	printf("Telefone:\t\t%s\n",Hotel.Telefone);
	printf("Email:\t\t\t%s\n",Hotel.Email);
	printf("Dono gerente:\t\t%s\n",Hotel.Dono_Gerente);
	printf("Telefone gerente:\t%s\n",Hotel.Telefone_Gerente);
	printf("Check in:\t\t%s\n",Hotel.Check_in);
	printf("Check out:\t\t%s\n",Hotel.Check_out);
	printf("%% de Lucro\t\t%s\n",Hotel.Lucro);
	printf("____________________________________________________\n");
	//Mostra dados do Hotel cadastrado na memoria
}

void Ler_Hotel_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	DADOS_HOTEL Hotel;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			printf("Codigo:\t\t\t%d\n",Hotel.Codigo);
			printf("Nome fantasia:\t\t%s\n",Hotel.Nome_Fantasia);
			printf("Razao social:\t\t%s\n",Hotel.Razao_Social);
			printf("Inscricao Estadual\t%s\n",Hotel.Inscricao_Estadual);
			printf("CNPJ:\t\t\t%s\n",Hotel.CNPJ);
			printf("Logradouro:\t\t%s\n",Hotel.Endereco.Logradouro);
			printf("Numero:\t\t\t%s\n",Hotel.Endereco.Numero);
			printf("Bairro:\t\t\t%s\n",Hotel.Endereco.Bairro);
			printf("Cidade:\t\t\t%s\n",Hotel.Endereco.Cidade);
			printf("Telefone:\t\t%s\n",Hotel.Telefone);
			printf("Email:\t\t\t%s\n",Hotel.Email);
			printf("Dono gerente:\t\t%s\n",Hotel.Dono_Gerente);
			printf("Telefone gerente:\t%s\n",Hotel.Telefone_Gerente);
			printf("Check in:\t\t%s\n",Hotel.Check_in);
			printf("Check out:\t\t%s\n",Hotel.Check_out);
			printf("%% de Lucro\t\t%s\n",Hotel.Lucro);
			printf("____________________________________________________\n");
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			printf("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Hotel->Codigo);
	fprintf(Arquivo,"%s;",Hotel->Nome_Fantasia);
	fprintf(Arquivo,"%s;",Hotel->Razao_Social);
	fprintf(Arquivo,"%s;",Hotel->Inscricao_Estadual);
	fprintf(Arquivo,"%s;",Hotel->CNPJ);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Logradouro);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Numero);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Bairro);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Cidade);
	fprintf(Arquivo,"%s;",Hotel->Telefone);
	fprintf(Arquivo,"%s;",Hotel->Email);
	fprintf(Arquivo,"%s;",Hotel->Dono_Gerente);
	fprintf(Arquivo,"%s;",Hotel->Telefone_Gerente);
	fprintf(Arquivo,"%s;",Hotel->Check_in);
	fprintf(Arquivo,"%s;",Hotel->Check_out);
	fprintf(Arquivo,"%s;\n",Hotel->Lucro);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Hotel, sizeof(DADOS_HOTEL), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Hotel.bin'");
   		//Mensagem de Confirmação
}

DADOS_HOTEL Retorna_Struct_Grava_Memoria(DADOS_HOTEL *Hotel){
	//Metodo do tipo Dados_Hotel e recebe por parametro ponteiro de Dados de Hotel
	Hotel->Codigo = 1;
	//Como salva so 1 dado na memoria coloca como codigo 1
	printf("\nNome Fantasia:");
	scanf("%s",Hotel->Nome_Fantasia);
	printf("Razão Social:");
	scanf("%s",Hotel->Razao_Social);
	printf("Inscrição Estadual:");
	scanf("%s",Hotel->Inscricao_Estadual);
	printf("CNPJ:");
	scanf("%s",Hotel->CNPJ);
	printf("Logradouro:");
	scanf("%s",Hotel->Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Hotel->Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Hotel->Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Hotel->Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Hotel->Telefone);
	printf("e-mail:");
	scanf("%s",Hotel->Email);
	printf("Dono/Gerente:");
	scanf("%s",Hotel->Dono_Gerente);
	printf("Telefone/Gente:");
	scanf("%s",Hotel->Telefone_Gerente);
	printf("Horário de check-in:");
	scanf("%s",Hotel->Check_in);
	printf("Horário de check-out:");
	scanf("%s",Hotel->Check_out);
	printf("Margen de lucro de produtos vendidos:");
	scanf("%s",Hotel->Lucro);
	//Le os outros dados
	return *Hotel;
	//Retorna ponteiro de hotel
}

void Criar_Modificar_Hotel(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	DADOS_HOTEL Hotel;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Hotel.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Texto);
		}else{
			Hotel.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Hotel.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Binario);
		}else{
			Hotel.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	printf("\nNome Fantasia:");
	scanf("%s",Hotel.Nome_Fantasia);
	printf("Razão Social:");
	scanf("%s",Hotel.Razao_Social);
	printf("Inscrição Estadual:");
	scanf("%s",Hotel.Inscricao_Estadual);
	printf("CNPJ:");
	scanf("%s",Hotel.CNPJ);
	printf("Logradouro:");
	scanf("%s",Hotel.Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Hotel.Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Hotel.Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Hotel.Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Hotel.Telefone);
	printf("e-mail:");
	scanf("%s",Hotel.Email);
	printf("Dono/Gerente:");
	scanf("%s",Hotel.Dono_Gerente);
	printf("Telefone/Gente:");
	scanf("%s",Hotel.Telefone_Gerente);
	printf("Horário de check-in:");
	scanf("%s",Hotel.Check_in);
	printf("Horário de check-out:");
	scanf("%s",Hotel.Check_out);
	printf("Margen de lucro de produtos vendidos:");
	scanf("%s",Hotel.Lucro);
	//Mostra Dados de Hotel salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Hotel_Txt(Url,&Hotel);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Hotel_Bin(Url,&Hotel);
			//Grava em BIN
			break;

		case Banco_De_Dados:
			printf("Banco de Dados não foi implentado\n");
			break;
		case Nuvem:
			printf("Nuvem não foi implementado\n");
			break;
	}
		//Para Grava o Buffer da String no Arquivo
}


int Retorna_Campo_Struct_Hotel(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	DADOS_HOTEL Hotel;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
		Validador = Hotel.Codigo;
		if(feof(Arquivo)){
			return -1;
			break;
		}
		if(Validador == Codigo){
			//Verifica se o codigo é igual ao lido
			return Numero_Structs;
			//Retorna a linha que tem o codigo
			break;
			//Confirma se saiu do loop
		}
		Numero_Structs++;
		//Soma no contac
	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
}

void Apagar_Modificar_Hotel_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		DADOS_HOTEL Hotel;
		//Cria uma Variavel do tipo Dados_Hotel
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Hotel(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			printf("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
					fwrite(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Hotel(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					printf("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo_Temporario); 
						//Printa no Arquivo Temporario
				}
				fclose(Arquivo_Temporario);
				fclose(Arquivo);
					//Fecha ambos os Arquivos
				remove(Url);
					//Remove o Arquivo Original
				rename("Arquivos/Temp",Url);
					//Renomeia o Arquivo
				if(Modificar==0){
					printf("\nExcluído com Sucesso");
					//Mostra que foi apagado com sucesso
				}
			}
		}
	}
}


#endif
