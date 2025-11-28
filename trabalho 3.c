#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include <windows.h>
#define QTD 30
#define LETRAS 50

//structs
struct pessoa{
	int idade, birth[3], matricula, tipo_profissional;
	char nome[LETRAS], email[LETRAS], endereco[6][LETRAS], fone[20], cpf[15], registro_profissional[LETRAS];
};

struct profissao{
	int id;
	char profissao[LETRAS], sigla[LETRAS];
};

struct consulta{
	int data[3], id;
	char descricao[LETRAS*4];
	int dados_profissional, dados_paciente;
};

typedef struct pessoa profissional;
typedef struct pessoa paciente;
typedef struct consulta consulta;
typedef struct profissao profissao;

//variáveis globais
int count_pacientes = 0, count_profissionais = 0, count_consultas = 0, a, b, i,  cod, ExC = 0, ExP = 0, ExPa = 0, count_profissao = 10;
char choose[LETRAS], choose1[LETRAS];

paciente lista_pacientes[QTD];
profissao tprofissao[15];
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
void Profissao(int id);

//arquivos
void salvarProfissoes() {
	int i;
    FILE *f = fopen("lista_profissoes.txt", "w");
    if (f){
    	for(i = 0; i < count_profissao; i++) {
	        fprintf(f, "ID: #%d\nPROFISSÃO: %s\nSIGLA: %s\n_\n", tprofissao[i].id, tprofissao[i].profissao, tprofissao[i].sigla);
	    }
	    fclose(f);
	}else{
		printf("ERRO: Não ta salvando os dados!");
		return;
	}
}

void salvarProfissionais() {
	int i;
	char prof[LETRAS], sig[LETRAS]; 
    FILE *f = fopen("lista_profissionais.txt", "w");
    if(f){
    	for(i = 0; i < count_profissionais; i++) {
	    	if(lista_profissionais[i].tipo_profissional <= count_profissao){
				strcpy(prof, tprofissao[lista_profissionais[i].tipo_profissional-1].profissao);
				strcpy(sig, tprofissao[lista_profissionais[i].tipo_profissional-1].sigla);	
			}
	        fprintf(f, "MATRICULA: %d\nNOME: %sCPF: %sPROFISSAO: %s\nSIGLA: %s\nDATA DE ANIVERSARIO: %d/%d/%d\nTELEFONE: %sEMAIL: %s__\n",
	            lista_profissionais[i].matricula,
	            lista_profissionais[i].nome,
	            lista_profissionais[i].cpf,
	            prof,
	            sig,
	            lista_profissionais[i].birth[0],
	            lista_profissionais[i].birth[1],
	            lista_profissionais[i].birth[2],
	            lista_profissionais[i].fone,
	            lista_profissionais[i].email);
	    }
    fclose(f);
	}else{
		printf("ERRO: Não ta salvando os dados!");
		return;
	}
    
}

/*
void salvarClientes() {
	int i;
    FILE *f = fopen("clientes.txt","w");
    if(!f) return;
    for(i = 0; i < qtdClientes; i++) {
        fprintf(f,"%d;%s;%02d/%02d/%04d;%d;%s;%s;%s;%s\n",
            clientes[i].codigo,
            clientes[i].nome,
            clientes[i].dataNasc.dia,
            clientes[i].dataNasc.mes,
            clientes[i].dataNasc.ano,
            clientes[i].idade,
            clientes[i].email,
            clientes[i].fone,
            clientes[i].celular,
            clientes[i].endereco);
    }
    fclose(f);
}

void salvarAtendimentos() {
	int i;
    FILE *f = fopen("atendimentos.txt","w");
    if(!f) return;
    for(i=0; i<qtdAtendimentos; i++) {
        fprintf(f,"%d;%d;%d;%02d/%02d/%04d;%s\n",
            atendimentos[i].numero,
            atendimentos[i].Prof_matricula,
            atendimentos[i].Cliente_codigo,
            atendimentos[i].data.dia,
            atendimentos[i].data.mes,
            atendimentos[i].data.ano,
            atendimentos[i].descricao);
    }
    fclose(f);
}
*/

