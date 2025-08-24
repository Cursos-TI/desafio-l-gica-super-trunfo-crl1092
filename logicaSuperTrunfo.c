#include <stdio.h>
#include <stdlib.h> 


// tentativa de aplicacao do conceito de estrutura:
typedef struct {
    char codigo[4];
    char estado[3];
    char cidade[50];
    unsigned long int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double pib_per_capita;
    double densidade;
} Carta;
//funções em que vou desenrolar meu código na função main: 
void CadastrarCartas(Carta *c) {
      printf("digite o código da carta escolhida: \n");
      scanf("%3s",c->codigo);
      printf("digite o cógigo do estado escolhido: \n");
      scanf("%2s",c->estado);
      getchar();
      printf("digite o nome da cidade escolhida: \n");
      fgets(c->cidade, 50, stdin);
      printf("digite a população total da cidade escolhida: \n");
      scanf("%lu",&c->populacao);
      printf("digite a área total da cidade escolhida: \n");
      scanf("%lf",&c->area);
      printf("digite o pib total da cidade escolhida em reais e somente números: \n");
      scanf("%lf",&c->pib);
      printf("digite o numero de pontos turisticos da cidade escolhida: \n");
      scanf("%d",&c->pontos_turisticos);
};
void CalcularParametros(Carta *c){
      if (c->area > 0){
            c->densidade = c->populacao/c->area;
      } else {
             printf("ATENÇÃO! A área da carta foi definida como 0.\n\n");
      };
      if (c->populacao > 0) {
            c->pib_per_capita = c->pib / c->populacao;
      } else {
             printf("ATENÇÃO! A população da carta foi definida como 0.\n\n");
      };
};
void ExibirInformacoes (Carta c){
      printf("\nCarta: %s - %s (%s) \n", c.codigo, c.cidade, c.estado);
      printf("População: %lu habitantes\n", c.populacao);
      printf("Área: %.2lf km²\n", c.area);
      printf("PIB: %.2lf bilhões de reais\n", c.pib / 1e9);
      printf("Pontos turísticos: %d\n", c.pontos_turisticos);
      printf("PIB per capita: %.2lf\n", c.pib_per_capita);
      printf("Densidade: %.2lf\n", c.densidade);
};
void CompararCartas (Carta c1, Carta c2){
      int opcao;
      printf("escolha um quesito para a comparar as cartas individualmente: \n\n");
      printf("1. quesito população. \n");
      printf("2. quesito área total. \n");
      printf("3. quesito pib total. \n");
      printf("4. quesito numero de pontos turísticos. \n");
      printf("5. quesito pib per capta. \n");
      printf("6. quesito densidade populacional. \n\n");
      scanf("%d",&opcao);
      
      switch (opcao)
      {
      case 1:
            if(c1.populacao > c2.populacao){
                  printf("sua primeira carta vençeu no quesito população.\n\n");
            } else if (c1.populacao < c2.populacao) {
                  printf("sua segunda carta venceu no quesito população.\n\n");
            } else {
                  printf("houve um empate no quesito população.\n\n");
            };
            break;
      case 2:
            if(c1.area > c2.area){
                  printf("sua primeira carta vençeu no quesito área total.\n\n");
            } else if (c1.area < c2.area) {
                  printf("sua segunda carta venceu no quesito área total.\n\n");
            } else {
                  printf("houve um empate no quesito Area total.\n\n");
            };
            break;
      case 3:
            if(c1.pib > c2.pib){
                  printf("sua primeira carta vençeu no quesito pib total.\n\n");
            } else if (c1.pib < c2.pib) {
                  printf("sua segunda carta venceu no quesito pib total.\n\n");
            } else {
                  printf("houve um empate no quesito pib total.\n\n");
            };
      break;
      case 4:
            if(c1.pontos_turisticos > c2.pontos_turisticos){
                  printf("sua primeira carta vençeu no quesito pontos turisticos.\n\n");
            } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
                  printf("sua segunda carta venceu no quesito pontos turisticos.\n\n");
            } else {
                  printf("houve um empate no quesito pontos turisticos.\n\n");
            };
      break;
      case 5:
            if (c1.pib_per_capita > c2.pib_per_capita) {
                  printf("sua primeira carta venceu no quesito PIB per capta.\n\n");
            } else if (c1.pib_per_capita < c2.pib_per_capita) {
                  printf("sua segunda carta venceu no quesito PIB per capta.\n\n");
            } else {
                  printf("houve um empate no quesito PIB per capta.\n\n");
            };
      break;
      case 6:
            if (c1.densidade < c2.densidade) {
                  printf("sua primeira carta venceu no quesito densidade populacional.\n\n");
            } else if (c1.densidade > c2.densidade) {
                  printf("sua segunda carta venceu no quesito densidade populacional.\n\n");
            } else {
                  printf("houve um empate no quesito densidade populacional.\n\n");
            }
      break;
      default:
            printf("Opção inválida!");
            break;
      };
};

void menuPrincipal() {
      printf(" .......BEM VINDO AO JOGO DE CARTAS SUPER TRUNFO....... \n\n"); //inicio
      printf("1. Cadastrar cartas.\n");
      printf("2. Exibir cartas.\n");
      printf("3. Comparar aributos individualmente.\n");
      printf("4. comparar multiplos atributos.\n");
      printf("0. sair\n");
      printf("Escolha uma opção: ");
}

void limparTela() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux/Mac
    #endif
}

