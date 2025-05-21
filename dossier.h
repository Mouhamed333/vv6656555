#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int code,effectif,codes,capacite,numReservation,codeClasse,codeSalle,duree;
char nom[20],niveau[20],position[20],machine[20],EDT[50],classe[50],salle[50],date[20],heureDebut[10],motif[50],etat[20],planning[20],planningg[20],planninggg[20],planningggg[20],planninggggg[20],planningggggg[20],planninggggggg[20],planningggggggg[20],planninggggggggg[20];


FILE*fp;
FILE*fps;
FILE*fpfsalle;
FILE*fpfclasse;
FILE*fpe;
FILE*fpel;
FILE*fpr;
FILE*fpelll;
FILE*fpem1;
FILE*fpem1s;
FILE*fpem2retel;
FILE*fpem1retel;
FILE*fpplanning;
FILE*fpplanning2;
FILE*fpplanning3;
FILE*fpplanning4;
FILE*fpplanning5;
FILE*fpplanning6;
FILE*fpplanning7;
FILE*fpplanning8;
FILE*fpplanning9;

void creationclasse(void);
void affichageclasse(void);
void modifierclasse(void);
void supprimerclasse(void);
void creationsalle(void);
void affichagelisteclasse(void);
void affichagesalle(void);
void modifiersalle(void);
void supprimersalle(void);
void affichageedt(void);
void affichageedtl1(void);
void affichageedtl3bio(void);
void affichageedtm1sir(void);
void affichageedtm1sirsoir(void);
void affichageedtm2retel(void);
void affichageedtm1retel(void);
void creationreservation(void);
void affichagereservation(void);
void affichageplanningrc1(void);
void affichageplanningrc2(void);
void affichageplanningrc3(void);
void affichageplanningrc4(void);
void affichageplanningTPE1(void);
void affichageplanningTPE2(void);
void affichageplanningTPE3(void);
void affichageplanningTP_extension(void);
void affichageplanningamphi3(void);
void affichagereservation(void);
void recherchereservationclasse(void);
void recherchereservationsalle(void);
void modifieretatreservation(void);
void supprimerreservation(void);
void affichagelistesalles(void);


