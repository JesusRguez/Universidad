void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses, unsigned int ases, std::list<int> &selectedIDs, float mapWidth, float mapHeight, std::list<Object*> obstacles) {

    unsigned int costeTotal = 0;

    std::list<Defense*>::const_iterator it = defenses.begin();
    while (it != defenses.end()) {
        costeTotal += (*it)->cost;
        ++it;
    }

    if (costeTotal <= ases) {
        std::list<Defense*>::const_iterator iter = defenses.begin();
        while (iter != defenses.end()) {
            selectedIDs.push_back((*iter)->id);
            ++iter;
        }
    }else{

        // Algoritmo de la mochila

        i = defenses.size() - 1;
        int j = ases;

        std::list<Defense*>::const_iterator iterDef = defenses.end();
        --iterDef;

        // Ahora, recuperamos la combinacion de defensas

        while (i>=0 && j>0) {
            if(i>0 && matriz[i][j] == matriz[i-1][j]){
                --i;
                --iterDef;
            }else{
                selectedIDs.push_back((*iterDef)->id);
                j -= (*iterDef)->cost;
                --i;
                --iterDef;
            }
        }
    }
}
