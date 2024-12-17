add_library(lib
        board.cpp
        game.cpp
        player.cpp
        players/randomPlayer.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
