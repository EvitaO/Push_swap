/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:29:18 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 15:52:44 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct			s_node
{
	int					nbr;
	int					pos;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct			s_optie
{
	int					i;
}						t_options;

int						str_argument(char **argv, t_node **stack_a);

void					ft_check_input(char **str, int argc);
void					ft_check_numb(char **str, int argc);
double					ft_atoidouble(const char *str);

int						check_if_sort(t_node **a);

int						lst_size_rev(t_node *lst);

void					first_elem(t_node **a, t_node **b);
t_node					*make_node(char *str, t_node **stack_a);
void					make_list(t_node **stack_a, int i, char **argv);

void					print_list(t_node **a, t_node **b);
t_node					*goto_end(t_node **stack);

/*
**-------------------------The possible moves
*/

void					swap(t_node **stack);
void					ft_swap_a(t_node **stack);
void					ft_swap_b(t_node **stack);
void					ft_swap_ab(t_node **stack_a, t_node **stack_b);

void					ft_push_a(t_node **stack_src, t_node **stack_des);
void					ft_push_b(t_node **stack_src, t_node **stack_des);

void					ft_rotate_a(t_node **stack);
void					ft_rotate_b(t_node **stack);
void					ft_rotate(t_node **stack);
void					ft_rotate_ab(t_node **stack_a, t_node **stack_b);

void					ft_rev_rotate(t_node **stack);
void					ft_rev_rotate_a(t_node **stack);
void					ft_rev_rotate_b(t_node **stack);
void					ft_rev_rotate_ab(t_node **stack_a, t_node **stack_b);

/*
**---------------------------moves voor checker
*/

void					push(t_node **stack_src, t_node **stack_des);
void					check_swap(t_node **stack);
void					swap_ab(t_node **stack_a, t_node **stack_b);
void					rev_rotate(t_node **stack);
void					rev_rotate_ab(t_node **stack_a, t_node **stack_b);
void					rotate(t_node **stack);
void					rotate_ab(t_node **stack_a, t_node **stack_b);

/*
**--------------------------------till 5 arg
*/

void					max_five(t_node **a, t_node **b, int argc);
void					max_three_numb(t_node **a);
void					rev_max_three_numb(t_node **b);

/*
**------------------------------put position
*/

void					put_pos(t_node **a, int size);
int						find_nbr(t_node **a);
void					set_position(t_node **a, int num, int p);

/*
**-----------------------------------sorting
*/

int						end_of_list(t_node **s);

void					sort_alg(t_node **stack_a, t_node **stack_b, int argc);
void					check_rotate_a(t_node **a, int pos);
void					check_rotate_exacte_a(t_node **a, int pos);
void					check_rotate_exacte_b(t_node **b, int pos);
void					check_rotate_b(t_node **b, int pos);
void					merge_to_b(t_node **a, t_node **b, int size);
void					merge_to_a(t_node **a, t_node **b, int middle);
void					start_sort(t_node **a, t_node **b);

void					sort_part_2(t_node **a, t_node **b, int size, \
						int max_pos);
void					sort_part_3(t_node **a, t_node **b);

int						checks_for_sort_b(t_node **a, t_node **b, int tail);
int						checks_for_sort_b_2(t_node **a, t_node **b, int i);
int						checks_for_sort_a(t_node **a, t_node **b, int tail);
int						checks_for_sort_a_2(t_node **a, t_node **b, int i);

void					free_list(t_node **a, t_node **b);

/*
**------------------------------------checker
*/

int						check_if_sorted(t_node **a, int size);
void					checker(t_node **a, t_node **b);
int						execute(char *str, t_node **a, t_node **b);

/*
**------------------------------------option
*/

void					set_option(char *str, t_options *option);
void					do_option(t_node **a, t_node **b);
void					do_help(void);

#endif
