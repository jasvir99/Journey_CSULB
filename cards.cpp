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
#include "chipbox.h"
#include <map>
#include <utility>
#include "discardcard.h"

//Initializing static data members

int GamePlay::total_points[3] = {};
//int GamePlay::cards_in_hand[5] = {};
int GamePlay::top_card_in_hand = 0;
int GamePlay::top_card_in_hand_ai1 = 0;
int GamePlay::top_card_in_hand_ai2 = 0;
int GamePlay::craft_chips[3] = {2,1,3};
int GamePlay::learning_chips[3] = {2,3,0};
int GamePlay::integrity_chips[3] = {2,2,3};
int GamePlay::quality_points[3] = {0,0,0};
int GamePlay::cards_to_be_removed[11] = {6,2,5,1,15,16,17,22,31,34,35};
int GamePlay::deck_for_second_level[12] = {40,41,42,43,44,45,46,47,48,49,50,51};

std::map<int, GamePlay*> Cards::play;

QList<int> empty_list()
{
    //special function to initialize empty qlist
    QList<int> list;
    return list;
}

QList<int> GamePlay::cards_in_hand = empty_list();
QList<int> GamePlay::ai1_hand = empty_list();
QList<int> GamePlay::ai2_hand = empty_list();
QList<int> GamePlay::discarded_card_deck = empty_list();

QList<int> init_complete_deck()
{
    QList<int> deck;
    for(int i = 0; i < 39; i++)
    {
        deck.insert(i,i+1);
    }

    return deck;
}

QList<int> GamePlay::complete_card_deck = init_complete_deck();

GamePlay::GamePlay()
{

    QTime time = QTime::currentTime();
    qsrand((uint)time.second());
}

Cards::Cards()
{
     play[0] = new Cecs105();
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

int GamePlay::randomize_deck()
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

    return 0;
}

void Cards::initialize_map_with_objects()
{
    play.insert(std::make_pair(1, new Maths122()));
    play.insert(std::make_pair(2, new LunchAtBrawtrustHall()));
    play.insert(std::make_pair(3, new ResearchOnCompilers()));
    play.insert(std::make_pair(4, new Cecs174()));
    play.insert(std::make_pair(5, new Cecs100()));
    play.insert(std::make_pair(6, new ExerciseInRecreation()));
    play.insert(std::make_pair(7, new FindLabUsingElevators));
    play.insert(std::make_pair(8, new EnjoyPeace));
    play.insert(std::make_pair(9, new ParkingViolation));
    play.insert(std::make_pair(10, new SayGoodByeToProfessor));
    play.insert(std::make_pair(11, new JoiningEatOrSoccer));
    play.insert(std::make_pair(12, new GetLateForClass));
    play.insert(std::make_pair(13, new PlayBigGame));
    play.insert(std::make_pair(14, new PassMath123()));
    play.insert(std::make_pair(15, new PassPhysics151()));
    play.insert(std::make_pair(16, new PassKin253()));
    play.insert(std::make_pair(17, new LearnNetbeans()));
    play.insert(std::make_pair(18, new ChooseMajor()));
    play.insert(std::make_pair(19, new ScoreGoal()));
    play.insert(std::make_pair(20, new MakeDeansList()));
    play.insert(std::make_pair(21, new PassSoccerClass()));
    play.insert(std::make_pair(22, new FallInPond()));
    play.insert(std::make_pair(23, new UseNewLaptop()));
    play.insert(std::make_pair(24, new MeetDean()));
    play.insert(std::make_pair(25, new CrashProgram()));
    play.insert(std::make_pair(26, new PressFloorButton()));
    play.insert(std::make_pair(27, new MakeAlarmBuzz()));
    play.insert(std::make_pair(28, new MeetProfessorEnglert()));
    play.insert(std::make_pair(29, new BeSoccerGoalie()));
    play.insert(std::make_pair(30, new TakeElectiveClass()));
    play.insert(std::make_pair(31, new MeetProfessorHoffman()));
    play.insert(std::make_pair(32, new GoToOutpost()));
    play.insert(std::make_pair(33, new AttendOralCommunication()));
    play.insert(std::make_pair(34, new PassChemsitry111()));
    play.insert(std::make_pair(35, new LearnLinux()));
    play.insert(std::make_pair(36, new MakeFriend()));
    play.insert(std::make_pair(37, new EnjoyNature()));
    play.insert(std::make_pair(38, new ParkInStudentParking));
    play.insert(std::make_pair(39, new LbsuVsUci()));
    play.insert(std::make_pair(40, new CarPool()));
    play.insert(std::make_pair(41, new Cecs274()));
    play.insert(std::make_pair(42, new Cecs201()));
    play.insert(std::make_pair(43, new Engl317()));
    play.insert(std::make_pair(44, new Phys152()));
    play.insert(std::make_pair(45, new Phil270()));
    play.insert(std::make_pair(46, new Cecs228()));
    play.insert(std::make_pair(47, new Cecs277()));
    play.insert(std::make_pair(48, new Cecs285()));
    play.insert(std::make_pair(49, new Cecs282()));
    play.insert(std::make_pair(50, new HaveSwim()));
}

