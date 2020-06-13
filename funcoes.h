


//Criar uma nova estacao e retornar o apontador da mesma. 
struct Estacao* ObterNovaEstacao(char sigla) {
	struct Estacao* novaEstacao
		= (struct Estacao*)malloc(sizeof(struct Estacao));
	novaEstacao->sigla = sigla;
	novaEstacao->anterior = NULL;
	novaEstacao->proxima = NULL;
	return novaEstacao;
}

//Inserir nova estacao no inicio da rede rede
void InsertAtHead(char sigla) {
	struct Estacao* novaEstacao = ObterNovaEstacao(sigla);
	if(inicial == NULL) {
		inicial = novaEstacao;
		return;
	}
	inicial->anterior = novaEstacao;
	novaEstacao->proxima = inicial; 
	inicial = novaEstacao;
}

//Inserir nova estacao no terminal da rede
void inserirProximaEstacao(char sigla) {
	struct Estacao* temp = inicial;
	struct Estacao* novaEstacao = ObterNovaEstacao(sigla);
	if(inicial == NULL) {
		inicial = novaEstacao;
		return;
	}
	while(temp->proxima != NULL) temp = temp->proxima; // Va ate ultima estacao
	temp->proxima = novaEstacao;
	novaEstacao->anterior = temp;
}

//Mostrar todas as estacoes da de partida ate a do terminal
void ida() {
  int contador = 1;
	struct Estacao* temp = inicial;
//	printf("Ida: ");
	while(temp != NULL) {
    printf("ESTACAO #%d: %c --->  ", contador++, temp->sigla);
		temp = temp->proxima;
	}
	printf("\n");
}

//Mostrar todas as estacoes da do terminal ate a de partida. 
void volta() {
	struct Estacao* temp = inicial;
	if(temp == NULL) return; // caso nenhuma estacao existe na rede, fim
	while(temp->proxima != NULL) {
		temp = temp->proxima;
	}
	printf("Volta: ");
  int contador = 1;
	while(temp != NULL) {
	printf("ESTACAO #%d: %c --->  ", contador++, temp->sigla);
		temp = temp->anterior;
	}
	printf("\n");
}


//Opcoes tomar 
int opcoes(int opcao){
  switch(opcao){
    case 1: //criar estacao para a proxima viagem
      printf("INSERIR SIGLA DA ESTACAO SEGUINTE (ex: 'A', 'B', 'C'): ");
      char sigla;
      scanf(" %c", &sigla); //Sigla que representa a estacao
      //posicionar a estacao na rota a percorrer
      inserirProximaEstacao(sigla); 
      break;
    case 2:
      printf("IDA: \n");
      //o arranque da viagem a partir da estacao de partida
      ida();
      break;
    case 3:
      printf("VOLTA: \n");
      //regresso a partir da ultima estacao
      volta();
      break;
    default:
      return 0;

  }

  return 1;
}

//Opcoes que resumem as funcionalidades do programa
int interfaceUtilizador(){
    int opcao;
    
    do{
      printf("\nOpcoes:\n");
      printf("1. Definir a rota por inserir sigla da Nova Estacao:\n");
      printf("2. Arrancar com a Viagem\n");
      printf("3. Regressar da viagem\n");
      printf("4. Terminar o programa\n");
      scanf("%d", &opcao);

      opcoes(opcao);

    }
    while (opcao != 4);
    return opcao;
}

