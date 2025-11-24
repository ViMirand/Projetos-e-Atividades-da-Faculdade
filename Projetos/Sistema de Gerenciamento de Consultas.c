#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<locale.h>

#define QTD 30
#define LETRAS 50

//structs
struct pessoa{
	int idade, birth[3], matricula;
	char nome[LETRAS], email[LETRAS], endereco[6][LETRAS], fone[20], cpf[15], registro_profissional[LETRAS], tipo_de_profissional[LETRAS], sigla[LETRAS];
};

struct consulta{
	int data[3], id;
	char descricao[LETRAS*2], dados_profissional, dados_paciente;
};

typedef struct pessoa profissional;
typedef struct pessoa paciente;
typedef struct consulta consulta;

//variáveis globais
int count_pacientes = 0, count_profissionais = 0, count_consultas = 0, a, b, cod;
char choose[LETRAS];

paciente lista_pacientes[QTD];
profissional lista_profissionais[QTD];
consulta lista_consulta[QTD];

//funções
void Cadastro();
void Profissional();
void Paciente();
void Consultas();
void Check(int op);
void Menu();


void Cadastro(){
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- DADOS DO PACIENTE ------------------\n");
		lista_pacientes[count_pacientes].matricula = count_pacientes+1+202500;
		printf("MATRICULA: %d\n", lista_pacientes[count_pacientes].matricula);
		getchar();
		printf("NOME: ");
		fgets(lista_pacientes[count_pacientes].nome, LETRAS, stdin);
		printf("Data de Nascimento: ");
		for(a=0; a<3; a++){
			scanf("%d", &lista_pacientes[count_pacientes].birth[a]);
		}
		getchar();
		if(lista_pacientes[count_pacientes].birth[1] < 11 ){
			lista_pacientes[count_pacientes].idade = 2025 - lista_pacientes[count_pacientes].birth[2];	
		}else if(lista_pacientes[count_pacientes].birth[1] >= 11 ){
			lista_pacientes[count_pacientes].idade = 2026 - lista_pacientes[count_pacientes].birth[2];
		}
		printf("Idade: %d\n", lista_pacientes[count_pacientes].idade);
		printf("Fone: ");
		fgets(lista_pacientes[count_pacientes].fone, 20, stdin);
		printf("Email: ");
		fgets(lista_pacientes[count_pacientes].email, LETRAS, stdin);
		printf("____________________ Endereco _________________\n");
		printf("LOGRADOURO: ");
		fgets(lista_pacientes[count_pacientes].endereco[0], LETRAS, stdin);
		printf("NUMERO: ");
		fgets(lista_pacientes[count_pacientes].endereco[1], LETRAS, stdin);
		printf("BAIRRO: ");
		fgets(lista_pacientes[count_pacientes].endereco[2], LETRAS, stdin);
		printf("CIDADE: ");
		fgets(lista_pacientes[count_pacientes].endereco[3], LETRAS, stdin);
		printf("ESTADO: ");
		fgets(lista_pacientes[count_pacientes].endereco[4], LETRAS, stdin);
		printf("CEP: ");
		fgets(lista_pacientes[count_pacientes].endereco[5], LETRAS, stdin);		
		count_pacientes++;	
		system("cls");
		Paciente();
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- DADOS DO PROFISSIONAL ------------------\n");
		lista_profissionais[count_profissionais].matricula = count_profissionais+1+202500;
		printf("MATRICULA: %d\n", lista_profissionais[count_profissionais].matricula);
		getchar();
		printf("NOME: ");
		fgets(lista_profissionais[count_profissionais].nome, LETRAS, stdin);
		printf("CPF: ");
		fgets(lista_profissionais[count_profissionais].cpf, 20, stdin);
		printf("Data de Nascimento: ");
		for(a=0; a<3; a++){
			scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
		}
		getchar();		
		if(lista_profissionais[count_profissionais].birth[1] < 11 ){
			lista_profissionais[count_profissionais].idade = 2025 - lista_profissionais[count_profissionais].birth[2];	
		}else if (lista_profissionais[count_profissionais].birth[1] >= 11 ){
			lista_profissionais[count_profissionais].idade = 2026 - lista_profissionais[count_profissionais].birth[2];
		}
		printf("Idade: %d", lista_profissionais[count_profissionais].idade);
		printf("\nFone: ");
		fgets(lista_profissionais[count_profissionais].fone, 20, stdin);
		printf("Email: ");
		fgets(lista_profissionais[count_profissionais].email, LETRAS, stdin);
		printf("Profissao: ");
		fgets(lista_profissionais[count_profissionais].tipo_de_profissional, LETRAS, stdin);
		printf("Sigla do Conselho (CRM, COREN, etc.): ");
		fgets(lista_profissionais[count_profissionais].sigla, LETRAS, stdin);
		printf("Numero de Registro Profissional (NRP): ");
		fgets(lista_profissionais[count_profissionais].registro_profissional, LETRAS, stdin);
		printf("--------------------------------------------\n");
		count_profissionais++;
		system("cls");
		Profissional();	
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- NOVO ATENDIMENTO ------------------\n");
		lista_consulta[count_consultas].id = count_consultas+1;
		printf("MATRICULA: %d\n", lista_consulta[count_consultas].id);
		printf("Matricula do Profissional Atendente: ");
		scanf("%d", &lista_consulta[count_consultas].dados_profissional);
	//	cod = lista_consulta[count_consultas].dados_profissional - 202501;
	//	printf("Doutor(a): %s", lista_profissionais[cod].nome);
		printf("Matricula do Paciente: ");
		scanf("%d", &lista_consulta[count_consultas].dados_paciente);
		getchar();
		printf("Descricao: ");
		fgets(lista_consulta[count_consultas].descricao, LETRAS, stdin);
		getchar();
		count_consultas++;
		system("cls");
		Consultas();
	}
}

