"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var tslib_1 = require("tslib");
var prompts_1 = (0, tslib_1.__importDefault)(require("prompts"));
function calculateLoanMonthly(interest, amountBorrowed, years) {
    var amountPerPeriod = amountBorrowed * (interest * (Math.pow(1 + interest, years / 12)) / ((Math.pow(1 + interest, years / 12) - 1)));
    return amountPerPeriod;
}
var questions = [
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
(function () { return (0, tslib_1.__awaiter)(void 0, void 0, void 0, function () {
    var response;
    return (0, tslib_1.__generator)(this, function (_a) {
        switch (_a.label) {
            case 0: return [4, (0, prompts_1.default)(questions)];
            case 1:
                response = _a.sent();
                console.log(response.interest);
                return [2];
        }
    });
}); })();
function getInterest(response) {
    console.log(response);
}
//# sourceMappingURL=index.js.map