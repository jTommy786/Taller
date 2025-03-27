
#include <stdio.h>

int main() {
    int id, stock, cantidad, opcion, val;
    float precio, ganancias;
    char nombre[30];

  
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
                val=scanf("%d", &id);
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
                    printf("Ingrese el precio unitario del producto: ");
                    fflush(stdin);
                    val=scanf("%f", &precio);
                }while(val != 1);
                
                break; 
            
        
            case 2:
                do{
                printf("Ingrese la cantidad a vender: ");
                fflush(stdin);
                val=scanf("%d", &cantidad);
                if(val != 1){
                    printf("Error ingrese unicamente enteros positivos");
                }
                stock-=cantidad;
                ganancias+= cantidad*precio;
                }while(val != 1);
                if(cantidad>10){
                    ganancias+=(cantidad*precio)*0.2;
                }else{
                    ganancias+=(cantidad*precio);
                }
                break;

            case 3:
                do{
                printf("Ingrese la cantidad a agregar al stock: ");
                fflush(stdin);
                val=scanf("%d", &cantidad);
                }while(val != -1);
                
                break;

            case 4:
                printf("\nInformacion del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
                printf("Total de ganancias: $%.2f\n", ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invlida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
