// Program should ask for loan amount, period of payment (month, year), interest rate
// how many payments in those periods, and maybe more
// It should then use all that information and give how much 
// the user should pay per month and the monthly principal and interest paid
// It should save a record of the loan payments in a file and reload and display them

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

const string PROGRAM_NAME = "Loan Amortization Calculator";
const string suffix = ".txt";

int getIntWithPrompt(string userPromptInt) {
    // declare userInput
    int userInputInt;
    // print userPromptInt
    cout << userPromptInt;
    // take the userInput
    cin >> userInputInt;
    // return userInput
    return userInputInt;
}

double getDoubleWithPrompt(string userPromptDouble) {
    // declare userInput
    double userInputDouble;
    // print userPromptDouble
    cout << userPromptDouble;
    // take the userInput
    cin >> userInputDouble;
    // return userInput
    return userInputDouble;
}

double getLoanAmount() {
    // declare loanAmount
    double loanAmount;
    // ask user for loanAmount
    loanAmount = getDoubleWithPrompt("How much would you like to take out: ");

    cerr << endl;
    cerr << "User's loan amount is " << fixed << setprecision(2) << loanAmount << endl;
    cerr << endl;
    // return loanAmount
    return loanAmount;
}

double getloanTerm(int periodChoice) {
    // declare loanTermInMonths and initialize to 0
    double loanTermInMonths = 0;
    // declare loanTermInYears and initialize to 0
    double loanTermInYears = 0;
    // declare loanTermInWeeks and initialize to 0
    // double loanTermInWeeks = 0;

    if(periodChoice == 1) {
        loanTermInMonths = getDoubleWithPrompt("How many months do you have to pay the loan: ");

        cerr << endl;
        cerr << "Loan term in months is " << loanTermInMonths << endl;
        cerr << endl;

        // return loanTermInMonths
        return loanTermInMonths;
    }
    // if years, ask for how many years the user wants for paying the loan (make sure 1 year is equivalent to 12 months)
    else if(periodChoice == 2) {
        loanTermInYears = getDoubleWithPrompt("How many years do you have to pay the loan: ");

        cerr << endl;
        cerr << "Loan term in years is " << loanTermInYears << endl;
        cerr << endl;

        // return loanTermInYears
        return loanTermInYears;
    }
    // else if(periodChoice == 3) {
    //     loanTermInWeeks = getDoubleWithPrompt("How many weeks do you have to pay the loan: ");

    //     cerr << endl;
    //     cerr << "Loan term in weeks is " << loanTermInWeeks << endl;
    //     cerr << endl;

    //     // return loanTermInWeeks
    //     return loanTermInWeeks;
    // }
    else {
        return -1;
    }
}

double getInterestRate(int periods) {
    // declare monthlyInterestRate
    double monthlyInterestRate;
    // declare yearlyInterestRate
    double yearlyInterestRate;

    yearlyInterestRate = getDoubleWithPrompt("What is the yearly interest rate: ");
    // divide the input by 100 to get it as a decimal and then by 12 to get the monthly rate
    cerr << endl;
    cerr << "Converting yearly interest rate to a decimal" << endl;
    cerr << "Yearly interest rate is " << fixed << setprecision(4) << yearlyInterestRate / 100 << endl;
    cerr << "Converting yearly interest rate to monthly interest rate" << endl;
    monthlyInterestRate = (yearlyInterestRate / 12.0) / 100.0;
    cerr << "Monthly interest rate now " << monthlyInterestRate << endl;
    cerr << endl;
    // return monthlyInterestRate
    return monthlyInterestRate;
}

