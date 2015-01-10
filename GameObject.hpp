/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 14:26:28 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT
# define GAME_OBJECT

class GameObject
{
public:
	GameObject( void );
	GameObject( GameObject const & src );
	virtual ~GameObject( void );

	GameObject &		operator=( GameObject const & rhs );

// private:
// 	Vector2f *			_pos;

};

#endif
