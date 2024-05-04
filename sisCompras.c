/*Armazenar o valor (em Reais) de 10 produtos em um vetor (portanto os valores s�o pr�-estabelecidos). OK

Armazenar uma matriz de Strings com o nome de cada um dos produtos (pr�-estabelecidos). OK

Solicitar o nome do cliente e armazen�-lo. OK

Solicitar o endere�o do cliente para entrega e armazen�-lo. OK

Apresentar ao cliente uma lista (texto) com o nome dos 10 produtos da loja e seu c�digo. OK

Enquanto o cliente n�o digitar o n�mero 11 (que significa que quer concluir a compra), o algoritmo deve:
Imprimir a lista de produtos OK
Solicitar o c�digo do produto que deseja comprar (n�o aceitar c�digos inv�lidos, ou seja, menor que um (1) ou maior que onze (11)) OK
Solicitar a quantidade de produtos que deseja comprar do produto selecionado. OK

Quando o cliente encerra o pedido, o algoritmo deve apresentar o valor total da compra e a quantidade de produtos junto com o nome e endere�o para entrega. OK*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#define LINHAS	10
#define DIM 50
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int codigoProd[LINHAS] = { 1,2,3,4,5,6,7,8,9,10 } /* C�digo dos produtos */, codigoProdEscolhido, multiplicador, contador, resposta, carrinho = 0; /* Armazena a quantidade de produtos */
	double valorProdutos[LINHAS] = { 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0 } /* Valor dos produtos */, valorTotal = 0; /* Armazena o valor dos produtos */;
	char nomeCliente[DIM], enderecoCliente[DIM], nomeProdutos[LINHAS][DIM] = { "Laranja", "Uva", "Bergamota", "Mel�o", "Abacaxi", "Morango", "Melancia", "Manga", "Kiwi", "Damasco" }; /* Nome dos produtos */
	printf("Digite seu nome: "); // Bem vindo
	gets(nomeCliente);
	printf("\n");
	printf("\tBem Vindo %s ao Hortifruti dos Estudantes!\n", nomeCliente);
	printf("\n");
	printf("Digite o seu endere�o para que seja realizada a entrega da sua compra: ");
	gets(enderecoCliente);
	printf("O endere�o digitado foi: %s\n", enderecoCliente);
	printf("Este � o menu de op��es:\n"); // Primeiro Switch
	printf("\t1 - Lista de produtos\n");
	printf("\t2 - Sair do programa\n");
	printf("Digite sua escolha: ");
	scanf_s("%d", &resposta);
	printf("\n");
	switch (resposta)
	{
	case 1:
		printf("A lista de produtos cadastrados �:\n"); // Imprime a tabela pela primeira vez
		printf("\n");
		printf("%4s%21s%21s\n", "C�digo produto", "Nome do produto", "Valor do produto");
		for (contador = 0; contador < LINHAS; contador++)
		{
			printf("%4d%27s%14s%.2lf\n", codigoProd[contador], nomeProdutos[contador], "R$", valorProdutos[contador]);
		}
		printf("\n");
		printf("Voc� deseja realizar a compra?\n"); // Segundo Switch
		printf("\t1 - Sim\n");
		printf("\t2 - N�o\n");
		printf("Sua resposta: ");
		scanf_s("%d", &resposta);
		printf("\n");
		switch (resposta)
		{
		case 1:
			do
			{
				printf("Digite o c�digo do produto: "); // Escolha do produto
				scanf_s("%d", &codigoProdEscolhido);
			} while (codigoProdEscolhido <= 0 || codigoProdEscolhido > LINHAS); // Aceita apenas produtos v�lidos
			printf("Digite a quantidade desse produto que voc� deseja comprar: ");
			scanf_s("%d", &multiplicador);
			printf("O produto escolhido foi %s cujo c�digo � %d e seu valor � R$%.2lf. A quantidade escolhida foi %d\n", nomeProdutos[codigoProdEscolhido - 1], codigoProd[codigoProdEscolhido - 1], valorProdutos[codigoProdEscolhido - 1], multiplicador);
			carrinho = carrinho + (1 * multiplicador); // Adiciona a quantidade de produtos escolhidos ao carrinho
			valorTotal = valorTotal + (valorProdutos[codigoProdEscolhido - 1] * multiplicador); // Armazena o valor desses produtos

			printf("\n");
			printf("Continuar comprando (1 - Sim / 11 - N�o): "); // Continuar at� digitar o n�mero 11
			scanf_s("%d", &resposta);
			printf("\n");
			while (resposta != 11) // While principal
			{
				printf("A lista de produtos cadastrados �:\n"); //Tabela de produtos cadastrados
				printf("\n");
				printf("%4s%21s%21s\n", "C�digo produto", "Nome do produto", "Valor do produto");
				for (contador = 0; contador < LINHAS; contador++)
				{
					printf("%4d%27s%14s%.2lf\n", codigoProd[contador], nomeProdutos[contador], "R$", valorProdutos[contador]);
				}
				printf("\n");
				do
				{
					printf("Digite o c�digo do produto: ");
					scanf_s("%d", &codigoProdEscolhido);
				} while (codigoProdEscolhido <= 0 || codigoProdEscolhido > LINHAS);
				printf("Digite a quantidade desse produto que voc� deseja comprar: ");
				scanf_s("%d", &multiplicador);
				printf("O produto escolhido foi %s cujo c�digo � %d e seu valor � R$%.2lf. A quantidade escolhida foi %d\n", nomeProdutos[codigoProdEscolhido - 1], codigoProd[codigoProdEscolhido - 1], valorProdutos[codigoProdEscolhido - 1], multiplicador);
				carrinho = carrinho + (1 * multiplicador);
				valorTotal = valorTotal + (valorProdutos[codigoProdEscolhido - 1] * multiplicador);
				printf("\n");
				printf("Continuar comprando (1 - Sim / 11 - N�o): ");
				scanf_s("%d", &resposta);
				printf("\n");
			} // Fim do While
			printf("Voc� comprou %d produtos\n", carrinho); // Sa�da do programa
			printf("O valor total da compra foi de R$%.2lf\n", valorTotal);
			printf("Suas compras ser�o entregues no endere�o: %s\n", enderecoCliente);
			printf("Muito obrigado por comprar conosco %s\n", nomeCliente);
			break;
		case 2: //Fim do Segundo Switch
			printf("Voc� saiu do Hortifruti!");
			break;
		default:
			printf("Reinicie o programa e digite uma op��o v�lida!");
			break;
		}
		break;
	case 2: // Fim do Primeiro Switch
		printf("Voc� saiu do Hortifruti!");
		break;
	default:
		printf("Reinicie o programa e digite uma op��o v�lida!");
		break;
	}
	return 0;
}