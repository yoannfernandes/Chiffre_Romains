#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Rom_Deci();
void Deci_Rom();

int main()    //programme principal
{
    int nSelec=0;

    printf("Saisissez 1 pour convertire un decimal en Romains ou 2 pour convertire un Romain en decimal\n"); //demande le choix de converion
    scanf("%d",&nSelec);
    if (nSelec==1)                  //voici le menue pour lancer les voids
        Deci_Rom();                 //choix 1: converstion decimal a romains
    else if (nSelec==2)             //choix 2: converstion romains a decimal
        Rom_Deci();

    return 0;                       //fin prograamme principal
}
void Rom_Deci(){                    //premier void, la converstion romains a decimal

    char cSaisie[100];              //la variable qui va recevoire la saisie
    int nCpt=0, nResul=0;

    printf("Vous avez choisie de nombre Romains a decimal\n");
    printf("Rentrez un nombre Romains compris entre 1 et 3999 en majuscule\n");
    scanf("%s",cSaisie);

    int n = strlen(cSaisie);        //On cherche la longueur de la saisie

    if (n < 0) // vérification de saisie
        return;

    for(nCpt = 0; nCpt < n; nCpt++) {   //boucle POUR qui va se dérouler le nombre de fois définie par la longueur de la chaine de saisie

        if(cSaisie[nCpt]=='M'){         //condition pour vérifier si M est présent
            nResul=nResul+1000;         //on augmente le resultat si la condition est remplie
        }

        else if(cSaisie[nCpt]=='D'){    //condition pour vérifier si D est présent
            nResul=nResul+500;
        }

        else if(cSaisie[nCpt]=='C'){    //condition pour vérifier si C est présent
            if(cSaisie[nCpt+1]=='M' && nCpt+1 < n){ //on vérifie 900 et si c'est le cas on incrémente le compteur pour éviter de refaire la même lettre au prochain passage
                nResul=nResul+900;
                nCpt=nCpt+1;
            }
            else if(cSaisie[nCpt+1]=='D' && nCpt+1 < n){    //on vérifie 400
                nResul=nResul+400;
                nCpt=nCpt+1;
            }
            else{
                nResul=nResul+100;      //si il n'y a pas 900 ou 400 alors on a 100
            }
        }

        else if(cSaisie[nCpt]=='L'){    //condition pour vérifier si L est présent
            nResul=nResul+50;
        }

        else if(cSaisie[nCpt]=='X'){    //condition pour vérifier si X est présent
            if(cSaisie[nCpt+1]=='C' && nCpt+1 < n){ //on vérifie 90
                nResul=nResul+90;
                nCpt=nCpt+1;
            }
            else if(cSaisie[nCpt+1]=='L' && nCpt+1 < n){    //on vérifie 40
                nResul=nResul+40;
                nCpt=nCpt+1;
            }
            else{
                nResul=nResul+10;   //si il n'y a pas 90 ni 40 alors on a 10
            }
        }

        else if(cSaisie[nCpt]=='V'){    //condition pour vérifier si V est présent
            nResul=nResul+5;
        }

        else if(cSaisie[nCpt]=='I'){    //condition pour vérifier si I est présent
            if(cSaisie[nCpt+1]=='X' && nCpt+1 < n){ //on vérifie si on a pas 9
                nResul=nResul+9;
                nCpt=nCpt+1;
            }
            else if(cSaisie[nCpt+1]=='V' && nCpt+1 < n){    //on vérifie si on a pas 4
                nResul=nResul+4;
                nCpt=nCpt+1;
            }
            else{
                nResul=nResul+1;    //si on a pas 9 ou 4 alors on a 1
            }
        }
    }
    printf("%d",nResul);    //On affiche le résultat
}

void Deci_Rom(){        //deuxieme void, la converstion decimal a romains

    int nSaisie=0;
    printf("Vous avez choisie de decimal a nombre Romains\n");
    printf("Rentrez un nombre entre 1 et 3999\n");
    scanf("%d",&nSaisie);       //on récupère la saisie

    while(nSaisie>0){       //Boucle Tant que la saisie n'est pas égale a 0

        if(nSaisie>=1000){      //On vérifie si on a pas 1000 dans la saisie
            printf("M");        //Si oui on ecrit M
            nSaisie=nSaisie-1000;//On déduit 1000 du nombre saisie
        }

        else if(nSaisie>=900){  //On vérifie si on a pas 900 dans la saisie
            printf("CM");       //Si oui on ecrit CM
            nSaisie=nSaisie-900;//On déduit 900 du nombre saisie
        }

        else if(nSaisie>=500){  //On vérifie si on a pas 500 dans la saisie
            printf("D");        //Si oui on ecrit D
            nSaisie=nSaisie-500;//On déduit 500 du nombre saisie
        }

        else if(nSaisie>=400){  //On vérifie si on a pas 400 dans la saisie
            printf("CD");       //Si oui on ecrit CD
            nSaisie=nSaisie-400;//On déduit 400 du nombre saisie
        }

        else if(nSaisie>=100){  //On vérifie si on a pas 100 dans la saisie
            printf("C");        //Si oui on ecrit C
            nSaisie=nSaisie-100;//On déduit 100 du nombre saisie
        }

        else if(nSaisie>=90){   //On vérifie si on a pas 90 dans la saisie
            printf("XC");       //Si oui on ecrit XC
            nSaisie=nSaisie-90;//On déduit 90 du nombre saisie
        }

        else if(nSaisie>=50){   //On vérifie si on a pas 50 dans la saisie
            printf("L");        //Si oui on ecrit L
            nSaisie=nSaisie-50;//On déduit 50 du nombre saisie
        }

        else if(nSaisie>=40){   //On vérifie si on a pas 40 dans la saisie
            printf("XL");       //Si oui on ecrit XL
            nSaisie=nSaisie-40;//On déduit 40 du nombre saisie
        }

        else if(nSaisie>=10){   //On vérifie si on a pas 10 dans la saisie
            printf("X");        //Si oui on ecrit X
            nSaisie=nSaisie-10;//On déduit 10 du nombre saisie
        }

        else if(nSaisie>=9){    //On vérifie si on a pas 9 dans la saisie
            printf("IX");       //Si oui on ecrit IX
            nSaisie=nSaisie-9;//On déduit 9 du nombre saisie
        }

        else if(nSaisie>=5){    //On vérifie si on a pas 5 dans la saisie
            printf("V");        //Si oui on ecrit V
            nSaisie=nSaisie-5;//On déduit 5 du nombre saisie
        }

        else if(nSaisie>=4){    //On vérifie si on a pas 4 dans la saisie
            printf("IV");       //Si oui on ecrit IV
            nSaisie=nSaisie-4;//On déduit 4 du nombre saisie
        }

        else if(nSaisie>=1){    //On vérifie si on a pas 1 dans la saisie
            printf("I");        //Si oui on ecrit I
            nSaisie=nSaisie-1;//On déduit 1 du nombre saisie
        }
    }

}
