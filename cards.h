/**
 *
 *       \file       cards.h
 *
 *       \brief      Header file for cards.cpp which includes neccessary
 *                   classes for functionality of cards.
 *
 *       \version    0.1
 *       \date       Wedenesday, November 23 2015 13:48 PT\n
 *       Compiler    g++
 *
 *       \author     Jasvir Singh Grewal, jasvirsinghgrewal1991@gmail.com\n
 *                   Mayank Kasturia, mayankkasturia1993@gmail.com
 *
 *       License     GNU General Public License
 *
 *       \source     https://github.com/jasvir99/Journey_CSULB
 */

#ifndef CARDS
#define CARDS

#include <QMainWindow>
#include "mainwindow.h"

namespace card_list {
    class GamePlay;
}

class GamePlay
{

public:
     static int total_points[3];
     static QList<int> cards_in_hand;
     static int top_card_in_hand;
     static QList<int> complete_card_deck;
     bool already_have_card(int card_list_array[], int card_id, int array_size);
     explicit GamePlay();
     void randomize_deck();
     int gen_rand_number(int max);
     void main_play();
     static int learning_chips[3];
     static int craft_chips[3];
     static int quality_points[3];
     static int integrity_chips[3];
     void initialize_map_with_objects();

    //public content

private:
    //private content
};

class Cecs105 : public GamePlay
{
public:
    void main_play();

};

class Maths122 : public GamePlay
{
public:
    void main_play();

};

class LunchAtBrawtrustHall : public GamePlay
{
public:
    void main_play();
};

class ResearchOnCompilers : public GamePlay
{
public:
    void main_play();
};

class Cecs174 : public GamePlay
{
public:
    void main_play();
};

class Cecs100 : public GamePlay
{
public:
    void main_play();
};

class ExerciseInRecreation : public GamePlay
{
public:
    void main_play();
};

class FindLabUsingElevators : public GamePlay
{
public:
    void main_play();
};

class EnjoyPeace : public GamePlay
{
public:
    void main_play();
};

class ParkingViolation : public GamePlay
{
public:
    void main_play();
};

class JoiningEatOrSoccer : public GamePlay
{
public:
    void main_play();
};

class GetLateForClass : public GamePlay
{
public:
    void main_play();
};

class SayGoodByeToProfessor : public GamePlay
{
public:
    void main_play();
};

class PassMath123 : public GamePlay
{
public:
    void main_play();
};

class PlayBigGame : public GamePlay
{
public:
    void main_play();
};

class PassPhysics151 : public GamePlay
{
public:
    void main_play();
};

class PassKin253 : public GamePlay
{
public:
    void main_play();
};

class LearnNetbeans : public GamePlay
{
public:
    void main_play();
};

class ChooseMajor : public GamePlay
{
public:
    void main_play();
};

class ScoreGoal : public GamePlay
{
public:
    void main_play();
};

class MakeDeansList : public GamePlay
{
public:
    void main_play();
};

class PassSoccerClass : public GamePlay
{
public:
    void main_play();
};

class FallInPond : public GamePlay
{
public:
    void main_play();
};

class UseNewLaptop : public GamePlay
{
public:
    void main_play();
};

class MeetDean : public GamePlay
{
public:
    void main_play();
};

class CrashProgram : public GamePlay
{
public:
    void main_play();
};

class PressFloorButton : public GamePlay
{
public:
    void main_play();
};

class MakeAlarmBuzz : public GamePlay
{
public:
    void main_play();
};

class MeetProfessorEnglert : public GamePlay
{
public:
    void main_play();
};

class BeSoccerGoalie : public GamePlay
{
public:
    void main_play();
};

class TakeEffectiveClass : public GamePlay
{
public:
    void main_play();
};

class MeetProfessorHoffman : public GamePlay
{
public:
    void main_play();
};

class GoToOutpost : public GamePlay
{
public:
    void main_play();
};

class AttendOralCommunication : public GamePlay
{
public:
    void main_play();
};

class PassChemsitry111 : public GamePlay
{
public:
    void main_play();
};

class LearnLinux : public GamePlay
{
public:
    void main_play();
};

class MakeFriend : public GamePlay
{
public:
    void main_play();
};

class EnjoyNature : public GamePlay
{
public:
    void main_play();
};

class ParkInStudentParking : public GamePlay
{
public:
    void main_play();
};

#endif // CARDS
