#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	double valor1, valor2, valor3, valor4, maior, menor, media;
	printf("Informe o valor em reais e centavos da primeira loja: R$ ");
	scanf_s("%lf", &valor1);
	// Verifica se os valores estão corretos
	while (valor1 <= 0) {
		printf("Informe o valor em reais e centavos correto da primeira loja: R$ ");
		scanf_s("%lf", &valor1);
	}
	printf("Informe o valor em reais e centavos da segunda loja: R$ ");
	scanf_s("%lf", &valor2);
	while (valor2 <= 0) {
		printf("Informe o valor em reais e centavos correto da segunda loja: R$ ");
		scanf_s("%lf", &valor2);
	}
	printf("Informe o valor em reais e centavos da terceira loja: R$ ");
	scanf_s("%lf", &valor3);
	while (valor3 <= 0) {
		printf("Informe o valor em reais e centavos correto da terceira loja: R$ ");
		scanf_s("%lf", &valor3);
	}
	printf("Informe o valor em reais e centavos da quarta loja: R$ ");
	scanf_s("%lf", &valor4);
	while (valor4 <= 0) {
		printf("Informe o valor em reais e centavos correto da quarta loja: R$ ");
		scanf_s("%lf", &valor4);
	}
	// Calculo da media dos valores
	media = (valor1 + valor2 + valor3 + valor4) / 4;
	// Calculo do maior valor
	maior = valor1;
	if (valor2 > maior && valor2 > valor3 && valor2 > valor4) {
		maior = valor2;
		printf("\nO maior valor encontrado foi o da segunda loja, R$%.2lf\n", maior);
	}
	else if (valor3 > maior && valor3 > valor2 && valor3 > valor4) {
		maior = valor3;
		printf("\nO maior valor encontrado foi o da terceira loja, R$%.2lf\n", maior);
	}
	else if (valor4 > maior && valor4 > valor3 && valor4 > valor2) {
		maior = valor4;
		printf("\nO maior valor encontrado foi o da quarta loja, R$%.2lf\n", maior);
	} else if (maior = valor1) {
		printf("\nO maior valor encontrado foi o da primeira loja, R$%.2lf\n", maior);
	}
	// Calculo do menor valor
	menor = valor1;
	if (valor2 < menor && valor3 > valor2 && valor4 > valor2) {
		menor = valor2;
		printf("\nO menor valor encontrado foi o da segunda loja, R$%.2lf\n", menor);
	}
	else if (valor3 < menor && valor2 > valor3 && valor4 > valor3) {
		menor = valor3;
		printf("\nO menor valor encontrado foi o da terceira loja, R$%.2lf\n", menor);
	}
	else if (valor4 < menor && valor2 > valor4 && valor3 > valor4) {
		menor = valor4;
		printf("\nO menor valor encontrado foi o da quarta loja, R$%.2lf\n", menor);
	}
	else if (valor1 = menor) {
		printf("\nO menor valor encontrado foi o da primeira loja, R$%.2lf\n", menor);
	}
	printf("\nA media dos valores dos ovos de páscoa é: R$%.2lf\n", media);

	return 0;
}