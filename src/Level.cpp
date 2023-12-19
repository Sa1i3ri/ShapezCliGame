//
// Created by 14832 on 2023/12/13.
//

#include "../header/Level.h"



Level::Level() {
    this->levelType = LevelType::nullLevel;
    this->map = nullptr;
    this->sizeMap();
}



Level::Level(LevelType levelType, Map *map) {
    this->levelType = levelType;
    this->map = map;
    this->sizeMap();
}

void Level::sizeMap() {
    this->board = *new vector<vector<type>>;
    for (int i = 0; i < Map::H; i++) {
        vector<type> temp;
        for(int j =0;j<Map::W;j++){
            temp.push_back(type::nullObject);
        }
        this->board.push_back(temp);
    }
}


void Level::initMap() {
    fromLevelToMap();
    this->map->initMap();
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
void Level::fromLevelToMap() {
    for(int i=0;i<Map::H;i++){
        for(int j=0;j<Map::W;j++){
            //::free(map->board[i][j]);
            map->board[i][j] = translation(this->board[i][j]);
        }
    }
}

void Level::deployMineral(int i,int j,type type) {
    if(i >= Map::H || j>=Map::W || i<0 || j<0){
        return;
    }
    this->board[i][j] = type;
}
void Level::wideScaleDeploy(int start_i, int end_i, int start_j, int end_j, int offset, type type) {
    if(start_i > end_i || start_j > end_j){
        return;
    }
    for(int i = start_i - offset;i<end_i + offset;i++){
        for(int j =start_j - offset;j<end_j + offset;j++){
            deployMineral(i,j,type);
        }
    }
}

void Level::LevelNull() {
    for (int i = 0; i < Map::H; i++) {
        vector<type> temp;
        for(int j =0;j<Map::W;j++){
            temp.push_back(type::nullObject);
        }
        this->board.push_back(temp);
    }

}
void Level::Level1() {
    wideScaleDeploy(0,Map::H/5,0,Map::W/5,Map::AMineralSize,type::Amineral);

    wideScaleDeploy(4*Map::H/5,5 * Map::H/5,4 * Map::W/5,5 * Map::W/5,Map::BMineralSize,type::Bmineral);

    wideScaleDeploy(Map::H/2,Map::H/2,Map::H/2,Map::H/2,Map::CentreSize,type::centre);
}
void Level::Level2(){
    wideScaleDeploy(0,Map::H/5,0,Map::W/5,Map::BMineralSize,type::Bmineral);

    wideScaleDeploy(4*Map::H/5,5 * Map::H/5,4 * Map::W/5,5 * Map::W/5,Map::AMineralSize,type::Amineral);

    wideScaleDeploy(Map::H/2,Map::H/2,Map::H/2,Map::H/2,Map::CentreSize,type::centre);
}
void Level::Level3() {

    wideScaleDeploy(0,Map::H/5,0,Map::W/5,Map::AMineralSize,type::Amineral);

    wideScaleDeploy(Map::H/2,Map::H/2,Map::H/2,Map::H/2,Map::CentreSize,type::centre);

}

void Level::levelInit() {
    sizeMap();

    if(this->levelType == LevelType::level1){
        this->Level1();
    }else if(this->levelType == LevelType::level2){
        this->Level2();
    }else if(this->levelType == LevelType::level3){
        this->Level3();
    }else if(this->levelType == LevelType::nullLevel){
        this->LevelNull();
    }
}
void Level::mapInit() {
    this->map->sizeMap();
    this->initMap();
}



void Level::upgradeReInit() {
    if(Map::isUpgrade){
        //升级过或者第一次，就要初始化
        this->sizeMap();
        Map::isUpgrade = false;
        //this->map->isInit = false;

        levelInit();
        this->initMap();
    }



}

void Level::upgrade(char input) {
    if(map->upGradeTimes>0){
        if(input=='z'){
            //升级开采机速率
            if(this->map->ExtractorInterval  > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                this->map->ExtractorInterval -=1;

            }
        }else if(input == 'x'){
            //升级传送带速率
            if(this->map->TransmissionBeltInterval > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                this->map->TransmissionBeltInterval -=1;

            }
        }else if(input == 'c'){
            //升级切割器速率
            if(this->map->CutterInterval > 1){
                //this->isUpgrade = false;
                map->upGradeTimes--;

                this->map->CutterInterval -=1;
            }
        }
    }
}

























