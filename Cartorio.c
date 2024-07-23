#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastras os usuários no sistema
{
	// início da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação de variáveis/strings
    
    printf("Digite o CPF a ser cadastrado:  "); //coletando informação do usuário
    scanf("%s",cpf); // %s refere-se a string
		
	strcpy(arquivo,cpf); // Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma vírgula
	fclose(file); //fecha o arquivo

	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file, nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para gravação. O "a"significa acrescentar
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); // NÃO CONSEGUI FAZER A IDENTIFICAÇÃO ESTE CAMPO. POR FAVOR ME INDIQUE NA CORREÇÃO  
}

int consulta() // Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem	

	// início da ceiação de variáveis/string	
    char cpf[40];
    char conteudo[200];
    // final da criação de variáveis/strings
		
	printf ("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "R" significa LER
	
	if(file==NULL) // Função responsável por mostrar que o usuário não está cadastrado no sistema
	{
		printf("Não foi possível abrir o arquivo, não localizado. \n"); //mensagem para o usuário
	}	
	
	while(fgets(conteudo, 200, file) !=NULL) // Função responsável por mostrar que o usuário caso esteja cadastrado no sistema
	{
		printf("\n Essas são as informações do usuário: "); //mostra informação do usuário cadastrado no sistema
		printf ("%s", conteudo); // %s refere-se a string
		printf("\n\n"); // dá espaço entre as linhas no sistema
	}
	fclose(file); //fecha o arquivo
	system("pause"); // NÃO CONSEGUI FAZER A IDENTIFICAÇÃO ESTE CAMPO. POR FAVOR ME INDIQUE NA CORREÇÃO  
	
		}

int deletar() // Função responsável por deletar os usuários no sistema
{
	// início da criação de variáveis/string
	char cpf[40];
	// fim da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); // %s refere-se a string
		
	remove(cpf); // remove o usuário do sistema
		
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "R" significa LER
	
	if (file == NULL) // Função responsável por mostrar ao usuário caso o usuário tenha sido detelado do sistema
	{
		printf("O usuário foi deletado e não se encontra mais no sistema! \n"); //mensagem para o usuário
		system("pause"); // NÃO CONSEGUI FAZER A IDENTIFICAÇÃO ESTE CAMPO. POR FAVOR ME INDIQUE NA CORREÇÃO  
	}
	
	fclose(file);  //fecha o arquivo
}

int main () // Função principal do sistema
{
	// início da criação de variáveis/string
	int opcao=0; //Definindo variáveis
	int x=1;
	// fim da criação de variáveis/string
	
	for(x=1;x=1;)
	{
	
		system("cls"); // responsável por limpar a tela do sistema
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem	
			
		printf("### Cartório da EBAC### \n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf ("%d", &opcao); //armazanendo a escolha do usuário
	
		system("cls"); // responsáel por limpar a tela
		
		switch(opcao) // início da seleção do menu
		{
			case 1: 
			registro(); // chamada de funções
	 		break;
	 		
	 		case 2:
			consulta(); // chamada de funções
	 		break;
	 		
	 		case 3:
			deletar(); // chamada de funções
	 		break;

	 		default:
	 		printf("Essa opção não está disponível!\n"); //mensagem para o usuário
			system("pause");
	 		break;
 		
		} //fim da operação
	}
}
