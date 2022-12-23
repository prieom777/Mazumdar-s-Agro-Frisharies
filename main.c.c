#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//GLOBAL DEFINITION SECTION

void mainMenu();
int authentication();

// functions to manage projects
void projectMenu();
void addNewProject();
void saveProjectInfo();
void viewAllProjects();
void updateProjectInfo();
void deleteProjectInfo();

// functions to manage expenses
void expenseMenu();
void addNewExpense();
void saveExpenseInfo();
void viewAllExpenses();
void updateExpenseInfo();
void deleteExpenseInfo();

// functions to manage feeding history
void fHistoryMenu();
void addNewFHistory();
void saveFHistoryInfo();
void viewAllFHistory();
void updateFHistoryInfo();
void deleteFHistoryInfo();

// functions to manage employee
void employeeMenu();
void addNewEmployee();
void saveEmployeeInfo();
void viewAllEmployee();
void updateEmployeeInfo();
void deleteEmployeeInfo();

// functions to manage sells
void sellsMenu();
void addNewSells();
void saveSellsInfo();
void viewAllSells();
void updateSellsInfo();
void deleteSellsInfo();

// functions to generate reports
void generateReport();
// functions for price estimation
void priceEstimate();


//Project structure
struct Project{
    int id;
    float estimatedBudget;
    char projectName[50], projectShortDes[100], projectType[30], startDate[15], endDate[15];
};

//Expense structure
struct Expense{
    int id, projectId;
    float amount;
    char date[30], productOrService[20], supplierInfo[25];
};

//FeedingHistory structure
struct FeedingHistory{
    int id, projectId;
    float quantity;
    char date[10], time[10], foodCategory[10];
};

//Employee structure
struct Employee{
    int id, phoneNumber;
    float salary;
    char name[50], address[50], email[25];
};

//SellsInfo structure
struct SellsInfo{
    int id, projectId;
    float amount, quantity;
    char productName[20],date[10];
};


// declaring file pointer for the file read write operation
FILE *fileToOperate;
// declaring a variable to hold data of our custom data structure
struct Project projectInfo;
struct Expense expenseInfo;
struct FeedingHistory fHistoryInfo;
struct Employee employeeInfo;
struct SellsInfo sellsInfo;

//main function of the program
int main(){
    system("cls");
    int choice;
    printf("\n***Mazumdar's Agro & Fisheries***\n\n");
    printf("Please Login First!!!\n   1. Enter Credentials\n   2. Exit\nPlease enter your choice (1/2) : ");
    login: scanf("%d", &choice);
    if(choice==1){
        //calling the login function to check whether password is correct or not
        reauthenticate: if(authentication()==0){
            mainMenu();
        }else {
            system("cls");
            printf("Your password or username is incorrect. Please Try again.\n");
            goto reauthenticate; // taking re-input for the valid password
        }
    }else if(choice==2){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }else{
        printf("\nInvalid Choice. You should enter \"1\" for Login or \"2\" for Exit.\n\nPlease enter your choice again (1/2) : ");
        goto login;
    }
    return 0;

}

// main menu of the project
void mainMenu(){
    system("cls");
    printf("\n\n***** Mazumdar's Agro & Fisheries Admin Panel. *****\n");
    printf("\n\t1. Manage Projects\n\t2. Manage Expenses\n\t3. Manage Feeding History\n\t4. Manage Employee\n\t5. Manage Sells\n\t6. Generate Report\n\t7. Price Estimation\n\t8. Logout\n");
    printf("\nChose the option what you want to do (1/2/3/4/5/6/7/8) : ");

    int userChoice;
    redirToMainMenu: scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
        projectMenu();
        break;
    case 2:
        expenseMenu();
        break;
    case 3:
        fHistoryMenu();
        break;
    case 4:
        employeeMenu();
        break;
    case 5:
        sellsMenu();
        break;
    case 6:
        generateReport();
        break;
    case 7:
        priceEstimate();
        break;
    case 8:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;
    default:
        printf("\nInvalid input. Please enter a valid input : ");
        goto redirToMainMenu;
    }

}

