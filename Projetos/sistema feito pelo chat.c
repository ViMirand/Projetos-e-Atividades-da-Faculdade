#include<stdio.h>
#include<stdlib.h> // Para system("cls") e exit()
#include<string.h>
#include<locale.h>

// --- CONSTANTES ---
#define QTD 30      // Capacidade máxima de registros
#define LETRAS 50   // Tamanho padrão de strings para nome, email, etc.
#define ENDERECO_LINHAS 6 // Logradouro, Número, Bairro, Cidade, Estado, CEP

// --- STRUCTS (ENTIDADES) ---
// Estrutura base para Cliente e Profissional
struct pessoa{
	int idade, birth[3], matricula;
	char nome[LETRAS], cpf[20], email[LETRAS], endereco[ENDERECO_LINHAS][LETRAS], fone[20], celular[20];
	// Campos específicos de Profissional
	char registro_profissional[LETRAS], tipo_de_profissional[LETRAS], sigla[LETRAS]; 
};

struct consulta{
	int numero, Prof_matricula, Cliente_codigo; // Relações
	int data[3]; // dia, mes, ano
	char descricao[LETRAS*3];
};

typedef struct pessoa profissional;
typedef struct pessoa cliente; // Usaremos 'cliente' para consistência com o PDF
typedef struct consulta consulta;

// --- VARIÁVEIS GLOBAIS ---
int count_clientes = 0, count_profissionais = 0, count_consultas = 0, i, j;
cliente lista_clientes[QTD];
profissional lista_profissionais[QTD];
consulta lista_consulta[QTD];

// --- PROTÓTIPOS DE FUNÇÕES ---
void LimparBuffer();
void MenuPrincipal();
void MenuProfissionais();
void MenuClientes();
void MenuAtendimentos();
void MenuRelatorios();
void CadastrarProfissional();
void ListarProfissionais();
void CadastrarCliente();
void ListarClientes();
void CadastrarAtendimento();
void ListarAtendimentosGerais();

// --- IMPLEMENTAÇÕES DE FUNÇÕES DE UTILIDADE ---

// Função para limpar o buffer de entrada (essencial após scanf)
void LimparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para calcular a idade (simplificada)
void CalcularIdade(int dia, int mes, int ano, int *idade_ptr) {
    // Para 2025, o mês de corte é Novembro (11/2025) conforme seu código anterior
    if (mes < 11) {
        *idade_ptr = 2025 - ano;
    } else {
        *idade_ptr = 2026 - ano;
    }
}

// --- FUNÇÕES DE CADASTRO E MANUTENÇÃO ---

