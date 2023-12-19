//
// Created by 14832 on 2023/12/18.
//

#include "../header/SavingFile.h"

vector<vector<string>> SavingFile::read(const string& name) {
    //以读入方式打开文件
    ifstream csv_data(name, ios::in);
    if (!csv_data.is_open()){
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    string line;

    vector<vector<string>> result;
    vector<string> words; //声明一个字符串向量
    string word;
    // ------------读取数据-----------------
    // 读取标题行
    //getline(csv_data, line);


    istringstream sin;
    // 按行读取数据
    while (getline(csv_data, line))
    {
        // 清空vector及字符串流,只存当前行的数据
        words.clear();
        sin.clear();

        sin.str(line);
        //将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
        while (getline(sin, word, ','))
        {
            words.push_back(word); //将每一格中的数据逐个push
        }
        if(words.size()>0){
            result.push_back(words);
        }


    }
    csv_data.close();

    return result;

}

void SavingFile::readFile(const string &name,Level* level1,Level* level2,Level* level3) {
    auto file = read(name);

    for(int i =0;i<7;i++){
        readGlobalVariable(file,i);
    }
    readLevel(file,level1);
    readLevel(file,level2);
    readLevel(file,level3);


}



void SavingFile::readGlobalVariable(const vector<vector<string>> &file, int i) {
    if(file[i][0] == "CentreSize"){
        int CentreSize = atoi(file[i][1].c_str());
        Map::CentreSize = CentreSize;
    }else if(file[i][0] == "AMineralSize"){
        int AMineralSize = atoi(file[i][1].c_str());
        Map::AMineralSize = AMineralSize;
    }else if(file[i][0] == "BMineralSize"){
        int BMineralSize = atoi(file[i][1].c_str());
        Map::BMineralSize = BMineralSize;
    }else if(file[i][0]=="MapSize"){
        int H = atoi(file[i][1].c_str());
        int W = atoi(file[i][2].c_str());
        Map::H = H;
        Map::W = W;
    }else if(file[i][0]=="AMineralValue"){
        int AMineralValue = atoi(file[i][1].c_str());
        Mineral::AMineralValue = AMineralValue;
    }else if(file[i][0]=="BMineralValue"){
        int BMineralValue = atoi(file[i][1].c_str());
        Mineral::BMineralValue = BMineralValue;
    }else if(file[i][0]=="Money"){
        int money = atoi(file[i][1].c_str());
        Map::money = money;
    }

}

void SavingFile::readLevel(const vector<vector<string>>& file,Level* level) {
    //获取每一关的存档
    int levelIndex = -1;
    string name;
    switch (level->levelType) {
        case level1: name = "level1";
            break;
        case level2:name = "level2";
            break;
        case level3:name = "level3";
            break;
        case nullLevel:name="nullLevel";
            break;
    }

    for(int i =0;i<file.size()-1;i++){
        if(file[i][0]==name){
            levelIndex = i+1;
            break;
        }
    }

    if(levelIndex==-1){
        //存档里没有这一关
        level->levelInit();
        level->mapInit();
    }
    //在已经更新过全局变量的基础上，重新调整大小
    level->sizeMap();
    level->levelInit();
    for(int i = levelIndex;i<levelIndex + Map::H;i++){
        for(int j =0;j<Map::W;j++){
            level->map->board[i-levelIndex][j] = fromStringToObject(file[i][j]);
        }
    }

}

Object *SavingFile::fromStringToObject(string object) {
    int colonIndex = object.find(':');
    int plusIndex = object.find('+');
    if(colonIndex == string::npos){
        return fromAllStringToObject(object);
    }else{
        string Equip = object.substr(0,colonIndex);
        string mineral = object.substr(colonIndex+1,plusIndex- colonIndex-1);
        string dir = object.substr(plusIndex+1);
        Equipment* equipment =(Equipment*) fromStringToEquipment(Equip,dir);
        equipment->mineral = (Mineral*) fromAllStringToObject(mineral);
        return equipment;
    }
}

Equipment *SavingFile::fromStringToEquipment(const string& object,const string& dir) {
    direction direction;
    if(dir=="up"){
        direction = direction::up;
    }else if(dir == "down"){
        direction = direction::down;
    }else if(dir == "left"){
        direction = direction::left;
    }else if(dir == "right"){
        direction = direction::right;
    }
    if(object == "extractor") return new Extractor(direction);
    if(object=="transmissionBelt") return new TransmissionBelt(direction);
    if(object == "cutter") return new Cutter(direction,order::first);
    if(object == "rubbishBin") return new RubbishBin();
    if(object=="centre") return new Centre();

}

Object *SavingFile::fromAllStringToObject(const string& object) {
    if(object == "nullObject") return new NullObject();
    //if(object == "extractor") return new Extractor();
    //if(object=="transmissionBelt") return new TransmissionBelt();
    //if(object == "cutter") return new Cutter();
    if(object == "rubbishBin") return new RubbishBin();
    if(object == "Amineral") return new AMineral();
    if(object == "Bmineral") return new BMineral;
    if(object== "centre") return new Centre();
    if(object == "nullMineral") return new NullMineral();
    if(object == "halfAmineral") return new HalfAMineral();

}

void SavingFile::writeFile(const string& name,Level* level1,Level* level2,Level* level3) {
    ofstream outFile(name, ios::out);
    vector<vector<string>>words;
    words = writeGlobalVariable();
    auto temp = writeLevel(level1);
    for(int i =0;i<temp.size();i++){
        words.push_back(temp[i]);
    }
    temp.clear();

    temp = writeLevel(level2);
    for(int i =0;i<temp.size();i++){
        words.push_back(temp[i]);
    }
    temp.clear();

    temp = writeLevel(level3);
    for(int i =0;i<temp.size();i++){
        words.push_back(temp[i]);
    }
    temp.clear();


    //写入文件
    for(int i =0;i<words.size();i++){
        for(int j=0;j<words[i].size();j++){
            outFile<<words[i][j];
            if(j<words[i].size()-1){
                outFile<<",";
            }else{
                outFile<<endl;
            }

        }
    }

}

vector<vector<string>> SavingFile::writeGlobalVariable() {
    vector<vector<string>> file;

    vector<string> CentreSize;
    CentreSize.push_back("CentreSize");
    CentreSize.push_back(to_string(Map::CentreSize));
    file.push_back(CentreSize);

    vector<string> AMineralSize;
    AMineralSize.push_back("AMineralSize");
    AMineralSize.push_back(to_string(Map::AMineralSize));
    file.push_back(AMineralSize);

    vector<string> BMineralSize;
    BMineralSize.push_back("BMineralSize");
    BMineralSize.push_back(to_string(Map::BMineralSize));
    file.push_back(BMineralSize);

    vector<string> MapSize;
    MapSize.push_back("MapSize");
    MapSize.push_back(to_string(Map::H));
    MapSize.push_back(to_string(Map::W));
    file.push_back(MapSize);

    vector<string> AMineralValue;
    AMineralValue.push_back("AMineralValue");
    AMineralValue.push_back(to_string(Mineral::AMineralValue));
    file.push_back(AMineralValue);

    vector<string> BMineralValue;
    BMineralValue.push_back("BMineralValue");
    BMineralValue.push_back(to_string(Mineral::BMineralValue));
    file.push_back(BMineralValue);

    vector<string> Money;
    Money.push_back("Money");
    Money.push_back(to_string(Map::money));
    file.push_back(Money);

    return file;
}

vector<vector<string>> SavingFile::writeLevel(Level* level) {
    vector<vector<string>> words;
    vector<string> line;
    if(level->levelType == level1){
        line.push_back("level1");
    }else if(level->levelType == level2){
        line.push_back("level2");
    }else if(level->levelType == level3){
        line.push_back("level3");
    }

    words.push_back(line);
    for(int i=0; i < level->map->board.size(); i++){
        line.clear();
        for(int j =0; j < level->map->board[i].size(); j++){
            line.push_back(fromObjectToString(level->map->board[i][j]));
        }
        words.push_back(line);
    }

    return words;

}



string SavingFile::fromObjectToString(Object *object) {
    type type = object->type;
    //是否是器械
    if(type== type::extractor || type== type::cutter || type==type::centre||type==type::transmissionBelt || type==type::rubbishBin){
        return fromEquipmentToString((Equipment*)object);
    }else{
        return fromAllTypeToString(object->type);
    }
}

string SavingFile::fromAllTypeToString(type type) {
    switch (type) {
        case type::nullObject : return "nullObject";
        case extractor: return "extractor";
        case transmissionBelt:return "transmissionBelt";
        case cutter:return "cutter";
        case rubbishBin:return "rubbishBin";
        case Amineral:return "Amineral";
        case Bmineral:return "Bmineral";
        case centre:return "centre";
        case nullMineral:return "nullMineral";
        case halfAmineral:return "halfAmineral";
    }

}

string SavingFile::fromEquipmentToString(Equipment *equipment) {
    string dir = "up";
    switch (equipment->dir) {
        case up: dir = "up";
            break;
        case down: dir = "down";
            break;
        case direction::left:dir = "left";
            break;
        case direction::right: dir = "right";
            break;
    }
    return fromAllTypeToString(equipment->type) + ":" + fromAllTypeToString(equipment->mineral->type) + "+" + dir ;
}












