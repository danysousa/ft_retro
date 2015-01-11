/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveKeyComponent.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:03:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 15:54:50 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEKEYCOMPONENT_HPP
# define MOVEKEYCOMPONENT_HPP
# include "MoveComponent.hpp"

class MoveKeyComponent : public MoveComponent
{
	public:
		MoveKeyComponent( void );
		MoveKeyComponent( int up, int down, int left, int right, float speed );
		MoveKeyComponent( MoveKeyComponent const & src );
		virtual ~MoveKeyComponent( void );

		MoveKeyComponent &		operator=( MoveKeyComponent const & rhs );

		void					setKeyUp( int key );
		void					setKeyDown( int key );
		void					setKeyLeft( int key );
		void					setKeyRight( int key );
		int						getKeyUp( void ) const;
		int						getKeyDown( void ) const;
		int						getKeyLeft( void ) const;
		int						getKeyRight( void ) const;

		void					up( float delta );
		void					down( float delta );
		void					left( float delta );
		void					right( float delta );
		virtual void			input( float delta );


	private:
		int						_keyUp;
		int						_keyDown;
		int						_keyLeft;
		int						_keyRight;
		bool					_isKeyUp;
		bool					_isKeyDown;
		bool					_isKeyLeft;
		bool					_isKeyRight;

};

#endif
