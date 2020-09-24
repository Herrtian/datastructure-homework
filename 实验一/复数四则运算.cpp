#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct con
{
	float rea;
	float vir;
}Con;

Con add (Con &c1, Con &c2)
{
	Con c3 ;
	c3.rea = c1.rea + c2.rea;
	c3.vir = c1.vir +c2.vir;
	
	return c3;
}
Con minus (Con &c1, Con &c2)
{
	Con c3 ;
	c3.rea = c1.rea - c2.rea;
	c3.vir = c1.vir -c2.vir;
	
	return c3;
}
Con dot (Con &c1, Con &c2)
{
	Con c3 ;
	c3.rea = c1.rea * c2.rea - c1.vir * c2.vir;
	c3.vir = c1.rea * c2.vir  + c1.vir * c2.rea  ;
	
	return c3;
}
Con div (Con &c1, Con &c2)
{
	Con c3 ;
	float s = c2.rea * c2.rea +c2.vir * c2.vir;
	
	c3.rea = c1.rea * c2.rea + c1.vir * c2.vir;
	c3.vir = c2.rea * c1.vir - c1.rea * c2.vir;
	
	c3.rea = c3.rea / (1.0 * s) ;
	c3.vir = c3.vir / (1.0 * s) ;
	
	return c3;
}





int main()
{
	Con c1 ,c2 ,c3;
	scanf("%f %f %f %f",&c1.rea,&c1.vir,&c2.rea,&c2.vir);
	c3 = add(c1,c2);
	
	if(fabs(c3.rea) < 0.1 && fabs(c3.vir) >= 0.1)
	{
		printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.vir);
	}
	else if (fabs(c3.vir) < 0.1 && fabs(c3.rea) >= 0.1 )
	{
		printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else if(fabs(c3.rea) < 0.1 && fabs(c3.vir) < 0.1)
	{
		printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else
	{
		if(c3.vir>0)
		{
			printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1f+%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		else{
			printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1f%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);

		}
		

	}
	c3 = minus(c1,c2);
	
	if(fabs(c3.rea) < 0.1 && fabs(c3.vir) >= 0.1)
	{
		printf("(%.1f+%.1fi) - (%.1f+%.1fi) = %.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.vir);
	}
	else if (fabs(c3.vir) < 0.1 && fabs(c3.rea) >= 0.1 )
	{
		printf("(%.1f+%.1fi) - (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else if(fabs(c3.rea) < 0.1 && fabs(c3.vir) < 0.1)
	{
		printf("(%.1f+%.1fi) - (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else
	{
		if(c3.vir > 0)
		{
			printf("(%.1f+%.1fi) - (%.1f+%.1fi) = %.1f+%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		else
		{
			printf("(%.1f+%.1fi) - (%.1f+%.1fi) = %.1f%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		
				
	}
	
	c3 = dot(c1,c2);
	if(fabs(c3.rea) < 0.1 && fabs(c3.vir) >= 0.1)
	{
		printf("(%.1f+%.1fi) * (%.1f+%.1fi) = %.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.vir);
	}
	else if (fabs(c3.vir) < 0.1 && fabs(c3.rea) >= 0.1 )
	{
		printf("(%.1f+%.1fi) * (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else if(fabs(c3.rea) < 0.1 && fabs(c3.vir) < 0.1)
	{
		printf("(%.1f+%.1fi) * (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else
	{
		
		if(c3.vir > 0)
		{
			printf("(%.1f+%.1fi) * (%.1f+%.1fi) = %.1f+%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		else
		{
			printf("(%.1f+%.1fi) * (%.1f+%.1fi) = %.1f%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		
		
	}
	c3 = div(c1,c2);
	if(fabs(c3.rea) < 0.1 && fabs(c3.vir) >= 0.1)
	{
		printf("(%.1f+%.1fi) / (%.1f+%.1fi) = %.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.vir);
	}
	else if (fabs(c3.vir) < 0.1 && fabs(c3.rea) >= 0.1 )
	{
		printf("(%.1f+%.1fi) / (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else if(fabs(c3.rea) < 0.1 && fabs(c3.vir) < 0.1)
	{
		printf("(%.1f+%.1fi) / (%.1f+%.1fi) = %.1f\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea);
	}
	else
	{
		if(c3.vir > 0)
		{
			printf("(%.1f+%.1fi) / (%.1f+%.1fi) = %.1f+%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		else
		{
			printf("(%.1f+%.1fi) / (%.1f+%.1fi) = %.1f%.1fi\n",c1.rea ,c1.vir,c2.rea,c2.vir,c3.rea,c3.vir);
		}
		
		
	}	
	
	return 0;
}


