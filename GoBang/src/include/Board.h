#ifndef _BOARD_H_
#define _BOARD_H_
class Board {
private:
	static const int DefaultSize = 16;
	int size = DefaultSize;

	int board[DefaultSize][DefaultSize];//x,y,�洢��ֵ��ʾ�ô���������λ���
public:
	Board();
	//Board(int size);

	int getSize();
	bool setPlayerCode(int x, int y, int playerCode);
	int getPlayerCode(int x, int y);
	int getCodeOffsetPosi(int x, int y, int position, int offset);
	bool isInBoard(int x, int y);
	//void print();
};
#endif // _BOARD_H_

