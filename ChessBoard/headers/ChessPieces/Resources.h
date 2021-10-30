//
// Created by ismael on 10/23/21.
//

#ifndef CHESS_RESOURCES_H
#define CHESS_RESOURCES_H

#include <map>
#include "../../enums/Player.h"
#include "../../enums/PieceType.h"

class Resources {
public:
    static std::string getImagePath(PlayerID playerID, PieceType pieceType) {
        std::map<PieceType, std::string> imageResourceMap = {{PieceType::ROOK, "rook"},
                                                             {PieceType::KNIGHT, "knight"},
                                                             {PieceType::BISHOP, "bishop"},
                                                             {PieceType::QUEEN, "queen"},
                                                             {PieceType::KING, "king"},
                                                             {PieceType::PAWN, "pawn"},
                                                             {PieceType::NULL_PIECE, ""}};
        if(imageResourceMap.count(pieceType) < 1) {
            return "";
        }

        const std::string assetPath = ":/images/";
        const std::string playerDir = playerID == PlayerID::PLAYER_DARK ? "DarkChessPieces/" : "LightChessPieces/";
        const std::string pieceStr = imageResourceMap[pieceType];
        const std::string extension = ".png";
        std::string fullImagePath = assetPath + playerDir + pieceStr + extension;

        return fullImagePath;
    }

    static const int SQUARE_SIZE = 70;
};


#endif //CHESS_RESOURCES_H
