#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastras os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da cria��o de vari�veis/strings
    
    printf("Digite o CPF a ser cadastrado:  "); //coletando informa��o do usu�rio
    scanf("%s",cpf); // %s refere-se a string
		
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma v�rgula
	fclose(file); //fecha o arquivo

	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file,","); //salva o arquivo com o acrescimo de uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para grava��o. O "a"significa acrescentar
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); // N�O CONSEGUI FAZER A IDENTIFICA��O ESTE CAMPO. POR FAVOR ME INDIQUE NA CORRE��O  
}

int consulta() // Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem	

	// in�cio da ceia��o de vari�veis/string	
    char cpf[40];
    char conteudo[200];
    // final da cria��o de vari�veis/strings
		
	printf ("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "R" significa LER
	
	if(file==NULL) // Fun��o respons�vel por mostrar que o usu�rio n�o est� cadastrado no sistema
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n"); //mensagem para o usu�rio
	}	
	
	while(fgets(conteudo, 200, file) !=NULL) // Fun��o respons�vel por mostrar que o usu�rio caso esteja cadastrado no sistema
	{
		printf("\n Essas s�o as informa��es do usu�rio: "); //mostra informa��o do usu�rio cadastrado no sistema
		printf ("%s", conteudo); // %s refere-se a string
		printf("\n\n"); // d� espa�o entre as linhas no sistema
	}
	fclose(file); //fecha o arquivo
	system("pause"); // N�O CONSEGUI FAZER A IDENTIFICA��O ESTE CAMPO. POR FAVOR ME INDIQUE NA CORRE��O  
	
		}

int deletar() // Fun��o respons�vel por deletar os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char cpf[40];
	// fim da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); // %s refere-se a string
		
	remove(cpf); // remove o usu�rio do sistema
		
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "R" significa LER
	
	if (file == NULL) // Fun��o respons�vel por mostrar ao usu�rio caso o usu�rio tenha sido detelado do sistema
	{
		printf("O usu�rio foi deletado e n�o se encontra mais no sistema! \n"); //mensagem para o usu�rio
		system("pause"); // N�O CONSEGUI FAZER A IDENTIFICA��O ESTE CAMPO. POR FAVOR ME INDIQUE NA CORRE��O  
	}
	
	fclose(file);  //fecha o arquivo
}

int main () // Fun��o principal do sistema
{
	// in�cio da cria��o de vari�veis/string
	int opcao=0; //Definindo vari�veis
	int x=1;
	// fim da cria��o de vari�veis/string
	
	for(x=1;x=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela do sistema
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem	
			
		printf("### Cart�rio da EBAC### \n\n");//Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf ("%d", &opcao); //armazanendo a escolha do usu�rio
	
		system("cls"); // respons�el por limpar a tela
		
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1: 
			registro(); // chamada de fun��es
	 		break;
	 		
	 		case 2:
			consulta(); // chamada de fun��es
	 		break;
	 		
	 		case 3:
			deletar(); // chamada de fun��es
	 		break;

	 		default:
	 		printf("Essa op��o n�o est� dispon�vel!\n"); //mensagem para o usu�rio
			system("pause");
	 		break;
 		
		} //fim da opera��o
	}
}