// necessary codes for password protected login
int authentication(){
    char fixUsername[15]="admin";
    char fixPassword[15]="12345";
    char userName[15],userPassword[15];

    printf("\nEnter Username : ");
    fflush(stdin);
    gets(userName);
    printf("\nEnter Password : ");
    fflush(stdin);
    gets(userPassword);

    int flag1 = (strcmp(userName,fixUsername));
    int flag2 = (strcmp(userPassword, fixPassword));

    return flag1+flag2;
}

// Functions of project management starts here
// project sub menu
void projectMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");
    printf("A. Create New Project Info\n");
    printf("B. View all project info\n");
    printf("C. Update existing project info\n");
    printf("D. Delete a project info\n");
    printf("E. Back to Main Menu\n\n");

    returnToProjectMenu: printf("Choose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewProject();
        break;
    case 'B':
        viewAllProjects();
        break;
    case 'C':
        updateProjectInfo();
        break;
    case 'D':
        deleteProjectInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToProjectMenu;
    }
}

void addNewProject(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(projectInfo.projectType);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &projectInfo.id);
    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(projectInfo.projectName);
    printf("Please Provide Short Details About Project: ");
    fflush(stdin);
    gets(projectInfo.projectShortDes);
    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(projectInfo.startDate);
    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(projectInfo.endDate);
    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%f", &projectInfo.estimatedBudget);

    saveProjectInfo();

    redirAddSub: printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t2.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        addNewProject();
    }else if (choice==2){
        projectMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirAddSub;
    }
}

void saveProjectInfo()
{
    fileToOperate = fopen("projectData.txt", "a");
    fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// codes to show the stored projects info from file
void viewAllProjects()
{
    system("cls");

    fileToOperate = fopen("projectData.txt", "r");
    printf("\n\n\t\t\t***** All Projects List *****\n\n");
    printf(" **Project ID** \t**Project Title**\t**Project Type** \t**Start Date** \t\t**End Date**");
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        printf("\n\t%d\t\t%s\t\t\t\t%s\t\t%s\t\t%s\n",projectInfo.id,projectInfo.projectName, projectInfo.projectType,projectInfo.startDate,projectInfo.endDate);
    }
    fclose(fileToOperate);

    redirViewSub: printf("\n\t\t\t1. Project Menu\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        projectMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirViewSub;
    }
}

