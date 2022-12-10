#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct store{
	char product_name[50] ;
	int product_price ;
	int status;
	struct store* prev ;
	struct store* next ;
};



struct shopping_cart{
	char product_name[50];
	int product_price;
	struct shopping_cart* next ;
};

void print_shopping_cart(struct shopping_cart *head){
    
    if(head == NULL){
        printf(" shopping cart is empty\n"); 
        printf("\n===========================================================\n\n");
    }else{
        struct shopping_cart *ptr = head;
        while( ptr != NULL){
            printf("%s      %d",ptr->product_name,ptr->product_price);
           
        }
    }

}

struct shopping_cart* add_at_the_empty (struct store* head){
    
    
    struct shopping_cart* newcart = (struct shopping_cart*) malloc(sizeof(struct shopping_cart));
    struct store* newp = head;
    newcart->product_price = newp->product_price;
 //   newcart->product_name = newp->product_name;  
    strcpy(newcart->product_name , newp->product_name);
    newcart->next = NULL;
    return newcart;

} 



// Add any functon you want

void print_list(struct store* tail , struct shopping_cart* newcart){
       
       struct store* head = tail->next;

        printf("product name: %s\n",head->product_name);
        printf("product price: %d\n",head->product_price);
        if(head->status == 1){

                printf("product status: Available\n\n");
               }else{

                printf("product status: Out of Stock\n\n");
               }
        
        int option;
        do{
            printf("1- Prev            2- Buy          3- Next           4- Exit Store    \n\n");
            printf("\nEnter option: ");
            scanf("%d",&option);
            printf("\n\n======================================\n\n");
            


        switch(option){

           case 1:
                   head = head->prev;
                   printf("product name: %s\n",head->product_name);
                   printf("product price: %d\n",head->product_price);
                   if(head->status == 1){

                    printf("product status: Available\n\n");
                   }else{

                    printf("product status: Out of Stock\n\n");
                   }

                   break;
           case 2:
           
                  
                //  if(newcart == NULL){
                    // newcart = add_at_the_empty(head); 
                  //  printf("OOOOOOOOOOOOOOOOOK");
                  //  print_shopping_cart(newcart);
                //  }else{
                     /// add_at_the_end(head);
                //  }
                

               break;

           case 3:

                head = head->next;
                printf("product name: %s\n",head->product_name);
                printf("product price: %d\n",head->product_price);
              if(head->status == 1){

                printf("product status: Available\n\n");
               }else{

                printf("product status: Out of Stock\n\n");
               }
                break;


        }

        }while(option != 4);









}


struct store* add_at_end(struct store* tail , char name[50], int price, int status)
{
	// Complete

    struct store* newp = (struct store*) malloc(sizeof(struct store));


	struct store* head  = tail->next;

	newp->product_price = price;
	newp->status = status;
	strcpy(newp->product_name , name);

	newp->next = head;
	newp->prev = tail;
	tail->next = newp;
	head->prev = newp;
	tail = newp;
	return tail;


}

struct store* add_to_empty(struct store* tail, char name[50], int price , int status)
{
	// Complete

	struct store* newp = tail;

	newp->product_price = price;
	newp->status = status;
	strcpy(newp->product_name , name);

	newp->prev = newp;
	newp->next = newp;

	return newp;


}



int main()
{
	struct store* market = (struct store*) malloc(sizeof(struct store));

	market = add_to_empty(market , "Pepsi" , 5 , 1);
	market = add_at_end(market , "Chips", 5,  0);
	market = add_at_end(market , "Chocolate", 10,  1);


// ====================================================================

	struct store* grocery = (struct store*) malloc(sizeof(struct store));

	grocery = add_to_empty(grocery , "Apples" , 5 , 1);
	grocery = add_at_end(grocery , "Oranges", 5,  0);
	grocery = add_at_end(grocery , "Carrots", 10,  1);


// ====================================================================

	struct store* tech = (struct store*) malloc(sizeof(struct store));

	tech = add_to_empty(tech , "Mouse" , 5 , 1);
	tech = add_at_end(tech , "Keyboard", 5,  0);
	tech = add_at_end(tech , "Laptop", 10,  1);


// ====================================================================

	printf("========================================================================\n");
	printf("|   Welcome to CS212 Data Structures & Algorithms console commerce ^^  |\n");
	printf("========================================================================\n\n");


	int option ;
    struct shopping_cart* newcart = NULL;
	do
	{
		printf("1- View Stores\n");
		printf("2- View My shopping Cart\n");
		printf("3- Exit console commerce\n");

		printf("\nPlease enter an option number: ");

		scanf("%d", &option);

		printf("\n\n===========================================================\n\n");

        
		switch(option){

            case 1:
                     printf("Stores Menu: \n\n");
    
                     printf("1- Market        2-Grocery        3-Tech \n\n ");
    
                     printf("\nPleas enter Store number to browse it's products, or 4 to return to main menu:");
                     int number_of_stor;
                     scanf("%d",&number_of_stor);
                     printf("\n===========================================================\n\n");
    
    
                     switch(number_of_stor){
    
                         case 1:
                                 printf("\n\n");
                                 printf("Welcome to the Super Market ,All your needs are here ^^\n\n");
                                 print_list(market,newcart);
                                 printf("\n\n");
                         break;
                         case 2:
                                 printf("\n\n");
                                 printf("Welcome to the Grocery ,All your needs are here ^^\n\n");
                                 print_list(grocery,newcart);
                                 printf("\n\n");
                         break;
    
                         case 3:
    
                                 printf("\n\n");
                                 printf("Welcome to the Tech ,All your needs are here ^^\n\n");
                                 print_list(tech,newcart);
                                 printf("\n\n");
    
                          break;
    
    
                     }
                     
            case 2:
           
              print_shopping_cart(newcart);
              
            break;
             
           
		}

		// Complete here

	} while(option != 3);




}




