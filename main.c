#include <stdio.h>
#include <string.h>

int main() {
    int stock = -1, cantidad, opcion, val;
    float precio = 0, ganancias = 0;
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
        
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no válida. Por favor, ingrese un número.\n");
            while (getchar() != '\n'); // Limpia el buffer
            continue;
        }

        switch (opcion) {
            case 1:
                do {
                    printf("Ingrese el ID del producto (solo caracteres alfanuméricos): ");
                    scanf("%s", id);
                    if (strspn(id, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != strlen(id)) {
                        printf("Error: El ID solo debe contener caracteres alfanuméricos.\n");
                    } else {
                        break;
                    }
                } while (1);

                printf("Ingrese el nombre del producto: ");
                while (getchar() != '\n'); // Limpia el buffer
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de línea

                do {
                    printf("Ingrese la cantidad inicial en stock (entero positivo): ");
                    if (scanf("%d", &stock) != 1 || stock < 0) {
                        printf("Entrada no válida. Intente nuevamente.\n");
                        while (getchar() != '\n'); // Limpia el buffer
                        continue;
                    } else {
                        break;
                    }
                } while (1);

                do {
                    printf("Ingrese el precio unitario del producto: ");
                    if (scanf("%f", &precio) != 1 || precio <= 0) {
                        printf("Entrada no válida. Intente nuevamente.\n");
                        while (getchar() != '\n'); // Limpia el buffer
                        continue;
                    } else {
                        break;
                    }
                } while (1);

                break;

            case 2:
                if (stock <= 0) {
                    printf("No hay stock disponible para vender\n");
                    break;
                }

                do {
                    printf("Ingrese la cantidad a vender: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0 || cantidad > stock) {
                        printf("Error: Cantidad no válida o no hay suficiente stock.\n");
                        while (getchar() != '\n'); // Limpia el buffer
                        continue;
                    } else {
                        break;
                    }
                } while (1);

                stock -= cantidad;
                ganancias += cantidad * precio;

                if (cantidad > 10) {
                    ganancias -= cantidad * precio * 0.2; // Descuento del 20%
                    printf("Se ha aplicado un descuento del 20 porciento\n");
                }

                break;

            case 3:
            if (stock <= 0) {
                    printf("No hay stock disponible para abastecer\n");
                    break;
                }
                do {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad < 0) {
                        printf("Entrada no válida. Intente nuevamente.\n");
                        while (getchar() != '\n'); // Limpia el buffer
                        continue;
                    } else {
                        break;
                    }
                } while (1);

                stock += cantidad;

                break;

            case 4:
            if (stock <= 0) {
                    printf("No hay stock disponible para mostrar\n");
                    break;
                }
                printf("\nInformacion del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s\n", nombre);
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
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
