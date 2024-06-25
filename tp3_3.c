#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    int PrecioUnitario; // entre 10- 100
 } Producto;

  typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
 } Cliente;

 int main() {
 srand(time(NULL));
 char *Buff; //variable auxiliar
 char *Buff2;
 char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
 int cantClientes;
 printf("Ingrese la cantidad de clientes: ");
 scanf("%d", &cantClientes);
 Cliente * clientes = (Cliente *)malloc(sizeof(Cliente)*cantClientes);
 for (int i=0;i<cantClientes;i++) {
   clientes[i].ClienteID = i+1;
   Buff = (char *)malloc(sizeof(char)*100);
   Buff2 = (char *)malloc(sizeof(char)*100);
   int cantNombres;
   printf("Ingrese la cantidad de nombres del cliente número %d: ", i+1);
   scanf("%d", &cantNombres);
   for (int c=0;c<cantNombres;c++) {   
      printf("Ingrese el nombre número %d: ", c+1);
      if (c==0) {
         fflush(stdin);
         gets(Buff);
      } else {
         gets(Buff2);
         strcat(Buff," ");
         strcat(Buff,Buff2);
      }
   }
   char * nombreCliente = (char *)malloc(sizeof(char)*(strlen(Buff)+1));
   strcpy(nombreCliente,Buff);
   clientes[i].NombreCliente = nombreCliente;
   clientes[i].CantidadProductosAPedir = 1+rand()%5;
   Producto * productos = (Producto *)malloc(sizeof(Producto)*(clientes[i].CantidadProductosAPedir));
   for (int j=0;j<clientes[i].CantidadProductosAPedir;j++) {
      productos[j].ProductoID = j+1;
      productos[j].Cantidad = 1+rand()%10;
      productos[j].TipoProducto = TiposProductos[rand()%5];
      productos[j].PrecioUnitario = 10 + rand()%91;
   }
   clientes[i].Productos = productos;
}
 free(Buff);
 for (int i=0;i<cantClientes;i++) {
   printf("\nCliente número %d\n",i+1);
   printf("ID: %d\n",clientes[i].ClienteID);
   printf("Nombre: %s\n",clientes[i].NombreCliente);
   printf("Cantidad de productos a pedir: %d\n",clientes[i].CantidadProductosAPedir);
   int costoTotal = 0;
   for (int j=0;j<clientes[i].CantidadProductosAPedir;j++) {
      printf("Producto %d:\n",j+1);
      printf("ID: %d\n", clientes[i].Productos[j].ProductoID);
      printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
      printf("Tipo: %s\n", clientes[i].Productos[j].TipoProducto);
      printf("Precio: %d\n", clientes[i].Productos[j].PrecioUnitario);
      costoTotal += costoTotalProd(clientes[i].Productos[j]);
   }
   printf("Total a pagar: %d\n", costoTotal);
 }
 free(clientes);
 return 0;
}

 int costoTotalProd(Producto prod) {
   int costoTotal = prod.Cantidad*prod.PrecioUnitario;
   return costoTotal;
 }