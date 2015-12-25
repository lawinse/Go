#pragma once
#include"constants.h"
class GoBoard {
public:
	int * board;
	int * next_stone;
	static int board_size;
	static float komi;
	static int final_status[MAX_BOARD * MAX_BOARD];
	int ko_i;
	int ko_j;
	int step;
	int rival_move_i;
	int rival_move_j;
	int handicap;
	static int deltai[4];
	static int deltaj[4];
	static int diag_i[4];
	static int diag_j[4];
	static int around_i[8];
	static int around_j[8];
	void show_game();
	GoBoard();
	~GoBoard();

	GoBoard * copy_board();
	static int  I(int pos);
	static int  J(int pos);
	static int POS(int i, int  j);
	int get_string(int i, int j, int *stonei, int *stonej);
	void play_move( int i, int j, int color);
	static int pass_move(int i, int j);
	int on_board(int i, int j);
	int get_board( int i, int j);
	int board_empty();
	void clear_board();
	int suicide(int i, int j, int color);
	int provides_liberty(int ai, int aj, int i, int j, int color);	//some static functions tranfered to not static
	int has_additional_liberty(int i, int j, int libi, int libj);
	int remove_string(int i, int j);
	int same_string(int pos1, int pos2);
	int legal_move(int i, int j, int color);
	int generate_legal_moves(int* moves, int color);
	int checkLiberty(int i, int j);
	int autoRun(int color, bool* blackExist, bool* whiteExist);
	int autoRun_fill_the_board(int color, bool* blackExist, bool* whiteExist);
	bool available(int i, int j, int color);
	void calcGame(int *b, int *w, int *bScore, int *wScore);
	void compute_final_status(void);
	int get_final_status(int i, int j);
	void set_final_status(int i, int j, int status);
	int valid_fixed_handicap(int handicap);
	void place_fixed_handicap(int handicap);
	void set_final_status_string(int pos, int status);
	int findALiberty(int i, int j);
	int suicideLike(int i, int j, int color);
	int select_and_play(int color);
	int random_legal_move(int color);
	double chinese_count();
	bool is_surrounded(int point, int color);

	//int is_heuristic_available(int color, int rival_move);
	int is_star_available(int color, int last_moves);
	int is_xiaomu_available(int color, int rival_move);
	int is_anti_kakari_available(int color, int rival_move);
	int is_anti_yijianjia_available(int color, int rival_move);
	int is_anti_dian33_available(int color, int rival_move);
	int is_kakari_available(int color, int rival_move);

	bool heavy_policy(int point, int  side);
	bool is_virtual_eye(int point, int color);
	int check_one_Liberty(int i, int j);
	int find_one_Liberty_for_atari(int i, int j);
	int last_atari_heuristic( int color);
	void try_to_save_by_eat(int neighbor_i,int neighbor_j,int* saves, int &saves_number);
	int find_one_Liberty_for_atari2(int bi, int bj, bool*checked);
	int capture_heuristic(int color);
	int gains_liberty(int move, int color);
	int mogo_pattern_heuristic( int color);
	bool match_mogo_pattern(int bi, int bj, int color);
	bool match_hane(int bi, int bj, int color);
	bool match_cut1(int bi, int bj, int color);
	bool match_cut2(int bi, int bj, int color);
	bool match_board_side(int bi, int bj, int color);

	bool GoBoard::is_self_atari(int point, int color);
};