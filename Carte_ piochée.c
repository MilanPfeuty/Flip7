Carte* pioche(){
    Carte* paquet = malloc(sizeof(Carte) * 79);
    if (paquet == NULL){
        exit(1);
    }

    int p = 0;

    for(int i = 0; i < 13; i++){
        int nb;

        if(i == 0 || i == 1){
            nb = 1;
        } else {
            nb = i;
        }

        for(int j = 0; j < nb; j++){
            paquet[p].numero = i;
            p++;
        }
    }
    return paquet;
}