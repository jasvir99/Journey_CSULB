/**
 *
 *       \file       cards.cpp
 *
 *       \brief      includes
 *
 *       \version    0.1
 *       \date       Wedenesday, October 14 2015 11:58 PT\n
 *       Compiler    g++
 *
 *       \author     Jasvir Singh Grewal, jasvirsinghgrewal1991@gmail.com\n
 *                   Mayank Kasturia, mayankkasturia1993@gmail.com
 *
 *       License     GNU General Public License
 *
 *       \source     https://github.com/jasvir99/Journey_CSULB
 */

#include "cards.h"

//Initializing static data members

int GamePlay::total_points[3] = {0,0,0};
int GamePlay::cards_in_hand[5] = {0,0,0,0,0};
int GamePlay::top_card_in_hand = 1;
