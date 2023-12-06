//
// Created by 14832 on 2023/12/4.
//

#include "../header/Map.h"

Map::Map() {
    this->cursor = new Cursor();

    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            this->board[i][j] = new NullObject();
        }
    }

    this->cursor->containedObj = this->board[this->cursor->x][this->cursor->y];



}

void Map::moveCursor(direction dir) {
    if(dir == direction::up){
        this->cursor->x--;
        if(this->cursor->x <0){
            this->cursor->x=0;
        }
    } else if(dir == direction::down){
        this->cursor->x++;
        if(this->cursor->x >=H){
            this->cursor->x = H-1;
        }
    }else if(dir == direction::left){
        this->cursor->y--;
        if(this->cursor->y <0){
            this->cursor->y = 0;
        }
    }else if(dir == direction::right){
        this->cursor->y++;
        if(this->cursor->y >=W){
            this->cursor->y = W-1;
        }
    }
    this->cursor->containedObj = this->board[this->cursor->x][this->cursor->y];
}

direction Map::inputForMoveCursor(char input) {

    if (input == 'w') {
        return direction::up;
    } else if (input == 's') {
        return direction::down;
    }else if(input =='a'){
        return direction::left;
    }else if(input == 'd'){
        return direction::right;
    }
    return direction::up;
}

void Map::transmission() {

}

void Map::cursorInputChoose(char input) {
    if(input == '1' || input == '2' || input == '3' || input=='4' || input==' '||input=='r'){
        Object *toFree = this->cursor->curObj;
        if(input == '1'){
            this->cursor->curObj = new TransmissionBelt(direction::up);
        }else if(input == '2'){
            this->cursor->curObj = new Extractor(direction::up);
        }else if(input == '3'){
            this->cursor->curObj = new Cutter(direction::up,order::first);
        }else if(input =='4'){
            this->cursor->curObj = new RubbishBin();
        }else if(input==' '){

            if(this->cursor->curObj->type == type::nullObject){
                this->cursor->curObj = new NullObject();
                return;
            }
            //加入开采器
            if(this->cursor->curObj->type == type::extractor){
                Extractor *curExt =(Extractor *) this->cursor->curObj;
                curExt->deploy(this->board[this->cursor->x][this->cursor->y]);
            }

            //加入切割机
            if(this->cursor->curObj->type == type::cutter){
                Cutter *curCutter = (Cutter *) this->cursor->curObj;
                if(curCutter->dir == direction::up){
                    if(this->cursor->y >=W-1){
                        return;
                    }else{
                        //在map上加上另一半cutter
                        this->board[this->cursor->x][this->cursor->y+1] = new Cutter(direction::up,order::second);
                    }
                }
            }
            //TODO

            //在map中加上光标现在的object
            this->board[this->cursor->x][this->cursor->y] = this->cursor->curObj;
            this->cursor->containedObj = this->board[this->cursor->x][this->cursor->y];
            this->cursor->curObj = new NullObject();
        }else if(input=='r'){
            //转向
            direction toDir = direction::up;
            auto curEquipment = (Equipment *) this->cursor->curObj;
            direction curDir = curEquipment->dir;

            if(curDir == direction::up){
                toDir = direction::right;
            }else if(curDir == direction::right){
                toDir = direction::down;
            }else if(curDir == direction::down){
                toDir = direction::left;
            }else if(curDir == direction::left){
                toDir = direction::up;
            }

            curEquipment->changeDirection(toDir);

        }
    }

}

void Map::ExtractorOperate(int x, int y) {


    if(this->board[x][y]->type != type::extractor){
        return;
    }



    auto curExt = (Extractor *) this->board[x][y];
    if(curExt->curTime == curExt->interval){
        curExt->curTime=0;
        //时间到了才能执行

        //记录下extractor内矿物的种类
        type curMineralType = curExt->mineral->type;

        if(curExt->dir == direction::up){
            if(x==0){
                //越界
                return;
            }
            if(this->board[x-1][y]->type == type::transmissionBelt ||
               this->board[x-1][y]->type == type::cutter||
               this->board[x-1][y]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x-1][y];
                curDirTo->mineral = curExt->mineral;
            }
        }else if(curExt->dir == direction::down){
            if(x == H-1){
                //越界
                return;
            }
            if(this->board[x+1][y]->type == type::transmissionBelt ||
               this->board[x+1][y]->type == type::cutter||
               this->board[x+1][y]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x+1][y];
                curDirTo->mineral = curExt->mineral;
            }
        }else if(curExt->dir == direction::left){
            if(y==0){
                //越界
                return;
            }
            if(this->board[x][y-1]->type == type::transmissionBelt ||
               this->board[x][y-1]->type == type::cutter||
               this->board[x][y-1]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x][y-1];
                curDirTo->mineral = curExt->mineral;
            }

        }else if(curExt->dir == direction::right){
            if(y==W-1){
                //越界
                return;
            }
            if(this->board[x][y+1]->type == type::transmissionBelt ||
               this->board[x][y+1]->type == type::cutter||
               this->board[x][y+1]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x][y+1];
                curDirTo->mineral = curExt->mineral;
            }
        }


        //在原地重新放置一个矿物
        if(curMineralType == type::Amineral){
            curExt->mineral = new AMineral();
        }else if(curMineralType == type::Bmineral){
            curExt->mineral = new BMineral();
        }

    }


}

