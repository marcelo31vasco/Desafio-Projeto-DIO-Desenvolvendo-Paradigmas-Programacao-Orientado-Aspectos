#include<stdio.h>
#include<stdlib.h>


struct Conta {
    float saldo;
};

void deposito(struct Conta *conta, float valor) {
    conta->saldo += valor;
}

void sacar(struct Conta *conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        
        printf("\n Seu saque foi realizado com sucesso!\n");
    
    } else {
    	
        printf("\n Seu saldo eh insuficiente!\n");
    }
}

void exibirExtrato(struct Conta *conta, const char *tipoConta) {
    printf("\n Extrato detalhado de sua da Conta %s: %.2f\n", tipoConta, conta->saldo);
    if (conta->saldo > 0) {
        printf("\n Saldo Positivo \n");
    } else {
        printf("\n Sem saldo disponivel \n");
    }
}

int main() {
    struct Conta corrente, poupanca, salario;

    corrente.saldo = 0.0;
    poupanca.saldo = 0.0;
    salario.saldo = 0.0;

    deposito(&corrente, 0.00);
    deposito(&poupanca, 5500.00);
    deposito(&salario, 2752.00);

    exibirExtrato(&corrente, "Corrente");
    exibirExtrato(&poupanca, "Poupanca");
    exibirExtrato(&salario, "Salario");

    int opcaoConta;

	do {
	
	printf("\n Escolha qual a conta desejar realizar o saque:\n");
    printf("1 - Conta Corrente\n");
    printf("2 - Conta Poupanca\n");
    printf("3 - Conta Salario\n");
    printf("4 - Sair da sua conta \n");
    scanf("%d", &opcaoConta);

    if (opcaoConta == 4) {
        break;
    }


    float valorSaque;
    printf("Digite o valor que deseja sacar: ");
    scanf("%f", &valorSaque);

    switch (opcaoConta) {
        case 1:
            sacar(&corrente, valorSaque);
            break;
        case 2:
            sacar(&poupanca, valorSaque);
            break;
        case 3:
            sacar(&salario, valorSaque);
            break;
        default:
            printf("\n Operacao invalida \n");
    }

    exibirExtrato(&corrente, "Corrente");
    exibirExtrato(&poupanca, "Poupanca");
    exibirExtrato(&salario, "Salario");

	} while (1); 

    return 0;
}