double calculateTotalPerPeriod(double amountTakenInLoan, int termOfLoan, double rateOfInterest, int choiceOfTerms) {
    // use the information from the other functions to get the total money that should be paid 
    // each period
    double totalPerPeriod = -1;
    if(choiceOfTerms == 1) {
        cerr << "Calculating the total per period" << endl;
        totalPerPeriod = amountTakenInLoan * ((rateOfInterest * pow(((1.0 + rateOfInterest)), termOfLoan)) / ((pow((1.0 + rateOfInterest), termOfLoan)) - 1.0));
    
        cerr << endl;
        cerr << "Total per period now " << setprecision(2) << totalPerPeriod << endl;
        cerr << endl;
    }
    else if(choiceOfTerms == 2) {
        termOfLoan *= 12;

        cerr << "Calculating the total per period" << endl;
        totalPerPeriod = amountTakenInLoan * ((rateOfInterest * pow(((1.0 + rateOfInterest)), termOfLoan)) / ((pow((1.0 + rateOfInterest), termOfLoan)) - 1.0));

        totalPerPeriod *= 12;

        cerr << endl;
        cerr << "Total per period now " << setprecision(2) << totalPerPeriod << endl;
        cerr << endl;
    }
    // else if(choiceOfTerms == 3) {
    //     termOfLoan /= 4.34524;

    //     cerr << "Calculating the total per period" << endl;
    //     totalPerPeriod = amountTakenInLoan * ((rateOfInterest * pow(((1.0 + rateOfInterest)), termOfLoan)) / ((pow((1.0 + rateOfInterest), termOfLoan)) - 1.0));

    //     totalPerPeriod /= 2;

    //     cerr << endl;
    //     cerr << "Total per period now " << setprecision(2) << totalPerPeriod << endl;
    //     cerr << endl;
    // }
    // return this amount
    return totalPerPeriod;
}

string getFileName() {
    // declare fileToDealWith
    string fileToOpen;
    // ask the user for their file name
    cout << "What would you like to name your file (please enter as one word with ThisCapitalization)? ";
    // initialize fileToDealWith as the user's input
    cin >> fileToOpen;
    // return fileToOpen
    return fileToOpen;
}

