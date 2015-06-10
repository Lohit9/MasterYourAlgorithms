#include <assert.h>
// note that the questions requires us to input a pointer a the parameter not just  a date struct 
bool is_valid(const struct date *e) {
    struct date d =*e; 
    if ((d.year/4)%2==0)
   {
        if( (d.month==4)||(d.month==6)||(d.month==9)||
        (d.month==11))
        {
            return ((0<d.day)&&
            (d.day<=30));
        }
        else if (d.month==2)
        {
            return ((0<d.day)&&
            (d.day<=29));
        }
        else 
        {
            return ((0<d.day)&&
            (d.day<=31));
        }
  }
   else
        {
        if( (d.month==4)||
        (d.month==6)||
        (d.month==9)||
        (d.month==10))
        {
            return ((0<d.day)&&(d.day<=30));
        }
        else if (d.month==2)
            {
            return ((0<d.day)&&
            (d.day<=28));
            }
        else 
        {
        return ((0<d.day)&&(d.day<=31));
        }
    }
}

// see header file
bool d_eq(const struct date *e1, const struct date *e2) {
   struct date d1 =*e1;
    struct date d2 =*e1; 
    return ((d1.day==d2.day)&&(d1.month==d2.month)&&
    (d1.year==d2.year));
}

// see header file
bool greaterthan(const struct date *e1, const struct date *e2) {
     struct date d1 =*e1;
    struct date d2 =*e2; 
    if ((d1.year==d2.year)&&(d1.month==d2.month))
    {
        return (d1.day>d2.day);

    }
    else if (d1.year==d2.year)
    {
       return(d1.month>d2.month);
    }
    else 
    {
       return (d1.year>d2.year);
    }

}

// see header file
void tomorrow(struct date *e) {
    struct date d =*e;
    if (d.month%2!=0 && d.month<=7)
    {
        if (d.day==31)
        {
            d.day=1;
            d.month=d.month+1;
        }
    }
    else if (d.month%2==0 && 8<=d.month<=12)
    {
        if (d.day==31)
        {
            d.day=1;
            d.month=d.month+1;
        }
    }
    else if (d.month%2==0 && 4<=d.month<=6)
    {
        if (d.day==30)
        {
            d.day=1;
            d.month=1;
        }
    }
    else if (d.month%2!=0 && 9<=d.month<=11)
    {
        if (d.day==30)
        {
            d.day=1;
            d.month=d.month+1;
        }
    }
    else if (d.month==2 && d.year%4==0)
    {
        if (d.day==29)
        {
            d.day=1;
            d.month=d.month+1;
        }
    }
    else if (d.month==2 && d.year%4!=0)
    {
        if (d.day==28)
        {
            d.day=1;
            d.month=d.month+1;
        }
    }
    else if (d.month==12 && d.day==31)
    {
        d.day=1;
        d.month=1;
        d.year=d.year+1;
    }
    else
    {
        d.day=d.day+1;

    }

}


// see header file
void yesterday(struct date *d) {

}

/*int main()
{
    const struct date date1 = {12,33,2013};
const struct date date2 = {12,23,2013};
const struct date date3 = {2,10,2010};
const struct date date4 = {12,23,2013};
const struct date date5 = {2,29,2100};

assert(is_valid(date1)==false);
assert(d_eq(date4 ,date2)== true); 
assert(is_valid(date5)==false);
assert(greaterthan(date2,date3)== true);

}*/

