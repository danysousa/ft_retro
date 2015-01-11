/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:19:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 20:24:14 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "../GameEngine/GameObject.hpp"

class Map : public GameObject
{
	public:
		Map( void );
		Map( Map & cpy );
		virtual ~Map( void );

		Map &			operator=( Map & rhs );
};

#endif
