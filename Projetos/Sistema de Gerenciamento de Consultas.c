#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

#define QTD 30
#define LETRAS 50

//structs
struct pessoa{
	int idade, birth[3], matricula;
	char nome[LETRAS], email[LETRAS], endereco[6][LETRAS], fone[20], cpf[15], registro_profissional[LETRAS], tipo_de_profissional[LETRAS], sigla[LETRAS];
};

struct consulta{
	int data[3], id;
	char descricao[LETRAS*4];
	int dados_profissional, dados_paciente;
};

typedef struct pessoa profissional;
typedef struct pessoa paciente;
typedef struct consulta consulta;

//variáveis globais
int count_pacientes = 0, count_profissionais = 0, count_consultas = 0, a, b, cod, ExC = 0, ExP = 0, ExPa = 0;
char choose[LETRAS], choose1[LETRAS];

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
void Encontra(int idP, int idC);
void Relatorios();
void Verificacao(int op);
void Apresentacao_Relatorios();


void Cadastro(){
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- DADOS DO PACIENTE ------------------\n");
		lista_pacientes[count_pacientes].matricula = count_pacientes+1+202500;
		printf("MATRICULA: %d\n", lista_pacientes[count_pacientes].matricula);
		getchar();
		printf("NOME: ");
		fgets(lista_pacientes[count_pacientes].nome, LETRAS, stdin);
		printf("CPF: ");
		fgets(lista_pacientes[count_pacientes].cpf, 20, stdin);
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
		Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
		printf("Data da Consulta: ");
		for(b=0; b<3; b++){
			scanf("%d", &lista_consulta[a].data[b]);
		}
		printf("Descricao: ");
		fgets(lista_consulta[count_consultas].descricao, LETRAS, stdin);
		count_consultas++;
		system("cls");
		Consultas();
	}
}

