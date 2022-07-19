# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_libs.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:11:09 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/19 15:27:09 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURR_PATH=$(dirname "$(readlink -f "$0")")

if [ $(uname) = 'Linux' ]
then
	MINILIBX_PATH='../../minilibx/minilibx-linux'
elif [ $(uname) = 'Darwin' ]
then
	MINILIBX_PATH='../../minilibx/minilibx-macos'
else
	MINILIBX_PATH='.'
	echo "Unsuported OS"
fi

MTXLIB_PATH='../../mtxlib'
LIBFT_PATH='../../libft'


if [ -d $MINILIBX_PATH -a -f $MINILIBX_PATH"/libmlx.a" ]; then
	echo "creating libmlx.a link"
	ln $MINILIBX_PATH"/libmlx.a" $CURR_PATH'/libmlx.a'
else
	echo "Missing minilibx library"
fi

if [ -d $MTXLIB_PATH -a -f $MTXLIB_PATH"/libmtx.a" ]; then
	echo "creating libmtx.a link"
	ln $MTXLIB_PATH"/libmtx.a" $CURR_PATH'/libmtx.a'
else
	echo "Missing mtxlib library"
fi

if [ -d $LIBFT_PATH -a -f $LIBFT_PATH"/libft.a" ]; then
	echo "creating libft.a link"
	ln $LIBFT_PATH"/libft.a" $CURR_PATH'/libft.a'
else
	echo "Missing libft library"
fi
