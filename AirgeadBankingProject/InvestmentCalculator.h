#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

class InvestmentCalculator {
public:
    // Constructor to initialize all inputs
    InvestmentCalculator(double t_initialAmount, double t_monthlyDeposit, double t_annualInterest, int t_years);

    // Display report without monthly deposits
    void displayYearlyReportNoDeposit() const;

    // Display report with monthly deposits
    void displayYearlyReportWithDeposit() const;

private:
    // These hold the user inputs used for calculations
    double m_initialAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_years;
};

#endif
