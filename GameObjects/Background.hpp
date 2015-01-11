/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:19:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 20:24:14 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP
# include "../GameEngine/GameObject.hpp"

class Background : public GameObject
{
	public:
		Background( void );
		Background( Background & cpy );
		virtual ~Background( void );

		Background &			operator=( Background & rhs );
};

#endif
