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

namespace card_list {
    class GamePlay;
}

class GamePlay: public QMainWindow
{
    Q_OBJECT

public:
     static int total_points[3];
     static int cards_in_hand[5];
     static int top_card_in_hand;

    //public content

private:
    //private content
};

class Cecs105 : public GamePlay
{

};

class Maths122 : public GamePlay
{

};

class LunchAtBrawtrustHall : public GamePlay
{

};

class ResearchOnCompilers : public GamePlay
{

};

class Cecs174 : public GamePlay
{

};

class Cecs100 : public GamePlay
{

};

class ExerciseInRecreation : public GamePlay
{

};

class FindLabUsingElevators : public GamePlay
{

};

class EnjoyPeace : public GamePlay
{

};

class ParkingViolation : public GamePlay
{

};

class JoiningEatOrSoccer : public GamePlay
{

};

class GetLateForClass : public GamePlay
{

};

class SayGoodByeToProfessor : public GamePlay
{

};

class PassMath123 : public GamePlay
{

};

class PlayBigGame : public GamePlay
{

};

class PassPhysics151 : public GamePlay
{

};

class PassKin253 : public GamePlay
{

};

class LearnNetbeans : public GamePlay
{

};

class ChooseMajor : public GamePlay
{

};

class ScoreGoal : public GamePlay
{

};

class MakeDeansList : public GamePlay
{

};

class PassSoccerClass : public GamePlay
{

};

class FallInPond : public GamePlay
{

};

class UseNewLaptop : public GamePlay
{

};

class MeetDean : public GamePlay
{

};

class CrashProgram : public GamePlay
{

};

class PressFloorButton : public GamePlay
{

};

class MakeAlarmBuzz : public GamePlay
{

};

class MeetProfessorEnglert : public GamePlay
{

};

class BeSoccerGoalie : public GamePlay
{

};

class TakeEffectiveClass : public GamePlay
{

};

class MeetProfessorHoffman : public GamePlay
{

};

class GoToOutpost : public GamePlay
{

};

class AttendOralCommunication : public GamePlay
{

};

class PassChemsitry111 : public GamePlay
{

};

class LearnLinux : public GamePlay
{

};

class MakeFriend : public GamePlay
{

};

class EnjoyNature : public GamePlay
{

};

class ParkInStudentParking : public GamePlay
{

};

#endif // CARDS
