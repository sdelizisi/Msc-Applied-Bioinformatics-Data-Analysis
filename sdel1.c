#include <stdio.h>
#include <string.h>

int main  ()

{

   char seq[5000];
   int len, i, k;
   int InternalStop;
   int firstcodon, lastcodon;


   while(printf("Enter a nucleotide sequence: "), scanf("%s", seq)==1)
   {

   InternalStop=0;
   firstcodon=0;
   lastcodon=0;

   len=strlen(seq);

   for (i=0; i<=len-3; i++)
   {
   if (seq[i]=='A' && seq[i+1]=='T' && seq[i+2]=='G')
      
     if(firstcodon == 0)

	  {
	   firstcodon=1;
  
           for( k=i+3; k<=len-3; k+=3)
	     
              {
	          char a=seq[k];
	          char b=seq[k+1];
	          char c=seq[k+2];


                  if ( ( a=='T' && b=='A' && c=='A' )  ||
                       ( a=='T' && b=='A' && c=='G' )  ||
                       ( a=='T' && b=='G' && c=='A' ) )
	                
                           	{
                                   if (lastcodon==1)
                                      {
                                         InternalStop=1;
                                      }
                                lastcodon=1;
		                    }
              }
      }    
   }

   
 
   if (firstcodon == 1)
        {
           printf("Start codon found. \n");
        }  
   else
        {
           printf("No start codon. \n");
        }

   if (lastcodon==1)
        {
           printf("Stop codon found. \n");
        }
   else
        {
           printf("No stop codon found. \n");
        }

   if (InternalStop==1)
	{
	   printf("Internal stop codon found. \n");
	}
   else
	{
	   printf("No internal stop codons. \n");
	}
   

   if (firstcodon==1 && lastcodon==1 && InternalStop==0)
        {
           printf("Valid prokaryotic coding sequence. \n");
        }
   else
        {
           printf("Not valid prokaryotic coding sequence. \n");
        }



   }


}










