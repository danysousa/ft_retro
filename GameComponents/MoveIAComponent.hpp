/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveIAComponent.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:32:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 16:12:21 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEIACOMPONENT_HPP
#define MOVEIACOMPONENT_HPP
# include "MoveComponent.hpp"

class MoveIAComponent : public MoveComponent
{
	public:
		MoveIAComponent( void );
		MoveIAComponent( int speed, std::string deplacement );
		MoveIAComponent( MoveIAComponent const & src );
		virtual ~MoveIAComponent( void );

		MoveIAComponent &		operator=( MoveIAComponent const & rhs );

		void					setDeplacement( std::string value );
		std::string				getDeplacement( void );

		virtual void			input( float delta );
		virtual void			random( float delta );

	private:
		std::string				_deplacement;

};

#endif