void Start(){
	tprofissao[0].id = 1;
	strcpy(tprofissao[0].profissao, "MEDICO");
	strcpy(tprofissao[0].sigla, "CRM");
	tprofissao[1].id = 2;
	strcpy(tprofissao[1].profissao, "NUTRICIONISTA");
	strcpy(tprofissao[1].sigla, "CRN");
	tprofissao[2].id = 3; // Corrigido de profissao[2] para tprofissao[2]
	strcpy(tprofissao[2].profissao, "DENTISTA");
	strcpy(tprofissao[2].sigla, "CRO");
	tprofissao[3].id = 4; // Corrigido
	strcpy(tprofissao[3].profissao, "FISIOTERAPEUTA");
	strcpy(tprofissao[3].sigla, "CREFITO");
	tprofissao[4].id = 5; // Corrigido
	strcpy(tprofissao[4].profissao, "PSICOLOGO");
	strcpy(tprofissao[4].sigla, "CRP");
	tprofissao[5].id = 6; // Corrigido
	strcpy(tprofissao[5].profissao, "ENFERMEIRO(A)");
	strcpy(tprofissao[5].sigla, "COREN");
	tprofissao[6].id = 7; // Corrigido
	strcpy(tprofissao[6].profissao, "FARMACEUTICO");
	strcpy(tprofissao[6].sigla, "CRF");
	tprofissao[7].id = 8; // Corrigido
	strcpy(tprofissao[7].profissao, "TERAPEUTA OCUPACIONAL");
	strcpy(tprofissao[7].sigla, "CREFITO");
	tprofissao[8].id = 9; // Corrigido
	strcpy(tprofissao[8].profissao, "BIOMEDICO");
	strcpy(tprofissao[8].sigla, "CRBM");
	tprofissao[9].id = 10; // Corrigido
	strcpy(tprofissao[9].profissao, "FONOAUDIOLOGO");
	strcpy(tprofissao[9].sigla, "CREFONO");
}

void Profissao(int id){
	if(id<=count_profissao){
		printf("PROFISSAO: %s", tprofissao[id-1].profissao);
		printf("\nSIGLA: %s\n", tprofissao[id-1].sigla);	
	}else{
		count_profissao++;
		tprofissao[count_profissao].id = count_profissao-1;
		printf("\nNOVA PROFISSAO: ");
		fgets(tprofissao[count_profissao].profissao, LETRAS, stdin);
		printf("\nSIGLA: ");
		fgets(tprofissao[count_profissao].sigla, LETRAS, stdin);
		lista_profissionais[count_profissionais].tipo_profissional = tprofissao[count_profissao].id;
	}
	salvarProfissoes();
}

