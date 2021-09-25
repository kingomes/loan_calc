export declare class money {
    interest: number;
    amountBorrowed: number;
    numPayments: number;
    years: number;
    constructor(interest: number, amountBorrowed: number, numPayments: number, years: number);
    getAmmountBorrowed(): number;
    setAmmountBorrowed(amountBorrowed: number): void;
    getInterest(): number;
    setInterest(interest: number): void;
    getYears(): number;
    setYears(years: number): void;
    getNumPayments(): number;
    setNumPayments(numPayments: number): void;
}
