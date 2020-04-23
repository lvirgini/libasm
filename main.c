// FOR READ IS THE FIRST LINE 
#include "incs/libasm.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

/*
** dans gdb set disassembly-flavor intel
**
** Avec GCC, l'option -Wpadded pour voir si il y a besoin de restructurer
** des structure afin qu'elle prennent le moins de place. 
**
** objdump -s a.out
**
** strace df -h  : montre les appels systems
*/

void	ft_free_data(void * data)
{
}


void		print_list(t_list *lst)
{
	int i = 0;

	//printf("&list = %p\n list = %llx\n", lst, lst);
	while(lst && ++i)
	{
		printf("%d = %p : data = %s\t &next : %p  next = %llx\n", i, lst->data, lst->data, &lst->next, lst->next);
		lst = lst->next;
	}
	printf("\n");
}

void		ft_list_remove_if2(t_list **begin_list,void*data_ref,
								int(*cmp)(), void(*free_fct)(void*))
{
	t_list	*save_next;

	while (*begin_list)
	{
		if (cmp(data_ref, (*begin_list)->data) == 0)
		{	
			free_fct((*begin_list)->data);
			save_next = (*begin_list)->next;
			free(*begin_list);
			*begin_list = save_next;
			begin_list = &(*begin_list);
		}
		else
			begin_list = &(*begin_list)->next;
	}



}


t_list		*ft_lstnew(void *content)
{
	t_list *l;

	if (!(l = (t_list *)malloc(sizeof(l))))
		return (NULL);
	if (!(l->data = malloc(sizeof(* content))))
		return (NULL);
	l->data = content;
	l->next = NULL;
	return (l);
}



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
	
	printf("chaine \"\\t\\n\\v\" : \n");
	printf("\t %ld = strlen\n\t %ld = ft_strlen.s\n", strlen("\t\n\v"), ft_strlen("\t\n\v"));

	printf("chaine nulle: \n\t(strlen segfault) \n");
	//printf("\t %ld = strlen\n", strlen(ptr_null));
	//printf("\t %ld = ft_strlen.s\n", ft_strlen(ptr_null));



printf("\n ......-*  STRCPY  *-...................\n\n");

	char dst[20] = {0, };
	char dst2[20] = {0, };

	printf("dst2 = %p\ndst  = %p\n\n", dst2, dst);

	printf("src = chaine std : \n");
	printf("\tft_strcpy = \t|%s|	%p\n", ft_strcpy(dst2, str_std), dst2);
	printf("\tstrcpy = \t|%s|	%p\n\n", strcpy(dst, str_std), dst);

	printf("src = chaine vide :  \n");
	printf("\tft_strcpy = \t|%s| \t%p\n", ft_strcpy(dst2, str_vide), dst2);
	printf("\tstrcpy = \t|%s| \t%p\n\n", strcpy(dst, str_vide), dst);

	printf("src len > dst len : (segfault) \n");
//	printf("\tstrcpy = |%s|\n", strcpy(dst, str_long));
//	printf("\tft_strcpy = |%s|\n", ft_strcpy(dst2, str_long));

	printf("src = Null : (segfault)\n");
//	printf("\tft_strcpy = \t|%s| \t%p\n", ft_strcpy(dst2, ptr_null), dst2);
//	printf("\tstrcpy = \t|%s| \t%p\n\n", strcpy(dst, ptr_null), dst);

	printf("\n ......-*  STRCPMP  *-...................\n\n");

	printf("chaines identiques\n");
	printf("%d = strcmp\n", strcmp(str_std, str_std));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, str_std));

	printf("chaines diff\n");
	printf("%d = strcmp\n", strcmp(str_std, str_long));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, str_long));

	printf("chaines diff dont s1 = vide\n");
	printf("%d = strcmp\n", strcmp( "", str_std));
	printf("%d = ft_strcmp\n\n", ft_strcmp("", str_std));

	printf("chaines diff dont s2 = vide\n");
	printf("%d = strcmp\n", strcmp(str_std, ""));
	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, ""));

	printf("chaines diff si une des deux est null = (segfault)\n");
//	printf("%d = strcmp\n", strcmp( ptr_null, str_std));
//	printf("%d = ft_strcmp\n\n", ft_strcmp(ptr_null, str_std));

//	printf("%d = strcmp\n", strcmp(str_std, ptr_null));
//	printf("%d = ft_strcmp\n\n", ft_strcmp(str_std, ptr_null));


	printf("\n ......-*  WRITE : *-...................\n\n");
///

	long long ret_write = 0;

	printf("pointeur Null :\n");
	errno = 0;
	ret_write = ft_write(1, ptr_null, 25);
	printf("| ft_write  \t= %ld\t errno = %d\n", ret_write, errno);

	errno = 0;
	ret_write = write(1, ptr_null, 25);
	printf("|    write  \t= %ld\t errno = %d\n\n", ret_write, errno);


	printf("\"str_std\" : \n");
	errno = 0;
	ret_write = write(1, str_std, strlen(str_std));
	printf("|    write  \t= %ld\t errno = %d\n", ret_write, errno);

	errno = 0;
	ret_write = ft_write(1, str_std, ft_strlen(str_std));
	printf("| ft_write \t= %ld\t errno = %d\n\n", ret_write, errno);


	printf("str standard : size > len \n");
	errno = 0;
	ret_write = write(1, str_std, 28);
	printf("|    write  \t= %ld\t errno = %d\n", ret_write, errno);

	errno = 0;
	ret_write = ft_write(1, str_std, 28);
	printf("| ft_write  \t= %ld\t errno = %d\n\n", ret_write, errno);


