/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveComponent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:03:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 11:52:35 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MoveComponent_HPP
# define MoveComponent_HPP
# include "../GameEngine/GameComponent.hpp"

class MoveComponent : public GameComponent
{
	public:
		MoveComponent( void );
		MoveComponent( int up, int down, int left, int right );
		MoveComponent( MoveComponent const & src );
		virtual ~MoveComponent( void );

		MoveComponent &		operator=( MoveComponent const & rhs );

		void		setKeyUp( int key );
		void		setKeyDown( int key );
		void		setKeyLeft( int key );
		void		setKeyRight( int key );
		int			getKeyUp( void ) const;
		int			getKeyDown( void ) const;
		int			getKeyLeft( void ) const;
		int			getKeyRight( void ) const;

	private:
		int			_keyUp;
		int			_keyDown;
		int			_keyLeft;
		int			_keyRight;
};

#endif