QString GamePlay::main_play(int player)
{
    //defination of virtual function;
    return result_string;
}

QString Cecs105::main_play(int player)
{
    qDebug()<<"This is cecs105";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        result_string = " got 1 learning chip.";
        return result_string;
    }
    else
    {
        qDebug()<<"fail";
        result_string = " and got failed.";
        return result_string;
    }
}

bool Cecs105::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 14 || location == 17)
        return true;
    else
        return false;
}

QString Maths122::main_play(int player)
{
    qDebug()<<"This is maths122";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one chip of choice.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::craft_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::craft_enabled = true;

        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool Maths122::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 7)
        return true;
    else
        return false;
}

QString LunchAtBrawtrustHall::main_play(int player)
{
    qDebug()<<"This is lunch";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one craft chip.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool LunchAtBrawtrustHall::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 9)
        return true;
    else
        return false;
}

QString ResearchOnCompilers::main_play(int player)
{
    qDebug()<<"This is research";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one learning chip.";
        qDebug()<<"Success";
        learning_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool ResearchOnCompilers::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 7)
        return true;
    else
        return false;
}

QString Cecs174::main_play(int player)
{
    qDebug()<<"This is cecs174";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one learning chip.";
        qDebug()<<"Success";
        learning_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool Cecs174::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 14)
        return true;
    else
        return false;
}

QString Cecs100::main_play(int player)
{
    qDebug()<<"This is cecs100";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one craft chip.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool Cecs100::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 17)
        return true;
    else
        return false;
}

QString ExerciseInRecreation::main_play(int player)
{
    qDebug()<<"This is exercise";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one integrity chip.";
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool ExerciseInRecreation::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 5)
        return true;
    else
        return false;
}

QString FindLabUsingElevators::main_play(int player)
{
    qDebug()<<"This is findlab";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one integrity chip.";
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool FindLabUsingElevators::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 16)
        return true;
    else
        return false;
}

QString EnjoyPeace::main_play(int player)
{
    qDebug()<<"This is peace";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one of the learning and integrity chip.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::craft_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }

        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::craft_enabled = true;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool EnjoyPeace::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 1)
        return true;
    else
        return false;
}

QString ParkingViolation::main_play(int player)
{
    qDebug()<<"This is Parking";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one learning chip.";
        qDebug()<<"Success";
        learning_chips[player] += 1;
        if(player == MainWindow::main_player_id)
        {
            DiscardCard discard;
            if(DiscardCard::card_discarded)
            {
                learning_chips[player] += 1;
            }
        }

        else
        {
            remove_game_card_from_hand(player);
            learning_chips[player] += 1;
        }
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool ParkingViolation::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 6)
        return true;
    else
        return false;
}

QString JoiningEatOrSoccer::main_play(int player)
{
    qDebug()<<"This is eatorsoccer";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one of the craft or learning chip.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::integrity_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::integrity_enabled = true;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool JoiningEatOrSoccer::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 18)
        return true;
    else
        return false;
}

