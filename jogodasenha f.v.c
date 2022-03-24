#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void tentativas(char valor[]);
void gera_random(int senha[]);
void CompararIguais(char valor[], int senha[], int valor_novo[], int senha_nova[], int k, int todos_acertos[], int todos_valores[][4]);
void CompararPertos(int valor_novo[], int senha_nova[], int todos_acertos[], int k);
void limpaTela();
void gerar_menu();
void Verificacao(char valor[], int senha[], int k);
void tabela(int todos_acertos[] , int todos_valores[][4], int k);

int main(){
  int senha[4] , j , i, valor_novo[4]={}, k , senha_nova[4]={}, todos_acertos[40]={}, todos_valores[10][4];
  char valor[50];
   limpaTela();
   gerar_menu();
   gera_random(senha);	
 for( j =0; j<10 ; j++){
   tentativas(valor);
   k++;
   CompararIguais(valor, senha, valor_novo, senha_nova, k, todos_acertos, todos_valores);
   CompararPertos(valor_novo, senha_nova, todos_acertos, k );
   tabela(todos_acertos, todos_valores, k);
   Verificacao(valor, senha, k);
   printf("\n");
  printf("A senha é :  ");
  for( i = 0 ; i < 4; i++){ 
   printf("%d ", senha[i]);
    }
  }
 return 0;
}

void gera_random(int senha[]){
  int i , n , max = 6;

  srand(time (NULL));
  
  for( i = 0; i < 4; i++){
     n = rand();
     n = n % max;
     senha[i] = n;

  }
}



void tentativas(char valor[]){
   int tam, i;
   
   printf("\033[1;32m");
   printf("Digite um valor (aaaa): ");
   scanf("%s",valor);
   tam = strlen(valor);
   getchar();

   /*temos que fazer as verificações agr*/
   for( i= 0; i<4; i++){
   while((tam> 4 || tam<4) || ( valor[i]<47 || valor[i]>53)){  /* verificação de tamanho, o valor " aaaa" infelizmente pode passar pois tem tamanho 4 */
    limpaTela ();
        printf("\033[0m");
        printf("\n==================================================================================================================================\n");
        printf("\033[1;32m");
        printf("        __    ______     _______   ______      _______       ___             _______. _______ .__   __.  __    __       ___      \n");
        printf("       |  |  /  __  \\   /  _____| /  __  \\    |       \\     /   \\           /       ||   ____||  \\ |  | |  |  |  |     /   \\     \n");
        printf("       |  | |  |  |  | |  |  __  |  |  |  |   |  .--.  |   /  ^  \\         |   (----`|  |__   |   \\|  | |  |__|  |    /  ^  \\    \n");
        printf(" .--.  |  | |  |  |  | |  | |_ | |  |  |  |   |  |  |  |  /  /_\\  \\         \\   \\    |   __|  |  . `  | |   __   |   /  /_\\  \\   \n");
        printf(" |  `--'  | |  `--'  | |  |__| | |  `--'  |   |  '--'  | /  _____  \\    .----)   |   |  |____ |  |\\   | |  |  |  |  /  _____  \\  \n");
        printf("  \\______/   \\______/   \\______|  \\______/    |_______/ /__/     \\__\\   |_______/    |_______||__| \\__| |__|  |__| /__/     \\__\\ \ \n");
        printf("\033[0m");
        printf("\n==================================================================================================================================");
        printf("\033[1;32m");
        printf("\n\n                                         Coloque um valor válido (de 0 a 5): ");
     scanf("%s",valor);
     tam = strlen(valor);
     i=0;
     getchar();
       }
   
     }

 }
         