void creationclasse()
{
	int codeR,tr=0;
	fp=fopen("classe.txt","a+");
	if(fp==NULL)
	{
		printf("ce n'est pas possible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le code:");
	scanf("%d",&codeR);
	while(!feof(fp)){

	fscanf(fp,"%d %s %s %d",&code,nom,niveau,&effectif);
	if(code==codeR)
	{
		tr=1;
		break;
	}
	}	
	if(tr==1){
		printf("classe existe deja!!!\n");
		
	}
	else{
	    printf("donner le nom:");
		scanf("%s",nom)	;
		printf("donner le niveau:");
		scanf("%s",niveau)	;
		printf("donner l effectif:");
		scanf("%d",&effectif)	;
		fprintf(fp,"%d\n %s\n %s\n %d\n",codeR,nom,niveau,effectif);
	}
	fclose(fp);
}
void affichagelisteclasse()
{
	FILE*fpfclasse;
	char classe[50];
	fpfclasse=fopen("listeclasse.txt","rt");
	if(fpfclasse==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(classe,sizeof(classe),fpfclasse)  !=NULL)
	{
		printf("%s",classe);
	}
fclose(fpfclasse);
}

void affichageclasse()
{
int codeR,tr=0;
fp=fopen("classe.txt","rt");
    if(fp==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	printf("donner le code:");
	scanf("%d",&codeR);
	while(!feof(fp))
	{
		fscanf(fp,"%d\n %s\n %s\n %d\n",&code,nom,niveau,&effectif);
		if(code==codeR)
		{
		tr=1;
		printf("nom:%s\n",nom);
		printf("niveau:%s\n",niveau);
		printf("effectif:%d\n",effectif);
		}
	}
	if(tr==0)
	{
		printf("la classe n'existe pas!!!\n");
	}
	
	fclose(fp);
	
}
void modifierclasse()
{
int codeR,tr=0;
FILE*fa,*fp;
fp=fopen("classe.txt","rt");
    if(fp==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
fa=fopen("fa.txt","wt");
	if(fa==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
    printf("donner le code de la classe a modifier:");
    scanf("%d",&codeR);
    while(fscanf(fp,"%d\n %s\n %s\n %d\n",&code,nom,niveau,&effectif)==4)
    {
    	if(code==codeR){
	
    	tr=1;
    	printf("donner le nouveau nom:");
    	scanf("%s",nom);
		}
	
	fprintf(fa,"%d\n %s\n %s\n %d\n",code,nom,niveau,effectif);
	}


	fclose(fp);
	fclose(fa);
	remove("classe.txt");
	rename("fa.txt","classe.txt");
	if(tr==0)
	printf("la classe n'existe pas\n");
	else
	printf("la classe est modifier\n");
	
	
}
void supprimerclasse()
{
int codeR, tr = 0;
int code, effectif;
char nom[50], niveau[50]; 
FILE*fa,*fp;
fp=fopen("classe.txt","rt");
    if(fp==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
fa=fopen("fa.txt","wt");
	if(fa==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
    printf("donner le code de la classe a supprimer:");
    scanf("%d",&codeR);
    while(fscanf(fp,"%d\n %s\n %s\n %d\n",&code,nom,niveau,&effectif)==4)
    {
    	if(code!=codeR)
	fprintf(fa,"%d\n %s\n %s\n %d\n",code,nom,niveau,effectif);
	    else
    	tr=1;
	}


	fclose(fp);
	fclose(fa);
	remove("classe.txt");
	rename("fa.txt","classe.txt");
	if(tr==0)
	printf("la classe n existe pas\n");
	else
	printf("la classe est supprimer\n");
	
	
}


void creationsalle()
{
	int codeR,tr=0;
	fps=fopen("salle.txt","a+");
	if(fps==NULL)
	{
		printf("ce n'est pas possible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le code:");
	scanf("%d",&codeR);
	while(!feof(fps)){

	fscanf(fps,"%d %s %d %s",&codes,position,&capacite,machine);
	if(codes==codeR)
	{
		tr=1;
		break;
	}
	}	
	if(tr==1){
		printf("salle existe deja!!!\n");
		
	}
	else{
	    printf("donner sa position:");
		scanf("%s",position)	;
		printf("donner sa capacite:");
		scanf("%d",&capacite)	;
		printf("donner la disponibilite ou non des machines:");
		scanf("%s",machine)	;
		fprintf(fps,"%d\n %s\n %d\n %s\n",codeR,position,capacite,machine);
	}
	fclose(fps);
}
void affichagelistesalles()
{
	FILE*fpfsalle;
	char salle[50];
	fpfsalle=fopen("listesalle.txt","rt");
	if(fpfsalle==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(salle,sizeof(salle),fpfsalle)  !=NULL)
	{
		printf("%s",salle);
	}
fclose(fpfsalle);
}

void affichagesalle()
{
int codeR,tr=0;
fps=fopen("salle.txt","rt");
    if(fps==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	printf("donner le code:");
	scanf("%d",&codeR);
	while(fscanf(fps,"%d %s %d %s",&codes,position,&capacite,machine)==4)
	{
		if(codes==codeR)
		{
		tr=1;
		printf("position:%s\n",position);
		printf("capacite:%d\n",capacite);
		printf("machine:%s\n",machine);
		}
	}
	if(tr==0)
	{
		printf("la salle n'existe pas!!!\n");
	}
	
	fclose(fps);
	
}

void modifiersalle()
{
int codeR,tr=0;
FILE*fas,*fps;
fps=fopen("salle.txt","rt");
    if(fps==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
fas=fopen("fas.txt","wt");
	if(fas==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
    printf("donner le code de la classe a modifier:");
    scanf("%d",&codeR);
    while(fscanf(fps,"%d %s %d %s",&codes,position,&capacite,machine)==4)
    {
    	if(codes==codeR){
	
    	tr=1;
    	printf("donner le nouveau position:");
    	scanf("%s",position);
    		printf("donner le nouveau capacite:");
    	scanf("%d",&capacite);
    		printf("donner le nouveau disponibilite ou non des machines:");
    	scanf("%s",machine);
		}
	
fprintf(fas,"%d\n %s\n %d\n %s\n",codes,position,capacite,machine);
	}


	fclose(fps);
	fclose(fas);
	remove("salle.txt");
	rename("fas.txt","salle.txt");
	if(tr==0)
	printf("la salle n'existe pas\n");
	else
	printf("la salle est modifier\n");
	
	
}


void supprimersalle()
{
int codeR, tr = 0;
int codes,capacite;
char position[20],machine[20]; 
FILE*fas,*fps;
fps=fopen("salle.txt","rt");
    if(fps==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
fas=fopen("fas.txt","wt");
	if(fas==NULL)
    {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
    printf("donner le code de la salle à supprimer:");
    scanf("%d",&codeR);
  while(fscanf(fps,"%d %s %d %s",&codes,position,&capacite,machine)==4)
    {
    	if(codes!=codeR)
	fprintf(fas,"%d\n %s\n %d\n %s\n",codes,position,capacite,machine);
	    else
    	tr=1;
	}


	fclose(fps);
	fclose(fas);
	remove("salle.txt");
	rename("fas.txt","salle.txt");
	if(tr==0)
	printf("la salle n'existe pas\n");
	else
	printf("la salle est supprimer\n");
	
	
}
void affichageedt()
{
	FILE*fpe;
	char EDT[50];
	fpe=fopen("edt.txt","rt");
	if(fpe==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpe)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpe);
}
void affichageedtl1()
{
	FILE*fpel;
	char EDT[50];
	fpel=fopen("edtl.txt","rt");
	if(fpel==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpel)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpel);
}
void affichageedtl3bio()
{
	FILE*fpelll;
	char EDT[50];
	fpelll=fopen("edtl3bio.txt","rt");
	if(fpelll==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpelll)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpelll);

}
void affichageedtm1sir()
{
	FILE*fpem1;
	char EDT[50];
	fpem1=fopen("edtm1sir.txt","rt");
	if(fpem1==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpem1)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpem1);

}
void affichageedtm2retel()
{
	FILE*fpem2retel;
	char EDT[50];
	fpem2retel=fopen("edtm2retel.txt","rt");
	if(fpem2retel==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpem2retel)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpem2retel);

}
void affichageedtm1retel()
{
	FILE*fpem1retel;
	char EDT[50];
	fpem1retel=fopen("edtm1retel.txt","rt");
	if(fpem1retel==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpem1retel)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpem1retel);

}
void affichageedtm1sirsoir()
{
	FILE*fpem1s;
	char EDT[50];
	fpem1s=fopen("edtm1sirsoir.txt","rt");
	if(fpem1s==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(EDT,sizeof(EDT),fpem1s)  !=NULL)
	{
		printf("%s",EDT);
	}
fclose(fpem1s);

}




void creationreservation()
{
	int numR,tr=0;
	fpr=fopen("reservation.txt","a+");
	if(fpr==NULL)
	{
		printf("ce n'est pas possible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le numero de reservation:");
	scanf("%d",&numR);
	while(!feof(fpr)){
		fscanf(fpr,"%d %d %d %s %s %d %s %s",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat);
		if(numReservation==numR)
		{
			tr=1;
			break;
		}
	}	
	if(tr==1){
		printf("reservation existe deja!!!\n");
	}
	else{
		printf("donner le code de la classe:");
		scanf("%d",&codeClasse);
		printf("donner le code de la salle:");
		scanf("%d",&codeSalle);
		printf("donner la date (ex: lundi):");
		scanf("%s",date);
		printf("donner l'heure de debut (ex: 08h00):");
		scanf("%s",heureDebut);
		printf("donner la duree en heure:");
		scanf("%d",&duree);
		printf("donner le motif:");
		scanf("%s",motif);
		printf("donner l'etat (reserve/annule/valide/encours/termine):");
		scanf("%s",etat);
		fprintf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",numR,codeClasse,codeSalle,date,heureDebut,duree,motif,etat);
	}
	fclose(fpr);
}

void affichagereservation()
{
	int numR,tr=0;
	fpr=fopen("reservation.txt","rt");
	if(fpr==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}	
	printf("donner le numero de reservation:");
	scanf("%d",&numR);
	while(!feof(fpr))
	{
		fscanf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat);
		if(numReservation==numR)
		{
			tr=1;
			printf("Code classe: %d\n",codeClasse);
			printf("Code salle: %d\n",codeSalle);
			printf("Date: %s\n",date);
			printf("Heure de debut: %s\n",heureDebut);
			printf("Duree: %d heure\n",duree);
			printf("Motif: %s\n",motif);
			printf("Etat: %s\n",etat);
		}
	}
	if(tr==0)
	{
		printf("la reservation n'existe pas!!!\n");
	}
	fclose(fpr);
}
void recherchereservationclasse()
{
	int codeR,tr=0;
	fpr=fopen("reservation.txt","rt");
	if(fpr==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le code de la classe:");
	scanf("%d",&codeR);
	while(fscanf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat) != EOF)
	{
		if(codeClasse==codeR && (strcmp(etat,"valide")==0 || strcmp(etat,"encours")==0))
		{
			tr=1;
			printf("\nReservation numero: %d\n",numReservation);
			printf("Code salle: %d\n",codeSalle);
			printf("Date: %s\n",date);
			printf("Heure de debut: %s\n",heureDebut);
			printf("Duree: %d heure\n",duree);
			printf("Motif: %s\n",motif);
			printf("Etat: %s\n",etat);

		}
	}
	if(tr==0)
	{
		printf("Aucune reservation trouvee pour cette classe\n");
	}
	fclose(fpr);
}

void recherchereservationsalle()
{
	int codeR,tr=0;
	fpr=fopen("reservation.txt","rt");
	if(fpr==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le code de la salle:");
	scanf("%d",&codeR);
	while(fscanf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat) != EOF)
	{
		if(codeSalle==codeR && (strcmp(etat,"valide")==0 || strcmp(etat,"encours")==0))
		{
			tr=1;
			printf("\nReservation numero: %d\n",numReservation);
			printf("Code classe: %d\n",codeClasse);
			printf("Date: %s\n",date);
			printf("Heure de debut: %s\n",heureDebut);
			printf("Duree: %d heure\n",duree);
			printf("Motif: %s\n",motif);
			printf("Etat: %s\n",etat);
		}
	}
	if(tr==0)
	{
		printf("Aucune reservation trouvee pour cette salle\n");
	}
	fclose(fpr);
}

void modifieretatreservation()
{
	int numR,tr=0;
	FILE*fa,*fpr;
	fpr=fopen("reservation.txt","rt");
	if(fpr==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	fa=fopen("fa.txt","wt");
	if(fa==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le numero de la reservation a modifier:");
	scanf("%d",&numR);
	while(fscanf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat) != EOF)
	{
		if(numReservation==numR)
		{
			tr=1;
			printf("donner le nouvel etat (reserve/annule/valide/encours/termine):");
			scanf("%s",etat);
		}
		fprintf(fa,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",numReservation,codeClasse,codeSalle,date,heureDebut,duree,motif,etat);
	}
	fclose(fpr);
	fclose(fa);
	remove("reservation.txt");
	rename("fa.txt","reservation.txt");
	if(tr==0)
		printf("la reservation n'existe pas\n");
	else
		printf("l'etat de la reservation a ete modifie\n");
}

void supprimerreservation()
{
	int numR,tr=0;
	FILE*fa,*fpr;
	fpr=fopen("reservation.txt","rt");
	if(fpr==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	fa=fopen("fa.txt","wt");
	if(fa==NULL)
	{
		printf("impossible d'ouvrir le fichier\n");
		exit(1);
	}
	printf("donner le numero de la reservation a supprimer:");
	scanf("%d",&numR);
	while(fscanf(fpr,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",&numReservation,&codeClasse,&codeSalle,date,heureDebut,&duree,motif,etat) != EOF)
	{
		if(numReservation!=numR)
			fprintf(fa,"%d\n %d\n %d\n %s\n %s\n %d\n %s\n %s\n",numReservation,codeClasse,codeSalle,date,heureDebut,duree,motif,etat);
		else
			tr=1;
	}
	fclose(fpr);
	fclose(fa);
	remove("reservation.txt");
	rename("fa.txt","reservation.txt");
	if(tr==0)
		printf("la reservation n'existe pas\n");
	else
		printf("la reservation a ete supprimee\n");
}











void affichageplanningrc1()
{
	FILE*fpplanning;
	char planning[20];
	fpplanning=fopen("planning rc1.txt","rt");
	if(fpplanning==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planning,sizeof(planning),fpplanning)  !=NULL)
	{
		printf("%s",planning);
	}
fclose(fpplanning);

}
void affichageplanningrc2()
{
	FILE*fpplanning2;
	char planningg[20];
	fpplanning2=fopen("planning rc2.txt","rt");
	if(fpplanning2==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planningg,sizeof(planningg),fpplanning2)  !=NULL)
	{
		printf("%s",planningg);
	}
fclose(fpplanning2);

}
void affichageplanningrc3()
{
	FILE*fpplanning3;
	char planninggg[20];
	fpplanning3=fopen("planning rc3.txt","rt");
	if(fpplanning3==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planninggg,sizeof(planninggg),fpplanning3)  !=NULL)
	{
		printf("%s",planninggg);
	}
fclose(fpplanning3);

}

void affichageplanningrc4()
{
	FILE*fpplanning4;
	char planningggg[20];
	fpplanning4=fopen("planning rc4.txt","rt");
	if(fpplanning4==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planningggg,sizeof(planningggg),fpplanning4)  !=NULL)
	{
		printf("%s",planningggg);
	}
fclose(fpplanning4);

}

void affichageplanningTPE1()
{
	FILE*fpplanning5;
	char planninggggg[20];
	fpplanning5=fopen("planning tp E1.txt","rt");
	if(fpplanning5==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planninggggg,sizeof(planninggggg),fpplanning5)  !=NULL)
	{
		printf("%s",planninggggg);
	}
fclose(fpplanning5);

}
void affichageplanningTPE2()
{
	FILE*fpplanning6;
	char planningggggg[20];
	fpplanning6=fopen("planning tp E2.txt","rt");
	if(fpplanning6==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planningggggg,sizeof(planningggggg),fpplanning6)  !=NULL)
	{
		printf("%s",planningggggg);
	}
fclose(fpplanning6);

}
void affichageplanningTPE3()
{
	FILE*fpplanning7;
	char planninggggggg[20];
	fpplanning7=fopen("planning tp E3.txt","rt");
	if(fpplanning7==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planninggggggg,sizeof(planninggggggg),fpplanning7)  !=NULL)
	{
		printf("%s",planninggggggg);
	}
fclose(fpplanning7);

}
void affichageplanningTP_extension()
{
	FILE*fpplanning8;
	char planningggggggg[20];
	fpplanning8=fopen("planning TP EXTENSION.txt","rt");
	if(fpplanning8==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planningggggggg,sizeof(planningggggggg),fpplanning8)  !=NULL)
	{
		printf("%s",planningggggggg);
	}
fclose(fpplanning8);

}
void affichageplanningamphi3()
{
	FILE*fpplanning9;
	char planninggggggggg[20];
	fpplanning9=fopen("planning amphi3.txt","rt");
	if(fpplanning9==NULL)
	 {
    	printf("impossible d'ouvrir le fichier\n");
    	exit(1);
	
	}	
	while(fgets(planninggggggggg,sizeof(planninggggggggg),fpplanning9)  !=NULL)
	{
		printf("%s",planninggggggggg);
	}
fclose(fpplanning9);

}
#endif