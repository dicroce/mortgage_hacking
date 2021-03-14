
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    double mortgage_amount = 396000;           // principal
    double loan_rate = 0.0316;
    double loan_years = 30;

    double monthly_rate = loan_rate / 12;      // monthly interest
    double loan_months = loan_years * 12;      // number of payments

    // Payment formula    P[i(1 + i)^n]/[(1+i)^n-1]
    double payment = ((mortgage_amount * monthly_rate) * pow(1 + monthly_rate, 360)) / (pow(1 + monthly_rate, 360) - 1.0);

    double balance = mortgage_amount;

    // The extra_principal map is used to model extra payments. The first field is the month number the extra payment
    // occurs on, the second value is the amount of the extra payment.
    map<int, double> extra_principal = {{2, 40000.0}};

    double total_of_payments = 0.0;

    int i = 1;
    while(balance > 0.0)
    {
        double interest_part = balance * monthly_rate;
        double principal_part = payment - interest_part;

        if(extra_principal.find(i) != extra_principal.end())
            principal_part += extra_principal[i];

        if(principal_part > balance)
        {
            principal_part = balance;
            balance = 0.0;
        }
        else balance -= principal_part;

        printf("(%d) payment = %f, principal_part = %f, interest_part = %f, balance = %f\n", i, payment, principal_part, interest_part, balance);
        fflush(stdout);

        total_of_payments += payment;

        ++i;
    }

    if(i < (int)loan_months)
    {
        printf("Loan Finished in %f years.\n",((double)i)/12);
    }

    printf("Total of Payments: %f\n", total_of_payments);

    double payment_times_loan_months = payment * loan_months;

    printf("Total of Payments without extra principle: %f\n", payment_times_loan_months);

    if(total_of_payments < payment_times_loan_months)
    {
        printf("You Saved %f by prepaying.\n", payment_times_loan_months - total_of_payments);
    }

    return 0;
}
