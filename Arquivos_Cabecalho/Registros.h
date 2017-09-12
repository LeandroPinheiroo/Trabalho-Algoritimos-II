#ifndef _Registro_ 
	//Se não estiver definido entra no if
#define _Registro_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

//Enum
enum Modo_de_Abertura{Erro=0,Memoria,Arquivo_Texto,Arquivo_Binario,Banco_De_Dados,Nuvem};
enum Registro{Dados_Hotel=1,Dados_Hospede,Dados_Acomodacoes,Dados_Codigo_Categoria,Dados_Produtos,Dados_Fornecedores,Dados_Funcionarios};	
enum Acoes{Ler=1,Criar,Editar,Apagar};	
//enum Registro{Codigo=0,Nome_Fantasia,Razao_Social,Hotel,Inscricao_Estadual,CNPJ,Logradouro,Numero,Bairro,Cidade,Telefone,Email,Dono_Gerente,Telefone_Gerente,Check_in,Check_out,Lucro};
	//Enumerador para facilitar a leitura pois a onde estiver escrito tal palavra representara
	//o valor sendo que a cada termo tem um acrescimo unário ou seja como o primeiro termo tem
	//tribuido o valor 0 o segundo será atribuido o valor 1 o 3º o valor 2 e assim por diante

//Struturas e Union


//Define
#define Tamanho1 80
#define Tamanho2 999

	//O Typedef atribui um apelido em vez de ter que declarar "struct Nome_da_struct" será usado apenas "Nome_da_struct"
typedef struct Modo{
	char Leitura[4];
	char Escrita[4];
	char Concatenacao[4];
	int Modo_de_Abertura;
}MODO;
	
typedef struct Login{
	int Codigo_Usuario;
	int Permissao_Criar;
	int Permissao_Editar;
	int Permissao_Ler;
	int Permissao_Apagar;
	int Logado;
}LOGIN;
	
typedef struct Endereco{
	char Logradouro[Tamanho1];
	char Numero[Tamanho1];
	char Bairro[Tamanho1];
	char Cidade[Tamanho1];
}ENDERECO;

typedef struct Dados_Hotel{
	int Codigo;
	char Nome_Fantasia[Tamanho1];
	char Razao_Social[Tamanho1];
	char Inscricao_Estadual[Tamanho1];
	char CNPJ[Tamanho1];
	ENDERECO Endereco;
	char Telefone[Tamanho1];
	char Email[Tamanho1];
	char Dono_Gerente[Tamanho1];
	char Telefone_Gerente[Tamanho1];
	char Check_in[Tamanho1];
	char Check_out[Tamanho1];
	char Lucro[Tamanho1];
}DADOS_HOTEL;

typedef struct Dados_Hospede{
	int Codigo;
	char Nome[Tamanho1];
	char CPF[Tamanho1];
	ENDERECO Endereco;
	char Telefone[Tamanho1];
	char Email[Tamanho1];
	char Sexo[Tamanho1];
	char Estado_Civil[Tamanho1];
	char Data_Nascimento[Tamanho1];
}DADOS_HOSPEDE;

typedef struct Facilidades{
	int Televisao;
	int Ar_Condicionado;
	int Frigobar;
	int Internet;
	int Banheira;
}FACILIDADES;

typedef struct Acomodacoes{
	int Codigo;
	char Descricao[Tamanho2];
	FACILIDADES Facilidades;
	int Cod_Categoria;
}ACOMODACOES;

typedef struct Codigo_Categoria{
	int Codigo;
	char Nome[Tamanho1];
	char Descricao[Tamanho2];
	float Valor_Diaria;
	int Capacidade;
}CODIGO_CATEGORIA;
typedef struct Produtos{
	int Codigo;
	unsigned int Estoque;
	unsigned int Estoque_Minimo;
	char Descricao[Tamanho2];
	float Preco_Codigo;
	float Preco_Venda;
}PRODUTOS;

typedef struct Fornecedores{
	int Codigo;
	char Nome_Fantasia[Tamanho1];
	char Razao_Social[Tamanho1];
	char Inscricao_Estadual[Tamanho1];
	char CNPJ[Tamanho1];
	ENDERECO Endereco;
	char Telefone[Tamanho1];
	char Email[Tamanho1];

}FORNECEDORES;

typedef struct Funcionarios{
	int Codigo;
	char Usuario[Tamanho1];
	char Senha[Tamanho1];
	int Permissao;
		//Elaborar
}FUNCIONARIOS;
#endif