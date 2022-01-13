cmake_minimum_required(VERSION 3.20)
project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Chess main.cpp resources/res.qrc ChessBoard/headers/ChessPieces/ChessPiece.h ChessBoard/enums/Player.h ChessBoard/src/ChessPiece.cpp ChessBoard/enums/PieceType.h ChessBoard/src/ChessPieces/Rook.cpp ChessBoard/headers/ChessPieces/Rook.h ChessBoard/src/Game.cpp ChessBoard/headers/Game.h ChessBoard/src/ChessPieces/Knight.cpp ChessBoard/headers/ChessPieces/Knight.h ChessBoard/src/ChessPieces/Bishop.cpp ChessBoard/headers/ChessPieces/Bishop.h ChessBoard/src/ChessPieces/Queen.cpp ChessBoard/headers/ChessPieces/Queen.h ChessBoard/src/ChessPieces/King.cpp ChessBoard/headers/ChessPieces/King.h ChessBoard/src/ChessPieces/Pawn.cpp ChessBoard/headers/ChessPieces/Pawn.h ChessBoard/src/ChessPieces/EmptyPiece.cpp ChessBoard/headers/ChessPieces/EmptyPiece.h ChessBoard/views/MainChessView/ChessView.cpp ChessBoard/views/MainChessView/ChessView.h ChessBoard/views/MainChessView/ChessView.ui ChessBoard/headers/ChessPieces/Resources.h ChessBoard/src/BoardSpace.cpp ChessBoard/headers/BoardSpace.h ChessBoard/src/ChessMovementUtils.cpp ChessBoard/headers/ChessMovementUtils.h ChessBoard/headers/Coordinates.h ChessBoard/src/HintMarker.cpp ChessBoard/headers/HintMarker.h ChessBoard/views/PawnPromotionView/PawnPromotionView.cpp ChessBoard/views/PawnPromotionView/PawnPromotionView.h ChessBoard/views/PawnPromotionView/PawnPromotionView.ui ChessBoard/src/Coordinates.cpp)
target_link_libraries(Chess
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

