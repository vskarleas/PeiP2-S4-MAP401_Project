#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc!=1)
    {
        printf("No arguments are required for this test\n");
        exit(-2);
    }
    //Test no 4
    printf("Starting Test 4\n");
    Image I;
    printf("Enter the ame of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);

    char *fichier=malloc(strlen(name)+4);
    char *exit_file=malloc(strlen(name)+4);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    strcpy(exit_file,name);
    strcat(exit_file,".txt");

    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("=====================\n");
    printf("Test du Contour\n");
    printf("=====================\n");
    Contour k;
    k = algo_contour(I, exit_file); //1 here will be controlled from a variable on Tache 5 where more contpurs are required to be added on the same file
    printf("=====================\n");
    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    //We could definitely pass the FILE ready from here, but there was an issue with the file's signatures for access
    printf("=====================\n");
    return 0;

}
