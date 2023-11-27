#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
class Sorts {
public:
    void ordenaSeleccion(std::vector<T> &v);
    void ordenaBurbuja(std::vector<T> &v);
    void ordenaMerge(std::vector<T> &v);
    int busqSecuencial(const std::vector<T> &v, const T &target);
    int busqBinaria(const std::vector<T> &v, const T &target);
};



template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) {
    //n es el numero de datos del vector
    // i es la encargada de recorrer todos los datos del array
    // j es el siguiente numero de i
    // min es el valor minimo el cual sera organizado
    
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            //Voltea los valores
            std::swap(v[i], v[min]);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) {
    for(int i = v.size()-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j + 1]){
                std::swap(v[j], v[j + 1]);
            }
        }
    }
    
}

template <class T>
void merge(std::vector<T> &v, int left, int middle, int right){
    //Definimos las 2 mitades del array
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //Creamos dos vectores para la colocar las mitades correspondientes
    std::vector<T> leftArray(n1);
    std::vector<T> rightArray(n2);

    //Copiamos la parte izquierda del array en leftArray
    for (int i = 0; i < n1; i++) {
        leftArray[i] = v[left + i];
    }

    //Copiamos la parte derecha del array en rightArray
    for (int j = 0; j < n2; j++) {
        rightArray[j] = v[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;  //K es el primer indice del subarreglo izquierdo

    //
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            v[k] = leftArray[i]; //copiamos el elemento del leftArray en el subarreglo v
            i++; //Avaza al siguiente elemento del LeftArray
        } else {
            v[k] = rightArray[j]; //copiamos el elemento del rightArray en el subarreglo v
            j++; // Avanza al siguiente elemento en rightArray.
        }
        k++; //Avanza al siguiente elemeno del subarreglo v
    }
    //Copiamos los elementos restantes del leftArray
    while (i < n1) {
        v[k] = leftArray[i]; //Copiamos el elemento del leftArray en el subarreglo v
        i++; //Avanzo en leftArray
        k++; //Avanzo en el subarreglo v
    }

    //Copiamos los elementos restantes del rightArray
    while (j < n2) {
        v[k] = rightArray[j];
        j++;
        k++;
    }
}

template <class T>
void mergeSort(std::vector<T> &v, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        //Llamaos recursivamente la parte izquierda y derecha
        mergeSort(v, left, middle);
        mergeSort(v, middle + 1, right);
        
        //Fusionamos las 2 mitades ordenadas
        merge(v, left, middle, right);
    }
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &v) {
    int size = v.size(); //Obtiene el tamaño del vector

    //Si el tamaño del vector original es menor a 2 significa que ya esta ordenado
    if (size < 2) {
        return; 
    }
    //Si no esta ordenado entonces los ordenamos con el mergeSort
    mergeSort(v, 0, size - 1);
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &v, const T &target){
    //Recorremos todo el array
    for (int i = 0; i < v.size(); i++){
        //Por cada elemento del array comprobamos si es el objetivo
        if (v[i] == target){
            //Si lo es regresamos el valor del indice
            return i;
        }
    }
    //Si no se encuentra regresamos que no se encontro el valor
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &v, const T &target) {
    int left = 0;                // Índice izquierdo del rango de búsqueda.
    int right = v.size() - 1;    // Índice derecho del rango de búsqueda.

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calcula el índice medio del rango.

        if (v[mid] == target) {
            return mid;  // Se encontró el objetivo, retorna su índice.
        } else if (v[mid] < target) {
            left = mid + 1; // El objetivo está en la mitad derecha del rango.
        } else {
            right = mid - 1; // El objetivo está en la mitad izquierda del rango.
        }
    }

    return -1; // El objetivo no se encontró en el vector, retorna -1.
}


#endif // SORTS_H
