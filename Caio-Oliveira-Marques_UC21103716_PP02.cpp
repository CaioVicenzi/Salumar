// NOME: Caio Oliveira Marques MATR�CULA: UC21103716

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int quantidadeAssentos;
	char nomeUsuario[30];
	int idadeUsuario;
	int opcao;
	char nomeDestino[30];
	float preco = 0;
	
	// cadastrando o usu�rio
	printf("Ol� usu�rio! Bem vindo ao sistema de vendas da SALUMAN LINHAS A�REAS\n\n");
	printf("Digite aqui o seu nome: ");
	fgets(nomeUsuario, 30, stdin);
	printf("Digite aqui a sua idade: ");
	scanf("%i", &idadeUsuario);
	fflush(stdin);
	
	printf("Usu�rio %s registrado com sucesso!\n\n", nomeUsuario);
	system("PAUSE");
	system("CLS");
	
	// Nesse ponto aqui n�s temos em m�os o nome e a idade do usu�rio, que ser� usado posteriormente no c�lculo do pre�o
	
	// Selecionando um avi�o:
	printf("============ ESCOLHER AVI�O ============\n\n");
	
	printf("Digite o nome do destino: ");
	fgets(nomeDestino, 30, stdin);
	
	printf("Agora, digite o pre�o: ");
	scanf("%f", &preco);
	fflush(stdin);
	
	// Se a idade do usu�rio for menor ou igual a 5, o pre�o ser� descontado na metade do valor.
	if(idadeUsuario <=5)
		preco = preco / 2;

	//Nesse ponto n�s temos a informa��o do nome do destino e pre�o, que usaremos posteriormente.
	
	while(true){
		printf("Para finalizar, digite a quantidade de assentos: ");
		scanf("%i", &quantidadeAssentos);
		fflush(stdin);
		
		// Como terceira condi��o necess�ria eu defini que a quantidade de assentos tem que ser divis�vel por 4.
		if(quantidadeAssentos >= 90 && quantidadeAssentos <= 200 && quantidadeAssentos%4 == 0) break;
			else {
				printf(VERMELHO "Valor digitado � inv�lido, todos nossos avi�es possuem entre 90 e 200 assentos e s�o divis�veis por 4...!\n");	
				printf(RESET);	
			}
	}
	
	// Nessa parte abaixo, a gente divide a quantidade de assentos em 4 filas de assentos, por isso o n�mero de assentos, nessa
	// empresa fict�cia, � sempre divis�vel por 4.
		
	int quantidadeColunas = quantidadeAssentos/4;
	
	// O mapa dos assentos do avi�o � uma matriz de caracteres com sempre 4 filas, por�m a quantidade de colunas varia de
	//acordo com a quantidade de assentos.
	char assentos[4][quantidadeColunas]; 
	
	//preechendo as colunas com 'D' de dispon�veis.
	for(int linha = 0; linha<4; linha++){
		for (int coluna = 0; coluna<quantidadeColunas; coluna++){
			assentos[linha][coluna] = 'D';
		}
	}
	system("CLS");
	
	// Essa matriz funcionar� da seguinte forma: o primeiro valor ser� o �ndice, que come�ar� por 1, 
	// j� o segundo, ser� a linha do assento e o terceiro, a coluna do assento.
	int matrizReservas[quantidadeAssentos][3];
	
	int quantasReservasJaForamFeitas = 0;
	int opcaoEscolhida;
	int numeroIdentificadorReserva, i, linha, coluna;
	bool valorFoiEncontrado = false;
	char confirmar;
	int quantidadeReservados, quantidadeConfirmados, quantidadeDisponiveis;

	// S� sai desse la�o se o usu�rio digitar 4.
	while(true){
		// Menu principal
		printf("---- Menu Principal ----\n\n");
		printf("1- Reservar assento\n");
		printf("2- Confirmar uma reserva\n");
		printf("3- Cancelar uma reserva\n");
		printf("4- Informa��es do avi�o\n");
		printf("5- Sair do Programa\n");
		printf("Sua escolha: ");
		scanf("%i", &opcaoEscolhida);
	
		switch (opcaoEscolhida){
			case 1: 
				system("CLS");
				// Exibe o mapa dos assentos do avi�o
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(int colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (int j = 0; j < quantidadeColunas; j++){
						if(assentos[i][j] == 'D'){
							printf(VERDE "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");
						} else if(assentos[i][j] == 'R'){
							printf(VERMELHO "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						} else {
							printf(AZUL "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						}
					}
					printf("\n");
				}
				printf("PS:\nD = ASSENTO DISPON�VEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				// Se a linha do assento digitada for v�lida o la�o volta, caso contr�rio, o programa exibe uma mensagem de
				//erro e o la�o se repete, o programa pergunta novamente a linha do assento (processo semelhante acontece com
				//a coluna
				while(true){
					// pedindo para o usu�rio as posi��es dos assentos
					int linhaAssentoReservado, colunaAssentoReservado;
					while(true){	
						printf("Digite a linha do assento: ");
						scanf("%i", &linhaAssentoReservado);
						fflush(stdin);
						if(linhaAssentoReservado <= 4 && linhaAssentoReservado > 0) break;
							else{
								printf( VERMELHO "Valor de linha digitado � inv�lido, existem apenas 4 linhas\n");
								printf(RESET);
							}
					}
	
					while(true){
						printf("Digite a coluna do assento: ");
						scanf("%i", &colunaAssentoReservado);
						fflush(stdin);
						if(colunaAssentoReservado <= quantidadeColunas && colunaAssentoReservado > 0) break;
						else printf(VERMELHO "Valor de coluna digitado � inv�lido, existem apenas %i colunas\n", quantidadeColunas);
						printf(RESET);
					}
		
					// verificando se o assento est� dispon�vel
					if(assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] == 'D'){
						// trocando a posi��o para "Reservado"
						assentos[linhaAssentoReservado-1][colunaAssentoReservado-1] = 'R'; 
						// subtra� um da linha assento reservado e coluna para que fique f�cil para o usu�rio ter um assento
						// que comece com 1 e termine com 4
						
						matrizReservas[quantasReservasJaForamFeitas][0] = quantasReservasJaForamFeitas + 1;
						matrizReservas[quantasReservasJaForamFeitas][1] = linhaAssentoReservado - 1;
						matrizReservas[quantasReservasJaForamFeitas][2] = colunaAssentoReservado - 1;
						printf("SUA RESERVA POSSUI IDENTIFICA��O %i, USE ESSA IDENTIFICA��O PARA CONFIRMAR OU CANCELAR SUA RESERVA\n", 
							quantasReservasJaForamFeitas + 1);
						printf("PRE�O: %.2f\n\n", preco);
						quantasReservasJaForamFeitas++;
						printf(VERDE "--- Reserva conclu�da com sucesso! ---\n\n");
						printf(RESET);
						
						system("PAUSE");
						system("CLS");
						break;
					} else printf("Assento j� est� reservado ou confirmado, tente outro assento\n");
				}
				break;
	
			case 2: 
				valorFoiEncontrado = false;
				system("CLS");
				printf("=======> CONFIRMAR UMA RESERVA <========\n\n");
				printf("Digite o n�mero identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = true;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMA��ES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Pre�o: %.2f\n\n", preco);
							
							printf("Deseja confirmar a reserva? (S -> SIM, QUALQUER OUTRO -> N�O): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'C';
								printf(VERDE "RESERVA CONFIRMADA COM SUCESSO!\n\n");
								printf(RESET);	
							}	
						} else printf("A RESERVA DIGITADA J� FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) {
					printf(VERMELHO "A RESERVA DIGITADA N�O FOI ENCONTRADA!\n\n");
					printf(RESET);	
				}
				system("PAUSE");
				system("CLS");
				break;
				
			case 3: 
				valorFoiEncontrado = false;
				system("CLS");
				printf("=======> CANCELAR UMA RESERVA <========\n\n");
				printf("Digite o n�mero identificador da reserva: ");
				scanf("%i", &numeroIdentificadorReserva);
				fflush(stdin);
				
				for(i = 0; i < quantasReservasJaForamFeitas; i++){
					if (matrizReservas[i][0] == numeroIdentificadorReserva){
						valorFoiEncontrado = true;
						linha = matrizReservas[i][1];
						coluna = matrizReservas[i][2]; 
						if(assentos[linha][coluna] == 'R') {
							printf("\n\n------ INFORMA��ES DA RESERVA -------\n\n");
							printf("Nome do passageiro: %s", nomeUsuario);
							printf("Linha do assento: %i\n", linha + 1);
							printf("Coluna do assento: %i\n", coluna + 1);
							printf("Numero de reserva: %i\n", numeroIdentificadorReserva);
							printf("Destino: %s\n", nomeDestino);
							printf("Pre�o: %.2f\n\n", preco);
							
							printf("Deseja cancelar a reserva? (S -> SIM, QUALQUER OUTRO -> N�O): ");
							scanf("%c", &confirmar);
							fflush(stdin);
							
							if(confirmar == 'S'){
								assentos[linha][coluna] = 'D';
								printf(VERDE "RESERVA CANCELADA COM SUCESSO!\n\n");
								printf(RESET);	
							}	
						} else printf("A RESERVA DIGITADA J� FOI CONFIRMADA OU FOI CANCELADA...\n\n");
					}
				}
				
				if(!valorFoiEncontrado) printf(VERMELHO "A RESERVA DIGITADA N�O FOI ENCONTRADA!\n\n");
				printf(RESET);
				system("PAUSE");
				system("CLS");
				break;
				
			case 4:
				quantidadeConfirmados = 0;
				quantidadeDisponiveis = 0;
				quantidadeReservados = 0;
				float precoTotal;
				
				system("CLS");
				// Exibe o mapa dos assentos do avi�o
				printf("========> MAPA DOS ASSENTOS <========\n\n");
				printf("|Colunas:|");
				for(int colunas = 0; colunas<quantidadeColunas; colunas++){
					printf("%2i|", colunas + 1);
				}
				printf("\n");
				for(i = 0; i<4; i++){
					printf("|Linha %i:|", i + 1);
					for (int j = 0; j < quantidadeColunas; j++){
						if(assentos[i][j] == 'D'){
							printf(VERDE "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");
						} else if(assentos[i][j] == 'R'){
							printf(VERMELHO "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						} else {
							printf(AZUL "%c", assentos[i][j]);
							printf(RESET);
							printf(" |");						
						}
					}
					printf("\n");
				}
				
				printf("PS:\nD = ASSENTO DISPON�VEL \nR = ASSENTO RESERVADO\nC = ASSENTO COM RESERVA CONFIRMADA\n");
				
				for(i = 0; i<4; i++){
					for(int j = 0; j<quantidadeColunas; j++){
						if(assentos[i][j] == 'C') quantidadeConfirmados++;
							else if(assentos[i][j] == 'D') quantidadeDisponiveis++;
								else quantidadeReservados++;
					}
				}
				
				printf("\n\n");
				printf("=========> INFORMA��ES <=========\n\n");
				precoTotal = quantidadeConfirmados * preco;
				printf("DESTINO: %s", nomeDestino);
				printf("ASSENTOS RESERVADOS: %i\n", quantidadeReservados);
				printf("RESERVAS CONFIRMADAS: %i\n", quantidadeConfirmados);
				printf("ASSENTOS DISPON�VEIS: %i\n", quantidadeDisponiveis);
				printf("TOTAL EM REAIS: %.2f\n\n", precoTotal);
				
				system("PAUSE");
				system("CLS");
				break;	
			
			case 5:
				printf("Obrigado pela escolha e volte sempre!"); 
				return 0;
			 
			default: 
				printf(VERMELHO "Valor inv�lido."); 
				printf(RESET);
				break;
		}
	}
}
