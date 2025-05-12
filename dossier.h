
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
int code,effectif,codes,capacite;
char nom[20],niveau[20],position[20],machine[20];


FILE*fp;
FILE*fps;
void creationclasse(void);
void affichageclasse(void);
void modifierclasse(void);
void supprimerclasse(void);
void creationsalle(void);
void affichagesalle(void);
void modifiersalle(void);
void supprimersalle(void);

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
#endif