//

	printf("str standard : size < len\n");
	errno = 0;
	ret_write = write(1, str_std, 3);
	printf("|    write  \t= %ld\t errno = %d\n", ret_write, errno);

	errno = 0;
	ret_write = ft_write(1, str_std, 3);
	printf("| ft_write  \t= %d\t errno = %d\n\n", ret_write, errno);
	


	printf("\n ......-*  READ : *-...................\n\n");

	int fd = open("main.c", O_RDONLY);
	char buf[20] = {0, };
	char buf2[20] = {0, };
	int  ret_read = 0;

	printf("fd = %d\n", fd);

	errno = 0;
	ret_read = read(fd, ptr_null, 15);
	printf("   read ptr null = %d |%s|	errno = %d\n", ret_read, buf, errno);
	errno = 0;
	ret_read = ft_read(fd, ptr_null, 15);
	printf("ft_read ptr null = %d |%s|	errno = %d\n\n", ret_read, buf2, errno);


	errno = 0;
	ret_read = read(-1, buf, 15);
	printf("   read fd -1 = %d |%s|	errno = %d\n", ret_read, buf, errno);
	errno = 0;
	ret_read = ft_read(-1, buf, 15);
	printf("ft_read fd -1 = %d |%s|	errno = %d\n\n", ret_read, buf2, errno);


	errno = 0;
	ret_read =  read(75, buf, 15);
	printf("   read fd 75 = %d |%s|	errno = %d\n",ret_read, buf, errno);
	errno = 0;
	ret_read = ft_read(75, buf2, 15);
	printf("ft_read fd 75 = %d |%s|	errno = %d\n\n",ret_read , buf2, errno);


	printf("   read = %d |%s|\n", read(fd, buf, 15), buf);
	printf("ft_read = %d |%s|\n\n", ft_read(fd, buf2, 15), buf2);


	close(fd);


	printf("\n ......-*  STRDUP : *-...................\n\n");

	char *str_dup1 = strdup(str_std);
	printf("%p = |%s| = strdup\n", str_dup1, str_dup1);
	free(str_dup1);

	char *str_dup2 = ft_strdup(str_std);
	printf("%p = |%s| = ft_strdup\n\n", str_dup2, str_dup2);
	free(str_dup2);
	

	str_dup1 = strdup(str_vide);
	printf("%p = |%s| = strdup\n", str_dup1, str_dup1);
	free(str_dup1);

	str_dup2 = ft_strdup(str_vide);
	printf("%p = |%s| = ft_strdup\n\n", str_dup2, str_dup2);
	free(str_dup2);


	printf("strdup(NULL) = segfault\n\n");
//	str_dup1 = strdup(ptr_null);
//	printf("%p = |%s| = strdup\n", str_dup1, str_dup1);
//	free(str_dup1);

//	str_dup2 = ft_strdup(ptr_null);
//	printf("%p = |%s| = ft_strdup\n", str_dup2, str_dup2);
//	free(str_dup2);


	printf("\n ......-*  ATOI_BASE : *-...................\n\n");

	printf("%d\n",ft_atoi_base("       ++---1100d0", "01 456"));
	printf("%d\n",ft_atoi_base("       ++---1100d0", "01+456"));
	printf("%d\n",ft_atoi_base("       ++---1100d0", "01-56"));
	printf("%d\n",ft_atoi_base("       ++---az100d0", "01-56"));
	printf("%d\n",ft_atoi_base("       ++---1100d0", "01"));
	printf("%d\n",ft_atoi_base("       ++--1100d0", "01"));
	printf("%d\n",ft_atoi_base("       ---abc", "0123456789abcdef"));
	

	printf("\n ......-*  List_Push_Front + list size : *-...................\n\n");


    t_list *t = ft_lstnew("lst new");
	print_list(t);
	printf("list size = %d\n\n", ft_list_size(t));

	ft_list_push_front(&t, "front 1er");
	print_list(t);
	printf("list size = %d\n\n", ft_list_size(t));

	ft_list_push_front(&t, "front 2eme");
	print_list(t);
	printf("list size = %d\n\n", ft_list_size(t));



printf("\n ......-*  List_remove_if : *-...................\n\n");

	t_list *lst = NULL;

	ft_list_push_front(&lst, "dernier");
	ft_list_push_front(&lst, "nana");
	ft_list_push_front(&lst, "troisieme");
	ft_list_push_front(&lst, "deuxieme");
	ft_list_push_front(&lst, "nana");
	ft_list_push_front(&lst, "premier");
	printf("list size = %d\n\n", ft_list_size(lst));
	print_list(lst);


	int (*cmp)(const char *, const char *);
	cmp = &(ft_strcmp);

	void (*free_fct)(void *);
	free_fct = &(ft_free_data);
	

	// ft_list_remove_if2(&lst, "nana", cmp, free_fct);
	ft_list_remove_if(&lst, "nana", cmp, free_fct);
	print_list(lst);

printf("\n ......-*  List_sort : *-...................\n\n");

	/*ret = ft_list_sort(&t, cmp);
	printf("%d\n", ret);

	printf("list sort :: data = %d,  next = %d\n", *(int *)(t)->data, t->next);
	printf("list sort :: t->next->data = %d,  t->next->next = %d\n\n", *(int *)(t)->next->data, t->next->next);
	printf("list sort :: t->next->next->data = %d,  t->next->next->next = %d\n\n", *(int *)(t)->next->next->data, t->next->next->next);

	printf("t = %d  &t = %d\n", t, &t);
	printf("&data = %d,  &next = %d, &b = %d  &a = %d\n", &(t->data), &(t->next), &b, &a);
	printf("data = %d,  next = %d\n", t->data, t->next);
   
	//(*cmp)(list_ptr->data, other_list_ptr->data)



	*/return (0);
}
