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
#include "QDebug"
#include <map>
#include <utility>

//Initializing static data members

int GamePlay::total_points[3] = {};
//int GamePlay::cards_in_hand[5] = {};
int GamePlay::top_card_in_hand = 0;
int GamePlay::craft_chips[3] = {};
int GamePlay::learning_chips[3] = {};
int GamePlay::integrity_chips[3] = {};
int GamePlay::quality_points[3] = {};

std::map<int, GamePlay*> GamePlay::play;

QList<int> empty_list()
{
    //special function to initialize empty qlist
    QList<int> list;
    return list;
}

QList<int> GamePlay::cards_in_hand = empty_list();
QList<int> GamePlay::complete_card_deck = empty_list();

GamePlay::GamePlay()
{
    play[0] = new Cecs100();
    for(int i = 0; i < 51; i++)
    {
        complete_card_deck.insert(i,i+1);
    }
}

bool GamePlay::already_have_card(int card_list_array[], int card_id,
                                 int array_size)
{
    bool card_in_list = false;
    for (int j=1;j <= array_size;j++)
    {
        if(card_list_array[j] == card_id)
        {
           card_in_list = true;
           break;
        }
    }

    return card_in_list;
}

int GamePlay::gen_rand_number(int max)
{
    /*
     * function to generate random number b/w 0 and max
     */

    int b = qrand() % max;
    return b;
}

void GamePlay::randomize_deck()
{
    int deck_size = complete_card_deck.size();
    if(deck_size == 0)
    {
        deck_size = 51;
    }
    for(int i = 0; i < complete_card_deck.size(); i++)
    {
        int pos =  gen_rand_number(deck_size);
        int temp = complete_card_deck[i];
        complete_card_deck[i] = complete_card_deck[pos];
        complete_card_deck[pos] = temp;
    }
}

void GamePlay::initialize_map_with_objects()
{
   // play.insert(std::make_pair(1, new Maths122()));
}

void GamePlay::main_play()
{
    qDebug()<<"This is base main_play";
}

void Cecs105::main_play()
{
    qDebug()<<"This is cecs105";
}

void Maths122::main_play()
{
    qDebug()<<"This is maths122";
}

void LunchAtBrawtrustHall::main_play()
{
    qDebug()<<"This is lunch";
}

void ResearchOnCompilers::main_play()
{
    qDebug()<<"This is research";
}

void Cecs174::main_play()
{
    qDebug()<<"This is cecs174";
}

void Cecs100::main_play()
{
    qDebug()<<"This is cecs100";
}

void ExerciseInRecreation::main_play()
{
    qDebug()<<"This is exercise";
}

void FindLabUsingElevators::main_play()
{
    qDebug()<<"This is findlab";
}

void EnjoyPeace::main_play()
{
    qDebug()<<"This is peace";
}

void ParkingViolation::main_play()
{
    qDebug()<<"This is Parking";
}

void JoiningEatOrSoccer::main_play()
{
    qDebug()<<"This is eatorsoccer";
}

void GetLateForClass::main_play()
{
    qDebug()<<"This is late for class";
}

void SayGoodByeToProfessor::main_play()
{
    qDebug()<<"This is good to professor";
}

void PassMath123::main_play()
{
    qDebug()<<"This is pass math 123";
}

void PlayBigGame::main_play()
{
    qDebug()<<"This is play big game";
}

void PassPhysics151::main_play()
{
    qDebug()<<"This is pass physics";
}

void PassKin253::main_play()
{
    qDebug()<<"This is passkin";
}

void LearnNetbeans::main_play()
{
    qDebug()<<"This is net beans";
}

void ChooseMajor::main_play()
{
    qDebug()<<"This is choose major";
}

void ScoreGoal::main_play()
{
    qDebug()<<"This is score goal";
}

void MakeDeansList::main_play()
{
    qDebug()<<"This is make dean list";
}

void PassSoccerClass::main_play()
{
    qDebug()<<"This is pass soccer class";
}

void FallInPond::main_play()
{
    qDebug()<<"This is fallinpond";
}

void UseNewLaptop::main_play()
{
    qDebug()<<"This is new laptop";
}

void MeetDean::main_play()
{
    qDebug()<<"This is meet dean";
}

void CrashProgram::main_play()
{
    qDebug()<<"This is crash program";
}

void PressFloorButton::main_play()
{
    qDebug()<<"This is press floor button";
}

void MakeAlarmBuzz::main_play()
{
    qDebug()<<"This is make alarm buzz";
}

void MeetProfessorEnglert::main_play()
{
    qDebug()<<"This is englert";
}

void BeSoccerGoalie::main_play()
{
    qDebug()<<"This is goalie";
}

void TakeEffectiveClass::main_play()
{
    qDebug()<<"This is effective class";
}

void MeetProfessorHoffman::main_play()
{
    qDebug()<<"This is hoffman";
}

void GoToOutpost::main_play()
{
    qDebug()<<"This is outpost";
}

void AttendOralCommunication::main_play()
{
    qDebug()<<"This is oral communication";
}

void PassChemsitry111::main_play()
{
    qDebug()<<"This is pass chemistry";
}

void LearnLinux::main_play()
{
    qDebug()<<"This is learn linux";
}

void MakeFriend::main_play()
{
    qDebug()<<"This is make friend";
}

void EnjoyNature::main_play()
{
    qDebug()<<"This is enjoy nature";
}

void ParkInStudentParking::main_play()
{
    qDebug()<<"This is parking in student parking";
}
