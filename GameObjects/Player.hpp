/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 15:29:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER
# define PLAYER
# include <string>
# include "../GameEngine/GameObject.hpp"

class Player : public GameObject
{
public:
	Player( void );
	Player( std::string const & display );
	Player( Player const & src );
	virtual ~Player( void );

	Player &		operator=( Player const & rhs );

	void			init( std::string const & display );
};

#endif
