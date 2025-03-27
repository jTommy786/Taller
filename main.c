
#include <stdio.h>

int main() {
    int stock =-1, cantidad, opcion, val;
    float precio, ganancias;
    char nombre[30];
    char id[30];

  
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Ingresar el producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            
            case 1: 
                
                do{
                    
                printf("Ingrese el ID del producto: ");
                fflush(stdin);
                val=scanf("%s", &id);
                if(val != 1){
                    printf("error ingrese unicamente numeros\n");
                }
                }while(val != 1);

                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                int val;
                do{
                    printf("Ingrese la cantidad inicial en stock: ");
                    fflush(stdin);
                    val = scanf("%d", &stock); 
                    if(val != 1){
                        printf("El valor es incorrecto, ingreselo de nuevo\n");
                    }
                }while(val != 1);

                do{
                    printf("\nIngrese el precio unitario del producto: \n");
                    fflush(stdin);
                    val=scanf("%f", &precio);
                }while(val != 1);
                
                break; 
            
                

            case 2:

                if(stock<0){
                    printf("No hay stock disponible para vender\n");
                    break;
                }
                do{
                printf("\nIngrese la cantidad a vender: ");
                fflush(stdin);
                val=scanf("%d", &cantidad);
                if(val != 1){
                    printf("\nError ingrese unicamente enteros positivos\n");
                }
                if(cantidad>stock){
                    printf("Error no hay stock suficiente\n");
                }
                stock-=cantidad;
                ganancias+= cantidad*precio;
                }while(val != 1 || cantidad>stock);
                if(cantidad>10){
                    ganancias+=(cantidad*precio)*0.2;
                    printf("\nSe ha aplicado un descuento del 20 porciento\n");
                }else{
                    ganancias+=(cantidad*precio);
                }
            
                break;

            case 3:
            if(stock<0){
                printf("No hay stock disponible para vender\n");
                break;
            }
                do{
                printf("Ingrese la cantidad a agregar al stock: ");
                fflush(stdin);
                val=scanf("%d", &cantidad);
                }while(val != 1);
                stock+=cantidad;
                
                break;

            case 4:
            if(stock<0){
                printf("No hay stock disponible para vender\n");
                break;
            }
                printf("\nInformacion del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
            if(stock<0){
                printf("No hay stock disponible para vender\n");
                break;
            }
                printf("Total de ganancias: $%.2f\n", ganancias);
                break;
            

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invlida. Intente nuevamente.\n");
        }
    } while (opcion != 6 || stock<0);

    return 0;
}
