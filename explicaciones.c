if (A && B) AND
if (A || B) OR

Comparadores
1 1 = 1 AND (&&)  
1 0 = 0
0 1 = 0
0 0 = 0

1 1 = 1 OR (||)
1 0 = 1
0 1 = 1
0 0 = 0


Operaciones binarias
n1 1111101    AND (&)
n2 0010101 
   _______
n3 0010101		 
		
n1 1111101    OR (|)
n2 0010101
   ________
n3 1111101


	Comparamos con 1

 c = 01000101
 1 = 00000001
_____________
     00000001
	
	Desplazamos el bit 1 posición
 c = 01000100
 1 = 00000010
 ____________
     00000000
