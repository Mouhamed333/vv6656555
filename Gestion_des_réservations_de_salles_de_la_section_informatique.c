#include<stdio.h>
#include<stdlib.h>
#include "dossier.h" 
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
 int main(void )
{
	int choix,choix0;
	do{ clear_screen();
		
		printf("Gestion des reservations de salles de la section informatique\n\n");
		
		printf("1-creationclasse\n");
		printf("2-afficherclasse\n");
		printf("3-modifierclasse\n");
		printf("4-supprimerclasse\n");
		printf("5-creationsalle\n");
		printf("6-affichersalle\n");
		printf("7-modifiersalle\n");
		printf("8-supprimersalle\n");
		printf("9-afficheredt\n");
		printf("0-fin de traitement\n\n");
		printf("votre choix:");
		scanf("%d",&choix);
		
		     switch(choix)
		     {
		     	case 1:creationclasse()
					;break;
				 
				case 2: affichageclasse()
					;break;
				 
				case 3:modifierclasse()
					;break;
				 
				case 4:supprimerclasse()
					;break;
					
				case 5:creationsalle()
					;break;
					
				case 6: affichagesalle()
					;break;
					
				case 7:modifiersalle()
					;break;
					
				case 8:supprimersalle()
					;break;
			    
			case 9:
                printf("\n*** Affichage emploi du temps ***\n");
                printf("1 - Emploi du temps l3\n");
                printf("2 - Emploi du temps l2\n");
                printf("4 - Emploi du temps l1\n");
                printf("5 - Emploi du temps l?\n");
                printf("6 - Emploi du temps l?\n");
                printf("7 - Emploi du temps l?\n");
                printf("8 - Emploi du temps l?\n");
                printf("Votre choix : ");
                scanf("%d", &choix0);
                switch (choix0) {
                    case 1: affichageedt(); break;
                    case 2:               ; break;
                    case 3:               ; break;
                    case 4:               ; break;
                    case 5:               ; break;
                    case 6:               ; break;
                    case 7:               ; break;
                    default: printf("Choix invalide pour l'emploi du temps.\n");
                }
                break;
				 
				case 0: printf("fin du traitement\n")
					;break;
				 
				 default: printf("choix erroné !!!! le choix entre 0 et 8");
				 
			 }
			  getchar(); getchar();
			 
			 }while(choix!=0);

return 0;	
}