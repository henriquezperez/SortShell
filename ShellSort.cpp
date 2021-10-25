#include <iostream>

using namespace std;
/*
    
    Método de ordenación SHELL

    Es una mejora del método de inserción directa que se utiliza cuando el número de elementos
    a ordenar es grande. El método se denomina SHELL en honor a su inventor Donald Shell, y también
    método de inserción con incrementos decrecientes.

    En el método de clasificación por inserción se compara con los elementos contiguos de su izquierda,
    uno tras otro. Si el elemento a insertar es más pequeño, por ejemplo, hay que ejecutar muchas
    comparaciones antes de colocarlo en su lugar definitivamente.

    Shell modificó los saltos contiguos resultantes de las comparaciones por saltos de mayor tamaño
    y con eso se conseguía la clasificación más rápida. El método se basa en fijar el tamaño de los
    saltos constantes pero de más de una posición.

    Ejemplo:

    Supongamos un vector de elementos:

    4, 12, 16, 24, 36, 3

    En el método de inserción directa, los saltos se hacen de una posición en una posición y se necesitará
    cinco comparaciones.

    En el método SHELL, si los saltos son de dos posiciones, se realizan tres comparaciones

    4, 12, 16, 24, 36, 3

    En el método se basa en tomar como salto N/2 (donde N es el número de elementos)
    y luego se va reduciendo a la mitad de cada repetición hasta que el salto o distancia vale 1.
    
    Arreglo = a[]
    N = 6
    (salto = N/2) ->  6/2 = 3
    3 saltos.
    j y k = posicion
    aux : variable auxiliar que contrenda a la variable 'j'
    y & z : número de intercambio

                                   4 <= 24 = Si                 16 <= 3 = No, hacer intercambio.
    a[j]      a[k]               a[4]     a[24]                      a[16]     a[3]
    ┌───────────┐                ┌───────────┐                        ┌───────────┐
    v           v                v           v                        v           v
    4, 12, 16, 24, 36, 3         4, 12, 16, 24, 36, 3   ...    4, 12, 16, 24, 36, 3 

    ----------------------------------------------------------------------------------------------
    Intercambio:

    aux = 16 //contrenda a 'j' del array
    y = 3   // 'y' contiene la variable 'k' del array
    z = 16 //se mueve a la variable 'k' del array
       
           a[y]     a[z]
           ┌───────────┐
           v           v
    4, 12, 3, 24, 36, 16

*/
void Intercambio(int &y, int &z);
void SortShell(int a[], int n);

int main(){
    cout<<"\n\tM\x82todo de ordenaci\xa2n SHELL\n\n";
    int cantidad=0;
    cout<<"\xa8"<<"Cantidad de n\xa3meros que desea ordenar?:";
    cin>>cantidad;
    int Arreglo[cantidad];
    for (int i = 0; i < cantidad; i++)
    {       
       cout<<i+1<<"-"<<"n\xa3mero:> ";
       cin>>Arreglo[i];
    }
    SortShell(Arreglo,cantidad);
    cout<<"\nEl arreglo ordenado ascendente es:\n";
    for (int i = 0; i < cantidad; i++)
    {
        cout<<Arreglo[i]<<"|";
    }
    cout<<"\n\nEl arreglo ordenado descendente es:\n";
    for (int i = cantidad -1 ; i >=0; i--)
    {
        cout<<Arreglo[i]<<"|";
    }
    cout<<endl<<endl;
    system("pause");
    return 0;
}

void SortShell(int a[], int n){

    int salto=0, i=0, j=0, k=0;
    salto = n/2;
    while (salto>0) //Mientras que el salto sea a 1, si es 0 termina el proceso
    {
        for (i = salto; i < n; i++)
        {
            j = i - salto;
            while (j>=0)
            {
                k = j + salto;
                if (a[j] <= a[k]) // Si esta ordenado
                {
                    j--;
                }
                else{ // de lo contrario intercambio de valor en la posicion
                    Intercambio(a[j],a[k]);
                    j -= salto;
                }   
            }
        }
        salto = salto/2; // Si esta ordenado la primera ronda, sigue hasta que el salto se a 1
    }
}

void Intercambio(int &y,int &z){
    int aux;
    aux = y;
    y = z;
    z = aux;
}

/*
void intercambio(int &y, int &z){
    int aux;
    aux = y;
    y = z;
    z = aux;
}

void ordenamientoShell(int a[], int n){

    int salto, i,j,k;
    salto = n/2;

    while (salto>0)
    {
        for (i = salto; i < n; i++)
        {
           j = i -salto;
           while (j>=0)
           {
               k = j + salto;
               if (a[j]<=a[k])
               {    
                   j--;
               }
               else{
                   intercambio(a[j],a[k]);
                   j -= salto;
               }
           }      
        }
        salto = salto/2;
    }
}

int main(){
    int a[] = {45,44,1,45,85,74};

    ordenamientoShell(a,6);
    cout<<"\nEl ordenamiento es ascendente:\n";
    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<"|";
    }
    
    system("pause");
    return 0;
}
*/