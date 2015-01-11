/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapLimitComponent.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:27:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 21:40:51 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPLIMITCOMPONENT_HPP
# define MAPLIMITCOMPONENT_HPP
# include <string>
# include "../GameEngine/GameComponent.hpp"

class MapLimitComponent : public GameComponent
{
public:
	MapLimitComponent( void );
	MapLimitComponent( std::string const & display );
	MapLimitComponent( MapLimitComponent const & src );
	virtual ~MapLimitComponent( void );

	MapLimitComponent &		operator=( MapLimitComponent const & rhs );

	void					input( float delta );
	virtual void			render( RenderEngine & renderEngine );

	std::string				getFirst( void ) const;
	std::string				getSecond( void ) const;
	int						getRank( void ) const;
	std::string				getDisplay( void ) const;
	void					setFirst( std::string value );
	void					setSecond( std::string value );

private:
	std::string				_first;
	std::string				_second;
	int						_rank;
	std::string				_display;
	int						_frame;

};

#endif