void storeResultsInFile(double uTotal, double uInterestRate, double aLoan, double lTerm, int numPeriodsChoice, string fileName) {
    // open a file 
    ofstream amortizationSchedule;

    double monthlyBalance = aLoan; // balance starts as total loan amount

    double yearlyBalance = aLoan; // balance starts as total loan amount

    // double biWeeklyBalance = aLoan; // balance starts as total loan amount

    // declare and initialize ttime and local_time as imported time data types
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    // declare and initalize year and month as the current year and month
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    // int day = local_time->tm_mday;



    amortizationSchedule.open(fileName + suffix);
    // show the date, the total paid each month and the principal
    // and interest and finally the balance by the end of each month
    amortizationSchedule << "Date" << setw(10) << "Payment" << setw(10) << "Principal" << setw(10) << "Interest" << setw(9);
    amortizationSchedule << "Balance" << endl;
    amortizationSchedule << "--------------------------------------------" << endl;
    if(numPeriodsChoice == 1) {
        for(int currentMonth = 1; currentMonth <= lTerm; currentMonth ++) {
            double monthlyInterest = uInterestRate * monthlyBalance;
            double monthlyPrincipal;

            if(month < 12) {
                month ++;
            }
            else if (month == 12) {
                month = 1;
                year ++;
            }


            if(currentMonth != lTerm) {
                monthlyPrincipal = uTotal - monthlyInterest;
            }
            else {
                monthlyPrincipal = monthlyBalance;
            }
            monthlyBalance -= monthlyPrincipal;

            if(month != 10 && month != 11 && month != 12) {
                amortizationSchedule << fixed << setprecision(2) << month << "/" << year << setw(8) << uTotal << setw(10);
                amortizationSchedule << monthlyPrincipal << setw(10) << monthlyInterest << setw(10) << monthlyBalance << endl;
            }
            else {
                amortizationSchedule << fixed << setprecision(2) << month << "/" << year << setw(7) << uTotal << setw(10);
                amortizationSchedule << monthlyPrincipal << setw(10) << monthlyInterest << setw(10) << monthlyBalance << endl;
            }
        }
    }
    else if(numPeriodsChoice == 2) {
        for(int currentYear = 1; currentYear <= lTerm; currentYear ++) {
            double yearlyInterest = uInterestRate * 12 * yearlyBalance;
            double yearlyPrincipal;

            year ++;


            if(currentYear != lTerm) {
                yearlyPrincipal = uTotal - yearlyInterest;
            }
            else {
                yearlyPrincipal = yearlyBalance;
            }
            yearlyBalance -= yearlyPrincipal;

            amortizationSchedule << fixed << setprecision(2) << year << setw(10) << uTotal << setw(10);
            amortizationSchedule << yearlyPrincipal << setw(10) << yearlyInterest << setw(10) << yearlyBalance << endl;
        }
    }
    // else if(numPeriodsChoice == 3) {
    //     for(int currentWeek = 1; currentWeek <= lTerm; currentWeek += 2) {
    //         double biWeeklyInterest = uInterestRate / 2.17262 * biWeeklyBalance;
    //         double biWeeklyPrincipal;

    //         // odd months and august, october, and december but not september and november have 31 days
    //         if((month % 2 != 0 && month != 9 && month != 11) || (month == 8 || month == 10 || month == 12)) {
    //             if(day < 17 && (month < 12 || month == 12)) {
    //                 day += 14;
    //             }
    //             else if(day == 17 && (month < 12 || month == 12)) {
    //                 month ++;
    //                 day = 0;
    //                 day += 14;
    //             }
    //             else if(day > 17 && month < 12) {
    //                 month ++;
    //                 day -= 17;
    //                 day += 14;
    //             }
    //             else if(day > 17 && month == 12) {
    //                 year ++;
    //                 month = 1;
    //                 day -= 17;
    //                 day += 14;
    //             }
    //         }
    //         // even months and September and November but not Februrary have 30 days
    //         else if((month != 2 && month % 2 == 0) || (month == 9 || month == 11)) {
    //             if(day < 16 && (month < 12 || month == 12)) {
    //                 day += 14;
    //             }
    //             else if(day == 16 && (month < 12 || month == 12)) {
    //                 month ++;
    //                 day = 0;
    //                 day += 14;
    //             }
    //             else if(day > 16 && month < 12) {
    //                 month ++;
    //                 day -= 17;
    //                 day += 14;
    //             }
    //             else if(day > 16 && month == 12) {
    //                 year ++;
    //                 month = 0;
    //                 day -= 16;
    //                 day += 14;
    //             }
    //         }
    //         // February in years divisible by both 100 and 400 or not 100 but 4 has 29 days because it is a leap year
    //         else if((month == 2 && year % 100 == 0 && year % 400 == 0) || (month == 2 && year % 100 != 0 && year % 4 == 0)) {
    //             if(day < 15 && (month < 12 || month == 12)) {
    //                 day += 14;
    //             }
    //             else if(day == 15 && (month < 12 || month == 12)) {
    //                 month ++;
    //                 day = 0;
    //                 day += 14;
    //             }
    //             else if(day > 15 && month < 12) {
    //                 month ++;
    //                 day -= 17;
    //                 day += 14;
    //             }
    //             else if(day > 15 && month == 12) {
    //                 year ++;
    //                 month = 1;
    //                 day -= 15;
    //                 day += 14;
    //             }
    //         }
    //         // February in regular years should have 28 days
    //         else {
    //             if(day < 14 && (month < 12 || month == 12)) {
    //                 day += 14;
    //             }
    //             else if(day == 14 && (month < 12 || month == 12)) {
    //                 month ++;
    //                 day = 0;
    //                 day += 14;
    //             }
    //             else if(day > 14 && month < 12) {
    //                 month ++;
    //                 day -= 17;
    //                 day += 14;
    //             }
    //             else if(day > 14 && month == 12) {
    //                 year ++;
    //                 month = 1;
    //                 day -= 14;
    //                 day += 14;
    //             }
    //         }


    //         if(currentWeek != lTerm && currentWeek < lTerm) {
    //             biWeeklyPrincipal = (uTotal - biWeeklyInterest) * 2;
    //         }
    //         else {
    //             biWeeklyPrincipal = biWeeklyBalance;
    //         }
    //         biWeeklyBalance -= biWeeklyPrincipal;

    //         if(month != 10 && month != 11 && month != 12) {
    //             amortizationSchedule << fixed << setprecision(2) << month << "/" << day << "/" << year << setw(8) << uTotal << setw(10);
    //             amortizationSchedule << biWeeklyPrincipal << setw(10) << biWeeklyInterest << setw(10) << biWeeklyBalance << endl;
    //         }
    //         else {
    //             amortizationSchedule << fixed << setprecision(2) << month << "/" << day << "/" << year << setw(7) << uTotal << setw(10);
    //             amortizationSchedule << biWeeklyPrincipal << setw(10) << biWeeklyInterest << setw(10) << biWeeklyBalance << endl;
    //         }
    //     }
    // }
    // close the file
    amortizationSchedule.close();
}