void CompararIguais(char valor[], int senha[], int valor_novo[], int senha_nova[], int k, int todos_acertos[], int todos_valores[][4]){
     int valor_int[50], j, acertos = 0, i = 0;
     for( i = 0; i < 4; i++){      /* colocando os valores de de uma matriz char para uma matriz int(uma espécie de conversão) para fazermos a comparação com a matriz senha*/
        valor_int[i] = valor[i] - '0' ;
     }
      for(i = 0; i<4 ; i++){
        todos_valores[k-1][i] = valor_int[i];
      }
       for( j = 0 , acertos = 0; j < 4; j++){
           if(senha[j] != valor_int[j]){
               valor_novo[j] = valor_int[j];
               senha_nova[j] = senha[j];
               }
           else{
               acertos++;
               valor_novo[j] = 9;  /* valor inválido que usaremos para compararPerto*/
               senha_nova[j] = 8;
               }    
               
           todos_acertos[k-1] = acertos;       
           }
    printf("\033[0m");
        
        limpaTela ();
        printf("\033[0m");
        printf("\n==================================================================================================================================\n");
        printf("\033[1;32m");
        printf("        __    ______     _______   ______      _______       ___             _______. _______ .__   __.  __    __       ___      \n");
        printf("       |  |  /  __  \\   /  _____| /  __  \\    |       \\     /   \\           /       ||   ____||  \\ |  | |  |  |  |     /   \\     \n");
        printf("       |  | |  |  |  | |  |  __  |  |  |  |   |  .--.  |   /  ^  \\         |   (----`|  |__   |   \\|  | |  |__|  |    /  ^  \\    \n");
        printf(" .--.  |  | |  |  |  | |  | |_ | |  |  |  |   |  |  |  |  /  /_\\  \\         \\   \\    |   __|  |  . `  | |   __   |   /  /_\\  \\   \n");
        printf(" |  `--'  | |  `--'  | |  |__| | |  `--'  |   |  '--'  | /  _____  \\    .----)   |   |  |____ |  |\\   | |  |  |  |  /  _____  \\  \n");
        printf("  \\______/   \\______/   \\______|  \\______/    |_______/ /__/     \\__\\   |_______/    |_______||__| \\__| |__|  |__| /__/     \\__\\ \ \n");
        printf("\033[0m");
        printf("\n==================================================================================================================================");

        
        printf("\033[1;32m");
        printf ("\n\n                         █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    	    printf ("                         █     CERTOS      |   %d   █        |       |       |      █              █\n", acertos);
            printf ("                         █-----------------|-------█    %d   |   %d   |   %d   |   %d  █ TENTATIVA %d  █\n", valor_int[0], valor_int[1], valor_int[2], valor_int[3], k	 );
    
     }                                   
  
 
  void CompararPertos(int valor_novo[], int senha_nova[], int todos_acertos[], int k ){
          int j , m, perto = 0 ;
          
          for(j=0; j<4; j++){
            for(m=0; m<4; m++){
               if (senha_nova[j] == valor_novo[m]){
                    perto++;
                    senha_nova[j] = 8;
                    valor_novo[m] = 9; } } }
                    
              todos_acertos[k+19] = perto ;  
                    
    
    printf ("                         █ FORA DE POSICAO |   %d   █        |       |       |      █              █\n", perto);
    printf ("                         █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");              
                                                                     
 
     
 
 } 
void limpaTela(){
     #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(linux) || defined(unix)
        system("clear");
    #endif
}


  
 void gerar_menu( ){
    
    int opcoes;
    char nome[50];
    
        printf("\033[0m");
        printf("\n==================================================================================================================================\n");
        printf("\033[1;32m");
        printf("        __    ______     _______   ______      _______       ___             _______. _______ .__   __.  __    __       ___      \n");
        printf("       |  |  /  __  \\   /  _____| /  __  \\    |       \\     /   \\           /       ||   ____||  \\ |  | |  |  |  |     /   \\     \n");
        printf("       |  | |  |  |  | |  |  __  |  |  |  |   |  .--.  |   /  ^  \\         |   (----`|  |__   |   \\|  | |  |__|  |    /  ^  \\    \n");
        printf(" .--.  |  | |  |  |  | |  | |_ | |  |  |  |   |  |  |  |  /  /_\\  \\         \\   \\    |   __|  |  . `  | |   __   |   /  /_\\  \\   \n");
        printf(" |  `--'  | |  `--'  | |  |__| | |  `--'  |   |  '--'  | /  _____  \\    .----)   |   |  |____ |  |\\   | |  |  |  |  /  _____  \\  \n");
        printf("  \\______/   \\______/   \\______|  \\______/    |_______/ /__/     \\__\\   |_______/    |_______||__| \\__| |__|  |__| /__/     \\__\\ \ \n");
        printf("\033[0m");
        printf("\n==================================================================================================================================");
        
        printf("\033[1;32m");
        printf ("\n\n                                        NICKNAME: ");
        scanf("%s", &nome);
        
        
        limpaTela ();
        printf("\033[0m");
        printf("\n==================================================================================================================================\n");
        printf("\033[1;32m");
        printf("        __    ______     _______   ______      _______       ___             _______. _______ .__   __.  __    __       ___      \n");
        printf("       |  |  /  __  \\   /  _____| /  __  \\    |       \\     /   \\           /       ||   ____||  \\ |  | |  |  |  |     /   \\     \n");

        printf("       |  | |  |  |  | |  |  __  |  |  |  |   |  .--.  |   /  ^  \\         |   (----`|  |__   |   \\|  | |  |__|  |    /  ^  \\    \n");
        printf(" .--.  |  | |  |  |  | |  | |_ | |  |  |  |   |  |  |  |  /  /_\\  \\         \\   \\    |   __|  |  . `  | |   __   |   /  /_\\  \\   \n");
        printf(" |  `--'  | |  `--'  | |  |__| | |  `--'  |   |  '--'  | /  _____  \\    .----)   |   |  |____ |  |\\   | |  |  |  |  /  _____  \\  \n");
        printf("  \\______/   \\______/   \\______|  \\______/    |_______/ /__/     \\__\\   |_______/    |_______||__| \\__| |__|  |__| /__/     \\__\\ \ \n");
        printf("\033[0m");
        printf("\n==================================================================================================================================");
 
        printf("\n                         Bem vindo(a) ao jogo, %s! Sera que voce consegue adivinhar a senha?\n", nome);
        printf("                         >>> INSTRUCOES:\n");
        printf("                         Escolha 4 numeros entre 0 e 6.\n");
        printf("                         Voce tem 10 chances de acertar. Boa sorte!\n");
        
        printf("\033[1;37m");
        printf("\n                         Digite 1 para começar ou digite qualquer número para sair: ");
        scanf("%d", &opcoes);        
        
        limpaTela ();
        printf("\033[0m");
        printf("\n==================================================================================================================================\n");
        printf("\033[1;32m");
        printf("        __    ______     _______   ______      _______       ___             _______. _______ .__   __.  __    __       ___      \n");
        printf("       |  |  /  __  \\   /  _____| /  __  \\    |       \\     /   \\           /       ||   ____||  \\ |  | |  |  |  |     /   \\     \n");
        printf("       |  | |  |  |  | |  |  __  |  |  |  |   |  .--.  |   /  ^  \\         |   (----`|  |__   |   \\|  | |  |__|  |    /  ^  \\    \n");
        printf(" .--.  |  | |  |  |  | |  | |_ | |  |  |  |   |  |  |  |  /  /_\\  \\         \\   \\    |   __|  |  . `  | |   __   |   /  /_\\  \\   \n");
        printf(" |  `--'  | |  `--'  | |  |__| | |  `--'  |   |  '--'  | /  _____  \\    .----)   |   |  |____ |  |\\   | |  |  |  |  /  _____  \\  \n");
        printf("  \\______/   \\______/   \\______|  \\______/    |_______/ /__/     \\__\\   |_______/    |_______||__| \\__| |__|  |__| /__/     \\__\\ \ \n");
        printf("\033[0m");
        printf("\n==================================================================================================================================");
 

        if(opcoes == 1){
        printf("\n\n\n                                       Iniciando.... ");
        }
        else{
            printf("                                                            Fim de jogo\n\n\n");
            exit(0);
        }
    
}


 void Verificacao( char valor[], int senha[] ,  int k){
 
    int i, resposta[4], igual = 1;
     
    for( i = 0; i < 4; i++){      /* colocando os valores de de uma matriz char para uma matriz int(uma espécie de conversão) para fazermos a comparação com a matriz senha*/
        resposta[i] = valor[i] - '0' ;
     }
     
      
      for( i = 0 ; i < 4; i++){
         
             if(resposta [i] != senha[i]){
                     igual = 0;
         }     
        }
      
 
 
      if(igual ==  1){
			printf("\033[1;32m");
			printf ("\n\n\n                                                              PARABENS!\n\n");
			printf("\033[1;37m");
			printf ("      :::     :::  ::::::::   ::::::::  ::::::::::     ::::::::      :::     ::::    ::: :::    :::  ::::::::  :::    ::: :::\n");
			printf ("      :+:     :+: :+:    :+: :+:    :+: :+:           :+:    :+:   :+: :+:   :+:+:   :+: :+:    :+: :+:    :+: :+:    :+: :+:\n");
			printf ("      +:+     +:+ +:+    +:+ +:+        +:+           +:+         +:+   +:+  :+:+:+  +:+ +:+    +:+ +:+    +:+ +:+    +:+ +:+\n");
			printf ("      +#+     +:+ +#+    +:+ +#+        +#++:++#      :#:        +#++:++#++: +#+ +:+ +#+ +#++:++#++ +#+    +:+ +#+    +:+ +#+\n");
			printf ("       +#+   +#+  +#+    +#+ +#+        +#+           +#+   +#+# +#+     +#+ +#+  +#+#+# +#+    +#+ +#+    +#+ +#+    +#+ +#+\n");
			printf ("        #+#+#+#   #+#    #+# #+#    #+# #+#           #+#    #+# #+#     #+# #+#   #+#+# #+#    #+# #+#    #+# #+#    #+#\n");
			printf ("          ###      ########   ########  ##########     ########  ###     ### ###    #### ###    ###  ########   ########  ###\n");  
         
          	        printf("                                                            Fim de jogo\n\n\n");
                       exit(0);
         
         }
         
           
      else{
           if((k == 10)){
		printf("\033[1;37m");
		    
		printf ("\n\n\n      :::     :::  ::::::::   ::::::::  ::::::::::    :::::::::  :::::::::: :::::::::  :::::::::  :::::::::: :::    :::\n");
		printf ("      :+:     :+: :+:    :+: :+:    :+: :+:           :+:    :+: :+:        :+:    :+: :+:    :+: :+:        :+:    :+:\n");
		printf ("      +:+     +:+ +:+    +:+ +:+        +:+           +:+    +:+ +:+        +:+    +:+ +:+    +:+ +:+        +:+    +:+\n");
		printf ("      +#+     +:+ +#+    +:+ +#+        +#++:++#      +#++:++#+  +#++:++#   +#++:++#:  +#+    +:+ +#++:++#   +#+    +:+\n");
		printf ("       +#+   +#+  +#+    +#+ +#+        +#+           +#+        +#+        +#+    +#+ +#+    +#+ +#+        +#+    +#+\n");
		printf ("        #+#+#+#   #+#    #+# #+#    #+# #+#           #+#        #+#        #+#    #+# #+#    #+# #+#        #+#    #+#\n");
		printf ("          ###      ########   ########  ##########    ###        ########## ###    ### #########  ##########  ########\n");
               printf("                                                            Fim de jogo\n\n\n");
               exit(0);    
             
           
           }
      
      }
      
} 
 
 
 void tabela(int todos_acertos[], int  todos_valores[][4], int k){
    int i, j;
   for(j=0; j<k; j++){
     for(i=0; i < 4; i++){
    printf("%d",todos_valores[j][i]);
     }
    } 
    for( i = 0; i<k; i++){
     printf("%d", todos_acertos[i]);
    }
    for( i = 0 ; i < k; i++){
      printf("%d", todos_acertos[i+20]);
    }
  }
   

