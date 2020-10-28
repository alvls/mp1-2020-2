#define NumOfProducts 10
#include <stdio.h>
int code,lastbarcode,count = 0,temp1, temp2,lastcode,i=0, sum=0, sumd=0,totalsum=0,autoen=0,countproducts=0,
productcount[NumOfProducts] = { 0 }, barcodeout[NumOfProducts] = { 0 };

//SETTING DATA
int index[] = { 4343,5124,3213,4342,6543,6542,6876,5323,2314,9876 };
int pricelist[] = { 1543,1654,7654,2434,5453,434,545,6325,9876, 4353};
char description[] = ("Smart Digital Picture Frame 10.1Multipurpose Foldable Computer Study Desk - Black"
	"2-Piece Melamine Dinnerware Set"
	"Moving Boxes with Handles"
	"Dual Performance Bath Towel"
	"Foldable Clothes Drying Laundry Rack"
	"Replacement Water Filters for Water Pitchers"
	"Memory Foam With Strong Innerspring Support"
	"Kitchen Storage Baker's Rack with Wood Table"
	"Step Hair Dryer And Volumizer Hot Air Brush");
int descriptionsize[NumOfProducts][2] = {
	{0,32},{32,81},{81,112},{112,137} ,{137,168} ,{168,205},
	{205,263} ,{263,307} ,{307,345} ,{345,388}
};
float discountlist[] = {10,25,45,15,20,10,5,5,90,50 };



void addtoout() {
	barcodeout[lastcode] = 1;
	printf("Successfully added product with barcode = %d\n",lastbarcode);
}
void notoout() {
	barcodeout[lastcode] = 0;
	printf("Successfully removed product with barcode = %d\n", lastbarcode);
}
int summator(int code,int count) {
	temp1 = (pricelist[code]);
	return((temp1-(temp1 * (discountlist[code] / 100))*count));
}
void FinalSum(int mode) {
	for (i = 0; i < NumOfProducts; i++) {
		if (barcodeout[i] == 1) {
			temp1 = pricelist[i];
			temp2 = productcount[i];
			sum += temp1*temp2;
			sumd += temp1*(discountlist[i]/100)*temp2;
			totalsum = (sum - sumd);
		}
	}
	if (i == NumOfProducts) {
		printf("Don`t find that bar code\n");
	}
	if (mode == 1) {
		printf("Sum without diskount`s = %d, sum of discounts = %d, total sum = %d\n", sum, sumd, totalsum);
	}
	else
		printf("Total sum = %d\n", totalsum);

}
void seedescription() {
	temp1 = descriptionsize[lastcode][0];
	temp2 = descriptionsize[lastcode][1];
	for (temp1; temp1 < temp2; temp1++) {
		printf("%c", description[temp1]);
	}
	printf("\n");
}
void scanproduct() {
	printf("Input barcode\n");
	scanf_s("%d", &lastbarcode);
	for (i = 0; i < NumOfProducts; i++) {
		printf("Yeah");
		if (index[i] == lastbarcode) {
			productcount[i] += 1;
			countproducts += 1;
			lastcode = i;
			break;
		}
	}
	if (autoen == 1) {
		addtoout();
	}

}
void makeout() {
	for (i = 0; i < NumOfProducts; i++) {
		if (barcodeout[i] == 1){
			temp1 = descriptionsize[i][0];
			temp2 = descriptionsize[i][1];
			for (temp1; temp1 < temp2; temp1++) {
				printf("%c", description[temp1]);
			}
			printf(" Price: %d",pricelist[i]);
			temp1 = productcount[i];
			printf(" Count: %d", temp1);
			printf(" Total sum = %d\n", summator(i,temp1));
			printf("\n");
		}
		
	}
	printf("\n");
	printf("\n");
	FinalSum(1);
}

int main() {

	while (1) {
		printf("Input command:\n1-scan product\n2-see product description\n3-add product data to receipt\n"
		"4-generate a receipt\n5-calculate a total ammount\n6-delete product from receipt\n7-automatic mode(auto add after scan)\n0-EXIT\n");
		scanf_s("%d", &code);
		switch (code)
		{
		case 1:
			scanproduct();
			break;
		case 2:
			seedescription();
			break;
		case 3:
			addtoout();
			break;
		case 4:
			makeout();
			printf("\n");
			break;
		case 5:
			FinalSum(0);
			break;
		case 6:
			notoout();
		case 7:
			if (autoen != 1)
				autoen = 1;
			else
				autoen = 0;
			break;
		case 0:
			return 0;
		}
	}
}


