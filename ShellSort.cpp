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
void DivLine(){
    cout<<"\n\n------------------------------------------------------------------\n";
}

void Impresion(int Arreglo[], int n){
    cout<<"\nArreglo ordenado en ascendente:\n\n";
    for (int i = 0; i < n; i++)
    {
        cout<<Arreglo[i]<<"|";
    }
    DivLine();
    cout<<"\nArreglo ordenado en descendente:\n\n";
    for (int i = n -1 ; i >=0; i--)
    {
        cout<<Arreglo[i]<<"|";
    }
}

void Intercambio(int &y, int &z){ //Cambia los valores de las posiciones j(y) y k(z)
    int aux;
    aux = y;
    y = z;
    z = aux;
}

void OrdenamientoShell(int Arreglo[], int n){
    int salto, i,j,k; // j = posición izquierda, k = posición derecha
    salto = n/2; //Cuantos posciones hace el salto iniciando con la posición cero
    while (salto>0) // Mientras sea 1 el proceso de intercambio termina, pero si es cero, termina definitivamente
    {
        for (i = salto; i < n; i++) //Iteramos
        {
            //Impresion(Arreglo,n); //Muestra la impresion por cada iteración de cambio
           j = i -salto; //Mueve una posición adelante cuando i aumenta
           while (j>=0)
           {
               k = j + salto; // Hace el salto de posición
               if (Arreglo[j]<=Arreglo[k]) //Evaluación el valor de las posición
               {    
                   j = -1; //Baja una posición para salir del while j>=0
               }
               else{
                   Intercambio(Arreglo[j],Arreglo[k]); //De lo contrario se hace un intercambio
                   j -= salto; //Aqui mantenemos los saltos hasta que Arreglo[j]<=Arreglo[k] en todo el arreglo
               }
           }  
             //Impresion(Arreglo,n); 
        }
        salto = salto/2; // Una vez iterados los saltos, vuelve a dividir y se hace menos saltos hasta llegar a 1
    }
    cout<<endl;
}

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
    OrdenamientoShell(Arreglo,cantidad);
    Impresion(Arreglo,cantidad);
    cout<<endl<<endl;
    system("pause");
    return 0;
}