void Listagem(){
	int op;
	system("cls");
	printf("\n\t L I S T A G E M\n\n");
	printf("----------- O P C O E S -------------\n\n\n");
	printf("Ordem alfabetica  _ _ _ _ _ _ _ _ _ 1\n\n");
	printf("Matricula _ _ _ _ _ _ _ _ _ _ _ _ _ 2\n\n");
	printf("Data de Aniversario _ _ _ _ _ _ _ _ 3\n\n\n");
	printf("-------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &op);
	Check(op);	
}

void Editar(){
	
}

void Excluir(){
	
}

void Profissional(){
	int op;
	system("cls");
	printf("\n\tA R E A   D O   P R O F I S S I O N A L\n\n");
	printf("------------------ O P C O E S --------------------\n\n\n");
	printf("1 - Novo profissional\n");
	printf("2 - Editar cadastro\n");
	printf("3 - Excluir cadastro\n");
	printf("4 - Listagem de profissionais de saude da unidade\n");
	printf("5 - Voltar ao inicio\n\n\n");
	printf("---------------------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &op);
	Check(op);	
}

void Paciente(){
	int op;
	system("cls");
	printf("\n\tA R E A   D O   P A C I E N T E\n\n");
	printf("------------------ O P C O E S --------------------\n\n\n");
	printf("1 - Novo paciente\n");
	printf("2 - Editar cadastro\n");
	printf("3 - Excluir cadastro\n");
	printf("4 - Listagem de pacientes\n");
	printf("5 - Voltar ao inicio\n\n\n");
	printf("---------------------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &op);
	Check(op);	
}

void Consultas(){
	int op;
	system("cls");
	printf("\n  A R E A   D A S   C O N S U L T A S\n\n");
	printf("----------- O P C O E S -------------\n\n\n");
	printf("Nova consulta  _ _ _ _ _ _ _ _ _ _ _ 1\n\n");
	printf("Listagem  _ _ _ _ _ _ _ _ _ _ _ _ _ 2\n\n\n");
	printf("-------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &op);
	Check(op);
}

void Check(int op){
	switch (op){
		case 1:
			Cadastro();break;
		case 2:
			Editar(); break;
		case 3:
			Excluir(); break;
		case 4:
			Listagem();break;
		case 5:
			Menu(); break;
		default:
			system("cls");
			printf("\n\n\n\n\n\n\nOpcao inexistente! Você sera direcionado ao inicio.\n\n\n\n");
			system("pause");
			Menu();break;
	}
}

void Menu(){
	int op;
	printf("----------- SISTEMA DE GERENCIAMENTO DE CONSULTAS -----------\n\n");
    printf("1 - Gerenciar Profissionais de Saude\n");
    printf("2 - Gerenciar Pacientes\n");
    printf("3 - Gerenciar Atendimentos\n");
    printf("4 - Relatorios (Aniversariantes, Estatisticas)\n");
    printf("5 - Sair\n\n");
    printf("-------------------------------------------------------------------\n");
    printf("Escolha: ");
	scanf("%d", &op);
	if(op == 2){
		strcpy(choose, "PACIENTE");
		Paciente();
	}else if(op==1){
		strcpy(choose, "PROFISSIONAL");
		Profissional();
	}else if(op==3){
		strcpy(choose, "CONSULTAS");
		Consultas();
	}else if(op==4){
		strcpy(choose, "RELATORIOS");
		Consultas();
	}else{
		Check(0);
	}
}

int main(){
	setlocale(LC_ALL, "pt-br");
	printf("\n\n\n-----------------SISTEMA DE GERENCICAMENTO DE CONSULTAS------------------\n");
	system("pause");
	system("cls");
	Menu();
	return 10;
}
