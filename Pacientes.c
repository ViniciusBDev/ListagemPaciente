#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int registro() //Função responsavel por cadastrar os pacientes 
{
	// inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("digite o cpf a ser cadastrado: "); //coletando informaçâo dos paciente
	scanf("%s", cpf);//%s refere-se a string(salvando a string)
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores do aquivo
	
	FILE *file;//cria o arquino 	
	file = fopen(arquivo, "w");//cria o arquivo eo w significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o aquivo 
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file, ",");//","refere-se a divisão entre as inf do paciente
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);//%s refere-se a string(salvando a string)
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file, ",");//","refere-se a divisão entre as inf do paciente
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//%s refere-se a string(salvando a string
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file, ",");//","refere-se a divisão entre as inf do paciente
	fclose(file);
	
	printf("Digite o cardo a ser cadastrado: ");
	scanf("%s", cargo);//%s refere-se a string(salvando a string)
	
	file = fopen(arquivo, "a");// "a" para salvar dentro do arquivo
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);//%s refere-se a string(salvando a string)
	
	FILE *file;
	file = fopen(cpf,"r");//"r"função dada para ler o arquivo aberto
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informaçoes do usuario:");
		printf("%s", conteudo);//%s refere-se a string(salvando a string)
		printf("\n\n");// \n para pular linha
		
	}
	system("pause");//"pause" para parar a mesma tela para que o usuario consiga ler
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string(salvando a string)
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r"função dada para ler o arquivo aberto
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema! \n");
		system("pause");//"pause" para parar a mesma tela para que o usuario consiga ler
		
	}
}

int main()
	{
	 	int opcao=0; //Definindo variaveis
		 int laco=1;
  	
	 	for(laco=1;laco=1;)
 		{
      	 
  			system("cls");//responsalvel por limpar a tela
 					
    		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    	
 			printf("### Pacientes em tratamento ###\n\n"); //Inicio do menu
  			printf("Escolha a opção desejada do menu:\n\n");
  			printf("\t1 - Registrar nomes\n");
 			printf("\t2 - Consultar nomes\n");
 			printf("\t3 - Deletar nomes\n\n"); 
 			printf("\t4 - Sair do sistema\n\n");
 			printf("Opção: ");//fim do menu
	 
 			scanf("%d", &opcao);
 	
 			system("cls");//responsalvel por limpar a tela
	 
			switch(opcao)
 			{
				case 1:
				registro();
				break;
					
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por ultilizar o sistema!\n");
				return 0;
				break;
			
				default:
	 			printf("Essa opcao nao esta disponivel!\n");
				system("pause");//"pause" para parar a mesma tela para que o usuario consiga ler
				break;
   			}  //fim da seleção
	  	}
	}
