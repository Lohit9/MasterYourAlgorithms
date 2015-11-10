
// resize_array changes the length of the array from oldlen to the newlen 

int *resize_array(int *old, int oldlen, int newlen) 
{
    int *new = malloc(sizeof(int)*newlen);

    if (oldlen > newlen) return old;

    for(int i=0; i<oldlen ; i++)
    {
    	new[i] = old[i];
    }
    free(old);
    return new ;
}


// instead of this we can use the realloc(array,new size)


// AMORTIZED ANALYSIS

struct dyn_array {
  int *data;
  int len;
  int max;
};

void append_number(struct dyn_array *da, int i) 
{
   if (da->len == da->max)
   {
	    if (da->len ==0) 
	    {
	    	da->data = malloc(sizeof(int));
	    	da->len =1;
	    	da->max =1;
	    }

	    else 
	    {
	    	int newlen =  2 * da->len;
	    	da->data =  realloc(sizeof(int)* newlen);
	    	
	    }
	}

	da->data[len] =i;
	da->len ++;
}

//Dynamic Array initialization an d destruction

struct dyn_ar 
{
	int len;
	int max;
	int *data;

};

struct dyn_ar create_ar (int len)
{

	if (len = 0)
	{
		da->len = 0;
		da->max = 0;
		da->data= NULL;

	}
	 else
	 {
	 	int new = malloc(sizeof(int) * len );
	 	da->data = new;
	 	da->len = len 
	 	da->max =len;

	 }

	 return da->data;

}

 void destroy_dyn_array(struct dyn_array *da) 
 {
 	if (da->max > 0) free(da->data);
 	free(da);
 }


/-------the end------------/


