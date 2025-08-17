#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor - stores user input in private variables
InvestmentCalculator::InvestmentCalculator(double t_initialAmount, double t_monthlyDeposit,
                                           double t_annualInterest, int t_years) {
    m_initialAmount = t_initialAmount;
    m_monthlyDeposit = t_monthlyDeposit;
    m_annualInterest = t_annualInterest;
    m_years = t_years;
}

// Report that calculates yearly growth WITHOUT monthly deposits
void InvestmentCalculator::displayYearlyReportNoDeposit() const {
    double balance = m_initialAmount;
    double interestEarned;

    cout << "\nGrowth Report (Without Monthly Deposits):\n";
    cout << "Year    Year-End Balance    Interest Earned\n";

    for (int year = 1; year <= m_years; ++year) {
        interestEarned = balance * (m_annualInterest / 100.0);
        balance += interestEarned;

        cout << setw(4) << year << "    $" << fixed << setprecision(2) << setw(16) << balance
             << "    $" << setw(16) << interestEarned << "\n";
    }
}

// Report that calculates yearly growth WITH monthly deposits
void InvestmentCalculator::displayYearlyReportWithDeposit() const {
    double balance = m_initialAmount;
    double totalInterest, monthlyInterest;

    cout << "\nGrowth Report (With Monthly Deposits):\n";
    cout << "Year    Year-End Balance    Interest Earned\n";

    for (int year = 1; year <= m_years; ++year) {
        totalInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            balance += m_monthlyDeposit;

            // Monthly interest formula
            monthlyInterest = balance * ((m_annualInterest / 100.0) / 12);
            totalInterest += monthlyInterest;
            balance += monthlyInterest;
        }

        cout << setw(4) << year << "    $" << fixed << setprecision(2) << setw(16) << balance
             << "    $" << setw(16) << totalInterest << "\n";
    }
}