void Map::TransmissionBeltOperate(int x, int y,vector<TransmissionBelt*> *curTran,vector<Equipment*> *ToDir) {

    if(this->board[x][y]->type != type::transmissionBelt){
        return;
    }

    auto curTrans = (TransmissionBelt *) this->board[x][y];

    if(curTrans->curTime == curTrans->interval){
        curTrans->curTime = 0;
        if(curTrans->mineral->type==type::nullMineral){
            return;
        }
        if(curTrans->dir == direction::up){
            if(x==0){
                //越界
                return;
            }
            if(this->board[x-1][y]->type == type::transmissionBelt ||
               this->board[x-1][y]->type == type::cutter||
               this->board[x-1][y]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x-1][y];
                if(curDirTo->mineral->type != type::nullMineral){
                    //如果方向上的下一个满了，就堵塞着
                    return;
                }
                curTran->push_back(curTrans);
                ToDir->push_back(curDirTo);
//                curDirTo->mineral = curTrans->mineral;
//                curTrans->mineral = new NullMineral();
            }

        }else if(curTrans->dir == direction::down){

            if(x==H-1){
                //越界
                return;
            }
            if(this->board[x+1][y]->type == type::transmissionBelt ||
               this->board[x+1][y]->type == type::cutter||
               this->board[x+1][y]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x+1][y];
                if(curDirTo->mineral->type != type::nullMineral){
                    //如果方向上的下一个满了，就堵塞着
                    return;
                }
                curTran->push_back(curTrans);
                ToDir->push_back(curDirTo);
//                curDirTo->mineral = curTrans->mineral;
//                curTrans->mineral = new NullMineral();
            }

        }else if(curTrans->dir == direction::left){

            if(y==0){
                //越界
                return;
            }
            if(this->board[x][y-1]->type == type::transmissionBelt ||
               this->board[x][y-1]->type == type::cutter||
               this->board[x][y-1]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x][y-1];
                if(curDirTo->mineral->type != type::nullMineral){
                    //如果方向上的下一个满了，就堵塞着
                    return;
                }
                curTran->push_back(curTrans);
                ToDir->push_back(curDirTo);
//                curDirTo->mineral = curTrans->mineral;
//                curTrans->mineral = new NullMineral();
            }

        }else if(curTrans->dir == direction::right){

            if(y==W-1){
                //越界
                return;
            }
            if(this->board[x][y+1]->type == type::transmissionBelt ||
               this->board[x][y+1]->type == type::cutter||
               this->board[x][y+1]->type==type::rubbishBin){
                //如果方向上是1.传送带 2.切割器 3.垃圾桶，那就工作
                auto curDirTo = (Equipment *) this->board[x][y+1];
                if(curDirTo->mineral->type != type::nullMineral){
                    //如果方向上的下一个满了，就堵塞着
                    return;
                }
                curTran->push_back(curTrans);
                ToDir->push_back(curDirTo);
//                curDirTo->mineral = curTrans->mineral;
//                curTrans->mineral = new NullMineral();
            }

        }

    }



}

void Map::operateEverything() {
    auto curTrans = new vector<TransmissionBelt *>;
    auto ToDir = new vector<Equipment *>;
    for(int i = 0;i<H;i++){
        for(int j=0;j<W;j++){
            this->ExtractorOperate(i,j);
            this->TransmissionBeltOperate(i,j,curTrans,ToDir);
            updateEquipmentCurTime(i,j);
        }
    }

    Transmisson(curTrans,ToDir);

}

void Map::updateEquipmentCurTime(int x, int y) {

    if (this->board[x][y]->type == type::transmissionBelt ||
        this->board[x][y]->type == type::cutter ||
        this->board[x][y]->type == type::extractor ||
        this->board[x][y]->type == type::rubbishBin) {
        auto curEquipment = (Equipment *) this->board[x][y];
        curEquipment->curTime++;
    }



}

void Map::Transmisson(vector<TransmissionBelt *> *curTrans, vector<Equipment *> *ToDir) {
    for(int i =0;i<curTrans->size();i++){
//        curDirTo->mineral = curTrans->mineral;
//        curTrans->mineral = new NullMineral();
        (*ToDir)[i]->mineral = (*curTrans)[i]->mineral;
        (*curTrans)[i]->mineral = new NullMineral();

    }
}