void ComparacaoComDoisAtributos(Carta c1, Carta c2) {
    int atributo1, atributo2;
    int pontos1 = 0, pontos2 = 0;

    do {
        printf("1. População\n");
        printf("2. Área total\n");
        printf("3. PIB total\n");
        printf("4. Número de pontos turísticos\n");
        printf("5. PIB per capita\n");
        printf("6. Densidade populacional\n\n");

        printf("Escolha o primeiro atributo a ser comparado: ");
        scanf("%d", &atributo1);

        printf("Escolha o segundo atributo a ser comparado: ");
        scanf("%d", &atributo2);

        if (atributo1 == atributo2) {
            printf("\n Atributos iguais não são permitidos. Tente novamente.\n\n");
        }
    } while (atributo1 == atributo2);

    // --- comparação do primeiro atributo ---
    switch (atributo1) {
      case 1: 
            pontos1 += (c1.populacao > c2.populacao) ? 1 : 0;
            pontos2 += (c2.populacao > c1.populacao) ? 1 : 0; 
      break;
      case 2: 
            pontos1 += (c1.area > c2.area) ? 1 : 0;
            pontos2 += (c2.area > c1.area) ? 1 : 0; 
      break;
      case 3: 
            pontos1 += (c1.pib > c2.pib) ? 1 : 0;
            pontos2 += (c2.pib > c1.pib) ? 1 : 0;  
      break;
      case 4: 
            pontos1 += (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 0;
            pontos2 += (c2.pontos_turisticos > c1.pontos_turisticos) ? 1 : 0; 
      break;
      case 5: 
            pontos1 += (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 0;
            pontos2 += (c2.pib_per_capita > c1.pib_per_capita) ? 1 : 0; 
      break;
      case 6: 
            pontos1 += (c1.densidade < c2.densidade) ? 1 : 0;
            pontos2 += (c2.densidade < c1.densidade) ? 1 : 0; 
      break;
    };
    // --- comparação do segundo atributo ---
    switch (atributo2) {
        case 1: 
            pontos1 += (c1.populacao > c2.populacao) ? 1 : 0;
            pontos2 += (c2.populacao > c1.populacao) ? 1 : 0; 
      break;
      case 2: 
            pontos1 += (c1.area > c2.area) ? 1 : 0;
            pontos2 += (c2.area > c1.area) ? 1 : 0; 
      break;
      case 3: 
            pontos1 += (c1.pib > c2.pib) ? 1 : 0;
            pontos2 += (c2.pib > c1.pib) ? 1 : 0;  
      break;
      case 4: 
            pontos1 += (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 0;
            pontos2 += (c2.pontos_turisticos > c1.pontos_turisticos) ? 1 : 0; 
      break;
      case 5: 
            pontos1 += (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 0;
            pontos2 += (c2.pib_per_capita > c1.pib_per_capita) ? 1 : 0; 
      break;
      case 6: 
            pontos1 += (c1.densidade < c2.densidade) ? 1 : 0;
            pontos2 += (c2.densidade < c1.densidade) ? 1 : 0; 
      break;
    }
    limparTela();
    printf("\nResultado final:\n");
    if (pontos1 > pontos2) {
        printf("🎉 Carta 1 venceu por %d a %d!\n\n\n", pontos1, pontos2);
    } else if (pontos2 > pontos1) {
        printf("🎉 Carta 2 venceu por %d a %d!\n\n\n", pontos2, pontos1);
    } else {
        printf("🤝 Empate! %d a %d.\n\n\n", pontos1, pontos2);
    }
};    
      

//função main/principal
int main(){
      
      int OpcaoPrincipal;
      int cartasCadrastadas = 0;

      Carta carta1,carta2; //variaveis que vou inicializar nas quatro funções criadas.

      do {
            menuPrincipal();
            scanf("%d", &OpcaoPrincipal);
            switch (OpcaoPrincipal)
            {
            case 1:
                  limparTela();
            // processo de cadrastamento da primeira carta:
                  printf(".....cadrasto da primeira carta..... \n\n");
                  CadastrarCartas(&carta1);
                  CalcularParametros(&carta1);
                  // processo de cadrastamento da segunda carta:
            
                  printf(" .....cadrasto da segunda carta..... \n\n");
                  CadastrarCartas(&carta2);
                  CalcularParametros(&carta2);
                  printf("\nCartas cadastradas com sucesso!\n\n");
                  cartasCadrastadas = 1;
                  break;
            case 2:
                  limparTela();
                  if (cartasCadrastadas)
                  {
                        printf(" .....veja suas cartas cadrastadas..... \n\n");
                        ExibirInformacoes(carta1);
                        ExibirInformacoes(carta2);
                  }else {
                        printf("ATENÇÃO! Você ainda não cadastrou suas cartas, por favor cadastre suas cartas primeiro.\n\n");
                  };
                  break;
            case 3:
                  limparTela();
                if (cartasCadrastadas){
                        printf(" .....Comparações entre as cartas cadrastadas com somente um atributo a ser escolhido..... \n\n");
                        CompararCartas(carta1,carta2);
                } else {
                  printf("ATENÇÃO! Você ainda não cadastrou suas cartas, por favor cadastre suas cartas primeiro.\n\n");
                }
                break;
            case 4:
                  limparTela();
                  if (cartasCadrastadas){
                  ComparacaoComDoisAtributos(carta1, carta2);
                  } else {
                  printf("ATENÇÃO! Você ainda não cadastrou suas cartas, por favor cadastre suas cartas primeiro.\n\n");
                  }
                break;
                  break;
            case 0:
                  limparTela();
                  printf("saindo do jogo, até mais...\n\n");
                  break;
            default:
                  printf("\nOpção inválida! Tente novamente.\n");
                  break;
            }
      } while (OpcaoPrincipal != 0);   
};