#define NumOfProducts 10
#include <stdio.h>
#include <time.h>
int code,lastbarcode,count = 0,temp1, temp2,lastcode=-1,i=0,autoen=0,countproducts=0,sum=0,sumd=0,totalsum=0,k=0,
productcount[NumOfProducts] = { 0 }, barcodeout[NumOfProducts] = { 0 };



//SETTING DATA
int index[] = { 4343,5124,3213,4342,6543,6542,6876,5323,2314,9876 };
int pricelist[] = { 1543,1654,7654,2434,5453,434,545,6325,9876, 4353};
char* decription[NumOfProducts] = { {"Smart Digital Picture Frame 10.1"},{"Multipurpose Foldable Computer Study Desk - Black"},
	{"2-Piece Melamine Dinnerware Set"},{"Moving Boxes with Handles"},{"Dual Performance Bath Towel"},
	{"Foldable Clothes Drying Laundry Rack"},{"Replacement Water Filters for Water Pitchers"},
	{"Memory Foam With Strong Innerspring Support"},{"Kitchen Storage Baker's Rack with Wood Table"},
	{"Step Hair Dryer And Volumizer Hot Air Brush"} };
double discountlist[] = { 10,25,45,15,20,10,5,5,90,50 };


void addtoout(int code, int barcode) {
	temp1 = barcodeout[code];
	if (temp1 != 1) {
		barcodeout[code] = 1;
		printf("Successfully added product with barcode = %d\n", barcode);
	}
	else
		printf("This barcode is already added to cheque\n");
}
void timesec() {
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	printf("Cheque print time:%s\n",str);
}

void notoout(int code,int barcode) {
	int mode;
	do {
		printf("Delete all product data(set count = 0 and delete from chequek) OR  Just delete product from cheque?(1,2)");
		scanf_s("%d", &mode);
	} while (mode > 2 || mode < 1);
	if (mode == 1) {
		productcount[code] = 0;
		barcodeout[code] = 0;
		printf("Successfully delete information of product with barcode = %d\n", barcode);
	}
	if (mode == 2){
		barcodeout[code] = 0;
		printf("Successfully removed product with barcode = %d\n", barcode);
	}
	
}
void logo();
int summator(int code,int count) {
	temp1 = (pricelist[code]);
	return((temp1-(temp1 * (discountlist[code] / 100)))*count);
}
void FinalSum(int mode) {
	totalsum = sumd = sum = 0;
	for (i = 0; i < NumOfProducts; i++) {
		if (barcodeout[i] == 1) {
			temp1 = pricelist[i];
			temp2 = productcount[i];
			sum += temp1*temp2;
			sumd += temp1*(discountlist[i]/100)*temp2;
			totalsum = (sum - sumd);
		}
	}
	if (mode == 1) {
		printf("Sum without diskount`s = %dp\nSum of discounts = %dp\n"
			"--------------------"
			"-----------\nTotal sum = %dp\n", sum, sumd, totalsum);
	}
	else
		printf("Total sum = %dp\n", totalsum);

}
void seedescription(int code) {
	printf("%s", decription[code]);
}
void cleanout() {
	for (int i = 0; i < NumOfProducts; i++) {
		barcodeout[i] = 0;
		productcount[i] = 0;
	}
	printf("Succsessfully clean cheque");
}
void logo();
void scanproduct() {
	printf("Input barcode\n");
	scanf_s("%d", &lastbarcode);
	for (i = 0; i < NumOfProducts; i++) {
		if (index[i] == lastbarcode) {
			productcount[i] += 1;
			countproducts += 1;
			lastcode = i;
			break;
		}
	}
	if (i == NumOfProducts) {
		printf("Don`t find that bar code\n");
	}
	if (autoen == 1) {
		addtoout(lastcode,lastbarcode);
	}
}
void makeout() {
	system("cls");
	printf("\a\t\t\t\t ------------\n");
	printf("\t\t\t\t|   Cheque   |\n");
	printf("\t\t\t\t ------------\n");

	for (i = 0; i < NumOfProducts; i++) {
		if (barcodeout[i] == 1){
			k += 1;
			printf("%d. ", k);
			seedescription(i);
			printf(" Price: %dp",pricelist[i]);
			temp1 = productcount[i];
			printf(" Count: %d", temp1);
			printf(" Total sum = %dp\n", summator(i,temp1));
			printf("\n");
		}
		
	}
	printf("\n\n");
	printf("\t\t\t\t  ---------\n");
	printf("\t\t\t\t |  TOTAL  |\n");
	printf("\t\t\t\t  ---------\n");
	FinalSum(1);
	printf("\n");
	k = 0;
	printf("\t\t\tTHANKS FOR YOUR SHOPPING!\n");


	
	timesec();
	system("pause");
	
}
     
    
int main() {
	logo();
	printf("WELCOME TO OUR STORE!\n\n");
	while (1) {
		printf("Input command:\n1-scan product\n2-see product description\n3-add product data to receipt\n"
		"4-generate a receipt\n5-calculate a total ammount"
		"\n6-delete product from receipt\n7-automatic mode(auto add after scan)\n8-clear the cheque\n0-EXIT\n");
		scanf_s("%d", &code);
		switch (code)
		{
		case 1:
			scanproduct();
			break;
		case 2:
			if (lastcode != -1) {
				seedescription(lastcode);
				printf("\n");
			}
			else
				printf("You don`t scan a product\n");
			break;
		case 3:
			addtoout(lastcode,lastbarcode);
			break;
		case 4:
			makeout();
			printf("\n");
			break;
		case 5:
			FinalSum(0);
			break;
		case 6:
			notoout(lastcode,lastbarcode);
		case 7:
			if (autoen != 1)
				autoen = 1;
			else
				autoen = 0;
			break;
		case 8:
			cleanout();
			break;
		case 0:
			return 0;
		}
	}

}

void logo() {
	printf("                       ,########.                             \n"
		"                 .#########      ,(##########///                 \n"
		"                #########     (########(////////*                \n"
		"              .#######(    ////////////////////    ##            \n"
		"             ############/     .//////////.     *######       \n"
		"           ############(######             .############         \n"
		"          #############     #############################.       \n"
		"         #############(       *###########################       \n"
		"        ,#############        #############################      \n"
		"        ##############                      .##############      \n"
		"        #############                          ############      \n"
		"        (############   ,#########.             (##########      \n"
		"         ############################            ##########      \n"
		"         (###########################(           #########       \n"
		"          (##########################           #########        \n"
		"           .#######################            ########         \n"
		"             (################(.             *########           \n"
		"               *##                         #########			  \n"
		"                                       ##########                \n"
		"                               ./###########(                    \n"
		"                              .*///*.							  \n");
}

