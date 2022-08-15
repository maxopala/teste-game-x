#ifndef MAPA_H
#define MAPA_H

#include<string>
class Mapa
{
private:
    std::string* m;
    int lins;
    int cols;
public:
    Mapa();
    bool acessivel(int i, int j);
    bool parede(int i, int j);
    bool saida(int i, int j);
    int getLins() const;
    int getCols() const;
};

#endif // MAPA_H
