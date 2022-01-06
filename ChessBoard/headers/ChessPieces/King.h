//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "ChessPiece.h"
#include "Rook.h"

class King : public virtual ChessPiece {
private:
    bool hasMoved;
public:
    King(PlayerID playerId, QGraphicsItem *parent = nullptr)
            : ChessPiece(playerId, PieceType::KING) {
    }

    bool canMove(Coordinates coordinates);
    bool HasMoved() const;
    void afterPieceMoved(Coordinates coordinates) override;
    std::vector<Rook*> rooksEligibleForCastling();
    void addRookEligibleForCastling(std::vector<Rook*> & rookPtrList, int xIndex, int yIndex);
    void addRookEligibleForCastlingHelper(Rook* rookPtr, std::vector<Rook*> & rookPtrList, int xIndex, int yIndex);
};


#endif //CHESS_KING_H
