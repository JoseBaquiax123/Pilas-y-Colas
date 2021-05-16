#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Cola {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;
    Nodo *fondo;
public:
    Cola();
    ~Cola();
    void insertar(int x);
    int extraer();
    bool vacia();
    int cantidad();
};


Cola::Cola()
{
    raiz = NULL;
    fondo = NULL;
}

Cola::~Cola()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

void Cola::insertar(int x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia()) 
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else 
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int Cola::extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
        Nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else 
        {
            raiz = raiz->sig;
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}

bool Cola::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

int Cola::cantidad()
{
    Nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}


class CajeroAutomatico {
public:
    void simulacion();
};

void CajeroAutomatico::simulacion()
{
    srand(time(NULL));
    int estado = 0;
    int llegada = rand()%(100-1); 
    int salida = -1;
    int cantAtendidas = rand()%(100-1);
    Cola *cola = new Cola();
    for (int segundo = 0; segundo < 2; segundo++) 
    {
        if (llegada == segundo)
        {
            if (estado == 0) 
            {
                estado = 1;
                salida = segundo + 2 + rand()%2;
            }
            else 
            {
                cola->insertar(segundo);
            }
            llegada = segundo + 2 + rand()%3;
        }
        if (salida == segundo)
        {
            estado = 0;
            cantAtendidas++;
            if (!cola->vacia()) 
            {
                cola->extraer();
                estado = rand()%(6-1);
                salida = segundo + 1 + rand()%6;
            }
        }
    }
    cout<<"-------cajero uno-------"<<endl;
    cout <<"Atendidos:" <<cantAtendidas <<"\n";
    cout <<"En cola:" <<cola->cantidad() <<"\n";
    cout <<"timepo de espera:" <<rand()%(8-2)<<" segundos"<<"\n";
   
}

class CajeroAutomaticoDos {
public:
    void simulacion();
};

void CajeroAutomaticoDos::simulacion()
{
    srand(time(NULL));
    int estado = 0;
    int llegada = rand()%(100-1); 
    int salida = -1;
    int cantAtendidas = rand()%(99-1);
    Cola *cola = new Cola();
    for (int segundo = 0; segundo < 2; segundo++) 
    {
        if (llegada == segundo)
        {
            if (estado == 0) 
            {
                estado = 1;
                salida = segundo + 2 + rand()%2;
            }
            else 
            {
                cola->insertar(segundo);
            }
            llegada = segundo + 2 + rand()%3;
        }
        if (salida == segundo)
        {
            estado = 0;
            cantAtendidas++;
            if (!cola->vacia()) 
            {
                cola->extraer();
                estado = 1;
                salida = segundo + 2 + rand()%(100-1);
            }
        }
    }
    cout<<"-----------cajero dos--------"<<endl;
    cout <<"Atendidos:" <<cantAtendidas <<"\n";
    cout <<"En cola:" <<cola->cantidad() <<"\n";
    cout <<"timepo de espera:" <<rand()%(6-3)<<" segundos"<<"\n";
    
}
class CajeroAutomaticoTres {
public:
    void simulacion();
};

void CajeroAutomaticoTres::simulacion()
{
    srand(time(NULL));
    int estado = 0;
    int llegada = rand()%(100-1); 
    int salida = -1;
    int cantAtendidas = rand()%(101-1);
    Cola *cola = new Cola();
    for (int segundo = 0; segundo < 2; segundo++) 
    {
        if (llegada == segundo)
        {
            if (estado == 0) 
            {
                estado = 1;
                salida = segundo + 2 + rand()%2;
            }
            else 
            {
                cola->insertar(segundo);
            }
            llegada = segundo + 2 + rand()%3;
        }
        if (salida == segundo)
        {
            estado = 0;
            cantAtendidas++;
            if (!cola->vacia()) 
            {
                cola->extraer();
                estado = 1;
                salida = segundo + 2 + rand()%(100-1);
            }
        }
    }
    cout<<"-------cajero Tres-------"<<endl;
    cout <<"Atendidos:" <<cantAtendidas <<"\n";
    cout <<"En cola:" <<cola->cantidad() <<"\n";
    cout <<"timepo de espera:" <<rand()%(7-0)<<" segundos"<<"\n";
   
}
class CajeroAutomaticoCuatro {
public:
    void simulacion();
};

void CajeroAutomaticoCuatro::simulacion()
{
    srand(time(NULL));
    int estado = 0;
    int llegada = rand() % 2 + 2; 
    int salida = -1;
    int cantAtendidas = rand()%(102-1);
    Cola *cola = new Cola();
    for (int segundo = 0; segundo < 2; segundo++) 
    {
        if (llegada == segundo)
        {
            if (estado == 0) 
            {
                estado = 1;
                salida = segundo + 2 + rand()%2;
            }
            else 
            {
                cola->insertar(segundo);
            }
            llegada = segundo + 2 + rand()%3;
        }
        if (salida == segundo)
        {
            estado = 0;
            cantAtendidas++;
            if (!cola->vacia()) 
            {
                cola->extraer();
                estado = 1;
                salida = segundo + 2 + rand()%(100-1);
            }
        }
    }
    cout<<"-------cajero cuatro-------"<<endl;
    cout <<"Atendidos:" <<cantAtendidas <<"\n";
    cout <<"En cola:" <<cola->cantidad() <<"\n";
   cout <<"timepo de espera:" <<rand()%(7-1)<<" segundos"<<"\n";
}

int main()
{
    CajeroAutomatico *cajero1 = new CajeroAutomatico();
    CajeroAutomaticoDos *cajero2 = new CajeroAutomaticoDos();
    CajeroAutomaticoTres *cajero3 = new CajeroAutomaticoTres();
    CajeroAutomaticoCuatro *cajero4 = new CajeroAutomaticoCuatro();
    cajero1->simulacion();
    cajero2->simulacion();
    cajero3->simulacion();
    cajero4->simulacion();
    delete cajero1;
    delete cajero2;
    delete cajero3;
    delete cajero4;
    return 0;
}

