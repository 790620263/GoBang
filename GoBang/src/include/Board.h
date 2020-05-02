#ifndef _BOARD_H_
#define _BOARD_H_
class Board {
private:
	static const int DefaultSize =15;
	int size = DefaultSize;
	//int newX=0, newY=0;
	int board[DefaultSize][DefaultSize] = { 0 };//x,y,存储的值表示该处子属于哪位玩家
public:
	Board();
	//Board(int size);

	//void getNewPosition(int& x, int& y);
	int getSize();
	bool setPlayerCode(int x, int y, int playerCode);
	int getPlayerCode(int x, int y);
	int getCodeOffsetPosi(int x, int y, int position, int offset);
	bool isInBoard(int x, int y);
	//void print();
};
#endif // _BOARD_H_

