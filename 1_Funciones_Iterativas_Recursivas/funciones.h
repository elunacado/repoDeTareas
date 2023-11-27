
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

class Funciones{
        public:
        unsigned int sumaIterativa(int n) {
            unsigned long acum = 0;
            for(int i = 1; i <= n; i++){
                acum += i   ;
            }
            return acum;
        }

        unsigned long sumaRecursiva(int n) {
            if(n<=0){
                return 0;
            }else{
                return n + sumaRecursiva(n - 1);
            }
        };

        unsigned long sumaDirecta(int n) {
            int result = (n*(n+1)/2);
            return result;
        };

};
    #endif /* FUNCTIONS_H_ */
