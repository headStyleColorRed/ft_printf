//
//  ft_check_if_character.c
//  Wolfenstein
//
//  Created by Rodrigo  on 15/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../printf_lib.h"

int		ft_check_if_character(char str, char *characters)
{
	int i;
	
	i = 0;
	while (characters[i])
		if (characters[i++] == str)
			return (1);
	return (0);
}
