
#include "incs/libasm.h"
#include <string.h>
#include <stdio.h>


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	return (!(*s1) || *s1 != *s2
			? (unsigned char)*s1 - (unsigned char)*s2
			: ft_strncmp(++s1, ++s2, --n));
}

int main()
{

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
	char dst2[20] = {0, };

	printf("dst2 = %p\ndst= %p\n", dst2, dst);
	printf("src = chaine std : \n");
	printf("\tft_strcpy = |%s|	%p\n", ft_strcpy(dst2, str_std), dst2);
	printf("\tstrcpy = |%s|	%p\n\n", strcpy(dst, str_std), dst);

	printf("src = chaine vide :  \n");
	printf("\tft_strcpy = |%s| %p\n", ft_strcpy(dst2, str_vide), dst2);
	printf("\tstrcpy = |%s| %p\n\n", strcpy(dst, str_vide), dst);

	printf("src len > dst len : (segfault) \n");
//	printf("\tstrcpy = |%s|\n", strcpy(dst, str_long));
//	printf("\tft_strcpy = |%s|\n", ft_strcpy(dst2, str_long));

	printf("\n ......-* STRCPMP : *-...................\n\n");

	printf("chaines identiques\n");
	printf("%d = strcmp\n", strcmp(str_std, str_std));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, str_std));

	printf("chaines diff\n");
	printf("%d = strcmp\n", strcmp(str_std, str_long));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, str_long));

	printf("chaines diff dont une vide\n");
	printf("%d = strcmp\n", strcmp( "", str_std));
	printf("%d = ft_strcmp\n\n", ft_strcmp("", str_std));

	printf("chaines diff dont une vide\n");
	printf("%d = strcmp\n", strcmp(str_std, ""));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, ""));
	return (0);
}