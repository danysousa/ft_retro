/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 21:32:55 by rbenjami         ###   ########.fr       */
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

	void			initConstructor( std::string const & display );
	virtual void	init( CoreEngine & coreEngine );
	virtual void	input( float delta );
	virtual void	update( float delta );
	virtual void	collideWhith( GameObject const & colided );
	int				getMonsterKilled() const;
	int				getLives() const;
	void			killAMonster();
	void			setLives( int lives );

private:
	void			gameOverScreen();
	int				_monsterKilled;
	int				_lives;
};

#endif
