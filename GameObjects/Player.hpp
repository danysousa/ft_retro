/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:38:05 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 18:42:07 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER
# define PLAYER
# include "GameEngine/GameObject.hpp"

class Player : public GameObject
{
public:
	Player( void );
	Player( Player const & src );
	virtual ~Player( void );

	Player &			operator=( Player const & rhs );

};

#endif