QString GetLateForClass::main_play(int player)
{
    qDebug()<<"This is late for class";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one craft chip and got relocated to lactation room.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                             MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool GetLateForClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 6)
        return true;
    else
        return false;
}

QString SayGoodByeToProfessor::main_play(int player)
{
    qDebug()<<"This is good to professor";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 10 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 10;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed a game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool SayGoodByeToProfessor::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if(location == 13 && learning >= 6 && craft >= 6 && integrity >= 6)
        return true;
    else
        return false;
}


QString PassMath123::main_play(int player)
{
    qDebug()<<"This is pass math 123";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool PassMath123::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 14 || location == 17) && learning >= 5)
        return true;
    else
        return false;
}


QString PlayBigGame::main_play(int player)
{
    qDebug()<<"This is play big game";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 craft chip and get teleported to lactation room.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;
        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool PlayBigGame::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 3)
        return true;
    else
        return false;
}

QString PassPhysics151::main_play(int player)
{
    qDebug()<<"This is pass physics";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return result_string;
    }
}

bool PassPhysics151::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 17 && craft >= 3)
        return true;
    else
        return false;
}

QString PassKin253::main_play(int player)
{
    qDebug()<<"This is passkin";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 2 craft chips.";
        qDebug()<<"Success";
        craft_chips[player] += 2;
        return result_string;
    }
    else
    {
        result_string = " but got failed and teleported to room of retirement.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(13, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 13;
        return result_string;
    }
}


bool PassKin253::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 &&  craft >= 2)
        return true;
    else
        return false;
}

QString LearnNetbeans::main_play(int player)
{
    qDebug()<<"This is net beans";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return result_string;
    }
}

bool LearnNetbeans::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 20)
        return true;
    else
        return false;
}


QString ChooseMajor::main_play(int player)
{
    qDebug()<<"This is choose major";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return result_string;
    }
}

bool ChooseMajor::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location == 19 && integrity >= 3)
        return true;
    else
        return false;
}

QString ScoreGoal::main_play(int player)
{
    qDebug()<<"This is score goal";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and 1 integrity chip.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        integrity_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " but got failed and teleported to student parking.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 2;
        return result_string;
    }
}

bool ScoreGoal::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 && craft >= 3)
        return true;
    else
        return false;
}

QString MakeDeansList::main_play(int player)
{
    qDebug()<<"This is make dean list";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and teleported to student parking.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 2;
        return result_string;
    }
}

bool MakeDeansList::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 12 || location == 15) && learning >= 6)
        return true;
    else
        return false;
}

QString PassSoccerClass::main_play(int player)
{
    qDebug()<<"This is pass soccer class";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return result_string;
    }
}

bool PassSoccerClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 && craft >= 5)
        return true;
    else
        return false;
}

QString FallInPond::main_play(int player)
{
    qDebug()<<"This is fallinpond";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one of each integrity and craft chip.";
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        craft_chips[player] += 1;
        return result_string;
    }
    else
    {
        result_string = " but got failed and teleported to lactation room.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;
        return result_string;
    }
}

bool FallInPond::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 1 && learning >= 3)
        return true;
    else
        return false;
}

QString UseNewLaptop::main_play(int player)
{
    qDebug()<<"This is new laptop";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one chip of choice.";
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool UseNewLaptop::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location == 11 && integrity >=4 )
        return true;
    else
        return false;
}

QString MeetDean::main_play(int player)
{
    qDebug()<<"This is meet dean";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and one game card.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool MeetDean::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if((location == 12 || location == 15) && learning >= 3 && craft >= 3 &&
            integrity >= 3)
        return true;
    else
        return false;
}

QString CrashProgram::main_play(int player)
{
    qDebug()<<"This is crash program";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and one game card.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool CrashProgram::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 20 && learning >= 2)
        return true;
    else
        return false;
}

QString PressFloorButton::main_play(int player)
{
    qDebug()<<"This is press floor button";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 2 craft chips.";
        qDebug()<<"Success";
        craft_chips[player] += 2;
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 2 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return result_string;
    }
}

