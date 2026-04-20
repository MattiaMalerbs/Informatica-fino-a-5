#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void danno(float* vita){
    
    float danno= rand()%100 + 1;
    
    float V = 0;
    V = *vita;
    V = V - danno;
    
    printf("danno subito:%f \n", danno);
    
    *vita = V;
}

void lvl(int* livello, float* vita){
    
    float possibilita = 0;
    
    possibilita = rand()%100 + 1;
    
    if(possibilita >= 60){
        *livello = *livello + 1;
        float GV = 0;
        GV = rand () %100 + 1;
        *vita = *vita + GV;
    }
    
}

bool statistiche(float vita, int livello){
    
    if(vita >0){
    
    printf("le tue statistiche: Vita=%f, Livello=%d  \n", vita, livello);
    printf("\n");
    return true;
    }
    else{
        printf("sei morto");
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    float vita=100;
    int livello=1;
    int avanti = 0;
    
    printf("vuoi giocare? \n");
    printf("\n");
    printf("se vuoi giocare di 1 se vuoi smettere  premi 0 \n");
    printf("\n");
    scanf("%d", &avanti);
    
    
    
    if (avanti == 1){
        
        lvl(&livello, &vita);
        danno(&vita);
        
    }
    else{
            printf("fine");
        }
    
    while(avanti != 0){
        printf("\n");
        printf("le tue statistiche: Vita=%f, Livello=%d  \n", vita, livello);
        printf("\n");
        printf("se vuoi giocare di 1 se vuoi smettere  premi 0 \n");
        printf("\n");
        scanf("%d", &avanti); 
        
        if(statistiche(vita, livello)){
        printf("\n");
        printf("sei sopravissuto un altro giro!");
        printf("\n");
        
            if (avanti == 1){
            lvl(&livello, &vita);
            danno(&vita);
            }
        else{
            printf("fine");
        }
        
        }
        else{
        printf("\n");
        printf("sei morto");
        avanti = 0;
        }
    
    }
    
    return 0;
}