//  $Id: PlayerDriver.cxx,v 1.19 2004/08/15 13:57:55 grumbel Exp $
//
//  TuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <assert.h>
#include "tuxkart.h"
#include "sound.h"
#include "KartProperties.h"
#include "KartDriver.h"
#include "World.h"
#include "PlayerDriver.h"

PlayerDriver::PlayerDriver()
{
    tscale = 10.0 ;
    rscale =  3.0 ; 
}

void
PlayerDriver::update ()
{
  assert(kart);
  //FIXME:KartDriver::update () ;
}

void
PlayerDriver::incomingJoystick  (JoyInfo& ji)
{
  assert(kart);
  kart->controlls = ji;

  /* Physics debugging control*/
  if ( keyState [ SDLK_1 ] ) {
    printf ("Selected Inertia - value: %f\n", kart->kart_properties.inertia);
    selected_property = &kart->kart_properties.inertia;
  }
  if ( keyState [ SDLK_2 ] ) {
    printf ("Selected corner stiffness front - value: %f\n", kart->kart_properties.corn_f);
    selected_property = &kart->kart_properties.corn_f;
  }
  
  if ( keyState [ SDLK_3 ] ) {
    printf ("Selected corner stiffness rear - value: %f\n", kart->kart_properties.corn_r);
    selected_property = &kart->kart_properties.corn_r;
  }
  
  if ( keyState [ SDLK_4 ] ) {
    printf ("Selected maximum grip - value: %f\n", kart->kart_properties.max_grip);
    selected_property = &kart->kart_properties.max_grip;
  }
  
  if ( keyState [ SDLK_5 ] ) {
    printf ("Selected mass of kart - value: %f\n", kart->kart_properties.mass);
    selected_property = &kart->kart_properties.mass;
  }
  
  if ( keyState [ SDLK_6 ] ) {
    printf ("Selected wheels turn degree - value: %f\n", kart->kart_properties.turn_speed);
    selected_property = &kart->kart_properties.turn_speed;
  }
  
  if ( keyState [ SDLK_PLUS ] ) {
    *selected_property += 0.1f;
    printf ("Increased selected value to: %f\n", *selected_property);
  }
  
  if ( keyState [ SDLK_MINUS ] ) {
    *selected_property -= 0.1f;
    printf ("Decreased selected value to: %f\n", *selected_property);
  }  
}

void
PlayerDriver::incomingKeystroke ( const SDL_keysym& key )
{
  assert(kart);

  /* CTRL-R ...infinite ammo cheat. */
  if ( key.sym == SDLK_r && key.mod & KMOD_CTRL)
    {
      switch ( rand () % 5 )
        {
        case 0 : kart->collectable = COLLECT_SPARK ;
          kart->num_collectables = 1000000 ;
          break ;
        case 1 : kart->collectable = COLLECT_MISSILE ;
          kart->num_collectables = 1000000 ;
          break ;
        case 2 : kart->collectable = COLLECT_HOMING_MISSILE ;
          kart->num_collectables = 1000000 ;
          break ;
        case 3 : kart->collectable = COLLECT_ZIPPER ;
          kart->num_collectables = 1000000 ;
          break ;
        case 4 : kart->collectable = COLLECT_MAGNET ;
          kart->num_collectables = 1000000 ;
          break ;
        }
    }
}

/* EOF */
