#include "Labyrinth.h"
#include <iostream>

void checkItem(MazeCell* path, bool items[]){
    if(path -> whatsHere == Item::SPELLBOOK)
        items[0] = true;
    if(path -> whatsHere == Item::POTION)
        items[1] = true;
    if(path -> whatsHere == Item::WAND)
        items[2] = true;
}

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    int count = 0;
    
    //0 is SPELLBOOK 
    //1 is POTION
    //2 is WAND
    bool items[3] = {false, false, false}; 

    while(count < moves.length()){
        if(items[0] && items[1] && items[2])
            return true;

        if(moves[count] == 'N'){
            if(start -> north != nullptr)
                start = start -> north;
            else
                return false;
        }

        else if(moves[count] == 'S'){
            if(start -> south != nullptr)
                start = start -> south;
            else
                return false;
            
        }

        else if(moves[count] == 'W'){
            if(start -> west != nullptr)
                start = start -> west;
            else
                return false;
            
        }

        else if(moves[count] == 'E'){
            if(start -> east != nullptr)
                start = start -> east;
            else
                return false;
        }
        checkItem(start, items); 
        count++;
    }

    if(items[0] && items[1] && items[2])
        return true;
    return false;
}
