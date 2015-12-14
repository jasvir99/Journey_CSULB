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
     static QList<int> discarded_card_deck;
     bool already_have_card(int card_list_array[], int card_id, int array_size);
     explicit GamePlay();
     int randomize_deck();
     static QList<int> ai1_hand;
     static QList<int> ai2_hand;
     static int top_card_in_hand_ai1;
     static int top_card_in_hand_ai2;
     int gen_rand_number(int max);
     virtual bool main_play(int player);
     static int learning_chips[3];
     static int craft_chips[3];
     static int quality_points[3];
     static int integrity_chips[3];
     void add_game_card_in_hand(int player);
     void remove_game_card_from_hand(int player);

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
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class Maths122 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class LunchAtBrawtrustHall : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class ResearchOnCompilers : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class Cecs174 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class Cecs100 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class ExerciseInRecreation : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class FindLabUsingElevators : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class EnjoyPeace : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class ParkingViolation : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class JoiningEatOrSoccer : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class GetLateForClass : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class SayGoodByeToProfessor : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class PassMath123 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class PlayBigGame : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class PassPhysics151 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class PassKin253 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class LearnNetbeans : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class ChooseMajor : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class ScoreGoal : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MakeDeansList : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);


};

class PassSoccerClass : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class FallInPond : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class UseNewLaptop : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MeetDean : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class CrashProgram : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class PressFloorButton : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MakeAlarmBuzz : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MeetProfessorEnglert : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class BeSoccerGoalie : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class TakeElectiveClass : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MeetProfessorHoffman : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class GoToOutpost : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class AttendOralCommunication : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class PassChemsitry111 : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class LearnLinux : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class MakeFriend : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);

};

class EnjoyNature : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};

class ParkInStudentParking : public GamePlay
{
public:
    bool main_play(int player);
    bool pre_requisite_satified(int player);
};



#endif // CARDS
