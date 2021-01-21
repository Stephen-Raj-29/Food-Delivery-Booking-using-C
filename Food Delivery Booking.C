#include<stdio.h>
#include<stdlib.h>
struct Details
{
    int Customer_ID;
    int order;
    char Restaurant;
    char Destination;
    int Hr,mins,D_Hr,D_mins;
    char am[2];
    int chargers;
};
struct Details d;
struct Details book[100];
char ch;
int booking_id=0;
int head=0;


void booking()
{
    int booked_id;
    booking_id++;
    if(booking_id==1)
    {
        book[0]=d;
        book[0].chargers= 50;
        book[0].order+=1;
        d.mins+=30;
        if(d.mins>=60)
        {
            d.Hr++;
            book[0].D_Hr = d.Hr%12;
            book[0].D_mins =d.mins%60;
        }
        else
        {
            book[0].D_Hr = d.Hr;
            book[0].D_mins =d.mins;
        }
        booked_id=1;
        head++;
    }
    else
    {
        int flag=0;
        for(int i=0;i<head;i++)
        {
            if((book[i].Restaurant==d.Restaurant)&&(book[i].Destination==d.Destination))
            {
                if(d.am[0]!=book[i].am[0])
                {
                    d.Hr=d.Hr+12;
                    if((abs(d.Hr-book[i].Hr)%12 ==1) && ((60-book[i].mins)+d.mins < 15))
                    {
                        book[i].chargers+= 5;
                        book[i].order+=1;
                        booked_id=i+1;
                        d.mins+=30;
                        if(d.mins>=60)
                        {
                            d.Hr++;
                            book[i].D_Hr = d.Hr%12;
                            book[i].D_mins =d.mins%60;
                        }
                        else
                        {
                            book[i].D_Hr = d.Hr;
                            book[i].D_mins =d.mins;
                        }
                        flag=1;

                    }
                }
                else if(d.mins-book[i].mins < 15 && d.Hr-book[i].Hr==0)
                {
                        book[i].chargers+= 5;
                        book[i].order+=1;
                        booked_id=i+1;
                        d.mins+=30;
                        if(d.mins>=60)
                        {
                            d.Hr++;
                            book[i].D_Hr = d.Hr%12;
                            book[i].D_mins =d.mins%60;
                        }
                        else
                        {
                            book[i].D_Hr = d.Hr;
                            book[i].D_mins =d.mins;
                        }
                        flag=1;
                }
            }
        }
        if(flag==0)
        {
            book[head]=d;
            book[head].chargers= 50;
            book[head].order+=1;
            d.mins+=30;
            if(d.mins>=60)
            {
                d.Hr++;
                book[head].D_Hr = d.Hr%12;
                book[head].D_mins =d.mins%60;
            }
            else
            {
                book[head].D_Hr = d.Hr;
                book[head].D_mins =d.mins;
            }
            booked_id=head+1;
            head++;
        }
    }
    printf("\n--------------------------------------\n");
    printf("Booking ID : %d\n",booking_id);
    printf("\tAvailable Executives \n");
    printf("Executive     Delivery Charge Earned\n");
    int limit=head;
    if(limit<5)
        limit=5;
    for(int i=0;i<limit;i++)
        printf("   DE%d  \t\t%d\n",i+1,book[i].chargers);

    printf("Allotted Delivery Executive: DE%d",booked_id);
    printf("\n--------------------------------------\n\n");

}

void Display()
{
    printf("\nTRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT   ORDERS   PICK-UP_TIME   DELIVERY_TIME   DELIVERY CHARGE\n");
    for(int i=0;i<head;i++,printf("\n"))
    {
        printf(" %d\tDE%d   \t    %c   \t   %c     \t    %d  \t\t%d:%02d      \t%d:%02d   \t  %d",i+1,i+1,book[i].Restaurant,book[i].Destination,book[i].order,book[i].Hr,book[i].mins,book[i].D_Hr,book[i].D_mins,book[i].chargers);
    }
    printf("\n\nTotal earned\n");
    printf("Executive  Allowance  Deliver_Charges  Total\n");
    for(int i=0;i<head;i++,printf("\n"))
    {
        printf("   DE%d\t\t10\t%d\t\t%d",i+1,book[i].chargers,book[i].chargers+10);
    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n\n");
}


int main()
{
    int select;

    do
    {
    printf("\t\t\t\t----*Food Delivery Booking System*----\n\n\t\t1.Book Food\n\t\t2.Food Delivery details\n\t\t3.Exit\n\nEnter the choice : ");
    scanf("%d",&select);
    switch(select)
    {
    case 1:
        printf("\n\tEnter the Booking Details\n");
        printf("Customer ID : ");
        scanf("%d",&d.Customer_ID);
        printf("Restaurant : ");
        scanf("%c",&ch);
        scanf("%c",&d.Restaurant);
        printf("Destination : ");
        scanf("%c",&ch);
        scanf("%c",&d.Destination);
        printf("Time : ");
        scanf("%d:%d%c%s",&d.Hr,&d.mins,&ch,&d.am);
        booking();
        break;
    case 2:
        Display();
        break;
    case 3:
        return 0;
        break;
    default:
        printf("\nInvalid choice\n");
    }
    }while(1);
    return 0;
}
