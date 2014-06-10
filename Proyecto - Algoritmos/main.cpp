#include <iostream>

using namespace std;

struct nodo
{
    string nombre;//nombre del vertice o nodo
    string lugar;
    string gusto;
    struct nodo *siguienteNodo;
    struct arista *aristaAdyacente;//puntero hacia la primera arista del nodo
};

struct arista
{
    struct nodo *destino;//puntero al nodo de llegada
    struct arista *siguienteArista;
    int peso;
};

typedef struct nodo *Tnodo;//  Tipo Nodo

typedef struct arista *Tarista; //Tipo Arista

Tnodo inicioDeRed;//puntero cabeza


/*                      INSERTAR USUARIO AL GRAFO
---------------------------------------------------------------------*/
void insertarNodo()
{
    Tnodo temporal,nuevo=new struct nodo;

    cout<<"Ingrese el nombre del nuevo usuario:";
    cin>>nuevo->nombre;

    cout<<"Ingrese el lugar donde vive:";
    cin>>nuevo->lugar;

    cout<<"Ingrese cual es su gusto:";
    cin>>nuevo->gusto;

    nuevo->siguienteNodo = NULL;
    nuevo->aristaAdyacente=NULL;

    if(inicioDeRed==NULL)
    {
        inicioDeRed = nuevo;
        cout<<"Primer usuario ingresado...!!!";
    }
    else
    {
        temporal = inicioDeRed;
        while(temporal->siguienteNodo!=NULL)
        {
            temporal = temporal->siguienteNodo;
        }
        temporal->siguienteNodo = nuevo;
        cout<<"Nuevo usuario ingresado...!!!";
    }

}


/*                      AGREGAR RELAION DE AMISTAD
  funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void AgregaArista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo, int pPeso)
{
    Tarista temporal;
    if(aux->aristaAdyacente==NULL)
    {
        aux->aristaAdyacente=nuevo;
        nuevo->destino=aux2;
        nuevo->peso=pPeso;
        cout<<"Primera relacion de amistad....!";
    }
    else
    {
        temporal=aux->aristaAdyacente;
        while(temporal->siguienteArista!=NULL)
            temporal=temporal->siguienteArista;
        nuevo->destino=aux2;
        nuevo->peso;
        temporal->siguienteArista=nuevo;
        cout<<"Relacion de amistad creada...!!!!";
    }
}


/*                      INSERTAR AMISTAD
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void InsertarAmistad()
{
    string inicio, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;
    int peso;

    if(inicioDeRed==NULL)
    {
        cout<<"Grafo vacio...!!!!";
        return;
    }
    nuevo->siguienteArista=NULL;

    cout<<"Ingrese el amigo a enlazar:";
    cin>>fin;

    cout<<"Ingrese el peso de la relación :";
    cin>>peso;

    aux=inicioDeRed;

    aux2=inicioDeRed;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }

        aux2=aux2->siguienteNodo;
    }
    AgregaArista(aux,aux2, nuevo,peso);
    return;
}


/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void InsertarRelacionesDeAmistad()
{
    string inicio, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;
    int peso;

    if(inicioDeRed==NULL)
    {
        cout<<"Red vacia...!!!!";
        return;
    }
    nuevo->siguienteArista=NULL;
    cout<<"Ingrese la persona de inicio:";
    cin>>inicio;
    cout<<"Ingrese la persona final:";
    cin>>fin;

    cout<<"Ingrese el peso de la relación :";
    cin>>peso;

    aux=inicioDeRed;

    aux2=inicioDeRed;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }

        aux2=aux2->siguienteNodo;
    }
    while(aux!=NULL)
    {
        if(aux->nombre==inicio)
        {
            AgregaArista(aux,aux2, nuevo,peso);
            return;
        }

        aux = aux->siguienteNodo;
    }
}


/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
    esta funcion es utilizada al borrar un nodo pues si tiene aristas
    es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void VaciarAristas(Tnodo &aux)
{
    Tarista temporal1,temporal2;
    temporal1=aux->aristaAdyacente;
    while(temporal1->siguienteArista!=NULL)
    {
        temporal2=temporal1;
        temporal1=temporal1->siguienteArista;
        delete(temporal2);
    }
}


/*                      ELIMINAR RELACION DE AMISTAD
    funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
void EliminarRelacionDeAmistad()
{
    string inicio, fin;
    Tnodo aux, aux2;
    Tarista temporal1,temporaal2;

    cout<<"Ingrese nodo de inicio:";
    cin>>inicio;
    cout<<"Ingrese nodo fin:";
    cin>>fin;
    aux=inicioDeRed;
    aux2=inicioDeRed;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }
        else
            aux2=aux2->siguienteNodo;
    }
    while(aux!=NULL)
    {
        if(aux->nombre==inicio)
        {
            temporal1=aux->aristaAdyacente;
            while(temporal1!=NULL)
            {
                if(temporal1->destino==aux2)
                {
                    if(temporal1==aux->aristaAdyacente)
                        aux->aristaAdyacente=aux->aristaAdyacente->siguienteArista;
                    else
                        temporaal2->siguienteArista=temporal1->siguienteArista;
                    delete(temporal1);
                    cout<<"Arista  "<<aux->nombre<<"----->"<<aux2->nombre<<" eliminada.....!!!!";
                    return;
                }
            }
            temporaal2=temporal1;
            temporal1=temporal1->siguienteArista;
        }
        aux = aux->siguienteNodo;
    }
}



/*                      MOSTRAR AMIGOS
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void MostrarAmigos()
{
    Tnodo nodoABuscar;
    Tarista ar;
    nodoABuscar=inicioDeRed;
    cout<<"Nodo| Lista de adyacencia\n";

    while(nodoABuscar!=NULL)
    {
        cout<<"  "<<nodoABuscar->nombre<<"|";
        if(nodoABuscar->aristaAdyacente!=NULL)
        {
            ar=nodoABuscar->aristaAdyacente;
            while(ar!=NULL)
            {
                cout<<" "<<ar->destino->nombre;
                ar=ar->siguienteArista;
            }

        }
        nodoABuscar=nodoABuscar->siguienteNodo;
        cout<<endl;
    }

}


int main()
{
    int opcion=0;

    do
    {
        cout << endl;
        cout << "1. Insertar nuevos usuarios" << endl;
        cout << "2. Agregar amigos" << endl;
        cout << "3. Agregar una relacion de amistad" << endl;
        cout << "4. Eliminar una relaion de amistad" << endl;
        cout << "5. Buscar amigos" << endl;
        cout << "6. Mostrar arcos de un nodo" << endl;
        cout << "7. Mostrar el peso" << endl;
        cout << "8. Mostrar los arcos con mayor peso" << endl;

        cin>>opcion;

        if(opcion==1)
        {
            insertarNodo();
        }

        if(opcion==2)
        {
            InsertarAmistad();
        }

        if(opcion==3)
        {
            InsertarRelacionesDeAmistad();
        }

        if(opcion==4)
        {
            EliminarRelacionDeAmistad();
        }

        if(opcion==5)
        {
            MostrarAmigos();
        }

        if(opcion==6)
        {
            //MostrarAristas();
        }

        if(opcion==7)
        {
            //MostrarPeso();
        }
        cout << endl;

    }
    while(opcion<=7);

}
