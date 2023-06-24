#include <stdio.h>
#include <string.h>

//define constants 
#define MAX_NAME_LENGTH 35
#define MAX_LOCATION_LENGTH 65
#define MAX_NUMBER_LENGTH 20

// struct for contact information
struct contact {
	char name[MAX_NAME_LENGTH];
	char location[MAX_LOCATION_LENGTH];
	char number[MAX_NUMBER_LENGTH];
};

// struct for job search assistance service 
struct assistanceService {
	struct contact serviceProvider;
	char jobTitle[40];
	int experience;
	char jobDescription[MAX_NAME_LENGTH];
};

// global list of assistance services
struct assistanceService services[2000];


//function declarations
void addService(struct assistanceService service);
void deleteService(int position);
struct assistanceService getService(int position);
void editService(int position);


int main()
{
	return 0;
}

// function to add a service 
void addService(struct assistanceService service)
{
	// check if array is full
	int length = sizeof(services)/sizeof(services[0]);
	if(length == 2000)
	{
		printf("No more room in array");
		return;
	}

	// add service to array
	services[length] = service;
}

// function to delete a service
void deleteService(int position)
{
	// check if position is valid
	int length = sizeof(services)/sizeof(services[0]);
	if(position > length-1)
	{
		printf("Invalid position");
		return;
	}

	// delete service from array
	int j;
	for(j = position; j < length-1; j++) 
	{
        services[j] = services[j+1];
	}
	length = length-1;
}

// function to get a service
struct assistanceService getService(int position)
{
	// check if position is valid
	int length = sizeof(services)/sizeof(services[0]);
	if(position > length-1)
	{
		printf("Invalid position");
		return;
	}

	return services[position];
}

// function to edit a service
void editService(int position)
{
	// check if position is valid
	int length = sizeof(services)/sizeof(services[0]);
	if(position > length-1)
	{
		printf("Invalid position");
		return;
	}

	struct assistanceService service;

	// edit service in array
	printf("Enter a new name: ");
	gets(service.serviceProvider.name);
	printf("Enter a new location: ");
	gets(service.serviceProvider.location);
	printf("Enter a new number: ");
	gets(service.serviceProvider.number);
	printf("Enter a new job title: ");
	gets(service.jobTitle);
	printf("Enter a new experience level: ");
	scanf("%d", &service.experience);
	printf("Enter a new job description: ");
	gets(service.jobDescription);
	services[position] = service;
}