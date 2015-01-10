/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:54:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 14:24:01 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GameObject.hpp"

GameObject::GameObject()
{
	return ;
}

GameObject::GameObject( GameObject const & src )
{
	*this = src;
	return ;
}

GameObject::~GameObject()
{
	return ;
}


GameObject &	GameObject::operator=( GameObject const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}
