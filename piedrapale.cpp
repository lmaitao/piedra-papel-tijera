# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>


typedef struct {
int ganados;
int perdidos;
int empatados;
} Estadistica;



 int random_number(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

      
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }


int main (void)
{
int jug, maq, op, r, rondas;
char nombre1[20];
char nombre2[20];
char jugada[20];
char jugada2[20];
int contador =0;
Estadistica resultados[2];
char op3;

do
{


printf("Hola, jugaremos pidra, papel o tijera\n");

printf("Introduzca nombre jugador 1 : ");
scanf("%s", nombre1);

resultados[0].perdidos = 0;
resultados[0].ganados = 0;
resultados[0].empatados = 0;


printf("Introduzca nombre jugador 2 : ");
scanf("%s", nombre2);
resultados[1].perdidos = 0;
resultados[1].ganados = 0;
resultados[1].empatados = 0;


printf("Introduzca numero de rondas a jugar  : ");
scanf("%d", &rondas);




do{

contador ++;

printf("Ronda del Juego # %d \n", contador);

printf("Introduzca seleccion jugador 1(%s) = ", nombre1);
scanf("%s", jugada);

if (strcmp(strlwr(jugada), "piedra") ==0) { jug = 0;}
else if (strcmp(strlwr(jugada), "papel") ==0) { jug = 1;}
else if (strcmp(strlwr(jugada), "tijeras") ==0) { jug = 2;}


printf("Introduzca seleccion jugador 2(%s) =  ", nombre2);
scanf("%s", jugada2);

if (strcmp(strlwr(jugada2), "piedra") ==0) { r = 0;}
else if (strcmp(strlwr(jugada2), "papel") ==0) { r = 1;}
else if (strcmp(strlwr(jugada2), "tijeras") ==0) { r = 2;}



switch (jug)
{
case 0:
printf("%s  eligio Piedra\n", nombre1);
    if (r==0)
    {
     	printf("\t %s eligio Piedra\n\n", nombre2);
        printf("\t\t\tEmpate en la ronda \n\n\n");
        
        resultados[0].empatados += 1;
        resultados[1].empatados += 1;

    }
 else
    {
     if (r==1)
     {
       	printf("\t %s eligio Papel\n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre2);
        
        resultados[1].ganados += 1;
        resultados[0].perdidos += 1;

     }
     else
    {
     if (r==2)
     {
     	printf("\t %s eligio Tijeras \n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre1);
            resultados[0].ganados += 1;
        resultados[1].perdidos += 1;
	
	 }

    }
  }
break;
case 1:
printf("%s  eligio Papel \n", nombre1);	
        if (r==0)
        {

     	printf("\t %s eligio Piedra \n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre1);

        resultados[0].ganados += 1;
        resultados[1].perdidos += 1;

        }
        else
        {
            if (r==1)
            {

         	printf("\t %s eligio Papel\n\n", nombre2);
            printf("\t\t\tEmpate en la ronda \n\n\n");
        resultados[0].empatados += 1;
        resultados[1].empatados += 1;

            }
            else
            {
                if (r==2)
                {

     	printf("\t %s eligio Tijeras \n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre2);
        resultados[1].ganados += 1;
        resultados[0].perdidos += 1;

                }
            }
        }
break;
case 2 :
printf("%s  eligio Tijeras \n", nombre1);	
	
          if (r==0)
          {
     	printf("\t %s eligio Piedra \n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre2);
                resultados[1].ganados += 1;
                resultados[0].perdidos += 1;
          }
          else
          {
              if (r==1)
              {
       	printf("\t %s eligio Papel \n\n", nombre2);
        printf("\t\t\t %s Gana la ronda \n\n\n", nombre1);
                resultados[0].ganados += 1;
        resultados[1].perdidos += 1;
              }
              else
              {
                  if (r==2)
                  {
       	printf("\t %s eligio Tijeras\n\n", nombre2);
            printf("\t\t\tEmpate en la ronda \n\n\n");

        resultados[0].empatados += 1;
        resultados[1].empatados += 1;

                  }
              }
          }
          break;
default:
    printf("Por favor solo introduce los numeros que aparecen en el menu");
}

if (contador < rondas ) {
printf("Quieres jugar la siguiente ronda?\n");
printf("Si deseas continuar  jugando presiona 1\n");
printf("Si deseas salir del juego presiona 2\n");
scanf("%d", &op);
system("cls");


}




if (contador == rondas ) break;


}
while( (op != 2));


printf("Resultados \n");
printf("jugador %s - ganados = %d  - perdidos =  %d  - empatados = %d\n", nombre1, resultados[0].ganados, resultados[0].perdidos, resultados[0].empatados); 
printf("jugador %s - ganados = %d  - perdidos =  %d  - empatados = %d\n", nombre2, resultados[1].ganados, resultados[1].perdidos, resultados[1].empatados); 


printf("Ok, hasta luego, regresa pronto");
getch();

printf("\n Desea Jugar Nuevamente ? (S/N) \n");

op3 = getch();

} while(op3 != 'n');






}
