/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:02:28 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveKeyComponent.hpp"
# include "../GameComponents/DashBoardComponent.hpp"
# include "../GameEngine/Input.hpp"
# include "../GameEngine/CoreEngine.hpp"
# include "Bullet.hpp"
# include <sstream>

Player::Player() : GameObject(),
	_monsterKilled( 0 ),
	_lives( 3 )
{
	this->initConstructor( "player" );
	return ;
}

Player::Player( std::string const & display ) : GameObject(),
	_monsterKilled( 0 ),
	_lives( 3 )
{
	this->initConstructor( display );
	return ;
}
void		Player::init( CoreEngine & coreEngine )
{
	this->getPos().setY( coreEngine.getRenderEngine().getHeight() / 2 );

	return ;
}

void		Player::initConstructor( std::string const & display )
{
	DisplayComponent *		dc = new DisplayComponent( display );
	MoveKeyComponent *		mkc = new MoveKeyComponent( KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 0.7f );
	DashBoardComponent *	dbc = new DashBoardComponent( *this );

	dc->setColor( COLOR_GREEN );

	this->addComponent( *dc );
	this->addComponent( *mkc );
	this->addComponent( *dbc );
}

Player::Player( Player const & src ) : GameObject( src )
{
	*this = src;
	return ;
}

Player::~Player()
{
	return ;
}

Player &	Player::operator=( Player const & rhs )
{
	GameObject::operator=( rhs );
	return ( *this );
}

void		Player::input( float delta )
{
	if ( Input::isKeyDown( ' ' ) )
	{
		GameObject *	bullet = new Bullet( *this, "-", * new Vector2f( 1, 0 ) );
		bullet->setPos( *this->_pos );
		this->getCoreEngine().getGame().addObject( *bullet );
	}
	GameObject::input( delta );
}

void		Player::gameOverScreen()
{
	std::stringstream ss[9];

	ss[0] << " _____                        _____                \n";
	ss[1] << "|  __ \\                      |  _  |               \n";
	ss[2] << "| |  \\/ __ _ _ __ ___   ___  | | | |_   _____ _ __ \n";
	ss[3] << "| | __ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n";
	ss[4] << "| |_\\ \\ (_| | | | | | |  __/ \\ \\_/ /\\ V /  __/ |   \n";
	ss[5] << " \\____/\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n";
	ss[6] << "                                                   \n";
	ss[7] << "                Press ESC to exit !                \n";
	ss[8] << "                   Score: " << this->_monsterKilled << "                \n";

	int x = getCoreEngine().getRenderEngine().getWidth() / 2 - 25;
	int y = getCoreEngine().getRenderEngine().getHeight() / 2 - 4;

	SET_COLOR( COLOR_RED );
	for ( int i = 0; i < 9; i++ )
		mvprintw( y + i, x, ss[i].str().c_str() );
	SET_COLOR( COLOR_WHITE );
}

void		Player::update( float delta )
{
	if ( this->_lives <= 0 )
		this->gameOverScreen();
	else
		GameObject::update( delta );
}

void		Player::collideWhith( GameObject const & colided )
{
	// this->getParent().removeChild( *this );
	if ( this->_lives )
		this->_lives--;
	(void)colided;
}

int			Player::getMonsterKilled() const
{
	return ( this->_monsterKilled );
}

void		Player::killAMonster()
{
	this->_monsterKilled++;
}

int			Player::getLives() const
{
	return ( this->_lives );
}

void		Player::setLives( int lives )
{
	this->_lives = lives;
}