// Implementação do Cadastro de Profissional
void CadastrarProfissional(){
    if (count_profissionais >= QTD) {
        printf("\n?? ERRO: Limite de profissionais atingido.\n");
        return;
    }
    
    printf("\n----------- DADOS DO NOVO PROFISSIONAL -------------\n");
    profissional *p = &lista_profissionais[count_profissionais];
    
    // Matrícula
    p->matricula = count_profissionais + 1 + 202500;
    printf("MATRICULA: %d\n", p->matricula);

    // Nome
    printf("NOME COMPLETO: ");
    fgets(p->nome, LETRAS, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;

    // CPF
    printf("CPF: ");
    fgets(p->cpf, 20, stdin);
    p->cpf[strcspn(p->cpf, "\n")] = 0;

    // Data de Nascimento
    printf("Data de Nascimento (DD MM AAAA): ");
    if(scanf("%d %d %d", &p->birth[0], &p->birth[1], &p->birth[2]) != 3) {
        printf("?? Erro na leitura da data. Tente novamente.\n");
        LimparBuffer();
        return;
    }
    LimparBuffer();
    
    // Idade
    CalcularIdade(p->birth[0], p->birth[1], p->birth[2], &p->idade);
    printf("Idade Calculada: %d anos\n", p->idade);
    
    // Fone e Email
    printf("Fone: ");
    fgets(p->fone, 20, stdin);
    p->fone[strcspn(p->fone, "\n")] = 0;
    
    printf("Email: ");
    fgets(p->email, LETRAS, stdin);
    p->email[strcspn(p->email, "\n")] = 0;
    
    // Detalhes da Profissão
    printf("Tipo de Profissional (Medico, Enfermeiro, etc.): ");
    fgets(p->tipo_de_profissional, LETRAS, stdin);
    p->tipo_de_profissional[strcspn(p->tipo_de_profissional, "\n")] = 0;

    printf("Sigla do Conselho (CRM, COREN, etc.): ");
    fgets(p->sigla, LETRAS, stdin);
    p->sigla[strcspn(p->sigla, "\n")] = 0;
    
    printf("Numero de Registro Profissional (NRP): ");
    fgets(p->registro_profissional, LETRAS, stdin);
    p->registro_profissional[strcspn(p->registro_profissional, "\n")] = 0;

    count_profissionais++;
    printf("? Profissional cadastrado com sucesso! Retornando ao menu...\n");
}

// Implementação do Cadastro de Cliente (Paciente)
void CadastrarCliente(){
    if (count_clientes >= QTD) {
        printf("\n?? ERRO: Limite de clientes atingido.\n");
        return;
    }

    printf("\n----------- DADOS DO NOVO CLIENTE (PACIENTE) -------------\n");
    cliente *c = &lista_clientes[count_clientes];
    
    // Código (usando 'matricula' como 'codigo' do PDF)
    c->matricula = count_clientes + 1; // Código simples
    printf("CODIGO DO CLIENTE: %d\n", c->matricula);

    // Nome
    printf("NOME COMPLETO: ");
    fgets(c->nome, LETRAS, stdin);
    c->nome[strcspn(c->nome, "\n")] = 0;

    // Data de Nascimento
    printf("Data de Nascimento (DD MM AAAA): ");
    if(scanf("%d %d %d", &c->birth[0], &c->birth[1], &c->birth[2]) != 3) {
        printf("?? Erro na leitura da data. Tente novamente.\n");
        LimparBuffer();
        return;
    }
    LimparBuffer();
    
    // Idade
    CalcularIdade(c->birth[0], c->birth[1], c->birth[2], &c->idade);
    printf("Idade Calculada: %d anos\n", c->idade);
    
    // Contato
    printf("Fone Fixo: ");
    fgets(c->fone, 20, stdin);
    c->fone[strcspn(c->fone, "\n")] = 0;
    
    printf("Celular: ");
    fgets(c->celular, 20, stdin);
    c->celular[strcspn(c->celular, "\n")] = 0;

    printf("Email: ");
    fgets(c->email, LETRAS, stdin);
    c->email[strcspn(c->email, "\n")] = 0;
    
    // Endereço (6 campos)
    printf("--- ENDERECO ---\n");
    printf("Logradouro: "); fgets(c->endereco[0], LETRAS, stdin); c->endereco[0][strcspn(c->endereco[0], "\n")] = 0;
    printf("Numero: "); fgets(c->endereco[1], LETRAS, stdin); c->endereco[1][strcspn(c->endereco[1], "\n")] = 0;
    printf("Bairro: "); fgets(c->endereco[2], LETRAS, stdin); c->endereco[2][strcspn(c->endereco[2], "\n")] = 0;
    printf("Cidade: "); fgets(c->endereco[3], LETRAS, stdin); c->endereco[3][strcspn(c->endereco[3], "\n")] = 0;
    printf("Estado: "); fgets(c->endereco[4], LETRAS, stdin); c->endereco[4][strcspn(c->endereco[4], "\n")] = 0;
    printf("CEP: "); fgets(c->endereco[5], LETRAS, stdin); c->endereco[5][strcspn(c->endereco[5], "\n")] = 0;

    count_clientes++;
    printf("? Cliente cadastrado com sucesso! Retornando ao menu...\n");
}

// Implementação simples de Inserir Atendimento
void CadastrarAtendimento() {
    if (count_consultas >= QTD) {
        printf("\n?? ERRO: Limite de atendimentos atingido.\n");
        return;
    }

    printf("\n----------- NOVO ATENDIMENTO -------------\n");
    consulta *c = &lista_consulta[count_consultas];
    
    // Número do atendimento
    c->numero = count_consultas + 1;
    printf("NUMERO DO ATENDIMENTO: %d\n", c->numero);

    // Seleção (simplificada - apenas leitura da chave)
    printf("Matricula do Profissional Atendente: ");
    if(scanf("%d", &c->Prof_matricula) != 1) { LimparBuffer(); printf("Entrada invalida.\n"); return; }
    LimparBuffer();

    printf("Codigo do Cliente Atendido: ");
    if(scanf("%d", &c->Cliente_codigo) != 1) { LimparBuffer(); printf("Entrada invalida.\n"); return; }
    LimparBuffer();

    // Data
    printf("Data do Atendimento (DD MM AAAA): ");
    if(scanf("%d %d %d", &c->data[0], &c->data[1], &c->data[2]) != 3) {
        printf("?? Erro na leitura da data.\n");
        LimparBuffer();
        return;
    }
    LimparBuffer();
    
    // Descrição
    printf("Descricao do Atendimento:\n");
    fgets(c->descricao, LETRAS*3, stdin);
    c->descricao[strcspn(c->descricao, "\n")] = 0;
    
    count_consultas++;
    printf("? Atendimento registrado com sucesso!\n");
}


// --- FUNÇÕES DE LISTAGEM/RELATÓRIOS ---

void ListarProfissionais(){
    if (count_profissionais == 0) {
        printf("\nNenhum profissional cadastrado.\n");
        return;
    }
    printf("\n----------- LISTAGEM DE PROFISSIONAIS (%d Registros) -------------\n", count_profissionais);
    for ( i = 0; i < count_profissionais; i++) {
        profissional p = lista_profissionais[i];
        printf("---------------------------------------------------\n");
        printf("Matricula: %d | Nome: %s\n", p.matricula, p.nome);
        printf("Profissao: %s (%s - %s)\n", p.tipo_de_profissional, p.sigla, p.registro_profissional);
        printf("Nascimento: %d/%d/%d (Idade: %d)\n", p.birth[0], p.birth[1], p.birth[2], p.idade);
        printf("Contato: Fone: %s | Email: %s\n", p.fone, p.email);
    }
    printf("---------------------------------------------------\n");
}

void ListarClientes(){
    if (count_clientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }
    printf("\n----------- LISTAGEM DE CLIENTES (%d Registros) -------------\n", count_clientes);
    for (i = 0; i < count_clientes; i++) {
        cliente c = lista_clientes[i];
        printf("---------------------------------------------------\n");
        printf("Codigo: %d | Nome: %s\n", c.matricula, c.nome);
        printf("Nascimento: %d/%d/%d (Idade: %d)\n", c.birth[0], c.birth[1], c.birth[2], c.idade);
        printf("Contato: Cel: %s | Email: %s\n", c.celular, c.email);
    }
    printf("---------------------------------------------------\n");
}

// Uma implementação simples de um relatório (Atendimento Geral)
void ListarAtendimentosGerais() {
    if (count_consultas == 0) {
        printf("\nNenhum atendimento registrado.\n");
        return;
    }
    printf("\n----------- RELATORIO DE ATENDIMENTOS GERAIS (%d Registros) -------------\n", count_consultas);
    for (i = 0; i < count_consultas; i++) {
        consulta c = lista_consulta[i];
        printf("---------------------------------------------------\n");
        printf("Atendimento #%d em %d/%d/%d\n", c.numero, c.data[0], c.data[1], c.data[2]);
        printf("Profissional (Mat.): %d | Cliente (Cod.): %d\n", c.Prof_matricula, c.Cliente_codigo);
        printf("Descricao: %.50s...\n", c.descricao); // Limita a descrição para a lista
    }
    printf("---------------------------------------------------\n");
}

// --- FUNÇÕES DE MENU ---

void MenuProfissionais(){
    int op;
    do {
        system("cls"); // Limpa a tela
        printf("----------- MENU PROFISSIONAIS -------------\n\n");
        printf("1 - Cadastrar Novo Profissional\n");
        printf("2 - Listar Profissionais\n");
        printf("3 - [Em Construcao] Editar Profissional\n");
        printf("4 - [Em Construcao] Excluir Profissional\n");
        printf("5 - Retornar ao Menu Principal\n");
        printf("-------------------------------------------\n");
        printf("Escolha: ");
        
        if(scanf("%d", &op) != 1) { LimparBuffer(); op = 0; continue; }
        LimparBuffer(); // Limpa o buffer após scanf

        switch (op) {
            case 1: CadastrarProfissional(); break;
            case 2: ListarProfissionais(); system("pause"); break;
            case 3: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 4: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 5: return; 
            default: printf("\nOpcao invalida. Tente novamente.\n"); system("pause");
        }
    } while(op != 5);
}

void MenuClientes(){
    int op;
    do {
        system("cls"); // Limpa a tela
        printf("----------- MENU CLIENTES (PACIENTES) -------------\n\n");
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - [Em Construcao] Editar Cliente\n");
        printf("4 - [Em Construcao] Excluir Cliente\n");
        printf("5 - Retornar ao Menu Principal\n");
        printf("-------------------------------------------------\n");
        printf("Escolha: ");
        
        if(scanf("%d", &op) != 1) { LimparBuffer(); op = 0; continue; }
        LimparBuffer(); // Limpa o buffer após scanf

        switch (op) {
            case 1: CadastrarCliente(); break;
            case 2: ListarClientes(); system("pause"); break;
            case 3: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 4: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 5: return;
            default: printf("\nOpcao invalida. Tente novamente.\n"); system("pause");
        }
    } while(op != 5);
}

void MenuAtendimentos() {
    int op;
    do {
        system("cls");
        printf("----------- MENU ATENDIMENTOS -------------\n\n");
        printf("1 - Inserir Novo Atendimento\n");
        printf("2 - Listar Atendimentos Gerais\n");
        printf("3 - [Em Construcao] Editar Atendimento\n");
        printf("4 - [Em Construcao] Excluir Atendimento\n");
        printf("5 - Retornar ao Menu Principal\n");
        printf("-------------------------------------------\n");
        printf("Escolha: ");
        
        if(scanf("%d", &op) != 1) { LimparBuffer(); op = 0; continue; }
        LimparBuffer();

        switch (op) {
            case 1: CadastrarAtendimento(); break;
            case 2: ListarAtendimentosGerais(); system("pause"); break;
            case 3: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 4: printf("\nOpcao em desenvolvimento.\n"); system("pause"); break;
            case 5: return;
            default: printf("\nOpcao invalida. Tente novamente.\n"); system("pause");
        }
    } while(op != 5);
}

void MenuRelatorios() {
    // Apenas um placeholder para o Menu de Relatórios mais complexos
    system("cls");
    printf("----------- MENU RELATORIOS -------------\n\n");
    printf("Relatorios de Aniversariantes e Estatisticas serao implementados aqui.\n");
    printf("Pressione qualquer tecla para voltar...\n");
    system("pause");
    return;
}

void MenuPrincipal(){
	int op;
    do {
        system("cls"); // Limpa a tela (Windows)
        printf("----------- SISTEMA DE GERENCIAMENTO DE SAUDE IFAM 2025 -----------\n\n");
        printf("1 - Gerenciar Profissionais de Saude\n");
        printf("2 - Gerenciar Clientes (Pacientes)\n");
        printf("3 - Gerenciar Atendimentos (Consultas)\n");
        printf("4 - Relatorios (Aniversariantes, Estatisticas)\n");
        printf("5 - Sair\n\n");
        printf("-------------------------------------------------------------------\n");
        printf("Escolha: ");
        
        if(scanf("%d", &op) != 1) { // Verifica se a leitura foi bem-sucedida
            LimparBuffer(); // Limpa se for falha
            op = 0; // Define op como 0 para forçar o default
            continue; // Volta para o início do loop
        }
        LimparBuffer(); // Limpa o buffer após o scanf

        switch (op) {
            case 1: MenuProfissionais(); break;
            case 2: MenuClientes(); break;
            case 3: MenuAtendimentos(); break;
            case 4: MenuRelatorios(); break;
            case 5: printf("\nSaindo do sistema. Tchau!\n"); break;
            default: printf("\nOpcao invalida. Pressione qualquer tecla para tentar novamente.\n"); system("pause");
        }
    } while(op != 5);
}

// --- FUNÇÃO MAIN ---

int main(){
	// Define a localização para Português (para acentuação)
	setlocale(LC_ALL, "pt-br"); 
	
    // Nota: O sistema trabalha em Memória Principal (RAM) [cite: 28]
	MenuPrincipal();
	
	return 0; // Retorna 0 para indicar sucesso
}
