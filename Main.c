#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OpcoesInteracao();
void InicializarVariaveis(int *fome, int *higiene, int *inteligencia, int *ativo, int *energia, int *felicidade, int *saude);
void Status(int *fome, int *higiene, int *saude, int *inteligencia, int *ativo, int *energia, int *felicidade);

int main(int argc, char const *argv[])
{
    char nome[10];   
    int idade, fome, higiene, inteligencia, ativo, energia, felicidade, saude, vivo, seed, opcoes;
    char sexo;

    printf("Bem Vindo ao Tamagotchi\n");
    printf("De um Nome para seu Tamagotchi: ");
    scanf("%s", &nome);
    //recém-nascido!
    idade = 0;
    printf("Escolha o Sexo\n");
    printf("F -> Femea\n");
    printf("M -> Macho\n");
    printf("Resposta: ");
    scanf("%s", &sexo);

    if (sexo == 'M' || sexo == 'm')
    {
        printf("Voce escolheu Macho\n");      
        sexo = 'M';
    }else if(sexo == 'F' || sexo == 'f')
    {
        printf("Voce escolheu Femea\n");
        sexo = 'F';
    }
    
    InicializarVariaveis(&fome, &higiene, &inteligencia, &ativo, &energia, &felicidade, &saude);
    
    printf("________________________________________________\n");
    // O Tamagotchi está vivo.
    printf("\nSeu tamagotchi acabou de sair do ovo!\n");
    printf(" \n");
    printf("|Nome: %s\n", nome);
    printf("|Sexo: %c\n", sexo);
    printf("|Idade: %d\n", idade);
    printf(" \n");
    printf("|-STATUS:- \n");                           //Mostrando as informações do tamagotchi
    printf("|Fome: %d\n", fome);
    printf("|Higiene: %d\n", higiene);
    printf("|Saude: %d\n", saude);
    printf("|Inteligencia: %d\n", inteligencia);      
    printf("|Atividade: %d\n", ativo);
    printf("|Energia: %d\n", energia);
    printf("|Felicidade: %d\n", felicidade);

    printf(" \n");

    printf("Agora voce pode interagir com ele!!!\n");
    
    while (saude > 0 || opcoes != 8)
    {
        OpcoesInteracao();
        printf("Resposta: ");
        scanf("%d", &opcoes);

        if (opcoes == 1)
        {
           if (fome < 100 && (saude > 50 || felicidade > 50))  
            {
                printf("\nComendo um Pouco!\n");
                fome += 25;
                felicidade += 5;
                saude -= 15;
                higiene -= 10;
                energia += 10;
                if (fome>100)
                {
                    fome = 100;
                }
                if (energia>100)
                {
                    energia = 100;
                }
                if (saude<0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                if (felicidade>100)
                {
                    felicidade = 100;
                }
                if (higiene<0)
                {
                    higiene = 0;
                }
                
            
            }else if(fome == 100 && (felicidade > 80 || felicidade < 30))
            {
                printf("\nEle esta Cheio, mas comeu mais!\n");
                saude -= 15;
                felicidade += 10;
                if (saude<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                if (felicidade>100)
                {
                    felicidade = 100;
                }

            }
            else 
            {
                printf("\nMuito Cheio, nao to com fome!!\n");            
            }
            
            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
            
        }

        if (opcoes == 5)
        {
            if (higiene < 30 && felicidade > 10)
            {
                printf("\nTomando Banho!\n");
                higiene += 100;
                felicidade -= 5;
                saude += 5;
                ativo -= 5;
                energia -= 5;
                if (higiene>100)
                {   
                    higiene = 100;
                }
                if (felicidade<0)
                {
                    felicidade = 0;
                }
                if (saude>100)
                {
                    saude = 100;
                }
                if (ativo<0)
                {
                    ativo = 0;
                }
                if (energia<0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                
                

            }else
            {
                printf("\nNao preciso tomar banho agora!\n");
            }

            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        
        if (opcoes == 2)
        {
            if (energia > 40 && saude > 50)
            {
                printf("\nPraticando Esporte!\n");
                fome -= 20;
                energia -= 30;
                saude += 5;
                felicidade += 10;
                ativo += 10;
                higiene = 0;
                if (saude>100)
                {
                    saude = 100;
                }
                if (felicidade>100)
                {
                    felicidade = 100;
                }
                if (ativo>100)
                {
                    ativo = 100;
                }
                if (fome<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                if (energia<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }

            }else
            {
                printf("\nNao quero praticar Esporte!\n");
            }

            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        
        if (opcoes == 3)
        {
            if (fome > 30 && energia > 30)
            {
                printf("\nIndo Ler!\n");
                inteligencia += 10;
                energia -= 5;
                felicidade -= 10;
                fome -= 10;
                if (inteligencia>100)
                {
                    inteligencia = 100;
                }
                if (felicidade<0)
                {
                    felicidade = 0;
                }
                if (energia<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                if (fome<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                
            }else
            {
                printf("\nNao quero Ler!\n");
            }

            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        
        if (opcoes == 4)
        {
            if (energia > 10 || felicidade > 50)
            {
                printf("\nJogando!\n");   
                felicidade += 10;
                inteligencia += 5;
                higiene -= 5;
                energia -= 10;
                ativo += 10;
                fome -= 10;
                if (felicidade>100)
                {
                    felicidade = 100;
                }
                if (inteligencia>100)
                {
                    inteligencia = 100;
                }
                if (higiene<0)
                {
                    higiene = 0;
                }
                if (energia<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                if (ativo>100)
                {
                    ativo = 100;
                }
                if (fome<=0)
                {
                    printf("Seu Tamagotchi MORREU!\n");
                    return saude == 0;
                }
                
                
            }else
            {
                printf("\nNao quero Jogar!\n");
            }

            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        
        if (opcoes == 6)
        {
            if (saude < 30)
            {
                printf("\nTomando Remedio!\n");
                saude += 15;
                energia += 5;
                if (saude>100)
                {
                    saude = 100;
                }
                if (energia>100)
                {
                    energia = 100;
                }

            }else
            {
                printf("\nNao quero tomar Remedio!\n");
            }

            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        
        if (opcoes == 7)
        {
            if (energia < 30 && saude < 30)
            {
                printf("\nIndo Dormir!\n");
                energia += 30;
                saude += 10;
                if (energia>100)
                {
                    energia = 100;
                }
                if (saude>100)
                {
                    saude = 100;
                }
                
                Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);

                }else 
                {
                    printf("\nNao quero ir Dormir\n");
                }
                
            
            }
            
        if (saude == 0 || energia == 0 || fome ==0)
        {
            printf("Seu Tamagotchi MORREU!\n");
            return saude == 0;
            Status(&fome, &higiene, &saude, &inteligencia, &ativo, &energia, &felicidade);
        }
        if (opcoes == 8)
        {
            printf("\nSaiu do Jogo");
            return 0;
        }
        
        }
        
    return 0;
}

void OpcoesInteracao()
{
    printf(" \n");
    printf("Opcoes:\n");
    printf("1 - COMER\n");
    printf("2 - PRATICAR ESPORTE\n");
    printf("3 - LER\n");
    printf("4 - JOGAR\n");
    printf("5 - TOMAR BANHO\n");
    printf("6 - TOMAR REMEDIO\n");
    printf("7 - DORMIR\n");
    printf("8 - SAIR DO PROGRAMA\n");
}

void InicializarVariaveis(int *fome, int *higiene, int *inteligencia, int *ativo, int *energia, int *felicidade, int *saude)
{
    srand(time(NULL));
    *fome = 50 + (rand() % 50);
    *higiene = 50 + (rand() % 50);
    *inteligencia = 50 + (rand() % 50);
    *ativo = 50 + (rand() % 50);             //ainiciando essas variaveis aleatorias a partir de 50
    *energia = 50 + (rand() % 50);
    *felicidade = 50 + (rand() % 50);
    *saude = 50 + (rand() % 50);
}

void Status(int *fome, int *higiene, int *saude, int *inteligencia, int *ativo, int *energia, int *felicidade)
{
    printf("Fome: %d\n", *fome);
    printf("Higiene: %d\n", *higiene);
    printf("Saude: %d\n", *saude);
    printf("Inteligencia: %d\n", *inteligencia);
    printf("Atividade: %d\n",* ativo);
    printf("Energia: %d\n", *energia);
    printf("Felicidade: %d\n", *felicidade);
}