void Cadastro(){
	system("cls");
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
			getchar();
			if(a == 0 && (lista_pacientes[count_pacientes].birth[a] <= 0 || lista_pacientes[count_pacientes].birth[a] > 31)){
				printf("Dia Inexistente! Digite novamente: ");
				scanf("%d", &lista_pacientes[count_pacientes].birth[a]);
				getchar();
			}
			if(a == 1 && (lista_pacientes[count_pacientes].birth[a] <=0 || lista_pacientes[count_pacientes].birth[a] > 12)){
				printf("Mes Inexistente! Digite novamente: ");
				scanf("%d", &lista_pacientes[count_pacientes].birth[a]);
				getchar();
			}
			if(a == 2 && (lista_pacientes[count_pacientes].birth[a] < 1970 || lista_pacientes[count_pacientes].birth[a] > 2025)){
				printf("Vish, esse ano nao e permitido. Digite novamente: ");
				scanf("%d", &lista_pacientes[count_pacientes].birth[a]);
				getchar();
			}
		}
		if(lista_pacientes[count_pacientes].birth[1] <= 11 ){
			lista_pacientes[count_pacientes].idade = 2025 - lista_pacientes[count_pacientes].birth[2];	
		}else if(lista_pacientes[count_pacientes].birth[1] > 11 ){
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
		system("pause");	
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
			getchar();
			if(a == 0 && (lista_profissionais[count_profissionais].birth[a]<=0 || lista_profissionais[count_profissionais].birth[a] > 31)){
				printf("Dia Inexistente! Digite novamente: ");
				scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
				getchar();
			}
			if(a == 1 && (lista_profissionais[count_profissionais].birth[a]<=0 || lista_profissionais[count_profissionais].birth[a] > 12)){
				printf("Mes Inexistente! Digite novamente: ");
				scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
				getchar();
			}
			if(a == 2 && (lista_profissionais[count_profissionais].birth[a] < 1970 || lista_profissionais[count_profissionais].birth[a] > 2003)){
				printf("Vish, esse ano nao e permitido. Digite novamente: ");
				scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
				getchar();
			}
		}
		if(lista_profissionais[count_profissionais].birth[1] <= 11 ){
			lista_profissionais[count_profissionais].idade = 2025 - lista_profissionais[count_profissionais].birth[2];	
		}else if (lista_profissionais[count_profissionais].birth[1] > 11 ){
			lista_profissionais[count_profissionais].idade = 2026 - lista_profissionais[count_profissionais].birth[2];
		}
		printf("Idade: %d", lista_profissionais[count_profissionais].idade);
		printf("\nFone: ");
		fgets(lista_profissionais[count_profissionais].fone, 20, stdin);
		printf("Email: ");
		fgets(lista_profissionais[count_profissionais].email, LETRAS, stdin);
		for (a=0; a<10; a++){
			printf("%d | %s\n", tprofissao[a].id, tprofissao[a].profissao);
		}
		printf("\nEscolha, mas se sua profissao nao estiver ai, digite qualquer NUMERO para adicionar: ");
		scanf("%d", &lista_profissionais[count_profissionais].tipo_profissional);
		getchar();
		Profissao(lista_profissionais[count_profissionais].tipo_profissional);
		printf("Numero de Registro Profissional (NRP): ");
		fgets(lista_profissionais[count_profissionais].registro_profissional, LETRAS, stdin);
		printf("--------------------------------------------\n");
		count_profissionais++;
		salvarProfissionais();
		system("pause");
		system("cls");
		Profissional();	
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- NOVO ATENDIMENTO ------------------\n");
		lista_consulta[count_consultas].id = count_consultas+1;
		printf("MATRICULA: %d\n", lista_consulta[count_consultas].id);
		printf("Matricula do Profissional Atendente: ");
		scanf("%d", &lista_consulta[count_consultas].dados_profissional);
		cod = lista_consulta[count_consultas].dados_profissional - 202501;
		printf("Doutor(a): %s", lista_profissionais[cod].nome);
		Profissao(lista_profissionais[cod].tipo_profissional);
		printf("Matricula do Paciente: ");
		scanf("%d", &lista_consulta[count_consultas].dados_paciente);
		cod = lista_consulta[count_consultas].dados_paciente - 202501;
		printf("Paciente: %s", lista_pacientes[cod].nome);
		printf("CPF: %s", lista_pacientes[cod].cpf);
		getchar();
		printf("Data da Consulta:   /   /   ");
		for(b=0; b<3; b++){
			scanf("%d", &lista_consulta[count_consultas].data[b]);
			getchar();
			if(a == 0 && (lista_consulta[count_consultas].data[b] <= 0 || lista_consulta[count_consultas].data[b] > 31)){
				printf("Dia Inexistente! Digite novamente: ");
				scanf("%d", &lista_consulta[count_consultas].data[b]);
				getchar();
			}
			if(a == 1 && (lista_consulta[count_consultas].data[b] <= 0 || lista_consulta[count_consultas].data[b] > 12)){
				printf("Mes Inexistente! Digite novamente: ");
				scanf("%d", &lista_consulta[count_consultas].data[b]);
				getchar();
			}
			if(a == 2 && (lista_consulta[count_consultas].data[b] < 2000 || lista_consulta[count_consultas].data[b] > 2025)){
				printf("Vish, esse ano nao e permitido. Digite novamente: ");
				scanf("%d", &lista_consulta[count_consultas].data[b]);
				getchar();
			}
		}
		printf("Descricao: ");
		fgets(lista_consulta[count_consultas].descricao, LETRAS, stdin);
		count_consultas++;
		system("pause");
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
					printf("NOME: %s",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d | %d | %d (%d ANOS)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
					printf("CONTATO: %s\nEMAIL: %s",lista_pacientes[a].fone, lista_pacientes[a].email);
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
					printf("NOME: %s",lista_profissionais[a].nome);
					Profissao(lista_profissionais[a].tipo_profissional);
					printf("NRP: %s", lista_profissionais[a].registro_profissional);
					printf("NASCIMENTO: %d | %d | %d (%d ANOS)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
					printf("CONTATO: %sEMAIL: %s\n", lista_profissionais[a].fone, lista_profissionais[a].email);
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
					printf("ATENDIMENTO: #%d em %d | %d | %d\n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
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
			Profissao(lista_profissionais[a].tipo_profissional);
			printf("----------------------------------------------------------------\n");
		}
	}
	for(a=0;a<=count_pacientes; a++){
		if(lista_pacientes[a].matricula == idC){
			printf("PACIENTE: %s",lista_pacientes[a].nome);
			printf("CPF: %s", lista_pacientes[a].cpf);
			printf("IDADE: %d\n", lista_pacientes[a].idade);
			printf("----------------------------------------------------------------\n");
		}
	}
}

