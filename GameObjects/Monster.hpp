/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:00:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 17:58:28 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_HPP
# define MONSTER_HPP
# include <string>
# include "../GameEngine/GameObject.hpp"

class Monster : public GameObject
{
	public:
		Monster( void );
		Monster( std::string const & display );
		Monster( Monster & cpy );
		virtual ~Monster( void );

		Monster &		operator=( Monster & rhs );
		virtual void	init( CoreEngine & coreEngine );
		void			initConstructor( std::string const & display );
};

#endif
