#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b[512][512];                
int main()
{
       FILE *p;
       int a[3][3];
       int i,j,k,l,s,z=0;
       
       
	   for(i=0;i<3;i++)
	    {
	     for(j=0;j<3;j++)
		  { 
		    a[i][j]=1;
		   
		    
		  }
		  
		  
	    } 
		      
       p=fopen("square.txt","r");
       for(i=0;i<512;i++)
       {
          for(j=0;j<512;j++)
             {
                 fscanf(p,"%d ",&b[i][j]);
                 
             }
       }
       fclose(p);
      
      for(i=0;i<510;i++)
      {
      	for(j=0;j<510;j++)
      	 {
      	 	s=0;
      	  for(k=0;k<3;k++)
      	   {
      	    for(l=0;l<3;l++)
      	     {
      	     	s+=a[k][l]*b[i+k][j+l];
      	     	while(z++<9)
				   printf("%d ",b[i+k][j+l]);
      	     }
      	   }
      	   b[i+1][j+1]=s/9;
      	   
      	}
      }
       
       p=fopen("square(HPF).pgm","w");
      fprintf(p,"P2\n # Created by Soumyadeep\n 512 512\n 255\n");
       for(i=0;i<512;i++)
       {
          for(j=0;j<512;j++)
             {     
              	
                    fprintf(p,"%d ",b[i][j]);
               
             }
            
       }
       fclose(p);
      return 0;
}
                    
       
       
             