void Listagem(){
	system("cls");
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- LISTA DE PACIENTES [%d Registros] -----------------\n", count_pacientes-ExPa);
		if(count_pacientes == 0){
			printf("AINDA NAO HA REGISTROS!\n");
		}else{
			for (a=0; a < count_pacientes; a++){
				if(lista_pacientes[a].matricula != 0){
					printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
					printf("NOME: %s\n",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d | %d | %d (%d ANOS)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
					printf("CONTATO: \nCEL: %s\nEMAIL: %s\n",lista_pacientes[a].fone, lista_pacientes[a].email);
					printf("----------------------------------------------------------------\n");
				}
			}
		}
		system("pause");
		Paciente();		
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- LISTA DE PROFISSIONAIS DE SAUDE [%d Registros] ------------------\n", count_profissionais-ExP);
		if(count_profissionais == 0){
			printf("AINDA NAO HA REGISTROS!\n");
		}else{
			for (a=0; a < count_profissionais; a++){
				if(lista_profissionais[a].matricula != 0){
					printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
					printf("PROFISSAO: %s (%s - %s)\n",lista_profissionais[a].tipo_de_profissional, lista_profissionais[a].sigla, lista_profissionais[a].registro_profissional);
					printf("NOME: %s\n",lista_profissionais[a].nome);
					printf("NASCIMENTO: %d | %d | %d (%d ANOS)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
					printf("CONTATO: \nCEL: %s\nEMAIL: %s\n", lista_profissionais[a].fone, lista_profissionais[a].email);
					printf("----------------------------------------------------------------\n");
				}
			}
		}
		system("pause");
		Profissional();	
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- LISTA DE ATENDIMENTOS [%d Registros] ------------------\n", count_consultas-ExC);
		if(count_profissionais == 0){
			printf("AINDA NAO HA REGISTROS!\n");
		}else{
			for (a=0; a < count_consultas; a++){
				if(lista_consulta[a].id != 0){
					printf("ATENDIMENTO: #%d em %d | %d | %d", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
					printf("----------------------------------------------------------------\n");
					Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
					printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
					printf("----------------------------------------------------------------\n");
				}
			}
		}
		system("pause");
		Consultas();
	}	
}

void Encontra(int idP, int idC){
	for(a=0; a<=count_profissionais; a++){
		if(lista_profissionais[a].matricula == idP){
			printf("RESPONSAVEL: %s",lista_profissionais[a].nome);
			printf("PROFISSAO: %s", lista_profissionais[a].tipo_de_profissional);
			printf("----------------------------------------------------------------\n");
		}
	}
	for(a=0;a<=count_pacientes; a++){
		if(lista_pacientes[a].matricula == idC){
			printf("PACIENTE: %s ",lista_pacientes[a].nome);
			printf("CPF: %s", lista_pacientes[a].cpf);
			printf("IDADE: %d\n", lista_pacientes[a].idade);
			printf("----------------------------------------------------------------\n");
		}
	}
}

void Editar(){
	int op, mat;
	system("cls");
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- EDITAR DADOS DO PACIENTE ------------------\n");
		printf("Digite a matricula do paciente: ");
		scanf("%d", &mat);
		for(a=0;a<=count_pacientes; a++){
			if(lista_pacientes[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
				printf("NOME: %s\n",lista_pacientes[a].nome);
				printf("NASCIMENTO: %d / %d / %d (%d)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				printf("CONTATO: \nCEL: %s\nEMAIL: %s\n",lista_pacientes[a].fone, lista_pacientes[a].email);
				printf("----------------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
				printf("NOME: ");
				fgets(lista_pacientes[a].nome, LETRAS, stdin);
				printf("Data de Nascimento: ");
				for(b=0; b<3; b++){
					scanf("%d", &lista_pacientes[a].birth[b]);
				}
				getchar();
				if(lista_pacientes[a].birth[1] < 11 ){
					lista_pacientes[a].idade = 2025 - lista_pacientes[a].birth[2];	
				}else if(lista_pacientes[a].birth[1] >= 11 ){
					lista_pacientes[a].idade = 2026 - lista_pacientes[a].birth[2];
				}
				printf("Idade: %d\n", lista_pacientes[a].idade);
				printf("Fone: ");
				fgets(lista_pacientes[a].fone, 20, stdin);
				printf("Email: ");
				fgets(lista_pacientes[a].email, LETRAS, stdin);
				printf("________________________ Endereco ______________________\n");
				printf("LOGRADOURO: ");
				fgets(lista_pacientes[a].endereco[0], LETRAS, stdin);
				printf("NUMERO: ");
				fgets(lista_pacientes[a].endereco[1], LETRAS, stdin);
				printf("BAIRRO: ");
				fgets(lista_pacientes[a].endereco[2], LETRAS, stdin);
				printf("CIDADE: ");
				fgets(lista_pacientes[a].endereco[3], LETRAS, stdin);
				printf("ESTADO: ");
				fgets(lista_pacientes[a].endereco[4], LETRAS, stdin);
				printf("CEP: ");
				fgets(lista_pacientes[a].endereco[5], LETRAS, stdin);	
			}
		}
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- EDITAR DADOS DO PROFISSIONAL ------------------\n");
		printf("Digite a matricula do profissional: ");
		scanf("%d", &mat);
		for(a=0;a<=count_profissionais; a++){
			if(lista_profissionais[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
				printf("NOME: %s\n",lista_profissionais[a].nome);
				printf("CPF: %s\n",lista_profissionais[a].cpf);
				printf("PROFISSAO: %s\n",lista_profissionais[a].tipo_de_profissional);
				printf("SIGLA: %s\n",lista_profissionais[a].sigla);
				printf("NUMERO DE REGISTRO: %s (%s - %s)\n",lista_profissionais[a].registro_profissional);
				printf("NASCIMENTO: %d / %d / %d (%d)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				printf("CONTATO: \nCEL: %s\nEMAIL: %s\n", lista_profissionais[a].fone, lista_profissionais[a].email);
				printf("----------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
				printf("NOME: ");
				fgets(lista_profissionais[count_profissionais].nome, LETRAS, stdin);
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
			}
		}	
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- EDITAR DADOS DO ATENDIMENTOS --------------------\n");
		printf("Digite a identificacao do atendimento: ");
		scanf("%d", &mat);
		for(a=0;a<=count_consultas; a++){
			if(lista_consulta[a].id == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("ATENDIMENTO: #%d em %d / %d/ %d\n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
				printf("----------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
				printf("MATRICULA: %d\n", lista_consulta[count_consultas].id);
				printf("Matricula do Profissional Atendente: ");
				scanf("%d", &lista_consulta[count_consultas].dados_profissional);
				printf("Matricula do Paciente: ");
				scanf("%d", &lista_consulta[count_consultas].dados_paciente);
				getchar();
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("Descricao: ");
				fgets(lista_consulta[count_consultas].descricao, LETRAS, stdin);
			}
		}	
	}
}

void Excluir(){
	int mat, resp;
	system("cls");
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- EXCLUIR DADOS DO PACIENTE ------------------\n");
		printf("Digite a matricula do paciente: ");
		scanf("%d", &mat);
		for(a=0;a<=count_pacientes; a++){
			if(lista_pacientes[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
				printf("NOME: %s",lista_pacientes[a].nome);
				printf("NASCIMENTO: %d / %d / %d (%d anos)", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				printf("\nCONTATO: \nCEL: %s\nEMAIL: %s",lista_pacientes[a].fone, lista_pacientes[a].email);
				printf("----------------------------------------------------------------\n\n");
				printf("CONTINUAR? 0 - Nao\t1 - Sim\n");
				scanf("%d", &resp);
				if(resp == 1){
					lista_pacientes[a].matricula = 0;
					ExPa++;
				}
				system("pause");
			}
		}
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- EXCLUIR DADOS DO PROFISSIONAL ------------------\n");
		printf("Digite a matricula do profissional: ");
		scanf("%d", &mat);
		for(a=0;a<=count_profissionais; a++){
			if(lista_profissionais[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
				printf("NOME: %s",lista_profissionais[a].nome);
				printf("CPF: %s",lista_profissionais[a].cpf);
				printf("PROFISSAO: %s",lista_profissionais[a].tipo_de_profissional);
				printf("SIGLA: %s", lista_profissionais[a].sigla);
				printf("NUMERO DE REGISTRO: %s",lista_profissionais[a].registro_profissional);
				printf("NASCIMENTO: %d / %d / %d (%d anos)", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				printf("\nCONTATO: \nCEL: %s\nEMAIL: %s", lista_profissionais[a].fone, lista_profissionais[a].email);
				printf("----------------------------------------------------------\n\n");
				printf("CONTINUAR? 0 - Nao\t1 - Sim\n");
				scanf("%d", &resp);
				if(resp == 1){
					lista_profissionais[a].matricula = 0;
					ExP++;
				}
				system("pause");		
			}
		}	
	}else if (strcmp(choose, "CONSULTAS") == 0){
		for(a=0;a<count_consultas; a++){
			if(lista_consulta[a].id == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("ATENDIMENTO: #%d em %d / %d/ %d\n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
				printf("----------------------------------------------------------\n\n");
				printf("CONTINUAR? 0 - Nao\t1 - Sim\n");
				scanf("%d", &resp);
				if(resp == 1){
					lista_consulta[a].id = 0;
					ExC++;
				}
				system("pause");
			}
		}	
	}	
}

void Profissional(){
	int op;
	system("cls");
	printf("\n\tA R E A   D O   P R O F I S S I O N A L\n");
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
	printf("\n\tA R E A   D O   P A C I E N T E\n");
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
	printf("\n  A R E A   D A S   C O N S U L T A S\n");
	printf("----------- O P C O E S -------------\n\n\n");
	printf("1 - Novo atendimento\n");
	printf("2 - Editar atendimento\n");
	printf("3 - Excluir atendimento\n");
	printf("4 - Listagem de atendimentos\n");
	printf("5 - Voltar ao inicio\n\n\n");
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
			printf("\n\n\n\n\n\n\nOpcao inexistente! Voce sera direcionado ao inicio.\n\n\n\n");
			system("pause");
			Menu();
	}
}

void Relatorios(){
	int op;
	system("cls");
	printf("--------------------------- AREA DOS RELATORIOS ---------------------------\n\n");
	printf("1 - Aniversariantes da Instituicao\n");
    printf("2 - Atendimentos ordenados por Profissional\n");
    printf("3 - Voltar ao inicio\n\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Escolha: ");
	scanf("%d", &op);
	Verificacao(op);
}

void Verificacao(int op){
	if(op == 2){
		strcpy(choose1, "01");
		Apresentacao_Relatorios();
	}else if(op==1){
		strcpy(choose1, "02");
		Apresentacao_Relatorios();
	}else{
		Menu();
	}
}

void Apresentacao_Relatorios(){
	int m;
	char escolha[LETRAS];
	if (strcmp(choose1, "01") == 0){
		printf("--------------------------- ANIVERSARIANTES ---------------------------\n\n");
		printf("Digite o mes em questao [ EX: Quero abril, vou colocar 4 ]: ");
		scanf("%d", &m);
		printf("Agora, escolha, 'todos' (pacientes e profissionais) ou so 'pacientes': ");
		fgets(escolha, LETRAS, stdin);
		if (strcmp(escolha, "pacientes") == 0){
			for(a=0; a<count_pacientes;a++){
				if(m == lista_pacientes[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
					printf("NOME: %s\n",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d / %d / %d (%d)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				}
			}
		}else if(strcmp(escolha, "todos") == 0){
			for(a=0; a<count_pacientes;a++){
				if(m == lista_pacientes[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
					printf("NOME: %s\n",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d / %d / %d (%d)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				}
			}
			for(a=0; a<count_profissionais;a++){
				if(m == lista_profissionais[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
					printf("NOME: %s\n",lista_profissionais[a].nome);
					printf("PROFISSAO: %s\n", lista_profissionais[a].tipo_de_profissional);
					printf("NASCIMENTO: %d / %d / %d (%d)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1], lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				}
			}
		}
		system("pause");
	}else if (strcmp(choose1, "02") == 0){
		printf("--------------------------- ATENDIMENTOS ---------------------------\n\n");
		printf("Digite a matricula do profissional em questao: ");
		scanf("%d", &m);
		for(a=0; a<count_consultas;a++){
			if(m == lista_consulta[a].dados_profissional){
				printf("----------------------------------------------------------------\n");
				printf("ATENDIMENTO: #%d em %d / %d/ %d\n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
			}
		}
		system("pause");
	}
}

void Menu(){
	int op;
	system("cls");
	printf("----------- SISTEMA DE GERENCIAMENTO DE CONSULTAS -----------\n\n");
    printf("1 - Gerenciar Profissionais de Saude\n");
    printf("2 - Gerenciar Pacientes\n");
    printf("3 - Gerenciar Atendimentos\n");
    printf("4 - Relatorios (Aniversariantes, Atendimentos)\n");
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
		Relatorios();
	}else{
		return 10;
	}
}

int main(){
	setlocale(LC_ALL, "pt-br");
	printf("\n\n\n---------------------------------------------------------------------------------------------------------------------\n\n\n\n\n");
	printf("                                     SISTEMA DE GERENCICAMENTO DE CONSULTAS");
	printf("\n\n\n\n\n---------------------------------------------------------------------------------------------------------------------\n\n\n\n\n");
	system("pause");
	system("cls");
	Menu();
	return 10;
}
