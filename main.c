
#include "incs/libasm.h"
#include <string.h>
#include <stdio.h>


int main()
{
	//char *dst;

	//dst = ft_strcpy("lala", "prout");
	//printf("%s\n", dst);
	//printf("fuck\n");
	//printf(".c = %d\n", arg_int_ret_c());
	//printf(".s = %d\n", arg_int_ret());
	//printf("fuck\n");
	//int res = ft_addition(5, 45);
	//printf("addition.s = %d\n", res);
	//printf("addition.c = %d\n", ft_addition_c(5, 45));

/* *** STRLEN *** */

	//char *ptr_null = 0;
	char *str_vide = "";
	char *str_std = "Salut les bouzeuh";
	char *str_long = "C’est la version optimisée (-O3) pour le mode ARM et cette fois nous voyons B comme dernière instruction au lieu du BL habituel. Une autre différence entre cette version optimisée et la précédente (compilée sans optimisation) est l’absence de fonctions prologue et épilogue (les instructions qui préservent les valeurs des registres R0 et LR). L’instruction B saute simplement à une autre adresse, sans manipuler le registre LR de façon similaire au JMP en x86. Pourquoi est-ce que fonctionne? Parce ce code est en fait bien équivalent au précédent. Il y a deux raisons principales: 1) Ni la pile ni SP (pointeur de pile) ne sont modifiés; 2) l’appel à printf() est la dernière instruction, donc il ne se passe rien après. A la fin, la fonction printf() rend simplement le contrôle à l’adresse stockée dans LR. Puisque LR contient actuellement l’adresse du point depuis lequel notre fonction a été appelée alors le contrôle après printf() sera redonné à ce point. Par conséquent, nous n’avons pas besoin de sauver LR car il ne nous est pas nécessaire de le modifier. Et il ne nous est non plus pas nécessaire de modifier LR car il n’y a pas d’autre appel de fonction excepté printf(). Par ailleurs, après cet appel nous ne faisons rien d’autre! C’est la raison pour laquelle une telleoptimisation est possible.";

printf("\n ......-* STRLEN : *-...................\n\n");

	printf("chaine vide : \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_vide), ft_strlen(str_vide));
	
	printf("chaine standard : \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_std), ft_strlen(str_std));
	
	printf("chaine longue: \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_long), ft_strlen(str_long));
	
	printf("chaine nulle: (segfault) \n");
	//printf("\t %ld = strlen\n", strlen(ptr_null));
	//printf("\t %ld = ft_strlen.s\n", ft_strlen(ptr_null));

printf("\n ......-* STRCPY : *-...................\n\n");

	char dst[20] = {0, };

	printf("src = chaine std : \n");
	printf("\tstrcpy = %s\n", strcpy(dst, str_std));

	printf("src = chaine vide :  \n");
	printf("\tstrcpy = |%s|\n", strcpy(dst, str_vide));

	printf("src = chaine vide :  \n");
	printf("\tstrcpy = |%s|\n", strcpy(dst, str_long));
	
	return (0);
}