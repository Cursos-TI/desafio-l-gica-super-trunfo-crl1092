#include <stdio.h>
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
void CadrastarCartas(Carta *c) {
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
      printf("\nCarta: %s - %s (%s)\n", c.codigo, c.cidade, c.estado);
      printf("População: %lu habitantes\n", c.populacao);
      printf("Área: %.2lf km²\n", c.area);
      printf("PIB: %.2lf bilhões de reais\n", c.pib / 1e9);
      printf("Pontos turísticos: %d\n", c.pontos_turisticos);
      printf("PIB per capita: %.2lf\n", c.pib_per_capita);
      printf("Densidade: %.2lf\n", c.densidade);
};
void CompararCartas (Carta c1, Carta c2){
      if(c1.populacao > c2.populacao){
            printf("sua primeira carta vençeu no quesito população.\n\n");
      } else if (c1.populacao < c2.populacao) {
            printf("sua segunda carta venceu no quesito população.\n\n");
      } else {
            printf("houve um empate no quesito população.\n\n");
      };
      if(c1.area > c2.area){
            printf("sua primeira carta vençeu no quesito área total.\n\n");
      } else if (c1.area < c2.area) {
            printf("sua segunda carta venceu no quesito área total.\n\n");
      } else {
            printf("houve um empate no quesito Area total.\n\n");
      };
      if(c1.pib > c2.pib){
            printf("sua primeira carta vençeu no quesito pib total.\n\n");
      } else if (c1.pib < c2.pib) {
            printf("sua segunda carta venceu no quesito pib total.\n\n");
      } else {
            printf("houve um empate no quesito pib total.\n\n");
      };
      if(c1.pontos_turisticos > c2.pontos_turisticos){
            printf("sua primeira carta vençeu no quesito pontos turisticos.\n\n");
      } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
            printf("sua segunda carta venceu no quesito pontos turisticos.\n\n");
      } else {
            printf("houve um empate no quesito pontos turisticos.\n\n");
      };
      if (c1.pib_per_capita > c2.pib_per_capita) {
            printf("sua primeira carta venceu no quesito pib per capta.\n\n");
      } else if (c1.pib_per_capita < c2.pib_per_capita) {
            printf("sua segunda carta venceu no quesito pib per capta\n\n");
      } else {
            printf("houve um empate no quesito pob per capta.\n\n");
      };
      if (c1.densidade > c2.densidade) {
            printf("sua primeira carta venceu no quesito densidade populacional.\n\n");
      } else if (c1.densidade < c2.densidade) {
            printf("sua segunda carta venceu no quesito densidade populacional.\n\n");
      } else {
            printf("houve um empate no quesito densidade populacional.\n\n");
      }
      
      
};

//função main/principal
int main(){
      printf(" .......BEM VINDO AO JOGO DE CARTAS SUPER TRUNFO....... \n\n"); //inicio

      Carta carta1,carta2; //variaveis que vou inicializar nas quatro funções criadas.
      
      // processo de cadrastamento da primeira carta:
      printf(".....cadrasto da primeira carta..... \n\n");
      CadrastarCartas(&carta1);
      CalcularParametros(&carta1);
      // processo de cadrastamento da segunda carta:

      printf(" .....cadrasto da segunda carta..... \n\n");
      CadrastarCartas(&carta2);
      CalcularParametros(&carta2);
      //exibição das cartas cadrastadas:

      printf(" .....veja suas cartas cadrastadas..... \n\n");
      ExibirInformacoes(carta1);
      ExibirInformacoes(carta2);

      // Exibindo comparações:
      printf(" .....Comparações entre as cartas cadrastadas..... \n\n");
      CompararCartas(carta1,carta2);

}
