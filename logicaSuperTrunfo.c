#include <stdio.h>
int main(){
      //declaração de variaveis;
      char cidade1[50], cidade2[50],codigo1[4],codigo2[4],estado1[3],estado2[3];
      int pontos_turisticos1,pontos_turisticos2;
      unsigned long int populacao1,populacao2;
      double pib1,pib2;
      float area1,area2, pib_per_capta1,pib_per_capta2,densidade1,densidade2, super_poder1, super_poder2;
      //sistema de cadrastamento da primeira carta;

      printf("digite o código de sua primeira carta: (exemplo: A01.) \n");
      scanf("%3s", codigo1);
      printf("digite o código de seu estado escolhido para sua primeira carta: (exemolo: SP,MG,BA.)\n");
      scanf("%2s", estado1);
      printf("digite o nome da sua cidade escolhida para sua primeira carta: (exemplo: Recife.)\n");
      getchar();
      fgets(cidade1, 50, stdin);
      printf("qual o numero de população total da cidade escolhida para sua primeira carta? (somente numeros)\n");
      scanf("%lu", &populacao1);
      printf("qual a área total da sua cidade escolhida para sua primeira carta? \n");
      scanf("%f", &area1);
      printf("qual o PIB total da cidade escolhida para sua primeira carta? (em reais.) \n");
      scanf("%lf", &pib1);
      printf("quantos pontos turisticos tem ma cidade escolhida para sua primeira carta? \n");
      scanf("%d", &pontos_turisticos1);
	
      // sistema de criação dos numeros referentes ao pib per capta e densidade populacional da primeira carta:

      if (populacao1 > 0) {

            pib_per_capta1 = pib1 / (float)populacao1;
      } else {
            printf("ATENÇÃO! A população da carta 1 foi definida como 0.\n\n");
      } if (area1 > 0.0f) {

            densidade1 = (float)populacao1 / area1;
      } else {
            printf("ATENÇÃO!, A população da sua carta 1 é 0.");
      }


      printf("\n\n");

      // sistema de cadrastamento da segunda carta;
    
      printf("digite o código de sua segunda carta: (exemplo: B02.) \n");
      scanf("%3s", codigo2);
      printf("digite o código de seu estado escolhido para sua segunda carta: (exemolo: SP,MG,BA.)\n");
      scanf("%2s", estado2);
      printf("digite o nome da sua cidade escolhida para sua segunda carta: (exemplo: Goiás.)\n");
      getchar();
      fgets(cidade2, 50, stdin);
      printf("qual o numero de população total da cidade escolhida para sua segunda carta? (somente numeros)\n");
      scanf("%lu", &populacao2);
      printf("qual a área total da sua cidade escolhida para sua segunda carta? \n");
      scanf("%f", &area2);
      printf("qual o PIB total da cidade escolhida para sua segunda carta? (em reais.) \n");
      scanf("%lf", &pib2);
      printf("quantos pontos turisticos tem ma cidade escolhida para sua segunda carta? \n");
      scanf("%d", &pontos_turisticos2);
    
      // sistema de criação dos numeros referentes ao pib per capta e densidade populacional e verificação de entradas invalidas como o 0. da segunda carta :
      if (populacao2 > 0) {

            pib_per_capta2 = pib2 / (float)populacao2;
      } else {
            printf("ATENÇÃO! A população da carta 2 foi definida como 0.\n\n");
      } if (area2 > 0.0f) {

            densidade2 = (float)populacao2 / area2;
      } else {
            printf("ATENÇÃO!, A população da sua carta dois é 0.");
      }

      // exibindo informações da primeira carta com espaco entre as linhas pois achei que seria mais bonitinho;

      printf("carta1: \n\n");
      printf("O codigo da sua primeira carta é: %s\n\n", codigo1);
      printf("O código do estado escolhido na sua primeira carta é: %s\n\n", estado1);
      printf("O nome da cidade escolhida da sua primeira carta é: %s\n\n", cidade1);
      printf("A população total da sua primeira cidade escolhida é de: %lu habitantes.\n\n", populacao1);
      printf("A area total da sua primeira cidade escolhida é de: %.2f km²\n\n", area1);
      printf("O PIB total da sua primeira cidade escolhida é de: %.2lf bilhões de reais.\n\n", pib1 / 1000000000.0);
      printf("A sua primeira cidade tem o número de: %d pontos turisticos\n\n", pontos_turisticos1);
      printf("A sua primeira carta tem a densidade populacional de: %.2f\n\n", densidade1);
      printf("A sua primeira carta tem o pib per capta no valor de: %.2f\n\n", pib_per_capta1);
      // exibindo informações da segunda carta com espaco entre as linhas pois achei que seria mais bonitinho;
    
      printf("carta2: \n\n");
      printf("O codigo da sua segunda carta é: %s\n\n", codigo2);
      printf("O código do estado escolhido na sua segunda carta é: %s\n\n", estado2);
      printf("O nome da cidade escolhida da sua segunda carta é: %s\n\n", cidade2);
      printf("A população total da sua segunda cidade escolhida é de: %lu habitantes.\n\n", populacao2);
      printf("A area total da sua segunda cidade escolhida é de: %.2f km²\n\n", area2);
      printf("O PIB total da sua segunda cidade escolhida é de: %.2lf bilhões de reais.\n\n", pib2 / 1000000000.0);
      printf("A sua segunda cidade tem o número de: %d pontos turisticos\n\n", pontos_turisticos2);
      printf("A sua segunda carta tem a densidade populacional de: %.2f\n\n", densidade2);
      printf("A sua segunda carta tem o pib per capta no valor de: %.2f\n\n", pib_per_capta2);


      // tentativa de implementação do calculo do super poder:

      super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_per_capta1 + (1/densidade1);
      super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capta2 + (1/densidade2);

      // sistema de comparação talvez;

      printf("..............Comparação de cartas!.............\n\n");

      if (populacao1 > populacao2) {
            printf("sua primeira carta venceu no quesito população!\n\n");
      } else {
            printf("sua segunda carta venceu no quesito população!\n\n");
      } if (area1 > area2) {
           printf("sua primeira carta venceu no quesito Área total!\n\n"); 
      } else {
            printf("sua segunda carta venceu no quesito Área total!\n\n");
      } if (pib1 > pib2) {
            printf("sua primeira carta venceu no quesito PIB total!\n\n");
      } else {
            printf("sua segunda carta venceu no quesito PIB total!\n\n");
      } if (densidade1 < densidade2) {
            printf("sua primeira carta venceu no quesito densidade populacional!\n\n");
      } else {
            printf("sua segunda carta venceu no quesito dencidade populacional!\n\n");
      } if (pib_per_capta1 > pib_per_capta2) {
            printf("sua primeira carta venceu no quesito pob per capta!\n\n");
      } else {
            printf("sua segunda carta venceu no quesito pib per capta!\n\n");
      } if (super_poder1 > super_poder2) {
            printf("sua primeira carta venceu no quesito super poder!\n\n");
      } else {
            printf("sua segunda carta venceu no quesito super poder!\n\n");
      }
      return 0;
}