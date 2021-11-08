//
// Created by ismael on 11/7/21.
//

#ifndef CHESS_CHESSMOVEMENTMEDIATOR_H
#define CHESS_CHESSMOVEMENTMEDIATOR_H

#include <vector>
#include "BoardSpace.h"

class ChessMovementMediator {
private:
    inline static std::vector<BoardSpace*> boardSpaceList;
    static void setBoardSpaceBackground(BoardSpace* boardSpace);
public:
    static void addBoardSpace(BoardSpace* boardSpace);
    static void movePieces();
};


#endif //CHESS_CHESSMOVEMENTMEDIATOR_H
