import prompts from 'prompts';

function calculateLoanMonthly(interest : number, amountBorrowed : number, years : number) : number {
    let amountPerPeriod = amountBorrowed * (interest * (Math.pow(1 + interest, years / 12)) / ((Math.pow(1 + interest, years / 12) - 1)));
    return amountPerPeriod;
}

const questions = [
    {
        type: 'number',
        name: 'interest',
        message: "Enter interest: "
    },
    {
        type: 'number',
        name: 'amountBorrowed',
        message: "Enter the amount you wish to borrow: "
    },
    {
        type: 'number',
        name: 'years',
        message: "Enter how many years you have to pay back the loan"
    }
];

(async() => {
    const response = await prompts(questions);
    console.log(response)
}) ();

function getInterest(response) {
    console.log(response)
}