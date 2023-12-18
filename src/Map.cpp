//
// Created by 14832 on 2023/12/4.
//

#include "../header/Map.h"

int Map::W = 30;
int Map::H = 20;

Map::Map() {
    this->cursor = new Cursor();
    this->overallValue = 0;
    this->AMineralNum =0;
    this->BMineralNum =0;
    this->HalfAMineralNum =0;
    this->mission1 = false;
    this->mission2 = false;
    this->mission3 = false;
    //this->isUpgrade = false;
    this->upGradeTimes = 0;
    this->level1 = false;
    this->level2 = false;
    this->level3 = false;


    for(int i =0;i<H;i++){
        vector<Object*> temp;
        for(int j=0;j<W;j++){
            temp.push_back(new NullObject);
        }
        this->board.push_back(temp);
    }


    this->cursor->containedObj = this->board[this->cursor->x][this->cursor->y];

}

void Map::initMap() {
    this->cursor = new Cursor();
    this->overallValue = 0;
    this->AMineralNum =0;
    this->BMineralNum =0;
    this->HalfAMineralNum =0;
    this->mission1 = false;
    this->mission2 = false;
    this->mission3 = false;
    //this->isUpgrade = false;
    this->upGradeTimes = 0;
    this->level1 = false;
    this->level2 = false;
    this->level3 = false;

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

void Map::cursorInputChoose(char input) {
    if(input == '1' || input == '2' || input == '3' || input=='4' ||input=='5' || input==' '||input=='r'){
        Object *toFree = this->cursor->curObj;
        if(input == '1'){
            this->cursor->curObj = new TransmissionBelt(direction::up);
        }else if(input == '2'){
            this->cursor->curObj = new Extractor(direction::up);
        }else if(input == '3'){
            this->cursor->curObj = new Cutter(direction::up,order::first);
        }else if(input =='4'){
            this->cursor->curObj = new RubbishBin();
        }else if(input=='5'){
            this->cursor->curObj = new NullObject();
        }else if(input==' '){
            //加入开采器
            if(this->cursor->curObj->type == type::extractor){
                Extractor *curExt =(Extractor *) this->cursor->curObj;
                curExt->deploy(this->board[this->cursor->x][this->cursor->y]);
            }

            //加入切割机



            if(this->cursor->curObj->type == type::cutter){
                Cutter *curCutter = (Cutter *) this->cursor->curObj;
                //四个方向
                if(curCutter->dir == direction::up){
                    if(this->cursor->y ==W-1){
                        return;
                    }else{
                        //在map上加上另一半cutter
                        this->board[this->cursor->x][this->cursor->y+1] = new Cutter(direction::up,order::second);
                    }
                }else if(curCutter->dir == direction::down){
                    if(this->cursor->y ==0){
                        return;
                    }else{
                        //在map上加上另一半cutter
                        this->board[this->cursor->x][this->cursor->y-1] = new Cutter(direction::down,order::second);
                    }
                }else if(curCutter->dir == direction::left){
                    if(this->cursor->x ==0){
                        return;
                    }else{
                        //在map上加上另一半cutter
                        this->board[this->cursor->x-1][this->cursor->y] = new Cutter(direction::left,order::second);
                    }
                }else if(curCutter->dir == direction::right){
                    if(this->cursor->x ==H-1){
                        return;
                    }else{
                        //在map上加上另一半cutter
                        this->board[this->cursor->x+1][this->cursor->y] = new Cutter(direction::right,order::second);
                    }
                }


            }
            //加入垃圾桶和传送带，一下代码足矣

            //在map中加上光标现在的object
            this->board[this->cursor->x][this->cursor->y] = this->cursor->curObj;
            this->cursor->containedObj = this->board[this->cursor->x][this->cursor->y];
            if(this->cursor->curObj->type == type::transmissionBelt){
                this->cursor->curObj = new TransmissionBelt(*(TransmissionBelt *)this->cursor->curObj);
            }else if(this->cursor->curObj->type == type::extractor){
                this->cursor->curObj = new Extractor(*(Extractor *)this->cursor->curObj);
            }else if(this->cursor->curObj->type == type::cutter){
                this->cursor->curObj = new Cutter(*(Cutter *)this->cursor->curObj);
            }else if(this->cursor->curObj->type == type::rubbishBin){
                this->cursor->curObj = new RubbishBin(*(RubbishBin *)this->cursor->curObj);
            }


        }else if(input=='r'){
            //转向
            if(this->cursor->curObj->type == type::nullObject){
                return;
            }
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

        if(curExt->mineral->type == type::nullMineral){
            return;
        }

        //记录下extractor内矿物的种类
        type curMineralType = curExt->mineral->type;
        if(curMineralType == type::nullMineral){
            return;
        }

        if(curExt->dir == direction::up){
            if(x==0){
                //越界
                return;
            }
            if(this->board[x-1][y]->type == type::transmissionBelt ||
               this->board[x-1][y]->type == type::cutter||
               this->board[x-1][y]->type==type::rubbishBin||
               this->board[x-1][y]->type==type::centre){
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
               this->board[x+1][y]->type==type::rubbishBin||
                this->board[x+1][y]->type==type::centre){
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
               this->board[x][y-1]->type==type::rubbishBin||
                    this->board[x][y-1]->type==type::centre){
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
               this->board[x][y+1]->type==type::rubbishBin||
                    this->board[x][y+1]->type==type::centre){
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
               this->board[x-1][y]->type==type::rubbishBin||
               this->board[x-1][y]->type==type::centre){
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
               this->board[x+1][y]->type==type::rubbishBin||
               this->board[x+1][y]->type==type::centre){
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
               this->board[x][y-1]->type==type::rubbishBin||
               this->board[x][y-1]->type==type::centre){
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
               this->board[x][y+1]->type==type::rubbishBin||
               this->board[x][y+1]->type==type::centre){
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
            this->TransmissionBeltOperate(i,j,curTrans,ToDir);
        }
    }
    Transmisson(curTrans,ToDir);
    for(int i = 0;i<H;i++){
        for(int j=0;j<W;j++){
            this->CentreOperate(i,j);
            this->CutterOperate(i,j);
            this->ExtractorOperate(i,j);
            this->RubbishBinOperate(i,j);
            updateEquipmentCurTime(i,j);
        }
    }



}

void Map::updateEquipmentCurTime(int x, int y) {

    if (this->board[x][y]->type == type::transmissionBelt ||
        this->board[x][y]->type == type::cutter ||
        this->board[x][y]->type == type::extractor ||
        this->board[x][y]->type == type::rubbishBin ||
        this->board[x][y]->type == type::centre) {
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

void Map::RubbishBinOperate(int x, int y) {
    if(this->board[x][y]->type != type::rubbishBin){
        return;
    }

    auto curRubbishBin = (RubbishBin *) this->board[x][y];

    if(curRubbishBin->curTime == curRubbishBin->interval){
        curRubbishBin->curTime = 0;
        if(curRubbishBin->mineral->type == type::nullMineral){
            return;
        }
        ::free(curRubbishBin->mineral);
        curRubbishBin->mineral = new NullMineral();
    }



}

void Map::CutterOperate(int x, int y) {
    if(this->board[x][y]->type != type::cutter){
        return;
    }

    auto curCutter = (Cutter *) this->board[x][y];
    if(curCutter->curTime == curCutter->interval){
        //时间到了才能操作
        curCutter->curTime = 0;
        if(curCutter->mineral->type == type::nullMineral){
            return;
        }

        auto curMineral = (Mineral *)curCutter->mineral;
        if(curMineral->isCutble){
            //可以被切割
            //这个vector只有两个值，第一个为x坐标，第二个为y坐标
            vector<int>* anotherCutterLocation = locateAnotherCutter(x,y,curCutter->ord,curCutter->dir);
            int anotherX = (*anotherCutterLocation)[0];
            int anotherY = (*anotherCutterLocation)[1];
            if(curCutter->dir == direction::up){
                if(x == 0){
                    //越界
                    return;
                }
                if( (this->board[x-1][y]->type == type::transmissionBelt ||
                        this->board[x-1][y]->type == type::rubbishBin||
                        this->board[x-1][y]->type == type::centre) &&
                        (this->board[anotherX-1][anotherY]->type == type::transmissionBelt ||
                        this->board[anotherX-1][anotherY]->type == type::rubbishBin||
                                this->board[anotherX-1][anotherY]->type == type::centre)){
                    //本Cutter和配套的Cutter的方向上都为传送带或者垃圾桶，才能输出
                    auto curDirTo1 = (Equipment *) this->board[x-1][y];
                    auto curDirTo2 = (Equipment *) this->board[anotherX-1][anotherY];
                    if(curDirTo1->mineral->type != type::nullMineral ||curDirTo2->mineral->type != type::nullMineral){
                        //如果方向上的下一个满了，就堵塞着
                        return;
                    }

                    ::free(curCutter->mineral);
                    curCutter->mineral = new NullMineral();
                    curDirTo1->mineral = new HalfAMineral();
                    curDirTo2->mineral = new HalfAMineral();

                }
            }else if(curCutter->dir == direction::down){
                if(x == H-1){
                    //越界
                    return;
                }
                if( (this->board[x+1][y]->type == type::transmissionBelt ||
                this->board[x+1][y]->type == type::rubbishBin ||
                        this->board[x+1][y]->type == type::centre) &&
                    (this->board[anotherX+1][anotherY]->type == type::transmissionBelt ||
                     this->board[anotherX+1][anotherY]->type == type::rubbishBin||
                            this->board[anotherX+1][anotherY]->type == type::centre)){
                    //本Cutter和配套的Cutter的方向上都为传送带或者垃圾桶，才能输出
                    auto curDirTo1 = (Equipment *) this->board[x+1][y];
                    auto curDirTo2 = (Equipment *) this->board[anotherX+1][anotherY];
                    if(curDirTo1->mineral->type != type::nullMineral ||curDirTo2->mineral->type != type::nullMineral){
                        //如果方向上的下一个满了，就堵塞着
                        return;
                    }

                    ::free(curCutter->mineral);
                    curCutter->mineral = new NullMineral();
                    curDirTo1->mineral = new HalfAMineral();
                    curDirTo2->mineral = new HalfAMineral();

                }
            }else if(curCutter->dir == direction::left){
                if(y==0){
                    //越界
                    return;
                }
                if( (this->board[x][y-1]->type == type::transmissionBelt ||
                     this->board[x][y-1]->type == type::rubbishBin||
                        this->board[x][y-1]->type == type::centre) &&
                    (this->board[anotherX][anotherY-1]->type == type::transmissionBelt ||
                     this->board[anotherX][anotherY-1]->type == type::rubbishBin||
                            this->board[anotherX][anotherY-1]->type == type::centre)){
                    //本Cutter和配套的Cutter的方向上都为传送带或者垃圾桶，才能输出
                    auto curDirTo1 = (Equipment *) this->board[x][y-1];
                    auto curDirTo2 = (Equipment *) this->board[anotherX][anotherY-1];
                    if(curDirTo1->mineral->type != type::nullMineral ||curDirTo2->mineral->type != type::nullMineral){
                        //如果方向上的下一个满了，就堵塞着
                        return;
                    }

                    ::free(curCutter->mineral);
                    curCutter->mineral = new NullMineral();
                    curDirTo1->mineral = new HalfAMineral();
                    curDirTo2->mineral = new HalfAMineral();

                }
            }else if(curCutter->dir == direction::right){
                if(y==W-1){
                    //越界
                    return;
                }
                if( (this->board[x][y+1]->type == type::transmissionBelt ||
                     this->board[x][y+1]->type == type::rubbishBin ||
                        this->board[x][y+1]->type == type::centre) &&
                    (this->board[anotherX][anotherY+1]->type == type::transmissionBelt ||
                     this->board[anotherX][anotherY+1]->type == type::rubbishBin||
                            this->board[anotherX][anotherY+1]->type == type::centre)){
                    //本Cutter和配套的Cutter的方向上都为传送带或者垃圾桶，才能输出
                    auto curDirTo1 = (Equipment *) this->board[x][y+1];
                    auto curDirTo2 = (Equipment *) this->board[anotherX][anotherY+1];
                    if(curDirTo1->mineral->type != type::nullMineral ||curDirTo2->mineral->type != type::nullMineral){
                        //如果方向上的下一个满了，就堵塞着
                        return;
                    }

                    ::free(curCutter->mineral);
                    curCutter->mineral = new NullMineral();
                    curDirTo1->mineral = new HalfAMineral();
                    curDirTo2->mineral = new HalfAMineral();

                }
            }


        }

    }
}

vector<int>* Map::locateAnotherCutter(int x,int y,order ord,direction dir) {
    auto *result = new vector<int>;
    if(ord==order::first){
        if(dir== direction::up){
            result->push_back(x);
            result->push_back(y+1);
        } else if(dir == direction::down){
            result->push_back(x);
            result->push_back(y-1);
        }else if(dir == direction::left){
            result->push_back(x-1);
            result->push_back(y);
        }else if(dir == direction::right){
            result->push_back(x+1);
            result->push_back(y);
        }
    }else if(ord == order::second){
        if(dir== direction::up){
            result->push_back(x);
            result->push_back(y-1);
        } else if(dir == direction::down){
            result->push_back(x);
            result->push_back(y+1);
        }else if(dir == direction::left){
            result->push_back(x+1);
            result->push_back(y);
        }else if(dir == direction::right){
            result->push_back(x-1);
            result->push_back(y);
        }
    }
    return result;
}

void Map::CentreOperate(int x, int y) {
    if(this->board[x][y]->type != type::centre){
        return;
    }
    auto curCentre = (Centre *) this->board[x][y];
    if(curCentre->curTime == curCentre->interval){
        curCentre->curTime = 0;
        this->missionsJudge(x,y);

    }
}

void Map::AMineralMission(Centre *curCentre) {
    if(curCentre->mineral->type == type::Amineral){
        this->AMineralNum++;
        this->overallValue += curCentre->mineral->value;

        free(curCentre->mineral);
        curCentre->mineral = new NullMineral();
    }
}

void Map::BMineralMission(Centre *curCentre) {
    if(curCentre->mineral->type == type::Bmineral){
        this->BMineralNum++;
        this->overallValue += curCentre->mineral->value;

        free(curCentre->mineral);
        curCentre->mineral = new NullMineral();
    }

}

void Map::HalfAMineralMission(Centre *curCentre) {
    if(curCentre->mineral->type == type::halfAmineral){
        this->HalfAMineralNum++;
        this->overallValue += curCentre->mineral->value;

        free(curCentre->mineral);
        curCentre->mineral = new NullMineral();
    }

}

void Map::missionsJudge(int x,int y) {

    auto curCentre = (Centre *) this->board[x][y];

    this->AMineralMission(curCentre);
    this->BMineralMission(curCentre);
    this->HalfAMineralMission(curCentre);


    if(this->AMineralNum == AMineralTarget || this->BMineralNum == BMineralTarget
    || this->HalfAMineralNum == HalfAMineralTarget){
        //完成任务，进行升级
        //this->isUpgrade = true;
        if(this->AMineralNum == AMineralTarget && this->mission1== false){
            this->upGradeTimes++;
            this->mission1 = true;
        }
        if(this->BMineralNum == BMineralTarget && this->mission2 == false){
            this->upGradeTimes++;
            this->mission2 = true;
        }
        if(this->HalfAMineralNum == HalfAMineralTarget && this->mission3 == false){
            this->upGradeTimes++;
            this->mission3 = true;
        }

    }

}








