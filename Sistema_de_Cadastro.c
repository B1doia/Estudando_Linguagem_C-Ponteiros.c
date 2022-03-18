#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef struct enderecoStruct
  
{
char rua[40];
char bairro[30];
char numero[6];
char cep[8];
char cidade[20];
char estado[20];
} Endereco;

typedef struct CadastroPessoaStruct
{
char nome[40];
char reg[12];
char rg[10];
char telefone[11];
Endereco end;
} Pessoa;

int input = 0;
int qtdClientes;
int tamClientes;
Pessoa *clientes;
FILE *arquivo;
char clientes_dir[] = "Clientes.bin";


void menuPrincipal();
void menuClientes();
void menuAlterarCliente();
void removerQuebraLinha();
Pessoa receberCliente();
Endereco receberEndereco();
void inserirCliente();
Pessoa *buscarCliente();
void alterarEndereco();
void alterarNomeCliente();
void alterarTelefoneCliente();
int removerCliente();
void listarClientes();


int main(int argc, char** argv)
  
{
    menuPrincipal();
    return 0;
}

void erro(char *nome_arquivo)
  
{
    printf("Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

void sucesso()
  
{
    system("cls");
    printf ("Operacao realizada com sucesso!");
}

void menuPrincipal()
  
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  H&R GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|\t 1 - Cliente          |\n");
        printf("\t\t\t|\t 2 - Consoles         |\n");
        printf("\t\t\t|\t 3 - Jogos            |\n");
        printf("\t\t\t|\t 4 - Vendas           |\n");
        printf("\t\t\t|\t 0 - Sair             |\n");
        printf ("\t\t\t|\t                      |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void menuClientes()
  
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  H&R GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Listar Clientes      |\n");
        printf("\t\t\t|    2 - Buscar Cliente       |\n");
        printf("\t\t\t|    3 - Cadastrar Cliente    |\n");
        printf("\t\t\t|    4 - Alterar Cadastro     |\n");
        printf("\t\t\t|    5 - Excluir Cadastro     |\n");
        printf("\t\t\t|    6 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf ("\t\t\t|                             |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            listarClientes();
            break;
        case 2:
            buscarCliente();
            break;
        case 3:
            fflush(stdin);
            inserirCliente(receberCliente());
            break;
        case 4:
            menuAlterarCliente();
            break;
        case 5:
            removerCliente(qtdClientes, clientes_dir);
            break;
        case 6:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void menuAlterarCliente()
  
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  H&R GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Alterar Nome         |\n");
        printf("\t\t\t|    2 - Alterar Telefone     |\n");
        printf("\t\t\t|    3 - Alterar Endereco     |\n");
        printf("\t\t\t|    4 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf ("\t\t\t|                             |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            alterarNomeCliente();
            break;
        case 2:
            alterarTelefoneCliente();
            break;
        case 3:
            alterarEndereco();
            break;
        case 4:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void removerQuebraLinha(char *string)
  
{
    if(string != NULL && strlen(string) > 0)
    {
        short tamanho = strlen(string);
        if(string[tamanho-1] == '\n')
        {
            string[tamanho-1] = '\0';
        }
    }
}

void receberString(char *string_destino, int quantidade_caracteres)
  
{
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

Pessoa receberCliente()
{
    Pessoa p;

    printf("Nome: ");
    receberString(p.nome, 39);
    printf ("CPF: ");
    receberString(p.reg, 13);
    fflush(stdin);
    printf ("RG: ");
    receberString(p.rg, 11);
    fflush(stdin);
    printf ("Telefone: ");
    receberString(p.telefone, 12);
    fflush(stdin);

    p.end = receberEndereco();

    sucesso();
    return p;
}

Endereco receberEndereco()
{
    Endereco e;

    printf ("Rua: ");
    receberString(e.rua, 39);
    fflush(stdin);
    printf ("Numero: ");
    receberString(e.numero, 5);
    fflush(stdin);
    printf ("CEP: ");
    receberString(e.cep, 9);
    fflush(stdin);
    printf ("Bairro: ");
    receberString(e.bairro, 29);
    printf ("Cidade: ");
    receberString(e.cidade, 20);
    printf ("Estado: ");
    receberString(e.estado, 20);

    sucesso();
    return e;
}

void inserirCliente(Pessoa p)
  
{
    if(qtdClientes == tamClientes)
    {
        tamClientes *= 1.5;
        clientes = realloc(clientes, tamClientes*sizeof(Pessoa));
    }
    clientes[qtdClientes] = p;
    qtdClientes++;
}    

void listarClientes()
  
{
    int c;
  
    printf("\nListando %d clientes cadastrados\n", qtdClientes);
  
    for(c=0; c < qtdClientes; c++)
    {
        printf("-----------------------------------\n");
        printf("(%d)\n", c+1);
        printf("Nome  = %s\n", clientes[c].nome);
        printf("CPF = %s\n", clientes[c].reg);
        printf("RG = %s\n", clientes[c].rg);
        printf("Telefone = %s\n", clientes[c].telefone);
        printf("Endereco = %s", clientes[c].end.rua);
        printf(" - %s,", clientes[c].end.numero);
        printf(" %s,", clientes[c].end.bairro);
        printf(" %s", clientes[c].end.cidade);
        printf(" - %s.", clientes[c].end.estado);
    }
}

void alterarNomeCliente()
  
{
    int i;
    char cpf[11], nome[40];
  
    printf ("Digite o CPF do cliente a ter o nome alterado: ");
    fgets(cpf, 11, stdin);
    printf ("Digite o novo nome: ");
    fgets(nome, 39, stdin);
  
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].reg, cpf) == 0)
        {
            strcpy(clientes[i].nome, nome);
            break;
        }
    }
}

void alterarTelefoneCliente()
  
{
    int i;
    char cpf[11], fone[11];
  
    printf ("Digite o CPF do cliente a ter o telefone alterado: ");
    fgets(cpf, 11, stdin);
    printf ("Digite o novo numero: ");
    fgets(fone, 11, stdin);
  
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].reg, cpf) == 0)
        {
            strcpy(clientes[i].telefone, fone);
            break;
        }
    }
}


void alterarEndereco()
  
{
    int i;
    char cpf[12];
  
    printf ("Digite o CPF do cliente a ter o endereco alterado: ");
    fgets(cpf, 11, stdin);
    Endereco e;
    e = receberEndereco();
  
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].reg, cpf) == 0)
        {
            clientes[i].end = e;
            break;
        }
    }
}

Pessoa *buscarCliente()
  
{
    Pessoa *p = NULL;
    int i;
    char cpf[12];
    printf ("Digite o CPF do cliente a ser buscado: ");
    fgets(cpf, 11, stdin);
  
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].reg, cpf) == 0)
        {
            p = &clientes[i];    
            break;
        }
    }
    return p;
}

int removerCliente(int qtd, char *dir)
  
{
  
int i, CPF, sucess = 0;
printf("Digite o CPF do cliente que deseja remover: ");
scanf ("%d", &CPF);
  
for (i=0; i < qtd; i++)
{
    if((clientes[i].reg - CPF) == 0)
    {
        while(i < qtd-1)
        {
            clientes[i] = clientes[i+1];
            i++;
        }
        qtd--;
        sucess = 1;
        break;
    }
    else
    {
        erro(dir);
    }
}
return sucess;
}
