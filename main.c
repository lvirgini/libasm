// FOR READ IS THE FIRST LINE 
#include "incs/libasm.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{

	char *ptr_null = 0;
	char *str_vide = "";
	char *str_std = "Salut les bouzeuh";
	char *str_long = "C’est la version optimisée (-O3) pour le mode ARM et cette fois nous voyons B comme dernière instruction au lieu du BL habituel. Une autre différence entre cette version optimisée et la précédente (compilée sans optimisation) est l’absence de fonctions prologue et épilogue (les instructions qui préservent les valeurs des registres R0 et LR). L’instruction B saute simplement à une autre adresse, sans manipuler le registre LR de façon similaire au JMP en x86. Pourquoi est-ce que fonctionne? Parce ce code est en fait bien équivalent au précédent. Il y a deux raisons principales: 1) Ni la pile ni SP (pointeur de pile) ne sont modifiés; 2) l’appel à printf() est la dernière instruction, donc il ne se passe rien après. A la fin, la fonction printf() rend simplement le contrôle à l’adresse stockée dans LR. Puisque LR contient actuellement l’adresse du point depuis lequel notre fonction a été appelée alors le contrôle après printf() sera redonné à ce point. Par conséquent, nous n’avons pas besoin de sauver LR car il ne nous est pas nécessaire de le modifier. Et il ne nous est non plus pas nécessaire de modifier LR car il n’y a pas d’autre appel de fonction excepté printf(). Par ailleurs, après cet appel nous ne faisons rien d’autre! C’est la raison pour laquelle une telleoptimisation est possible.";

printf("\n ......-*  STRLEN  *-...................\n\n");

	printf("chaine vide : \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_vide), ft_strlen(str_vide));
	
	printf("chaine standard : \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_std), ft_strlen(str_std));
	
	printf("chaine longue: \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen(str_long), ft_strlen(str_long));
	
	printf("chaine nulle: (segfault) \n");
	//printf("\t %ld = strlen\n", strlen(ptr_null));
	//printf("\t %ld = ft_strlen.s\n", ft_strlen(ptr_null));

printf("\n ......-*  STRCPY  *-...................\n\n");

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

	printf("\n ......-*  STRCPMP  *-...................\n\n");

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

	printf("\n ......-*  WRITE : *-...................\n\n");

	printf("| ft_write = %ld\n", ft_write(1, ptr_null, 25));
	printf("| write = %ld\n", write(1, ptr_null, 25));

	printf("adresse str = %p, %s\n", str_std, str_std);
	printf("| write = %ld\n", write(1, str_std, 25));
	printf("| ft_write = %ld\n", ft_write(1, str_std, 25));
	printf("adresse str = %p, %s\n\n", str_std, str_std);

	printf("adresse str = %p, %s\n", str_std, str_std);
	printf("| write = %ld\n", write(1, str_std, 3));
	printf("| ft_write = %ld\n", ft_write(1, str_std, 3));
	printf("adresse str = %p, %s\n\n", str_std, str_std);

	printf("\n ......-*  READ : *-...................\n\n");

	int fd = open("main.c", O_RDONLY);
	char buf[20] = {0, };
	char buf2[20] = {0, };

	printf("fd = %d\n", fd);
	printf("read ptr null = %d |%s|\n", read(fd, ptr_null, 15), buf);
	printf("ft_read ptr null = %d |%s|\n\n", read(fd, ptr_null, 15), buf2);

	printf("read fd -1= %d |%s|\n", read(-1, buf, 15), buf);
	printf("ft_read fd -1 = %d |%s|\n\n", read(-1, buf2, 15), buf2);
	
	printf("read fd 45 = %d |%s|\n", read(45, buf, 15), buf);
	printf("ft_read fd 45 = %d |%s|\n\n", read(45, buf2, 15), buf2);

	printf("read = %d |%s|\n", read(fd, buf, 15), buf);
	printf("ft_read = %d |%s|\n\n", read(fd, buf2, 15), buf2);
		
	close(fd);

	printf("\n ......-*  STRDUP : *-...................\n\n");

	char *str_dup1 = strdup(str_std);
	printf("%p = |%s| = strdup\n", str_dup1, str_dup1);

	char *str_dup2 = ft_strdup(str_std);
	printf("%p = |%s| = ft_strdup\n\n", str_dup2, str_dup2);

	str_dup1 = strdup(str_vide);
	printf("%p = |%s| = strdup\n", str_dup1, str_dup1);

	str_dup2 = ft_strdup(str_vide);
	printf("%p = |%s| = ft_strdup\n", str_dup2, str_dup2);
	free(str_dup1);
	free(str_dup2);

	return (0);
}