//codes to update the information of a specific project in a file
void updateProjectInfo(){
    system("cls");
    printf("\nUpdate Project Information\n");

    printf("Please enter project id you want to modify: ");
    int pId;
    fflush(stdin);
    scanf("%d", &pId);
    fileToOperate = fopen("projectData.txt", "r+");
    int found = 0;
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id == pId)
        {
            found = 1;
            printf("\nProvide all necessary information about the project\n\n");
            printf("Please Enter Project Type (Fish/Poultry): ");
            fflush(stdin);
            gets(projectInfo.projectType);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &projectInfo.id);
            printf("Please Enter Project Name/Title: ");
            fflush(stdin);
            gets(projectInfo.projectName);
            printf("Please Provide Short Details About Project: ");
            fflush(stdin);
            gets(projectInfo.projectShortDes);
            printf("Please Enter Project Start Date: ");
            fflush(stdin);
            gets(projectInfo.startDate);
            printf("Please Enter Project End Date: ");
            fflush(stdin);
            gets(projectInfo.endDate);
            printf("Please Enter the Estimated Budget: ");
            fflush(stdin);
            scanf("%f", &projectInfo.estimatedBudget);
            fseek(fileToOperate, -sizeof(projectInfo), SEEK_CUR);
            fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nProject information updated\n");
    }
    else
    {
        printf("\nProject with the given ID not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// deleting a project info from the file
void deleteProjectInfo(){
    system("cls");
    FILE  *removeFile;

    int pId;
    printf("Enter The project id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("projectData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id != pId)
        {
            fwrite(&projectInfo, sizeof(struct Project), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("projectData.txt");
    rename("temp.txt", "projectData.txt");

    printf("\nProject Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another  Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// Functions of project management end here

// Functions of expense management starts here

// expense menu function
void expenseMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");
    printf("A. Add an Expense\n");
    printf("B. View all Expenses\n");
    printf("C. Update existing expense info\n");
    printf("D. Delete a expense\n");
    printf("E. Back to Main Menu\n\n");

    returnToExpenseMenu: printf("Choose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewExpense();
        break;
    case 'B':
        viewAllExpenses();
        break;
    case 'C':
        updateExpenseInfo();
        break;
    case 'D':
        deleteExpenseInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToExpenseMenu;
    }
}

// add new expense info function
void addNewExpense(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Expense ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.projectId);
    printf("Please Enter Product/Service Type: ");
    fflush(stdin);
    gets(expenseInfo.productOrService);
    printf("Please Enter Supplier Info: ");
    fflush(stdin);
    gets(expenseInfo.supplierInfo);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(expenseInfo.date);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &expenseInfo.amount);

    saveExpenseInfo();

    redirToSubMenu: printf("\n\t\t\t1. Do You Want To Add Another new Expense info?\n\t\t\t2. Expense Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewExpense();
    }else if (choice==2){
        expenseMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save expense info function
void saveExpenseInfo()
{
    fileToOperate = fopen("expenseData.txt", "a");
    fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllExpenses(){
    system("cls");

    printf("\n\n\t\t\t***** All Expenses List *****\n\n");
    printf(" **Expense ID** \tProject ID** \t**Product/Service** \t**Amount(BDT)** \t**Date**");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%s\t\t%.2f\t\t\t%s\n",expenseInfo.id,expenseInfo.projectId,expenseInfo.productOrService, expenseInfo.amount,expenseInfo.date);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t1. Expense Menu\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        expenseMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update expense info function
void updateExpenseInfo(){
    system("cls");
    printf("\nUpdate Project Information\n");

    printf("Please enter project id you want to modify: ");
    int eId;
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("expenseData.txt", "r+");
    int found = 0;
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Expense ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.projectId);
            printf("Please Enter Product/Service Type: ");
            fflush(stdin);
            gets(expenseInfo.productOrService);
            printf("Please Enter Supplier Info: ");
            fflush(stdin);
            gets(expenseInfo.supplierInfo);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(expenseInfo.date);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &expenseInfo.amount);

            fseek(fileToOperate, -sizeof(expenseInfo), SEEK_CUR);
            fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nExpense information updated\n");
    }
    else
    {
        printf("\nExpense with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateFHistoryInfo();
    }else if (choice==2){
        fHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete expense info fuction
void deleteExpenseInfo(){
    system("cls");
    FILE  *removeFile;

    int pId;
    printf("Enter The Expense Id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("expenseData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id != pId)
        {
            fwrite(&expenseInfo, sizeof(struct Expense), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("expenseData.txt");
    rename("temp.txt", "expenseData.txt");
    system("cls");
    printf("\nExpense Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteExpenseInfo();
    }else if (choice==2){
        expenseMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// functions of expense management ends here

// functions of feeding history management starts here
// fHistory menu function
void fHistoryMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");
    printf("A. Add a Feeding History\n");
    printf("B. View all Feeding History\n");
    printf("C. Update a Feeding History info\n");
    printf("D. Delete a Feeding History\n");
    printf("E. Back to Main Menu\n\n");

    returnToFHistoryMenu: printf("Choose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewFHistory();
        break;
    case 'B':
        viewAllFHistory();
        break;
    case 'C':
        updateFHistoryInfo();
        break;
    case 'D':
        deleteFHistoryInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToFHistoryMenu;
    }
}

// add new fHistory info function
void addNewFHistory(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Feeding History ID: ");
    fflush(stdin);
    scanf("%d", &fHistoryInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &fHistoryInfo.projectId);
    printf("Please Enter Quantity(KG): ");
    fflush(stdin);
    scanf("%f", &fHistoryInfo.quantity);
    printf("Please Enter Food Category: ");
    fflush(stdin);
    gets(fHistoryInfo.foodCategory);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(fHistoryInfo.date);
    printf("Please Enter Time: ");
    fflush(stdin);
    gets(fHistoryInfo.time);

    saveFHistoryInfo();

    redirToSubMenu: printf("\n\t\t\t1.Do You Want To Add Another new Feeding History info?\n\t\t\t2.Feeding History Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewFHistory();
    }else if (choice==2){
        fHistoryMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save fHistory info function
void saveFHistoryInfo()
{
    fileToOperate = fopen("fHistoryData.txt", "a");
    fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllFHistory(){
    system("cls");
    printf("\n\n\t\t\t\t\t***** All Feeding History List *****\n\n");
    printf(" **Feeding History ID** \tProject ID** \t**Quantity** \t**Food Category** \t**Date**");

    fileToOperate = fopen("fHistoryData.txt", "r");
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%.2f\t\t\t%s\t\t%s\n",fHistoryInfo.id,fHistoryInfo.projectId,fHistoryInfo.quantity, fHistoryInfo.foodCategory,fHistoryInfo.date);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t1. Feeding History Menu\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        fHistoryMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update fHistory info function
void updateFHistoryInfo(){
    system("cls");
    printf("\nUpdate Project Information\n");

    printf("Please enter project id you want to modify: ");
    int fhId;
    fflush(stdin);
    scanf("%d", &fhId);
    fileToOperate = fopen("fHistoryData.txt", "r+");
    int found = 0;
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.id == fhId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Feeding History ID: ");
            fflush(stdin);
            scanf("%d", &fHistoryInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &fHistoryInfo.projectId);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f", &fHistoryInfo.quantity);
            printf("Please Enter Food Category: ");
            fflush(stdin);
            gets(fHistoryInfo.foodCategory);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(fHistoryInfo.date);
            printf("Please Enter Time: ");
            fflush(stdin);
            gets(fHistoryInfo.time);

            fseek(fileToOperate, -sizeof(fHistoryInfo), SEEK_CUR);
            fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nFeeding History information updated\n");
    }
    else
    {
        printf("\nFeeding History with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateFHistoryInfo();
    }else if (choice==2){
        fHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete fHistory info fuction
void deleteFHistoryInfo(){
    system("cls");
    FILE  *removeFile;

    int fHId;
    printf("Enter The Feeding History Id :");
    fflush(stdin);
    scanf("%d", &fHId);

    fileToOperate = fopen("fHistoryData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.id != fHId)
        {
            fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("fHistoryData.txt");
    rename("temp.txt", "fHistoryData.txt");
    system("cls");
    printf("\nFeeding History Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteFHistoryInfo();
    }else if (choice==2){
        fHistoryMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
// functions of feeding history management ends here

//functions of employee management starts here
// employee menu function
void employeeMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");
    printf("A. Add A New Employee\n");
    printf("B. View all Employees\n");
    printf("C. Update An Existing Employee Info\n");
    printf("D. Delete an Employee Info\n");
    printf("E. Back to Main Menu\n\n");

    returnToEmployeeMenu: printf("Choose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewEmployee();
        break;
    case 'B':
        viewAllEmployee();
        break;
    case 'C':
        updateEmployeeInfo();
        break;
    case 'D':
        deleteEmployeeInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToEmployeeMenu;
    }
}

// add new employee info function
void addNewEmployee(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the Employee\n\n");
    printf("Please Enter Employee ID: ");
    fflush(stdin);
    scanf("%d", &employeeInfo.id);
    printf("Please Enter Employee Name: ");
    fflush(stdin);
    gets(employeeInfo.name);
    printf("Please Enter Employee Email: ");
    fflush(stdin);
    gets(employeeInfo.email);
    printf("Please Enter Employee Phone-number: ");
    fflush(stdin);
    scanf("%d",&employeeInfo.phoneNumber);
    printf("Please Enter Employee Salary: ");
    fflush(stdin);
    scanf("%f", &employeeInfo.salary);

    saveEmployeeInfo();

    redirToSubMenu: printf("\n\t\t\t1.Do You Want To Add Another new Employee info?\n\t\t\t2.Employee Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewEmployee();
    }else if (choice==2){
        employeeMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save employee info function
void saveEmployeeInfo()
{
    fileToOperate = fopen("employeeData.txt", "a");
    fwrite(&employeeInfo, sizeof(struct Employee), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all employee function
void viewAllEmployee(){
    system("cls");

    printf("\n\n\t\t\t***** All Employee List *****\n\n");
    printf(" **Employee ID** \t Name** \t**Phone Number** \t**Email** \t\t**Salary**");

    fileToOperate = fopen("employeeData.txt", "r");
    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t%s\t\t0%d\t\t%s\t\t%.2f\n",employeeInfo.id,employeeInfo.name,employeeInfo.phoneNumber, employeeInfo.email,employeeInfo.salary);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t1. Employee Menu\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        employeeMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update employee info function
void updateEmployeeInfo(){
    system("cls");
    printf("\nUpdate Project Information\n");

    int eId;
    printf("Please enter Employee id you want to modify: ");
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("employeeData.txt", "r+");
    int found = 0;
    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        if (employeeInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Employee\n\n");
            printf("Please Enter Employee ID: ");
            fflush(stdin);
            scanf("%d", &employeeInfo.id);
            printf("Please Enter Employee Name: ");
            fflush(stdin);
            gets(employeeInfo.name);
            printf("Please Enter Employee Email: ");
            fflush(stdin);
            gets(employeeInfo.email);
            printf("Please Enter Employee Phone-number: ");
            fflush(stdin);
            scanf("%d",&employeeInfo.phoneNumber);
            printf("Please Enter Employee Salary: ");
            fflush(stdin);
            scanf("%f", &employeeInfo.salary);

            fseek(fileToOperate, -sizeof(employeeInfo), SEEK_CUR);
            fwrite(&employeeInfo, sizeof(struct Employee), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nEmployee information updated\n");
    }
    else
    {
        printf("\nEmployee with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Employee info?\n\t\t\t2. Employee Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateEmployeeInfo();
    }else if (choice==2){
        employeeMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete employee info fuction
void deleteEmployeeInfo(){
    system("cls");
    FILE  *removeFile;

    int eId;
    printf("Enter The Employee Id :");
    fflush(stdin);
    scanf("%d", &eId);

    fileToOperate = fopen("employeeData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        if (employeeInfo.id != eId)
        {
            fwrite(&employeeInfo, sizeof(struct Employee), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("employeeData.txt");
    rename("temp.txt", "employeeData.txt");
    system("cls");
    printf("\nEmployee Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Employee info?\n\t\t\t2. Employee Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteEmployeeInfo();
    }else if (choice==2){
        employeeMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
//functions of employee management ends here

//functions of sells management start here
// sells menu function
void sellsMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");
    printf("A. Add A Selling Info\n");
    printf("B. View All Sells\n");
    printf("C. Update Existing Selling info\n");
    printf("D. Delete A Selling Info\n");
    printf("E. Back to Main Menu\n\n");

    returnToSellsMenu: printf("Choose the Option(A/B/C/D/E): ");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);

    switch (menuChoice)
    {
    case 'A':
        addNewSells();
        break;
    case 'B':
        viewAllSells();
        break;
    case 'C':
        updateSellsInfo();
        break;
    case 'D':
        deleteSellsInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToSellsMenu;
    }
}

// add new sells info function
void addNewSells(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Fisheries Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the Sell\n\n");
    printf("Please Enter Selling Info ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.projectId);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &sellsInfo.amount);
    printf("Please Enter Product Name: ");
    fflush(stdin);
    gets(sellsInfo.productName);
    printf("Please Enter Quantity: ");
    fflush(stdin);
    scanf("%f",&sellsInfo.quantity);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(sellsInfo.date);

    saveSellsInfo();

    redirToSubMenu: printf("\n\t\t\t1. Do You Want To Add Another new Selling info?\n\t\t\t2. Sells Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewSells();
    }else if (choice==2){
        sellsMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToSubMenu;
    }
}

//save sells info function
void saveSellsInfo()
{
    fileToOperate = fopen("sellsData.txt", "a");
    fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all sells function
void viewAllSells(){
    system("cls");

    printf("\n\n\t\t\t***** All Sells List *****\n\n");
    printf(" **Sells ID** \tProduct** \t**Quantity** \t**Amount(BDT)** \t**Date**");

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        printf("\n\n\t%d\t%s\t\t%.2f\t\t%.2f\t\t%s\n",sellsInfo.id,sellsInfo.productName,sellsInfo.quantity, sellsInfo.amount,sellsInfo.date);
    }
    fclose(fileToOperate);

    redirToViewSub: printf("\n\t\t\t1. Sells Menu\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        sellsMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirToViewSub;
    }
}

//update sells info function
void updateSellsInfo(){
    system("cls");
    printf("\nUpdate Project Information\n");

    int sId;
    printf("Please enter project id you want to modify: ");
    fflush(stdin);
    scanf("%d", &sId);
    fileToOperate = fopen("sellsData.txt", "r+");
    int found = 0;
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id == sId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Sell\n\n");
            printf("Please Enter Selling Info ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.projectId);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &sellsInfo.amount);
            printf("Please Enter Product Name: ");
            fflush(stdin);
            gets(sellsInfo.productName);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f",&sellsInfo.quantity);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(sellsInfo.date);

            fseek(fileToOperate, -sizeof(sellsInfo), SEEK_CUR);
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nSelling Info information updated\n");
    }
    else
    {
        printf("\nSelling Info with the given ID  not found in file\n");
    }


    redirUpdateSub: printf("\n\t\t\t1. Do You Want To Modify Another Selling Info info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateSellsInfo();
    }else if (choice==2){
        sellsMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirUpdateSub;
    }
}

// delete sells info fuction
void deleteSellsInfo(){
    system("cls");
    FILE  *removeFile;

    int sId;
    printf("Enter The Selling Info Id :");
    fflush(stdin);
    scanf("%d", &sId);

    fileToOperate = fopen("sellsData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id != sId)
        {
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("sellsData.txt");
    rename("temp.txt", "sellsData.txt");
    system("cls");
    printf("\nSelling Info  Successfully Deleted\n");

    redirDeleteSub: printf("\n\t\t\t1. Do You Want To delete Another Selling info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);

    if(choice==1){
        deleteSellsInfo();
    }else if (choice==2){
        sellsMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirDeleteSub;
    }

}
//functions of sells management ends here

// functions of report generation

void generateReport(){
    system("cls");

    int pId,found = 0;
    float totalExpenses =0, totalSells =0,totalFeed=0;
    printf("\n\nPlease enter project id you want to Generate Report: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\n\n\t\t\t***** Project Report *****\n\n");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
           totalExpenses += expenseInfo.amount;
           found = 1;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
           totalSells += sellsInfo.amount;
           found = 1;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("fHistoryData.txt", "r");
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.projectId == pId)
        {
           totalFeed += fHistoryInfo.quantity;
           found = 1;
        }
    }
    fclose(fileToOperate);

    if (found == 1)
    {
        printf("\n\tProject Id : %d\n", pId);
        printf("\n\tProject Total Feed Give : %.2f KG\n", totalFeed);
        printf("\n\tProject Total Sells : %.2f(BDT)\n", totalSells);
        printf("\n\tProject Total Expenses : %.2f(BDT)\n", totalExpenses);
        if(totalSells-totalExpenses >0){
            printf("\n\tNET Profit : %.2f (BDT)\n", totalSells-totalExpenses);
        }else{
            printf("\n\tNET Loss : %.2f (BDT)\n", totalExpenses-totalSells);
        }
    }
    else
    {
        printf("\nProject with the given ID not found in file\n");
    }

    redirReportSub: printf("\n\t\t\t1. Do You Want To Generate Report For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        generateReport();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirReportSub;
    }
}

void priceEstimate(){
    system("cls");

    int pId,found = 0;
    float percentage;
    char sign;
    float totalExpenses = 0,totalSells=0;
    float lossOrProfit;

    printf("\n\nPlease enter Project Id you want to estimate price: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\nPlease enter the Percentage you to make profit(X%%): ");
    fflush(stdin);
    scanf("%f%c", &percentage,&sign);

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
           totalExpenses += expenseInfo.amount;
           found = 1;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
           totalSells += sellsInfo.amount;
           found = 1;
        }
    }
    fclose(fileToOperate);

    lossOrProfit = (totalExpenses + (totalExpenses*(percentage/100))) - totalSells;

    if (found == 1)
    {
        printf("\n\n\t\t\t***** Price Estimation *****\n\n");
        printf("\n\tProject Id : %d\n", pId);
        printf("\n\tProject Total Sells Till Now : %.2f(BDT)\n", totalSells);
        printf("\n\tProject Total Expenses Till Now : %.2f(BDT)\n", totalExpenses);

        if(lossOrProfit > 0){
            printf("\n\tTo do a profit of %.2f%% you need to have more %.2f (BDT) sells from this project.\n", percentage, lossOrProfit);
        }else{
            printf("\n\tThe Project is already in profit of %.2f (BDT)\n\n",lossOrProfit*-1);
        }
    }
    else
    {
        printf("\nProject with the given ID not found in file\n");
    }

    redirReportSub: printf("\n\t\t\t1. Do You Want To Estimate Price For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Logout");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        priceEstimate();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto redirReportSub;
    }
}
