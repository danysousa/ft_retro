/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DashBoardComponent.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:57:25 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 21:52:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASH_BOARD_COMPONENT
# define DASH_BOARD_COMPONENT
# include "../GameEngine/GameComponent.hpp"
# include "../GameObjects/Player.hpp"

class DashBoardComponent : public GameComponent
{
public:
	DashBoardComponent( void );
	DashBoardComponent( Player & player );
	DashBoardComponent( DashBoardComponent const & src );
	virtual ~DashBoardComponent( void );

	DashBoardComponent &		operator=( DashBoardComponent const & rhs );

	virtual void	render( RenderEngine & renderEngine );

private:
	Player *		_player;
	int				_frame;
	int				_sec;

};

#endif
