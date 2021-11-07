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
public:
    void static addChessPiece(BoardSpace* boardSpace);
    void static movePieces();
};


#endif //CHESS_CHESSMOVEMENTMEDIATOR_H
