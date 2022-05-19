/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:53:40 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/18 18:41:32 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
//----------------------------------  ft_lstnew
t_philo	*ft_lstnew(int id, t_args *shared_data)
{
	t_philo	*element;

	element = (t_philo *)malloc(sizeof(t_philo));
	if (!element)
		return (0);
	pthread_mutex_init(&(element->fork), NULL);
	element->id = id;
	element->meals_eaten = 0;
	element->shared_data = shared_data;
	element->last_meal = 0;
	element->next = NULL;
	return (element);
}

//------------------------------------ ft_add_back
void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*lastnode;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	else if (*lst != NULL)
	{
		lastnode = ft_lstlast(lst);
		lastnode->next = new;
	}
}

//---------------------------------------- find last node int list 
t_philo	*ft_lstlast(t_philo **lst)
{
	t_philo	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}
