# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_includes.sh                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 19:27:55 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/19 15:23:40 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

CURR_PATH=$(dirname "$(readlink -f "$0")")

echo "CURR_PATH ${CURR_PATH}"

if [ $(uname) = 'Linux' ]
then
	MINILIBX_PATH_I='../../minilibx/minilibx-linux'
elif [ $(uname) = 'Darwin' ]
then
	MINILIBX_PATH_I='../../minilibx/minilibx-macos'
else
	MINILIBX_PATH_I='.'
	echo "Unsuported OS"
fi

MLX_ADDONS_PATH_I='../mlx_addons/includes'
MTXLIB_PATH_I='../../mtxlib/includes'
LIBFT_PATH_I='../../libft'

INCL_LIST='MINILIBX_PATH_I MLX_ADDONS_PATH_I MTXLIB_PATH_I LIBFT_PATH_I'
#echo "include list : ${INCL_LIST}"


#for p in "${INCL_LIST[@]}"
for p in $INCL_LIST
do
	echo $p
	echo "${!p}"
	$(cd "${!p}" && cp *.h $CURR_PATH)
#	echo "copying include file $p"
#	$(cd "${p}" && cp *.h $CURR_PATH)
#	cd $p
#	cp *.h $CURR_PATH
#	cd $CURR_PATH
done