void Editar(){
	int op, mat;
	char Alterar[LETRAS];
	system("cls");
	if (strcmp(choose, "PACIENTE") == 0){
		printf("---------------- EDITAR DADOS DO PACIENTE ------------------\n");
		printf("Digite a matricula do paciente: ");
		scanf("%d", &mat);
		getchar();
		for(a=0;a<=count_pacientes; a++){
			if(lista_pacientes[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
				printf("NOME: %s\n",lista_pacientes[a].nome);
				printf("NASCIMENTO: %d | %d | %d (%d)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				printf("CONTATO: \nCEL: %s\nEMAIL: %s\n",lista_pacientes[a].fone, lista_pacientes[a].email);
				printf("----------------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
			    printf("Qual campo deseja alterar (nome, data, fone, email, logradouro, numero, bairro, cidade, estado, cep) ou pressione ENTER/texto invalido para sair: ");
				do {
			    fgets(Alterar, LETRAS, stdin); 
			    Alterar[strcspn(Alterar, "\n")] = 0;
			    if (strcmp(Alterar, "nome") == 0 || strcmp(Alterar, "NOME") == 0 || strcmp(Alterar, "Nome") == 0) {
			        printf("Novo NOME: ");
			        fgets(lista_pacientes[a].nome, LETRAS, stdin);
			        strcpy(Alterar, "");
			    }else if (strcmp(Alterar, "data") == 0 || strcmp(Alterar, "DATA") == 0 || strcmp(Alterar, "Data") == 0 || strcmp(Alterar, "nascimento") == 0) {
			        printf("Nova Data de Nascimento (Dia Mes Ano, ex: 25 11 1990): ");
			        strcpy(Alterar, "");
					for (b = 0; b < 3; b++) {
			            scanf("%d", &lista_pacientes[a].birth[b]);
						if(a == 0 && (lista_pacientes[a].birth[b] <=0 || lista_pacientes[a].birth[b] > 31)){
							printf("Dia Inexistente! Digite novamente: ");
							scanf("%d", &lista_pacientes[a].birth[b]);
							getchar();
						}
						if(a == 1 && (lista_pacientes[a].birth[b] <=0 || lista_pacientes[a].birth[b] > 12)){
							printf("Mes Inexistente! Digite novamente: ");
							scanf("%d", &lista_pacientes[a].birth[b]);
							getchar();
						}
						if(a == 2 && (lista_pacientes[a].birth[b] < 1970 || lista_pacientes[a].birth[b] > 2003)){
							printf("Vish, esse ano nao e permitido. Digite novamente: ");
							scanf("%d", &lista_pacientes[a].birth[b]);
							getchar();
						}    
			        }
			        getchar();
			        if (lista_pacientes[a].birth[1] < 11 ){
			            lista_pacientes[a].idade = 2025 - lista_pacientes[a].birth[2];    
			        }else { 
			            lista_pacientes[a].idade = 2026 - lista_pacientes[a].birth[2]; 
			        }
			        printf("Idade recalculada: %d\n", lista_pacientes[a].idade);
				    }else if (strcmp(Alterar, "fone") == 0 || strcmp(Alterar, "FONE") == 0 || strcmp(Alterar, "contato") == 0) {
				        printf("Novo Fone: ");
				        fgets(lista_pacientes[a].fone, 20, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "email") == 0 || strcmp(Alterar, "EMAIL") == 0) {
				        printf("Novo Email: ");
				        fgets(lista_pacientes[a].email, LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "logradouro") == 0 || strcmp(Alterar, "LOGRADOURO") == 0) {
				        printf("Novo LOGRADOURO: ");
				        fgets(lista_pacientes[a].endereco[0], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "numero") == 0 || strcmp(Alterar, "NUMERO") == 0) {
				        printf("Novo NUMERO: ");
				        fgets(lista_pacientes[a].endereco[1], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "bairro") == 0 || strcmp(Alterar, "BAIRRO") == 0) {
				        printf("Novo BAIRRO: ");
				        fgets(lista_pacientes[a].endereco[2], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "cidade") == 0 || strcmp(Alterar, "CIDADE") == 0) {
				        printf("Nova CIDADE: ");
				        fgets(lista_pacientes[a].endereco[3], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "estado") == 0 || strcmp(Alterar, "ESTADO") == 0) {
				        printf("Novo ESTADO: ");
				        fgets(lista_pacientes[a].endereco[4], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else if (strcmp(Alterar, "cep") == 0 || strcmp(Alterar, "CEP") == 0) {
				        printf("Novo CEP: ");
				        fgets(lista_pacientes[a].endereco[5], LETRAS, stdin);
				        strcpy(Alterar, "");
				    }else {
				        // Se o usuário digitou algo (não vazio), avisa que é inválido
				        if (strlen(Alterar) > 0) {
				             printf("Opção de alteração inválida. Saindo do modo de alteração.\n");
				        }
				        // Se for vazio (pressionou ENTER), o loop encerra naturalmente.
				    }
				} while(strcmp(Alterar, "") != 0 );
			}
		}
		system("pause");
		Paciente();
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- EDITAR DADOS DO PROFISSIONAL ------------------\n");
		printf("Digite a matricula do profissional: ");
		scanf("%d", &mat);
		getchar();
		for(a=0;a<=count_profissionais; a++){
			if(lista_profissionais[a].matricula == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
				printf("NOME: %s",lista_profissionais[a].nome);
				printf("CPF: %s",lista_profissionais[a].cpf);
				Profissao(lista_profissionais[a].tipo_profissional);
				printf("NUMERO DE REGISTRO: %s",lista_profissionais[a].registro_profissional);
				printf("NASCIMENTO: %d | %d | %d (%d anos)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				printf("CONTATO: %s\nEMAIL: %s", lista_profissionais[a].fone, lista_profissionais[a].email);
				printf("----------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
				printf("Qual campo deseja alterar (nome, data, fone, email, profissao, registro) ou pressione ENTER/texto invalido para sair: ");
				do{
					fgets(Alterar, LETRAS, stdin);
			    	Alterar[strcspn(Alterar, "\n")] = 0;
				if (strcmp(Alterar, "nome") == 0 || strcmp(Alterar, "NOME") == 0 || strcmp(Alterar, "Nome") == 0) {
				    printf("Novo NOME: ");
				    fgets(lista_profissionais[a].nome, LETRAS, stdin);
				    strcpy(Alterar, "");
				}else if (strcmp(Alterar, "data") == 0 || strcmp(Alterar, "DATA") == 0 || strcmp(Alterar, "Data") == 0 || strcmp(Alterar, "nascimento") == 0) {
				    strcpy(Alterar, "");
				    printf("Nova Data de Nascimento (Dia Mes Ano, ex: 25 11 1990): ");
				    for(a=0; a<3; a++){
						scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
						getchar();
						if(a=0 && (lista_profissionais[count_profissionais].birth[a]<=0 || lista_profissionais[count_profissionais].birth[a] > 31)){
							printf("Dia Inexistente! Digite novamente: ");
							scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
							getchar();
						}
						if(a=1 && (lista_profissionais[count_profissionais].birth[a]<=0 || lista_profissionais[count_profissionais].birth[a] > 12)){
							printf("Mes Inexistente! Digite novamente: ");
							scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
							getchar();
						}
						if(a=2 && (lista_profissionais[count_profissionais].birth[a] < 1970 || lista_profissionais[count_profissionais].birth[a] > 2003)){
							printf("Vish, esse ano nao e permitido. Digite novamente: ");
							scanf("%d", &lista_profissionais[count_profissionais].birth[a]);
							getchar();
						}
					}	
					if(lista_profissionais[count_profissionais].birth[1] <= 11 ){
						lista_profissionais[count_profissionais].idade = 2025 - lista_profissionais[count_profissionais].birth[2];	
					}else if (lista_profissionais[count_profissionais].birth[1] > 11 ){
						lista_profissionais[count_profissionais].idade = 2026 - lista_profissionais[count_profissionais].birth[2];
					}
				    printf("Idade recalculada: %d\n", lista_profissionais[a].idade);
				}else if (strcmp(Alterar, "contato") == 0 || strcmp(Alterar, "CONTATO") == 0) {
				    strcpy(Alterar, "");
				    printf("Novo Fone: ");
				    fgets(lista_profissionais[a].fone, 20, stdin);
				}else if (strcmp(Alterar, "email") == 0 || strcmp(Alterar, "EMAIL") == 0) {
				    strcpy(Alterar, "");
				    printf("Novo Email: ");
				    fgets(lista_profissionais[a].email, LETRAS, stdin);
				}else if (strcmp(Alterar, "profissao") == 0 || strcmp(Alterar, "PROFISSÃO") == 0 || strcmp(Alterar, "tipo") == 0) {
				    strcpy(Alterar, "");
				    for (a=0; a<10; a++){
						printf("%d | %s\n", tprofissao[a].id, tprofissao[a].profissao);
					}
				    printf("Novo Tipo de Profissao (Digite o numero): ");
				    scanf("%d", &lista_profissionais[a].tipo_profissional);
				    getchar();
					Profissao(lista_profissionais[a].tipo_profissional);
				}else if (strcmp(Alterar, "registro") == 0 || strcmp(Alterar, "REGISTRO") == 0 || strcmp(Alterar, "nrp") == 0) {
				    strcpy(Alterar, "");
				    printf("Novo Numero de Registro Profissional (NRP): ");
				    fgets(lista_profissionais[a].registro_profissional, LETRAS, stdin);
				}else {
				    printf("Opção de alteração inválida. Tente 'nome', 'data', 'fone', 'email', 'profissao' ou 'registro'.\n");
				}
				} while(strcmp(Alterar, "") != 0 );
			}
		}
		system("pause");
		Profissional();
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- EDITAR DADOS DO ATENDIMENTOS --------------------\n");
		printf("Digite a identificacao do atendimento: ");
		scanf("%d", &mat);
		getchar();
		for(a=0;a<=count_consultas; a++){
			if(lista_consulta[a].id == mat){
				printf("---------------------- ANTIGO DADO -----------------------\n");
				printf("ATENDIMENTO: #%d em %d | %d | %d \n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
				printf("----------------------------------------------------------\n\n");
				printf("----------------------- NOVO DADO ------------------------\n");
				printf("Qual dado desejas alterar?\n\n1-paciente\n2-profissional\n3-descricao\n4-data\nEscolha: ");
				do{
					fgets(Alterar, LETRAS, stdin);
			    	Alterar[strcspn(Alterar, "\n")] = 0;
					if (strcmp(Alterar, "profissional") == 0 || strcmp(Alterar, "PROFISSIONAL") == 0 || strcmp(Alterar, "Profissional") == 0){
						printf("Matricula do Profissional Atendente: ");
						scanf("%d", &lista_consulta[count_consultas].dados_profissional);
						getchar();
					}else if (strcmp(Alterar, "profissional") == 0 || strcmp(Alterar, "PROFISSIONAL") == 0 || strcmp(Alterar, "Profissional") == 0){
						printf("Matricula do Paciente: ");
						scanf("%d", &lista_consulta[count_consultas].dados_paciente);
						getchar();break;
					}else if (strcmp(Alterar, "profissional") == 0 || strcmp(Alterar, "PROFISSIONAL") == 0 || strcmp(Alterar, "Profissional") == 0){
						printf("Descricao: ");
						fgets(lista_consulta[count_consultas].descricao, LETRAS, stdin);
					}
				}while(strcmp(Alterar, "") != 0 );
			} 
		}
		system("pause");
		Consultas();	
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
				printf("--------------------------- DADO ------------------------------\n");
				printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
				printf("NOME: %s",lista_pacientes[a].nome);
				printf("NASCIMENTO: %d | %d | %d (%d anos)", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				printf("\nCONTATO: %s\nEMAIL: %s",lista_pacientes[a].fone, lista_pacientes[a].email);
				printf("----------------------------------------------------------------\n\n");
				printf("CONTINUAR? 0 - Nao\t1 - Sim\n");
				scanf("%d", &resp);
				if(resp == 1){
					lista_pacientes[a].matricula = 0;
					ExPa++;
				}
			}
		}
		system("pause");
		Paciente();
	}else if (strcmp(choose, "PROFISSIONAL") == 0){
		printf("---------------- EXCLUIR DADOS DO PROFISSIONAL ------------------\n");
		printf("Digite a matricula do profissional: ");
		scanf("%d", &mat);
		for(a=0;a<=count_profissionais; a++){
			if(lista_profissionais[a].matricula == mat){
				printf("-------------------------- DADO --------------------------\n");
				printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
				printf("NOME: %s",lista_profissionais[a].nome);
				printf("CPF: %s",lista_profissionais[a].cpf);
				Profissao(lista_profissionais[a].tipo_profissional);
				printf("NUMERO DE REGISTRO: %s",lista_profissionais[a].registro_profissional);
				printf("NASCIMENTO: %d | %d | %d (%d anos)", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1],  lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				printf("\nCEL: %s\nEMAIL: %s", lista_profissionais[a].fone, lista_profissionais[a].email);
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
		system("pause");
		Profissional();
	}else if (strcmp(choose, "CONSULTAS") == 0){
		printf("---------------- EXCLUIR DADOS DA CONSULTA ----------------------\n");
		printf("Digite o codigo da consulta: ");
		scanf("%d", &mat);
		for(a=0;a<count_consultas; a++){
			if(lista_consulta[a].id == mat){
				printf("-------------------------- DADO --------------------------\n");
				printf("ATENDIMENTO: #%d em %d | %d | %d\n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
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
		system("pause");
		Consultas();
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
	if(op == 1){
		strcpy(choose1, "01");
		Apresentacao_Relatorios();
	}else if(op==2){
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
		getchar();
		printf("Agora, escolha, 'todos' (pacientes e profissionais) ou so 'pacientes': ");
		fgets(escolha, LETRAS, stdin);
		if (strcmp(escolha, "pacientes\n") == 0){
			for(a=0; a<count_pacientes;a++){
				if(m == lista_pacientes[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
					printf("NOME: %s",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d | %d | %d (%d anos)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				}
			}
		}else if(strcmp(escolha, "todos\n") == 0){
			for(a=0; a<count_pacientes;a++){
				if(m == lista_pacientes[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_pacientes[a].matricula);
					printf("NOME: %s",lista_pacientes[a].nome);
					printf("NASCIMENTO: %d | %d | %d (%d anos)\n", lista_pacientes[a].birth[0], lista_pacientes[a].birth[1], lista_pacientes[a].birth[2], lista_pacientes[a].idade);
				}
			}
			for(a=0; a<count_profissionais;a++){
				if(m == lista_profissionais[a].birth[1]){
					printf("----------------------------------------------------------------\n");
					printf("MATRICULA: %d | ",lista_profissionais[a].matricula);
					printf("NOME: %s",lista_profissionais[a].nome);
					Profissao(lista_profissionais[a].tipo_profissional);
					printf("NASCIMENTO: %d | %d | %d (%d anos)\n", lista_profissionais[a].birth[0], lista_profissionais[a].birth[1], lista_profissionais[a].birth[2], lista_profissionais[a].idade);
				}
			}
		}
		system("pause");
		Relatorios();
	}else if (strcmp(choose1, "02") == 0){
		printf("--------------------------- ATENDIMENTOS ---------------------------\n\n");
		printf("Digite a matricula do profissional em questao: ");
		scanf("%d", &m);
		getchar();
		for(a=0; a<count_consultas;a++){
			if(m == lista_consulta[a].dados_profissional){
				printf("----------------------------------------------------------------\n");
				printf("ATENDIMENTO: #%d em %d | %d | %d \n", lista_consulta[a].id, lista_consulta[a].data[0], lista_consulta[a].data[1], lista_consulta[a].data[2]);
				Encontra(lista_consulta[a].dados_profissional, lista_consulta[a].dados_paciente);
				printf("DESCRICAO: %s \n", lista_consulta[a].descricao);
			}
		}
		system("pause");
		Relatorios();
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
	Start();
	printf("\n\n\n---------------------------------------------------------------------------------------------------------------------\n\n\n\n\n");
	printf("                                     SISTEMA DE GERENCICAMENTO DE CONSULTAS");
	printf("\n\n\n\n\n---------------------------------------------------------------------------------------------------------------------\n\n\n\n\n");
	system("pause");
	system("cls");
	Menu();
	return 10;
}
