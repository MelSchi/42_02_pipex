/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:40:54 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 13:13:00 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	ft_strlen_del(const char *s, char del)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != del && s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	size_t	join_len;
	size_t	i;

	i = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	join_len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) ft_calloc ((join_len + 1), sizeof (char));
	if (join == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	join[i] = s2[0];
	free(s1);
	return (join);
}
