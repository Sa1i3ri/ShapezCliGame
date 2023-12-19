//
// Created by 14832 on 2023/12/18.
//

#ifndef REALGAME_SAVINGFILE_H
#define REALGAME_SAVINGFILE_H
#include "string"
#include "../Interface/Level.h"
#include "iostream"
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "../Interface/Map.h"
#include "../Mineral/Mineral.h"


using namespace std;


class SavingFile {
private:
    static vector<vector<string>> read(const string& name);
    static void readGlobalVariable(const vector<vector<string>>& file,int i);
    static void readLevel(const vector<vector<string>>& file,Level* level);
    static Object* fromStringToObject(string object);
    static Equipment* fromStringToEquipment(const string& object,const string& dir);
    static Object* fromAllStringToObject(const string& object);

    static vector<vector<string>> writeGlobalVariable();
    static vector<vector<string>> writeLevel(Level* level);
    static string fromObjectToString(Object *object);
    static string fromAllTypeToString(type type);
    static string fromEquipmentToString(Equipment *equipment);

public:
    static void readFile(const string& name,Level* level1,Level* level2,Level* level3);
    static void writeFile(const string& name,Level* level1,Level* level2,Level* level3);
};


#endif //REALGAME_SAVINGFILE_H
