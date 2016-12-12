#ifndef GAME_2048_HPP
#define GAME_2048_HPP

#include "lib.hpp"
#include "Game.hpp"

class Game_2048 : public z::Game
{
public:
  virtual void start_grid();
  virtual void display_grid();
  virtual void command_press();
  virtual void logic_flow();
  virtual int if_win_or_lose();

  Game_2048(int n_line, int n_colomn, z::ElementPtr brush, int win_condition) : Game(n_line, n_colomn, move(brush)),
          win{win_condition}, max{0}, score{0}, game_win{false}, game_over{false} {}

  int win;
  int max;
  int score;

  bool game_win;
  bool game_over;

private:
  void find_max();
  bool is_blocked();
  void display_win_screen();
  bool display_yes_no_question(int i = 1);
  void display_help_screen();
};

#endif