/*Task-02:
Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%*/

#include <iostream>
using namespace std;

class LoanHelper
{
    private:
        const float interestrate;
        float loanAmt;
        int months;

    public:
        LoanHelper() : interestrate(0.0), loanAmt(0.0), months(0) {}
        LoanHelper(float rate, float loan, int m) : interestrate(rate), loanAmt(loan), months(m) {}

        void calculatePayment()
        {
            double amt = loanAmt/months;

            double topay = amt * (1 + interestrate);
            cout << "You have to pay " << topay << " every month for " << months << " to repay your loan." << endl;
        }
};

int main()
{
    float interestrate, loanAmt;
    int months;
    cout << "Enter interest rate (between 0-0.005): " << endl;
    cin >> interestrate;
    if (interestrate >= 0.0 && interestrate <= 0.005)
    {
        cout << "Enter loan amount: " << endl;
        cin >> loanAmt;
        cout << "Enter number of months to repay the loan: " << endl;
        cin >> months;

        LoanHelper lh1(interestrate, loanAmt, months);
        lh1.calculatePayment();
    }
    else
        cout << "Invalid interest rate." << endl;
}