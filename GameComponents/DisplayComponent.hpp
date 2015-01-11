/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayComponent.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:42:16 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 12:41:18 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_COMPONENT
# define DISPLAY_COMPONENT
# include <string>
# include "../GameEngine/GameComponent.hpp"

class DisplayComponent : public GameComponent
{
public:
	DisplayComponent( void );
	DisplayComponent( std::string const & display );
	DisplayComponent( DisplayComponent const & src );
	virtual ~DisplayComponent( void );

	DisplayComponent &		operator=( DisplayComponent const & rhs );

	virtual void			input( float delta );
	virtual void			update( float delta );
	virtual void			render( RenderEngine & renderEngine );

	std::string				getDisplay() const;

private:
	std::string				_display;

};

#endif
