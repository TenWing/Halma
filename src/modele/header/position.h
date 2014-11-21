/**
 * \file      position.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit  la position d'un pion
 *
 * \details   Définit la structure d'une position
 */

#ifndef POSITION_H
#define POSITION_H

 typedef(struct Position, Position);

 struct Position {
 	int x;
 	int y;
 };

 #endif