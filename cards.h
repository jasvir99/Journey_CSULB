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
     int randomize_deck();
     static QList<int> ai1_hand;
     static QList<int> ai2_hand;
     static int top_card_in_hand_ai1;
     static int top_card_in_hand_ai2;
     int gen_rand_number(int max);
     virtual void main_play(int player);
     static int learning_chips[3];
     static int craft_chips[3];
     static int quality_points[3];
     static int integrity_chips[3];

    //public content

private:
    //private content
};

class Cards
{
public:
    explicit Cards();
    void initialize_map_with_objects();
    typedef std::map<int, GamePlay*> card_class_map;
    static card_class_map play;

};

class Cecs105 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);

};

class Maths122 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);

};

class LunchAtBrawtrustHall : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class ResearchOnCompilers : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class Cecs174 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class Cecs100 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class ExerciseInRecreation : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class FindLabUsingElevators : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class EnjoyPeace : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class ParkingViolation : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class JoiningEatOrSoccer : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class GetLateForClass : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class SayGoodByeToProfessor : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PassMath123 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PlayBigGame : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PassPhysics151 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PassKin253 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class LearnNetbeans : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class ChooseMajor : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class ScoreGoal : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MakeDeansList : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();

};

class PassSoccerClass : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class FallInPond : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class UseNewLaptop : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MeetDean : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class CrashProgram : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PressFloorButton : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MakeAlarmBuzz : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MeetProfessorEnglert : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class BeSoccerGoalie : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class TakeElectiveClass : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MeetProfessorHoffman : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class GoToOutpost : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class AttendOralCommunication : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class PassChemsitry111 : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class LearnLinux : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class MakeFriend : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
    void punishment();
};

class EnjoyNature : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

class ParkInStudentParking : public GamePlay
{
public:
    void main_play(int player);
    bool pre_requisite_satified(int player);
};

#endif // CARDS
