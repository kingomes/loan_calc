export class money {
    public interest: number
    public amountBorrowed: number
    public numPayments: number
    public years: number

    public constructor(interest: number, amountBorrowed: number, numPayments: number, years: number) {
        this.amountBorrowed = amountBorrowed
        this.interest = interest
        this.numPayments = numPayments
        this.years = years
    }
    public getAmmountBorrowed() : number {
        return this.amountBorrowed
    }
    public setAmmountBorrowed(amountBorrowed: number) : void {
        this.amountBorrowed = amountBorrowed
    }
    public getInterest() : number {
        return this.interest
    }
    public setInterest(interest: number) : void {
        this.interest = interest
    }
    public getYears() : number {
        return this.years
    }
    public setYears(years: number) : void {
        this.years = years
    } 
    public getNumPayments() : number {
        return this.numPayments
    }
    public setNumPayments(numPayments: number) : void {
        this.numPayments = numPayments
    } 
}