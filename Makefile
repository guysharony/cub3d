# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 07:41:52 by gsharony          #+#    #+#              #
#    Updated: 2020/01/23 10:14:20 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G			= game/

R			= graphic/

L			= lib/

GP			= ${G}positions/

GM			= ${G}move/

GS			= ${G}setters/

LL			= ${L}libft/

LP			= ${L}parser/

LPM			= ${LP}map/

LPC			= ${LP}check/

POSITIONS	= ${GP}compute_wall.c ${GP}dlt_dst.c ${GP}get_sld.c ${GP}get_stp.c ${GP}get_texture_posx.c \
			  ${GP}get_wallc.c ${GP}get_wallx.c ${GP}map_pos.c ${GP}ray_dir.c ${GP}set_draw.c ${GP}set_hit.c ${GP}sld_int.c \
			  ${GP}spt_draw.c ${GP}spt_invdet.c ${GP}spt_pos.c ${GP}spt_screenx.c ${GP}spt_size.c ${GP}spt_texture.c ${GP}spt_transform.c ${GP}stp_int.c \

MOVE		= ${GM}move_backward.c ${GM}move_forward.c ${GM}move_left.c ${GM}move_right.c ${GM}rotate_left.c ${GM}rotate_right.c

SETTERS		= ${GS}set_colors.c ${GS}set_data.c ${GS}set_player.c ${GS}set_resolution.c ${GS}set_world.c

GAME		= ${G}context.c ${G}environment.c ${G}event.c ${G}game.c ${POSITIONS} ${MOVE} ${SETTERS}

GRAPHIC		= ${R}color.c ${R}get_texture.c ${R}graphic.c

PARSER		= ${LP}parse.c ${LP}parsecommands.c ${LP}parsemap.c \
			  ${LPM}get_check.c ${LPM}get_height.c ${LPM}get_init.c ${LPM}get_line.c ${LPM}get_walls.c ${LPM}get_width.c \
			  ${LPC}arguments.c ${LPC}blocks.c ${LPC}color.c ${LPC}end.c ${LPC}files.c ${LPC}map.c ${LPC}player.c ${LPC}resolution.c

LIBFT		= ${LL}clean.c ${LL}ft_atoi.c ${LL}ft_bzero.c ${LL}ft_calloc.c ${LL}ft_error.c ${LL}ft_files.c ${LL}ft_includes.c ${LL}ft_isdigit.c ${LL}ft_isnumber.c \
			  ${LL}ft_ispresent.c ${LL}ft_jumpline.c ${LL}ft_memset.c ${LL}ft_parsecolor.c ${LL}ft_putchar.c ${LL}ft_putchar_fd.c ${LL}ft_putnbr.c ${LL}ft_putnbr_fd.c \
			  ${LL}ft_putstr.c ${LL}ft_putstr_fd.c ${LL}ft_split.c ${LL}ft_strchr.c ${LL}ft_strcpy.c ${LL}ft_strdup.c ${LL}ft_strjoin.c ${LL}ft_strlen.c ${LL}ft_strmcpy.c \
			  ${LL}ft_strncmp.c ${LL}ft_strrchr.c ${LL}ft_substr.c ${LL}get_next_line.c ${LL}bitmap.c ${LL}buf.c

LIB			= ${LIBFT} ${PARSER}

SRCS		= main.c ${GAME} ${GRAPHIC} ${LIB}

OBJS		= ${SRCS:.c=.o}

INCLUDES	= include

RM			= rm -f

CFLAGS		= -I ${INCLUDES}

EXE			= cub3d

all:		${EXE}

${EXE}:		${OBJS}
			gcc ${CFLAGS} -o ${EXE} ${OBJS} -lmlx -framework OpenGL -framework AppKit

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

.PHONY:		all clean fclean
