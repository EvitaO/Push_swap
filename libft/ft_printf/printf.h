/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:52:40 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:25:50 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

/*
**# define HASHTAG		(1 << 0)	0000 0000 0000 0001
**# define SPACE		(1 << 1)	0000 0000 0000 0010
**# define PLUS			(1 << 2) 	0000 0000 0000 0100
**# define ZERO			(1 << 3)  	0000 0000 0000 1000
**# define MINUS		(1 << 4)  	0000 0000 0001 0000
**# define DOT			(1 << 5)  	0000 0000 0010 0000
**# define HH			(1 << 6)  	0000 0000 0100 0000
**# define H			(1 << 7)  	0000 0000 1000 0000
**# define ELL			(1 << 8)  	0000 0001 0000 0000
**# define ELLELL		(1 << 9)  	0000 0010 0000 0000
**# define L			(1 << 10)	0000 0100 0000 0000
*/

enum
{
	HASHTAG = (1 << 0),
	SPACE = (1 << 1),
	PLUS = (1 << 2),
	ZERO = (1 << 3),
	MINUS = (1 << 4),
	DOT = (1 << 5),
	HH = (1 << 6),
	H = (1 << 7),
	ELL = (1 << 8),
	ELLELL = (1 << 9),
	L = (1 << 10)
};

# define FLAGS	"0-#+ hlL.*"

typedef struct		s_flags
{
	short int		option;
	int				width;
	int				percision;
	char			type;
	int				count;
	int				floats_roundoff;
}					t_flags;

int					ft_printf(const char *restrict format, ...);

/*
**check/read input functions
*/

int					check_flags(va_list a, const char *f, \
					int j, t_flags *check);
int					check_num(t_flags *check, const char *format, int j, \
					va_list a);
int					check_format(va_list arg, const char *format, \
					int j, t_flags *check);
int					ft_put_flag_on(t_flags *check, const char *f, int j, \
					va_list a);
int					ft_check_hh_ll(t_flags *check, const char *f, int j);
int					ft_wildcard_num(t_flags *check, va_list a, \
					const char *format, int j);
void				ft_percent_flag(t_flags *check);
void				read_struct(t_flags *check, va_list arg);
long double			ft_check_arg(t_flags *check, va_list arg);
long long			ft_check_argid(t_flags *check, va_list arg);

/*
**basic functions
*/

void				ft_putstr_check(char const *s, t_flags *check);
void				ft_putnbr_base(unsigned long long nbr, int base, int ltr);
void				ft_width(int k, int stop, char c);
void				ft_print_width(t_flags *check, int len, int s);
void				ft_write_char(char c, t_flags *check);
char				*ft_itoa_base(unsigned long long n, int base, int ltr);
int					ft_count_num(unsigned long long n, int base);
void				ft_clean_struct(t_flags *check);

/*
**binary functions
*/

void				print_binary(t_flags *check, va_list arg);
void				ft_check_flagsb(t_flags *check, int i);
void				ft_big_bin(int i, t_flags *check, unsigned long long num);
void				ft_small_bin(int i, t_flags *check, unsigned long long num);

/*
**float functions
*/

void				ft_nan_inf(long double i, t_flags *check);
void				ft_write_inf_nan(long double i, t_flags *check);
void				ft_dec_nul(t_flags *check, unsigned long long x, \
					int tot, int sign);
void				ft_ifs_flo(t_flags *check, int tot, int sign, \
					unsigned long long x);
long double			ft_make_dec_num(unsigned long long *x, long double *i, \
					int *cnt);
void				ft_put_float(unsigned long long p, int tot, t_flags *check);
void				ft_write_width(t_flags *check, int tot);
void				input_flo(t_flags *check, va_list arg);
int					ft_check_pos(long double *i, t_flags *check, int b);
int					ft_check_hsp(t_flags *check);
unsigned long long	ft_flo_zero(long double i, t_flags *check);
unsigned long long	ft_flo_num(long double i, t_flags *check);
void				ft_negwth(t_flags *check, unsigned long long x, \
					long double i, int tot);
unsigned long long	roff(t_flags *c, unsigned long long x, int d, \
					long double n);
void				ft_write_flags2(t_flags *check, int sign);

/*
**string-char functions
*/

void				input_char_str(t_flags *check, va_list arg);
void				s_with_flag(t_flags *check, char *str);
void				s_with_flagwidth(t_flags *check, char *str);
void				s_flag_dot_width(t_flags *check, char *str);
void				s_flag_minus_dot(t_flags *check, char *str);
void				ft_print_char(char a, t_flags *check);

/*
**pointer functions
*/

void				p_with_flag(t_flags *check, unsigned long long ptr);
void				ft_print_pointer(t_flags *check, unsigned long long ptr);

/*
**diouxX functions
*/

void				input_base(t_flags *check, va_list arg);
void				input_int(t_flags *check, va_list arg);
void				input_octal_special(t_flags *check);
void				ft_input_id(t_flags *check, va_list arg);
void				input_hex(t_flags *check, va_list arg);
void				ft_hexaocta(char *num, t_flags *check);
void				ft_put_zeros(t_flags *check, int len, int *i, char *str);
void				ft_di_int(char *num, int s, t_flags *check);
void				ft_write_flags(t_flags *check, int sign);
void				ft_width_hexaocta(t_flags *check, char *str, \
					char *num, int i);
char				*ft_check_change(t_flags *check, int len, char **num);
char				*ft_check_hash(t_flags *check, int *i, char *str, int *len);
void				ft_check_width(int len, t_flags *check, int s);
int					ft_print_flags(t_flags *check, int sign, int len);
void				ft_print_plus_space_min(t_flags *check, int sign);
void				ft_print_width_sp(t_flags *check);

#endif