void displayResults(string nameOfFile) {
    // open the file
    ifstream aSchedule;

    aSchedule.open(nameOfFile + suffix);

    // declare fileLine (should be each line of the file)
    string fileLine;
    // declare and initialize lineCount to 0
    int lineCount = 0;

    if(aSchedule.fail()) {
        cout << "Error while opening file" << endl;
    }
    else {
        while(getline(aSchedule, fileLine)) {
            lineCount ++;
            cout << fileLine << endl;
        }
    }
    // clear the file so it can be reloaded
    aSchedule.clear();
    // close file
    aSchedule.close();
    }

int main() {
    cout << "Welcome to " << PROGRAM_NAME << endl;

    // declare and initialize running to true so the program runs originally
    bool running = true;

    // run the program while running is true
    while(running) {
        // decalre runProgram
        char runProgram;
        // ask the user if they would like to run the program
        cout << "Would you like to run the program (y / n): ";
        cin >> runProgram;
        // end program when user enter 'n'
        if(runProgram == 'y') {
            running = true;
        }
        else if(runProgram == 'n') {
            running = false;
            break;
        }
        else {
            cout << "Invalid input." << endl;
            break;
        }

        // ask for the loan amount
        double amtLoan = getLoanAmount();

        if(amtLoan < 0) {
            cout << "Invalid input." << endl;
            break;
        }

        // declare periodChoice
        int choosePeriod;
        // ask if user wants the term in months, years or weeks
        choosePeriod = getIntWithPrompt("Would you like to enter your loan term in (1) months or (2) years (This will also be how often you pay the loan back): ");

        // ask for the loan term in months (if it is not a whole number of years) or years 
        double lnTerm = getloanTerm(choosePeriod);

        if(lnTerm < 0) {
            cout << "Invald input." << endl;
            break;
        }

        // ask for the interest rate (and either set it yearly or let the user choose how it is compounded)
        double iRate = getInterestRate(choosePeriod);

        if(iRate < 0) {
            cout << "Invalid input." << endl;
            break;
        }

        else {
            // plug these into total payment = loan amount((i * (1 + i) / n) / ((1 + i) / n) - 1 )
            double periodTotal = calculateTotalPerPeriod(amtLoan, lnTerm, iRate, choosePeriod);

            string fileToOpen = getFileName();
            // take total amount due, principal due, and interest each period and make table (open a new file and place these maybe)
            // print a total of all the amounts due, principals due, and interests each period
            storeResultsInFile(periodTotal, iRate, amtLoan, lnTerm, choosePeriod, fileToOpen);

            displayResults(fileToOpen);
        }
    }
    
    cout << "Thank you for using " << PROGRAM_NAME << endl;
    return 0;
}