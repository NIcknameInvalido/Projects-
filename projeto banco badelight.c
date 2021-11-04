//BANCO BADENLIGHT

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Banco {
	char *nome;
	int numeroConta;
	int saldo;
} Banco;

Banco iniciaBanco();
void depositar();
void limpaTela();
void sacar();
void imprimirSaldo();

int main(){
	int opcao = 1;
	Banco banco;
	char nome[100];
	int numeroDaConta;
	int valor;
	
	printf("Vamos abri sua conta :) \n");
	printf("Qual o seu Primeiro nome?: ");
	scanf("%s", &nome);
	numeroDaConta = rand() % 100;
	limpaTela();
	
	banco = iniciaBanco(nome, banco);
	
	while(opcao != 0){
		opcao = menu();
		
		switch(opcao){
			case 1:
				limpaTela();
				imprimirSaldo(&banco);
				
				printf("\n\nDeseja Realizar outra operacao? 0 para nao, 1 para sim: ");
				scanf("%d", &opcao);
			break;
			
			case 2:
				limpaTela();	
				printf("Quanto deseja depositar?: ");
				scanf("%d", &valor);
				depositar(valor, &banco);
				printf("\n\nDeseja Realizar outra operacao? 0 para nao, 1 para sim: ");
				scanf("%d", &opcao);
			break;
			
			case 3:
				limpaTela();
				printf("Quanto deseja sacar?: ");
				scanf("%d", &valor);
				sacar(valor, &banco);
				printf("\n\nDeseja Realizar outra operacao? 0 para nao, 1 para sim: ");
				scanf("%d", &opcao);
			break;
			
			case 0:
				opcao = 0;
				exit(0);
			break;
			
			default:
				printf("Opcao Invalida");
				printf("\n\nDeseja Realizar outra operacao? 0 para nao, 1 para sim: ");
				scanf("%d", &opcao);
			break;
			
		}
		limpaTela();
	}
}

int menu(){
	int opcao = 1;
	
	printf("\n|-----Seja bem vindo ao banco badelight-----|\n");
	printf("\n|         1 - Consulta de saldo:            |");
	printf("\n|         2 - Deposito:                     |");
	printf("\n|         3 - Saque:                        |");
	printf("\n|         0 - Sair:                         |");
	printf("\n|-------------------------------------------|\n");
	printf("\nSelecione uma opcao: ");
	scanf("%d", &opcao);
		
	return opcao;
	
}

Banco iniciaBanco(char nome[200], Banco banco, int numeroDaConta){
	banco.nome = nome;
	banco.saldo = 0;
	banco.numeroConta = numeroDaConta;
	return banco;
}

void limpaTela(){
	system("cls");
}

void depositar(int valor, Banco *banco){
	if(valor > 0){
		banco->saldo += valor;
		printf("Deposito realizado com sucesso\n");
	}else{
		printf("Valor invalido :( \n");
	}
}

void sacar(int valor, Banco *banco){
	
	if(banco->saldo > 0 && banco->saldo >= valor){
		banco->saldo -= valor;
		printf("Saque realizado com sucesso\n");
	}else{
		printf("Nao ha saldo suficiente :( \n");
	}
}

void imprimirSaldo(Banco *banco){
	if(banco->saldo > 0){
		printf("%c, Este é seu saldo atual: %dR$\n", banco->nome, banco->saldo);
	}else{
		printf("%s, seu saldo esta zerado \n", banco->nome, banco->saldo);
	}
}

