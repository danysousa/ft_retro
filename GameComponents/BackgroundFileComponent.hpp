/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundFileComponent.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 21:39:25 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 22:46:59 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUNDFILECOMPONENT_HPP
# define BACKGROUNDFILECOMPONENT_HPP
# include <string>
# include "../GameEngine/GameComponent.hpp"

class BackgroundFileComponent : public GameComponent
{
public:
	BackgroundFileComponent( void );
	BackgroundFileComponent( std::string const & display );
	BackgroundFileComponent( BackgroundFileComponent const & src );
	virtual ~BackgroundFileComponent( void );

	BackgroundFileComponent &		operator=( BackgroundFileComponent const & rhs );

	// void					input( float delta );
	virtual void			render( RenderEngine & renderEngine );


private:
	unsigned int			_frame;
	unsigned int			_rank;

};

#endif