bool PressFloorButton::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 16 && learning >= 4)
        return true;
    else
        return false;
}

QString MakeAlarmBuzz::main_play(int player)
{
    qDebug()<<"This is make alarm buzz";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one chip choice.";
        qDebug()<<"Success";
        craft_chips[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 2 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return result_string;
    }
}

bool MakeAlarmBuzz::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 18 && craft >= 3)
        return true;
    else
        return false;
}

QString MeetProfessorEnglert::main_play(int player)
{
    qDebug()<<"This is englert";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one chip of choice.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool MeetProfessorEnglert::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 19) && integrity >= 3)
        return true;
    else
        return false;
}

QString BeSoccerGoalie::main_play(int player)
{
    qDebug()<<"This is goalie";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and one game card.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return result_string;
    }
    else
    {
        result_string = " but got failed and teleported to student parking.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 2;
        return result_string;
    }
}

bool BeSoccerGoalie::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    if(location == 0 && learning >= 3 && craft >= 3)
        return true;
    else
        return false;
}

QString TakeElectiveClass::main_play(int player)
{
    qDebug()<<"This is effective class";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 learning chip and a game card.";
        qDebug()<<"Success";
        learning_chips[player] += 1;
        add_game_card_in_hand(player);
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 2 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return result_string;
    }
}

bool TakeElectiveClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 7 && learning >= 2)
        return true;
    else
        return false;
}


QString MeetProfessorHoffman::main_play(int player)
{
    qDebug()<<"This is hoffman";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and two game cards.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        add_game_card_in_hand(player);
        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 5 quality points and "
                        "teleported to lactation room.";
        qDebug()<<"fail";
        quality_points[player] -= 5;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;
        return result_string;
    }
}

bool MeetProfessorHoffman::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 11 || location == 14 || location == 18 || location == 19 ||
        location == 12 || location == 15 || location == 13 || location == 16 ||
        location  == 17) && learning >= 3)
        return true;
    else
        return false;
}

QString GoToOutpost::main_play(int player)
{
    qDebug()<<"This is outpost";
    if(pre_requisite_satified(player))
    {
        result_string = " and got one chip of choice.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return result_string;
    }

    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool GoToOutpost::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && location != 6)
        return true;
    else
        return false;
}

QString AttendOralCommunication::main_play(int player)
{
    qDebug()<<"This is oral communication";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 4 quality points and a chip of choice.";
        qDebug()<<"Success";
        quality_points[player] += 4;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool AttendOralCommunication::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && integrity >= 4)
        return true;
    else
        return false;
}

QString PassChemsitry111::main_play(int player)
{
    qDebug()<<"This is pass chemistry";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;

        return result_string;
    }
    else
    {
        result_string = " and got teleported to student parking.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 2;

        return result_string;
    }
}

bool PassChemsitry111::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && craft >= 6)
        return true;
    else
        return false;
}

QString LearnLinux::main_play(int player)
{
    qDebug()<<"This is learn linux";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 3 quality points and a chip of choice.";
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 1 quality point.";
        qDebug()<<"fail";
        quality_points[player] -= 1;

        return result_string;
    }
}

bool LearnLinux::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if(location == 11 && integrity >= 3 && craft >= 2 )
        return true;
    else
        return false;
}


QString MakeFriend::main_play(int player)
{
    qDebug()<<"This is make friend";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 3 quality points and a chip of choice.";
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return result_string;
    }
    else
    {
        result_string = " but got failed and loosed 1 game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);

        return result_string;
    }
}

bool MakeFriend::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 12 || location == 15) && integrity >= 2)
        return true;
    else
        return false;
}

QString EnjoyNature::main_play(int player)
{
    qDebug()<<"This is enjoy nature";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 craft chip and teleported to lactation room.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;

        return result_string;
    }
    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool EnjoyNature::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20)
        return true;
    else
        return false;
}

QString ParkInStudentParking::main_play(int player)
{
    qDebug()<<"This is parking in student parking";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 craft chip and teleported to lactation room.";
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 20;

        return result_string;
    }

    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool ParkInStudentParking::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 2)
        return true;
    else
        return false;
}

