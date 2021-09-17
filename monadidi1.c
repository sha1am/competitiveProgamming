//Q1.Write a program to find the largest number in an array

#include <stdio.h>
void main(){
	int a[]={5,13,6,8,9};
	int max=a[0];
	for(int i=0;i<5;i++){
		if(a[i]>max){
			max=a[i];
		}
	}

	printf("Largest is %d\n",max);
}

//Q2.Write a program to check wheather given year is leap or not
#include <stdio.h>
void main(){
	int year;
	printf("Enter the year \n");
	scanf("%d",&year);
	if(year%4==0){
		printf("%d Year is leap year \n",year);
	}
	else{
		printf("%d The given year is not a leap year",year);
	}
}

//Q3. Write a program to calculate area and circumference of a circle
#include<stdio.h>
void main(){
	int area,circumference,radius;
	printf("Enter the radius of the circle \n");
	scanf("%d", &radius);
	area=3.14*radius*radius;
	circumfernce=2*3.14*radius;
	printf("The area of the circle is %d and circumference is %d",area, circle);
}

//Q4.Write a program to find weather a number is even or odd
#include<stdio.h>
void main(){
		int num;
		printf("Enter the number ");
		scanf("%d",&num);
		if(num%2==0){
			printf("The number is even");
		}
		else{
			printf("The number is odd");
		}
}
//Q5.Write a program to find weather a number is prime or not
#include<stdio.h>
void main(){
		int num;
		printf("Enter the number");
		scanf("%d",&num);
		int noOfFactors=0;
		for(int i=2;i<n;i++){
			if(num%i==0) count++;
		}

		if(count==0) printf("The number is prime");
		else printf("The number is not prime");
}

//Q6.Write a program to find sum of digit of a number
#include <stdio.h>
void main(){
		int num;
		printf("Enter the number");
		scanf("%d",&num);
		int a,sum=0;
		while(num>0){
			a=num%10;
			num=num/10;
			sum=sum+a;
		}
		printf("The sum of digits is %d",sum);
}

//Q7.Write a program to display airthmetic operators 
#include <stdio.h>
void main(){
		int num1,num2,result;
		int choice;
		printf("Enter num1 :-");
		scanf("%d",&num1);
		printf("Enter num2 :-");
		scanf("%d",&num2);
		printf("Enter 1)Addition 2)Subtraction 3)Multiplication 4)Division:-");
		scanf("%d",&choice);
		switch(choice){
			case 1: result=num1+num2;
					printf("The sum is %d",&result);
			case 2: result=num1-num2;
					printf("The diff is %d",&result);
			case 3: result=num1*num2;
					printf("The ans is %d",&result);
			case 4: result=num1/num2;
					printf("The diff is %d",&result);
		}
}

//Q8.Write a program to display sum of first 10 natural number
#include <stdio.h>
void main(){
		int sum=0;
		for(int i=1;i<=10;i++){
			sum=sum+i;
		}

		printf("The sum is %d",sum);
}

//Q9.Write a program to find factorial of a given number
#include <stdio.h>
void main(){
		int num,ans=1;
		printf("Enter the number");
		scanf("%d",&num);

		for(int i=1;i<=num;i++){
			ans=ans*i;
		}

		printf("The factorial of %d is %d",num,ans);
//Q10.Write a program to print fibbonaci sequence till 10
#include <stdio.h>
void main(){
		int num=10;
		int arr[10];
		arr[0]=0;
		arr[1]=1;

		for(int i=2;i<=10;i++){
			arr[i]=arr[i-1]+arr[i-2];
		}

		for(int i=0;i<=10;i++){
			printf("%d ",arr[i]);
		}

		
}

//Q11.Write a program to add two numbers using pointers
#include <stdio.h>
void main(){
		int num1,num2,*p,*q,result;
		int choice;
		printf("Enter num1 :-");
		scanf("%d",&num1);
		printf("Enter num2 :-");
		scanf("%d",&num2);
		
		p=&num1;
		q=&num2;
		sum=*p+*q;
		printf("Sum of the numbers is %d",sum);
}


//Q12.Write a program to show sum and average of 10 elements
#include <stdio.h>
void main(){
		int arr[10]={1,2,5,6,4,6,3,2,8,9};
		int sum=0;
		for(int i=0;i<10;i++){
			sum=sum+arr[i];
		}
		printf("Sum of the numbers is %d and average is %d",sum,sum/10);
}

//Q13.Write a program to find number of occurence of vowels, consonents, word, spaces in given line 
#include <stdio.h>
void main(){
		char line[150];
		int vowels=0,consonant=0,words=0;

		printf("Enter the line string");
		fgets(line,sizeof(line),stdin);

		for(int i=0;line[i]!='\0',++i){
			if(line[i]=='a'||line[i]=='e'||line[i]=='i'||line[i]=='o'||line[i]=='u'||line[i]=='A'||line[i]=='E'||line[i]=='I'||line[i]=='O'||line[i]=='U')
			{
				vowel++;
			}
			else if((line[i]>='a' && line[i]<"z") || (line[i]>='A' && line[i]<"Z") ){
				consonant++;
			}
			else if(line[i]==" "){
				words++;

			}
		}

		printf("The number of vowels is %d,consonant is %d and number of words %d ",vowels, consonant,words);
}

//Q14.Write a program to find weather a string is palidrone or not
#include <stdio.h>
void main(){
		char string[20];
		int length;
		int flag=0;

		printf("Enter a string :-");
		scanf("%s",string);

		length=strlen(string);
		for(int i=0;i<length;i++){
			if(string[i-1]!=string[length-1-i]){
				flag=1;
			}
		}
		if(flag==1){
			printf("%s is not a palindrome",string);
		}
		else{
			printf("%s is a palindrome",string);
		}

}

//Q15.Ramesh’s basic salary is input through the keyboard. His dearness allowance is 40% of basic salary, and house rent allowance is 20% of basic salary. Write a program to calculate his gross salary.

#include<stdio.h>
void main()
{
	float basic_salary, dallowance, house_rent, gross_salary;
	printf("Enter Basic Salary: ");
	scanf("%f",&basic_salary);
    dallowance = 0.4 * basic_salary;
    house_rent = 0.2 * basic_salary;
    gross_salary = basic_salary + dallowance + house_rent;
	printf("\n Basic Salary: %.2f",  basic_salary);
	printf("\n Dearness Allowance: %.2f", dallowance);
	printf("\n House Rent: %.2f", house_rent);
	printf("\n\n Gross Salary: %.2f", gross_salary);
	
	
}




