#include <stdio.h>
#include <stdbool.h>

// Estrutura que representa uma conta bancária e suas funcionalidades básicas

typedef struct {
    char tipo[20];
    double saldo;
} ContaBancaria;

// Função para solicitar um saque em uma conta bancária

bool sacar(ContaBancaria* conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return true;
    } else {
        return false;
    }
}

// Função para exibir o extrato da conta

void exibirExtrato(ContaBancaria* contas, int numContas) {
    printf("\n Extrato das contas:\n");
    for (int i = 0; i < numContas; i++) {
        printf("%s: R$%.2f reais\n", contas[i].tipo, contas[i].saldo);
    }
}

int main() {
    // Criação das contas bancárias
    ContaBancaria contas[3];
    sprintf(contas[0].tipo, "Corrente");
    contas[0].saldo = 1212.60;
    sprintf(contas[1].tipo, "Salario");
    contas[1].saldo = 2752.33;
    sprintf(contas[2].tipo, "Poupanca");
    contas[2].saldo = 1050.35;

    while (true) {
       
        int opcao;
        printf("\n Escolha uma opcao: \n");
        printf("1. Realizar Saque \n");
        printf("2. Exibir Extrato \n");
        printf("3. Sair \n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Opções de conta
            int numConta;
            printf("\n Escolha a conta para realizar o saque: \n");
            printf("1. Conta Corrente\n");
            printf("2. Conta Salario\n");
            printf("3. Conta Poupanca\n");
            scanf("%d", &numConta);

            // Valor do saque
            double valorSaque;
            printf("Digite o valor que deseja sacar: ");
            scanf("%lf", &valorSaque);
            // Verifica se tem saldo na conta escolhida            
            bool saldoSuficiente = false;
            if (numConta >= 1 && numConta <= 3) {
                if (sacar(&contas[numConta - 1], valorSaque)) {
                    saldoSuficiente = true;
                }
            }

            // Exibição do resultado
            
            if (saldoSuficiente) {
                printf("Seu saque de R$%.2f reais foi realizado com sucesso na conta %s.\n \nRETIRE SEU DINHEIRO!\n", valorSaque, contas[numConta - 1].tipo);
                printf("\a"); // Emitir som de bip
            } else {
                printf("Seu saldo eh insuficiente para realizar saques no valor de R$%.2f reais da %s.\n", valorSaque, contas[numConta - 1].tipo);
            }
        } else if (opcao == 2) {
           
		    // Exibição do extrato
            exibirExtrato(contas, 3);
        } else if (opcao == 3) {
           
		    // Comando de saída
            printf("|*****************|\n");
            printf("|                 |\n");
            printf("| BANKofESTRELLA  |\n");
            printf("|   OBRIGADO!     |\n");
            printf("|                 |\n");
            printf("|*****************|\n");
            printf("\a"); //emitirar um bip sonoro no final
            break;
	}else{
		printf("\n Opcao invalida. Por favor, escolha uma opcao valida.\n");
		printf("\a");
	}
}
	return 0;
	
}
