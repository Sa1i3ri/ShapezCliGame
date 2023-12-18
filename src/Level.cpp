//
// Created by 14832 on 2023/12/13.
//

#include "../header/Level.h"

Level::Level() {
    this->levelType = LevelType::nullLevel;
    this->map = nullptr;
    this->LevelNull();

    board.resize(Map::H);
    for(int i =0;i<Map::H;i++){
        board[i].resize(Map::W);
    }
}

Level::Level(Map *map) {
    this->levelType = LevelType::nullLevel;
    this->map = map;
    this->LevelNull();
    board.resize(Map::H);
    for(int i =0;i<Map::H;i++){
        board[i].resize(Map::W);
    }
}

Level::Level(LevelType levelType, Map *map) {
    this->levelType = levelType;
    this->map = map;
    this->LevelNull();
    board.resize(Map::H);
    for(int i =0;i<Map::H;i++){
        board[i].resize(Map::W);
    }
}


void Level::initMap() {
    for(int i=0;i<Map::H;i++){
        for(int j=0;j<Map::W;j++){
            //::free(map->board[i][j]);
            map->board[i][j] = translation(this->board[i][j]);
        }
    }
    this->map->initMap();
    Equipment::CutterInterval = initCutterInterval;
    Equipment::ExtractorInterval = initExtractorInterval;
    Equipment::TransmissionBeltInterval = initTransmissionBeltInterval;

}

Object *Level::translation(type ObjectType) {
    switch (ObjectType) {
        case nullObject : return new NullObject();
        case Amineral : return new AMineral();
        case extractor: return new Extractor(direction::up);
        case transmissionBelt: return  new TransmissionBelt(direction::up);
        case cutter: return new Cutter(direction::up,order::first);
        case rubbishBin: return new RubbishBin();
        case Bmineral: return new BMineral();
        case centre: return new Centre();
        case nullMineral: return new NullMineral();
        case halfAmineral: return new HalfAMineral();
    }
}

void Level::LevelNull() {
//    for(int i =0;i<Map::H;i++){
//        for(int j=0;j<Map::W;j++){
//            this->board[i][j] = type::nullObject;
//        }
//    }
    for (int i = 0; i < Map::H; i++) {
        vector<type> temp;
        for(int j =0;j<Map::W;j++){
            temp.push_back(type::nullObject);
        }
        this->board.push_back(temp);
    }

}
void Level::Level1() {
    for(int i =0;i<Map::H/5;i++){
        for(int j =0;j<Map::W/5;j++){
            this->board[i][j] = type::Amineral;
        }
    }

    for(int i =Map::H/5;i< 2 * Map::H/5;i++){
        for(int j =Map::W/5;j< 2 * Map::W/5 ;j++){
            this->board[i][j] = type::Bmineral;
        }
    }

    for(int i = Map::H/2-1;i<=Map::H/2+1;i++){
        for(int j = Map::W/2-1;j<=Map::W/2+1;j++){
            this->board[i][j]  = type::centre;
        }
    }


}
void Level::Level2() {
    for(int i =0;i<Map::H/5;i++){
        for(int j =0;j<Map::W/5;j++){
            this->board[i][j] = type::Bmineral;
        }
    }

    for(int i =Map::H/5;i< 2 * Map::H/5;i++){
        for(int j =Map::W/5;j< 2 * Map::W/5 ;j++){
            this->board[i][j] = type::Amineral;
        }
    }

    for(int i = Map::H/2-1;i<=Map::H/2+1;i++){
        for(int j = Map::W/2-1;j<=Map::W/2+1;j++){
            this->board[i][j]  = type::centre;
        }
    }
}
void Level::Level3() {
    for(int i =0;i<Map::H/5;i++){
        for(int j =0;j<Map::H/5;j++){
            this->board[i][j] = type::Amineral;
        }
    }



    for(int i = Map::H/2-1;i<=Map::H/2+1;i++){
        for(int j = Map::W/2-1;j<=Map::W/2+1;j++){
            this->board[i][j]  = type::centre;
        }
    }
}

void Level::LevelLoad() {
    if(this->levelType == LevelType::level1){
        this->Level1();
    }else if(this->levelType == LevelType::level2){
        this->Level2();
    }else if(this->levelType == LevelType::level3){
        this->Level3();
    }else if(this->levelType == LevelType::nullLevel){
        this->LevelNull();
    }

    this->initMap();

}

void Level::upgrade(char input) {
    if(map->upGradeTimes>0){
        if(input=='z'){
            //升级开采机速率
            if(Equipment::ExtractorInterval  > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                Equipment::ExtractorInterval -=1;
                for(int i =0;i<Map::H;i++){
                    for(int j =0;j<Map::W;j++){
                        if(map->board[i][j]->type == type::extractor){
                            auto curExt = (Extractor*) this->board[i][j];
                            curExt->interval = Equipment::ExtractorInterval;
                            curExt->curTime = 0;
                        }
                    }
                }
            }
        }else if(input == 'x'){
            //升级传送带速率
            if(Equipment::TransmissionBeltInterval > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                Equipment::TransmissionBeltInterval -=1;
                for(int i =0;i<Map::H;i++){
                    for(int j =0;j<Map::W;j++){
                        if(map->board[i][j]->type == type::transmissionBelt){
                            auto curTran = (TransmissionBelt*) this->board[i][j];
                            curTran->interval = Equipment::TransmissionBeltInterval;
                            curTran->curTime= 0;
                        }
                    }
                }
            }
        }else if(input == 'c'){
            //升级切割器速率
            if(Equipment::CutterInterval > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                Equipment::CutterInterval -=1;
                for(int i =0;i<Map::H;i++){
                    for(int j =0;j<Map::W;j++){
                        if(map->board[i][j]->type == type::cutter){
                            auto curCutter = (Cutter*) this->board[i][j];
                            curCutter->interval = Equipment::CutterInterval;
                            curCutter->curTime = 0;
                        }
                    }
                }
            }
        }
    }
}












