#include <stdio.h> //blblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
int registro() //Função responsável por cadastrar novos usuários
{
	//Início da criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf(" digita o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //resonsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informações do usuário
	scanf("%s", nome);// %s refere-se ao salvar uma string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200, file )!= NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
}


int main()
	{
			
	int opcao=0;//definindo variáveis
	int laco=0;
	
	for(laco=1;laco=1;)
	{ 
	
	system("cls");//Responsável por limpar a tela
		
				
	
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	
	printf("###Cartório da EBAC###\n\n");//Inicio do menu
	printf(" Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("opção:");//Fim do menu
	
	scanf("%d", &opcao);//Armazenando a escolha do usuário
	
	system("cls");//Responsável por limpar a tela
	
		switch(opcao)//Inicio da seleção do menu
		{
			case 1:
			registro();//Chamada de funções 
			break;
		
			case 2:
			consultar();
		    break;
		    
		    case 3:
		    deletar();
			break;
			
			default:
			printf("essa opção não está disponivel \n");
			system("pause");
			break;	
		}//Fim da seleção
	}	
}

	
	
	
	
	
	