QString LbsuVsUci::main_play(int player)
{
    qDebug()<<"This is parking lbsu vs uci";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 chip of choice.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }

    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool LbsuVsUci::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 3)
        return true;
    else
        return false;
}

QString CarPool::main_play(int player)
{
    qDebug()<<"This is carpool";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 3 quality points and a game card.";
        qDebug()<<"Success";
        quality_points[player] += 3;
        add_game_card_in_hand(player);
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 2 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return result_string;
    }
}

bool CarPool::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integity = integrity_chips[player];
    if((location == 2 || location == 6) && integity >= 5)
        return true;
    else
        return false;
}


QString Cecs274::main_play(int player)
{
    qDebug()<<"This is cecs274";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and a game card.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return result_string;
    }
}

bool Cecs274::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 11 || location == 14 || location == 17) && learning >= 7)
        return true;
    else
        return false;
}

QString Cecs201::main_play(int player)
{
    qDebug()<<"This is cecs201";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 1 of each integrity, learning and craft chips.";
        qDebug()<<"Success";
        learning_chips[player] += 1;
        craft_chips[player] += 1;
        integrity_chips[player] += 1;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 3 quality points and a game card.";
        qDebug()<<"fail";
        quality_points[player] -= 3;
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool Cecs201::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if((location == 11 || location == 14 || location == 17) && craft >= 8)
        return true;
    else
        return false;
}

QString Engl317::main_play(int player)
{
    qDebug()<<"This is engl317";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }

    else
    {
        result_string = " but got failed and teleported to student parking.";
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                             MainWindow::y_offsets[player]);
        MainWindow::current_postions[player] = 2;
        return result_string;
    }
}

bool Engl317::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 8 && craft >= 6)
        return true;
    else
        return false;
}

QString Phys152::main_play(int player)
{
    qDebug()<<"This is phys152";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed one game card.";
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool Phys152::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 8 || location == 7) && integrity >= 7)
        return true;
    else
        return false;
}


QString Phil270::main_play(int player)
{
    qDebug()<<"This is phil270";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 3 quality points and 1 learning chip.";
        qDebug()<<"Success";
        quality_points[player] += 3;
        learning_chips[player] += 1;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] += 3;
        return result_string;
    }
}

bool Phil270::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 8 || location == 7) && integrity >= 7)
        return true;
    else
        return false;
}

QString Cecs228::main_play(int player)
{
    qDebug()<<"This is cecs228";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 2 quality points and a game card.";
        qDebug()<<"fail";
        quality_points[player] += 2;
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool Cecs228::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    if((location == 14 || location == 17 || location == 11) && integrity >= 8
            && craft >= 8 && learning >= 8)
        return true;
    else
        return false;
}

QString Cecs277::main_play(int player)
{
    qDebug()<<"This is cecs277";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 2 quality points and a game card.";
        qDebug()<<"fail";
        quality_points[player] += 2;
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool Cecs277::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    if((location == 11 || location == 14 || location == 18 || location == 19 ||
        location == 12 || location == 15 || location == 13 || location == 16 ||
        location  == 17 || location == 20)  && integrity >= 8
            && craft >= 8 && learning >= 8)
        return true;
    else
        return false;
}

QString Cecs285::main_play(int player)
{
    qDebug()<<"This is cecs285";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points and a chip of choice.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 3 quality points.";
        qDebug()<<"fail";
        quality_points[player] += 3;
        return result_string;
    }
}

bool Cecs285::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 18 || location == 1)  && learning >= 6)
        return true;
    else
        return false;
}

QString Cecs282::main_play(int player)
{
    qDebug()<<"This is cecs282";
    if(pre_requisite_satified(player))
    {
        result_string = " and got 5 quality points.";
        qDebug()<<"Success";
        quality_points[player] += 5;
        return result_string;
    }

    else
    {
        result_string = " but got failed and loosed 2 quality points and a game card.";
        qDebug()<<"fail";
        quality_points[player] += 2;
        remove_game_card_from_hand(player);
        return result_string;
    }
}

bool Cecs282::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    if((location == 11 || location == 14 || location == 18 || location == 19 ||
        location == 12 || location == 15 || location == 13 || location == 16 ||
        location  == 17 || location == 20)  && integrity >= 8
            && craft >= 8 && learning >= 8)
        return true;
    else
        return false;
}


QString HaveSwim::main_play(int player)
{
    qDebug()<<"This is have swim";
    if(pre_requisite_satified(player))
    {
        result_string = " and got a chip of choice.";
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return result_string;
    }

    else
    {
        result_string = " and got failed.";
        qDebug()<<"fail";
        return result_string;
    }
}

bool HaveSwim::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 5)
        return true;
    else
        return false;
}

void GamePlay::add_game_card_in_hand(int player)
{
    if(player == MainWindow::main_player_id)
    {
        randomize_deck();
        int top_of_deck = complete_card_deck.value(0);
        if(top_of_deck >= 0 && top_of_deck <= 51)
        {
             complete_card_deck.removeFirst();
             cards_in_hand.insert(0,top_of_deck);
             top_card_in_hand = 0;
             MainWindow window(false);
             window.set_icon_as_card();
        }
    }

    else if(player == MainWindow::ai_player1_id)
    {
        randomize_deck();
        int top_of_deck = complete_card_deck.value(0);
        if(top_of_deck != 0)
        {
             complete_card_deck.removeFirst();
             ai1_hand.insert(0,top_of_deck);
        }
    }

    else
    {
        randomize_deck();
        int top_of_deck = GamePlay::complete_card_deck.value(0);
        if(top_of_deck != 0)
        {
             complete_card_deck.removeFirst();
             ai2_hand.insert(0,top_of_deck);
        }
    }
}

void GamePlay::remove_game_card_from_hand(int player)
{
    if(player == MainWindow::main_player_id)
    {
        int hand = cards_in_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            if(card_to_be_removed == top_card_in_hand)
            {
                discarded_card_deck.append(card_to_be_removed - 1);
                cards_in_hand.removeAt(card_to_be_removed - 1);
            }
            else
            {
                discarded_card_deck.append(card_to_be_removed);
                cards_in_hand.removeAt(card_to_be_removed);
            }
        }
        else
        {
            card_to_be_removed = 3;
            if(card_to_be_removed == top_card_in_hand)
            {
                discarded_card_deck.append(card_to_be_removed - 1);
                cards_in_hand.removeAt(card_to_be_removed - 1);

            }
            else
            {
                discarded_card_deck.append(card_to_be_removed);
                cards_in_hand.removeAt(card_to_be_removed);
            }
        }
    }

    if(player == MainWindow::ai_player1_id)
    {
        int hand = ai1_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            discarded_card_deck.append(card_to_be_removed);
            ai1_hand.removeAt(card_to_be_removed);
        }
        else
        {
            discarded_card_deck.append(1);
            ai1_hand.removeAt(1);
        }
    }

    if(player == MainWindow::ai_player2_id)
    {
        int hand = ai2_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            discarded_card_deck.append(card_to_be_removed);
            ai2_hand.removeAt(card_to_be_removed);
        }
        else
        {
            discarded_card_deck.append(1);
            ai2_hand.removeAt(1);
        }
    }
}

void GamePlay::increase_level()
{
    qDebug()<<"level increased";
    complete_card_deck.clear();
    complete_card_deck = init_complete_deck();
    for(int i = 0; i < 11; i++ )
    {
        for(int j = 0; j < complete_card_deck.size(); j++)
        {
            if(complete_card_deck.value(j) == cards_to_be_removed[i])
            {
                complete_card_deck.removeAt(j);
                break;
            }
        }
    }

    for(int i = 0; i < 12; i++)
    {
        complete_card_deck.append(deck_for_second_level[i]);
    }

    cards_in_hand.clear();
    ai1_hand.clear();
    ai2_hand.clear();
    MainWindow window(false);
    window.set_cards_in_hand();
    window.set_icon_as_card();
}
